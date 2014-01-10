////////////////////////////////////////////////////////////
// Copyright (C) Roman Ryltsov, 2008-2014
// Created by Roman Ryltsov roman@alax.info

#pragma once

#include "rofiles.h"
#include "rodshow.h"
#include "DirectShowSpy_i.h"
#include "Common.h"
#include "AboutDialog.h"
#include "..\..\Repository-Private\Utilities\EmailTools\Message.h"

////////////////////////////////////////////////////////////
// CFilterGraphHelper

class ATL_NO_VTABLE CFilterGraphHelper :
	public CComObjectRootEx<CComMultiThreadModelNoCS>,
	public CComCoClass<CFilterGraphHelper, &__uuidof(FilterGraphHelper)>,
	public IProvideClassInfo2Impl<&__uuidof(FilterGraphHelper), &IID_NULL>,
	public IDispatchImpl<IFilterGraphHelper>
{
public:
	enum { IDR = IDR_FILTERGRAPHHELPER };

//DECLARE_REGISTRY_RESOURCEID(IDR)

BEGIN_COM_MAP(CFilterGraphHelper)
	COM_INTERFACE_ENTRY(IFilterGraphHelper)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(IProvideClassInfo2)
	COM_INTERFACE_ENTRY(IProvideClassInfo)
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
	};

	////////////////////////////////////////////////////////
	// CPropertyFrameDialog

	class CPropertyFrameDialog :
		public CDialogImpl<CPropertyFrameDialog>,
		public CDialogResize<CPropertyFrameDialog>
	{
	public:
		enum { IDD = IDD_FILTERGRAPHHELPER_PROPERTYFRAME };

	BEGIN_MSG_MAP_EX(CPropertyFrameDialog)
		//CHAIN_MSG_MAP(CDialogImpl<CPropertyFrameDialog>)
		CHAIN_MSG_MAP(CDialogResize<CPropertyFrameDialog>)
		MSG_WM_INITDIALOG(OnInitDialog)
		MSG_WM_DESTROY(OnDestroy)
		MSG_TVN_SELCHANGED(IDC_FILTERGRAPHHELPER_PROPERTYFRAME_TREE, OnTreeViewSelChanged)
		MSG_TVN_ITEMEXPANDING(IDC_FILTERGRAPHHELPER_PROPERTYFRAME_TREE, OnTreeViewItemExplanding)
		MSG_TVN_DBLCLK(IDC_FILTERGRAPHHELPER_PROPERTYFRAME_TREE, OnTreeViewDblClk)
		MSG_WM_SYSCOMMAND(OnSysCommand)
		COMMAND_ID_HANDLER_EX(IDOK, OnOk)
		COMMAND_ID_HANDLER_EX(IDCANCEL, OnCancel)
		COMMAND_ID_HANDLER_EX(IDC_FILTERGRAPHHELPER_PROPERTYFRAME_APPLY, OnApply)
		REFLECT_NOTIFICATIONS()
	END_MSG_MAP()

	BEGIN_DLGRESIZE_MAP(CPropertyFrameDialog)
		DLGRESIZE_CONTROL(IDC_FILTERGRAPHHELPER_PROPERTYFRAME_TREE, DLSZ_SIZE_Y)
		DLGRESIZE_CONTROL(IDC_FILTERGRAPHHELPER_PROPERTYFRAME_TEXT, DLSZ_SIZE_X | DLSZ_SIZE_Y)
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
			REFLECT_NOTIFICATIONS()
		END_MSG_MAP()

		BEGIN_DLGRESIZE_MAP(CEmailDialog)
			DLGRESIZE_CONTROL(IDC_FILTERGRAPHHELPER_EMAIL_BODY, DLSZ_SIZE_X | DLSZ_SIZE_Y)
			DLGRESIZE_CONTROL(IDC_FILTERGRAPHHELPER_EMAIL_SEND, DLSZ_MOVE_X | DLSZ_MOVE_Y)
		END_DLGRESIZE_MAP()

		private:
			CPropertyFrameDialog* m_pOwner;
			BOOL m_bActivating;
			CStatic m_TitleStatic;
			CFont m_TitleFont;
			CRoEdit m_FromEdit;
			CRoEdit m_ToEdit;
			CRoComboBoxT<> m_MethodComboBox;
			CRoEdit m_HostEdit;
			CRoEdit m_UsernameEdit;
			CRoEdit m_PasswordEdit;
			CRoEdit m_BodyEdit;
			CButton m_SendButton;
			CString m_sFilterGraphText;
			CRoMapT<INT_PTR, BOOL> m_ChangeMap;

		public:
		// CEmailDialog
			VOID InitializeControlsFromRegistry()
			{
				CRegKey Key;
				Key.Open(HKEY_CURRENT_USER, REGISTRY_ROOT, KEY_READ);
				if(!Key)
					return;
				CString sMessageString = _RegKeyHelper::QueryStringValue(Key, _T("Email Message Template"));
				if(sMessageString.IsEmpty())
					return;
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
				}
			}
			VOID InitializeBody()
			{
				CString sText;
				sText += _T("(add notes here)") _T("\r\n") _T("\r\n");
				sText += _T("* * *") _T("\r\n") _T("\r\n");
				#define I FormatIdentifier
				#pragma region System
				{
					sText += _T("# System") _T("\r\n") _T("\r\n");
					OSVERSIONINFOEX Version;
					ZeroMemory(&Version, sizeof Version);
					Version.dwOSVersionInfoSize = sizeof Version;
					GetVersionEx((OSVERSIONINFO*) &Version);
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
					TCHAR pszComputerName[256] = { 0 };
					DWORD nComputerNameLength = DIM(pszComputerName);
					GetComputerName(pszComputerName, &nComputerNameLength);
					sText += AtlFormatString(_T(" * ") _T("Computer Name: %s") _T("\r\n"), I(pszComputerName));
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
					sText += AtlFormatString(_T(" * ") _T("Processors: %s, Active Mask %s") _T("\r\n"), I(SystemInformation.dwNumberOfProcessors), I(SystemInformation.dwActiveProcessorMask, _T("0x%X")));
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

		// Window Message Handler
			LRESULT OnInitDialog(HWND, LPARAM lParam)
			{
				m_pOwner = (CPropertyFrameDialog*) lParam;
				m_bActivating = TRUE;
				_ATLTRY
				{
					CWaitCursor WaitCursor;
					m_TitleStatic = GetDlgItem(IDC_FILTERGRAPHHELPER_EMAIL_TITLE);
					CLogFont LogFont;
					LogFont.SetHeight(12, CClientDC(m_hWnd));
					LogFont.lfWeight = FW_BOLD;
					_tcsncpy_s(LogFont.lfFaceName, _T("Verdana"), _TRUNCATE);
					_W(m_TitleFont.CreateFontIndirect(&LogFont));
					m_TitleStatic.SetFont(m_TitleFont);
					m_FromEdit = GetDlgItem(IDC_FILTERGRAPHHELPER_EMAIL_FROM);
					m_ToEdit = GetDlgItem(IDC_FILTERGRAPHHELPER_EMAIL_TO);
					m_MethodComboBox.Initialize(GetDlgItem(IDC_FILTERGRAPHHELPER_EMAIL_METHOD));
					m_MethodComboBox.SetCurSel(0);
					m_HostEdit = GetDlgItem(IDC_FILTERGRAPHHELPER_EMAIL_HOST);
					m_UsernameEdit = GetDlgItem(IDC_FILTERGRAPHHELPER_EMAIL_USERNAME);
					m_PasswordEdit = GetDlgItem(IDC_FILTERGRAPHHELPER_EMAIL_PASSWORD);
					m_BodyEdit = GetDlgItem(IDC_FILTERGRAPHHELPER_EMAIL_BODY);
					m_BodyEdit.SetFont(m_pOwner->m_TextFont);
					m_SendButton = GetDlgItem(IDC_FILTERGRAPHHELPER_EMAIL_SEND);
					DlgResize_Init(TRUE);
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
				CString sSubject = AtlFormatString(_T("DirectShow Filter Graph by %s"), AtlLoadString(IDS_PROJNAME));
				__C(pMessage->put_Subject(CComBSTR(sSubject)));
				__C(pMessage->Send());
				MessageBeep(MB_OK);
				_RegKeyHelper::SetStringValue(HKEY_CURRENT_USER, REGISTRY_ROOT, _T("Email Message Template"), CString(sMessageString));
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
				TYPE_EMAIL,
			} TYPE;

		public:
			TYPE m_Type;
			CComPtr<IBaseFilter> m_pBaseFilter;
			CLSID m_ClassIdentifier;
			CComPtr<IPropertyPage> m_pPropertyPage;
			CObjectPtr<CPropertyPageSite> m_pSite;
			BOOL m_bSiteActivated;

		public:
		// CData
			CData(TYPE Type = TYPE_UNKNOWN) :
				m_Type(Type),
				m_ClassIdentifier(CLSID_NULL)
			{
			}
			CData(IBaseFilter* pBaseFilter) :
				m_Type(TYPE_FILTER),
				m_pBaseFilter(pBaseFilter),
				m_ClassIdentifier(CLSID_NULL)
			{
			}
			CData(IBaseFilter* pBaseFilter, const CLSID& ClassIdentifier, IPropertyPage* pPropertyPage) :
				m_Type(TYPE_FILTERPROPERTYPAGE),
				m_pBaseFilter(pBaseFilter),
				m_ClassIdentifier(ClassIdentifier),
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

	private:
		CFilterGraphHelper& m_Owner;
		BOOL m_bActivating; 
		CRoTreeViewT<CData, CRoListControlDataTraitsT> m_TreeView;
		CTreeItem m_FiltersItem;
		CTreeItem m_EmailItem;
		CTabCtrl m_Tab;
		CRoEdit m_TextEdit;
		CRect m_TextPosition;
		CFont m_TextFont;
		CButton m_OkButton;
		CButton m_CancelButton;
		CButton m_ApplyButton;
		CObjectPtr<CPropertyPageSite> m_pCurrentSite;
		CEmailDialog m_EmailDialog;

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
			#pragma region Filter
			CTreeItem FiltersItem = m_TreeView.InsertItem(NULL, NULL, CData(CData::TYPE_FILTERS), _T("Filters"));
			_FilterGraphHelper::CFilterArray FilterArray;
			_FilterGraphHelper::GetGraphFilters(m_Owner.m_pFilterGraph, FilterArray);
			CTreeItem PreviousFilterItem;
			for(SIZE_T nIndex = 0; nIndex < FilterArray.GetCount(); nIndex++)
			{
				const CComPtr<IBaseFilter>& pBaseFilter = FilterArray[nIndex];
				CTreeItem FilterItem = m_TreeView.InsertItem(FiltersItem, PreviousFilterItem, CData(pBaseFilter), CString(_FilterGraphHelper::GetFilterName(pBaseFilter)));
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
							continue;
						_ATLTRY
						{
							CComPtr<IPropertyPage> pPropertyPage;
							__C(pPropertyPage.CoCreateInstance(ClassIdentifier));
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
			#pragma endregion
			CTreeItem EmailItem = m_TreeView.InsertItem(NULL, FiltersItem, CData(CData::TYPE_EMAIL), _T("Email"));
			m_EmailItem.m_hTreeItem = EmailItem;
			m_EmailItem.m_pTreeView = &m_TreeView;
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

	// CDialogResize
		VOID DlgResize_UpdateLayout(INT nWidth, INT nHeight)
		{
			__super::DlgResize_UpdateLayout(nWidth, nHeight);
			if(m_pCurrentSite && m_pCurrentSite->m_pPropertyPage)
				_V(m_pCurrentSite->m_pPropertyPage->Move(GetTextEditPosition()));
		}

	// Window Message Handler
		LRESULT OnInitDialog(HWND, LPARAM)
		{
			m_bActivating = TRUE;
			_ATLTRY
			{
				CWaitCursor WaitCursor;
				#pragma region Bitness Indication
				CString sCaption;
				_W(GetWindowText(sCaption));
				#if defined(_WIN64)
					sCaption.Append(_T(" (64-bit)"));
				#else
					if(SafeIsWow64Process())
						sCaption.Append(_T(" (32-bit)"));
				#endif // defined(_WIN64)
				_W(SetWindowText(sCaption));
				#pragma endregion
				#pragma region System Menu
				CMenuHandle Menu = GetSystemMenu(FALSE);
				_W(Menu.AppendMenu(MF_SEPARATOR));
				_W(Menu.AppendMenu(MF_STRING, ID_APP_ABOUT, _T("&About...")));
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
				m_OkButton = GetDlgItem(IDOK);
				m_CancelButton = GetDlgItem(IDCANCEL);
				m_ApplyButton = GetDlgItem(IDC_FILTERGRAPHHELPER_PROPERTYFRAME_APPLY);
				__E(m_EmailDialog.Create(m_hWnd, (LPARAM) this));
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
		LRESULT OnTreeViewSelChanged(NMTREEVIEW* pHeader)
		{
			_A(pHeader);
			CTreeItem TreeItem(pHeader->itemNew.hItem);
			if(TreeItem)
			{
				CData& Data = m_TreeView.GetItemData(TreeItem);
				if(Data.m_Type != CData::TYPE_EMAIL)
					m_EmailDialog.ShowWindow(SW_HIDE);
				#pragma endregion
				if(Data.m_pBaseFilter)
				{
					if(Data.m_pPropertyPage)
					{
						m_TextEdit.ShowWindow(SW_HIDE);
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
					{
						CWaitCursor WaitCursor;
						HideCurrentSite();
						m_TextEdit.ShowWindow(SW_SHOW);
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
								sText += AtlFormatString(_T("%d. ") _T("%s") _T("\r\n"), nPinIndex, sPinText);
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
						m_TextEdit.SetValue(sText);
						m_ApplyButton.EnableWindow(FALSE);
					}
				} else
				{
					CWaitCursor WaitCursor;
					HideCurrentSite();
					switch(Data.m_Type)
					{
					#pragma region TYPE_EMAIL
					case CData::TYPE_EMAIL:
						m_TextEdit.ShowWindow(SW_HIDE);
						_W(m_EmailDialog.SetWindowPos(NULL, GetTextEditPosition(), SWP_NOZORDER | SWP_SHOWWINDOW));
						break;
					#pragma endregion
					default:
						m_TextEdit.ShowWindow(SW_SHOW);
						m_TextEdit.SetValue(m_Owner.GetText());
						m_EmailDialog.ShowWindow(SW_HIDE);
					}
					m_ApplyButton.EnableWindow(FALSE);
				}
			} else
			{
				HideCurrentSite();
				m_TextEdit.ShowWindow(SW_HIDE);
				m_EmailDialog.ShowWindow(SW_HIDE);
				m_ApplyButton.EnableWindow(FALSE);
			}
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
	};

private:
	mutable CRoCriticalSection m_DataCriticalSection;
	CComPtr<IFilterGraph> m_pFilterGraph;

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
		_Z4(atlTraceRefcount, 4, _T("this 0x%p\n"), this);
	}
	~CFilterGraphHelper()
	{
		_Z4(atlTraceRefcount, 4, _T("this 0x%p\n"), this);
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
	static CString GetFilterText(IBaseFilter* pBaseFilter, IReferenceClock* pFilterGraphReferenceClock = NULL)
	{
		CString sText;
		const CStringW sClassIdentifierString = _FilterGraphHelper::GetFilterClassIdentifierString(pBaseFilter);
		if(!sClassIdentifierString.IsEmpty())
			sText += AtlFormatString(_T(" * ") _T("Class: %s %s") _T("\r\n"), I(sClassIdentifierString), I(_FilterGraphHelper::GetFilterClassDescription(pBaseFilter)));
		_FilterGraphHelper::CPinArray InputPinArray;
		if(_FilterGraphHelper::GetFilterPins(pBaseFilter, PINDIR_INPUT, InputPinArray))
			sText += AtlFormatString(_T(" * ") _T("Input Pins: %s") _T("\r\n"), FormatPins(InputPinArray));
		_FilterGraphHelper::CPinArray OutputPinArray;
		if(_FilterGraphHelper::GetFilterPins(pBaseFilter, PINDIR_OUTPUT, OutputPinArray))
			sText += AtlFormatString(_T(" * ") _T("Output Pins: %s") _T("\r\n"), FormatPins(OutputPinArray));
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
				Array.Add(I(sSubtype));
				#pragma region MEDIATYPE_Video
				if(pMediaType->majortype == MEDIATYPE_Video)
				{
					const CVideoInfoHeader2 VideoInfoHeader2 = pMediaType.GetCompatibleVideoInfoHeader2();
					const CSize Extent = VideoInfoHeader2.GetExtent();
					if(Extent.cx || Extent.cy)
						Array.Add(AtlFormatString(_T("%s x %s"), I(Extent.cx), I(Extent.cy)));
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
		} else
		#pragma endregion 
		#pragma region FORMAT_VideoInfo2
		if(pMediaType->formattype == FORMAT_VideoInfo2)
		{
			sText += AtlFormatString(_T(" * ") _T("As `VIDEOINFOHEADER2`:") _T("\r\n"));
			const VIDEOINFOHEADER2* pVideoInfoHeader2 = (const VIDEOINFOHEADER2*) pMediaType->pbFormat;
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
		} else
		#pragma endregion 
		#pragma region FORMAT_MPEG2Video
		if(pMediaType->formattype == FORMAT_MPEG2Video)
		{
			sText += AtlFormatString(_T(" * ") _T("As `MPEG2VIDEOINFO`:") _T("\r\n"));
			const MPEG2VIDEOINFO* pMpeg2VideoInfo = (const MPEG2VIDEOINFO*) pMediaType->pbFormat;
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
			nExtraDataSize = pMediaType->cbFormat - (sizeof *pMpeg2VideoInfo - sizeof pMpeg2VideoInfo->dwSequenceHeader);
		} else
		#pragma endregion 
		#pragma region FORMAT_WaveFormatEx
		if(pMediaType->formattype == FORMAT_WaveFormatEx)
		{
			const WAVEFORMATEX* pWaveFormatEx = (const WAVEFORMATEX*) pMediaType->pbFormat;
			if(pWaveFormatEx->wFormatTag == WAVE_FORMAT_EXTENSIBLE)
			{
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
		#pragma endregion 
		#pragma region Extra Data
		if(nExtraDataSize)
		{
			if(!pnExtraData)
				pnExtraData = pMediaType->pbFormat + pMediaType->cbFormat - nExtraDataSize;
			sText += AtlFormatString(_T("  * ") _T("Extra Data: %s") _T("\r\n"), I(AtlFormatData(pnExtraData, nExtraDataSize).TrimRight()));
		}
		#pragma endregion 
		return sText;
	}
	static CString GetText(IFilterGraph* pFilterGraph, const CProcessData* pProcessData = NULL)
	{
		if(!pFilterGraph)
			return (LPCTSTR) NULL;
		CString sText;
		sText += AtlFormatString(_T("# ") _T("Filter Graph") _T("\r\n") _T("\r\n"));
		#pragma region Graph Parameters
		if(pProcessData)
			sText += AtlFormatString(_T("* ") _T("Process: %s (%s) %s") _T("\r\n"), I(pProcessData->m_nIdentifier), I(pProcessData->m_nIdentifier, _T("0x%X")), I(FindFileName(pProcessData->m_sImagePath)));
		#pragma region IMediaControl
		const CComQIPtr<IMediaControl> pMediaControl = pFilterGraph;
		if(pMediaControl)
			_ATLTRY
			{
				OAFilterState State;
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
			const CString sDirectory = (LPCTSTR) GetPathDirectory(pProcessData->m_sImagePath);
			if(!sDirectory.IsEmpty())
				sText += AtlFormatString(_T("* ") _T("Process Directory: %s") _T("\r\n"), I(sDirectory));
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
					sText += GetFilterText(pBaseFilter, pFilterGraphReferenceClock);
				}
				_ATLCATCHALL()
				{
					_Z_EXCEPTION();
				}
			sText += _T("\r\n");
			#pragma region Connection
			sText += AtlFormatString(_T("## ") _T("Connections") _T("\r\n") _T("\r\n"));
			INT nConnectionIndex = 0;
			for(SIZE_T nFilterIndex = 0; nFilterIndex < FilterArray.GetCount(); nFilterIndex++)
			{
				const CComPtr<IBaseFilter>& pBaseFilter = FilterArray[nFilterIndex];
				_FilterGraphHelper::CPinArray PinArray;
				_FilterGraphHelper::GetFilterPins(pBaseFilter, PINDIR_OUTPUT, PinArray);
				for(SIZE_T nPinIndex = 0; nPinIndex < PinArray.GetCount(); nPinIndex++)
				{
					const CComPtr<IPin>& pOutputPin = PinArray[nPinIndex];
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
	VOID SetFilterGraph(IFilterGraph* pFilterGraph) 
	{
		CRoCriticalSectionLock DataLock(m_DataCriticalSection);
		m_pFilterGraph = pFilterGraph;
	}
	BOOL SetFilterGraph(IUnknown* pFilterGraphUnknown) 
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
		CRoCriticalSectionLock DataLock(m_DataCriticalSection);
		m_pFilterGraph = pFilterGraph;
		return m_pFilterGraph != NULL;
	}
	CString GetText() const
	{
		CRoCriticalSectionLock DataLock(m_DataCriticalSection);
		return GetText(m_pFilterGraph);
	}

// IFilterGraphHelper
	STDMETHOD(get_FilterGraph)(IUnknown** ppFilterGraphUnknown)
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
	STDMETHOD(put_FilterGraph)(IUnknown* pFilterGraphUnknown)
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
	STDMETHOD(get_Text)(BSTR* psText)
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
	STDMETHOD(DoPropertyFrameModal)(LONG nParentWindowHandle)
	{
		_Z4(atlTraceCOM, 4, _T("...\n"));
		_ATLTRY
		{
			CWindow ParentWindow = (HWND) (LONG_PTR) nParentWindowHandle;
			if(!ParentWindow)
				ParentWindow = GetActiveWindow();
			__D(!ParentWindow || ParentWindow.IsWindow(), E_INVALIDARG);
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
};

OBJECT_ENTRY_AUTO(__uuidof(FilterGraphHelper), CFilterGraphHelper)
