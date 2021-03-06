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

#include "rofiles.h"
#include "rodshow.h"
#include "Module_i.h"
#include "Common.h"
#include "RunPropertyBag.h"
#include "RunEvent.h"

INT_PTR DoFilterGraphListPropertySheetModal(HWND hParentWindow = GetActiveWindow(), COptions* pOptions = NULL);

HRESULT FilterGraphHelper_DoPropertyFrameModal(LONG nParentWindowHandle);
HRESULT FilterGraphHelper_DoFilterGraphListModal(LONG nParentWindowHandle);
HRESULT FilterGraphHelper_OpenGraphStudioNext(LONG nParentWindowHandle, LPCWSTR pszMonikerDisplayName, VARIANT_BOOL* pbResult);
HRESULT FilterGraphHelper_OpenGraphEdit(LONG nParentWindowHandle, LPCWSTR pszMonikerDisplayName, VARIANT_BOOL* pbResult);

VOID MediaSampleTrace_Reset(DWORD nProcessIdentifier);
CString MediaSampleTrace_Get(DWORD nProcessIdentifier);
CComPtr<IUnknown> MediaSampleTrace_Lock();

////////////////////////////////////////////////////////////
// CRunPropertyBagPropertyPage

class ATL_NO_VTABLE CRunPropertyBagPropertyPage :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CRunPropertyBagPropertyPage, &__uuidof(RunPropertyBagPropertyPage)>,
	public COlePropertyPageT<CRunPropertyBagPropertyPage>,
	public CDialogResize<CRunPropertyBagPropertyPage>
{
public:
	enum { IDR = IDR_GENERIC_RUNPROPERTYBAG_PROPERTYPAGE };
	enum { IDD = IDD_GENERIC_RUNPROPERTYBAG };

BEGIN_COM_MAP(CRunPropertyBagPropertyPage)
	COM_INTERFACE_ENTRY(IPropertyPage2)
	COM_INTERFACE_ENTRY(IPropertyPage)
END_COM_MAP()

BEGIN_MSG_MAP_EX(CRunPropertyBagPropertyPage)
	CHAIN_MSG_MAP(COlePropertyPage)
	CHAIN_MSG_MAP(CDialogResize<CRunPropertyBagPropertyPage>)
	MSG_WM_INITDIALOG(OnInitDialog)
	MSG_WM_DESTROY(OnDestroy)
	COMMAND_ID_HANDLER_EX(IDC_GENERIC_RUNPROPERTYBAG_REFRESH, OnRefresh)
	COMMAND_ID_HANDLER_EX(IDC_GENERIC_RUNPROPERTYBAG_COPY, OnCopy)
	COMMAND_ID_HANDLER_EX(IDC_GENERIC_RUNPROPERTYBAG_SAVEAS, OnSaveAs)
	REFLECT_NOTIFICATIONS()
END_MSG_MAP()

BEGIN_DLGRESIZE_MAP(CRunPropertyBagPropertyPage)
	DLGRESIZE_CONTROL(IDC_GENERIC_RUNPROPERTYBAG_INTRODUCTION, DLSZ_SIZE_X)
	DLGRESIZE_CONTROL(IDC_GENERIC_RUNPROPERTYBAG_TEXT, DLSZ_SIZE_X | DLSZ_SIZE_Y)
	DLGRESIZE_CONTROL(IDC_GENERIC_RUNPROPERTYBAG_REFRESH, DLSZ_MOVE_Y)
	DLGRESIZE_CONTROL(IDC_GENERIC_RUNPROPERTYBAG_COPY, DLSZ_MOVE_Y)
	DLGRESIZE_CONTROL(IDC_GENERIC_RUNPROPERTYBAG_SAVEAS, DLSZ_MOVE_Y)
END_DLGRESIZE_MAP()

private:
	BOOL m_bActivating;
	CRoEdit m_TextEdit;
	CFont m_TextFont;
	CButton m_CopyButton;
	CButton m_SaveAsButton;
	CRoMapT<INT_PTR, BOOL> m_ChangeMap;

public:
// CRunPropertyBagPropertyPage
	static CString GetObjectFriendlyName()
	{
		return _StringHelper::GetLine(IDR, 2);
	}
	static HRESULT WINAPI UpdateRegistry(BOOL bRegister)
	{
		_Z2(atlTraceRegistrar, 2, _T("bRegister %d\n"), bRegister);
		return DefaultUpdateRegistry(bRegister);
	}
	CRunPropertyBagPropertyPage()
	{
		_Z4_THIS();
	}
	~CRunPropertyBagPropertyPage()
	{
		_Z4_THIS();
	}
	VOID UpdateControls()
	{
		const INT nLextLength = m_TextEdit.GetWindowTextLength();
		m_CopyButton.EnableWindow(nLextLength > 0);
		m_SaveAsButton.EnableWindow(nLextLength > 0);
	}
	VOID UpdateText()
	{
		CString sText;
		_A(GetObjectCount() == 1);
		m_TextEdit.SetValue(CRunPropertyBagHelper::GetPropertyBagText(GetObject(0)));
	}

// Window Message Handler
	LRESULT OnInitDialog(HWND, LPARAM)
	{
		m_bActivating = TRUE;
		_ATLTRY
		{
			CWaitCursor WaitCursor;
			m_TextEdit = GetDlgItem(IDC_GENERIC_RUNPROPERTYBAG_TEXT);
			CLogFont TextFont;
			CFontHandle(AtlGetDefaultGuiFont()).GetLogFont(TextFont);
			_tcsncpy_s(TextFont.lfFaceName, _T("Courier New"), _TRUNCATE);
			TextFont.SetHeight(8);
			m_TextFont = TextFont.CreateFontIndirect();
			m_TextEdit.SetFont(m_TextFont);
			//m_RefreshButton = GetDlgItem(IDC_GENERIC_RUNEVENT_REFRESH);
			m_CopyButton = GetDlgItem(IDC_GENERIC_RUNPROPERTYBAG_COPY);
			m_SaveAsButton = GetDlgItem(IDC_GENERIC_RUNPROPERTYBAG_SAVEAS);
			DlgResize_Init(FALSE);
			_A(GetObjectCount() >= 1);
			//const CComQIPtr<IRunPropertyBagAware> pRunPropertyBagAware = GetObject(0);
			//__D(pRunPropertyBagAware, E_NOINTERFACE);
			UpdateText();
			UpdateControls();
			m_ChangeMap.RemoveAll();
			m_bActivating = FALSE;
		}
		_ATLCATCH(Exception)
		{
			AtlExceptionMessageBox(m_hWnd, Exception);
			for(CWindow Window = GetWindow(GW_CHILD); Window.IsWindow(); Window = Window.GetWindow(GW_HWNDNEXT))
				Window.EnableWindow(FALSE);
		}
		return TRUE;
	}
	LRESULT OnDestroy()
	{
		return 0;
	}
	LRESULT OnRefresh(UINT, INT, HWND)
	{
		CWaitCursor WaitCursor;
		UpdateText();
		UpdateControls();
		return 0;
	}
	LRESULT OnCopy(UINT, INT, HWND)
	{
		SetClipboardText(m_hWnd, m_TextEdit.GetValue());
		MessageBeep(MB_OK);	
		return 0;
	}
	LRESULT OnSaveAs(UINT, INT, HWND)
	{
		static const COMDLG_FILTERSPEC g_pFilter[] = 
		{
			{ _T("Text Files"), _T("*.txt") },
			{ _T("BZip2 Compressed Text Files"), _T("*.txt.bz2") },
			{ _T("All Files"), _T("*.*") },
		};
		CPath sPath = _CommonDialogHelper::QuerySavePath(m_hWnd, g_pFilter, _T("txt"));
		if(!_tcslen(sPath))
			return 0;
		CAtlFile File;
		__C(File.Create(sPath, GENERIC_WRITE, FILE_SHARE_READ, CREATE_ALWAYS));
		_ATLTRY
		{
			CStringA sText = Utf8StringFromString(CStringW(m_TextEdit.GetValue()));
			static const BYTE g_pnByteOrderMark[] = { 0xEF, 0xBB, 0xBF, 0x00 };
			sText.Insert(0, (LPCSTR) g_pnByteOrderMark);
			if(_tcsicmp(GetPathExtension(sPath), _T(".bz2")) == 0)
			{
				CLocalObjectPtr<CBzip2Item> pItem;
				pItem->SetRawData((const BYTE*) (LPCSTR) sText, sText.GetLength());
				CHeapPtr<BYTE> pnData;
				SIZE_T nDataSize = 0;
				pItem->GetData(pnData, nDataSize);
				__C(File.Write(pnData, (DWORD) nDataSize));
			} else
				__C(File.Write(sText, (DWORD) sText.GetLength()));
		}
		_ATLCATCHALL()
		{
			File.Close();
			_W(DeleteFile(sPath));
			_ATLRETHROW;
		}
		MessageBeep(MB_OK);	
		return 0;
	}

// COlePropertyPageT, IRoPropertyPageT, IPropertyPage2, IPropertyPage
	STDMETHOD(Apply)()
	{
		_Z4(atlTraceCOM, 4, _T("...\n"));
		_ATLTRY
		{
			//if(!m_ChangeMap.IsEmpty())
			{
				//CWaitCursor WaitCursor;
				//m_ChangeMap.RemoveAll();
				SetDirty(FALSE);
			}
		}
		_ATLCATCH(Exception)
		{
			_C(Exception);
		}
		return S_OK;
	}
};

OBJECT_ENTRY_AUTO(__uuidof(RunPropertyBagPropertyPage), CRunPropertyBagPropertyPage)

////////////////////////////////////////////////////////////
// CRunEventPropertyPage

class ATL_NO_VTABLE CRunEventPropertyPage :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CRunEventPropertyPage, &__uuidof(RunEventPropertyPage)>,
	public COlePropertyPageT<CRunEventPropertyPage>,
	public CDialogResize<CRunEventPropertyPage>
{
public:
	enum { IDR = IDR_GENERIC_RUNEVENT_PROPERTYPAGE };
	enum { IDD = IDD_GENERIC_RUNEVENT };

BEGIN_COM_MAP(CRunEventPropertyPage)
	COM_INTERFACE_ENTRY(IPropertyPage2)
	COM_INTERFACE_ENTRY(IPropertyPage)
END_COM_MAP()

BEGIN_MSG_MAP_EX(CRunEventPropertyPage)
	CHAIN_MSG_MAP(COlePropertyPage)
	CHAIN_MSG_MAP(CDialogResize<CRunEventPropertyPage>)
	MSG_WM_INITDIALOG(OnInitDialog)
	MSG_WM_DESTROY(OnDestroy)
	COMMAND_HANDLER_EX(IDC_GENERIC_RUNEVENT_CAPTURE, BN_CLICKED, OnCaptureButtonClicked)
	COMMAND_ID_HANDLER_EX(IDC_GENERIC_RUNEVENT_REFRESH, OnRefresh)
	COMMAND_ID_HANDLER_EX(IDC_GENERIC_RUNEVENT_COPY, OnCopy)
	COMMAND_ID_HANDLER_EX(IDC_GENERIC_RUNEVENT_SAVEAS, OnSaveAs)
	REFLECT_NOTIFICATIONS()
END_MSG_MAP()

BEGIN_DLGRESIZE_MAP(CRunEventPropertyPage)
	DLGRESIZE_CONTROL(IDC_GENERIC_RUNEVENT_CAPTURE, DLSZ_SIZE_X)
	DLGRESIZE_CONTROL(IDC_GENERIC_RUNEVENT_TEXT, DLSZ_SIZE_X | DLSZ_SIZE_Y)
	DLGRESIZE_CONTROL(IDC_GENERIC_RUNEVENT_REFRESH, DLSZ_MOVE_Y)
	DLGRESIZE_CONTROL(IDC_GENERIC_RUNEVENT_COPY, DLSZ_MOVE_Y)
	DLGRESIZE_CONTROL(IDC_GENERIC_RUNEVENT_SAVEAS, DLSZ_MOVE_Y)
END_DLGRESIZE_MAP()

public:

private:
	BOOL m_bActivating;
	CButton m_CaptureButton;
	CRoEdit m_TextEdit;
	CButton m_RefreshButton;
	CButton m_CopyButton;
	CButton m_SaveAsButton;
	CRoMapT<INT_PTR, BOOL> m_ChangeMap;

public:
// CRunEventPropertyPage
	static CString GetObjectFriendlyName()
	{
		return _StringHelper::GetLine(IDR, 2);
	}
	static HRESULT WINAPI UpdateRegistry(BOOL bRegister)
	{
		_Z2(atlTraceRegistrar, 2, _T("bRegister %d\n"), bRegister);
		return DefaultUpdateRegistry(bRegister);
	}
	CRunEventPropertyPage()
	{
		_Z4_THIS();
	}
	~CRunEventPropertyPage()
	{
		_Z4_THIS();
	}
	VOID UpdateControls()
	{
		const BOOL bCapture = m_CaptureButton.GetCheck();
		//m_TextEdit.EnableWindow(bCapture);
		m_RefreshButton.EnableWindow(bCapture);
		const INT nLextLength = m_TextEdit.GetWindowTextLength();
		m_CopyButton.EnableWindow(nLextLength > 0);
		m_SaveAsButton.EnableWindow(nLextLength > 0);
	}
	VOID Refresh()
	{
		const CComQIPtr<IRunEventAware> pRunEventAware = GetObject(0);
		if(!pRunEventAware)
			return;
		CComVariantArray vValue;
		__C(pRunEventAware->get_Value(&vValue));
		CString sText;
		_ATLTRY
		{
			if(vValue.vt > VT_NULL)
			{
				CRoArrayT<CComVariantArray> Array;
				vValue.ToElementArray(Array);
				for(SIZE_T nIndex = 0; nIndex < Array.GetCount(); nIndex++)
				{
					CRunEventHelper::CEvents::CItem Item;
					if(!Item.SetAsVariant(Array[nIndex]))
						continue;
					sText.AppendFormat(_T("%d") _T("\t") _T("%hs"), (LONG) (Item.m_nTime / 10000i64), Item.m_pszText);
					sText.Append(_T("\r\n"));
				}
			}
		}
		_ATLCATCHALL()
		{
			_Z_EXCEPTION();
		}
		m_TextEdit.SetValue(sText);
	}

// Window Message Handler
	LRESULT OnInitDialog(HWND, LPARAM)
	{
		m_bActivating = TRUE;
		_ATLTRY
		{
			m_CaptureButton = GetDlgItem(IDC_GENERIC_RUNEVENT_CAPTURE);
			m_TextEdit = GetDlgItem(IDC_GENERIC_RUNEVENT_TEXT);
			m_RefreshButton = GetDlgItem(IDC_GENERIC_RUNEVENT_REFRESH);
			m_CopyButton = GetDlgItem(IDC_GENERIC_RUNEVENT_COPY);
			m_SaveAsButton = GetDlgItem(IDC_GENERIC_RUNEVENT_SAVEAS);
			DlgResize_Init(FALSE);
			//m_OutputSampleTimeEdit = GetDlgItem(IDC_SUSPENSIONFILTER_SAMPLE_OUTPUTTIME);
			_A(GetObjectCount() >= 1);
			const CComQIPtr<IRunEventAware> pRunEventAware = GetObject(0);
			__D(pRunEventAware, E_NOINTERFACE);
			VARIANT_BOOL bCapture = ATL_VARIANT_FALSE;
			__C(pRunEventAware->get_Capture(&bCapture));
			m_CaptureButton.SetCheck(bCapture != ATL_VARIANT_FALSE);
			if(bCapture != ATL_VARIANT_FALSE)
				Refresh();
			UpdateControls();
			m_ChangeMap.RemoveAll();
			m_bActivating = FALSE;
		}
		_ATLCATCH(Exception)
		{
			AtlExceptionMessageBox(m_hWnd, Exception);
			for(CWindow Window = GetWindow(GW_CHILD); Window.IsWindow(); Window = Window.GetWindow(GW_HWNDNEXT))
				Window.EnableWindow(FALSE);
		}
		return TRUE;
	}
	LRESULT OnDestroy()
	{
		return 0;
	}
	LRESULT OnCaptureButtonClicked(UINT, INT, HWND)
	{
		CWaitCursor WaitCursor;
		const CComQIPtr<IRunEventAware> pRunEventAware = GetObject(0);
		if(pRunEventAware)
			_ATLTRY
			{
				const BOOL bCapture = m_CaptureButton.GetCheck();
				__C(pRunEventAware->put_Capture(bCapture ? ATL_VARIANT_TRUE : ATL_VARIANT_FALSE));
			}
			_ATLCATCHALL()
			{
				_Z_EXCEPTION();
			}
		UpdateControls();
		return 0;
	}
	LRESULT OnRefresh(UINT, INT, HWND)
	{
		CWaitCursor WaitCursor;
		Refresh();
		UpdateControls();
		return 0;
	}
	LRESULT OnCopy(UINT, INT, HWND)
	{
		SetClipboardText(m_hWnd, m_TextEdit.GetValue());
		MessageBeep(MB_OK);	
		return 0;
	}
	LRESULT OnSaveAs(UINT, INT, HWND)
	{
		static const COMDLG_FILTERSPEC g_pFilter[] = 
		{
			{ _T("Text Files"), _T("*.txt") },
			{ _T("BZip2 Compressed Text Files"), _T("*.txt.bz2") },
			{ _T("All Files"), _T("*.*") },
		};
		CPath sPath = _CommonDialogHelper::QuerySavePath(m_hWnd, g_pFilter, _T("txt"));
		if(!_tcslen(sPath))
			return 0;
		CAtlFile File;
		__C(File.Create(sPath, GENERIC_WRITE, FILE_SHARE_READ, CREATE_ALWAYS));
		_ATLTRY
		{
			CStringA sText = Utf8StringFromString(CStringW(m_TextEdit.GetValue()));
			static const BYTE g_pnByteOrderMark[] = { 0xEF, 0xBB, 0xBF, 0x00 };
			sText.Insert(0, (LPCSTR) g_pnByteOrderMark);
			if(_tcsicmp(GetPathExtension(sPath), _T(".bz2")) == 0)
			{
				CLocalObjectPtr<CBzip2Item> pItem;
				pItem->SetRawData((const BYTE*) (LPCSTR) sText, sText.GetLength());
				CHeapPtr<BYTE> pnData;
				SIZE_T nDataSize = 0;
				pItem->GetData(pnData, nDataSize);
				__C(File.Write(pnData, (DWORD) nDataSize));
			} else
				__C(File.Write(sText, (DWORD) sText.GetLength()));
		}
		_ATLCATCHALL()
		{
			File.Close();
			_W(DeleteFile(sPath));
			_ATLRETHROW;
		}
		MessageBeep(MB_OK);	
		return 0;
	}

// COlePropertyPageT, IRoPropertyPageT, IPropertyPage2, IPropertyPage
	STDMETHOD(Apply)()
	{
		_Z4(atlTraceCOM, 4, _T("...\n"));
		_ATLTRY
		{
			//if(!m_ChangeMap.IsEmpty())
			{
				//CWaitCursor WaitCursor;
				//m_ChangeMap.RemoveAll();
				SetDirty(FALSE);
			}
		}
		_ATLCATCH(Exception)
		{
			_C(Exception);
		}
		return S_OK;
	}
};

OBJECT_ENTRY_AUTO(__uuidof(RunEventPropertyPage), CRunEventPropertyPage)

////////////////////////////////////////////////////////////
// CFilterGraphHelper

class ATL_NO_VTABLE CFilterGraphHelper :
	public CComObjectRootEx<CComMultiThreadModelNoCS>,
	public CComCoClass<CFilterGraphHelper, &__uuidof(FilterGraphHelper)>,
	public IProvideClassInfo2Impl<&__uuidof(FilterGraphHelper), &IID_NULL>,
	public IDispatchImpl<IFilterGraphHelper>,
	public CModuleVersionInformationT<CFilterGraphHelper>
{
public:
	enum { IDR = IDR_FILTERGRAPHHELPER };

//DECLARE_REGISTRY_RESOURCEID(IDR)

BEGIN_COM_MAP(CFilterGraphHelper)
	COM_INTERFACE_ENTRY(IProvideClassInfo2)
	COM_INTERFACE_ENTRY(IProvideClassInfo)
	COM_INTERFACE_ENTRY(IFilterGraphHelper)
	COM_INTERFACE_ENTRY_IID(__uuidof(IDispatch), IFilterGraphHelper)
	COM_INTERFACE_ENTRY(IModuleVersionInformation)
END_COM_MAP()

public:

	////////////////////////////////////////////////////////
	// CProcessData

	class CProcessData
	{
	public:
		CStringW m_sDisplayName;
		DWORD m_nIdentifier;
		CPath m_sImagePath;

	public:
	// CProcessData
		CProcessData() :
			m_nIdentifier(0)
		{
		}
	};

	////////////////////////////////////////////////////////
	// CPropertyFrameDialog

	class CPropertyFrameDialog :
		public CDialogImpl<CPropertyFrameDialog>,
		public CDialogResize<CPropertyFrameDialog>,
		public CDialogWithAcceleratorsT<CPropertyFrameDialog>
	{
	public:
		enum { IDD = IDD_FILTERGRAPHHELPER_PROPERTYFRAME };

	BEGIN_MSG_MAP_EX(CPropertyFrameDialog)
		//CHAIN_MSG_MAP(CDialogImpl<CPropertyFrameDialog>)
		CHAIN_MSG_MAP(CDialogResize<CPropertyFrameDialog>)
		MSG_WM_INITDIALOG(OnInitDialog)
		MSG_WM_DESTROY(OnDestroy)
		MSG_TVN_GETINFOTIP(IDC_FILTERGRAPHHELPER_PROPERTYFRAME_TREE, OnTreeViewGetInfoTip)
		MSG_TVN_SELCHANGED(IDC_FILTERGRAPHHELPER_PROPERTYFRAME_TREE, OnTreeViewSelChanged)
		MSG_TVN_ITEMEXPANDING(IDC_FILTERGRAPHHELPER_PROPERTYFRAME_TREE, OnTreeViewItemExplanding)
		MSG_TVN_DBLCLK(IDC_FILTERGRAPHHELPER_PROPERTYFRAME_TREE, OnTreeViewDblClk)
		NOTIFY_HANDLER_EX(IDC_FILTERGRAPHHELPER_PROPERTYFRAME_REFRESH, CRoHyperStatic::NC_ANCHORCLICKED, OnRefreshAnchorClicked)
		NOTIFY_HANDLER_EX(IDC_FILTERGRAPHHELPER_PROPERTYFRAME_COPY, CRoHyperStatic::NC_ANCHORCLICKED, OnCopyAnchorClicked)
		NOTIFY_HANDLER_EX(IDC_FILTERGRAPHHELPER_PROPERTYFRAME_SAVEAS, CRoHyperStatic::NC_ANCHORCLICKED, OnSaveAsAnchorClicked)
		MSG_WM_SYSCOMMAND(OnSysCommand)
		COMMAND_ID_HANDLER_EX(IDOK, OnOk)
		COMMAND_ID_HANDLER_EX(IDCANCEL, OnCancel)
		COMMAND_ID_HANDLER_EX(IDC_FILTERGRAPHHELPER_PROPERTYFRAME_APPLY, OnApply)
		COMMAND_ID_HANDLER_EX(IDC_FILTERGRAPHHELPER_PROPERTYFRAME_TREE_WALKUP, OnTreeWalkUp)
		COMMAND_ID_HANDLER_EX(IDC_FILTERGRAPHHELPER_ACTION_OPENGSN, OnActionCommand)
		COMMAND_ID_HANDLER_EX(IDC_FILTERGRAPHHELPER_ACTION_OPENGE, OnActionCommand)
		COMMAND_ID_HANDLER_EX(IDC_FILTERGRAPHHELPER_ACTION_OPENLIST, OnActionCommand)
		REFLECT_NOTIFICATIONS()
	END_MSG_MAP()

	BEGIN_DLGRESIZE_MAP(CPropertyFrameDialog)
		DLGRESIZE_CONTROL(IDC_FILTERGRAPHHELPER_PROPERTYFRAME_TREE, DLSZ_SIZE_Y)
		DLGRESIZE_CONTROL(IDC_FILTERGRAPHHELPER_PROPERTYFRAME_TEXT, DLSZ_SIZE_X | DLSZ_SIZE_Y)
		DLGRESIZE_CONTROL(IDC_FILTERGRAPHHELPER_PROPERTYFRAME_REFRESH, DLSZ_MOVE_Y)
		DLGRESIZE_CONTROL(IDC_FILTERGRAPHHELPER_PROPERTYFRAME_COPY, DLSZ_MOVE_Y)
		DLGRESIZE_CONTROL(IDC_FILTERGRAPHHELPER_PROPERTYFRAME_SAVEAS, DLSZ_MOVE_Y)
		DLGRESIZE_CONTROL(IDOK, DLSZ_MOVE_X | DLSZ_MOVE_Y)
		DLGRESIZE_CONTROL(IDCANCEL, DLSZ_MOVE_X | DLSZ_MOVE_Y)
		DLGRESIZE_CONTROL(IDC_FILTERGRAPHHELPER_PROPERTYFRAME_APPLY, DLSZ_MOVE_X | DLSZ_MOVE_Y)
	END_DLGRESIZE_MAP()

	public:

		////////////////////////////////////////////////////
		// CPropertyPageSite

		class ATL_NO_VTABLE CPropertyPageSite :
			public CComObjectRootEx<CComSingleThreadModel>,
			public IPropertyPageSite
		{
			friend class CPropertyFrameDialog;

		public:

		BEGIN_COM_MAP(CPropertyPageSite)
			COM_INTERFACE_ENTRY(IPropertyPageSite)
		END_COM_MAP()

		private:
			CPropertyFrameDialog* m_pOwner;
			CComPtr<IUnknown> m_pUnknown;
			CComPtr<IPropertyPage> m_pPropertyPage;
			CString m_sTitle;
			DWORD m_nStatus;

		public:
		// CPropertyPageSite
			CPropertyPageSite() :
				m_pOwner(NULL)
			{
			}
			VOID Initialize(CPropertyFrameDialog* pOwner, IUnknown* pUnknown, IPropertyPage* pPropertyPage)
			{
				_A(pOwner && pUnknown && pPropertyPage);
				_A(!m_pOwner);
				m_pOwner = pOwner;
				m_pUnknown = pUnknown;
				m_pPropertyPage = pPropertyPage;
				__C(pPropertyPage->SetObjects(1, &m_pUnknown.p));
				PROPPAGEINFO Information;
				ZeroMemory(&Information, sizeof Information);
				Information.cb = sizeof Information;
				__C(pPropertyPage->GetPageInfo(&Information));
				CStringW sTitle = Information.pszTitle;
				CoTaskMemFree(Information.pszTitle);
				CoTaskMemFree(Information.pszDocString);
				CoTaskMemFree(Information.pszHelpFile);
				m_sTitle = CString(sTitle);
				m_nStatus = 0;
				__C(pPropertyPage->SetPageSite(this));
			}
			VOID Terminate()
			{
				if(m_pPropertyPage)
				{
					_V(m_pPropertyPage->SetPageSite(NULL));
					m_pPropertyPage.Release();
				}
				m_pUnknown.Release();
				m_pOwner = NULL;
			}
			BOOL IsDirty()
			{
				return m_nStatus & PROPPAGESTATUS_DIRTY;
			}

		// IPropertyPageSite
			STDMETHOD(OnStatusChange)(DWORD nFlags)
			{
				_Z4(atlTraceCOM, 4, _T("nFlags 0x%x\n"), nFlags);
				m_nStatus = nFlags;
				m_pOwner->HandleStatusChange(this);
				return S_OK;
			}
			STDMETHOD(GetLocaleID)(LCID* pLocaleIdentifier)
			{
				_Z4(atlTraceCOM, 4, _T("...\n"));
				pLocaleIdentifier;
				return E_NOTIMPL;
			}
			STDMETHOD(GetPageContainer)(IUnknown** ppUnknown)
			{
				_Z4(atlTraceCOM, 4, _T("...\n"));
				ppUnknown;
				return E_NOTIMPL;
			}
			STDMETHOD(TranslateAccelerator)(MSG* pMessage)
			{
				_Z4(atlTraceCOM, 4, _T("...\n"));
				pMessage;
				return E_NOTIMPL;
			}
		};

		////////////////////////////////////////////////////
		// CMemoryAllocatorDialog

		class CMemoryAllocatorDialog :
			public CDialogImpl<CMemoryAllocatorDialog>,
			public CDialogResize<CMemoryAllocatorDialog>
		{
		public:
			enum { IDD = IDD_FILTERGRAPHHELPER_MEMORYALLOCATOR };

		BEGIN_MSG_MAP_EX(CMemoryAllocatorDialog)
			//CHAIN_MSG_MAP(CDialogImpl<CMemoryAllocatorDialog>)
			CHAIN_MSG_MAP(CDialogResize<CMemoryAllocatorDialog>)
			MSG_WM_INITDIALOG(OnInitDialog)
			MSG_LVN_GETDISPINFO(IDC_FILTERGRAPHHELPER_MEMORYALLOCATOR_LIST, OnListViewGetDispInfo)
			MSG_LVN_GETINFOTIP(IDC_FILTERGRAPHHELPER_MEMORYALLOCATOR_LIST, OnListViewGetInfoTip)
			COMMAND_ID_HANDLER_EX(IDC_FILTERGRAPHHELPER_MEMORYALLOCATOR_REFRESH, OnRefresh)
			REFLECT_NOTIFICATIONS()
		END_MSG_MAP()

		BEGIN_DLGRESIZE_MAP(CMemoryAllocatorDialog)
			DLGRESIZE_CONTROL(IDC_FILTERGRAPHHELPER_MEMORYALLOCATOR_LIST, DLSZ_SIZE_X | DLSZ_SIZE_Y)
			DLGRESIZE_CONTROL(IDC_FILTERGRAPHHELPER_MEMORYALLOCATOR_REFRESH, DLSZ_MOVE_Y)
		END_DLGRESIZE_MAP()

		public:

			////////////////////////////////////////////////
			// CMemoryAllocatorData

			class CMemoryAllocatorData
			{
			public:
				LONG_PTR m_nIdentifier;
				CString m_sNames;
				HRESULT m_nMemAllocatorResult;
				LONG m_nBufferCount;
				LONG m_nBufferSize;
				LONG m_nBufferAlign;
				LONG m_nBufferPrefix;
				HRESULT m_nMemAllocatorCallbackTempResult;
				LONG m_nFreeBufferCount;

			public:
			// CMemoryAllocatorData
				VOID Initialize(CRoArrayT<CComVariantArray>& Array)
				{
					SIZE_T nIndex = 0;
					__D(nIndex + 2 + 1 + 1 <= Array.GetCount(), E_UNNAMED);
					m_nIdentifier = Array[nIndex++].GetAsType(VT_I4).lVal;
					m_sNames = Array[nIndex++].GetAsType(VT_BSTR).bstrVal;
					m_nMemAllocatorResult = Array[nIndex++].GetAsType(VT_I4).lVal;
					if(SUCCEEDED(m_nMemAllocatorResult))
					{
						__D(nIndex + 4 <= Array.GetCount(), E_UNNAMED);
						m_nBufferCount = Array[nIndex++].GetAsType(VT_I4).lVal;
						m_nBufferSize = Array[nIndex++].GetAsType(VT_I4).lVal;
						m_nBufferAlign = Array[nIndex++].GetAsType(VT_I4).lVal;
						m_nBufferPrefix = Array[nIndex++].GetAsType(VT_I4).lVal;
					}
					m_nMemAllocatorCallbackTempResult = Array[nIndex++].GetAsType(VT_I4).lVal;
					if(SUCCEEDED(m_nMemAllocatorCallbackTempResult))
					{
						__D(nIndex + 1 <= Array.GetCount(), E_UNNAMED);
						m_nFreeBufferCount = Array[nIndex++].GetAsType(VT_I4).lVal;
					}
				}
			};

		private:
			CPropertyFrameDialog* m_pOwner;
			BOOL m_bActivating;
			CStatic m_TitleStatic;
			CFont m_TitleFont;
			CRoListViewT<CMemoryAllocatorData, CRoListControlDataTraitsT> m_ListView;
			CButton m_RefreshButton;
			CRoMapT<INT_PTR, BOOL> m_ChangeMap;

		public:
		// CMemoryAllocatorDialog
			VOID UpdateListView()
			{
				CWindowRedraw ListViewRedraw(m_ListView);
				CRoArrayT<INT> ValidItemArray;
				_ATLTRY
				{
					const CComQIPtr<IFilterGraphMemoryAllocatorData> pFilterGraphMemoryAllocatorData = m_pOwner->m_Owner.m_pFilterGraph;
					if(pFilterGraphMemoryAllocatorData)
					{
						CComVariantArray vValue;
						__C(pFilterGraphMemoryAllocatorData->get_Value(&vValue));
						if(vValue.vt > VT_NULL)
						{
							CRoArrayT<CComVariantArray> ItemArray;
							vValue.ToElementArray(ItemArray);
							for(auto&& vItemValue: ItemArray)
							{
								CRoArrayT<CComVariantArray> ItemItemArray;
								vItemValue.ToElementArray(ItemItemArray);
								// SUGG: Reuse existing list view items instead of full list replacement
								CMemoryAllocatorData Data;
								Data.Initialize(ItemItemArray);
								const INT nItem = m_ListView.InsertItem(m_ListView.GetItemCount(), Data);
								ValidItemArray.Add(nItem);
							}
						}
					}
				}
				_ATLCATCHALL()
				{
					m_ListView.DeleteAllItems();
					ValidItemArray.RemoveAll();
					_ATLRETHROW;
				}
				for(INT nItem = m_ListView.GetItemCount() - 1; nItem >= 0; nItem--)
					if(!ValidItemArray.FindFirst(nItem))
						m_ListView.DeleteItem(nItem);
			}

		// Window Message Handler
			LRESULT OnInitDialog(HWND, LPARAM lParam)
			{
				m_pOwner = (CPropertyFrameDialog*) lParam;
				m_bActivating = TRUE;
				_ATLTRY
				{
					CWaitCursor WaitCursor;
					m_TitleStatic = GetDlgItem(IDC_FILTERGRAPHHELPER_MEMORYALLOCATOR_TITLE);
					CreateTitleFont(m_TitleFont, m_TitleStatic);
					m_ListView.Initialize(GetDlgItem(IDC_FILTERGRAPHHELPER_MEMORYALLOCATOR_LIST));
					m_RefreshButton = GetDlgItem(IDC_FILTERGRAPHHELPER_MEMORYALLOCATOR_REFRESH);
					DlgResize_Init(FALSE, FALSE);
					_ATLTRY
					{
						UpdateListView();
					}
					_ATLCATCHALL()
					{
						_Z_EXCEPTION();
					}
					m_bActivating = FALSE;
				}
				_ATLCATCH(Exception)
				{
					for(CWindow Window = GetWindow(GW_CHILD); Window; Window = Window.GetWindow(GW_HWNDNEXT))
						Window.EnableWindow(FALSE);
					AtlExceptionMessageBox(m_hWnd, Exception);
				}
				return TRUE;
			}
			LRESULT OnListViewGetDispInfo(NMLVDISPINFO* pHeader)
			{
				const CMemoryAllocatorData& Data = m_ListView.DataFromParameter(pHeader->item.lParam);
				if(pHeader->item.mask & LVIF_TEXT)
				{
					CString& sTextBuffer = m_ListView.GetTextBufferString(TRUE);
					switch(pHeader->item.iSubItem)
					{
					case 1: // Buffer Count
						if(SUCCEEDED(Data.m_nMemAllocatorResult))
							sTextBuffer = _StringHelper::FormatNumber(Data.m_nBufferCount);
						break;
					case 2: // Free Buffer Count
						if(SUCCEEDED(Data.m_nMemAllocatorCallbackTempResult))
							sTextBuffer = _StringHelper::FormatNumber(Data.m_nFreeBufferCount);
						break;
					case 3: // Buffer Size
						if(SUCCEEDED(Data.m_nMemAllocatorResult))
							sTextBuffer = _StringHelper::FormatNumber(Data.m_nBufferSize);
						break;
					default: // Name
						sTextBuffer = Data.m_sNames;
					}
					pHeader->item.pszText = m_ListView.GetTextBuffer();
				}
				return 0;
			}
			LRESULT OnListViewGetInfoTip(NMLVGETINFOTIP* pHeader)
			{
				const CMemoryAllocatorData& Data = m_ListView.GetItemData(pHeader->iItem);
				CString& sTextBuffer = m_ListView.GetTextBufferString(TRUE);
				//sTextBuffer.AppendFormat(_T("Identifier: 0x%08X") _T("\r\n"), Data.m_nIdentifier);
				if(SUCCEEDED(Data.m_nMemAllocatorResult))
				{
					sTextBuffer.AppendFormat(_T("Buffer Count: %s") _T("\r\n"), _StringHelper::FormatNumber(Data.m_nBufferCount));
					sTextBuffer.AppendFormat(_T("Buffer Size: %s (%s total)") _T("\r\n"), _StringHelper::FormatNumber(Data.m_nBufferSize), _StringHelper::FormatNumber(Data.m_nBufferCount * Data.m_nBufferSize));
					if(Data.m_nBufferAlign > 1)
						sTextBuffer.AppendFormat(_T("Buffer Alignment: %s") _T("\r\n"), _StringHelper::FormatNumber(Data.m_nBufferAlign));
					if(Data.m_nBufferPrefix > 0)
						sTextBuffer.AppendFormat(_T("Buffer Prefix: %s") _T("\r\n"), _StringHelper::FormatNumber(Data.m_nBufferPrefix));
				} else
					sTextBuffer.AppendFormat(_T("IMemAllocator: %s") _T("\r\n"), Ds::FormatResult(Data.m_nMemAllocatorResult, _T("Error 0x%08X")));
				if(SUCCEEDED(Data.m_nMemAllocatorCallbackTempResult))
				{
					sTextBuffer.AppendFormat(_T("Free Buffer Count: %s") _T("\r\n"), _StringHelper::FormatNumber(Data.m_nFreeBufferCount));
				} else
					sTextBuffer.AppendFormat(_T("IMemAllocatorCallbackTemp: %s") _T("\r\n"), Ds::FormatResult(Data.m_nMemAllocatorCallbackTempResult, _T("Error 0x%08X")));
				CString sNames = Data.m_sNames;
				sNames.Replace(_T(", "), _T("|"));
				CRoArrayT<CString> Array;
				_StringHelper::Split(sNames, _T('|'), Array);
				if(!Array.IsEmpty())
				{
					sTextBuffer.Append(_T("\r\n") _T("Pin Connections:") _T("\r\n"));
					for(auto&& sName: Array)
					{
						sTextBuffer.AppendFormat(_T("  ") _T("%s") _T("\r\n"), sName);
					}
				}
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
			LRESULT OnRefresh(UINT, INT, HWND)
			{
				UpdateListView();
				return 0;
			}
		};

		////////////////////////////////////////////////////
		// CActionDialog

		class CActionDialog :
			public CDialogImpl<CActionDialog>,
			public CDialogResize<CActionDialog>
		{
		public:
			enum { IDD = IDD_FILTERGRAPHHELPER_ACTION };

		BEGIN_MSG_MAP_EX(CActionDialog)
			//CHAIN_MSG_MAP(CDialogImpl<CActionDialog>)
			CHAIN_MSG_MAP(CDialogResize<CActionDialog>)
			MSG_WM_INITDIALOG(OnInitDialog)
			COMMAND_ID_HANDLER_EX(IDC_FILTERGRAPHHELPER_ACTION_SAVEAS, OnSaveAs)
			COMMAND_ID_HANDLER_EX(IDC_FILTERGRAPHHELPER_ACTION_OPENGSN, OnOpenGsn)
			COMMAND_ID_HANDLER_EX(IDC_FILTERGRAPHHELPER_ACTION_OPENGE, OnOpenGe)
			COMMAND_ID_HANDLER_EX(IDC_FILTERGRAPHHELPER_ACTION_OPENLIST, OnOpenList)
			REFLECT_NOTIFICATIONS()
		END_MSG_MAP()

		BEGIN_DLGRESIZE_MAP(CActionDialog)
			//DLGRESIZE_CONTROL(IDC_FILTERGRAPHHELPER_ACTION_, DLSZ_SIZE_X | DLSZ_SIZE_Y)
		END_DLGRESIZE_MAP()

		private:
			CPropertyFrameDialog* m_pOwner;
			BOOL m_bActivating;
			CStatic m_TitleStatic;
			CFont m_TitleFont;
			CButton m_SaveAsButton;
			CRoHyperStatic m_SaveAsDescriptionStatic;
			CButton m_OpenGsnButton;
			CRoHyperStatic m_OpenGsnDescriptionStatic;
			CButton m_OpenGeButton;
			CRoHyperStatic m_OpenGeDescriptionStatic;
			CButton m_OpenListButton;
			CRoHyperStatic m_OpenListDescriptionStatic;
			CStringW m_sFilterGraphMonikerDisplayName;
			CRoMapT<INT_PTR, BOOL> m_ChangeMap;

		public:
		// CActionDialog

		// Window Message Handler
			LRESULT OnInitDialog(HWND, LPARAM lParam)
			{
				m_pOwner = (CPropertyFrameDialog*) lParam;
				m_bActivating = TRUE;
				_ATLTRY
				{
					CWaitCursor WaitCursor;
					m_TitleStatic = GetDlgItem(IDC_FILTERGRAPHHELPER_ACTION_TITLE);
					CreateTitleFont(m_TitleFont, m_TitleStatic);
					m_SaveAsButton = GetDlgItem(IDC_FILTERGRAPHHELPER_ACTION_SAVEAS);
					_W(m_SaveAsDescriptionStatic.SubclassWindow(GetDlgItem(IDC_FILTERGRAPHHELPER_ACTION_SAVEASDESCRIPTION)));
					m_OpenGsnButton = GetDlgItem(IDC_FILTERGRAPHHELPER_ACTION_OPENGSN);
					_W(m_OpenGsnDescriptionStatic.SubclassWindow(GetDlgItem(IDC_FILTERGRAPHHELPER_ACTION_OPENGSNDESCRIPTION)));
					m_OpenGeButton = GetDlgItem(IDC_FILTERGRAPHHELPER_ACTION_OPENGE);
					_W(m_OpenGeDescriptionStatic.SubclassWindow(GetDlgItem(IDC_FILTERGRAPHHELPER_ACTION_OPENGEDESCRIPTION)));
					m_OpenListButton = GetDlgItem(IDC_FILTERGRAPHHELPER_ACTION_OPENLIST);
					_W(m_OpenListDescriptionStatic.SubclassWindow(GetDlgItem(IDC_FILTERGRAPHHELPER_ACTION_OPENLISTDESCRIPTION)));
					//DlgResize_Init(FALSE, FALSE);
					_ATLTRY
					{
						m_sFilterGraphMonikerDisplayName.Empty();
						const CComQIPtr<ISpy> pSpy = m_pOwner->m_Owner.GetFilterGraph();
						if(pSpy)
						{
							CComBSTR sFilterGraphMonikerDisplayName;
							__C(pSpy->get_MonikerDisplayName(&sFilterGraphMonikerDisplayName));
							m_sFilterGraphMonikerDisplayName = sFilterGraphMonikerDisplayName;
						}
					}
					_ATLCATCHALL()
					{
						_Z_EXCEPTION();
					}
					const BOOL bMonikerDisplayNameAvailable = !m_sFilterGraphMonikerDisplayName.IsEmpty();
					m_OpenGsnButton.EnableWindow(bMonikerDisplayNameAvailable);
					m_OpenGsnDescriptionStatic.EnableWindow(bMonikerDisplayNameAvailable);
					m_OpenGeButton.EnableWindow(bMonikerDisplayNameAvailable);
					m_OpenGeDescriptionStatic.EnableWindow(bMonikerDisplayNameAvailable);
					m_bActivating = FALSE;
				}
				_ATLCATCH(Exception)
				{
					for(CWindow Window = GetWindow(GW_CHILD); Window; Window = Window.GetWindow(GW_HWNDNEXT))
						Window.EnableWindow(FALSE);
					AtlExceptionMessageBox(m_hWnd, Exception);
				}
				return TRUE;
			}
			LRESULT OnSaveAs(UINT, INT, HWND)
			{
				static const COMDLG_FILTERSPEC g_pFilter[] = 
				{
					{ _T("GraphEdit Files"), _T("*.grf") },
					{ _T("All Files"), _T("*.*") },
				};
				CPath sPath = _CommonDialogHelper::QuerySavePath(m_hWnd, g_pFilter, _T("grf"));
				if(_tcslen(sPath) == 0)
					return 0;
				#pragma region Save
				// NOTE: See http://msdn.microsoft.com/en-us/library/windows/desktop/dd377551
				const CComQIPtr<IPersistStream> pPersistStream = m_pOwner->m_Owner.GetFilterGraph();
				__D(pPersistStream, E_NOINTERFACE);
				CComPtr<IStorage> pStorage;
				{
					__C(StgCreateDocfile(CStringW(sPath), STGM_CREATE | STGM_TRANSACTED | STGM_READWRITE | STGM_SHARE_EXCLUSIVE, 0, &pStorage));
					CComPtr<IStream> pStream;
					__C(pStorage->CreateStream(L"ActiveMovieGraph", STGM_WRITE | STGM_CREATE | STGM_SHARE_EXCLUSIVE, 0, 0, &pStream));
					__C(pPersistStream->Save(pStream, TRUE));
				}
				__C(pStorage->Commit(STGC_DEFAULT));
				#pragma endregion
				MessageBeep(MB_OK);
				return 0;
			}
			LRESULT OnOpenGsn(UINT, INT, HWND)
			{
				OpenMonikerWithGsn(m_sFilterGraphMonikerDisplayName, m_hWnd);
				return 0;
			}
			LRESULT OnOpenGe(UINT, INT, HWND)
			{
				OpenMonikerWithGe(m_sFilterGraphMonikerDisplayName, m_hWnd);
				return 0;
			}
			LRESULT OnOpenList(UINT, INT, HWND)
			{
				DoFilterGraphListPropertySheetModal(m_hWnd, &m_pOwner->m_Owner.m_Options);
				return 0;
			}
		};

		////////////////////////////////////////////////////
		// CEmailLogDialog

		class CEmailLogDialog :
			public CDialogImpl<CEmailLogDialog>,
			public CDialogResize<CEmailLogDialog>
		{
		public:
			enum { IDD = IDD_FILTERGRAPHHELPER_EMAIL_LOG };

		BEGIN_MSG_MAP_EX(CEmailLogDialog)
			//CHAIN_MSG_MAP(CDialogImpl<CEmailLogDialog>)
			CHAIN_MSG_MAP(CDialogResize<CEmailLogDialog>)
			MSG_WM_INITDIALOG(OnInitDialog)
			MSG_LVN_GETDISPINFO(IDC_FILTERGRAPHHELPER_EMAIL_LOG_FILE, OnFileListViewGetDispInfo)
			//MSG_LVN_GETINFOTIP()
			MSG_LVN_ITEMCHANGED(IDC_FILTERGRAPHHELPER_EMAIL_LOG_FILE, OnFileListViewItemChanged)
			//COMMAND_HANDLER_EX(IDC_FILTERGRAPHHELPER_EMAIL_LOG_TRUNCATE, CBN_CHANGE, OnChanged)
			//COMMAND_HANDLER_EX(IDC_FILTERGRAPHHELPER_EMAIL_LOG_DELETE, CBN_CHANGE, OnChanged)
			REFLECT_NOTIFICATIONS()
		END_MSG_MAP()

		BEGIN_DLGRESIZE_MAP(CEmailLogDialog)
			DLGRESIZE_CONTROL(IDC_FILTERGRAPHHELPER_EMAIL_LOG_FILE, DLSZ_SIZE_X | DLSZ_SIZE_Y)
			DLGRESIZE_CONTROL(IDC_FILTERGRAPHHELPER_EMAIL_LOG_TRUNCATETITLE, DLSZ_MOVE_Y)
			DLGRESIZE_CONTROL(IDC_FILTERGRAPHHELPER_EMAIL_LOG_TRUNCATE, DLSZ_MOVE_Y)
			DLGRESIZE_CONTROL(IDC_FILTERGRAPHHELPER_EMAIL_LOG_DELETETITLE, DLSZ_MOVE_Y)
			DLGRESIZE_CONTROL(IDC_FILTERGRAPHHELPER_EMAIL_LOG_DELETE, DLSZ_MOVE_Y)
		END_DLGRESIZE_MAP()

		public:

			////////////////////////////////////////////////
			// CFileData

			class CFileData
			{
			public:
				UINT m_nLocation;
				CPath m_sPath;
				ULONGLONG m_nSize;
				FILETIME m_UpdateTime;

			public:
			// CFileData
				CFileData(UINT nLocation, LPCTSTR pszDirectory, WIN32_FIND_DATA FindData)
				{
					m_nLocation = nLocation;
					m_sPath.Combine(pszDirectory, FindData.cFileName);
					m_nSize = ((ULONGLONG) FindData.nFileSizeHigh << 32) + FindData.nFileSizeLow;
					m_UpdateTime = FindData.ftLastWriteTime;
				}
				FILETIME GetLocalUpdateTime() const
				{
					FILETIME UpdateTime;
					_W(FileTimeToLocalFileTime(&m_UpdateTime, &UpdateTime));
					return UpdateTime;
				}
			};

			////////////////////////////////////////////////
			// CFileDataSortTraits

			class CFileDataSortTraits :
				public CDefaultSortTraitsT<CFileData>
			{
			public:
			// CFileDataSortTraits
				static INT_PTR CompareElements(const CFileData& FileData1, const CFileData& FileData2, PARAMETERARGUMENT Parameter)
				{
					const INT nLocation = FileData1.m_nLocation - FileData2.m_nLocation;
					if(nLocation)
						return nLocation;
					return _tcsicmp(FindFileName(FileData1.m_sPath), FindFileName(FileData2.m_sPath));
				}
			};

			////////////////////////////////////////////////
			// CFileDataArray

			class CFileDataArray :
				public CRoArrayT<CFileData>
			{
			public:
			// CFileDataArray
				static BOOL CompareLocation(const CFileData& FileData, UINT nLocation)
				{
					return FileData.m_nLocation == nLocation;
				}
				SIZE_T GetCountForLocation(UINT nLocation)
				{
					return GetCountThatT<UINT>(&CFileDataArray::CompareLocation, nLocation);
				}
			};

			////////////////////////////////////////////////
			// CSelectedFileData

			class CSelectedFileData
			{
			public:
				CPath m_sPath;
				CString m_sName;

			public:
			// CSelectedFileData
			};

		private:
			CPropertyFrameDialog* m_pOwner;
			BOOL m_bActivating;
			CStatic m_TitleStatic;
			CFont m_TitleFont;
			CRoListViewT<CFileData, CRoListControlDataTraitsT> m_FileListView;
			INT m_nFileListViewGroupViewEnabled;
			CRoComboBoxT<> m_TruncateComboBox;
			CRoComboBoxT<> m_DeleteComboBox;
			CRoMapT<INT_PTR, BOOL> m_ChangeMap;

		public:
		// CEmailLogDialog
			CEmailLogDialog()
			{
			}
			VOID UpdateControls()
			{
			}
			VOID InitializeFileListView()
			{
				CWindowRedraw FileListViewRedraw(m_FileListView);
				m_FileListView.DeleteAllItems();
				m_FileListView.RemoveAllGroups();
				#pragma region File
				CFileDataArray FileDataArray;
				static DWORD g_pnLocations[] = 
				{
					CSIDL_COMMON_APPDATA,
					CSIDL_APPDATA,
				};
				for(SIZE_T nLocationIndex = 0; nLocationIndex < DIM(g_pnLocations); nLocationIndex++)
					_ATLTRY
					{
						TCHAR pszDirectory[MAX_PATH] = { 0 };
						if(!SHGetSpecialFolderPath(NULL, pszDirectory, g_pnLocations[nLocationIndex], FALSE))
							continue;
						CFindFiles FindFiles;
						for(BOOL bFound = FindFiles.FindFirstFile(pszDirectory, _T("*.*")); bFound; bFound = FindFiles.FindNextFile())
						{
							const WIN32_FIND_DATA& Data = FindFiles.GetFindData();
							if(Data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
								continue; // Directory
							LPCTSTR pszExtension = FindExtension(Data.cFileName);
							if(!pszExtension || !(_tcsicmp(pszExtension, _T(".log")) == 0 || _tcsicmp(pszExtension, _T(".dmp")) == 0))
								continue; // Extension Mismatch
							FileDataArray.Add(CFileData((UINT) nLocationIndex, pszDirectory, Data));
						}
					}
					_ATLCATCHALL()
					{
						_Z_EXCEPTION();
					}
				_SortHelper::QuickSort<CFileDataSortTraits>(FileDataArray);
				if(m_nFileListViewGroupViewEnabled >= 0)
				{
					if(FileDataArray.GetCountForLocation(0))
						m_FileListView.InsertGroup(0, 0, _T("Local Machine (Common AppData)"));
					if(FileDataArray.GetCountForLocation(1))
						m_FileListView.InsertGroup(1, 1, _T("Current User (AppData)"));
				}
				CPath sPrivateLogFileName = FindFileName(GetModulePath());
				sPrivateLogFileName.RenameExtension(_T(".log"));
				for(SIZE_T nIndex = 0; nIndex < FileDataArray.GetCount(); nIndex++)
				{
					CFileData& FileData = FileDataArray[nIndex];
					INT nItem;
					if(m_nFileListViewGroupViewEnabled >= 0)
						nItem = m_FileListView.InsertGroupItem(m_FileListView.GetItemCount(), FileData.m_nLocation, FileData);
					else
						nItem = m_FileListView.InsertItem(m_FileListView.GetItemCount(), FileData);
					if(_tcsicmp(FindFileName(FileData.m_sPath), sPrivateLogFileName) == 0)
						m_FileListView.SetCheckState(nItem, TRUE);
				}
			}
			SIZE_T GetFiles(CRoArrayT<CSelectedFileData>& Array)
			{
				_A(Array.IsEmpty());
				for(INT nItem = 0; nItem < m_FileListView.GetItemCount(); nItem++)
				{
					if(!m_FileListView.GetCheckState(nItem))
						continue;
					const CFileData& FileData = m_FileListView.GetItemData(nItem);
					CSelectedFileData SelectedFileData;
					SelectedFileData.m_sPath = FileData.m_sPath;
					CPath sName = FindFileName(FileData.m_sPath);
					if(FileData.m_nLocation == 1)
					{
						CString sExtention = FindExtension(sName);
						sName.RemoveExtension();
						sName = (LPCTSTR) AtlFormatString(_T("%s (%s)%s"), sName, _T("Current User"), sExtention);
					}
					SelectedFileData.m_sName = (LPCTSTR) sName;
					Array.Add(SelectedFileData);
				}
				return Array.GetCount();
			}
			ULONGLONG GetTruncateSize()
			{
				static const ULONGLONG g_pnTruncateSizes[] = 
				{
					 1i64 << 20, //  1 MB
					10i64 << 20, // 10 MB
					25i64 << 20, // 25 MB
					50i64 << 20, // 50 MB
				};
				const INT nItem = m_TruncateComboBox.GetCurSel();
				_A(nItem >= 0 && nItem < DIM(g_pnTruncateSizes));
				return g_pnTruncateSizes[nItem];
			}
			BOOL GetDelete()
			{
				return m_DeleteComboBox.GetCurSel() == 1;
			}

		// Window Message Handler
			LRESULT OnInitDialog(HWND, LPARAM lParam)
			{
				m_pOwner = (CPropertyFrameDialog*) lParam;
				m_bActivating = TRUE;
				_ATLTRY
				{
					CWaitCursor WaitCursor;
					m_TitleStatic = GetDlgItem(IDC_FILTERGRAPHHELPER_EMAIL_LOG_TITLE);
					CreateTitleFont(m_TitleFont, m_TitleStatic);
					m_FileListView.Initialize(GetDlgItem(IDC_FILTERGRAPHHELPER_EMAIL_LOG_FILE));
					m_nFileListViewGroupViewEnabled = m_FileListView.EnableGroupView(TRUE);
					if(!m_nFileListViewGroupViewEnabled)
						m_nFileListViewGroupViewEnabled = m_FileListView.IsGroupViewEnabled() ? 1 : -1;
					m_TruncateComboBox.Initialize(GetDlgItem(IDC_FILTERGRAPHHELPER_EMAIL_LOG_TRUNCATE));
					m_DeleteComboBox.Initialize(GetDlgItem(IDC_FILTERGRAPHHELPER_EMAIL_LOG_DELETE));
					DlgResize_Init(FALSE, FALSE);
					InitializeFileListView();
					m_FileListView.SetColumnWidth(3, LVSCW_AUTOSIZE);
					m_TruncateComboBox.SetCurSel(2);
					m_DeleteComboBox.SetCurSel(0);
					UpdateControls();
					m_bActivating = FALSE;
				}
				_ATLCATCH(Exception)
				{
					for(CWindow Window = GetWindow(GW_CHILD); Window; Window = Window.GetWindow(GW_HWNDNEXT))
						Window.EnableWindow(FALSE);
					AtlExceptionMessageBox(m_hWnd, Exception);
				}
				return TRUE;
			}
			LRESULT OnChanged(UINT, INT_PTR nIdentifier, HWND)
			{
				if(m_bActivating)
					return 0;
				m_ChangeMap[nIdentifier] = TRUE;
				UpdateControls();
				return 0;
			}
			LRESULT OnChanged(NMHDR* pHeader)
			{
				return OnChanged(pHeader->code, pHeader->idFrom, pHeader->hwndFrom);
			}
			LRESULT OnFileListViewGetDispInfo(NMLVDISPINFO* pHeader)
			{
				const CFileData& FileData = m_FileListView.DataFromParameter(pHeader->item.lParam);
				if(pHeader->item.mask & LVIF_TEXT)
				{
					CString& sTextBuffer = m_FileListView.GetTextBufferString(TRUE);
					switch(pHeader->item.iSubItem)
					{
					case 1: // Size
						sTextBuffer = _StringHelper::FormatNumber((LONGLONG) FileData.m_nSize);
						break;
					case 2: // Update Time
						sTextBuffer = _StringHelper::FormatDateTime(FileData.GetLocalUpdateTime());
						break;
					case 3: // Directory
						sTextBuffer = (LPCTSTR) GetPathDirectory(FileData.m_sPath);
						break;
					default: // File Name
						sTextBuffer = FindFileName(FileData.m_sPath);
					}
					pHeader->item.pszText = m_FileListView.GetTextBuffer();
				}
				return 0;
			}
			LRESULT OnFileListViewItemChanged(NMLISTVIEW* pHeader)
			{
				return m_FileListView.OnReflectedItemChanged(pHeader);
			}
		};

		////////////////////////////////////////////////////
		// CEmailDialog

		class CEmailDialog :
			public CDialogImpl<CEmailDialog>,
			public CDialogResize<CEmailDialog>
		{
		public:
			enum { IDD = IDD_FILTERGRAPHHELPER_EMAIL };

		BEGIN_MSG_MAP_EX(CEmailDialog)
			//CHAIN_MSG_MAP(CDialogImpl<CEmailDialog>)
			CHAIN_MSG_MAP(CDialogResize<CEmailDialog>)
			MSG_WM_INITDIALOG(OnInitDialog)
			MSG_WM_DESTROY(OnDestroy)
			MSG_WM_SHOWWINDOW(OnShowWindow)
			COMMAND_HANDLER_EX(IDC_FILTERGRAPHHELPER_EMAIL_FROM, EN_CHANGE, OnChanged)
			COMMAND_HANDLER_EX(IDC_FILTERGRAPHHELPER_EMAIL_TO, EN_CHANGE, OnChanged)
			COMMAND_HANDLER_EX(IDC_FILTERGRAPHHELPER_EMAIL_METHOD, CBN_SELENDOK, OnChanged)
			COMMAND_HANDLER_EX(IDC_FILTERGRAPHHELPER_EMAIL_HOST, EN_CHANGE, OnChanged)
			COMMAND_HANDLER_EX(IDC_FILTERGRAPHHELPER_EMAIL_USERNAME, EN_CHANGE, OnChanged)
			COMMAND_HANDLER_EX(IDC_FILTERGRAPHHELPER_EMAIL_PASSWORD, EN_CHANGE, OnChanged)
			COMMAND_HANDLER_EX(IDC_FILTERGRAPHHELPER_EMAIL_BODY, EN_CHANGE, OnChanged)
			COMMAND_ID_HANDLER_EX(IDC_FILTERGRAPHHELPER_EMAIL_SEND, OnSend)
			NOTIFY_HANDLER_EX(IDC_FILTERGRAPHHELPER_EMAIL_CLEANUP, CRoHyperStatic::NC_ANCHORCLICKED, OnCleanupStaticAnchorClicked)
			REFLECT_NOTIFICATIONS()
		ALT_MSG_MAP(IDC_FILTERGRAPHHELPER_EMAIL_FROM)
			MSG_WM_PASTE(OnFromEditPaste)
		END_MSG_MAP()

		BEGIN_DLGRESIZE_MAP(CEmailDialog)
			DLGRESIZE_CONTROL(IDC_FILTERGRAPHHELPER_EMAIL_BODY, DLSZ_SIZE_X | DLSZ_SIZE_Y)
			DLGRESIZE_CONTROL(IDC_FILTERGRAPHHELPER_EMAIL_SEND, DLSZ_MOVE_X | DLSZ_MOVE_Y)
			DLGRESIZE_CONTROL(IDC_FILTERGRAPHHELPER_EMAIL_CLEANUP, DLSZ_MOVE_Y)
		END_DLGRESIZE_MAP()

		private:
			CPropertyFrameDialog* m_pOwner;
			BOOL m_bActivating;
			CStatic m_TitleStatic;
			CFont m_TitleFont;
			CContainedWindowT<CRoEdit> m_FromEdit;
			CRoEdit m_ToEdit;
			CRoComboBoxT<> m_MethodComboBox;
			CRoEdit m_HostEdit;
			CRoEdit m_UsernameEdit;
			CRoEdit m_PasswordEdit;
			CRoEdit m_BodyEdit;
			CButton m_SendButton;
			CRoHyperStatic m_CleanupStatic;
			CString m_sFilterGraphText;
			CRoMapT<INT_PTR, BOOL> m_ChangeMap;

		public:
		// CEmailDialog
			CEmailDialog() :
				m_FromEdit(this, IDC_FILTERGRAPHHELPER_EMAIL_FROM)
			{
			}
			BOOL InitializeControlsFromMessageString(const CString& sMessageString)
			{
				_ATLTRY
				{
					CObjectPtr<CMessage> pMessage;
					pMessage.Construct();
					pMessage->LoadTypeInfo(IDR_EMAILTOOLS);
					pMessage->SetAsString(CStringA(sMessageString));
					#pragma region Sender and Recipients
					CComBSTR sSender, sToRecipients;
					__C(pMessage->get_Sender(&sSender));
					__C(pMessage->get_ToRecipients(&sToRecipients));
					m_FromEdit.SetValue(CString(sSender));
					m_ToEdit.SetValue(CString(sToRecipients));
					#pragma endregion 
					CComBSTR sAuthMethods;
					__C(pMessage->get_AuthMethods(&sAuthMethods));
					VARIANT_BOOL bSecureSocketsLayer, bTransportLayerSecurity;
					__C(pMessage->get_SecureSocketsLayer(&bSecureSocketsLayer));
					__C(pMessage->get_TransportLayerSecurity(&bTransportLayerSecurity));
					#pragma region Host and Port
					CComBSTR sHost;
					__C(pMessage->get_ServerHost(&sHost));
					LONG nPort = 0;
					__C(pMessage->get_ServerPort(&nPort));
					CString sHostT(sHost);
					if(nPort)
						sHostT += AtlFormatString(_T(":%d"), nPort);
					m_HostEdit.SetValue(sHostT);
					#pragma endregion 
					#pragma region User Name and Password
					CComBSTR sAuthName, sAuthPassword;
					__C(pMessage->get_AuthName(&sAuthName));
					__C(pMessage->get_AuthPassword(&sAuthPassword));
					m_UsernameEdit.SetValue(CString(sAuthName));
					m_PasswordEdit.SetValue(CString(sAuthPassword));
					#pragma endregion 
					m_MethodComboBox.SetCurSel(0);
					if(bTransportLayerSecurity != ATL_VARIANT_FALSE && sHostT.CompareNoCase(_T("smtp.gmail.com")) == 0)
					{
						//m_MethodComboBox.SetCurSel(0);
					} else
					{
						if(bTransportLayerSecurity != ATL_VARIANT_FALSE)
							m_MethodComboBox.SetCurSel(1);
						else if(bSecureSocketsLayer != ATL_VARIANT_FALSE)
							m_MethodComboBox.SetCurSel(2);
						else if(CString(sAuthMethods).CompareNoCase(_T("cram-md5")) == 0)
							m_MethodComboBox.SetCurSel(3);
						else if(!CString(sAuthName).IsEmpty())
							m_MethodComboBox.SetCurSel(4);
						else
							m_MethodComboBox.SetCurSel(5);
					}
				}
				_ATLCATCHALL()
				{
					_Z_EXCEPTION();
					return FALSE;
				}
				return TRUE;
			}
			VOID InitializeControlsFromRegistry()
			{
				const CString sMessageString = _RegKeyHelper::QueryStringValue(HKEY_CURRENT_USER, REGISTRY_ROOT, _T("Email Message Template"));
				if(sMessageString.IsEmpty())
					return;
				InitializeControlsFromMessageString(sMessageString);
			}
			VOID InitializeBody()
			{
				CString sText;
				sText += _T("(add notes here; graph data will be appended below)") _T("\r\n") _T("\r\n");
				sText += _T("* * *") _T("\r\n") _T("\r\n");
				#define I FormatIdentifier
				#pragma region System
				{
					sText += _T("# System") _T("\r\n") _T("\r\n");
					OSVERSIONINFOEX Version;
					ZeroMemory(&Version, sizeof Version);
					Version.dwOSVersionInfoSize = sizeof Version;
					#pragma warning(disable: 4996) // 'GetVersionExW': was declared deprecated
					GetVersionEx((OSVERSIONINFO*) &Version);
					#pragma warning(default: 4996)
					#pragma region Version
					CRoArrayT<CString> VersionArray;
					VersionArray.Add(AtlFormatString(_T("%s Build %s"), I(AtlFormatString(_T("%d.%d"), Version.dwMajorVersion, Version.dwMinorVersion)), I(Version.dwBuildNumber)));
					switch((Version.dwMajorVersion << 16) + Version.dwMinorVersion)
					{
					case 0x00050001: 
						VersionArray.Add(_T("Windows XP"));
						break;
					case 0x00050002: 
						if(Version.wProductType != VER_NT_WORKSTATION)
							VersionArray.Add(_T("Windows Server 2003"));
						break;
					case 0x00060000: 
						if(Version.wProductType == VER_NT_WORKSTATION)
							VersionArray.Add(_T("Windows Vista"));
						else
							VersionArray.Add(_T("Windows Server 2008"));
						break;
					case 0x00060001: 
						if(Version.wProductType == VER_NT_WORKSTATION)
							VersionArray.Add(_T("Windows 7"));
						else
							VersionArray.Add(_T("Windows Server 2008 R2"));
						break;
					case 0x00060002: 
						if(Version.wProductType == VER_NT_WORKSTATION)
							VersionArray.Add(_T("Windows 8"));
						else
							VersionArray.Add(_T("Windows Server 2012"));
						break;
					}
					if(_tcslen(Version.szCSDVersion))
						VersionArray.Add(Version.szCSDVersion);
					if(Version.wServicePackMajor)
						VersionArray.Add(AtlFormatString(_T("Service Pack %s"), I(AtlFormatString(_T("%d.%d"), Version.wServicePackMajor, Version.wServicePackMinor))));
					//Version.wSuiteMask, Version.wProductType
					sText += AtlFormatString(_T(" * ") _T("Version: %s") _T("\r\n"), _StringHelper::Join(VersionArray, _T("; ")));
					#pragma endregion 
					sText += AtlFormatString(_T(" * ") _T("Computer Name: %s") _T("\r\n"), I(GetComputerName()));
					TCHAR pszUserName[256] = { 0 };
					DWORD nUserNameLength = DIM(pszUserName);
					GetUserName(pszUserName, &nUserNameLength);
					CString sUserName(pszUserName);
					BOOL bAdministrator = FALSE;
					bool bIsMember = FALSE;
					if(CAccessToken().CheckTokenMembership(Sids::Admins(), &bIsMember) && bIsMember)
						bAdministrator = TRUE;
					sText += AtlFormatString(_T(" * ") _T("User Name: %s %s") _T("\r\n"), I(sUserName), bAdministrator ? _T("(Administrator)") : _T(""));
					SYSTEM_INFO SystemInformation;
					GetSystemInfo(&SystemInformation);
					#pragma region Architecture
					CString sArchitecture;
					switch(SystemInformation.wProcessorArchitecture)
					{
					case PROCESSOR_ARCHITECTURE_INTEL:
						sArchitecture = I(_T("x86"));
						break;
					case PROCESSOR_ARCHITECTURE_AMD64:
						sArchitecture = I(_T("AMD/Intel x64"));
						break;
					case PROCESSOR_ARCHITECTURE_IA64:
						sArchitecture = I(_T("Intel Itanium"));
						break;
					default:
						sArchitecture = I(SystemInformation.wProcessorArchitecture, _T("0x%04X"));
					}
					#if defined(_WIN64)
						sText += AtlFormatString(_T(" * ") _T("Architecture: %s (x64 Application)") _T("\r\n"), sArchitecture);
					#else
						sText += AtlFormatString(_T(" * ") _T("Architecture: %s") _T("\r\n"), sArchitecture);
					#endif // defined(_WIN64)
					#pragma endregion 
					sText += AtlFormatString(_T(" * ") _T("Processors: %s, Active Mask %s") _T("\r\n"), I(SystemInformation.dwNumberOfProcessors), I((DWORD) SystemInformation.dwActiveProcessorMask, _T("0x%X")));
					sText += AtlFormatString(_T(" * ") _T("Page Size: %s") _T("\r\n"), I(SystemInformation.dwPageSize, _T("0x%X")));
					sText += AtlFormatString(_T(" * ") _T("Application Address Space: %s..%s") _T("\r\n"), I(SystemInformation.lpMinimumApplicationAddress), I(SystemInformation.lpMaximumApplicationAddress));
					#pragma region Memory
					MEMORYSTATUSEX MemoryStatus = { sizeof MemoryStatus };
					_W(GlobalMemoryStatusEx(&MemoryStatus));
					sText += AtlFormatString(_T(" * ") _T("Physical Memory: %s MB") _T("\r\n"), I(_StringHelper::FormatNumber((LONG) (MemoryStatus.ullTotalPhys >> 20))));
					sText += AtlFormatString(_T(" * ") _T("Committed Memory Limit: %s MB") _T("\r\n"), I(_StringHelper::FormatNumber((LONG) (MemoryStatus.ullTotalPageFile >> 20))));
					#pragma endregion
				}
				#pragma endregion 
				sText += AtlFormatString(_T(" * ") _T("Module Version: %s") _T("\r\n"), I(_VersionInfoHelper::GetVersionString(_VersionInfoHelper::GetFileVersion(_VersionInfoHelper::GetModulePath()))));
				SYSTEMTIME LocalTime;
				GetLocalTime(&LocalTime);
				sText += AtlFormatString(_T(" * ") _T("Local Time: %s") _T("\r\n"), I(_StringHelper::FormatDateTime(&LocalTime)));
				sText += _T("\r\n");
				#undef I
				m_BodyEdit.SetValue(sText);
			}
			VOID UpdateControls()
			{
				BOOL bAllowSend = TRUE;
				if(m_ToEdit.GetValue().Trim().IsEmpty())
					bAllowSend = FALSE;
				const INT nMethod = m_MethodComboBox.GetCurSel();
				m_HostEdit.GetWindow(GW_HWNDPREV).EnableWindow(nMethod != 0); // Google Mail
				m_HostEdit.EnableWindow(nMethod != 0); // Google Mail
				m_UsernameEdit.GetWindow(GW_HWNDPREV).EnableWindow(nMethod != 5); // No Authentication
				m_UsernameEdit.EnableWindow(nMethod != 5); // No Authentication
				m_PasswordEdit.GetWindow(GW_HWNDPREV).EnableWindow(nMethod != 5); // No Authentication
				m_PasswordEdit.EnableWindow(nMethod != 5); // No Authentication
				if(nMethod != 0) // Google Mail
					if(m_HostEdit.GetValue().Trim().IsEmpty())
						bAllowSend = FALSE;
				if(nMethod != 5) // No Authentication
				{
					if(m_UsernameEdit.GetValue().Trim().IsEmpty())
						bAllowSend = FALSE;
					if(m_PasswordEdit.GetValue().Trim().IsEmpty())
						bAllowSend = FALSE;
				}
				m_SendButton.EnableWindow(bAllowSend);
			}
			static CString GetComputerName()
			{
				TCHAR pszComputerName[256] = { 0 };
				DWORD nComputerNameLength = DIM(pszComputerName);
				::GetComputerName(pszComputerName, &nComputerNameLength);
				return pszComputerName;
			}

		// Window Message Handler
			LRESULT OnInitDialog(HWND, LPARAM lParam)
			{
				m_pOwner = (CPropertyFrameDialog*) lParam;
				m_bActivating = TRUE;
				_ATLTRY
				{
					CWaitCursor WaitCursor;
					m_TitleStatic = GetDlgItem(IDC_FILTERGRAPHHELPER_EMAIL_TITLE);
					CreateTitleFont(m_TitleFont, m_TitleStatic);
					_W(m_FromEdit.SubclassWindow(GetDlgItem(IDC_FILTERGRAPHHELPER_EMAIL_FROM)));
					m_ToEdit = GetDlgItem(IDC_FILTERGRAPHHELPER_EMAIL_TO);
					m_MethodComboBox.Initialize(GetDlgItem(IDC_FILTERGRAPHHELPER_EMAIL_METHOD));
					m_MethodComboBox.SetCurSel(0);
					m_HostEdit = GetDlgItem(IDC_FILTERGRAPHHELPER_EMAIL_HOST);
					m_UsernameEdit = GetDlgItem(IDC_FILTERGRAPHHELPER_EMAIL_USERNAME);
					m_PasswordEdit = GetDlgItem(IDC_FILTERGRAPHHELPER_EMAIL_PASSWORD);
					m_BodyEdit = GetDlgItem(IDC_FILTERGRAPHHELPER_EMAIL_BODY);
					m_BodyEdit.SetFont(m_pOwner->m_TextFont);
					m_SendButton = GetDlgItem(IDC_FILTERGRAPHHELPER_EMAIL_SEND);
					_W(m_CleanupStatic.SubclassWindow(GetDlgItem(IDC_FILTERGRAPHHELPER_EMAIL_CLEANUP)));
					DlgResize_Init(FALSE, FALSE);
					InitializeControlsFromRegistry();
					InitializeBody();
					m_sFilterGraphText = m_pOwner->m_Owner.GetText();
					UpdateControls();
					m_bActivating = FALSE;
				}
				_ATLCATCH(Exception)
				{
					for(CWindow Window = GetWindow(GW_CHILD); Window; Window = Window.GetWindow(GW_HWNDNEXT))
						Window.EnableWindow(FALSE);
					AtlExceptionMessageBox(m_hWnd, Exception);
				}
				return TRUE;
			}
			LRESULT OnDestroy()
			{
				return 0;
			}
			LRESULT OnShowWindow(BOOL bShowing, INT)
			{
				if(bShowing && !m_ChangeMap.Lookup(IDC_FILTERGRAPHHELPER_EMAIL_BODY))
					InitializeBody();
				return 0;
			}
			LRESULT OnChanged(UINT, INT_PTR nIdentifier, HWND)
			{
				if(m_bActivating)
					return 0;
				m_ChangeMap[nIdentifier] = TRUE;
				UpdateControls();
				return 0;
			}
			LRESULT OnChanged(NMHDR* pHeader)
			{
				return OnChanged(pHeader->code, pHeader->idFrom, pHeader->hwndFrom);
			}
			LRESULT OnFromEditPaste()
			{
				_ATLTRY
				{
					CString sText;
					if(GetClipboardText(m_hWnd, sText))
					{
						const INT nLength = sText.GetLength();
						if(nLength >= 128 && nLength < 8192)
						{
							sText.Trim();
							const BOOL bResult = InitializeControlsFromMessageString(sText);
							UpdateControls();
							if(bResult)
								return 0;
						}
					}
				}
				_ATLCATCHALL()
				{
					MessageBeep(MB_ICONERROR);
				}
				return 0;
			}
			LRESULT OnSend(UINT, INT, HWND)
			{
				CWaitCursor WaitCursor;
				CObjectPtr<CMessage> pMessage;
				pMessage.Construct();
				#pragma region Setup
				pMessage->LoadTypeInfo(IDR_EMAILTOOLS);
				__C(pMessage->put_Sender(CComBSTR(m_FromEdit.GetValue())));
				__C(pMessage->put_ToRecipients(CComBSTR(m_ToEdit.GetValue())));
				// NOTE: 
				// 0 Google Mail (SMTP, TLS Connection)
				// 1 SMTP, TLS Connection, Plain Text Authentication (TLS, PLAIN)
				// 2 SMTP, SSL Connection, Plain Text Authentication (SSL, PLAIN)
				// 3 SMTP, Digest Authentication (CRAM-MD5)
				// 4 SMTP, Plain Text Authentication (PLAIN)
				// 5 SMTP, No Authentication
				const INT nMethod = m_MethodComboBox.GetCurSel();
				__C(pMessage->put_SecureSocketsLayer((nMethod == 2) ? ATL_VARIANT_TRUE : ATL_VARIANT_FALSE));
				__C(pMessage->put_TransportLayerSecurity((nMethod < 2) ? ATL_VARIANT_TRUE : ATL_VARIANT_FALSE));
				if(nMethod != 5)
				{
					__C(pMessage->put_AuthMethods(CComBSTR(_T("plain"))));
					__C(pMessage->put_AuthName(CComBSTR(m_UsernameEdit.GetValue())));
					__C(pMessage->put_AuthPassword(CComBSTR(m_PasswordEdit.GetValue())));
				}
				switch(nMethod)
				{
				case 0:
					__C(pMessage->put_ServerHost(CComBSTR(_T("smtp.gmail.com"))));
					break;
				default:
					CString sHost = m_HostEdit.GetValue();
					sHost.Trim();
					const INT nPortPosition = sHost.Find(_T(":"));
					if(nPortPosition >= 0)
					{
						INT nPort;
						__D(AtlStringToInteger(sHost.Mid(nPortPosition + 1), nPort), E_UNNAMED);
						__C(pMessage->put_ServerPort(nPort));
						sHost = sHost.Left(nPortPosition);
					}
					__C(pMessage->put_ServerHost(CComBSTR(sHost)));
					break;
				}
				switch(nMethod)
				{
				case 3:
					__C(pMessage->put_AuthMethods(CComBSTR(_T("cram-md5"))));
					break;
				}
				#pragma endregion 
				CStringA sMessageString = pMessage->GetAsString();
				CString sText = m_BodyEdit.GetValue();
				sText.TrimRight(_T("\t\n\r "));
				sText += _T("\r\n") _T("\r\n") _T("* * *") _T("\r\n") _T("\r\n");
				sText += m_sFilterGraphText;
				__C(pMessage->put_Body(CComBSTR(sText)));
				CString sSubject = AtlFormatString(_T("DirectShow Filter Graph from %s by %s"), GetComputerName(), AtlLoadString(IDS_PROJNAME));
				__C(pMessage->put_Subject(CComBSTR(sSubject)));
				#pragma region Attachment
				CRoArrayT<CPath> DeletePathArray;
				CRoArrayT<CString> FailurePathArray;
				{
					CEmailLogDialog& EmailLogDialog = m_pOwner->m_EmailLogDialog;
					CRoArrayT<CEmailLogDialog::CSelectedFileData> Array;
					if(EmailLogDialog.GetFiles(Array))
					{
						const ULONGLONG nTruncateSize = EmailLogDialog.GetTruncateSize();
						const BOOL bDelete = EmailLogDialog.GetDelete();
						for(SIZE_T nIndex = 0; nIndex < Array.GetCount(); nIndex++)
						{
							CEmailLogDialog::CSelectedFileData& FileData = Array[nIndex];
							_ATLTRY
							{
								CLocalObjectPtr<CBzip2Item> pItem;
								pItem->LoadFromFile(FileData.m_sPath, nTruncateSize);
								CHeapPtr<BYTE> pnData;
								SIZE_T nDataSize;
								pItem->GetData(pnData, nDataSize);
								if(nDataSize)
								{
									CObjectPtr<CMessage::CComAttachment> pAttachment = pMessage->GetAttachments()->Add();
									_ATLTRY
									{
										pAttachment->SetType(L"application/bzip2");
										pAttachment->SetDisposition(L"attachment");
										pAttachment->SetName(CStringW(FileData.m_sName + _T(".bz2")));
										CLocalObjectPtr<CUnmanagedMemoryStream> pStream;
										pStream->Initialize(pnData, nDataSize);
										pAttachment->LoadFromStream(pStream);
									}
									_ATLCATCHALL()
									{
										_V(pMessage->GetAttachments()->Remove(pAttachment));
										_ATLRETHROW;
									}
								}
								if(bDelete)
									DeletePathArray.Add(FileData.m_sPath);
							}
							_ATLCATCHALL()
							{
								_Z_EXCEPTION();
								FailurePathArray.Add((LPCTSTR) FileData.m_sPath);
							}
						}
					}
				}
				#pragma endregion 
				__C(pMessage->Send());
				for(SIZE_T nIndex = 0; nIndex < DeletePathArray.GetCount(); nIndex++)
					DeleteFile(DeletePathArray[nIndex]);
				_RegKeyHelper::SetStringValue(HKEY_CURRENT_USER, REGISTRY_ROOT, _T("Email Message Template"), CString(sMessageString));
				if(!FailurePathArray.IsEmpty())
				{
					const CString sMessage = AtlFormatString(_T("It was unable to attach the following files:") _T("\r\n\r\n") _T("%s"), _StringHelper::Join(FailurePathArray, _T("\r\n")));
					AtlMessageBoxEx(m_hWnd, (LPCTSTR) sMessage, IDS_WARNING, MB_ICONWARNING | MB_OK);
				}
				AtlOptionalMessageBoxEx(m_hWnd, _T("CFilterGraphHelper::CPropertyFrameDialog::CEmailDialog::CredentialsSaved"), _T("The email was sent.") _T("\r\n\r\n") _T("The credentials were written into registry for further reuse. Use Erase Cached Credentials link to delete them from registry."), IDS_INFORMATION, MB_ICONINFORMATION | MB_OK);
				MessageBeep(MB_OK);
				return 0;
			}
			LRESULT OnCleanupStaticAnchorClicked(NMHDR*)
			{
				_RegKeyHelper::DeleteValue(HKEY_CURRENT_USER, REGISTRY_ROOT, _T("Email Message Template"));
				AtlOptionalMessageBoxEx(m_hWnd, _T("CFilterGraphHelper::CPropertyFrameDialog::CEmailDialog::SavedCredentialsDeleted"), _T("Cached email credentials were removed from registry."), IDS_INFORMATION, MB_ICONINFORMATION | MB_OK);
				MessageBeep(MB_OK);
				return 0;
			}
		};

		////////////////////////////////////////////////////
		// CData

		class CData
		{
		public:

			/////////////////////////////////////////////////////////
			// TYPE

			typedef enum _TYPE
			{
				TYPE_UNKNOWN = 0,
				TYPE_FILTERS,
				TYPE_FILTER,
				TYPE_FILTERPROPERTYPAGE,
				TYPE_SERVICES,
				TYPE_SERVICEPROPERTYPAGE,
				TYPE_MEMORYALLOCATOR,
				TYPE_ACTION,
				TYPE_EMAIL,
				TYPE_EMAIL_LOG,
			} TYPE;

		public:
			TYPE m_Type;
			CComPtr<IBaseFilter> m_pBaseFilter;
			CLSID m_BaseFilterClassIdentifier;
			CString m_sBaseFilterClassDescription;
			CString m_sBaseFilterModulePath;
			CLSID m_PropertyPageClassIdentifier;
			CComPtr<IPropertyPage> m_pPropertyPage;
			CObjectPtr<CPropertyPageSite> m_pSite;
			BOOL m_bSiteActivated;

		public:
		// CData
			CData(TYPE Type = TYPE_UNKNOWN) :
				m_Type(Type),
				m_BaseFilterClassIdentifier(CLSID_NULL),
				m_PropertyPageClassIdentifier(CLSID_NULL)
			{
			}
			CData(IBaseFilter* pBaseFilter) :
				m_Type(TYPE_FILTER),
				m_pBaseFilter(pBaseFilter),
				m_BaseFilterClassIdentifier(CLSID_NULL),
				m_PropertyPageClassIdentifier(CLSID_NULL)
			{
				_ATLTRY
				{
					CLSID ClassIdentifier = CLSID_NULL;
					if(SUCCEEDED(pBaseFilter->GetClassID(&ClassIdentifier)) && ClassIdentifier != CLSID_NULL)
					{
						m_BaseFilterClassIdentifier = ClassIdentifier;
						const CString sClassIdentifier(_PersistHelper::StringFromIdentifier(ClassIdentifier));
						m_sBaseFilterClassDescription = _RegKeyHelper::QueryStringValue(HKEY_CLASSES_ROOT, AtlFormatString(_T("CLSID\\%s"), sClassIdentifier));
						m_sBaseFilterModulePath = _RegKeyHelper::QueryStringValue(HKEY_CLASSES_ROOT, AtlFormatString(_T("CLSID\\%s\\InprocServer32"), sClassIdentifier));
					}
				}
				_ATLCATCHALL()
				{
					_Z_EXCEPTION();
				}
			}
			CData(IBaseFilter* pBaseFilter, const CLSID& PropertyPageClassIdentifier, IPropertyPage* pPropertyPage) :
				m_Type(TYPE_FILTERPROPERTYPAGE),
				m_pBaseFilter(pBaseFilter),
				m_BaseFilterClassIdentifier(CLSID_NULL),
				m_PropertyPageClassIdentifier(PropertyPageClassIdentifier),
				m_pPropertyPage(pPropertyPage),
				m_bSiteActivated(FALSE)
			{
				_A(pPropertyPage);
			}
			CData(IPropertyPage* pPropertyPage) :
				m_Type(TYPE_SERVICEPROPERTYPAGE),
				m_BaseFilterClassIdentifier(CLSID_NULL),
				m_PropertyPageClassIdentifier(CLSID_NULL),
				m_pPropertyPage(pPropertyPage),
				m_bSiteActivated(FALSE)
			{
				_A(pPropertyPage);
			}
			CString GetPropertyPageTitle() const
			{
				if(!m_pPropertyPage)
					return _T("");
				PROPPAGEINFO PageInformation;
				ZeroMemory(&PageInformation, sizeof PageInformation);
				PageInformation.cb = sizeof PageInformation;
				__C(m_pPropertyPage->GetPageInfo(&PageInformation));
				CString sTitle(PageInformation.pszTitle);
				CoTaskMemFree(PageInformation.pszTitle);
				CoTaskMemFree(PageInformation.pszDocString);
				CoTaskMemFree(PageInformation.pszHelpFile);
				return sTitle;
			}
		};

		////////////////////////////////////////////////////
		// CObjectPropertyPage

		class CObjectPropertyPage
		{
		public:
			CComPtr<IUnknown> m_pUnknown;
			CComPtr<IPropertyPage> m_pPropertyPage;

		public:
		// CObjectPropertyPage
			CObjectPropertyPage()
			{
			}
			CObjectPropertyPage(IUnknown* pUnknown, IPropertyPage* pPropertyPage) :
				m_pUnknown(pUnknown),
				m_pPropertyPage(pPropertyPage)
			{
			}
		};

		typedef CRoArrayT<CObjectPropertyPage> CObjectPropertyPageArray;

	private:
		CFilterGraphHelper& m_Owner;
		BOOL m_bActivating; 
		CRoTreeViewT<CData, CRoListControlDataTraitsT> m_TreeView;
		CTreeItem m_FiltersItem;
		CTreeItem m_MemoryAllocatorItem;
		CTreeItem m_ActionItem;
		CTreeItem m_EmailItem;
		CTreeItem m_EmailLogItem;
		CTabCtrl m_Tab;
		CRoEdit m_TextEdit;
		CRect m_TextPosition;
		CFont m_TextFont;
		CRoHyperStatic m_RefreshStatic;
		CRoHyperStatic m_CopyStatic;
		CRoHyperStatic m_SaveAsStatic;
		CButton m_OkButton;
		CButton m_CancelButton;
		CButton m_ApplyButton;
		CObjectPtr<CPropertyPageSite> m_pCurrentSite;
		CMemoryAllocatorDialog m_MemoryAllocatorDialog;
		CActionDialog m_ActionDialog;
		CEmailDialog m_EmailDialog;
		CEmailLogDialog m_EmailLogDialog;

		static VOID CreateTitleFont(CFont& Font, HWND hStaticWindow = NULL)
		{
			_A(!Font);
			CLogFont LogFont;
			LogFont.SetHeight(12);
			LogFont.lfWeight = FW_BOLD;
			_tcsncpy_s(LogFont.lfFaceName, _T("Verdana"), _TRUNCATE);
			_W(Font.CreateFontIndirect(&LogFont));
			if(hStaticWindow)
				CStatic(hStaticWindow).SetFont(Font);
		}
		VOID ShowText(BOOL bVisible, BOOL bStaticVisible = FALSE)
		{
			m_TextEdit.ShowWindow(bVisible ? SW_SHOW : SW_HIDE);
			bStaticVisible &= bVisible;
			m_RefreshStatic.ShowWindow(bStaticVisible ? SW_SHOW : SW_HIDE);
			m_CopyStatic.ShowWindow(bStaticVisible ? SW_SHOW : SW_HIDE);
			m_SaveAsStatic.ShowWindow(bStaticVisible ? SW_SHOW : SW_HIDE);
		}

	public:
	// CPropertyFrameDialog
		CPropertyFrameDialog(CFilterGraphHelper* pOwner) :
			m_Owner(*pOwner)
		{
		}
		CRect GetTextEditPosition() const
		{
			CRect Position;
			_W(m_TextEdit.GetWindowRect(Position));
			_W(ScreenToClient(Position));
			return Position;
		}
		VOID UpdateTree()
		{
			CWindowRedraw TreeViewRedraw(m_TreeView);
			m_TreeView.DeleteAllItems();
			CTreeItem LastItem;
			#pragma region Filter
			CTreeItem FiltersItem = m_TreeView.InsertItem(NULL, NULL, CData(CData::TYPE_FILTERS), _T("Filters"));
			_FilterGraphHelper::CFilterArray FilterArray;
			_FilterGraphHelper::GetGraphFilters(m_Owner.m_pFilterGraph, FilterArray);
			CTreeItem PreviousFilterItem;
			for(SIZE_T nIndex = 0; nIndex < FilterArray.GetCount(); nIndex++)
			{
				const CComPtr<IBaseFilter>& pBaseFilter = FilterArray[nIndex];
				CData Data(pBaseFilter);
				CString sText(_FilterGraphHelper::GetFilterName(pBaseFilter));
				if(!Data.m_sBaseFilterClassDescription.IsEmpty() && sText.Find(Data.m_sBaseFilterClassDescription) < 0)
					sText += AtlFormatString(_T(" (%s)"), Data.m_sBaseFilterClassDescription);
				CTreeItem FilterItem = m_TreeView.InsertItem(FiltersItem, PreviousFilterItem, Data, sText);
				PreviousFilterItem = FilterItem;
				#pragma region Property Page
				const CComQIPtr<ISpecifyPropertyPages> pSpecifyPropertyPages = pBaseFilter;
				if(!pSpecifyPropertyPages)
					continue;
				_ATLTRY
				{
					CAUUID Pages;
					ZeroMemory(&Pages, sizeof Pages);
					__C(pSpecifyPropertyPages->GetPages(&Pages));
					CComHeapPtr<CLSID> pClassIdentifiers;
					pClassIdentifiers.Attach(Pages.pElems);
					CTreeItem PreviousPageItem;
					for(UINT nPageIndex = 0; nPageIndex < Pages.cElems; nPageIndex++)
					{
						const CLSID& ClassIdentifier = pClassIdentifiers[nPageIndex];
						if(ClassIdentifier == CLSID_NULL)
							continue; // Fake
						_ATLTRY
						{
							CComPtr<IPropertyPage> pPropertyPage;
							const HRESULT nCoCreateInstanceResult = pPropertyPage.CoCreateInstance(ClassIdentifier);
							_A(SUCCEEDED(nCoCreateInstanceResult) || nCoCreateInstanceResult == REGDB_E_CLASSNOTREG);
							if(nCoCreateInstanceResult == REGDB_E_CLASSNOTREG)
								continue; // Missing [Optional] Page
							__C(nCoCreateInstanceResult);
							CData Data(pBaseFilter, ClassIdentifier, pPropertyPage);
							Data.m_pSite.Construct()->Initialize(this, pBaseFilter, pPropertyPage);
							CTreeItem PageItem = m_TreeView.InsertItem(FilterItem, PreviousPageItem, Data, Data.GetPropertyPageTitle());
							PreviousPageItem = PageItem;
						}
						_ATLCATCHALL()
						{
							_Z_EXCEPTION();
						}
					}
					m_TreeView.Expand(FilterItem);
				}
				_ATLCATCHALL()
				{
					_Z_EXCEPTION();
				}
				#pragma endregion 
			}
			m_TreeView.Expand(FiltersItem);
			m_FiltersItem.m_hTreeItem = FiltersItem;
			m_FiltersItem.m_pTreeView = &m_TreeView;
			LastItem = FiltersItem;
			#pragma endregion
			#pragma region Services
			_ATLTRY
			{
				CObjectPropertyPageArray ObjectPropertyPageArray;
				const CComQIPtr<IServiceProvider> pServiceProvider = m_Owner.m_pFilterGraph;
				if(pServiceProvider)
				{
					#pragma region RunPropertyBagAware
					CComPtr<IRunPropertyBagAware> pRunPropertyBagAware;
					if(SUCCEEDED(pServiceProvider->QueryService<IRunPropertyBagAware>(__uuidof(IRunPropertyBagAware), &pRunPropertyBagAware)))
						_ATLTRY
						{
							_A(pRunPropertyBagAware);
							CObjectPtr<CRunPropertyBagPropertyPage> pRunPropertyBagPropertyPage;
							pRunPropertyBagPropertyPage.Construct();
							ObjectPropertyPageArray.Add(CObjectPropertyPage(pRunPropertyBagAware, pRunPropertyBagPropertyPage));
						}
						_ATLCATCHALL()
						{
							_Z_EXCEPTION();
						}
					#pragma endregion
					#pragma region RunEventAware
					CComPtr<IRunEventAware> pRunEventAware;
					if(SUCCEEDED(pServiceProvider->QueryService<IRunEventAware>(__uuidof(IRunEventAware), &pRunEventAware)))
						_ATLTRY
						{
							_A(pRunEventAware);
							CObjectPtr<CRunEventPropertyPage> pRunEventPropertyPage;
							pRunEventPropertyPage.Construct();
							ObjectPropertyPageArray.Add(CObjectPropertyPage(pRunEventAware, pRunEventPropertyPage));
						}
						_ATLCATCHALL()
						{
							_Z_EXCEPTION();
						}
					#pragma endregion
				}
				if(!ObjectPropertyPageArray.IsEmpty())
				{
					CTreeItem ServicesItem = m_TreeView.InsertItem(NULL, LastItem, CData(CData::TYPE_SERVICES), _T("Services"));
					LastItem = ServicesItem;
					CTreeItem PreviousServiceItem;
					for(auto&& ObjectPropertyPage: ObjectPropertyPageArray)
					{
						CData Data(ObjectPropertyPage.m_pPropertyPage);
						Data.m_pSite.Construct()->Initialize(this, ObjectPropertyPage.m_pUnknown, ObjectPropertyPage.m_pPropertyPage);
						CTreeItem ServiceItem = m_TreeView.InsertItem(ServicesItem, PreviousServiceItem, Data, Data.GetPropertyPageTitle());
						PreviousServiceItem = ServiceItem;
					}
					m_TreeView.Expand(ServicesItem);
				}
			}
			_ATLCATCHALL()
			{
				_Z_EXCEPTION();
			}
			#pragma endregion
			#pragma region Other
			CTreeItem MemoryAllocatorItem = m_TreeView.InsertItem(NULL, LastItem, CData(CData::TYPE_MEMORYALLOCATOR), _T("Memory Allocators"));
			m_MemoryAllocatorItem.m_hTreeItem = MemoryAllocatorItem;
			m_MemoryAllocatorItem.m_pTreeView = &m_TreeView;
			CTreeItem ActionItem = m_TreeView.InsertItem(NULL, MemoryAllocatorItem, CData(CData::TYPE_ACTION), _T("Action"));
			m_ActionItem.m_hTreeItem = ActionItem;
			m_ActionItem.m_pTreeView = &m_TreeView;
			CTreeItem EmailItem = m_TreeView.InsertItem(NULL, ActionItem, CData(CData::TYPE_EMAIL), _T("Email"));
			m_EmailItem.m_hTreeItem = EmailItem;
			m_EmailItem.m_pTreeView = &m_TreeView;
			CTreeItem EmailLogItem = m_TreeView.InsertItem(EmailItem, NULL, CData(CData::TYPE_EMAIL_LOG), _T("Log Files"));
			m_EmailLogItem.m_hTreeItem = EmailLogItem;
			m_EmailLogItem.m_pTreeView = &m_TreeView;
			#pragma endregion
			m_TreeView.Expand(EmailItem);
		}
		VOID HideCurrentSite()
		{
			if(!m_pCurrentSite)
				return;
			if(m_pCurrentSite->m_pPropertyPage)
				__C(m_pCurrentSite->m_pPropertyPage->Show(SW_HIDE));
			m_pCurrentSite.Release();
		}
		VOID HandleStatusChange(CPropertyPageSite* pPropertyPageSite)
		{
			_A(pPropertyPageSite);
			m_ApplyButton.EnableWindow(pPropertyPageSite->IsDirty());
		}
		VOID Apply()
		{
			if(!m_pCurrentSite || !m_pCurrentSite->m_pPropertyPage)
				return;
			__C(m_pCurrentSite->m_pPropertyPage->Apply());
			HandleStatusChange(m_pCurrentSite);
		}
		INT_PTR DoModal(HWND hParentWindow = GetActiveWindow())
		{
			return CDialogWithAccelerators::DoModal(hParentWindow);
		}

	// CDialogResize
		VOID DlgResize_UpdateLayout(INT nWidth, INT nHeight)
		{
			__super::DlgResize_UpdateLayout(nWidth, nHeight);
			const CRect Position = GetTextEditPosition();
			if(m_pCurrentSite && m_pCurrentSite->m_pPropertyPage)
				_V(m_pCurrentSite->m_pPropertyPage->Move(Position));
			_W(m_MemoryAllocatorDialog.SetWindowPos(NULL, Position, SWP_NOZORDER | SWP_NOACTIVATE));
			_W(m_ActionDialog.SetWindowPos(NULL, Position, SWP_NOZORDER | SWP_NOACTIVATE));
			_W(m_EmailDialog.SetWindowPos(NULL, Position, SWP_NOZORDER | SWP_NOACTIVATE));
			_W(m_EmailLogDialog.SetWindowPos(NULL, Position, SWP_NOZORDER | SWP_NOACTIVATE));
		}

	// CDialogWithAcceleratorsT
		BOOL TranslateAccelerator(MSG* pMessage)
		{
			CTreeItem TreeItem = m_TreeView.GetSelectedItem();
			if(TreeItem)
			{
				CData& Data = m_TreeView.GetItemData(TreeItem);
				if(Data.m_Type == CData::TYPE_FILTERPROPERTYPAGE)
				{
					if(Data.m_pPropertyPage)
						if(Data.m_pPropertyPage->TranslateAccelerator(pMessage) == S_OK)
							return TRUE;
				}
			}
			return __super::TranslateAccelerator(pMessage);
		}

	// Window Message Handler
		LRESULT OnInitDialog(HWND, LPARAM)
		{
			m_bActivating = TRUE;
			_ATLTRY
			{
				CWaitCursor WaitCursor;
				CAboutDialog::UpdateCaption(*this);
				#pragma region System Menu
				CMenuHandle Menu = GetSystemMenu(FALSE);
				_W(Menu.AppendMenu(MF_SEPARATOR));
				_W(Menu.AppendMenu(MF_STRING, ID_APP_ABOUT, _T("&About...")));
				#pragma endregion
				#pragma region Icon
				SetIcon(AtlLoadIconImage(IDI_MODULE, LR_COLOR, GetSystemMetrics(SM_CXICON), GetSystemMetrics(SM_CYICON)), TRUE);
				SetIcon(AtlLoadIconImage(IDI_MODULE, LR_COLOR, GetSystemMetrics(SM_CXSMICON), GetSystemMetrics(SM_CYSMICON)), FALSE);
				#pragma endregion 
				m_TreeView.Initialize(GetDlgItem(IDC_FILTERGRAPHHELPER_PROPERTYFRAME_TREE));
				m_TextEdit = GetDlgItem(IDC_FILTERGRAPHHELPER_PROPERTYFRAME_TEXT);
				CRect TextPosition;
				_W(m_TextEdit.GetWindowRect(TextPosition));
				_W(ScreenToClient(TextPosition));
				m_TextPosition = TextPosition;
				CLogFont TextFont;
				CFontHandle(AtlGetDefaultGuiFont()).GetLogFont(TextFont);
				_tcsncpy_s(TextFont.lfFaceName, _T("Courier New"), _TRUNCATE);
				TextFont.SetHeight(8);
				m_TextFont = TextFont.CreateFontIndirect();
				m_TextEdit.SetFont(m_TextFont);
				m_RefreshStatic.SubclassWindow(GetDlgItem(IDC_FILTERGRAPHHELPER_PROPERTYFRAME_REFRESH));
				m_CopyStatic.SubclassWindow(GetDlgItem(IDC_FILTERGRAPHHELPER_PROPERTYFRAME_COPY));
				m_SaveAsStatic.SubclassWindow(GetDlgItem(IDC_FILTERGRAPHHELPER_PROPERTYFRAME_SAVEAS));
				CRoHyperStatic::ArrangeHorizontally(&m_RefreshStatic, &m_CopyStatic, &m_SaveAsStatic, NULL);
				m_OkButton = GetDlgItem(IDOK);
				m_CancelButton = GetDlgItem(IDCANCEL);
				m_ApplyButton = GetDlgItem(IDC_FILTERGRAPHHELPER_PROPERTYFRAME_APPLY);
				__E(m_MemoryAllocatorDialog.Create(m_hWnd, (LPARAM) this));
				__E(m_ActionDialog.Create(m_hWnd, (LPARAM) this));
				__E(m_EmailDialog.Create(m_hWnd, (LPARAM) this));
				__E(m_EmailLogDialog.Create(m_hWnd, (LPARAM) this));
				DlgResize_Init(TRUE);
				UpdateTree();
				m_FiltersItem.Select();
				m_FiltersItem.EnsureVisible();
				CRect Position;
				_W(GetWindowRect(Position));
				Position.right += Position.Width() / 2;
				Position.bottom += Position.Width() / 4;
				_W(SetWindowPos(NULL, Position, SWP_NOMOVE | SWP_NOZORDER));
				_W(CenterWindow());
				m_bActivating = FALSE;
			}
			_ATLCATCH(Exception)
			{
				for(CWindow Window = GetWindow(GW_CHILD); Window; Window = Window.GetWindow(GW_HWNDNEXT))
					Window.EnableWindow(FALSE);
				AtlExceptionMessageBox(m_hWnd, Exception);
			}
			return TRUE;
		}
		LRESULT OnDestroy()
		{
			#pragma region Deactivate and Terminate Sites
			for(POSITION Position = m_TreeView.GetDataList().GetHeadPosition(); Position; m_TreeView.GetDataList().GetNext(Position))
			{
				CData& Data = m_TreeView.GetDataList().GetAt(Position);
				if(!Data.m_pSite)
					continue;
				if(Data.m_bSiteActivated)
				{
					const HRESULT nDeactivateResult = Data.m_pPropertyPage->Deactivate();
					_Z35_DSHRESULT(nDeactivateResult);
					Data.m_bSiteActivated = FALSE;
				}
				Data.m_pSite->Terminate();
			}
			#pragma endregion
			return 0;
		}
		LRESULT OnTreeViewGetInfoTip(NMTVGETINFOTIP* pHeader)
		{
			_A(pHeader);
			if(!pHeader->hItem) 
				return 0;
			CData& Data = m_TreeView.GetItemData(pHeader->hItem);
			CString sInfoTip;
			if(Data.m_pBaseFilter)
			{
				if(!Data.m_pPropertyPage)
				{
					sInfoTip.AppendFormat(_T("Name: %ls") _T("\r\n"), _FilterGraphHelper::GetFilterName(Data.m_pBaseFilter));
					if(Data.m_BaseFilterClassIdentifier != CLSID_NULL)
						sInfoTip.AppendFormat(_T("Class Identifier: %ls") _T("\r\n"), _PersistHelper::StringFromIdentifier(Data.m_BaseFilterClassIdentifier));
					if(!Data.m_sBaseFilterClassDescription.IsEmpty())
						sInfoTip.AppendFormat(_T("Class Description: %s") _T("\r\n"), Data.m_sBaseFilterClassDescription);
					if(!Data.m_sBaseFilterModulePath.IsEmpty())
						sInfoTip.AppendFormat(_T("Module Path: %s") _T("\r\n"), Data.m_sBaseFilterModulePath);
				} else
				{
					// TODO: ...
				}
			}
			sInfoTip.TrimRight(_T("\t\n\r "));
			_tcsncpy_s(pHeader->pszText, pHeader->cchTextMax, sInfoTip, _TRUNCATE);
			#pragma region Clipboard Copy
			if(GetKeyState(VK_CONTROL) < 0 && GetKeyState(VK_SHIFT) < 0)
				_ATLTRY
				{
					SetClipboardText(m_hWnd, sInfoTip);
					MessageBeep(MB_OK);
				}
				_ATLCATCHALL()
				{
					_Z_EXCEPTION();
					MessageBeep(MB_ICONERROR);
				}
			#pragma endregion
			return 0;
		}
		LRESULT OnTreeViewSelChanged(NMTREEVIEW* pHeader)
		{
			_A(pHeader);
			#pragma region Tree Item
			CTreeItem TreeItem(pHeader->itemNew.hItem);
			if(TreeItem)
			{
				CData& Data = m_TreeView.GetItemData(TreeItem);
				if(Data.m_Type != CData::TYPE_MEMORYALLOCATOR)
					m_MemoryAllocatorDialog.ShowWindow(SW_HIDE);
				if(Data.m_Type != CData::TYPE_ACTION)
					m_ActionDialog.ShowWindow(SW_HIDE);
				if(Data.m_Type != CData::TYPE_EMAIL)
					m_EmailDialog.ShowWindow(SW_HIDE);
				if(Data.m_Type != CData::TYPE_EMAIL_LOG)
					m_EmailLogDialog.ShowWindow(SW_HIDE);
				#pragma region Filter
				if(Data.m_pBaseFilter)
				{
					#pragma region Property Page
					if(Data.m_pPropertyPage)
					{
						ShowText(FALSE);
						if(Data.m_pSite != m_pCurrentSite)
							HideCurrentSite();
						if(!Data.m_bSiteActivated)
						{
							__C(Data.m_pPropertyPage->Activate(m_hWnd, GetTextEditPosition(), TRUE));
							Data.m_bSiteActivated = TRUE;
						} else
							__C(Data.m_pPropertyPage->Move(GetTextEditPosition()));
						__C(Data.m_pPropertyPage->Show(SW_SHOWNORMAL));
						m_pCurrentSite = Data.m_pSite;
						HandleStatusChange(m_pCurrentSite);
					} else
					#pragma endregion
					#pragma region Text
					{
						CWaitCursor WaitCursor;
						HideCurrentSite();
						ShowText(TRUE, FALSE);
						CString sText;
						sText += AtlFormatString(_T("## ") _T("Filter %ls") _T("\r\n") _T("\r\n"), _FilterGraphHelper::GetFilterName(Data.m_pBaseFilter));
						sText += m_Owner.GetFilterText(Data.m_pBaseFilter);
						sText += _T("\r\n");
						#pragma region Connection
						_FilterGraphHelper::CPinArray InputPinArray, OutputPinArray;
						_FilterGraphHelper::GetFilterPins(Data.m_pBaseFilter, PINDIR_INPUT, InputPinArray);
						_FilterGraphHelper::GetFilterPins(Data.m_pBaseFilter, PINDIR_OUTPUT, OutputPinArray);
						if(!InputPinArray.IsEmpty() || !OutputPinArray.IsEmpty())
						{
							sText += AtlFormatString(_T("## ") _T("Connections") _T("\r\n") _T("\r\n"));
							if(!InputPinArray.IsEmpty())
							{
								sText += AtlFormatString(_T("### ") _T("Input") _T("\r\n") _T("\r\n"));
								for(SIZE_T nPinIndex = 0; nPinIndex < InputPinArray.GetCount(); nPinIndex++)
								{
									const CComPtr<IPin>& pInputPin = InputPinArray[nPinIndex];
									const CComPtr<IPin> pOutputPin = _FilterGraphHelper::GetPeerPin(pInputPin);
									if(!pOutputPin)
										continue;
									sText += AtlFormatString(_T(" * ") _T("%s") _T("\r\n"), m_Owner.GetConnectionText(pOutputPin, pInputPin));
								}
								sText += _T("\r\n");
							}
							if(!OutputPinArray.IsEmpty())
							{
								sText += AtlFormatString(_T("### ") _T("Output") _T("\r\n") _T("\r\n"));
								for(SIZE_T nPinIndex = 0; nPinIndex < OutputPinArray.GetCount(); nPinIndex++)
								{
									const CComPtr<IPin>& pOutputPin = OutputPinArray[nPinIndex];
									const CComPtr<IPin> pInputPin = _FilterGraphHelper::GetPeerPin(pOutputPin);
									if(!pInputPin)
										continue;
									sText += AtlFormatString(_T(" * ") _T("%s") _T("\r\n"), m_Owner.GetConnectionText(pOutputPin, pInputPin));
								}
								sText += _T("\r\n");
							}
						}
						#pragma endregion 
						#pragma region Media Type
						_FilterGraphHelper::CPinArray PinArray;
						if(_FilterGraphHelper::GetFilterPins(Data.m_pBaseFilter, PinArray))
						{
							sText += AtlFormatString(_T("## ") _T("Media Types") _T("\r\n") _T("\r\n"));
							for(SIZE_T nPinIndex = 0; nPinIndex < PinArray.GetCount(); nPinIndex++)
							{
								const CComPtr<IPin>& pPin = PinArray[nPinIndex];
								CString sPinText = AtlFormatString(_T("%s"), FormatIdentifier(_FilterGraphHelper::GetPinFullName(pPin)));
								const CComPtr<IPin> pPeerPin = _FilterGraphHelper::GetPeerPin(pPin);
								if(pPeerPin)
									sPinText += AtlFormatString(_T(", %s"), FormatIdentifier(_FilterGraphHelper::GetPinFullName(pPeerPin)));
								sText += AtlFormatString(_T("%d. ") _T("%s") _T("\r\n"), 1 + nPinIndex, sPinText);
								_ATLTRY
								{
									CMediaType pMediaType;
									if(pPeerPin)
										pMediaType = _FilterGraphHelper::GetPinMediaType(pPin);
									else
										pMediaType = _FilterGraphHelper::EnumerateFirstPinMediaType(pPin);
									if(!pMediaType)
										continue;
									sText += m_Owner.GetMediaTypeText(pMediaType);
								}
								_ATLCATCHALL()
								{
									_Z_EXCEPTION();
								}
							}
							sText += _T("\r\n");
						}
						#pragma endregion
						#pragma region Runtime Property Bag
						_ATLTRY
						{
							const CString sPropertyBagText = CRunPropertyBagHelper::GetPropertyBagText(Data.m_pBaseFilter, CComQIPtr<ISpy>(m_Owner.m_pFilterGraph));
							if(!sPropertyBagText.IsEmpty())
							{
								sText += AtlFormatString(_T("## ") _T("Runtime Properties") _T("\r\n") _T("\r\n"));
								sText += sPropertyBagText;
								sText += _T("\r\n");
							}
						}
						_ATLCATCHALL()
						{
							_Z_EXCEPTION();
						}
						#pragma endregion 
						m_TextEdit.SetValue(sText);
						m_ApplyButton.EnableWindow(FALSE);
					}
					#pragma endregion
				} else
				#pragma endregion
				#pragma region Service Property Page 
				if(Data.m_pPropertyPage)
				{
					ShowText(FALSE);
					if(Data.m_pSite != m_pCurrentSite)
						HideCurrentSite();
					if(!Data.m_bSiteActivated)
					{
						__C(Data.m_pPropertyPage->Activate(m_hWnd, GetTextEditPosition(), TRUE));
						Data.m_bSiteActivated = TRUE;
					} else
						__C(Data.m_pPropertyPage->Move(GetTextEditPosition()));
					__C(Data.m_pPropertyPage->Show(SW_SHOWNORMAL));
					m_pCurrentSite = Data.m_pSite;
					HandleStatusChange(m_pCurrentSite);
				} else
				#pragma endregion
				#pragma region Other
				{
					CWaitCursor WaitCursor;
					HideCurrentSite();
					switch(Data.m_Type)
					{
					#pragma region TYPE_MEMORYALLOCATOR
					case CData::TYPE_MEMORYALLOCATOR:
						ShowText(FALSE);
						_W(m_MemoryAllocatorDialog.SetWindowPos(NULL, GetTextEditPosition(), SWP_NOZORDER | SWP_SHOWWINDOW));
						break;
					#pragma endregion
					#pragma region TYPE_ACTION
					case CData::TYPE_ACTION:
						ShowText(FALSE);
						_W(m_ActionDialog.SetWindowPos(NULL, GetTextEditPosition(), SWP_NOZORDER | SWP_SHOWWINDOW));
						break;
					#pragma endregion
					#pragma region TYPE_EMAIL
					case CData::TYPE_EMAIL:
						ShowText(FALSE);
						_W(m_EmailDialog.SetWindowPos(NULL, GetTextEditPosition(), SWP_NOZORDER | SWP_SHOWWINDOW));
						break;
					#pragma endregion
					#pragma region TYPE_EMAIL_LOG
					case CData::TYPE_EMAIL_LOG:
						ShowText(FALSE);
						_W(m_EmailLogDialog.SetWindowPos(NULL, GetTextEditPosition(), SWP_NOZORDER | SWP_SHOWWINDOW));
						break;
					#pragma endregion
					default:
						UpdateText();
						ShowText(TRUE, TRUE);
						m_MemoryAllocatorDialog.ShowWindow(SW_HIDE);
						m_ActionDialog.ShowWindow(SW_HIDE);
						m_EmailDialog.ShowWindow(SW_HIDE);
						m_EmailLogDialog.ShowWindow(SW_HIDE);
					}
					m_ApplyButton.EnableWindow(FALSE);
				}
				#pragma endregion
			} else
			#pragma endregion
			#pragma region No Tree Item
			{
				HideCurrentSite();
				ShowText(FALSE);
				m_MemoryAllocatorDialog.ShowWindow(SW_HIDE);
				m_ActionDialog.ShowWindow(SW_HIDE);
				m_EmailDialog.ShowWindow(SW_HIDE);
				m_EmailLogDialog.ShowWindow(SW_HIDE);
				m_ApplyButton.EnableWindow(FALSE);
			}
			#pragma endregion
			return 0;
		}
		LRESULT OnTreeViewItemExplanding(NMTREEVIEW* pHeader)
		{
			if(pHeader->action == TVE_COLLAPSE)
				return TRUE; // Prevent Collapsing
			return 0;
		}
		LRESULT OnTreeViewDblClk(NMHDR*)
		{
			CTreeItem TreeItem = m_TreeView.GetSelectedItem();
			if(!TreeItem)
				return 0;
			CData& Data = m_TreeView.GetItemData(TreeItem);
			if(!Data.m_pBaseFilter)
				return 0;
			COlePropertyFrameDialog Dialog(Data.m_pBaseFilter);
			if(!Dialog.SetObjectPages())
				return 0;
			Dialog.DoModal(m_hWnd);
			return 0;
		}
		VOID UpdateText()
		{
			m_TextEdit.SetValue(m_Owner.GetText());
			const INT nTextLength = m_TextEdit.GetWindowTextLength();
			//m_RefreshStatic.EnableWindow(TRUE);
			m_CopyStatic.EnableWindow(nTextLength > 0);
			m_SaveAsStatic.EnableWindow(nTextLength > 0);
		}
		LRESULT OnRefreshAnchorClicked(NMHDR*)
		{
			UpdateText();
			MessageBeep(MB_OK);
			return 0;
		}
		LRESULT OnCopyAnchorClicked(NMHDR*)
		{
			SetClipboardText(m_hWnd, m_TextEdit.GetValue());
			MessageBeep(MB_OK);
			return 0;
		}
		LRESULT OnSaveAsAnchorClicked(NMHDR*)
		{
			static const COMDLG_FILTERSPEC g_pFilter[] = 
			{
				{ _T("Markdown Files"), _T("*.md") },
				{ _T("Text Files"), _T("*.txt") },
				{ _T("BZip2 Compressed Markdown Files"), _T("*.md.bz2") },
				{ _T("All Files"), _T("*.*") },
			};
			CPath sPath = _CommonDialogHelper::QuerySavePath(m_hWnd, g_pFilter, _T("md"));
			if(!_tcslen(sPath))
				return 0;
			CAtlFile File;
			__C(File.Create(sPath, GENERIC_WRITE, FILE_SHARE_READ, CREATE_ALWAYS));
			_ATLTRY
			{
				CStringA sText = Utf8StringFromString(CStringW(m_TextEdit.GetValue()));
				static const BYTE g_pnByteOrderMark[] = { 0xEF, 0xBB, 0xBF, 0x00 };
				sText.Insert(0, (LPCSTR) g_pnByteOrderMark);
				if(_tcsicmp(GetPathExtension(sPath), _T(".bz2")) == 0)
				{
					CLocalObjectPtr<CBzip2Item> pItem;
					pItem->SetRawData((const BYTE*) (LPCSTR) sText, sText.GetLength());
					CHeapPtr<BYTE> pnData;
					SIZE_T nDataSize = 0;
					pItem->GetData(pnData, nDataSize);
					__C(File.Write(pnData, (DWORD) nDataSize));
				} else
					__C(File.Write(sText, (DWORD) sText.GetLength()));
			}
			_ATLCATCHALL()
			{
				File.Close();
				_W(DeleteFile(sPath));
				_ATLRETHROW;
			}
			MessageBeep(MB_OK);	
			return 0;
		}
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
		LRESULT OnOk(UINT, INT nIdentifier, HWND)
		{
			_ATLTRY
			{
				#pragma region Apply All
				for(POSITION Position = m_TreeView.GetDataList().GetHeadPosition(); Position; m_TreeView.GetDataList().GetNext(Position))
				{
					CData& Data = m_TreeView.GetDataList().GetAt(Position);
					if(!Data.m_pSite)
						continue;
					_A(Data.m_pPropertyPage);
					if(Data.m_bSiteActivated && Data.m_pSite->IsDirty())
						__C(Data.m_pPropertyPage->Apply());
				}
				#pragma endregion
			}
			_ATLCATCH(Exception)
			{
				_Z_ATLEXCEPTION(Exception);
				AtlMessageBoxEx(m_hWnd, (LPCTSTR) Ds::FormatResult(Exception), IDS_ERROR, MB_ICONERROR | MB_OK);
				return 0;
			}
			EndDialog(nIdentifier);
			return 0;
		}
		LRESULT OnCancel(UINT, INT nIdentifier, HWND)
		{
			EndDialog(nIdentifier);
			return 0;
		}
		LRESULT OnApply(UINT, INT, HWND)
		{
			_ATLTRY
			{
				Apply();
			}
			_ATLCATCH(Exception)
			{
				_Z_ATLEXCEPTION(Exception);
				AtlMessageBoxEx(m_hWnd, (LPCTSTR) Ds::FormatResult(Exception), IDS_ERROR, MB_ICONERROR | MB_OK);
			}
			return 0;
		}
		LRESULT OnTreeWalkUp(UINT, INT, HWND)
		{
			CTreeItem TreeItem = m_TreeView.GetSelectedItem();
			CTreeItem ParentTreeItem = TreeItem.GetParent();
			if(!ParentTreeItem)
				return 0;
			m_TreeView.SetFocus();
			m_TreeView.Select(ParentTreeItem, TVGN_CARET);
			return 0;
		}
		LRESULT OnActionCommand(UINT, INT nIdentifier, HWND)
		{
			return m_ActionDialog.SendMessage(WM_COMMAND, nIdentifier);
		}
	};

private:
	mutable CRoCriticalSection m_DataCriticalSection;
	CProcessData m_ProcessData;
	CComPtr<IFilterGraph> m_pFilterGraph;
	COptions m_Options;

public:
// CFilterGraphHelper
	static HRESULT WINAPI UpdateRegistry(BOOL bRegister)
	{
		_Z2(atlTraceRegistrar, 2, _T("bRegister %d\n"), bRegister);
		_ATLTRY
		{
			UpdateRegistryFromResource<CFilterGraphHelper>(bRegister);
		}
		_ATLCATCH(Exception)
		{
			_C(Exception);
		}
		return S_OK;
	}
	CFilterGraphHelper()
	{
		_Z4_THIS();
	}
	~CFilterGraphHelper()
	{
		_Z4_THIS();
	}
	static CString FormatIdentifier(LPCSTR pszValue)
	{
		CString sText;
		if(pszValue && *pszValue)
		{
			sText = _T("``");
			sText.Insert(1, CString(pszValue));
		}
		return sText;
	}
	static CString FormatIdentifier(LPCWSTR pszValue)
	{
		CString sText;
		if(pszValue && *pszValue)
		{
			sText = _T("``");
			sText.Insert(1, CString(pszValue));
		}
		return sText;
	}
	static CString FormatIdentifier(LONG nValue)
	{
		CString sText;
		sText = _T("``");
		sText.Insert(1, _StringHelper::FormatNumber(nValue));
		return sText;
	}
	static CString FormatIdentifier(ULONG nValue)
	{
		return FormatIdentifier((LONG) nValue);
	}
	static CString FormatIdentifier(BOOL nValue)
	{
		return FormatIdentifier((LONG) nValue);
	}
	static CString FormatIdentifier(LONGLONG nValue)
	{
		CString sText;
		sText = _T("``");
		sText.Insert(1, _StringHelper::FormatNumber(nValue));
		return sText;
	}
	static CString FormatIdentifier(LONG nValue, LPCTSTR pszFormat)
	{
		CString sText;
		sText = _T("``");
		sText.Insert(1, AtlFormatString(pszFormat, nValue));
		return sText;
	}
	static CString FormatIdentifier(const VOID* pvValue, LPCTSTR pszFormat = _T("0x%p"))
	{
		CString sText;
		sText = _T("``");
		sText.Insert(1, AtlFormatString(pszFormat, pvValue));
		return sText;
	}
	#define I FormatIdentifier
	static CString FormatPhysicalConnectorType(PhysicalConnectorType Value)
	{
		struct 
		{
			PhysicalConnectorType Value;
			LPCSTR pszName;
		} g_pMap[] = 
		{
			#define A(x) { x, #x },
			A(PhysConn_Video_Tuner)
			A(PhysConn_Video_Composite)
			A(PhysConn_Video_SVideo)
			A(PhysConn_Video_RGB)
			A(PhysConn_Video_YRYBY)
			A(PhysConn_Video_SerialDigital)
			A(PhysConn_Video_ParallelDigital)
			A(PhysConn_Video_SCSI)
			A(PhysConn_Video_AUX)
			A(PhysConn_Video_1394)
			A(PhysConn_Video_USB)
			A(PhysConn_Video_VideoDecoder)
			A(PhysConn_Video_VideoEncoder)
			A(PhysConn_Video_SCART)
			A(PhysConn_Video_Black)
			A(PhysConn_Audio_Tuner)
			A(PhysConn_Audio_Line)
			A(PhysConn_Audio_Mic)
			A(PhysConn_Audio_AESDigital)
			A(PhysConn_Audio_SPDIFDigital)
			A(PhysConn_Audio_SCSI)
			A(PhysConn_Audio_AUX)
			A(PhysConn_Audio_1394)
			A(PhysConn_Audio_USB)
			A(PhysConn_Audio_AudioDecoder)
			#undef A
		};
		for(SIZE_T nIndex = 0; nIndex < DIM(g_pMap); nIndex++)
			if(g_pMap[nIndex].Value == Value)
				return CString(g_pMap[nIndex].pszName);
		return AtlFormatString(_T("0x%04X"), Value);
	}
	static CString FormatPins(_FilterGraphHelper::CPinArray& PinArray)
	{
		CRoArrayT<CString> Array;
		for(SIZE_T nIndex  = 0; nIndex < PinArray.GetCount(); nIndex++)
		{
			const CComPtr<IPin>& pPin = PinArray[nIndex];
			CString sText = I(_FilterGraphHelper::GetPinName(pPin));
			const CComPtr<IPin> pPeerPin = _FilterGraphHelper::GetPeerPin(pPin);
			if(pPeerPin)
				sText += AtlFormatString(_T(" (%s)"), I(_FilterGraphHelper::GetPinFullName(pPeerPin)));
			Array.Add(sText);
		}
		return _StringHelper::Join(Array, _T(", "));
	}
	static CString GetFilterText(IBaseFilter* pBaseFilter, const CProcessData* pProcessData, IReferenceClock* pFilterGraphReferenceClock = NULL)
	{
		CString sText;
		#pragma region COM
		CString sPath;
		const CStringW sClassIdentifierString = _FilterGraphHelper::GetFilterClassIdentifierString(pBaseFilter);
		if(!sClassIdentifierString.IsEmpty())
		{
			CLSID ClassIdentifier = CLSID_NULL;
			const BOOL bClassIdentifierAvailable = _PersistHelper::ClassIdentifierFromString(sClassIdentifierString, ClassIdentifier);
			if(bClassIdentifierAvailable && ClassIdentifier != CLSID_NULL)
			{
				sText += AtlFormatString(_T(" * ") _T("Class: %s %s") _T("\r\n"), I(sClassIdentifierString), I(_FilterGraphHelper::GetFilterClassDescription(pBaseFilter)));
				_ATLTRY
				{
					sPath = _RegKeyHelper::QueryStringValue(HKEY_CLASSES_ROOT, AtlFormatString(_T("CLSID\\%ls\\InprocServer32"), sClassIdentifierString));
					if(!sPath.IsEmpty())
					{
						sText += AtlFormatString(_T(" * ") _T("Inproc Server: %s") _T("\r\n"), I(sPath));
						const ULONGLONG nProductVersion = _VersionInfoHelper::GetProductVersion(sPath);
						if(nProductVersion && (nProductVersion + 1))
							sText += AtlFormatString(_T(" * ") _T("Product Version: %s") _T("\r\n"), I(_VersionInfoHelper::GetVersionString(nProductVersion)));
						const ULONGLONG nFileVersion = _VersionInfoHelper::GetFileVersion(sPath);
						if(nFileVersion && (nFileVersion + 1))
							sText += AtlFormatString(_T(" * ") _T("File Version: %s") _T("\r\n"), I(_VersionInfoHelper::GetVersionString(nFileVersion)));
					}
				}
				_ATLCATCHALL()
				{
					_Z_EXCEPTION();
				}
			}
		}
		if(_tcslen(sPath) == 0 && pProcessData && pProcessData->m_nIdentifier == GetCurrentProcessId())
			_ATLTRY
			{
				const VOID* pvVirtualTable = *((const VOID**) pBaseFilter);
				MEMORY_BASIC_INFORMATION Information;
				if(VirtualQueryEx(GetCurrentProcess(), pvVirtualTable, &Information, sizeof Information))
				{
					TCHAR pszPath[MAX_PATH] = { 0 };
					if(GetModuleFileName((HMODULE) Information.AllocationBase, pszPath, DIM(pszPath)))
					{
						sPath = pszPath;
						sText += AtlFormatString(_T(" * ") _T("Virtual Table Location: %s") _T("\r\n"), I(sPath));
						const ULONGLONG nProductVersion = _VersionInfoHelper::GetProductVersion(sPath);
						if(nProductVersion && (nProductVersion + 1))
							sText += AtlFormatString(_T(" * ") _T("Product Version: %s") _T("\r\n"), I(_VersionInfoHelper::GetVersionString(nProductVersion)));
						const ULONGLONG nFileVersion = _VersionInfoHelper::GetFileVersion(sPath);
						if(nFileVersion && (nFileVersion + 1))
							sText += AtlFormatString(_T(" * ") _T("File Version: %s") _T("\r\n"), I(_VersionInfoHelper::GetVersionString(nFileVersion)));
					}
				}
			}
			_ATLCATCHALL()
			{
				_Z_EXCEPTION();
			}
		#pragma endregion 
		#pragma region Pin
		_FilterGraphHelper::CPinArray InputPinArray;
		if(_FilterGraphHelper::GetFilterPins(pBaseFilter, PINDIR_INPUT, InputPinArray))
			sText += AtlFormatString(_T(" * ") _T("Input Pins: %s") _T("\r\n"), FormatPins(InputPinArray));
		_FilterGraphHelper::CPinArray OutputPinArray;
		if(_FilterGraphHelper::GetFilterPins(pBaseFilter, PINDIR_OUTPUT, OutputPinArray))
			sText += AtlFormatString(_T(" * ") _T("Output Pins: %s") _T("\r\n"), FormatPins(OutputPinArray));
		#pragma endregion 
		#pragma region IReferenceClock
		const CComQIPtr<IReferenceClock> pReferenceClock = pBaseFilter;
		if(pReferenceClock)
		{
			CRoArrayT<CString> Array;
			Array.Add(I(_T("Available")));
			if(pReferenceClock == pFilterGraphReferenceClock)
				Array.Add(I(_T("Selected")));
			sText += AtlFormatString(_T(" * ") _T("Reference Clock: %s") _T("\r\n"), _StringHelper::Join(Array, _T(", ")));
		}
		#pragma endregion 
		#pragma region IFileSourceFilter
		const CComQIPtr<IFileSourceFilter> pFileSourceFilter = pBaseFilter;
		if(pFileSourceFilter)
			_ATLTRY
			{
				CComHeapPtr<OLECHAR> pszFileName;
				CMediaType pMediaType;
				pMediaType.Allocate(MEDIATYPE_NULL, MEDIASUBTYPE_NULL);
				const HRESULT nGetCurFileResult = pFileSourceFilter->GetCurFile(&pszFileName, pMediaType);
				_Z45_DSHRESULT(nGetCurFileResult);
				if(SUCCEEDED(nGetCurFileResult))
					sText += AtlFormatString(_T(" * ") _T("File Source: %s") _T("\r\n"), I(pszFileName));
			}
			_ATLCATCHALL()
			{
				_Z_EXCEPTION();
			}
		#pragma endregion 
		#pragma region IFileSinkFilter
		const CComQIPtr<IFileSinkFilter> pFileSinkFilter = pBaseFilter;
		if(pFileSinkFilter)
			_ATLTRY
			{
				CComHeapPtr<OLECHAR> pszFileName;
				CMediaType pMediaType;
				pMediaType.Allocate(MEDIATYPE_NULL, MEDIASUBTYPE_NULL);
				const HRESULT nGetCurFileResult = pFileSinkFilter->GetCurFile(&pszFileName, pMediaType);
				_Z45_DSHRESULT(nGetCurFileResult);
				if(SUCCEEDED(nGetCurFileResult))
					sText += AtlFormatString(_T(" * ") _T("File Sink: %s") _T("\r\n"), I(pszFileName));
			}
			_ATLCATCHALL()
			{
				_Z_EXCEPTION();
			}
		#pragma endregion 
		#pragma region IMediaSeeking
		const CComQIPtr<IMediaSeeking> pMediaSeeking = pBaseFilter;
		if(pMediaSeeking)
			_ATLTRY
			{
				sText += AtlFormatString(_T(" * ") _T("Media Seeking/Position") _T("\r\n"));
				DWORD nCapabilities = 0;
				if(SUCCEEDED(pMediaSeeking->GetCapabilities(&nCapabilities)))
					sText += AtlFormatString(_T("  * ") _T("Capabilities: %s") _T("\r\n"), I(AtlFormatString(_T("0x%X"), nCapabilities)));
				LONGLONG nDuration = 0, nPosition = 0, nStopPosition = 0;
				if(SUCCEEDED(pMediaSeeking->GetDuration(&nDuration)))
					sText += AtlFormatString(_T("  * ") _T("Duration: %s (%s seconds)") _T("\r\n"), I(_FilterGraphHelper::FormatSecondTime((DOUBLE) nDuration / 1E7)), I(_StringHelper::FormatNumber((DOUBLE) nDuration / 1E7, 3)));
				if(SUCCEEDED(pMediaSeeking->GetCurrentPosition(&nPosition)))
					sText += AtlFormatString(_T("  * ") _T("Position: %s (%s seconds)") _T("\r\n"), I(_FilterGraphHelper::FormatSecondTime((DOUBLE) nPosition / 1E7)), I(_StringHelper::FormatNumber((DOUBLE) nPosition / 1E7, 3)));
				if(SUCCEEDED(pMediaSeeking->GetStopPosition(&nStopPosition)))
					sText += AtlFormatString(_T("  * ") _T("Stop Position: %s (%s seconds)") _T("\r\n"), I(_FilterGraphHelper::FormatSecondTime((DOUBLE) nStopPosition / 1E7)), I(_StringHelper::FormatNumber((DOUBLE) nStopPosition / 1E7, 3)));
				DOUBLE fRate = 1.0;
				if(SUCCEEDED(pMediaSeeking->GetRate(&fRate)))
					sText += AtlFormatString(_T("  * ") _T("Rate: %s") _T("\r\n"), I(_StringHelper::FormatNumber(fRate, 3)));
				LONGLONG nPreroll = 0;
				if(SUCCEEDED(pMediaSeeking->GetPreroll(&nPreroll)) && nPreroll)
					sText += AtlFormatString(_T("  * ") _T("Preroll: %s seconds") _T("\r\n"), I(_StringHelper::FormatNumber((DOUBLE) nPreroll / 1E7, 3)));
			}
			_ATLCATCHALL()
			{
				_Z_EXCEPTION();
			}
		#pragma endregion 
		#pragma region IAMCrossbar
		const CComQIPtr<IAMCrossbar> pAmCrossbar = pBaseFilter;
		if(pAmCrossbar)
			_ATLTRY
			{
				sText += AtlFormatString(_T(" * ") _T("Crossbar:") _T("\r\n"));
				LONG nOutputPinCount = 0, nInputPinCount = 0;
				__C(pAmCrossbar->get_PinCounts(&nOutputPinCount, &nInputPinCount));
				sText += AtlFormatString(_T("  * ") _T("Pins: %s Input, %s Output") _T("\r\n"), I(nInputPinCount), I(nOutputPinCount));
				#pragma region Input
				for(LONG nInputPinIndex = 0; nInputPinIndex < nInputPinCount; nInputPinIndex++)
					_ATLTRY
					{
						CRoArrayT<CString> Array;
						LONG nRelatedPinIndex = -1;
						LONG nPhysicalType = 0; // PhysicalConnectorType
						__C(pAmCrossbar->get_CrossbarPinInfo(TRUE, nInputPinIndex, &nRelatedPinIndex, &nPhysicalType));
						if(nRelatedPinIndex >= 0)
							Array.Add(AtlFormatString(_T("Related %s"), I(nRelatedPinIndex)));
						Array.Add(AtlFormatString(_T("Physical Type %s"), I(FormatPhysicalConnectorType((PhysicalConnectorType) nPhysicalType))));
						sText += AtlFormatString(_T("  * ") _T("Input Pin %s: %s") _T("\r\n"), I(nInputPinIndex), _StringHelper::Join(Array, _T("; ")));
					}
					_ATLCATCHALL()
					{
						_Z_EXCEPTION();
					}
				#pragma endregion
				#pragma region Output
				for(LONG nOutputPinIndex = 0; nOutputPinIndex < nOutputPinCount; nOutputPinIndex++)
					_ATLTRY
					{
						CRoArrayT<CString> Array;
						LONG nRelatedPinIndex = -1;
						LONG nPhysicalType = 0; // PhysicalConnectorType
						__C(pAmCrossbar->get_CrossbarPinInfo(FALSE, nOutputPinIndex, &nRelatedPinIndex, &nPhysicalType));
						if(nRelatedPinIndex >= 0)
							Array.Add(AtlFormatString(_T("Related %s"), I(nRelatedPinIndex)));
						if(nPhysicalType > 0)
							Array.Add(AtlFormatString(_T("Physical Type %s"), I(FormatPhysicalConnectorType((PhysicalConnectorType) nPhysicalType))));
						LONG nRoutedInputPinIndex = -1;
						const HRESULT nGetIsRoutedToResult = pAmCrossbar->get_IsRoutedTo(nOutputPinIndex, &nRoutedInputPinIndex);
						_A(nGetIsRoutedToResult == S_OK || nRoutedInputPinIndex == -1);
						if(nRoutedInputPinIndex >= 0)
							Array.Add(AtlFormatString(_T("Routed to Input Pin %s"), I(nRoutedInputPinIndex)));
						CRoArrayT<CString> PinArray;
						for(LONG nInputPinIndex = 0; nInputPinIndex < nInputPinCount; nInputPinIndex++)
						{
							const HRESULT nCanRouteResult = pAmCrossbar->CanRoute(nOutputPinIndex, nInputPinIndex);
							if(nCanRouteResult == S_OK)
								PinArray.Add(I(nInputPinIndex));
						}
						if(!PinArray.IsEmpty())
							Array.Add(AtlFormatString(_T("Routeable to Input Pins %s"), _StringHelper::Join(PinArray, _T(", "))));
						sText += AtlFormatString(_T("  * ") _T("Output Pin %s: %s") _T("\r\n"), I(nOutputPinIndex), _StringHelper::Join(Array, _T("; ")));
					}
					_ATLCATCHALL()
					{
						_Z_EXCEPTION();
					}
				#pragma endregion
			}
			_ATLCATCHALL()
			{
				_Z_EXCEPTION();
			}
		#pragma endregion 
		return sText;
	}
	static CString GetConnectionText(IPin* pOutputPin, IPin* pInputPin)
	{
		_A(pOutputPin && pInputPin);
		CString sText = AtlFormatString(_T("%s - %s"), I(_FilterGraphHelper::GetPinFullName(pOutputPin)), I(_FilterGraphHelper::GetPinFullName(pInputPin)));
		_ATLTRY
		{
			const CMediaType pMediaType = _FilterGraphHelper::GetPinMediaType(pOutputPin);
			if(pMediaType)
			{
				CStringW sMajorType = _FilterGraphHelper::FormatMajorType(pMediaType->majortype);
				CStringW sSubtype;
				if(pMediaType->subtype != MEDIASUBTYPE_NULL)
					sSubtype = _FilterGraphHelper::FormatSubtype(pMediaType->majortype, pMediaType->subtype);
				CRoArrayT<CString> Array;
				Array.Add(I(sMajorType));
				if(!sSubtype.IsEmpty())
					Array.Add(I(sSubtype));
				#pragma region MEDIATYPE_Video
				if(pMediaType->majortype == MEDIATYPE_Video)
				{
					const CVideoInfoHeader2 VideoInfoHeader2 = pMediaType.GetCompatibleVideoInfoHeader2();
					const CSize Extent = VideoInfoHeader2.GetExtent();
					if(Extent.cx || Extent.cy)
						Array.Add(AtlFormatString(_T("%s x %s"), I(Extent.cx), I(Extent.cy)));
					if(VideoInfoHeader2.AvgTimePerFrame > 0)
						Array.Add(AtlFormatString(_T("%s frames/sec"), I(_StringHelper::FormatNumber(1E7 / VideoInfoHeader2.AvgTimePerFrame, 3))));
				} else
				#pragma endregion 
				#pragma region MEDIATYPE_Audio
				if(pMediaType->majortype == MEDIATYPE_Audio)
				{
					const CWaveFormatEx* pWaveFormatEx = pMediaType.GetWaveFormatEx();
					if(pWaveFormatEx)
					{
						if(pWaveFormatEx->nSamplesPerSec)
							Array.Add(AtlFormatString(_T("%s Hz"), I(pWaveFormatEx->nSamplesPerSec)));
						if(pWaveFormatEx->nChannels)
							Array.Add(AtlFormatString(_T("%s channels"), I(pWaveFormatEx->nChannels)));
						if(pWaveFormatEx->wBitsPerSample)
							Array.Add(AtlFormatString(_T("%s bits"), I(pWaveFormatEx->wBitsPerSample)));
					}
				}
				#pragma endregion 
				sText += AtlFormatString(_T(" (%s)"), _StringHelper::Join(Array, _T(", ")));
			}
		}
		_ATLCATCHALL()
		{
			_Z_EXCEPTION();
		}
		return sText;
	}
	static CString GetMediaTypeText(const CMediaType& pMediaType)
	{
		CString sText;
		#pragma region AM_MEDIA_TYPE
		#define J(x) I(pMediaType->x)
		#define K1(x) sText += AtlFormatString(_T(" * `") _T(#x) _T("`: %s") _T("\r\n"), J(x))
		sText += AtlFormatString(_T(" * ") _T("Data: %s") _T("\r\n"), I(AtlFormatData((const BYTE*) (const AM_MEDIA_TYPE*) pMediaType, sizeof *pMediaType).TrimRight()));
		sText += AtlFormatString(_T(" * ") _T("`majortype`: %s") _T("\r\n"), I(_FilterGraphHelper::FormatMajorType(pMediaType->majortype)));
		if(pMediaType->subtype != MEDIASUBTYPE_NULL)
			sText += AtlFormatString(_T(" * ") _T("`subtype`: %s") _T("\r\n"), I(_FilterGraphHelper::FormatSubtype(pMediaType->majortype, pMediaType->subtype)));
		K1(bFixedSizeSamples);
		K1(bTemporalCompression);
		K1(lSampleSize);
		if(pMediaType->formattype != GUID_NULL)
			sText += AtlFormatString(_T(" * ") _T("`formattype`: %s") _T("\r\n"), I(_FilterGraphHelper::FormatFormatType(pMediaType->formattype)));
		if(pMediaType->pUnk)
			sText += AtlFormatString(_T(" * ") _T("`pUnk`: %s") _T("\r\n"), I(AtlFormatString(_T("0x%p"), pMediaType->pUnk)));
		if(pMediaType->cbFormat)
		{
			K1(cbFormat);
			if(pMediaType->pbFormat)
				sText += AtlFormatString(_T(" * ") _T("Format Data, `pbFormat`: %s") _T("\r\n"), I(AtlFormatData(pMediaType->pbFormat, pMediaType->cbFormat).TrimRight()));
		}
		#undef J
		#undef K1
		#pragma endregion
		const BYTE* pnExtraData = NULL;
		SIZE_T nExtraDataSize = 0;
		#pragma region FORMAT_VideoInfo
		if(pMediaType->formattype == FORMAT_VideoInfo)
		{
			sText += AtlFormatString(_T(" * ") _T("As `VIDEOINFOHEADER`:") _T("\r\n"));
			const VIDEOINFOHEADER* pVideoInfoHeader = (const VIDEOINFOHEADER*) pMediaType->pbFormat;
			if(pVideoInfoHeader && pMediaType->cbFormat >= sizeof *pVideoInfoHeader)
			{
				#define J(x) I(pVideoInfoHeader->x)
				#define K1(x) sText += AtlFormatString(_T("  * `") _T(#x) _T("`: %s") _T("\r\n"), J(x))
				sText += AtlFormatString(_T("  * ") _T("`rcSource`: (%s, %s) - (%s, %s)") _T("\r\n"), J(rcSource.left), J(rcSource.top), J(rcSource.right), J(rcSource.bottom));
				sText += AtlFormatString(_T("  * ") _T("`rcTarget`: (%s, %s) - (%s, %s)") _T("\r\n"), J(rcTarget.left), J(rcTarget.top), J(rcTarget.right), J(rcTarget.bottom));
				K1(dwBitRate);
				K1(dwBitErrorRate);
				sText += AtlFormatString(_T("  * ") _T("`AvgTimePerFrame`: %s units") _T("\r\n"), I(_FilterGraphHelper::FormatReferenceTime(pVideoInfoHeader->AvgTimePerFrame)));
				K1(bmiHeader.biSize);
				K1(bmiHeader.biWidth);
				K1(bmiHeader.biHeight);
				K1(bmiHeader.biPlanes);
				K1(bmiHeader.biBitCount);
				sText += AtlFormatString(_T("  * ") _T("`bmiHeader.biCompression`: %s") _T("\r\n"), I(_FilterGraphHelper::GetFourccCodeString(pVideoInfoHeader->bmiHeader.biCompression)));
				K1(bmiHeader.biSizeImage);
				K1(bmiHeader.biXPelsPerMeter);
				K1(bmiHeader.biYPelsPerMeter);
				K1(bmiHeader.biClrUsed);
				K1(bmiHeader.biClrImportant);
				#undef J
				#undef K1
				nExtraDataSize = pMediaType->cbFormat - sizeof *pVideoInfoHeader;
			}
		} else
		#pragma endregion 
		#pragma region FORMAT_VideoInfo2
		if(pMediaType->formattype == FORMAT_VideoInfo2)
		{
			sText += AtlFormatString(_T(" * ") _T("As `VIDEOINFOHEADER2`:") _T("\r\n"));
			const VIDEOINFOHEADER2* pVideoInfoHeader2 = (const VIDEOINFOHEADER2*) pMediaType->pbFormat;
			if(pVideoInfoHeader2 && pMediaType->cbFormat >= sizeof *pVideoInfoHeader2)
			{
				#define J(x) I(pVideoInfoHeader2->x)
				#define K1(x) sText += AtlFormatString(_T("  * `") _T(#x) _T("`: %s") _T("\r\n"), J(x))
				#define K2(x, y) sText += AtlFormatString(_T("  * `") _T(#x) _T("`: %s") _T("\r\n"), I(pVideoInfoHeader2->x, y))
				sText += AtlFormatString(_T("  * ") _T("rcSource: (%s, %s) - (%s, %s)") _T("\r\n"), J(rcSource.left), J(rcSource.top), J(rcSource.right), J(rcSource.bottom));
				sText += AtlFormatString(_T("  * ") _T("rcTarget: (%s, %s) - (%s, %s)") _T("\r\n"), J(rcTarget.left), J(rcTarget.top), J(rcTarget.right), J(rcTarget.bottom));
				K1(dwBitRate);
				K1(dwBitErrorRate);
				sText += AtlFormatString(_T("  * ") _T("`AvgTimePerFrame`: %s units") _T("\r\n"), I(_FilterGraphHelper::FormatReferenceTime(pVideoInfoHeader2->AvgTimePerFrame)));
				K2(dwInterlaceFlags, _T("0x%X"));
				K2(dwCopyProtectFlags, _T("0x%X"));
				K1(dwPictAspectRatioX);
				K1(dwPictAspectRatioY);
				K2(dwControlFlags, _T("0x%X"));
				K1(bmiHeader.biSize);
				K1(bmiHeader.biWidth);
				K1(bmiHeader.biHeight);
				K1(bmiHeader.biPlanes);
				K1(bmiHeader.biBitCount);
				sText += AtlFormatString(_T("  * ") _T("`bmiHeader.biCompression`: %s") _T("\r\n"), I(_FilterGraphHelper::GetFourccCodeString(pVideoInfoHeader2->bmiHeader.biCompression)));
				K1(bmiHeader.biSizeImage);
				K1(bmiHeader.biXPelsPerMeter);
				K1(bmiHeader.biYPelsPerMeter);
				K1(bmiHeader.biClrUsed);
				K1(bmiHeader.biClrImportant);
				#undef J
				#undef K1
				#undef K2
				nExtraDataSize = pMediaType->cbFormat - sizeof *pVideoInfoHeader2;
				if(nExtraDataSize)
				{
					sText += AtlFormatString(_T("  * ") _T("Extra Data: (%d bytes)") _T("\r\n"), nExtraDataSize);
					nExtraDataSize = 0;
				}
			}
		} else
		#pragma endregion 
		#pragma region FORMAT_MPEG2Video
		if(pMediaType->formattype == FORMAT_MPEG2Video)
		{
			sText += AtlFormatString(_T(" * ") _T("As `MPEG2VIDEOINFO`:") _T("\r\n"));
			const MPEG2VIDEOINFO* pMpeg2VideoInfo = (const MPEG2VIDEOINFO*) pMediaType->pbFormat;
			if(pMpeg2VideoInfo && pMediaType->cbFormat >= offsetof(MPEG2VIDEOINFO, dwSequenceHeader)) //sizeof *pMpeg2VideoInfo)
			{
				#define J(x) I(pMpeg2VideoInfo->x)
				#define K1(x) sText += AtlFormatString(_T("  * `") _T(#x) _T("`: %s") _T("\r\n"), J(x))
				#define K2(x, y) sText += AtlFormatString(_T("  * `") _T(#x) _T("`: %s") _T("\r\n"), I(pMpeg2VideoInfo->x, y))
				sText += AtlFormatString(_T("  * ") _T("`hdr.rcSource`: (%s, %s) - (%s, %s)") _T("\r\n"), J(hdr.rcSource.left), J(hdr.rcSource.top), J(hdr.rcSource.right), J(hdr.rcSource.bottom));
				sText += AtlFormatString(_T("  * ") _T("`hdr.rcTarget`: (%s, %s) - (%s, %s)") _T("\r\n"), J(hdr.rcTarget.left), J(hdr.rcTarget.top), J(hdr.rcTarget.right), J(hdr.rcTarget.bottom));
				K1(hdr.dwBitRate);
				K1(hdr.dwBitErrorRate);
				sText += AtlFormatString(_T("  * ") _T("`hdr.AvgTimePerFrame`: %s") _T("\r\n"), I(_FilterGraphHelper::FormatReferenceTime(pMpeg2VideoInfo->hdr.AvgTimePerFrame)));
				K2(hdr.dwInterlaceFlags, _T("0x%X"));
				K2(hdr.dwCopyProtectFlags, _T("0x%X"));
				K1(hdr.dwPictAspectRatioX);
				K1(hdr.dwPictAspectRatioY);
				K2(hdr.dwControlFlags, _T("0x%X"));
				K1(hdr.bmiHeader.biSize);
				K1(hdr.bmiHeader.biWidth);
				K1(hdr.bmiHeader.biHeight);
				K1(hdr.bmiHeader.biPlanes);
				K1(hdr.bmiHeader.biBitCount);
				sText += AtlFormatString(_T("  * ") _T("`hdr.bmiHeader.biCompression`: %s") _T("\r\n"), I(_FilterGraphHelper::GetFourccCodeString(pMpeg2VideoInfo->hdr.bmiHeader.biCompression)));
				K1(hdr.bmiHeader.biSizeImage);
				K1(hdr.bmiHeader.biXPelsPerMeter);
				K1(hdr.bmiHeader.biYPelsPerMeter);
				K1(hdr.bmiHeader.biClrUsed);
				K1(hdr.bmiHeader.biClrImportant);
				K2(dwStartTimeCode, _T("0x%08X"));
				K1(cbSequenceHeader);
				K1(dwProfile);
				K1(dwLevel);
				K2(dwFlags, _T("0x%08X"));
				#undef J
				#undef K1
				#undef K2
				#undef J
				nExtraDataSize = pMediaType->cbFormat - (offsetof(MPEG2VIDEOINFO, dwSequenceHeader) //sizeof *pMpeg2VideoInfo 
					- sizeof pMpeg2VideoInfo->dwSequenceHeader);
			}
		} else
		#pragma endregion 
		#pragma region FORMAT_WaveFormatEx
		if(pMediaType->formattype == FORMAT_WaveFormatEx)
		{
			const WAVEFORMATEX* pWaveFormatEx = (const WAVEFORMATEX*) pMediaType->pbFormat;
			if(pWaveFormatEx && pMediaType->cbFormat >= sizeof *pWaveFormatEx)
			{
				if(pWaveFormatEx->wFormatTag == WAVE_FORMAT_EXTENSIBLE)
				{
					// WARN: Check pMediaType->cbFormat
					const WAVEFORMATEXTENSIBLE* pWaveFormatExtensible = (const WAVEFORMATEXTENSIBLE*) pMediaType->pbFormat;
					#define J(x) I(pWaveFormatExtensible->x)
					#define K1(x) sText += AtlFormatString(_T("  * `") _T(#x) _T("`: %s") _T("\r\n"), J(x))
					#define K2(x, y) sText += AtlFormatString(_T("  * `") _T(#x) _T("`: %s") _T("\r\n"), I(pWaveFormatExtensible->x, y))
					sText += AtlFormatString(_T(" * ") _T("As `WAVEFORMATEXTENSIBLE`:") _T("\r\n"));
					K2(Format.wFormatTag, _T("0x%02X"));
					K1(Format.nChannels);
					K1(Format.nSamplesPerSec);
					K1(Format.nAvgBytesPerSec);
					K1(Format.nBlockAlign);
					K1(Format.wBitsPerSample);
					K1(Format.cbSize);
					K1(Samples.wValidBitsPerSample);
					K2(dwChannelMask, _T("0x%02X"));
					sText += AtlFormatString(_T("  * ") _T("`SubFormat`: %s") _T("\r\n"), I(_PersistHelper::StringFromIdentifier(pWaveFormatExtensible->SubFormat)));
					#undef J
					#undef K1
					#undef K2
					nExtraDataSize = pWaveFormatEx->cbSize - (sizeof *pWaveFormatExtensible - sizeof *pWaveFormatEx);
				} else
				{
					#define J(x) I(pWaveFormatEx->x)
					#define K1(x) sText += AtlFormatString(_T("  * `") _T(#x) _T("`: %s") _T("\r\n"), J(x))
					#define K2(x, y) sText += AtlFormatString(_T("  * `") _T(#x) _T("`: %s") _T("\r\n"), I(pWaveFormatEx->x, y))
					K2(wFormatTag, _T("0x%02X"));
					K1(nChannels);
					K1(nSamplesPerSec);
					K1(nAvgBytesPerSec);
					K1(nBlockAlign);
					K1(wBitsPerSample);
					K1(cbSize);
					#undef J
					#undef K1
					#undef K2
					nExtraDataSize = pWaveFormatEx->cbSize;
				}
			}
		}
		#pragma endregion 
		#pragma region Extra Data
		if(nExtraDataSize)
		{
			if(!pnExtraData)
			{
				if(nExtraDataSize > pMediaType->cbFormat)
					nExtraDataSize = pMediaType->cbFormat;
				pnExtraData = pMediaType->pbFormat + pMediaType->cbFormat - nExtraDataSize;
			}
			const SSIZE_T nExtraDataExcessSize = (pnExtraData + nExtraDataSize) - (pMediaType->pbFormat + pMediaType->cbFormat);
			if(nExtraDataExcessSize > 0)
				nExtraDataSize -= min((SIZE_T) nExtraDataExcessSize, nExtraDataSize);
			sText += AtlFormatString(_T("  * ") _T("Extra Data: %s") _T("\r\n"), I(AtlFormatData(pnExtraData, nExtraDataSize).TrimRight()));
		}
		#pragma endregion 
		return sText;
	}
	static CString GetText(IFilterGraph* pFilterGraph, const CProcessData* pProcessData = NULL)
	{
		if(!pFilterGraph)
			return (LPCTSTR) NULL;
		const CComQIPtr<IServiceProvider> pServiceProvider = pFilterGraph;
		const CComQIPtr<ISpy> pSpy = pFilterGraph;
		CString sText;
		sText += AtlFormatString(_T("# ") _T("Filter Graph") _T("\r\n") _T("\r\n"));
		#pragma region Graph Parameters
		if(pProcessData)
			sText += AtlFormatString(_T("* ") _T("Process: %s (%s) %s") _T("\r\n"), I(pProcessData->m_nIdentifier), I(pProcessData->m_nIdentifier, _T("0x%X")), I(FindFileName(pProcessData->m_sImagePath)));
		#pragma region IMediaControl
		OAFilterState State = (OAFilterState) -1;
		const CComQIPtr<IMediaControl> pMediaControl = pFilterGraph;
		if(pMediaControl)
			_ATLTRY
			{
				const HRESULT nGetStateResult = pMediaControl->GetState(0, &State);
				_Z45_DSHRESULT(nGetStateResult);
				static const LPCTSTR g_ppszStates[] = { _T("Stopped"), _T("Paused"), _T("Running"), };
				if(SUCCEEDED(nGetStateResult) && (SIZE_T) State < DIM(g_ppszStates))
					sText += AtlFormatString(_T("* ") _T("State: %s") _T("\r\n"), I(g_ppszStates[(SIZE_T) State]));
			}
			_ATLCATCHALL()
			{
				_Z_EXCEPTION();
			}
		#pragma endregion 
		#pragma region IMediaPosition
		const CComQIPtr<IMediaPosition> pMediaPosition = pFilterGraph;
		if(pMediaPosition)
			_ATLTRY
			{
				DOUBLE fDuration = 0, fPosition = 0;
				const HRESULT nGetDurationResult = pMediaPosition->get_Duration(&fDuration);
				_Z45_DSHRESULT(nGetDurationResult);
				if(fDuration > 0)
				{
					sText += AtlFormatString(_T("* ") _T("Duration: %s (%s seconds)") _T("\r\n"), I(_FilterGraphHelper::FormatSecondTime(fDuration)), I(_StringHelper::FormatNumber(fDuration, 3)));
					const HRESULT nCurrentPositionResult = pMediaPosition->get_CurrentPosition(&fPosition);
					_Z45_DSHRESULT(nCurrentPositionResult);
					if(SUCCEEDED(nCurrentPositionResult))
						sText += AtlFormatString(_T("* ") _T("Position: %s (%s seconds)") _T("\r\n"), I(_FilterGraphHelper::FormatSecondTime(fPosition)), I(_StringHelper::FormatNumber(fPosition, 3)));
				}
			}
			_ATLCATCHALL()
			{
				_Z_EXCEPTION();
			}
		#pragma endregion 
		if(pProcessData)
		{
			if(!pProcessData->m_sDisplayName.IsEmpty())
				sText += AtlFormatString(_T("* ") _T("Display Name: %s") _T("\r\n"), I(pProcessData->m_sDisplayName));
			if(_tcslen(pProcessData->m_sImagePath))
			{
				const CString sDirectory = (LPCTSTR) GetPathDirectory(pProcessData->m_sImagePath);
				if(!sDirectory.IsEmpty())
					sText += AtlFormatString(_T("* ") _T("Process Directory: %s") _T("\r\n"), I(sDirectory));
			}
		}
		const CComQIPtr<IMediaFilter> pMediaFilter = pFilterGraph;
		CComPtr<IReferenceClock> pFilterGraphReferenceClock;
		const HRESULT nGetSyncSourceResult = pMediaFilter->GetSyncSource(&pFilterGraphReferenceClock);
		_Z45_DSHRESULT(nGetSyncSourceResult);
		sText += _T("\r\n");
		#pragma endregion 
		#pragma region Filter
		_FilterGraphHelper::CFilterArray FilterArray;
		_FilterGraphHelper::GetGraphFilters(pFilterGraph, FilterArray);
		if(!FilterArray.IsEmpty())
		{
			sText += AtlFormatString(_T("## ") _T("Filters") _T("\r\n") _T("\r\n"));
			for(SIZE_T nIndex = 0; nIndex < FilterArray.GetCount(); nIndex++)
				_ATLTRY
				{
					const CComPtr<IBaseFilter>& pBaseFilter = FilterArray[nIndex];
					sText += AtlFormatString(_T("%d. ") _T("%ls") _T("\r\n"), nIndex + 1, _FilterGraphHelper::GetFilterName(pBaseFilter));
					sText += GetFilterText(pBaseFilter, pProcessData, pFilterGraphReferenceClock);
				}
				_ATLCATCHALL()
				{
					_Z_EXCEPTION();
				}
			sText += _T("\r\n");
			#pragma region Connection
			sText += AtlFormatString(_T("## ") _T("Connections") _T("\r\n") _T("\r\n"));
			INT nConnectionIndex = 0;
			for(auto&& pBaseFilter: FilterArray)
			{
				_FilterGraphHelper::CPinArray PinArray;
				_FilterGraphHelper::GetFilterPins(pBaseFilter, PINDIR_OUTPUT, PinArray);
				for(auto&& pOutputPin: PinArray)
				{
					const CComPtr<IPin> pInputPin = _FilterGraphHelper::GetPeerPin(pOutputPin);
					if(!pInputPin)
						continue;
					sText += AtlFormatString(_T("%d. ") _T("%s") _T("\r\n"), ++nConnectionIndex, GetConnectionText(pOutputPin, pInputPin));
				}
			}
			sText += _T("\r\n");
			#pragma endregion 
			#pragma region Media Type
			sText += AtlFormatString(_T("## ") _T("Media Types") _T("\r\n") _T("\r\n"));
			INT nGlobalPinIndex = 0;
			CRoListT<CComPtr<IPin>> PinList;
			for(SIZE_T nFilterIndex = 0; nFilterIndex < FilterArray.GetCount(); nFilterIndex++)
			{
				const CComPtr<IBaseFilter>& pBaseFilter = FilterArray[nFilterIndex];
				_FilterGraphHelper::CPinArray PinArray;
				_FilterGraphHelper::GetFilterPins(pBaseFilter, PinArray);
				for(SIZE_T nPinIndex = 0; nPinIndex < PinArray.GetCount(); nPinIndex++)
				{
					const CComPtr<IPin>& pPin = PinArray[nPinIndex];
					if(PinList.FindFirst(pPin))
						continue;
					PinList.AddTail(pPin);
					CString sPinText = AtlFormatString(_T("%s"), I(_FilterGraphHelper::GetPinFullName(pPin)));
					const CComPtr<IPin> pPeerPin = _FilterGraphHelper::GetPeerPin(pPin);
					if(pPeerPin)
					{
						PinList.AddTail(pPeerPin);
						sPinText += AtlFormatString(_T(", %s"), I(_FilterGraphHelper::GetPinFullName(pPeerPin)));
					}
					sText += AtlFormatString(_T("%d. ") _T("%s") _T("\r\n"), ++nGlobalPinIndex, sPinText);
					_ATLTRY
					{
						CMediaType pMediaType;
						if(pPeerPin)
							pMediaType = _FilterGraphHelper::GetPinMediaType(pPin);
						else
							pMediaType = _FilterGraphHelper::EnumerateFirstPinMediaType(pPin);
						if(!pMediaType)
							continue;
						sText += GetMediaTypeText(pMediaType);
					}
					_ATLCATCHALL()
					{
						_Z_EXCEPTION();
					}
				}
			}
			sText += _T("\r\n");
			#pragma endregion 
			if(State > State_Stopped)
			{
				#pragma region Memory Allocator
				INT nConnectionIndex = 0;
				for(auto&& pBaseFilter: FilterArray)
				{
					_FilterGraphHelper::CPinArray PinArray;
					_FilterGraphHelper::GetFilterPins(pBaseFilter, PINDIR_INPUT, PinArray);
					for(auto&& pInputPin: PinArray)
					{
						_ATLTRY
						{
							const CComQIPtr<IMemInputPin> pMemInputPin = pInputPin;
							if(!pMemInputPin)
								continue; // No IMemInputPin
							const CComPtr<IPin> pOutputPin = _FilterGraphHelper::GetPeerPin(pInputPin);
							if(!pOutputPin)
								continue; // Not Connected
							CComPtr<IMemAllocator> pMemAllocator;
							pMemInputPin->GetAllocator(&pMemAllocator);
							if(!pMemAllocator)
								continue; // No Memory Allocator
							ALLOCATOR_PROPERTIES Properties;
							const HRESULT nGetPropertiesResult = pMemAllocator->GetProperties(&Properties);
							_Z45_DSHRESULT(nGetPropertiesResult);
							if(FAILED(nGetPropertiesResult))
								continue; // No Memory Allocator Properties
							const CComQIPtr<IMemAllocatorCallbackTemp> pMemAllocatorCallbackTemp = pMemAllocator;
							BOOL bFreeCountAvailable;
							LONG nFreeCount;
							if(pMemAllocatorCallbackTemp)
							{
								const HRESULT nGetFreeCountResult = pMemAllocatorCallbackTemp->GetFreeCount(&nFreeCount);
								_Z45_DSHRESULT(nGetFreeCountResult);
								bFreeCountAvailable = SUCCEEDED(nGetFreeCountResult);
							} else
								bFreeCountAvailable = FALSE;
							CString sConnectionText = AtlFormatString(_T("%s - %s"), I(_FilterGraphHelper::GetPinFullName(pInputPin)), I(_FilterGraphHelper::GetPinFullName(pOutputPin)));
							sConnectionText += _T(": ");
							CRoArrayT<CString> Array;
							Array.Add(AtlFormatString(_T("%s buffers"), I(Properties.cBuffers)));
							if(bFreeCountAvailable)
								Array.Add(AtlFormatString(_T("%s free buffers"), I(nFreeCount)));
							Array.Add(AtlFormatString(_T("%s bytes per buffer"), I(Properties.cbBuffer)));
							if(Properties.cbAlign > 1)
								Array.Add(AtlFormatString(_T("%s byte alignment"), I(Properties.cbAlign)));
							if(Properties.cbPrefix > 0)
								Array.Add(AtlFormatString(_T("%s byte prefix"), I(Properties.cbPrefix)));
							sConnectionText += _StringHelper::Join(Array, _T(", "));
							if(!nConnectionIndex)
								sText += AtlFormatString(_T("## ") _T("Memory Allocators") _T("\r\n") _T("\r\n"));
							sText += AtlFormatString(_T("%d. ") _T("%s") _T("\r\n"), ++nConnectionIndex, sConnectionText);
						}
						_ATLCATCHALL()
						{
							_Z_EXCEPTION();
						}
					}
				}
				if(nConnectionIndex)
					sText += _T("\r\n");
				#pragma endregion
			}
			#pragma region IMediaSeeking
			BOOL bMediaSeekingHeaderAdded = FALSE;
			for(SIZE_T nFilterIndex = 0; nFilterIndex < FilterArray.GetCount(); nFilterIndex++)
			{
				const CComPtr<IBaseFilter>& pBaseFilter = FilterArray[nFilterIndex];
				_FilterGraphHelper::CPinArray PinArray;
				_FilterGraphHelper::GetFilterPins(pBaseFilter, PINDIR_OUTPUT, PinArray);
				for(SIZE_T nPinIndex = 0; nPinIndex < PinArray.GetCount(); nPinIndex++)
				{
					const CComPtr<IPin>& pOutputPin = PinArray[nPinIndex];
					const CComQIPtr<IMediaSeeking> pMediaSeeking = pOutputPin;
					if(!pMediaSeeking)
						continue;
					if(!bMediaSeekingHeaderAdded)
					{
						sText += AtlFormatString(_T("## ") _T("Media Seeking/Position") _T("\r\n") _T("\r\n"));
						bMediaSeekingHeaderAdded = TRUE;
					}
					sText += AtlFormatString(_T("* ") _T("Pin: %s") _T("\r\n"), I(_FilterGraphHelper::GetPinFullName(pOutputPin)));
					_ATLTRY
					{
						DWORD nCapabilities = 0;
						if(SUCCEEDED(pMediaSeeking->GetCapabilities(&nCapabilities)))
							sText += AtlFormatString(_T(" * ") _T("Capabilities: %s") _T("\r\n"), I(AtlFormatString(_T("0x%X"), nCapabilities)));
						LONGLONG nDuration = 0, nPosition = 0, nStopPosition = 0;
						if(SUCCEEDED(pMediaSeeking->GetDuration(&nDuration)))
							sText += AtlFormatString(_T(" * ") _T("Duration: %s (%s seconds)") _T("\r\n"), I(_FilterGraphHelper::FormatSecondTime((DOUBLE) nDuration / 1E7)), I(_StringHelper::FormatNumber((DOUBLE) nDuration / 1E7, 3)));
						if(SUCCEEDED(pMediaSeeking->GetCurrentPosition(&nPosition)))
							sText += AtlFormatString(_T(" * ") _T("Position: %s (%s seconds)") _T("\r\n"), I(_FilterGraphHelper::FormatSecondTime((DOUBLE) nPosition / 1E7)), I(_StringHelper::FormatNumber((DOUBLE) nPosition / 1E7, 3)));
						if(SUCCEEDED(pMediaSeeking->GetStopPosition(&nStopPosition)))
							sText += AtlFormatString(_T(" * ") _T("Stop Position: %s (%s seconds)") _T("\r\n"), I(_FilterGraphHelper::FormatSecondTime((DOUBLE) nStopPosition / 1E7)), I(_StringHelper::FormatNumber((DOUBLE) nStopPosition / 1E7, 3)));
						DOUBLE fRate = 1.0;
						if(SUCCEEDED(pMediaSeeking->GetRate(&fRate)))
							sText += AtlFormatString(_T(" * ") _T("Rate: %s") _T("\r\n"), I(_StringHelper::FormatNumber(fRate, 3)));
						LONGLONG nPreroll = 0;
						if(SUCCEEDED(pMediaSeeking->GetPreroll(&nPreroll)) && nPreroll)
							sText += AtlFormatString(_T(" * ") _T("Preroll: %s seconds") _T("\r\n"), I(_StringHelper::FormatNumber((DOUBLE) nPreroll / 1E7, 3)));
					}
					_ATLCATCHALL()
					{
						_Z_EXCEPTION();
					}
				}
			}
			if(bMediaSeekingHeaderAdded)
				sText += _T("\r\n");
			#pragma endregion 
			#pragma region Runtime Property Bag
			const CString sRunPropertyBagHeader = AtlFormatString(_T("## ") _T("Runtime Properties") _T("\r\n") _T("\r\n"));
			BOOL bRunPropertyBagHeaderAdded = FALSE;
			{
				const CString sPropertyBagText = CRunPropertyBagHelper::GetPropertyBagText(pFilterGraph, pSpy);
				if(!sPropertyBagText.IsEmpty())
				{
					sText += sRunPropertyBagHeader;
					bRunPropertyBagHeaderAdded = TRUE;
					sText += sPropertyBagText;
					sText += _T("\r\n");
				}
			}
			for(auto&& pBaseFilter: FilterArray)
			{
				_ATLTRY
				{
					const CString sPropertyBagText = CRunPropertyBagHelper::GetPropertyBagText(pBaseFilter, pSpy);
					if(sPropertyBagText.IsEmpty())
						continue;
					if(!bRunPropertyBagHeaderAdded)
					{
						sText += sRunPropertyBagHeader;
						bRunPropertyBagHeaderAdded = TRUE;
					}
					sText += AtlFormatString(_T("### ") _T("Filter: %ls") _T("\r\n") _T("\r\n"), _FilterGraphHelper::GetFilterName(pBaseFilter));
					sText += sPropertyBagText;
					sText += _T("\r\n");
				}
				_ATLCATCHALL()
				{
					_Z_EXCEPTION();
				}
			}
			#pragma endregion 
		}
		#pragma endregion 
		#pragma region Clock
		{
			sText += AtlFormatString(_T("## ") _T("Clock") _T("\r\n") _T("\r\n"));
			CComPtr<IReferenceClock> pCurrentReferenceClock;
			_ATLTRY
			{
				const CComQIPtr<IMediaFilter> pMediaFilter = pFilterGraph;
				if(pMediaFilter)
					__C(pMediaFilter->GetSyncSource(&pCurrentReferenceClock));
			}
			_ATLCATCHALL()
			{
				_Z_EXCEPTION();
			}
			CStringW sCurrentName;
			for(auto&& pBaseFilter: FilterArray)
			{
				const CComQIPtr<IReferenceClock> pReferenceClock = pBaseFilter;
				if(!pReferenceClock)
					continue;
				const CStringW sName = _FilterGraphHelper::GetFilterName(pBaseFilter);
				CRoArrayT<CString> Array;
				_ATLTRY
				{
					if(pCurrentReferenceClock == pReferenceClock)
					{
						sCurrentName = sName;
						Array.Add(_T("Current"));
					}
					Array.Add(I(pReferenceClock));
					REFERENCE_TIME nTime = 0;
					__C(pReferenceClock->GetTime(&nTime));
					Array.Add(I(_FilterGraphHelper::FormatReferenceTime(nTime)));
					Array.Add(I(AtlFormatString(_T("0x%I64X"), nTime)));
				}
				_ATLCATCHALL()
				{
					_Z_EXCEPTION();
				}
				sText += AtlFormatString(_T(" * ") _T("%s (%s)") _T("\r\n"), I(sName), _StringHelper::Join(Array, _T(", ")));
			}
			if(pCurrentReferenceClock)
			{
				if(sCurrentName.IsEmpty())
				{
					CRoArrayT<CString> Array;
					_ATLTRY
					{
						Array.Add(I(pCurrentReferenceClock));
						REFERENCE_TIME nTime = 0;
						__C(pCurrentReferenceClock->GetTime(&nTime));
						Array.Add(I(_FilterGraphHelper::FormatReferenceTime(nTime)));
						Array.Add(I(AtlFormatString(_T("0x%I64X"), nTime)));
					}
					_ATLCATCHALL()
					{
						_Z_EXCEPTION();
					}
					sText += AtlFormatString(_T(" * ") _T("Current: External (%s)") _T("\r\n"), _StringHelper::Join(Array, _T(", ")));
				}
			} else
				sText += AtlFormatString(_T(" * ") _T("Current: None") _T("\r\n"));
			sText += _T("\r\n");
		}
		#pragma endregion 
		return sText;
	}
	#undef I
	CComPtr<IFilterGraph> GetFilterGraph() const
	{
		CRoCriticalSectionLock DataLock(m_DataCriticalSection);
		return m_pFilterGraph;
	}
	VOID SetFilterGraph(IFilterGraph* pFilterGraph, CProcessData* pProcessData = NULL) 
	{
		CRoCriticalSectionLock DataLock(m_DataCriticalSection);
		if(!pProcessData)
		{
			m_ProcessData = CProcessData();
			const CComQIPtr<ISpyEx> pSpyEx = pFilterGraph;
			if(pSpyEx)
				m_ProcessData.m_nIdentifier = GetCurrentProcessId();
		} else
			m_ProcessData = *pProcessData;
		m_pFilterGraph = pFilterGraph;
	}
	BOOL SetFilterGraph(IUnknown* pFilterGraphUnknown, CProcessData* pProcessData = NULL) 
	{
		CComQIPtr<IFilterGraph> pFilterGraph;
		if(pFilterGraphUnknown)
		{
			pFilterGraph = pFilterGraphUnknown;
			if(!pFilterGraph)
			{
				const CComQIPtr<IBaseFilter> pBaseFilter = pFilterGraphUnknown;
				if(!pBaseFilter)
				{
					const CComQIPtr<IPin> pPin = pFilterGraphUnknown;
					if(pPin)
						pFilterGraph = _FilterGraphHelper::GetFilterGraph(_FilterGraphHelper::GetPinFilter(pPin));
				} else
					pFilterGraph = _FilterGraphHelper::GetFilterGraph(pBaseFilter);
			}
		}
		SetFilterGraph(pFilterGraph, pProcessData);
		return pFilterGraph != NULL;
	}
	CString GetFilterText(IBaseFilter* pBaseFilter) const
	{
		return GetFilterText(pBaseFilter, m_ProcessData.m_nIdentifier ? &m_ProcessData : NULL);
	}
	CString GetText() const
	{
		CRoCriticalSectionLock DataLock(m_DataCriticalSection);
		return GetText(m_pFilterGraph, m_ProcessData.m_nIdentifier ? &m_ProcessData : NULL);
	}
	static LPCTSTR GetPlatformName()
	{
		#if defined(_WIN64)
			return _T("x64");
		#else
			return _T("Win32");
		#endif // defined(_WIN64)
	}
	static BOOL OpenMonikerWithGsn(LPCWSTR pszMonikerDisplayName, HWND hParentWindow = GetActiveWindow())
	{
		_A(pszMonikerDisplayName);
		static const LPCTSTR g_pszValueName = _T("GraphStudioNext Path");
		static const LPCTSTR g_pszFileName = _T("graphstudionext.exe");
		const CString sValueName = AtlFormatString(_T("%s (%s)"), g_pszValueName, GetPlatformName());
		CString sPath = _RegKeyHelper::QueryStringValue(HKEY_CURRENT_USER, REGISTRY_ROOT, sValueName);
		if(!FileExists(sPath))
			sPath.Empty();
		#pragma region Current Directory
		if(sPath.IsEmpty())
		{
			sPath = (LPCTSTR) Combine(GetPathDirectory(GetModulePath()), g_pszFileName);
			if(!FileExists(sPath))
				sPath.Empty();
		}
		#pragma endregion 
		#pragma region Application Registry
		if(sPath.IsEmpty())
		{
			#if defined(_WIN64)
				static const LPCTSTR g_pszValueName = _T("exeLocation64");
			#else
				static const LPCTSTR g_pszValueName = _T("exeLocation");
			#endif // defined(_WIN64)
			sPath = _RegKeyHelper::QueryStringValue(HKEY_CURRENT_USER, _T("Software\\MONOGRAM\\GraphStudioNext"), g_pszValueName);
			if(!FileExists(sPath))
				sPath.Empty();
		}
		#pragma endregion 
		if(sPath.IsEmpty())
		{
			static const COMDLG_FILTERSPEC g_pFilter[] = 
			{
				{ _T("Executable Files"), _T("*.exe") },
				{ _T("All Files"), _T("*.*") },
			};
			sPath = (LPCTSTR) _CommonDialogHelper::QueryOpenPath(hParentWindow, g_pFilter, _T("exe"), g_pszFileName);
			if(sPath.IsEmpty())
				return FALSE;
			_RegKeyHelper::SetStringValue(HKEY_CURRENT_USER, REGISTRY_ROOT, sValueName, sPath);
		}
		CWaitCursor WaitCursor;
		CString sParameters = AtlFormatString(_T("-a \"%ls\""), pszMonikerDisplayName);
		SHELLEXECUTEINFO Infomation;
		ZeroMemory(&Infomation, sizeof Infomation);
		Infomation.cbSize = sizeof Infomation;
		Infomation.lpFile = sPath;
		Infomation.lpParameters = sParameters;
		Infomation.nShow = SW_SHOWNORMAL;
		__E(ShellExecuteEx(&Infomation));
		return TRUE;
	}
	static BOOL OpenMonikerWithGe(LPCWSTR pszMonikerDisplayName, HWND hParentWindow = GetActiveWindow())
	{
		static const LPCTSTR g_pszValueName = _T("GraphEdit Path");
		static const LPCTSTR g_pszFileName = _T("graphedt.exe");
		const CString sValueName = AtlFormatString(_T("%s (%s)"), g_pszValueName, GetPlatformName());
		CString sPath = _RegKeyHelper::QueryStringValue(HKEY_CURRENT_USER, REGISTRY_ROOT, sValueName);
		if(!FileExists(sPath))
			sPath.Empty();
		#pragma region Current Directory
		if(sPath.IsEmpty())
		{
			sPath = (LPCTSTR) Combine(GetPathDirectory(GetModulePath()), g_pszFileName);
			if(!FileExists(sPath))
				sPath.Empty();
		}
		#pragma endregion 
		// SUGG: Look for Windows SDK
		if(sPath.IsEmpty())
		{
			static const COMDLG_FILTERSPEC g_pFilter[] = 
			{
				{ _T("Executable Files"), _T("*.exe") },
				{ _T("All Files"), _T("*.*") },
			};
			sPath = (LPCTSTR) _CommonDialogHelper::QueryOpenPath(hParentWindow, g_pFilter, _T("exe"), g_pszFileName);
			if(sPath.IsEmpty())
				return FALSE;
			_RegKeyHelper::SetStringValue(HKEY_CURRENT_USER, REGISTRY_ROOT, sValueName, sPath);
		}
		CStringW sFilterGraphMonikerDisplayName = pszMonikerDisplayName;
		const INT nSeparatorPosition = sFilterGraphMonikerDisplayName.Find(L';');
		if(nSeparatorPosition >= 0)
			sFilterGraphMonikerDisplayName = sFilterGraphMonikerDisplayName.Left(nSeparatorPosition);
		CWaitCursor WaitCursor;
		CString sParameters = AtlFormatString(_T("-a %ls"), sFilterGraphMonikerDisplayName);
		SHELLEXECUTEINFO Infomation;
		ZeroMemory(&Infomation, sizeof Infomation);
		Infomation.cbSize = sizeof Infomation;
		Infomation.lpFile = sPath;
		Infomation.lpParameters = sParameters;
		Infomation.nShow = SW_SHOWNORMAL;
		__E(ShellExecuteEx(&Infomation));
		return TRUE;
	}

// IFilterGraphHelper
	STDMETHOD(get_FilterGraph)(IUnknown** ppFilterGraphUnknown) override
	{
		_Z4(atlTraceCOM, 4, _T("...\n"));
		_ATLTRY
		{
			__D(ppFilterGraphUnknown, E_POINTER);
			*ppFilterGraphUnknown = GetFilterGraph().Detach();
		}
		_ATLCATCH(Exception)
		{
			_C(Exception);
		}
		return S_OK;
	}
	STDMETHOD(put_FilterGraph)(IUnknown* pFilterGraphUnknown) override
	{
		_Z4(atlTraceCOM, 4, _T("pFilterGraphUnknown 0x%p\n"), pFilterGraphUnknown);
		_ATLTRY
		{
			if(!SetFilterGraph(pFilterGraphUnknown))
				return S_FALSE;
		}
		_ATLCATCH(Exception)
		{
			_C(Exception);
		}
		return S_OK;
	}
	STDMETHOD(get_Text)(BSTR* psText) override
	{
		_Z4(atlTraceCOM, 4, _T("...\n"));
		_ATLTRY
		{
			__D(psText, E_POINTER);
			CRoCriticalSectionLock DataLock(m_DataCriticalSection);
			*psText = CComBSTR(GetText(m_pFilterGraph)).Detach();
		}
		_ATLCATCH(Exception)
		{
			_C(Exception);
		}
		return S_OK;
	}
	STDMETHOD(DoPropertyFrameModal)(LONG nParentWindowHandle) override
	{
		_Z4(atlTraceCOM, 4, _T("nParentWindowHandle 0x%08X\n"), nParentWindowHandle);
		_ATLTRY
		{
			CWindow ParentWindow = (HWND) (LONG_PTR) nParentWindowHandle;
			if(!ParentWindow)
				ParentWindow = GetActiveWindow();
			//__D(!ParentWindow || ParentWindow.IsWindow(), E_INVALIDARG);
			const CComQIPtr<IFilterGraph2> pFilterGraph2 = GetFilterGraph();
			__D(pFilterGraph2, E_NOINTERFACE);
			CPropertyFrameDialog PropertyFrameDialog(this);
			PropertyFrameDialog.DoModal(ParentWindow);
		}
		_ATLCATCH(Exception)
		{
			_C(Exception);
		}
		return S_OK;
	}
	STDMETHOD(DoFilterGraphListModal)(LONG nParentWindowHandle) override
	{
		_Z4(atlTraceCOM, 4, _T("nParentWindowHandle 0x%08X\n"), nParentWindowHandle);
		_ATLTRY
		{
			CWindow ParentWindow = (HWND) (LONG_PTR) nParentWindowHandle;
			if(!ParentWindow)
				ParentWindow = GetActiveWindow();
			//__D(!ParentWindow || ParentWindow.IsWindow(), E_INVALIDARG);
			DoFilterGraphListPropertySheetModal(ParentWindow, &m_Options);
		}
		_ATLCATCH(Exception)
		{
			_C(Exception);
		}
		return S_OK;
	}
	STDMETHOD(OpenGraphStudioNext)(LONG nParentWindowHandle, BSTR sMonikerDisplayName, VARIANT_BOOL* pbResult) override
	{
		_Z4(atlTraceCOM, 4, _T("nParentWindowHandle 0x%08X, sMonikerDisplayName \"%s\"\n"), nParentWindowHandle, CString(sMonikerDisplayName));
		_ATLTRY
		{
			__D(sMonikerDisplayName && *sMonikerDisplayName, E_INVALIDARG);
			CWindow ParentWindow = (HWND) (LONG_PTR) nParentWindowHandle;
			if(!ParentWindow)
				ParentWindow = GetActiveWindow();
			//__D(!ParentWindow || ParentWindow.IsWindow(), E_INVALIDARG);
			const BOOL bResult = OpenMonikerWithGsn(sMonikerDisplayName, ParentWindow);
			if(pbResult)
				*pbResult = bResult ? ATL_VARIANT_TRUE : ATL_VARIANT_FALSE;
		}
		_ATLCATCH(Exception)
		{
			_C(Exception);
		}
		return S_OK;
	}
	STDMETHOD(OpenGraphEdit)(LONG nParentWindowHandle, BSTR sMonikerDisplayName, VARIANT_BOOL* pbResult) override
	{
		_Z4(atlTraceCOM, 4, _T("nParentWindowHandle 0x%08X, sMonikerDisplayName \"%s\"\n"), nParentWindowHandle, CString(sMonikerDisplayName));
		_ATLTRY
		{
			__D(sMonikerDisplayName && *sMonikerDisplayName, E_INVALIDARG);
			CWindow ParentWindow = (HWND) (LONG_PTR) nParentWindowHandle;
			if(!ParentWindow)
				ParentWindow = GetActiveWindow();
			//__D(!ParentWindow || ParentWindow.IsWindow(), E_INVALIDARG);
			const BOOL bResult = OpenMonikerWithGe(sMonikerDisplayName, ParentWindow);
			if(pbResult)
				*pbResult = bResult ? ATL_VARIANT_TRUE : ATL_VARIANT_FALSE;
		}
		_ATLCATCH(Exception)
		{
			_C(Exception);
		}
		return S_OK;
	}
	STDMETHOD(get_Options)(VARIANT* pvOptions) override
	{
		_Z4(atlTraceCOM, 4, _T("this 0x%p\n"), this);
		_ATLTRY
		{
			__D(pvOptions, E_POINTER);
			VariantInit(pvOptions);
			__C(m_Options.GetVariant().Detach(pvOptions));
		}
		_ATLCATCH(Exception)
		{
			_C(Exception);
		}
		return S_OK;
	}
	STDMETHOD(put_Options)(VARIANT vOptions) override
	{
		_Z4(atlTraceCOM, 4, _T("this 0x%p, vOptions.vt %s\n"), this, reinterpret_cast<CComVariantArray&>(vOptions).FormatType());
		_ATLTRY
		{
			m_Options.SetVariant(vOptions);
		}
		_ATLCATCH(Exception)
		{
			_C(Exception);
		}
		return S_OK;
	}
	STDMETHOD(ResetMediaSampleTrace)(VARIANT vProcessIdentifier) override
	{
		_Z4(atlTraceCOM, 4, _T("this 0x%p, vProcessIdentifier %s\n"), this, reinterpret_cast<CComVariantArray&>(vProcessIdentifier).Format(TRUE));
		_ATLTRY
		{
			DWORD nProcessIdentifier = 0;
			if(vProcessIdentifier.vt > VT_NULL)
				nProcessIdentifier = (DWORD) reinterpret_cast<CComVariantArray&>(vProcessIdentifier).GetAsType(VT_I4).lVal;
			MediaSampleTrace_Reset(nProcessIdentifier);
		}
		_ATLCATCH(Exception)
		{
			_C(Exception);
		}
		return S_OK;
	}
	STDMETHOD(LockMediaSampleTrace)(IUnknown** ppLockUnknown) override
	{
		_Z4(atlTraceCOM, 4, _T("this 0x%p\n"), this);
		_ATLTRY
		{
			__D(ppLockUnknown, E_POINTER);
			*ppLockUnknown = MediaSampleTrace_Lock().Detach();
		}
		_ATLCATCH(Exception)
		{
			_C(Exception);
		}
		return S_OK;
	}
	STDMETHOD(GetMediaSampleTrace)(VARIANT vProcessIdentifier, BSTR* psText) override
	{
		_Z4(atlTraceCOM, 4, _T("this 0x%p, vProcessIdentifier %s\n"), this, reinterpret_cast<CComVariantArray&>(vProcessIdentifier).Format(TRUE));
		_ATLTRY
		{
			__D(psText, E_POINTER);
			DWORD nProcessIdentifier = 0;
			if(vProcessIdentifier.vt > VT_NULL)
				nProcessIdentifier = (DWORD) reinterpret_cast<CComVariantArray&>(vProcessIdentifier).GetAsType(VT_I4).lVal;
			*psText = CComBSTR(MediaSampleTrace_Get(nProcessIdentifier)).Detach();
		}
		_ATLCATCH(Exception)
		{
			_C(Exception);
		}
		return S_OK;
	}
};

OBJECT_ENTRY_AUTO(__uuidof(FilterGraphHelper), CFilterGraphHelper)

inline HRESULT FilterGraphHelper_DoPropertyFrameModal(LONG nParentWindowHandle, IUnknown* pFilterGraphUnknown)
{
	CLocalObjectPtr<CFilterGraphHelper> pFilterGraphHelper;
	pFilterGraphHelper->SetFilterGraph(pFilterGraphUnknown);
	return pFilterGraphHelper->DoPropertyFrameModal(nParentWindowHandle);
}
inline HRESULT FilterGraphHelper_DoFilterGraphListModal(LONG nParentWindowHandle)
{
	CLocalObjectPtr<CFilterGraphHelper> pFilterGraphHelper;
	return pFilterGraphHelper->DoFilterGraphListModal(nParentWindowHandle);
}
inline HRESULT FilterGraphHelper_OpenGraphStudioNext(LONG nParentWindowHandle, LPCWSTR pszMonikerDisplayName, VARIANT_BOOL* pbResult)
{
	CLocalObjectPtr<CFilterGraphHelper> pFilterGraphHelper;
	return pFilterGraphHelper->OpenGraphStudioNext(nParentWindowHandle, CComBSTR(pszMonikerDisplayName), pbResult);
}
inline HRESULT FilterGraphHelper_OpenGraphEdit(LONG nParentWindowHandle, LPCWSTR pszMonikerDisplayName, VARIANT_BOOL* pbResult)
{
	CLocalObjectPtr<CFilterGraphHelper> pFilterGraphHelper;
	return pFilterGraphHelper->OpenGraphEdit(nParentWindowHandle, CComBSTR(pszMonikerDisplayName), pbResult);
}
