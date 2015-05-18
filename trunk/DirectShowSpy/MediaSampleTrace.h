////////////////////////////////////////////////////////////
// Copyright (C) Roman Ryltsov, 2008-2015
// Created by Roman Ryltsov roman@alax.info, http://alax.info
//
// This source code is published to complement DirectShowSpy developer powertoy 
// and demonstrate the internal use of APIs and tricks powering the tool. It is 
// allowed to freely re-use the portions of the code in other projects, commercial 
// or otherwise (provided that you don�t pretend that you wrote the original tool).
//
// Please keep in mind that DirectShowSpy is a developer tool, it is strongly recommended
// that it is not shipped with release grade software. It is allowed to distribute
// DirectShowSpy if only it is not registered with Windows by default and either
// used privately, or registered on specific throubleshooting request. The advice applies 
// to hooking methods used by DirectShowSpy in general as well.

#pragma once

#include "rodshow.h"
#include "Module_i.h"
#include "Common.h"
#include "FilterGraphHelper.h"

////////////////////////////////////////////////////////////
// CMediaSampleTraceBase

class CMediaSampleTraceBase
{
public:

	////////////////////////////////////////////////////////
	// Structure

	#pragma pack(push, 1)

	enum
	{
		HEADERFLAGS_NONE = 0,
	};

	typedef struct _HEADER
	{
		UINT32 nCapacity;
		UINT32 nFlags;
		UINT32 nVersion;
		UINT32 nItemCount;
	} HEADER;

	enum
	{
		ITEMFLAGS_NONE = 0,
		ITEMFLAG_INVALID = 1,
	};

	typedef struct _ITEM
	{
		UINT32 nFlags;
		UINT32 nProcessIdentifier;
		UINT32 nPageIdentifier;
		UINT64 nFilterGraphIdentifier;
		WCHAR pszFilterGraphName[128];
	} ITEM;

	enum
	{
		PAGEHEADERFLAGS_NONE = 0,
		PAGEHEADERFLAG_X64 = 1,
	};

	typedef struct _PAGEHEADER
	{
		UINT32 nCapacity;
		UINT32 nFlags;
		UINT32 nProcessIdentifier;
		UINT32 nItemCount;
	} PAGEHEADER;

	enum
	{
		PAGEITEMFLAGS_NONE = 0,
		PAGEITEMFLAG_NEWSEGMENT = 0,
		PAGEITEMFLAG_MEDIASAMPLE = 1,
		PAGEITEMFLAG_ENDOFSTREAM = 2,
		PAGEITEMFLAG_COMMENT = 3,
		PAGEITEMFLAG_TYPE_MASK = 0x03,
	};

	typedef struct _PAGEITEM
	{
		UINT32 nFlags;
		UINT32 nThreadIdentifier;
		UINT64 nFilterIdentifier;
		WCHAR pszFilterName[32];
		WCHAR pszStreamName[32];
		UINT64 nTime;
		union
		{
			struct
			{
				REFERENCE_TIME nStartTime;
				REFERENCE_TIME nStopTime;
				DOUBLE fRate;
			} NewSegment;
			struct
			{
				AM_SAMPLE2_PROPERTIES Properties;
			} MediaSample;
		} Data;
		WCHAR pszComment[64];
	} PAGEITEM;

	#pragma pack(pop)

	////////////////////////////////////////////////////////
	// CData

	class CData
	{
	public:

		///////////////////////////////////////////////////////
		// CItem

		class CItem
		{
		public:
			ITEM m_Item;
			PAGEITEM m_PageItem;

		public:
		// CItem
			LPCTSTR FormatType() const
			{
				switch(m_PageItem.nFlags & PAGEITEMFLAG_TYPE_MASK)
				{
				case PAGEITEMFLAG_NEWSEGMENT:
					return _T("New Segment");
				case PAGEITEMFLAG_MEDIASAMPLE:
					return _T("Media Sample");
				case PAGEITEMFLAG_ENDOFSTREAM:
					return _T("End of Stream");
				//case PAGEITEMFLAG_COMMENT:
				//	return _T("Comment");
				}
				return _T("Comment");
			}
		};

		////////////////////////////////////////////////////
		// CItemSortTraits

		class CItemSortTraits :
			public CDefaultSortTraitsT<CItem>
		{
		public:
		// CItemSortTraits
			static INT_PTR CompareElements(const CItem& Item1, const CItem& Item2, PARAMETERARGUMENT)
			{
				const INT64 nTime = Item1.m_PageItem.nTime - Item2.m_PageItem.nTime;
				return (nTime < 0) ? -1 : (nTime > 0) ? 1 : 0;
			}
		};

	public:
		CRoArrayT<CItem> m_ItemArray;

	public:
	// CData
		VOID Initialize()
		{
			m_ItemArray.SetCount(0, 32768);
		}
		VOID Add(const HEADER* pHeader, const ITEM* pItem, const PAGEHEADER* pPageHeader, const PAGEITEM* pPageItem)
		{
			_A(pHeader && pItem && pPageHeader && pPageItem);
			pHeader; pPageHeader;
			const SIZE_T nIndex = m_ItemArray.Add();
			CItem& Item = m_ItemArray[nIndex];
			Item.m_Item = *pItem;
			Item.m_PageItem = *pPageItem;
		}
		VOID Sort()
		{
			_SortHelper::QuickSort<CItemSortTraits>(m_ItemArray);
		}
	};

	////////////////////////////////////////////////////////
	// CPages

	class CPages
	{
	private:
		UINT64 m_nFilterGraphIdentifier;
		CStringW m_sFilterGraphName;
		CMutex m_Mutex;
		CAtlFileMapping<HEADER> m_FileMapping;

	public:
	// CPages
		static LPCTSTR GetMutexName()
		{
			return _T("DirectShowSpy.MediaSamplePageRegistry.Access");
		}
		static SIZE_T GetFileMappingCapacity()
		{
			return 1 << 20; // 1 MB
		}
		static LPCTSTR GetFileMappingName()
		{
			return _T("DirectShowSpy.MediaSamplePageRegistry");
		}
		static CString GetPageMutexName(UINT32 nProcessIdentifier, UINT64 nPageIdentifier)
		{
			return AtlFormatString(_T("DirectShowSpy.MediaSamplePage.%08X.%08X.Access"), nProcessIdentifier, nPageIdentifier);
		}
		static SIZE_T GetPageFileMappingCapacity()
		{
			return 4 << 20; // 4 MB
		}
		static CString GetPageFileMappingName(UINT32 nProcessIdentifier, UINT64 nPageIdentifier)
		{
			return AtlFormatString(_T("DirectShowSpy.MediaSamplePage.%08X.%08X"), nProcessIdentifier, nPageIdentifier);
		}
		BOOL Initialize(BOOL bCreate = FALSE)
		{
			_A(!m_Mutex && !m_FileMapping);
			if(!bCreate)
			{
				if(!m_Mutex.Open(MUTEX_ALL_ACCESS, FALSE, GetMutexName()))
					return FALSE;
				_ATLTRY
				{
					//CMutexLock MutexLock(m_Mutex);
					__C(m_FileMapping.OpenMapping(GetFileMappingName(), GetFileMappingCapacity()));
				}
				_ATLCATCHALL()
				{
					m_Mutex.Close();
					_ATLRETHROW;
				}
			} else
			{
				__E(m_Mutex.Create(NULL, FALSE, GetMutexName()));
				//CMutexLock MutexLock(m_Mutex);
				__C(m_FileMapping.MapSharedMem(GetFileMappingCapacity(), GetFileMappingName()));
			}
			return TRUE;
		}
		VOID GetData(CData& Data)
		{
			_A(m_Mutex && m_FileMapping);
			Data.Initialize();
			CMutexLock MutexLock(m_Mutex);
			HEADER* pHeader = m_FileMapping;
			_A(pHeader->nCapacity);
			for(UINT32 nItemIndex = 0; nItemIndex < pHeader->nItemCount; nItemIndex++)
			{
				ITEM* pItem = (ITEM*) (pHeader + 1) + nItemIndex;
				if(pItem->nFlags & ITEMFLAG_INVALID)
					continue;
				_ATLTRY
				{
					CMutex PageMutex;
					__E(PageMutex.Open(MUTEX_ALL_ACCESS, FALSE, GetPageMutexName(pItem->nProcessIdentifier, pItem->nPageIdentifier)));
					CAtlFileMapping<PAGEHEADER> PageFileMapping;
					__C(PageFileMapping.OpenMapping(GetPageFileMappingName(pItem->nProcessIdentifier, pItem->nPageIdentifier), GetPageFileMappingCapacity()));
					PAGEHEADER* pPageHeader = PageFileMapping;
					CMutexLock MutexLock(PageMutex);
					#pragma region Bitness
					// SUGG: Support non-native bitness through conversion
					#if defined(_WIN64)
						if(!(pPageHeader->nFlags & PAGEHEADERFLAG_X64))
							continue;
					#else
						if(pPageHeader->nFlags & PAGEHEADERFLAG_X64)
							continue;
					#endif // defined(_WIN64)
					#pragma endregion
					for(UINT32 nItemIndex = 0; nItemIndex < pPageHeader->nItemCount; nItemIndex++)
					{
						PAGEITEM* pPageItem = (PAGEITEM*) (pPageHeader + 1) + nItemIndex;
						Data.Add(pHeader, pItem, pPageHeader, pPageItem);
					}
					continue;
				}
				_ATLCATCHALL()
				{
					_Z_EXCEPTION();
				}
				pItem->nFlags |= ITEMFLAG_INVALID;
			}
		}
		VOID ResetData()
		{
			CMutexLock MutexLock(m_Mutex);
			HEADER* pHeader = m_FileMapping;
			_A(pHeader->nCapacity);
			pHeader->nItemCount = 0;
			pHeader->nVersion++;
		}
		VOID Initialize(UINT64 nFilterGraphIdentifier, const CStringW& sFilterGraphName)
		{
			_A(!m_Mutex && !m_FileMapping);
			m_nFilterGraphIdentifier = nFilterGraphIdentifier;
			m_sFilterGraphName = sFilterGraphName;
			__E(m_Mutex.Create(NULL, FALSE, GetMutexName()));
			CMutexLock MutexLock(m_Mutex);
			BOOL bOpen = FALSE;
			__C(m_FileMapping.MapSharedMem(GetFileMappingCapacity(), GetFileMappingName(), &bOpen));
			HEADER* pHeader = m_FileMapping;
			if(!pHeader->nCapacity)
			{
				_A(!bOpen);
				pHeader->nCapacity = (UINT32) GetFileMappingCapacity();
				pHeader->nFlags = HEADERFLAGS_NONE;
				pHeader->nVersion = 0;
				pHeader->nItemCount = 0;
			} else
				_A(bOpen);
			#if defined(_DEBUG)
				_Z4(atlTraceGeneral, 4, _T("File mapping size %d, item size %d, item capacity %d\n"), GetFileMappingCapacity(), sizeof (ITEM), (GetFileMappingCapacity() - sizeof (HEADER)) / sizeof (ITEM));
				_Z4(atlTraceGeneral, 4, _T("Page file mapping size %d, page item size %d, page item capacity %d\n"), GetPageFileMappingCapacity(), sizeof (PAGEITEM), (GetPageFileMappingCapacity() - sizeof (PAGEHEADER)) / sizeof (PAGEITEM));
			#endif // defined(_DEBUG)
		}
		VOID CreatePage(UINT32& nPageIdentifier, CMutex& Mutex, CAtlFileMapping<PAGEHEADER>& FileMapping)
		{
			_A(!Mutex && !FileMapping);
			// SUGG: Random identifiers
			for(nPageIdentifier = 0; ; nPageIdentifier++)
			{
				if(!Mutex.Create(NULL, FALSE, GetPageMutexName(GetCurrentProcessId(), nPageIdentifier)))
				{
					const HRESULT nCreateResult = AtlHresultFromLastError();
					__D(nCreateResult == E_ACCESSDENIED, nCreateResult);
					continue; // Already Exists, Access Denied
				}
				_ATLTRY
				{
					CMutexLock MutexLock(Mutex);
					if(GetLastError() != ERROR_ALREADY_EXISTS)
					{
						BOOL bOpen = FALSE;
						__C(FileMapping.MapSharedMem(GetPageFileMappingCapacity(), GetPageFileMappingName(GetCurrentProcessId(), nPageIdentifier), &bOpen));
						_ATLTRY
						{
							__D(!bOpen, E_UNNAMED);
							PAGEHEADER* pPageHeader = FileMapping;
							_A(!pPageHeader->nCapacity);
							pPageHeader->nCapacity = (UINT32) GetPageFileMappingCapacity();
							pPageHeader->nFlags = 0;
							#if defined(_WIN64)
								pPageHeader->nFlags |= PAGEHEADERFLAG_X64;
							#endif // defined(_WIN64)
							pPageHeader->nProcessIdentifier = (UINT32) GetCurrentProcessId();
							pPageHeader->nItemCount = 0;
							MutexLock.Unlock();
							#pragma region Link Page
							{
								CMutexLock MutexLock(m_Mutex);
								HEADER* pHeader = m_FileMapping;
								const SIZE_T nCapacity = sizeof *pHeader + (pHeader->nItemCount + 1) * sizeof (ITEM);
								__D(nCapacity <= (SIZE_T) pHeader->nCapacity, HRESULT_FROM_WIN32(ERROR_BUFFER_OVERFLOW));
								ITEM* pItem = (ITEM*) (pHeader + 1) + pHeader->nItemCount;
								pItem->nFlags = ITEMFLAGS_NONE;
								pItem->nProcessIdentifier = (UINT32) GetCurrentProcessId();
								pItem->nPageIdentifier = nPageIdentifier;
								pItem->nFilterGraphIdentifier = m_nFilterGraphIdentifier;
								wcsncpy_s(pItem->pszFilterGraphName, m_sFilterGraphName, _TRUNCATE);
								pHeader->nItemCount++;
								pHeader->nVersion++;
							}
							#pragma endregion
							break;
						}
						_ATLCATCHALL()
						{
							_V(FileMapping.Unmap());
							_ATLRETHROW;
						}
					}
				}
				_ATLCATCHALL()
				{
					_Z_EXCEPTION();
				}
				Mutex.Close();
			}
		}
	};

	////////////////////////////////////////////////////////
	// CPage

	class CPage
	{
	public:

		///////////////////////////////////////////////////
		// CItem

		class CItem
		{
		public:
			UINT32 m_nPageIdentifier;
			CMutex m_Mutex;
			CAtlFileMapping<PAGEHEADER> m_FileMapping;
			BOOL m_bActive;

		public:
		// CItem
		};

	private:
		CRoListT<CItem> m_ItemList;

	public:
	// CPage
		VOID Register(CPages& Pages, UINT64 nFilterIdentifier, const CStringW& sFilterName, LPCWSTR pszStreamName, const PAGEITEM& PageItem, LPCWSTR pszComment)
		{
			const UINT64 nTime = (UINT64) CUsAccurateFileTime::GetTime();
			for(UINT nIteration = 0; ; nIteration++)
			{
				_A(nIteration < 2);
				if(!m_ItemList.IsEmpty() && m_ItemList.GetTail().m_bActive)
				{
					CMutexLock MutexLock(m_ItemList.GetTail().m_Mutex);
					PAGEHEADER* pPageHeader = m_ItemList.GetTail().m_FileMapping;
					const SIZE_T nCapacity = sizeof *pPageHeader + (pPageHeader->nItemCount + 1) * sizeof (PAGEITEM);
					if(nCapacity <= (SIZE_T) pPageHeader->nCapacity)
					{
						PAGEITEM* pPageItem = (PAGEITEM*) (pPageHeader + 1) + pPageHeader->nItemCount;
						pPageItem->nFlags = PageItem.nFlags & PAGEITEMFLAG_TYPE_MASK;
						pPageItem->nThreadIdentifier = GetCurrentThreadId();
						pPageItem->nFilterIdentifier = nFilterIdentifier;
						wcsncpy_s(pPageItem->pszFilterName, sFilterName, _TRUNCATE);
						if(pszStreamName)
							wcsncpy_s(pPageItem->pszStreamName, pszStreamName, _TRUNCATE);
						else
							*pPageItem->pszStreamName = 0;
						pPageItem->nTime = nTime;
						pPageItem->Data = PageItem.Data;
						if(pszComment)
							wcsncpy_s(pPageItem->pszComment, pszComment, _TRUNCATE);
						else
							*pPageItem->pszComment = 0;
						pPageHeader->nItemCount++;
						return;
					}
					m_ItemList.GetTail().m_bActive = FALSE;
				}
				const POSITION Position = m_ItemList.AddTail();
				_ATLTRY
				{
					CItem& Item = m_ItemList.GetAt(Position);
					Pages.CreatePage(Item.m_nPageIdentifier, Item.m_Mutex, Item.m_FileMapping);
					Item.m_bActive = TRUE;
				}
				_ATLCATCHALL()
				{
					m_ItemList.RemoveAt(Position);
					_ATLRETHROW;
				}
			}
		}
	};

public:
// CMediaSampleTraceBase
};

////////////////////////////////////////////////////////////
// CMediaSampleTrace

class ATL_NO_VTABLE CMediaSampleTrace :
	public CComObjectRootEx<CComMultiThreadModelNoCS>,
	public CComCoClass<CMediaSampleTrace>,// &__uuidof(MediaSampleTrace)>,
	//public IProvideClassInfo2Impl<&__uuidof(MediaSampleTrace), &IID_NULL>,
	public IMediaSampleTrace,
	public CMediaSampleTraceBase
{
public:
	//enum { IDR = IDR_MediaSampleTrace };

DECLARE_NO_REGISTRY() //DECLARE_REGISTRY_RESOURCEID(IDR)

BEGIN_COM_MAP(CMediaSampleTrace)
	COM_INTERFACE_ENTRY(IMediaSampleTrace)
	//COM_INTERFACE_ENTRY(IProvideClassInfo2)
	//COM_INTERFACE_ENTRY(IProvideClassInfo)
END_COM_MAP()

public:

private:
	//mutable CRoCriticalSection m_DataCriticalSection;
	UINT_PTR m_nFilterGraphIdentifier;
	CStringW m_sFilterGraphName;
	CPages m_Pages;
	CPage m_Page;

public:
// CMediaSampleTrace
	CMediaSampleTrace()
	{
		_Z4_THIS();
	}
	~CMediaSampleTrace()
	{
		_Z4_THIS();
	}
	VOID Initialize(ISpy* pSpy)
	{
		_A(pSpy);
		CComBSTR sName;
		__C(pSpy->get_FriendlyName(&sName));
		const CComQIPtr<IFilterGraph2> pFilterGraph2 = pSpy;
		_A(pFilterGraph2);
		//CRoCriticalSectionLock DataLock(m_DataCriticalSection);
		m_nFilterGraphIdentifier = (UINT_PTR) (IFilterGraph2*) pFilterGraph2;
		m_sFilterGraphName = CStringW(sName);
		m_Pages.Initialize((UINT64) m_nFilterGraphIdentifier, m_sFilterGraphName);
		// NOTE: We might prefer to let the pages leak away to outlive the filter graph itself...
		AddRef();
	}
	static CStringW GetFilterName(IUnknown* pBaseFilterUnknown)
	{
		CStringW sFilterName;
		const CComQIPtr<IBaseFilter> pBaseFilter = pBaseFilterUnknown;
		if(pBaseFilter)
			sFilterName = _FilterGraphHelper::GetFilterName(pBaseFilter);
		return sFilterName;
	}

// IMediaSampleTrace
	STDMETHOD(RegisterNewSegment)(IUnknown* pBaseFilterUnknown, const WCHAR* pszStreamName, LONGLONG nStartTime, LONGLONG nStopTime, DOUBLE fRate, const WCHAR* pszComment)
	{
		_Z5(atlTraceCOM, 5, _T("this 0x%p, pBaseFilterUnknown 0x%p, pszStreamName \"%s\", nStartTime %I64d\n"), this, pBaseFilterUnknown, CString(pszStreamName), nStartTime);
		_ATLTRY
		{
			PAGEITEM PageItem;
			PageItem.nFlags = PAGEITEMFLAG_NEWSEGMENT;
			PageItem.Data.NewSegment.nStartTime = nStartTime;
			PageItem.Data.NewSegment.nStopTime = nStopTime;
			PageItem.Data.NewSegment.fRate = fRate;
			m_Page.Register(m_Pages, (UINT_PTR) pBaseFilterUnknown, GetFilterName(pBaseFilterUnknown), pszStreamName, PageItem, pszComment);
		}
		_ATLCATCH(Exception)
		{
			_C(Exception);
		}
		return S_OK;
	}
	STDMETHOD(RegisterMediaSample)(IUnknown* pBaseFilterUnknown, const WCHAR* pszStreamName, const BYTE* pnSamplePropertiesData, const WCHAR* pszComment)
	{
		_Z5(atlTraceCOM, 5, _T("this 0x%p, pBaseFilterUnknown 0x%p, pszStreamName \"%s\", pnSamplePropertiesData 0x%p\n"), this, pBaseFilterUnknown, CString(pszStreamName), pnSamplePropertiesData);
		_ATLTRY
		{
			__D(pnSamplePropertiesData, E_POINTER);
			PAGEITEM PageItem;
			PageItem.nFlags = PAGEITEMFLAG_MEDIASAMPLE;
			PageItem.Data.MediaSample.Properties = *((const AM_SAMPLE2_PROPERTIES*) pnSamplePropertiesData);
			m_Page.Register(m_Pages, (UINT_PTR) pBaseFilterUnknown, GetFilterName(pBaseFilterUnknown), pszStreamName, PageItem, pszComment);
		}
		_ATLCATCH(Exception)
		{
			_C(Exception);
		}
		return S_OK;
	}
	STDMETHOD(RegisterEndOfStream)(IUnknown* pBaseFilterUnknown, const WCHAR* pszStreamName, const WCHAR* pszComment)
	{
		_Z5(atlTraceCOM, 5, _T("this 0x%p, pBaseFilterUnknown 0x%p, pszStreamName \"%s\"\n"), this, pBaseFilterUnknown, CString(pszStreamName));
		_ATLTRY
		{
			PAGEITEM PageItem;
			PageItem.nFlags = PAGEITEMFLAG_ENDOFSTREAM;
			m_Page.Register(m_Pages, (UINT_PTR) pBaseFilterUnknown, GetFilterName(pBaseFilterUnknown), pszStreamName, PageItem, pszComment);
		}
		_ATLCATCH(Exception)
		{
			_C(Exception);
		}
		return S_OK;
	}
	STDMETHOD(RegisterComment)(IUnknown* pBaseFilterUnknown, const WCHAR* pszStreamName, const WCHAR* pszComment)
	{
		_Z5(atlTraceCOM, 5, _T("this 0x%p, pBaseFilterUnknown 0x%p, pszStreamName \"%s\", pszComment \"%s\"\n"), this, pBaseFilterUnknown, CString(pszStreamName), CString(pszComment));
		_ATLTRY
		{
			PAGEITEM PageItem;
			PageItem.nFlags = PAGEITEMFLAG_COMMENT;
			m_Page.Register(m_Pages, (UINT_PTR) pBaseFilterUnknown, GetFilterName(pBaseFilterUnknown), pszStreamName, PageItem, pszComment);
		}
		_ATLCATCH(Exception)
		{
			_C(Exception);
		}
		return S_OK;
	}
};

//OBJECT_ENTRY_AUTO(__uuidof(MediaSampleTrace), CMediaSampleTrace)

////////////////////////////////////////////////////////////
// CMediaSampleTracePropertySheet

class CMediaSampleTracePropertySheet :
	public CSizablePropertySheetT<CMediaSampleTracePropertySheet>,
	public CMediaSampleTraceBase
{
public:

BEGIN_MSG_MAP_EX(CMediaSampleTracePropertySheet)
	CHAIN_MSG_MAP(CSizablePropertySheet)
	MSG_WM_SYSCOMMAND(OnSysCommand)
END_MSG_MAP()

public:

	////////////////////////////////////////////////////////
	// CMediaSamplePropertyPage

	class CMediaSamplePropertyPage :
		public CPropertyPageT<CMediaSamplePropertyPage>,
		public CPropertyPageWithAcceleratorsT<CMediaSamplePropertyPage>,
		public CDialogResize<CMediaSamplePropertyPage>
	{
	public:
		enum { IDD = IDD_MEDIASAMPLETRACE_MEDIASAMPLE_PROPERTYPAGE };

	BEGIN_MSG_MAP_EX(CMediaSamplePropertyPage)
		CHAIN_MSG_MAP(CPropertyPage)
		CHAIN_MSG_MAP(CPropertyPageWithAccelerators)
		CHAIN_MSG_MAP(CDialogResize<CMediaSamplePropertyPage>)
		MSG_WM_INITDIALOG(OnInitDialog)
		MSG_LVN_GETDISPINFO(IDC_MEDIASAMPLETRACE_MEDIASAMPLE_LIST, OnListViewGetDispInfo)
		MSG_LVN_GETINFOTIP(IDC_MEDIASAMPLETRACE_MEDIASAMPLE_LIST, OnListViewGetInfoTip)
		MSG_WM_CONTEXTMENU(OnContextMenu)
		COMMAND_ID_HANDLER_EX(IDC_MEDIASAMPLETRACE_MEDIASAMPLE_REFRESH, OnRefresh)
		COMMAND_ID_HANDLER_EX(IDC_MEDIASAMPLETRACE_MEDIASAMPLE_COPYTOCLIPBOARD, OnCopyToClipboard)
		COMMAND_ID_HANDLER_EX(IDC_MEDIASAMPLETRACE_MEDIASAMPLE_SAVETOFILE, OnSaveToFile)
		COMMAND_ID_HANDLER_EX(IDC_MEDIASAMPLETRACE_MEDIASAMPLE_RESETDATA, OnResetData)
		COMMAND_ID_HANDLER_EX(IDC_MEDIASAMPLETRACE_MEDIASAMPLE_OPENFILTERGRAPHLIST, OnOpenFilterGraphList)
		REFLECT_NOTIFICATIONS()
	END_MSG_MAP()

	BEGIN_DLGRESIZE_MAP(CMediaSamplePropertyPage)
		DLGRESIZE_CONTROL(IDC_MEDIASAMPLETRACE_MEDIASAMPLE_INTRODUCTION, DLSZ_SIZE_X)
		DLGRESIZE_CONTROL(IDC_MEDIASAMPLETRACE_MEDIASAMPLE_LIST, DLSZ_SIZE_X | DLSZ_SIZE_Y)
		DLGRESIZE_CONTROL(IDC_MEDIASAMPLETRACE_MEDIASAMPLE_REFRESH, DLSZ_MOVE_Y)
		DLGRESIZE_CONTROL(IDC_MEDIASAMPLETRACE_MEDIASAMPLE_COPYTOCLIPBOARD, DLSZ_MOVE_Y)
		DLGRESIZE_CONTROL(IDC_MEDIASAMPLETRACE_MEDIASAMPLE_SAVETOFILE, DLSZ_MOVE_Y)
	END_DLGRESIZE_MAP()

	private:
		CMediaSampleTracePropertySheet& m_PropertySheet;
		CRoHyperStatic m_IntroductionStatic;
		CRoListViewT<CData::CItem, CRoListControlDataTraitsT> m_ListView;
		CRoHyperStatic m_RefreshStatic;
		CRoHyperStatic m_CopyToClipboardStatic;
		CRoHyperStatic m_SaveToFileStatic;
		CRoMapT<INT, BOOL> m_ChangeMap;
		CPages m_Pages;

	public:
	// CMediaSamplePropertyPage
		CMediaSamplePropertyPage(CMediaSampleTracePropertySheet* pPropertySheet) :
			m_PropertySheet(*pPropertySheet)
		{
		}
		VOID UpdateControls()
		{
		}
		VOID UpdateListView()
		{
			CWindowRedraw ListViewRedraw(m_ListView);
			m_ListView.DeleteAllItems();
			CPages Pages;
			if(Pages.Initialize())
			{
				CData Data;
				Pages.GetData(Data);
				Data.Sort();
				INT nItem = 0;
				for(auto&& Item: Data.m_ItemArray)
					m_ListView.InsertItem(nItem++, Item);
			}
		}
		static CString FormatTime(UINT64 nTime)
		{
			SYSTEMTIME Time;
			FileTimeToSystemTime(&reinterpret_cast<const FILETIME&>(nTime), &Time);
			return AtlFormatString(_T("%02d:%02d:%02d.%03d"), Time.wHour, Time.wMinute, Time.wSecond, Time.wMilliseconds);
		}
		CStringA CreateText()
		{
			CString sText;
			#pragma region Header
			LPCTSTR g_ppszHeader[] = 
			{
				_T("Time"),
				_T("Process Identifier"),
				_T("Thread Identifier"),
				_T("Filter Graph Identifier"),
				_T("Filter Graph Name"),
				_T("Filter Identifier"),
				_T("Filter Name"),
				_T("Stream"),
				_T("Type"),
				_T("Media Sample Flags"),
				_T("Start Time"),
				_T("Stop Time"),
				_T("Length Time"),
				_T("Data Size"),
				_T("Comment"),
			};
			sText += _StringHelper::Join(g_ppszHeader, _T("\t")) + _T("\r\n");
			#pragma endregion
			for(INT nItem = 0; nItem < m_ListView.GetItemCount(); nItem++)
			{
				const CData::CItem& Item = m_ListView.GetItemData(nItem);
				CRoArrayT<CString> Array;
				Array.Add(FormatTime(Item.m_PageItem.nTime));
				Array.Add(AtlFormatString(_T("%d"), Item.m_Item.nProcessIdentifier));
				Array.Add(AtlFormatString(_T("%d"), Item.m_PageItem.nThreadIdentifier));
				Array.Add(AtlFormatString(_T("0x%p"), Item.m_Item.nFilterGraphIdentifier));
				Array.Add(CString(Item.m_Item.pszFilterGraphName));
				Array.Add(AtlFormatString(_T("0x%p"), Item.m_PageItem.nFilterIdentifier));
				Array.Add(CString(Item.m_PageItem.pszFilterName));
				Array.Add(CString(Item.m_PageItem.pszStreamName));
				Array.Add(Item.FormatType());
				switch(Item.m_PageItem.nFlags & PAGEITEMFLAG_TYPE_MASK)
				{
				case PAGEITEMFLAG_NEWSEGMENT:
					Array.Add(_T(""));
					Array.Add(AtlFormatString(_T("%I64d"), Item.m_PageItem.Data.NewSegment.nStartTime));
					if(Item.m_PageItem.Data.NewSegment.nStopTime < LLONG_MAX)
						Array.Add(AtlFormatString(_T("%I64d"), Item.m_PageItem.Data.NewSegment.nStopTime));
					//Item.m_PageItem.Data.NewSegment.fRate
					break;
				case PAGEITEMFLAG_MEDIASAMPLE:
					Array.Add(_FilterGraphHelper::FormatSampleFlags(Item.m_PageItem.Data.MediaSample.Properties.dwSampleFlags));
					if(Item.m_PageItem.Data.MediaSample.Properties.dwSampleFlags & AM_SAMPLE_TIMEVALID)
					{
						Array.Add(AtlFormatString(_T("%I64d"), Item.m_PageItem.Data.MediaSample.Properties.tStart));
						if(Item.m_PageItem.Data.MediaSample.Properties.dwSampleFlags & AM_SAMPLE_STOPVALID)
						{
							Array.Add(AtlFormatString(_T("%I64d"), Item.m_PageItem.Data.MediaSample.Properties.tStop));
							Array.Add(AtlFormatString(_T("%I64d"), Item.m_PageItem.Data.MediaSample.Properties.tStop - Item.m_PageItem.Data.MediaSample.Properties.tStart));
						}
					}
					while(Array.GetCount() < 13)
						Array.Add(_T(""));
					Array.Add(AtlFormatString(_T("%d"), Item.m_PageItem.Data.MediaSample.Properties.lActual));
					break;
				case PAGEITEMFLAG_ENDOFSTREAM:
				case PAGEITEMFLAG_COMMENT:
					break;
				default:
					_A(FALSE);
				}
				if(*Item.m_PageItem.pszComment)
				{
					while(Array.GetCount() < 14)
						Array.Add(_T(""));
					Array.Add(CString(Item.m_PageItem.pszComment));
				}
				sText += _StringHelper::Join(Array, _T("\t"));
				sText += _T("\r\n");
			}
			return CStringA(sText);
		}

	// Window Message Handler
		LRESULT OnInitDialog(HWND, LPARAM)
		{
			_ATLTRY
			{
				CWaitCursor WaitCursor;
				_W(m_IntroductionStatic.SubclassWindow(GetDlgItem(IDC_MEDIASAMPLETRACE_MEDIASAMPLE_INTRODUCTION)));
				m_ListView.Initialize(GetDlgItem(IDC_MEDIASAMPLETRACE_MEDIASAMPLE_LIST));
				_W(m_RefreshStatic.SubclassWindow(GetDlgItem(IDC_MEDIASAMPLETRACE_MEDIASAMPLE_REFRESH)));
				m_RefreshStatic.SetExtendedStyle(CRoHyperStatic::CS_ANCHORCLICKCOMMAND);
				_W(m_CopyToClipboardStatic.SubclassWindow(GetDlgItem(IDC_MEDIASAMPLETRACE_MEDIASAMPLE_COPYTOCLIPBOARD)));
				m_CopyToClipboardStatic.SetExtendedStyle(CRoHyperStatic::CS_ANCHORCLICKCOMMAND);
				_W(m_SaveToFileStatic.SubclassWindow(GetDlgItem(IDC_MEDIASAMPLETRACE_MEDIASAMPLE_SAVETOFILE)));
				m_SaveToFileStatic.SetExtendedStyle(CRoHyperStatic::CS_ANCHORCLICKCOMMAND);
				CRoHyperStatic::ArrangeHorizontally(&m_RefreshStatic, &m_CopyToClipboardStatic, &m_SaveToFileStatic, NULL);
				DlgResize_Init(FALSE, FALSE);
				_ATLTRY
				{
					// NOTE: This forces the global file mapping open referenced by UI
					// WARN: This is however incomplete since we only keep master mapping and process mappings are gone once the process is gone
					m_Pages.Initialize(TRUE);
				}
				_ATLCATCHALL()
				{
					_Z_EXCEPTION();
				}
				UpdateListView();
				m_ChangeMap.RemoveAll();
				UpdateControls();
				#pragma region Default Property Sheet Size
				CRect Position;
				_W(m_PropertySheet.GetWindowRect(Position));
				Position.InflateRect(6 * Position.Width() / 8, 5 * Position.Width() / 8);
				CSize ScreenExtent(GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN));
				ScreenExtent.cx -= ScreenExtent.cx / 8;
				ScreenExtent.cy -= ScreenExtent.cy / 8;
				if(Position.Width() > ScreenExtent.cx)
					Position.right = Position.left + ScreenExtent.cx;
				if(Position.Height() > ScreenExtent.cy)
					Position.bottom = Position.top + ScreenExtent.cy;
				_W(m_PropertySheet.MoveWindow(Position));
				_W(m_PropertySheet.CenterWindow());
				#pragma endregion
			}
			_ATLCATCHALL()
			{
				for(CWindow Window = GetWindow(GW_CHILD); Window.IsWindow(); Window = Window.GetWindow(GW_HWNDNEXT))
					Window.EnableWindow(FALSE);
				_ATLRETHROW;
			}
			return TRUE;
		}
		LRESULT OnTranslateAccelerator(MSG* pMessage)
		{
			return TranslateAccelerator(m_hWnd, m_hAccelerators, pMessage) ? PSNRET_MESSAGEHANDLED : PSNRET_NOERROR;
		}
		LRESULT OnListViewGetDispInfo(NMLVDISPINFO* pHeader)
		{
			const CData::CItem& Item = m_ListView.DataFromParameter(pHeader->item.lParam);
			if(pHeader->item.mask & LVIF_TEXT)
			{
				CString& sTextBuffer = m_ListView.GetTextBufferString(TRUE);
				switch(pHeader->item.iSubItem)
				{
				case 1: // Process
					sTextBuffer = AtlFormatString(_T("%d"), (UINT_PTR) Item.m_Item.nProcessIdentifier);
					break;
				case 2: // Thread
					sTextBuffer = AtlFormatString(_T("%d"), (UINT_PTR) Item.m_PageItem.nThreadIdentifier);
					break;
				case 3: // Filter Graph
					sTextBuffer = AtlFormatString(_T("0x%p %ls"), (UINT_PTR) Item.m_Item.nFilterGraphIdentifier, Item.m_Item.pszFilterGraphName);
					break;
				case 4: // Filter
					sTextBuffer = AtlFormatString(_T("0x%p %ls"), (UINT_PTR) Item.m_PageItem.nFilterIdentifier, Item.m_PageItem.pszFilterName);
					break;
				case 5: // Stream
					sTextBuffer = AtlFormatString(_T("%ls"), Item.m_PageItem.pszStreamName);
					break;
				case 6: // Type
					sTextBuffer = Item.FormatType();
					break;
				case 7: // Flags
					if((Item.m_PageItem.nFlags & PAGEITEMFLAG_TYPE_MASK) == PAGEITEMFLAG_MEDIASAMPLE)
						sTextBuffer = _FilterGraphHelper::FormatSampleFlags(Item.m_PageItem.Data.MediaSample.Properties.dwSampleFlags);
					break;
				case 8: // Start Time
					if((Item.m_PageItem.nFlags & PAGEITEMFLAG_TYPE_MASK) == PAGEITEMFLAG_NEWSEGMENT)
					{
						sTextBuffer = _FilterGraphHelper::FormatReferenceTime(Item.m_PageItem.Data.NewSegment.nStartTime);
					} else
					if((Item.m_PageItem.nFlags & PAGEITEMFLAG_TYPE_MASK) == PAGEITEMFLAG_MEDIASAMPLE)
					{
						if(Item.m_PageItem.Data.MediaSample.Properties.dwSampleFlags & AM_SAMPLE_TIMEVALID)
							sTextBuffer = _FilterGraphHelper::FormatReferenceTime(Item.m_PageItem.Data.MediaSample.Properties.tStart);
					}
					break;
				case 9: // Stop Time
					if((Item.m_PageItem.nFlags & PAGEITEMFLAG_TYPE_MASK) == PAGEITEMFLAG_NEWSEGMENT)
					{
						if(Item.m_PageItem.Data.NewSegment.nStopTime < LLONG_MAX)
							sTextBuffer = _FilterGraphHelper::FormatReferenceTime(Item.m_PageItem.Data.NewSegment.nStopTime);
					} else
					if((Item.m_PageItem.nFlags & PAGEITEMFLAG_TYPE_MASK) == PAGEITEMFLAG_MEDIASAMPLE)
					{
						if((Item.m_PageItem.Data.MediaSample.Properties.dwSampleFlags & (AM_SAMPLE_TIMEVALID | AM_SAMPLE_STOPVALID)) == (AM_SAMPLE_TIMEVALID | AM_SAMPLE_STOPVALID))
							sTextBuffer = _FilterGraphHelper::FormatReferenceTime(Item.m_PageItem.Data.MediaSample.Properties.tStop);
					}
					break;
				case 10: // Comment
					sTextBuffer = CString(Item.m_PageItem.pszComment);
					break;
				default: // Time
					sTextBuffer = FormatTime(Item.m_PageItem.nTime);
				}
				pHeader->item.pszText = m_ListView.GetTextBuffer();
			}
			return 0;
		}
		LRESULT OnListViewGetInfoTip(NMLVGETINFOTIP* pHeader)
		{
			const CData::CItem& Item = m_ListView.GetItemData(pHeader->iItem);
			CString& sTextBuffer = m_ListView.GetTextBufferString(TRUE);
			sTextBuffer.AppendFormat(_T("Time: %s\r\n"), FormatTime(Item.m_PageItem.nTime));
			sTextBuffer.AppendFormat(_T("Process: %d\r\n"), (UINT_PTR) Item.m_Item.nProcessIdentifier);
			sTextBuffer.AppendFormat(_T("Thread: %d\r\n"), (UINT_PTR) Item.m_PageItem.nThreadIdentifier);
			sTextBuffer.AppendFormat(_T("Filter Graph: 0x%p %ls\r\n"), (UINT_PTR) Item.m_Item.nFilterGraphIdentifier, Item.m_Item.pszFilterGraphName);
			sTextBuffer.AppendFormat(_T("Filter: 0x%p %ls\r\n"), (UINT_PTR) Item.m_PageItem.nFilterIdentifier, Item.m_PageItem.pszFilterName);
			sTextBuffer.AppendFormat(_T("Stream: %ls\r\n"), Item.m_PageItem.pszStreamName);
			sTextBuffer.AppendFormat(_T("Type: %s\r\n"), Item.FormatType());
			switch(Item.m_PageItem.nFlags & PAGEITEMFLAG_TYPE_MASK)
			{
			case PAGEITEMFLAG_NEWSEGMENT:
				sTextBuffer.AppendFormat(_T("Start Time: %s\r\n"), _FilterGraphHelper::FormatReferenceTime(Item.m_PageItem.Data.NewSegment.nStartTime));
				if(Item.m_PageItem.Data.NewSegment.nStopTime < LLONG_MAX)
					sTextBuffer.AppendFormat(_T("Stop Time: %s\r\n"), _FilterGraphHelper::FormatReferenceTime(Item.m_PageItem.Data.NewSegment.nStopTime));
				sTextBuffer.AppendFormat(_T("Rate: %.3f\r\n"), Item.m_PageItem.Data.NewSegment.fRate);
				break;
			case PAGEITEMFLAG_MEDIASAMPLE:
				sTextBuffer.AppendFormat(_T("Sample Flags: %s\r\n"), _FilterGraphHelper::FormatSampleFlags(Item.m_PageItem.Data.MediaSample.Properties.dwSampleFlags));
				if(Item.m_PageItem.Data.MediaSample.Properties.dwSampleFlags & AM_SAMPLE_TIMEVALID)
				{
					sTextBuffer.AppendFormat(_T("Start Time: %s\r\n"), _FilterGraphHelper::FormatReferenceTime(Item.m_PageItem.Data.MediaSample.Properties.tStart));
					if(Item.m_PageItem.Data.MediaSample.Properties.dwSampleFlags & AM_SAMPLE_STOPVALID)
					{
						sTextBuffer.AppendFormat(_T("Stop Time: %s\r\n"), _FilterGraphHelper::FormatReferenceTime(Item.m_PageItem.Data.MediaSample.Properties.tStop));
						sTextBuffer.AppendFormat(_T("Length Time: %s\r\n"), _FilterGraphHelper::FormatReferenceTime(Item.m_PageItem.Data.MediaSample.Properties.tStop - Item.m_PageItem.Data.MediaSample.Properties.tStart));
					}
				}
				sTextBuffer.AppendFormat(_T("Data Size: %s\r\n"), _StringHelper::FormatNumber(Item.m_PageItem.Data.MediaSample.Properties.lActual));
				break;
			case PAGEITEMFLAG_ENDOFSTREAM:
			case PAGEITEMFLAG_COMMENT:
				break;
			default:
				_A(FALSE);
			}
			if(*Item.m_PageItem.pszComment)
				sTextBuffer.AppendFormat(_T("\r\n") _T("%ls\r\n"), Item.m_PageItem.pszComment);
			sTextBuffer.TrimRight(_T("\t\n\r ."));
			#pragma region Clipboard Copy
			if(GetKeyState(VK_CONTROL) < 0 && GetKeyState(VK_SHIFT) < 0)
				_ATLTRY
				{
					SetClipboardText(m_hWnd, sTextBuffer);
					MessageBeep(MB_OK);
				}
				_ATLCATCHALL()
				{
					_Z_EXCEPTION();
					MessageBeep(MB_ICONERROR);
				}
			#pragma endregion
			_tcsncpy_s(pHeader->pszText, pHeader->cchTextMax, m_ListView.GetTextBuffer(), _TRUNCATE);
			return 0;
		}
		LRESULT OnContextMenu(CWindow, CPoint Position)
		{
			CMenu ContainerMenu = AtlLoadMenu(IDD);
			CMenuHandle Menu = ContainerMenu.GetSubMenu(0);
			Menu.TrackPopupMenu(TPM_RIGHTBUTTON | TPM_LEFTALIGN | TPM_TOPALIGN, Position.x, Position.y, m_hWnd); 
			return 0;
		}
		LRESULT OnRefresh(UINT, INT, HWND)
		{
			CWaitCursor WaitCursor;
			UpdateListView();
			return 0;
		}
		LRESULT OnCopyToClipboard(UINT, INT, HWND)
		{
			CWaitCursor WaitCursor;
			SetClipboardText(m_hWnd, CreateText());
			MessageBeep(MB_OK);
			return 0;
		}
		LRESULT OnSaveToFile(UINT, INT, HWND)
		{
			static const COMDLG_FILTERSPEC g_pFilter[] = 
			{
				{ _T("TSV Files"), _T("*.tsv") },
				{ _T("TSV Files, Bzip2 Compressed"), _T("*.tsv.bz2") },
				{ _T("All Files"), _T("*.*") },
			};
			CPath sPath = _CommonDialogHelper::QuerySavePath(m_hWnd, g_pFilter, _T("tsv"), _T("Media Sample Trace.tsv"));
			if(!_tcslen(sPath))
				return 0;
			CWaitCursor WaitCursor;
			const CStringA sText = CreateText();
			LPCTSTR pszExtension = FindExtension(sPath);
			CAtlFile File;
			__C(File.Create(sPath, GENERIC_WRITE, FILE_SHARE_READ, CREATE_ALWAYS));
			_ATLTRY
			{
				if(_tcsicmp(pszExtension, _T(".bz2")) == 0)
				{
					CLocalObjectPtr<CBzip2Item> pItem;
					pItem->SetRawData((const BYTE*) (LPCSTR) sText, sText.GetLength());
					CHeapPtr<BYTE> pnData;
					SIZE_T nDataSize;
					pItem->GetData(pnData, nDataSize);
					__C(File.Write(pnData, (DWORD) nDataSize));
				} else
				{
					__C(File.Write(sText, sText.GetLength() * sizeof (CHAR)));
				}
			}
			_ATLCATCHALL()
			{
				File.Close();
				DeleteFile(sPath);
				_ATLRETHROW;
			}
			return 0;
		}
		LRESULT OnResetData(UINT, INT, HWND)
		{
			CWaitCursor WaitCursor;
			m_Pages.ResetData();
			UpdateListView();
			return 0;
		}
		LRESULT OnOpenFilterGraphList(UINT, INT, HWND)
		{
			CLocalObjectPtr<CFilterGraphHelper> pFilterGraphHelper;
			pFilterGraphHelper->DoFilterGraphListModal((LONG) (LONG_PTR) m_hWnd);
			return 0;
		}
	};

private:
	CMediaSamplePropertyPage m_MediaSamplePropertyPage;

public:
// CMediaSampleTracePropertySheet
	CMediaSampleTracePropertySheet() :
		CSizablePropertySheetT<CMediaSampleTracePropertySheet>(IDS_MEDIASAMPLETRACE_MEDIASAMPLE_PROPERTYSHEETCAPTION),
		m_MediaSamplePropertyPage(this)
	{
		AddPage(m_MediaSamplePropertyPage);
	}
	BOOL SetInitialPosition()
	{
		if(!__super::SetInitialPosition())
			return FALSE;
		SetIcon(AtlLoadIconImage(IDI_MODULE, LR_DEFAULTCOLOR, GetSystemMetrics(SM_CXICON), GetSystemMetrics(SM_CYICON)), TRUE);
		SetIcon(AtlLoadIconImage(IDI_MODULE, LR_DEFAULTCOLOR, GetSystemMetrics(SM_CXSMICON), GetSystemMetrics(SM_CYSMICON)), FALSE);
		CAboutDialog::UpdateCaption(*this);
		#pragma region System Menu
		CMenuHandle Menu = GetSystemMenu(FALSE);
		_W(Menu.AppendMenu(MF_SEPARATOR));
		_W(Menu.AppendMenu(MF_STRING, ID_APP_ABOUT, _T("&About...")));
		#pragma endregion
		return TRUE;
	}

// Window Message Handler
	LRESULT OnSysCommand(UINT nCommand, CPoint)
	{
		switch(nCommand)
		{
		case ID_APP_ABOUT:
			{
				CAboutDialog Dialog;
				Dialog.DoModal(m_hWnd);
			}
			break;
		default:
			SetMsgHandled(FALSE);
		}
		return 0;
	}
};

// TODO: Double-Click on media trace entry opens graph