////////////////////////////////////////////////////////////
// Copyright (C) Roman Ryltsov, 2006-2017
// Created by Roman Ryltsov roman@alax.info
//
// A permission to use the source code is granted as long as reference to 
// source website http://alax.info is retained.

#pragma once

#define SECURITY_WIN32
#include <security.h>
#include "rocrypt.h"
#include "rowinhttp.h"
#include "AboutDialog.h"
//#include "..\DeflateTools\Bzip2Item.h"

#pragma comment(lib, "secur32.lib")

////////////////////////////////////////////////////////////
// CMainDialog

class CMainDialog : 
	public CDialogImpl<CMainDialog>,
	public CDialogResize<CMainDialog>
{
public:
	enum { IDD = IDD_MAIN };

BEGIN_MSG_MAP_EX(CMainDialog)
	CHAIN_MSG_MAP(CDialogResize<CMainDialog>)
	MSG_WM_INITDIALOG(OnInitDialog)
	COMMAND_ID_HANDLER_EX(IDOK, OnCommand)
	COMMAND_ID_HANDLER_EX(IDCANCEL, OnCommand)
	//COMMAND_ID_HANDLER_EX(IDC_UPDATE, OnUpdate)
	COMMAND_ID_HANDLER_EX(IDC_SUBMIT, OnSubmit)
	COMMAND_ID_HANDLER_EX(IDC_SAVEAS, OnSaveAs)
END_MSG_MAP()

BEGIN_DLGRESIZE_MAP(CMainDialog)
	DLGRESIZE_CONTROL(IDC_TEXT, DLSZ_SIZE_X | DLSZ_SIZE_Y)
	//DLGRESIZE_CONTROL(IDC_UPDATE, DLSZ_MOVE_X | DLSZ_MOVE_Y)
	DLGRESIZE_CONTROL(IDC_SUBMIT, DLSZ_MOVE_X | DLSZ_MOVE_Y)
	DLGRESIZE_CONTROL(IDC_SAVEAS, DLSZ_MOVE_X | DLSZ_MOVE_Y)
	DLGRESIZE_CONTROL(IDOK, DLSZ_MOVE_X | DLSZ_MOVE_Y)
END_DLGRESIZE_MAP()

public:

private:
	CDpiAwareness m_DpiAwareness;
	CFont m_TextFont;
	CFont m_ButtonFont;
	CRoArrayT<CString> m_SpecifierArray;
	CString m_sText;
	CRoEdit m_TextEdit;
	CButton m_UpdateButton;
	CButton m_SubmitButton;
	CButton m_SaveAsButton;
	CButton m_CloseButton;

public:
// CMainDialog
	VOID Initialize()
	{
		m_sText.Empty();
		CString sText;
		#pragma region System
		{
			sText += _T("# System") _T("\r\n") _T("\r\n");
			#pragma region Version
			// NOTE: Operating system version changes in Windows 8.1 and Windows Server 2012 R2 https://msdn.microsoft.com/en-us/library/windows/desktop/dn302074
			{
				OSVERSIONINFOEX Version = { sizeof Version };
				#pragma warning(disable: 4996) // 'GetVersionExW': was declared deprecated
				_W(GetVersionEx((OSVERSIONINFO*) &Version));
				#pragma warning(default: 4996)
				CRoArrayT<CString> Array;
				Array.Add(AtlFormatString(_T("%d.%d.%d"), Version.dwMajorVersion, Version.dwMinorVersion, Version.dwBuildNumber));
				#pragma region Friendly Version
				{
					//NOTE: https://msdn.microsoft.com/en-us/library/windows/desktop/ms724833
					static const struct
					{
						LPCSTR pszFriendlyName;
						INT nMajorVersion; // DWORD
						INT nMinorVersion; // DWORD
						INT wProductType; // WORD
					} g_pMap[] = 
					{
						{ "Windows 10", 10, 0, VER_NT_WORKSTATION },
						{ "Windows Server 2016", 10, 0, ~VER_NT_WORKSTATION },
						{ "Windows 8.1", 6, 3, VER_NT_WORKSTATION },
						{ "Windows Server 2012 R2", 6, 3, ~VER_NT_WORKSTATION },
						{ "Windows 8", 6, 2, VER_NT_WORKSTATION },
						{ "Windows Server 2012", 6, 2, ~VER_NT_WORKSTATION },
						{ "Windows 7", 6, 1, VER_NT_WORKSTATION },
						{ "Windows Server 2008 R2", 6, 1, ~VER_NT_WORKSTATION },
						{ "Windows Server 2008", 6, 0, ~VER_NT_WORKSTATION },
						{ "Windows Vista", 6, 0, VER_NT_WORKSTATION },
						//{ "Windows Server 2003 R2", 5, 2, GetSystemMetrics(SM_SERVERR2) != 0
						//{ "Windows Home Server", 5, 2, OSVERSIONINFOEX.wSuiteMask & VER_SUITE_WH_SERVER
						//{ "Windows Server 2003", 5, 2, GetSystemMetrics(SM_SERVERR2) == 0
						//{ "Windows XP Professional x64 Edition", 5, 2, (OSVERSIONINFOEX.wProductType == VER_NT_WORKSTATION) && (SYSTEM_INFO.wProcessorArchitecture==PROCESSOR_ARCHITECTURE_AMD64)
						{ "Windows XP", 5, 1 },
						{ "Windows 2000", 5, 0 },
					};
					for(auto&& Item: g_pMap)
					{
						if(Item.nMajorVersion != Version.dwMajorVersion || Item.nMinorVersion != Version.dwMinorVersion)
							continue;
						if(Item.wProductType == VER_NT_WORKSTATION && Version.wProductType != VER_NT_WORKSTATION)
							continue;
						if(Item.wProductType == ~VER_NT_WORKSTATION && Version.wProductType == VER_NT_WORKSTATION)
							continue;
						const CString sFriendlyName(Item.pszFriendlyName);
						Array.Add(sFriendlyName);
						#pragma region Version Specifier
						if(m_SpecifierArray.IsEmpty())
						{
							m_SpecifierArray.Add(sFriendlyName);
							if(Version.dwMajorVersion >= 10)
								m_SpecifierArray.Add(AtlFormatString(_T("%d.%d.%d"), Version.dwMajorVersion, Version.dwMinorVersion, Version.dwBuildNumber));
							if(Version.wServicePackMinor)
								m_SpecifierArray.Add(AtlFormatString(_T("SP %d.%d"), Version.wServicePackMajor, Version.wServicePackMinor));
							else if(Version.wServicePackMajor)
								m_SpecifierArray.Add(AtlFormatString(_T("SP %d"), Version.wServicePackMajor));
						}
						#pragma endregion 
						break;
					}
				}
				#pragma endregion
				if(Version.wServicePackMajor > 0)
					Array.Add(AtlFormatString(_T("Service Pack %d.%d"), Version.wServicePackMajor, Version.wServicePackMinor));
				if(Version.wSuiteMask)
				{
					#pragma region Map
					static CFlagNameT<WORD> g_pMap[] = 
					{
						#define A(x) { x, #x },
						A(VER_SUITE_SMALLBUSINESS)
						A(VER_SUITE_ENTERPRISE)
						A(VER_SUITE_BACKOFFICE)
						A(VER_SUITE_COMMUNICATIONS)
						A(VER_SUITE_TERMINAL)
						A(VER_SUITE_SMALLBUSINESS_RESTRICTED)
						A(VER_SUITE_EMBEDDEDNT)
						A(VER_SUITE_DATACENTER)
						A(VER_SUITE_SINGLEUSERTS)
						A(VER_SUITE_PERSONAL)
						A(VER_SUITE_BLADE)
						A(VER_SUITE_EMBEDDED_RESTRICTED)
						A(VER_SUITE_SECURITY_APPLIANCE)
						A(VER_SUITE_STORAGE_SERVER)
						A(VER_SUITE_COMPUTE_SERVER)
						A(VER_SUITE_WH_SERVER)
						#undef A
					};
					#pragma endregion
					Array.Add(FormatFlagsT(g_pMap, Version.wSuiteMask));
				}
				if(Version.wProductType)
				{
					#pragma region Map
					static CEnumerationNameT<BYTE> g_pMap[] = 
					{
						#define A(x) { x, #x },
						A(VER_NT_WORKSTATION)
						A(VER_NT_DOMAIN_CONTROLLER)
						A(VER_NT_SERVER)
						#undef A
					};
					#pragma endregion
					Array.Add(FormatEnumerationT(g_pMap, Version.wProductType));
				}
				CString sTitle;
				// ...
				CString sItems = _StringHelper::Join(Array, _T(", "));
				if(sTitle.IsEmpty())
					sTitle = sItems;
				else
					sTitle = AtlFormatString(_T("%s (%s)"), sTitle, sItems);
				sText += AtlFormatString(_T(" * ") _T("Version: %s") _T("\r\n"), sTitle);
				_ATLTRY
				{
					// NOTE: Requires Win Vista, Win Server 2003
					typedef BOOL (WINAPI *GETPRODUCTINFO)(DWORD dwOSMajorVersion, DWORD dwOSMinorVersion, DWORD dwSpMajorVersion, DWORD dwSpMinorVersion, PDWORD pdwReturnedProductType);
					GETPRODUCTINFO pGetProductInfo = (GETPRODUCTINFO) GetProcAddress(GetModuleHandle(_T("kernel32.dll")), "GetProductInfo");
					if(pGetProductInfo)
					{
						DWORD nProductType = 0;
						__E(pGetProductInfo(Version.dwMajorVersion, Version.dwMinorVersion, Version.wServicePackMajor, Version.wServicePackMinor, &nProductType));
						if(nProductType)
						{
							#pragma region Map
							static CEnumerationNameT<DWORD> g_pMap[] = 
							{
								#define A(x) { x, #x },
								A(PRODUCT_UNDEFINED)
								A(PRODUCT_ULTIMATE)
								A(PRODUCT_HOME_BASIC)
								A(PRODUCT_HOME_PREMIUM)
								A(PRODUCT_ENTERPRISE)
								A(PRODUCT_HOME_BASIC_N)
								A(PRODUCT_BUSINESS)
								A(PRODUCT_STANDARD_SERVER)
								A(PRODUCT_DATACENTER_SERVER)
								A(PRODUCT_SMALLBUSINESS_SERVER)
								A(PRODUCT_ENTERPRISE_SERVER)
								A(PRODUCT_STARTER)
								A(PRODUCT_DATACENTER_SERVER_CORE)
								A(PRODUCT_STANDARD_SERVER_CORE)
								A(PRODUCT_ENTERPRISE_SERVER_CORE)
								A(PRODUCT_ENTERPRISE_SERVER_IA64)
								A(PRODUCT_BUSINESS_N)
								A(PRODUCT_WEB_SERVER)
								A(PRODUCT_CLUSTER_SERVER)
								A(PRODUCT_HOME_SERVER)
								A(PRODUCT_STORAGE_EXPRESS_SERVER)
								A(PRODUCT_STORAGE_STANDARD_SERVER)
								A(PRODUCT_STORAGE_WORKGROUP_SERVER)
								A(PRODUCT_STORAGE_ENTERPRISE_SERVER)
								A(PRODUCT_SERVER_FOR_SMALLBUSINESS)
								A(PRODUCT_SMALLBUSINESS_SERVER_PREMIUM)
								A(PRODUCT_HOME_PREMIUM_N)
								A(PRODUCT_ENTERPRISE_N)
								A(PRODUCT_ULTIMATE_N)
								A(PRODUCT_WEB_SERVER_CORE)
								A(PRODUCT_MEDIUMBUSINESS_SERVER_MANAGEMENT)
								A(PRODUCT_MEDIUMBUSINESS_SERVER_SECURITY)
								A(PRODUCT_MEDIUMBUSINESS_SERVER_MESSAGING)
								A(PRODUCT_SERVER_FOUNDATION)
								A(PRODUCT_HOME_PREMIUM_SERVER)
								A(PRODUCT_SERVER_FOR_SMALLBUSINESS_V)
								A(PRODUCT_STANDARD_SERVER_V)
								A(PRODUCT_DATACENTER_SERVER_V)
								A(PRODUCT_ENTERPRISE_SERVER_V)
								A(PRODUCT_DATACENTER_SERVER_CORE_V)
								A(PRODUCT_STANDARD_SERVER_CORE_V)
								A(PRODUCT_ENTERPRISE_SERVER_CORE_V)
								A(PRODUCT_HYPERV)
								A(PRODUCT_STORAGE_EXPRESS_SERVER_CORE)
								A(PRODUCT_STORAGE_STANDARD_SERVER_CORE)
								A(PRODUCT_STORAGE_WORKGROUP_SERVER_CORE)
								A(PRODUCT_STORAGE_ENTERPRISE_SERVER_CORE)
								A(PRODUCT_STARTER_N)
								A(PRODUCT_PROFESSIONAL)
								A(PRODUCT_PROFESSIONAL_N)
								A(PRODUCT_SB_SOLUTION_SERVER)
								A(PRODUCT_SERVER_FOR_SB_SOLUTIONS)
								A(PRODUCT_STANDARD_SERVER_SOLUTIONS)
								A(PRODUCT_STANDARD_SERVER_SOLUTIONS_CORE)
								A(PRODUCT_SB_SOLUTION_SERVER_EM)
								A(PRODUCT_SERVER_FOR_SB_SOLUTIONS_EM)
								A(PRODUCT_SOLUTION_EMBEDDEDSERVER)
								A(PRODUCT_SOLUTION_EMBEDDEDSERVER_CORE)
								A(PRODUCT_PROFESSIONAL_EMBEDDED)
								A(PRODUCT_ESSENTIALBUSINESS_SERVER_MGMT)
								A(PRODUCT_ESSENTIALBUSINESS_SERVER_ADDL)
								A(PRODUCT_ESSENTIALBUSINESS_SERVER_MGMTSVC)
								A(PRODUCT_ESSENTIALBUSINESS_SERVER_ADDLSVC)
								A(PRODUCT_SMALLBUSINESS_SERVER_PREMIUM_CORE)
								A(PRODUCT_CLUSTER_SERVER_V)
								A(PRODUCT_EMBEDDED)
								A(PRODUCT_STARTER_E)
								A(PRODUCT_HOME_BASIC_E)
								A(PRODUCT_HOME_PREMIUM_E)
								A(PRODUCT_PROFESSIONAL_E)
								A(PRODUCT_ENTERPRISE_E)
								A(PRODUCT_ULTIMATE_E)
								A(PRODUCT_ENTERPRISE_EVALUATION)
								A(PRODUCT_MULTIPOINT_STANDARD_SERVER)
								A(PRODUCT_MULTIPOINT_PREMIUM_SERVER)
								A(PRODUCT_STANDARD_EVALUATION_SERVER)
								A(PRODUCT_DATACENTER_EVALUATION_SERVER)
								A(PRODUCT_ENTERPRISE_N_EVALUATION)
								A(PRODUCT_EMBEDDED_AUTOMOTIVE)
								A(PRODUCT_EMBEDDED_INDUSTRY_A)
								A(PRODUCT_THINPC)
								A(PRODUCT_EMBEDDED_A)
								A(PRODUCT_EMBEDDED_INDUSTRY)
								A(PRODUCT_EMBEDDED_E)
								A(PRODUCT_EMBEDDED_INDUSTRY_E)
								A(PRODUCT_EMBEDDED_INDUSTRY_A_E)
								A(PRODUCT_STORAGE_WORKGROUP_EVALUATION_SERVER)
								A(PRODUCT_STORAGE_STANDARD_EVALUATION_SERVER)
								A(PRODUCT_CORE_ARM)
								A(PRODUCT_CORE_N)
								A(PRODUCT_CORE_COUNTRYSPECIFIC)
								A(PRODUCT_CORE_SINGLELANGUAGE)
								A(PRODUCT_CORE)
								A(PRODUCT_PROFESSIONAL_WMC)
								A(PRODUCT_MOBILE_CORE)
								A(PRODUCT_EMBEDDED_INDUSTRY_EVAL)
								A(PRODUCT_EMBEDDED_INDUSTRY_E_EVAL)
								A(PRODUCT_EMBEDDED_EVAL)
								A(PRODUCT_EMBEDDED_E_EVAL)
								A(PRODUCT_NANO_SERVER) //A(PRODUCT_CORE_SERVER)
								A(PRODUCT_CLOUD_STORAGE_SERVER)
								A(PRODUCT_CORE_CONNECTED)
								A(PRODUCT_PROFESSIONAL_STUDENT)
								A(PRODUCT_CORE_CONNECTED_N)
								A(PRODUCT_PROFESSIONAL_STUDENT_N)
								A(PRODUCT_CORE_CONNECTED_SINGLELANGUAGE)
								A(PRODUCT_CORE_CONNECTED_COUNTRYSPECIFIC)
								A(PRODUCT_UNLICENSED)
								#undef A
							};
							#pragma endregion
							sText += AtlFormatString(_T(" * ") _T("Product: %s") _T("\r\n"), FormatEnumerationT(g_pMap, nProductType));
						}
					}
				}
				_ATLCATCHALL()
				{
					_Z_EXCEPTION();
				}
			}
			#pragma endregion 
			TCHAR pszComputerName[MAX_COMPUTERNAME_LENGTH] = { 0 };
			#if TRUE
				ULONG nComputerNameLength = DIM(pszComputerName);
				_W(GetComputerNameEx(ComputerNameDnsFullyQualified, pszComputerName, &nComputerNameLength));
			#else
				DWORD nComputerNameLength = DIM(pszComputerName);
				_W(GetComputerName(pszComputerName, &nComputerNameLength));
			#endif
			sText += AtlFormatString(_T(" * ") _T("Computer Name: `%s`") _T("\r\n"), pszComputerName);
			TCHAR pszUserName[256] = { 0 };
			#if TRUE
				ULONG nUserNameLength = DIM(pszUserName);
				_W(GetUserNameEx(NameSamCompatible, pszUserName, &nUserNameLength));
			#else
				DWORD nUserNameLength = DIM(pszUserName);
				_W(GetUserName(pszUserName, &nUserNameLength));
			#endif
			BOOL bAdministrator = FALSE;
			bool bIsMember = FALSE;
			if(CAccessToken().CheckTokenMembership(Sids::Admins(), &bIsMember) && bIsMember)
				bAdministrator = TRUE;
			sText += AtlFormatString(_T(" * ") _T("User Name: `%s` %s") _T("\r\n"), pszUserName, bAdministrator ? _T("(Administrator)") : _T(""));
			WCHAR pszSystemLocaleName[64] = { 0 }, pszUserLocaleName[64] = { 0 };
			_W(GetSystemDefaultLocaleName(pszSystemLocaleName, DIM(pszSystemLocaleName)));
			_W(GetUserDefaultLocaleName(pszUserLocaleName, DIM(pszUserLocaleName)));
			sText += AtlFormatString(_T(" * ") _T("Locale: System `%ls`, User `%ls`") _T("\r\n"), pszSystemLocaleName, pszUserLocaleName);
			SYSTEMTIME LocalTime;
			GetLocalTime(&LocalTime);
			sText += AtlFormatString(_T(" * ") _T("Local Time: `%s`") _T("\r\n"), _StringHelper::FormatDateTime(&LocalTime));
			SYSTEM_INFO SystemInformation;
			GetSystemInfo(&SystemInformation);
			#pragma region Architecture
			CString sArchitecture;
			switch(SystemInformation.wProcessorArchitecture)
			{
			case PROCESSOR_ARCHITECTURE_INTEL:
				sArchitecture = _T("x86");
				break;
			case PROCESSOR_ARCHITECTURE_AMD64:
				sArchitecture = _T("AMD/Intel x64");
				break;
			case PROCESSOR_ARCHITECTURE_IA64:
				sArchitecture = _T("Intel Itanium");
				break;
			default:
				sArchitecture = AtlFormatString(_T("`0x%04X`"), SystemInformation.wProcessorArchitecture);
			}
			#if defined(_WIN64)
				sText += AtlFormatString(_T(" * ") _T("Architecture: %s (x64 Application)") _T("\r\n"), sArchitecture);
			#else
				sText += AtlFormatString(_T(" * ") _T("Architecture: %s") _T("\r\n"), sArchitecture);
			#endif // defined(_WIN64)
			#pragma endregion 
			sText += AtlFormatString(_T(" * ") _T("Processors: `%d`, Active Mask `0x%X`") _T("\r\n"), SystemInformation.dwNumberOfProcessors, SystemInformation.dwActiveProcessorMask);
			sText += AtlFormatString(_T(" * ") _T("Page Size: `0x%X`") _T("\r\n"), SystemInformation.dwPageSize);
			sText += AtlFormatString(_T(" * ") _T("Application Address Space: `0x%p`..`0x%p`") _T("\r\n"), SystemInformation.lpMinimumApplicationAddress, SystemInformation.lpMaximumApplicationAddress);
			#pragma region Memory
			MEMORYSTATUSEX MemoryStatus = { sizeof MemoryStatus };
			_W(GlobalMemoryStatusEx(&MemoryStatus));
			sText += AtlFormatString(_T(" * ") _T("Physical Memory: `%s` MB") _T("\r\n"), _StringHelper::FormatNumber((LONG) (MemoryStatus.ullTotalPhys >> 20)));
			sText += AtlFormatString(_T(" * ") _T("Committed Memory Limit: `%s` MB") _T("\r\n"), _StringHelper::FormatNumber((LONG) (MemoryStatus.ullTotalPageFile >> 20)));
			#pragma endregion
			sText += AtlFormatString(_T(" * ") _T("Application Version: `%s`") _T("\r\n"), _VersionInfoHelper::GetVersionString(_VersionInfoHelper::GetFileVersion(_VersionInfoHelper::GetModulePath())));
			//sText += _T("\r\n");
			#pragma region CPU Identification and Features
			_ATLTRY
			{
				CRoArrayT<CString> Array;
				// NOTE: __cpuid, __cpuidex https://msdn.microsoft.com/en-us/library/hskdteyh.aspx
				//       http://stackoverflow.com/questions/6121792/how-to-check-if-a-cpu-supports-the-sse3-instruction-set
				//		 https://docs.microsoft.com/en-us/cpp/intrinsics/cpuid-cpuidex
				//		 https://en.wikipedia.org/wiki/CPUID
				INT pnInformation[4] = { -1 };
				__cpuid(pnInformation, 0);
				const INT nIdentifierCount = pnInformation[0];
				CTempBuffer<INT> pnData((nIdentifierCount + 1) * _countof(pnInformation));
				for(INT nIdentifierIndex = 0; nIdentifierIndex <= nIdentifierCount; nIdentifierIndex++)
					__cpuidex(pnData + 4 * nIdentifierIndex, nIdentifierIndex, 0);
				#pragma region Vendor
				CHAR pszVendor[0x20];
				ZeroMemory(pszVendor, sizeof pszVendor);
				*reinterpret_cast<INT*>(pszVendor + 0) = pnData[1];
				*reinterpret_cast<INT*>(pszVendor + 4) = pnData[3];
				*reinterpret_cast<INT*>(pszVendor + 8) = pnData[2];
				Array.Add(AtlFormatString(_T("`%hs`"), pszVendor));
				#pragma endregion 
				INT n1Ecx = 0, n1Edx = 0;
				if(nIdentifierCount >= 1)
				{
					n1Ecx = pnData[1 * 4 + 2];
					n1Edx = pnData[1 * 4 + 3];
					if(n1Edx)
					{
						CRoArrayT<CString> SubArray;
						if(n1Edx & (1 << 23))
							SubArray.Add(_T("MMX"));
						if(n1Edx & (1 << 25))
							SubArray.Add(_T("SSE"));
						if(n1Edx & (1 << 26))
							SubArray.Add(_T("SSE2"));
						Array.Add(AtlFormatString(_T("0x1 EDX `0x%08X` (%s)"), n1Edx, _StringHelper::Join(SubArray, _T(", "))));
					}
					if(n1Ecx)
					{
						CRoArrayT<CString> SubArray;
						if(n1Ecx & (1 << 0))
							SubArray.Add(_T("SSE3"));
						if(n1Ecx & (1 << 9))
							SubArray.Add(_T("SSSE3"));
						if(n1Ecx & (1 << 19))
							SubArray.Add(_T("SSE41"));
						if(n1Ecx & (1 << 20))
							SubArray.Add(_T("SSE42"));
						if(n1Ecx & (1 << 28))
							SubArray.Add(_T("AVX"));
						Array.Add(AtlFormatString(_T("0x1 ECX `0x%08X` (%s)"), n1Ecx, _StringHelper::Join(SubArray, _T(", "))));
					}
				}
				INT n7Ebx = 0, n7Ecx = 0;
				if(nIdentifierCount >= 7)
				{
					n7Ebx = pnData[7 * 4 + 1];
					n7Ecx = pnData[7 * 4 + 2];
					if(n7Ebx)
					{
						CRoArrayT<CString> SubArray;
						if(n7Ebx & (1 << 5))
							SubArray.Add(_T("AVX2"));
						Array.Add(AtlFormatString(_T("0x7 EBX `0x%08X` (%s)"), n7Ebx, _StringHelper::Join(SubArray, _T(", "))));
					}
					if(n7Ecx)
					{
						//CRoArrayT<CString> SubArray;
						//if(n7Ecx & (1 << 5))
						//	SubArray.Add(_T("AVX2"));
						Array.Add(AtlFormatString(_T("0x7 ECX `0x%08X`"), n7Ebx));
					}
				}
				__cpuid(pnInformation, 0x80000000);
				const UINT nExtendedIdentifierCount = (UINT) pnInformation[0];
				CTempBuffer<INT> pnExtendedData((nExtendedIdentifierCount - 0x80000000 + 1) * _countof(pnInformation));
				for(UINT nExtendedIdentifierIndex = 0x80000000; nExtendedIdentifierIndex <= nExtendedIdentifierCount; nExtendedIdentifierIndex++)
					__cpuidex(pnExtendedData + 4 * (nExtendedIdentifierIndex - 0x80000000), nExtendedIdentifierIndex, 0);
				INT nEx1Ecx = 0, nEx1Edx = 0;
				if(nExtendedIdentifierCount >= 0x80000001)
				{
					nEx1Ecx = pnExtendedData[1 * 4 + 2];
					nEx1Edx = pnExtendedData[1 * 4 + 3];
				}
				#pragma region Vendor
				CHAR pszBrand[0x40];
				ZeroMemory(pszBrand, sizeof pszBrand);
				if(nExtendedIdentifierCount >= 0x80000004)
				{
					memcpy(pszBrand, pnExtendedData + 2 * 4, 3 * 4 * sizeof (INT));
					sText += AtlFormatString(_T(" * ") _T("CPU Brand: %hs") _T("\r\n"), pszBrand);
				}
				#pragma endregion 
				sText += AtlFormatString(_T(" * ") _T("CPUID: %s") _T("\r\n"), _StringHelper::Join(Array, _T(", ")));
			}
			_ATLCATCHALL()
			{
				//_Z_EXCEPTION();
			}
			#pragma endregion
			#pragma region IsProcessorFeaturePresent
			// NOTE: IsProcessorFeaturePresent function https://msdn.microsoft.com/en-us/library/windows/desktop/ms724482 
			{
				static const CEnumerationNameT<DWORD> g_pMap[] = 
				{
					#define A(x) { x, #x },
					A(PF_FLOATING_POINT_PRECISION_ERRATA)
					A(PF_FLOATING_POINT_EMULATED)
					A(PF_COMPARE_EXCHANGE_DOUBLE)
					A(PF_MMX_INSTRUCTIONS_AVAILABLE)
					A(PF_PPC_MOVEMEM_64BIT_OK)
					A(PF_ALPHA_BYTE_INSTRUCTIONS)
					A(PF_XMMI_INSTRUCTIONS_AVAILABLE)
					A(PF_3DNOW_INSTRUCTIONS_AVAILABLE)
					A(PF_RDTSC_INSTRUCTION_AVAILABLE)
					A(PF_PAE_ENABLED)
					A(PF_XMMI64_INSTRUCTIONS_AVAILABLE)
					A(PF_SSE_DAZ_MODE_AVAILABLE)
					A(PF_NX_ENABLED)
					A(PF_SSE3_INSTRUCTIONS_AVAILABLE)
					A(PF_COMPARE_EXCHANGE128)
					A(PF_COMPARE64_EXCHANGE128)
					A(PF_CHANNELS_ENABLED)
					A(PF_XSAVE_ENABLED)
					A(PF_ARM_VFP_32_REGISTERS_AVAILABLE)
					A(PF_ARM_NEON_INSTRUCTIONS_AVAILABLE)
					A(PF_SECOND_LEVEL_ADDRESS_TRANSLATION)
					A(PF_VIRT_FIRMWARE_ENABLED)
					A(PF_RDWRFSGSBASE_AVAILABLE)
					A(PF_FASTFAIL_AVAILABLE)
					A(PF_ARM_DIVIDE_INSTRUCTION_AVAILABLE)
					A(PF_ARM_64BIT_LOADSTORE_ATOMIC)
					A(PF_ARM_EXTERNAL_CACHE_AVAILABLE)
					A(PF_ARM_FMAC_INSTRUCTIONS_AVAILABLE)
					A(PF_RDRAND_INSTRUCTION_AVAILABLE)
					A(PF_ARM_V8_INSTRUCTIONS_AVAILABLE)
					A(PF_ARM_V8_CRYPTO_INSTRUCTIONS_AVAILABLE)
					A(PF_ARM_V8_CRC32_INSTRUCTIONS_AVAILABLE)
					A(PF_RDTSCP_INSTRUCTION_AVAILABLE)
					#undef A
				};
				sText += AtlFormatString(_T(" * ") _T("IsProcessorFeaturePresent:") _T("\r\n"));
				for(auto&& Item: g_pMap)
					if(IsProcessorFeaturePresent(Item.Value))
						sText += AtlFormatString(_T("  * %hs") _T("\r\n"), Item.pszName);
			}
			#pragma endregion
			m_sText += sText;
		}
		m_sText += _T("\r\n");
		#pragma endregion
		DWORD nSize = 0;
		GetLogicalProcessorInformation(NULL, &nSize);
		CTempBuffer<SYSTEM_LOGICAL_PROCESSOR_INFORMATION> pLogicalProcessorInformation;
		ATLVERIFY(pLogicalProcessorInformation.AllocateBytes(nSize));
		ATLENSURE_THROW(GetLogicalProcessorInformation(pLogicalProcessorInformation, &nSize), AtlHresultFromLastError());
		static const CEnumerationNameT<LOGICAL_PROCESSOR_RELATIONSHIP> g_pLogicalProcessorRelationshipMap[] = 
		{
			#define A(x) { x, #x },
			A(RelationProcessorCore)
			A(RelationNumaNode)
			A(RelationCache)
			A(RelationProcessorPackage)
			A(RelationGroup)
			//A(RelationAll)
			#undef A
		};
		m_sText.Append(_T("## Logical Processors") _T("\r\n"));
		m_sText.Append(_T("\r\n"));
		_Z4(atlTraceGeneral, 4, _T("nSize %d, sizeof (SYSTEM_LOGICAL_PROCESSOR_INFORMATION) %d\n"), nSize, sizeof (SYSTEM_LOGICAL_PROCESSOR_INFORMATION));
		CAtlMap<LOGICAL_PROCESSOR_RELATIONSHIP, UINT> RelationshipMap;
		RelationshipMap[RelationProcessorCore] = 0;
		RelationshipMap[RelationNumaNode] = 0;
		RelationshipMap[RelationCache] = 0;
		RelationshipMap[RelationProcessorPackage] = 0;
		RelationshipMap[RelationGroup] = 0;
		for(const SYSTEM_LOGICAL_PROCESSOR_INFORMATION* pCurrentLogicalProcessorInformation = pLogicalProcessorInformation; (const BYTE*) (pCurrentLogicalProcessorInformation + 1) <= (const BYTE*) ((const SYSTEM_LOGICAL_PROCESSOR_INFORMATION*) pLogicalProcessorInformation) + nSize; pCurrentLogicalProcessorInformation++)
		{
			_Z4(atlTraceGeneral, 4, _T("pCurrentLogicalProcessorInformation 0x%p\n"), pCurrentLogicalProcessorInformation);
			m_sText.AppendFormat(_T("Record %s (0x%02X)") _T("\r\n"), FormatEnumerationT(g_pLogicalProcessorRelationshipMap, pCurrentLogicalProcessorInformation->Relationship), pCurrentLogicalProcessorInformation->ProcessorMask);
			m_sText += _T("\r\n");
			#pragma region RelationProcessorCore
			if(pCurrentLogicalProcessorInformation->Relationship == RelationProcessorCore)
			{
				static const CFlagNameT<BYTE> g_pFlagMap[] = 
				{
					#define A(x) { x, #x },
					A(LTP_PC_SMT)
					#undef A
				};
				m_sText.AppendFormat(_T("  * ProcessorCore.Flags: %s") _T("\r\n"), FormatFlagsT(g_pFlagMap, pCurrentLogicalProcessorInformation->ProcessorCore.Flags));
				m_sText += _T("\r\n");
				RelationshipMap[RelationProcessorCore]++;
			}
			#pragma endregion 
			#pragma region RelationNumaNode
			if(pCurrentLogicalProcessorInformation->Relationship == RelationNumaNode)
			{
				m_sText.AppendFormat(_T("  * NumaNode.NodeNumber: 0x%X\r\n"), pCurrentLogicalProcessorInformation->NumaNode.NodeNumber);
				m_sText += _T("\r\n");
				RelationshipMap[RelationNumaNode]++;
			}
			#pragma endregion 
			#pragma region RelationCache
			if(pCurrentLogicalProcessorInformation->Relationship == RelationCache)
			{
				static const CEnumerationNameT<BYTE> g_pAssociativityMap[] = 
				{
					#define A(x) { x, #x },
					A(CACHE_FULLY_ASSOCIATIVE)
					#undef A
				};
				static const CEnumerationNameT<PROCESSOR_CACHE_TYPE> g_pTypeMap[] = 
				{
					#define A(x) { x, #x },
					A(CacheUnified)
					A(CacheInstruction)
					A(CacheData)
					A(CacheTrace)
					#undef A
				};
				m_sText.AppendFormat(_T("  * Cache.Level: %d") _T("\r\n"), pCurrentLogicalProcessorInformation->Cache.Level);
				m_sText.AppendFormat(_T("  * Cache.Associativity: %s") _T("\r\n"), FormatEnumerationT(g_pAssociativityMap, pCurrentLogicalProcessorInformation->Cache.Associativity));
				m_sText.AppendFormat(_T("  * Cache.LineSize: %d (0x%X)") _T("\r\n"), pCurrentLogicalProcessorInformation->Cache.LineSize, pCurrentLogicalProcessorInformation->Cache.LineSize);
				m_sText.AppendFormat(_T("  * Cache.Size: %d (0x%X)") _T("\r\n"), pCurrentLogicalProcessorInformation->Cache.Size, pCurrentLogicalProcessorInformation->Cache.Size);
				m_sText.AppendFormat(_T("  * Cache.Type: %s") _T("\r\n"), FormatEnumerationT(g_pTypeMap, pCurrentLogicalProcessorInformation->Cache.Type));
				m_sText += _T("\r\n");
				RelationshipMap[RelationCache]++;
			}
			#pragma endregion 
			#pragma region RelationProcessorPackage
			if(pCurrentLogicalProcessorInformation->Relationship == RelationProcessorPackage)
				RelationshipMap[RelationProcessorPackage]++;
			#pragma endregion 
			#pragma region RelationGroup
			if(pCurrentLogicalProcessorInformation->Relationship == RelationGroup)
				RelationshipMap[RelationGroup]++;
			#pragma endregion 
		}
		#pragma region Summary
		m_sText.Append(_T("### Record Count per Relationship") _T("\r\n") _T("\r\n"));
		m_sText.AppendFormat(_T(" *  %s: %d") _T("\r\n"), FormatEnumerationT(g_pLogicalProcessorRelationshipMap, RelationProcessorCore), RelationshipMap[RelationProcessorCore]);
		m_sText.AppendFormat(_T(" *  %s: %d") _T("\r\n"), FormatEnumerationT(g_pLogicalProcessorRelationshipMap, RelationNumaNode), RelationshipMap[RelationNumaNode]);
		m_sText.AppendFormat(_T(" *  %s: %d") _T("\r\n"), FormatEnumerationT(g_pLogicalProcessorRelationshipMap, RelationCache), RelationshipMap[RelationCache]);
		m_sText.AppendFormat(_T(" *  %s: %d") _T("\r\n"), FormatEnumerationT(g_pLogicalProcessorRelationshipMap, RelationProcessorPackage), RelationshipMap[RelationProcessorPackage]);
		m_sText.AppendFormat(_T(" *  %s: %d") _T("\r\n"), FormatEnumerationT(g_pLogicalProcessorRelationshipMap, RelationGroup), RelationshipMap[RelationGroup]);
		m_sText += _T("\r\n");
		#pragma endregion 
	}
	VOID UpdateControls()
	{
	}

// Window Message Handler
	LRESULT OnInitDialog(HWND, LPARAM)
	{
		Initialize();
		DlgResize_Init(FALSE);
		SetIcon(AtlLoadIconImage(IDI_MODULE, LR_DEFAULTCOLOR, GetSystemMetrics(SM_CXICON), GetSystemMetrics(SM_CYICON)), TRUE);
		SetIcon(AtlLoadIconImage(IDI_MODULE, LR_DEFAULTCOLOR, GetSystemMetrics(SM_CXSMICON), GetSystemMetrics(SM_CYSMICON)), FALSE);
		CMenuHandle Menu = GetSystemMenu(FALSE);
		_W(Menu.AppendMenu(MF_SEPARATOR));
		_W(Menu.AppendMenu(MF_STRING, ID_APP_ABOUT, _T("&About...")));
		CAboutDialog::UpdateCaption(*this);
		m_TextEdit = GetDlgItem(IDC_TEXT);
		m_TextFont = m_DpiAwareness.ScaleFont(m_TextEdit.GetFont(), 11);
		m_TextEdit.SetFont(m_TextFont);
		m_TextEdit.SetWindowText(m_sText);
		m_UpdateButton = GetDlgItem(IDC_UPDATE);
		m_SubmitButton = GetDlgItem(IDC_SUBMIT);
		m_SaveAsButton = GetDlgItem(IDC_SAVEAS);
		m_CloseButton = GetDlgItem(IDOK);
		m_ButtonFont = m_DpiAwareness.ScaleFont(GetFont(), 9);
		m_UpdateButton.SetFont(m_ButtonFont);
		m_SubmitButton.SetFont(m_ButtonFont);
		m_SaveAsButton.SetFont(m_ButtonFont);
		m_CloseButton.SetFont(m_ButtonFont);
		#pragma region Position
		{
			CRect Position;
			_W(GetWindowRect(Position));
			const HMONITOR hMonitor = MonitorFromPoint(Position.CenterPoint(), MONITOR_DEFAULTTONEAREST);
			MONITORINFO Information = { sizeof Information };
			if(GetMonitorInfo(hMonitor, &Information))
			{
				CSize DefaultExtent = reinterpret_cast<const CRect&>(Information.rcWork).Size();
				DefaultExtent.cx = DefaultExtent.cx * 6 / 8;
				DefaultExtent.cy = DefaultExtent.cy * 6 / 8;
				BOOL bUpdate = FALSE;
				CSize ExcessExtent(DefaultExtent.cx - Position.Width(), DefaultExtent.cy - Position.Height());
				if(ExcessExtent.cx > 0)
				{
					Position.left -= ExcessExtent.cx / 2;
					Position.right = Position.left + DefaultExtent.cx;
					bUpdate = TRUE;
				}
				if(ExcessExtent.cy > 0)
				{
					Position.top -= ExcessExtent.cy / 2;
					Position.bottom = Position.top + DefaultExtent.cy;
					bUpdate = TRUE;
				}
				if(bUpdate)
					_W(MoveWindow(Position, FALSE));
			}
		}
		_W(CenterWindow());
		#pragma endregion
		UpdateControls();
		return TRUE;
	}
	LRESULT OnCommand(UINT, INT nIdentifier, HWND)
	{
		_W(EndDialog(nIdentifier));
		return 0;
	}
	LRESULT OnSubmit(UINT, INT nIdentifier, HWND)
	{
		CWaitCursor WaitCursor;
		const CString sFileDescription = _VersionInfoHelper::GetString(_VersionInfoHelper::GetModulePath(), _T("FileDescription"));
		CWinHttpPostData PostData;
		PostData.AddValue(_T("subj"), sFileDescription);
		CStringA sTextA = Utf8StringFromString(m_TextEdit.GetValue());
		static const UINT g_nFlags = _Base64Helper::FLAG_NOPAD | _Base64Helper::FLAG_NOCRLF;
		#if TRUE
			CStringA sBodyTextA = sTextA;
			static const SIZE_T g_nMaximalBodyLength = 24 << 10; // 24 KB
			if(sBodyTextA.GetLength() > (INT) g_nMaximalBodyLength)
			{
				sBodyTextA = sBodyTextA.Left((INT) g_nMaximalBodyLength);
				sBodyTextA += "\r\n";
				sBodyTextA += AtlFormatStringT<CStringA>("<%d more characters truncated>", sTextA.GetLength() - sBodyTextA.GetLength()) + "\r\n";
				PostData.AddValue(_T("body"), CString(_Base64Helper::Encode<CStringA>((const BYTE*) (LPCSTR) sBodyTextA, sBodyTextA.GetLength(), g_nFlags)));
				#pragma region Bzip2 Body
				//_ATLTRY
				//{
				//	CLocalObjectPtr<CBzip2Item> pItem;
				//	pItem->SetRawData((const BYTE*) (LPCSTR) sTextA, sTextA.GetLength());
				//	CComBSTR sDataText;
				//	__C(pItem->get_DataText(&sDataText));
				//	#if defined(_DEBUG) && FALSE
				//		COMPILER_MESSAGE("Debug: Write Base64 Bzip2 Output to File")
				//		CPath sPath;
				//		sPath.Combine(GetPathDirectory(GetModulePath()), _T("Output.bz2.b64"));
				//		CAtlFile File; 
				//		_V(File.Create(sPath, GENERIC_WRITE, FILE_SHARE_READ, CREATE_ALWAYS));
				//		_V(File.Write(CStringA(sDataText), sDataText.Length()));
				//	#endif // defined(_DEBUG)
				//	PostData.AddValue(_T("attachment_0_body"), sDataText);
				//	PostData.AddValue(_T("attachment_0_filename"), _T("body.md.bz2"));
				//	PostData.AddValue(_T("attachment_count"), _T("1"));
				//}
				//_ATLCATCHALL()
				//{
				//	_Z_EXCEPTION();
				//}
				#pragma endregion 
			} else
				PostData.AddValue(_T("body"), CString(_Base64Helper::Encode<CStringA>((const BYTE*) (LPCSTR) sTextA, sTextA.GetLength(), g_nFlags)));
		#else
			PostData.AddValue(_T("body"), CString(_Base64Helper::Encode<CStringA>((const BYTE*) (LPCSTR) sTextA, sTextA.GetLength(), g_nFlags)));
		#endif
		#if defined(_DEBUG)
			PostData.AddValue(_T("debug"), _T("1"));
		#endif // defined(_DEBUG)
		CWinHttpSessionHandle Session = OpenWinHttpSessionHandle(sFileDescription);
		__E(Session);
		CWinHttpConnectionHandle Connection = Session.Connect(CStringW(_T("alax.info")));
		__E(Connection);
		CWinHttpRequestHandle Request = Connection.OpenRequest(CStringW(_T("POST")), CStringW(_T("/post.php")));
		__E(Request);
		CStringW sPostHeaders = PostData.GetHeaders();
		CStringA sPostData(PostData.GetValue());
		__E(Request.Send(sPostHeaders, -1, const_cast<LPSTR>((LPCSTR) sPostData), sPostData.GetLength(), sPostData.GetLength()));
		__E(Request.ReceiveResponse());
		DWORD nStatusCode = 0;
		__E(Request.QueryNumberHeader(WINHTTP_QUERY_STATUS_CODE | WINHTTP_QUERY_FLAG_NUMBER, nStatusCode));
		__D(nStatusCode / 100 == HTTP_STATUS_OK / 100, E_UNNAMED);
		MessageBeep(MB_OK);
		UpdateControls();
		return 0;
	}
	LRESULT OnSaveAs(UINT, INT nIdentifier, HWND)
	{
		CWaitCursor WaitCursor;
		const CStringA sTextA = Utf8StringFromString(m_TextEdit.GetValue());
		static const COMDLG_FILTERSPEC g_pFilter[] = 
		{
			{ _T("Markdown Files"), _T("*.md") },
			//{ _T("Markdown Files, Bzip2 Compressed"), _T("*.md.bz2") },
			{ _T("All Files"), _T("*.*") },
		};
		const CPath sPath = _CommonDialogHelper::QuerySavePath(m_hWnd, g_pFilter, _T("md"), _T("Output.md"));
		if(!_tcslen(sPath))
			return 0;
		LPCTSTR pszExtension = FindExtension(sPath);
		CAtlFile File;
		__C(File.Create(sPath, GENERIC_WRITE, FILE_SHARE_READ, CREATE_ALWAYS));
		_ATLTRY
		{
			//if(_tcsicmp(pszExtension, _T(".bz2")) == 0)
			//{
			//	CLocalObjectPtr<CBzip2Item> pItem;
			//	pItem->SetRawData((const BYTE*) (LPCSTR) sTextA, sTextA.GetLength());
			//	CHeapPtr<BYTE> pnData;
			//	SIZE_T nDataSize;
			//	pItem->GetData(pnData, nDataSize);
			//	__C(File.Write(pnData, (DWORD) nDataSize));
			//} else
			{
				__C(File.Write(sTextA, sTextA.GetLength() * sizeof (CHAR)));
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
};
