////////////////////////////////////////////////////////////
// Copyright (C) Roman Ryltsov, 2008-2011
// Created by Roman Ryltsov roman@alax.info
// 
// $Id$

#pragma once

#include <atlctrlx.h>
#include <atlsplit.h>
#include "rofiles.h"
#include "AboutDialog.h"

////////////////////////////////////////////////////////////
// CRegistrationPropertySheet

class CRegistrationPropertySheet :
	public CPropertySheetT<CRegistrationPropertySheet>
{
public:

BEGIN_MSG_MAP_EX(CRegistrationPropertySheet)
	CHAIN_MSG_MAP(CPropertySheet)
	MSG_WM_SYSCOMMAND(OnSysCommand)
END_MSG_MAP()

public:

	////////////////////////////////////////////////////////
	// CRegistrationPropertyPage

	class CRegistrationPropertyPage :
		public CPropertyPageT<CRegistrationPropertyPage>,
		//public CDialogResize<CRegistrationPropertyPage>,
		public CWindowWithPrivateMessagesT<CRegistrationPropertyPage>
	{
	public:
		enum { IDD = IDD_REGISTRATION_REGISTRATION_PROPERTYPAGE };

	BEGIN_MSG_MAP_EX(CRegistrationPropertyPage)
		CHAIN_MSG_MAP(CPropertyPage)
		//CHAIN_MSG_MAP(CDialogResize<CRegistrationPropertyPage>)
		CHAIN_MSG_MAP(CWindowWithPrivateMessages)
		MSG_WM_INITDIALOG(OnInitDialog)
		COMMAND_ID_HANDLER_EX(IDC_REGISTRATION_REGISTRATION_REGISTER, OnRegister)
		COMMAND_ID_HANDLER_EX(IDC_REGISTRATION_REGISTRATION_UNREGISTER, OnUnregister)
		COMMAND_ID_HANDLER_EX(IDC_REGISTRATION_REGISTRATION_USERREGISTER, OnUserRegister)
		COMMAND_ID_HANDLER_EX(IDC_REGISTRATION_REGISTRATION_USERUNREGISTER, OnUserUnregister)
		REFLECT_NOTIFICATIONS()
	END_MSG_MAP()

	private:
		CRegistrationPropertySheet& m_PropertySheet;
		CRoEdit m_StatusEdit;
		CRoEdit m_PathEdit;
		CButton m_RegisterButton;
		CButton m_UnregisterButton;
		CRoEdit m_UserStatusEdit;
		CRoEdit m_UserPathEdit;
		CButton m_UserRegisterButton;
		CButton m_UserUnregisterButton;
		//CRoIconStatic m_UserNoteStatic;
		CRoArrayT<CString> m_StatusArray;
		CPath m_sPath;
		CPath m_sUserPath;

		static BOOL IsAdministrator()
		{
			bool bIsMember = FALSE;
			return CAccessToken().CheckTokenMembership(Sids::Admins(), &bIsMember) && bIsMember;
		}

	public:
	// CRegistrationPropertyPage
		CRegistrationPropertyPage(CRegistrationPropertySheet* pPropertySheet) throw() :
			m_PropertySheet(*pPropertySheet)
		{
		}
		VOID UpdateControls()
		{
			_A(_pAtlModule);
			#pragma region System
			CPath sPath = FindTypeLibraryPath(HKEY_LOCAL_MACHINE);
			const BOOL bPathEmpty = _tcslen(sPath) == 0;
			m_StatusEdit.SetValue(m_StatusArray[bPathEmpty ? 0 : 1]);
			m_PathEdit.SetValue(sPath);
			m_PathEdit.GetWindow(GW_HWNDPREV).EnableWindow(!bPathEmpty);
			m_PathEdit.EnableWindow(!bPathEmpty);
			m_RegisterButton.EnableWindow(bPathEmpty);
			m_UnregisterButton.EnableWindow(!bPathEmpty);
			m_sPath = sPath;
			#pragma endregion 
			#pragma region Per-User
			CPath sUserPath = FindTypeLibraryPath(HKEY_CURRENT_USER);
			const BOOL bUserPathEmpty = _tcslen(sUserPath) == 0;
			m_UserStatusEdit.SetValue(m_StatusArray[bUserPathEmpty ? 0 : 1]);
			m_UserPathEdit.SetValue(sUserPath);
			m_UserPathEdit.GetWindow(GW_HWNDPREV).EnableWindow(!bUserPathEmpty);
			m_UserPathEdit.EnableWindow(!bUserPathEmpty);
			m_UserRegisterButton.EnableWindow(bUserPathEmpty);
			m_UserUnregisterButton.EnableWindow(!bUserPathEmpty);
			m_sUserPath = sUserPath;
			#pragma endregion 
		}

	// CDialogResize				
			
	// Window message handlers
		LRESULT OnInitDialog(HWND, LPARAM)
		{
			_ATLTRY
			{
				CWaitCursor WaitCursor;
				m_StatusEdit = GetDlgItem(IDC_REGISTRATION_REGISTRATION_STATUS);
				m_PathEdit = GetDlgItem(IDC_REGISTRATION_REGISTRATION_PATH);
				m_RegisterButton = GetDlgItem(IDC_REGISTRATION_REGISTRATION_REGISTER);
				m_UnregisterButton = GetDlgItem(IDC_REGISTRATION_REGISTRATION_UNREGISTER);
				m_UserStatusEdit = GetDlgItem(IDC_REGISTRATION_REGISTRATION_USERSTATUS);
				m_UserPathEdit = GetDlgItem(IDC_REGISTRATION_REGISTRATION_USERPATH);
				m_UserRegisterButton = GetDlgItem(IDC_REGISTRATION_REGISTRATION_USERREGISTER);
				m_UserUnregisterButton = GetDlgItem(IDC_REGISTRATION_REGISTRATION_USERUNREGISTER);
				//_W(m_UserNoteStatic.SubclassWindow(GetDlgItem(IDC_REGISTRATION_REGISTRATION_USERNOTE)));
				//m_UserNoteStatic.SetIdealHeight();
				if(GetOsVersion() >= 0x00060000) // Windows Vista or Windows Server 2008
				{
					if(!IsAdministrator())
					{
						m_RegisterButton.SetElevationRequiredState(TRUE);
						m_UnregisterButton.SetElevationRequiredState(TRUE);
					}
				}
				_StringHelper::GetCommaSeparatedItems(AtlLoadString(IDC_REGISTRATION_REGISTRATION_STATUS), m_StatusArray);
				_A(m_StatusArray.GetCount() == 2);
				UpdateControls();
			}
			_ATLCATCHALL()
			{
				for(CWindow Window = GetWindow(GW_CHILD); Window.IsWindow(); Window = Window.GetWindow(GW_HWNDNEXT))
					Window.EnableWindow(FALSE);
				_ATLRETHROW;
			}
			return TRUE;
		}
		LRESULT OnDestroy()
		{
			return 0;
		}
		INT OnSetActive() throw()
		{
			_ATLTRY
			{
				CWaitCursor WaitCursor;
				UpdateControls();
			}
			_ATLCATCHALL()
			{
				_Z_EXCEPTION();
				return -1;
			}
			return 0;
		}
		LRESULT OnRegister(UINT, INT, HWND)
		{
			_ATLTRY
			{
				CWaitCursor WaitCursor;
				const BOOL bSilent = !(GetKeyState(VK_SCROLL) & 1);
				const DWORD nExitCode = ExecuteWait(AtlFormatString(_T("%s \"%s\""), bSilent ? _T("/s") : _T(""), GetPath()), TRUE);
				if(bSilent)
					MessageBeep(nExitCode ? MB_ICONERROR : MB_OK);
			}
			_ATLCATCH(Exception)
			{
				AtlExceptionMessageBox(m_hWnd, Exception);
			}
			UpdateControls();
			return 0;
		}
		LRESULT OnUnregister(UINT, INT, HWND)
		{
			_ATLTRY
			{
				CWaitCursor WaitCursor;
				const BOOL bSilent = !(GetKeyState(VK_SCROLL) & 1);
				const DWORD nExitCode = ExecuteWait(AtlFormatString(_T("%s /u \"%s\""), bSilent ? _T("/s") : _T(""), GetPath()), TRUE);
				if(bSilent)
					MessageBeep(nExitCode ? MB_ICONERROR : MB_OK);
			}
			_ATLCATCH(Exception)
			{
				AtlExceptionMessageBox(m_hWnd, Exception);
			}
			UpdateControls();
			return 0;
		}
		LRESULT OnUserRegister(UINT, INT, HWND)
		{
			_ATLTRY
			{
				CWaitCursor WaitCursor;
				const BOOL bSilent = !(GetKeyState(VK_SCROLL) & 1);
				const DWORD nExitCode = ExecuteWait(AtlFormatString(_T("%s /i:user /n \"%s\""), bSilent ? _T("/s") : _T(""), GetPath()));
				if(bSilent)
					MessageBeep(nExitCode ? MB_ICONERROR : MB_OK);
			}
			_ATLCATCH(Exception)
			{
				AtlExceptionMessageBox(m_hWnd, Exception);
			}
			UpdateControls();
			return 0;
		}
		LRESULT OnUserUnregister(UINT, INT, HWND)
		{
			_ATLTRY
			{
				CWaitCursor WaitCursor;
				const BOOL bSilent = !(GetKeyState(VK_SCROLL) & 1);
				const DWORD nExitCode = ExecuteWait(AtlFormatString(_T("%s /i:user /n /u \"%s\""), bSilent ? _T("/s") : _T(""), GetPath()));
				if(bSilent)
					MessageBeep(nExitCode ? MB_ICONERROR : MB_OK);
			}
			_ATLCATCH(Exception)
			{
				AtlExceptionMessageBox(m_hWnd, Exception);
			}
			UpdateControls();
			return 0;
		}
	};

	////////////////////////////////////////////////////////
	// CProppageRegistrationPropertyPage

	class CProppageRegistrationPropertyPage :
		public CPropertyPageT<CProppageRegistrationPropertyPage>,
		//public CDialogResize<CProppageRegistrationPropertyPage>,
		public CWindowWithPrivateMessagesT<CProppageRegistrationPropertyPage>
	{
	public:
		enum { IDD = IDD_REGISTRATION_PROPPAGEREGISTRATION_PROPERTYPAGE };

	BEGIN_MSG_MAP_EX(CProppageRegistrationPropertyPage)
		CHAIN_MSG_MAP(CPropertyPage)
		//CHAIN_MSG_MAP(CDialogResize<CProppageRegistrationPropertyPage>)
		CHAIN_MSG_MAP(CWindowWithPrivateMessages)
		MSG_WM_INITDIALOG(OnInitDialog)
		COMMAND_ID_HANDLER_EX(IDC_REGISTRATION_PROPPAGEREGISTRATION_REGISTER, OnRegister)
		COMMAND_ID_HANDLER_EX(IDC_REGISTRATION_PROPPAGEREGISTRATION_UNREGISTER, OnUnregister)
		COMMAND_ID_HANDLER_EX(IDC_REGISTRATION_PROPPAGEREGISTRATION_USERREGISTER, OnUserRegister)
		COMMAND_ID_HANDLER_EX(IDC_REGISTRATION_PROPPAGEREGISTRATION_USERUNREGISTER, OnUserUnregister)
		REFLECT_NOTIFICATIONS()
	END_MSG_MAP()

	private:
		CRegistrationPropertySheet& m_PropertySheet;
		CRoEdit m_StatusEdit;
		CRoEdit m_PathEdit;
		CButton m_RegisterButton;
		CButton m_UnregisterButton;
		CRoEdit m_UserStatusEdit;
		CRoEdit m_UserPathEdit;
		CButton m_UserRegisterButton;
		CButton m_UserUnregisterButton;
		//CRoIconStatic m_UserNoteStatic;
		CRoArrayT<CString> m_StatusArray;
		CPath m_sPath;
		CPath m_sUserPath;

		static BOOL IsAdministrator()
		{
			bool bIsMember = FALSE;
			return CAccessToken().CheckTokenMembership(Sids::Admins(), &bIsMember) && bIsMember;
		}

	public:
	// CProppageRegistrationPropertyPage
		CProppageRegistrationPropertyPage(CRegistrationPropertySheet* pPropertySheet) throw() :
			m_PropertySheet(*pPropertySheet)
		{
		}
		VOID UpdateControls()
		{
			class __declspec(uuid("92A3A302-DA7C-4A1F-BA7E-1802BB5D2D02")) PSFactoryBuffer;
			_A(_pAtlModule);
			#pragma region System
			//CPath sUserPath = FindTypeLibraryPath(HKEY_LOCAL_MACHINE);
			CPath sPath = FindClassPath(HKEY_LOCAL_MACHINE, __uuidof(PSFactoryBuffer));
			const BOOL bPathEmpty = _tcslen(sPath) == 0;
			m_StatusEdit.SetValue(m_StatusArray[bPathEmpty ? 0 : 1]);
			m_PathEdit.SetValue(sPath);
			m_PathEdit.GetWindow(GW_HWNDPREV).EnableWindow(!bPathEmpty);
			m_PathEdit.EnableWindow(!bPathEmpty);
			m_RegisterButton.EnableWindow(bPathEmpty);
			m_UnregisterButton.EnableWindow(!bPathEmpty);
			m_sPath = sPath;
			#pragma endregion 
			#pragma region Per-User
			//CPath sUserPath = FindTypeLibraryPath(HKEY_CURRENT_USER);
			//const BOOL bUserPathEmpty = _tcslen(sUserPath) == 0;
			//m_UserStatusEdit.SetValue(m_StatusArray[bUserPathEmpty ? 0 : 1]);
			//m_UserPathEdit.SetValue(sUserPath);
			//m_UserPathEdit.GetWindow(GW_HWNDPREV).EnableWindow(!bUserPathEmpty);
			//m_UserPathEdit.EnableWindow(!bUserPathEmpty);
			//m_UserRegisterButton.EnableWindow(bUserPathEmpty);
			//m_UserUnregisterButton.EnableWindow(!bUserPathEmpty);
			//m_sUserPath = sUserPath;
			#pragma endregion 
		}

	// CDialogResize				
			
	// Window message handlers
		LRESULT OnInitDialog(HWND, LPARAM)
		{
			_ATLTRY
			{
				CWaitCursor WaitCursor;
				m_StatusEdit = GetDlgItem(IDC_REGISTRATION_PROPPAGEREGISTRATION_STATUS);
				m_PathEdit = GetDlgItem(IDC_REGISTRATION_PROPPAGEREGISTRATION_PATH);
				m_RegisterButton = GetDlgItem(IDC_REGISTRATION_PROPPAGEREGISTRATION_REGISTER);
				m_UnregisterButton = GetDlgItem(IDC_REGISTRATION_PROPPAGEREGISTRATION_UNREGISTER);
				m_UserStatusEdit = GetDlgItem(IDC_REGISTRATION_PROPPAGEREGISTRATION_USERSTATUS);
				m_UserPathEdit = GetDlgItem(IDC_REGISTRATION_PROPPAGEREGISTRATION_USERPATH);
				m_UserRegisterButton = GetDlgItem(IDC_REGISTRATION_PROPPAGEREGISTRATION_USERREGISTER);
				m_UserUnregisterButton = GetDlgItem(IDC_REGISTRATION_PROPPAGEREGISTRATION_USERUNREGISTER);
				//_W(m_UserNoteStatic.SubclassWindow(GetDlgItem(IDC_REGISTRATION_PROPPAGEREGISTRATION_USERNOTE)));
				//m_UserNoteStatic.SetIdealHeight();
				if(GetOsVersion() >= 0x00060000) // Windows Vista or Windows Server 2008
				{
					if(!IsAdministrator())
					{
						m_RegisterButton.SetElevationRequiredState(TRUE);
						m_UnregisterButton.SetElevationRequiredState(TRUE);
					}
				}
				_StringHelper::GetCommaSeparatedItems(AtlLoadString(IDC_REGISTRATION_PROPPAGEREGISTRATION_STATUS), m_StatusArray);
				_A(m_StatusArray.GetCount() == 2);
				UpdateControls();
			}
			_ATLCATCHALL()
			{
				for(CWindow Window = GetWindow(GW_CHILD); Window.IsWindow(); Window = Window.GetWindow(GW_HWNDNEXT))
					Window.EnableWindow(FALSE);
				_ATLRETHROW;
			}
			return TRUE;
		}
		LRESULT OnDestroy()
		{
			return 0;
		}
		INT OnSetActive() throw()
		{
			_ATLTRY
			{
				CWaitCursor WaitCursor;
				UpdateControls();
			}
			_ATLCATCHALL()
			{
				_Z_EXCEPTION();
				return -1;
			}
			return 0;
		}
		LRESULT OnRegister(UINT, INT, HWND)
		{
			_ATLTRY
			{
				CWaitCursor WaitCursor;
				const BOOL bSilent = !(GetKeyState(VK_SCROLL) & 1);
				const DWORD nExitCode = ExecuteWait(AtlFormatString(_T("%s \"%s\""), bSilent ? _T("/s") : _T(""), m_PropertySheet.m_sPropPagePath), TRUE);
				if(bSilent)
					MessageBeep(nExitCode ? MB_ICONERROR : MB_OK);
			}
			_ATLCATCH(Exception)
			{
				AtlExceptionMessageBox(m_hWnd, Exception);
			}
			UpdateControls();
			return 0;
		}
		LRESULT OnUnregister(UINT, INT, HWND)
		{
			_ATLTRY
			{
				CWaitCursor WaitCursor;
				const BOOL bSilent = !(GetKeyState(VK_SCROLL) & 1);
				const CPath& sPath = m_sPath; //m_PropertySheet.m_sPropPagePath
				const DWORD nExitCode = ExecuteWait(AtlFormatString(_T("%s /u \"%s\""), bSilent ? _T("/s") : _T(""), sPath), TRUE);
				if(bSilent)
					MessageBeep(nExitCode ? MB_ICONERROR : MB_OK);
			}
			_ATLCATCH(Exception)
			{
				AtlExceptionMessageBox(m_hWnd, Exception);
			}
			UpdateControls();
			return 0;
		}
		LRESULT OnUserRegister(UINT, INT, HWND)
		{
			_ATLTRY
			{
				CWaitCursor WaitCursor;
				const BOOL bSilent = !(GetKeyState(VK_SCROLL) & 1);
				const DWORD nExitCode = ExecuteWait(AtlFormatString(_T("%s /i:user /n \"%s\""), bSilent ? _T("/s") : _T(""), m_PropertySheet.m_sPropPagePath));
				if(bSilent)
					MessageBeep(nExitCode ? MB_ICONERROR : MB_OK);
			}
			_ATLCATCH(Exception)
			{
				AtlExceptionMessageBox(m_hWnd, Exception);
			}
			UpdateControls();
			return 0;
		}
		LRESULT OnUserUnregister(UINT, INT, HWND)
		{
			_ATLTRY
			{
				CWaitCursor WaitCursor;
				const BOOL bSilent = !(GetKeyState(VK_SCROLL) & 1);
				const DWORD nExitCode = ExecuteWait(AtlFormatString(_T("%s /i:user /n /u \"%s\""), bSilent ? _T("/s") : _T(""), m_PropertySheet.m_sPropPagePath));
				if(bSilent)
					MessageBeep(nExitCode ? MB_ICONERROR : MB_OK);
			}
			_ATLCATCH(Exception)
			{
				AtlExceptionMessageBox(m_hWnd, Exception);
			}
			UpdateControls();
			return 0;
		}
	};

private:
	CRegistrationPropertyPage m_RegistrationPropertyPage;
	CProppageRegistrationPropertyPage m_ProppageRegistrationPropertyPage;
	CPath m_sPropPagePath;

public:
// CRegistrationPropertySheet
	CRegistrationPropertySheet() :
		CPropertySheetT<CRegistrationPropertySheet>(IDS_REGISTRATION_PROPERTYSHEETCAPTION),
		m_RegistrationPropertyPage(this),
		m_ProppageRegistrationPropertyPage(this)
	{
		AddPage(m_RegistrationPropertyPage);
		CPath sDirectory = GetPath();
		sDirectory.RemoveFileSpec();
		m_sPropPagePath.Combine(sDirectory, _T("proppage.dll"));
		if(m_sPropPagePath.FileExists())
			AddPage(m_ProppageRegistrationPropertyPage);
	}
	BOOL SetInitialPosition()
	{
		if(!__super::SetInitialPosition())
			return FALSE;
		SetIcon(AtlLoadIconImage(IDI_MODULE, LR_DEFAULTCOLOR, GetSystemMetrics(SM_CXICON), GetSystemMetrics(SM_CYICON)), TRUE);
		SetIcon(AtlLoadIconImage(IDI_MODULE, LR_DEFAULTCOLOR, GetSystemMetrics(SM_CXSMICON), GetSystemMetrics(SM_CYSMICON)), FALSE);
		#pragma region Indication of Bitness
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
		return TRUE;
	}
	static LPCTSTR GetTypeLibraryType() throw()
	{
		#if defined(_WIN64)
			static LPCTSTR g_pszTypeLibraryType = _T("win64");
		#else
			static LPCTSTR g_pszTypeLibraryType = _T("win32");
		#endif // defined(_WIN64)
		return g_pszTypeLibraryType;
	}
	static CPath FindTypeLibraryPath(const GUID& Identifier = _pAtlModule->m_libid)
	{
		CPath sPath;
		CRegKey Key;
		if(SUCCEEDED(HRESULT_FROM_WIN32(Key.Open(HKEY_CLASSES_ROOT, AtlFormatString(_T("TypeLib\\%ls\\1.0\\0\\%s"), _PersistHelper::StringFromIdentifier(Identifier), GetTypeLibraryType()), KEY_READ))))
			sPath = (LPCTSTR) _RegKeyHelper::QueryStringValue(Key);
		return sPath;
	}
	static CPath FindTypeLibraryPath(HKEY hRootKey, const GUID& Identifier = _pAtlModule->m_libid)
	{
		CPath sPath;
		CRegKey Key;
		if(SUCCEEDED(HRESULT_FROM_WIN32(Key.Open(hRootKey, AtlFormatString(_T("Software\\Classes\\TypeLib\\%ls\\1.0\\0\\%s"), _PersistHelper::StringFromIdentifier(Identifier), GetTypeLibraryType()), KEY_READ))))
			sPath = (LPCTSTR) _RegKeyHelper::QueryStringValue(Key);
		return sPath;
	}
	static CPath FindClassPath(HKEY hRootKey, const GUID& Identifier)
	{
		CPath sPath;
		CRegKey Key;
		if(SUCCEEDED(HRESULT_FROM_WIN32(Key.Open(hRootKey, AtlFormatString(_T("Software\\Classes\\CLSID\\%ls\\InProcServer32"), _PersistHelper::StringFromIdentifier(Identifier)), KEY_READ))))
			sPath = (LPCTSTR) _RegKeyHelper::QueryStringValue(Key);
		return sPath;
	}
	static HANDLE Execute(const CString& sParameters, BOOL bAsAdministrator = FALSE)
	{
		SHELLEXECUTEINFO Information;
		ZeroMemory(&Information, sizeof Information);
		Information.cbSize = sizeof Information;
		Information.fMask = SEE_MASK_NOCLOSEPROCESS;  
		if(bAsAdministrator)
			Information.lpVerb = _T("runas");
		Information.lpFile = _T("regsvr32.exe");
		Information.nShow = SW_SHOWNORMAL;  
		Information.lpParameters = sParameters;  
		__E(ShellExecuteEx(&Information));
		_Z4(atlTraceSync, 4, _T("Information.hInstApp 0x%p, .hProcess 0x%p\n"), Information.hInstApp, Information.hProcess);
		return Information.hProcess;
	}
	static DWORD ExecuteWait(const CString& sParameters, BOOL bAsAdministrator = FALSE)
	{
		CHandle Process;
		Process.Attach(Execute(sParameters, bAsAdministrator));
		const DWORD nWaitResult = WaitForSingleObject(Process, INFINITE);
		_Z4(atlTraceSync, 4, _T("nWaitResult 0x%x\n"), nWaitResult);
		_A(nWaitResult == WAIT_OBJECT_0);
		DWORD nExitCode = 0;
		_W(GetExitCodeProcess(Process, &nExitCode));
		_Z4(atlTraceGeneral, 4, _T("nExitCode %d (0x%x)\n"), nExitCode, nExitCode);
		return nExitCode;
	}
	static CPath GetPath()
	{
		TCHAR pszPath[MAX_PATH] = { 0 };
		_W(GetModuleFileName(_AtlBaseModule.GetModuleInstance(), pszPath, DIM(pszPath)));
		return pszPath;
	}

// Window message handelrs
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

