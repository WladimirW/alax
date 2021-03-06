////////////////////////////////////////////////////////////
// Copyright (C) Roman Ryltsov, 2008-2011
// Created by Roman Ryltsov roman@alax.info

#pragma once

#include "rodshow.h"
#include "romf.h"
#include <mmdeviceapi.h>
#include <mmreg.h>
#include <functiondiscoverykeys.h>
#include <propkey.h>
#include <devpkey.h>
#include <devicetopology.h>
#include <audioclient.h>
#include <endpointvolume.h>
#include <audiopolicy.h>
//#include <dsound.h>
#include "AboutDialog.h"

////////////////////////////////////////////////////////////
// CMainDialog

class CMainDialog : 
	public CDialogImpl<CMainDialog>,
	public CDialogResize<CMainDialog>
{
public:
	enum { IDD = IDD_MAIN };

BEGIN_MSG_MAP_EX(CMainDialog)
	//CHAIN_MSG_MAP(CMainDialog)
	CHAIN_MSG_MAP(CDialogResize<CMainDialog>)
	MSG_WM_INITDIALOG(OnInitDialog)
	MSG_WM_SYSCOMMAND(OnSysCommand)
	COMMAND_ID_HANDLER_EX(IDCANCEL, OnCommand)
	COMMAND_ID_HANDLER_EX(IDOK, OnCommand)
END_MSG_MAP()

BEGIN_DLGRESIZE_MAP(CMainDialog)
	DLGRESIZE_CONTROL(IDC_TEXT, DLSZ_SIZE_X | DLSZ_SIZE_Y)
	DLGRESIZE_CONTROL(IDOK, DLSZ_MOVE_X | DLSZ_MOVE_Y)
END_DLGRESIZE_MAP()

private:
	CDpiAwareness m_DpiAwareness;
	CFont m_TextFont;
	CRoEdit m_TextEdit;
	CFont m_ButtonFont;
	CButton m_CloseButton;

public:
// CMainDialog
	static BOOL IsWaveFormatExKey(const PROPERTYKEY& Key)
	{
		if(Key == PKEY_AudioEngine_DeviceFormat)
			return TRUE;
		if(Key == PKEY_AudioEngine_OEMFormat)
			return TRUE;
		class __declspec(uuid("{3D6E1656-2E50-4C4C-8D85-D0ACAE3C6C68}")) A;
		if(Key.fmtid == __uuidof(A) && (Key.pid == 2 || Key.pid == 3))
			return TRUE;
		class __declspec(uuid("{E4870E26-3CC5-4CD2-BA46-CA0A9A70ED04}")) B;
		if(Key.fmtid == __uuidof(B) && Key.pid == 0) // PKEY_AudioEngine_??? endpointkeys.h
			return TRUE;
		class __declspec(uuid("{624F56DE-FD24-473E-814A-DE40AACAED16}")) C;
		if(Key.fmtid == __uuidof(C) && Key.pid == 3)
			return TRUE;
		return FALSE;
	}
	static VOID FormatWaveFormatEx(const WAVEFORMATEX* pWaveFormatEx, SIZE_T nWaveFormatExSize, CRoArrayT<CString>& Array)
	{
		_A(nWaveFormatExSize >= sizeof (WAVEFORMATEX));
		Array.Add(AtlFormatString(_T("wFormatTag 0x%02X"), pWaveFormatEx->wFormatTag));
		Array.Add(AtlFormatString(_T("nChannels %d"), pWaveFormatEx->nChannels));
		Array.Add(AtlFormatString(_T("nSamplesPerSec %d"), pWaveFormatEx->nSamplesPerSec));
		Array.Add(AtlFormatString(_T("nAvgBytesPerSec %d"), pWaveFormatEx->nAvgBytesPerSec));
		Array.Add(AtlFormatString(_T("nBlockAlign %d"), pWaveFormatEx->nBlockAlign));
		Array.Add(AtlFormatString(_T("wBitsPerSample %d"), pWaveFormatEx->wBitsPerSample));
		Array.Add(AtlFormatString(_T("cbSize %d"), pWaveFormatEx->cbSize));
		if(nWaveFormatExSize < sizeof (WAVEFORMATEXTENSIBLE) || pWaveFormatEx->wFormatTag != WAVE_FORMAT_EXTENSIBLE)
			return;
		const WAVEFORMATEXTENSIBLE* pWaveFormatExtensible = (const WAVEFORMATEXTENSIBLE*) pWaveFormatEx;
		Array.Add(AtlFormatString(_T("wValidBitsPerSample %d"), pWaveFormatExtensible->Samples.wValidBitsPerSample));
		Array.Add(AtlFormatString(_T("dwChannelMask 0x%02X"), pWaveFormatExtensible->dwChannelMask));
		Array.Add(AtlFormatString(_T("SubFormat %ls"), _PersistHelper::StringFromIdentifier(pWaveFormatExtensible->SubFormat)));
	}

// Window Message Handler
	LRESULT OnInitDialog(HWND, LPARAM)
	{
		DlgResize_Init();
		SetIcon(AtlLoadIconImage(IDI_MODULE, LR_DEFAULTCOLOR, GetSystemMetrics(SM_CXICON), GetSystemMetrics(SM_CYICON)), TRUE);
		SetIcon(AtlLoadIconImage(IDI_MODULE, LR_DEFAULTCOLOR, GetSystemMetrics(SM_CXSMICON), GetSystemMetrics(SM_CYSMICON)), FALSE);
		CMenuHandle Menu = GetSystemMenu(FALSE);
		_W(Menu.AppendMenu(MF_SEPARATOR));
		_W(Menu.AppendMenu(MF_STRING, ID_APP_ABOUT, _T("&About...")));
		CAboutDialog::UpdateCaption(*this);
		m_TextEdit = GetDlgItem(IDC_TEXT);
		m_TextFont = m_DpiAwareness.ScaleFont(m_TextEdit.GetFont(), 11);
		m_TextEdit.SetFont(m_TextFont);
		m_CloseButton = GetDlgItem(IDOK);
		m_ButtonFont = m_DpiAwareness.ScaleFont(GetFont(), 9);
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
		_ATLTRY
		{
			CWaitCursor WaitCursor;
			CString sText;
			#pragma region The Enumeration
			_ATLTRY
			{
				CComPtr<IMMDeviceEnumerator> pMmDeviceEnumerator;
				__C(pMmDeviceEnumerator.CoCreateInstance(__uuidof(MMDeviceEnumerator)));
				CComPtr<IMMDeviceCollection> pMmDeviceCollection;
				__C(pMmDeviceEnumerator->EnumAudioEndpoints(eAll, DEVICE_STATEMASK_ALL, &pMmDeviceCollection));
				UINT nDeviceCount = 0;
				__C(pMmDeviceCollection->GetCount(&nDeviceCount));
				for(UINT nDeviceIndex = 0; nDeviceIndex < nDeviceCount; nDeviceIndex++)
					_ATLTRY
			 		{
						sText.AppendFormat(_T("Device %d:\r\n"), nDeviceIndex);
						CComPtr<IMMDevice> pMmDevice;
						__C(pMmDeviceCollection->Item(nDeviceIndex, &pMmDevice));
						CComHeapPtr<WCHAR> pszIdentifier;
						__C(pMmDevice->GetId(&pszIdentifier));
						sText.AppendFormat(_T("\t") _T("Identifier\t%ls\r\n"), pszIdentifier);
						#pragma region State
						DWORD nState = 0;
						__C(pMmDevice->GetState(&nState));
						static const CFlagNameT<DWORD> g_pDeviceStateMap[] = 
						{
							#define A(x) { x, #x },
							A(DEVICE_STATE_ACTIVE)
							A(DEVICE_STATE_DISABLED)
							A(DEVICE_STATE_NOTPRESENT)
							A(DEVICE_STATE_UNPLUGGED)
							#undef A
						};
						sText.AppendFormat(_T("\t") _T("State\t%s\t0x%02X\r\n"), FormatFlagsT(g_pDeviceStateMap, nState), nState);
						#pragma endregion 
						#pragma region Property Store
						sText.AppendFormat(_T("\t") _T("Properties:\r\n"));
						CComPtr<IPropertyStore> pPropertyStore;
						__C(pMmDevice->OpenPropertyStore(STGM_READ, &pPropertyStore));
						DWORD nPropertyCount = 0;
						__C(pPropertyStore->GetCount(&nPropertyCount));
						for(DWORD nPropertyIndex = 0; nPropertyIndex < nPropertyCount; nPropertyIndex++)
							_ATLTRY
							{
								PROPERTYKEY Key;
								__C(pPropertyStore->GetAt(nPropertyIndex, &Key));
								PROPVARIANT Value;
								PropVariantInit(&Value);
								__C(pPropertyStore->GetValue(Key, &Value));
								_ATLTRY
								{
									CString sKeyName;
									// NOTE: This is brought to you by regexp .+{PKEY_[^,]+}.+ -> A(\1)
									#pragma region Named SDK constants
									#define A(x) { &x, #x },
									#define B(x) { &reinterpret_cast<const PROPERTYKEY&>(x), #x },
									static const struct 
									{ 
										const PROPERTYKEY* pKey; 
										LPCSTR pszName; 
									} g_pMap[] = 
									{
										#pragma region functiondiscoverykeys.h
										A(PKEY_NAME)
										A(PKEY_Device_DeviceDesc)
										A(PKEY_Device_HardwareIds)
										A(PKEY_Device_CompatibleIds)
										A(PKEY_Device_Service)
										A(PKEY_Device_Class)
										A(PKEY_Device_ClassGuid)
										A(PKEY_Device_Driver)
										A(PKEY_Device_ConfigFlags)
										A(PKEY_Device_Manufacturer)
										A(PKEY_Device_FriendlyName)
										A(PKEY_Device_LocationInfo)
										A(PKEY_Device_PDOName)
										A(PKEY_Device_Capabilities)
										A(PKEY_Device_UINumber)
										A(PKEY_Device_UpperFilters)
										A(PKEY_Device_LowerFilters)
										A(PKEY_Device_BusTypeGuid)
										A(PKEY_Device_LegacyBusType)
										A(PKEY_Device_BusNumber)
										A(PKEY_Device_EnumeratorName)
										A(PKEY_Device_Security)
										A(PKEY_Device_SecuritySDS)
										A(PKEY_Device_DevType)
										A(PKEY_Device_Exclusive)
										A(PKEY_Device_Characteristics)
										A(PKEY_Device_Address)
										A(PKEY_Device_UINumberDescFormat)
										A(PKEY_Device_PowerData)
										A(PKEY_Device_RemovalPolicy)
										A(PKEY_Device_RemovalPolicyDefault)
										A(PKEY_Device_RemovalPolicyOverride)
										A(PKEY_Device_InstallState)
										A(PKEY_Device_LocationPaths)
										A(PKEY_Device_BaseContainerId)
										A(PKEY_Device_DevNodeStatus)
										A(PKEY_Device_ProblemCode)
										A(PKEY_Device_EjectionRelations)
										A(PKEY_Device_RemovalRelations)
										A(PKEY_Device_PowerRelations)
										A(PKEY_Device_BusRelations)
										A(PKEY_Device_Parent)
										A(PKEY_Device_Children)
										A(PKEY_Device_Siblings)
										A(PKEY_Device_TransportRelations)
										A(PKEY_Device_Reported)
										A(PKEY_Device_Legacy)
										A(PKEY_Device_InstanceId)
										A(PKEY_Device_ContainerId)
										A(PKEY_Device_ModelId)
										A(PKEY_Device_FriendlyNameAttributes)
										A(PKEY_Device_ManufacturerAttributes)
										A(PKEY_Device_PresenceNotForDevice)
										A(PKEY_Numa_Proximity_Domain)
										A(PKEY_Device_DHP_Rebalance_Policy)
										A(PKEY_Device_Numa_Node)
										A(PKEY_Device_BusReportedDeviceDesc)
										A(PKEY_Device_InstallInProgress)
										A(PKEY_Device_DriverDate)
										A(PKEY_Device_DriverVersion)
										A(PKEY_Device_DriverDesc)
										A(PKEY_Device_DriverInfPath)
										A(PKEY_Device_DriverInfSection)
										A(PKEY_Device_DriverInfSectionExt)
										A(PKEY_Device_MatchingDeviceId)
										A(PKEY_Device_DriverProvider)
										A(PKEY_Device_DriverPropPageProvider)
										A(PKEY_Device_DriverCoInstallers)
										A(PKEY_Device_ResourcePickerTags)
										A(PKEY_Device_ResourcePickerExceptions)
										A(PKEY_Device_DriverRank)
										A(PKEY_Device_DriverLogoLevel)
										A(PKEY_Device_NoConnectSound)
										A(PKEY_Device_GenericDriverInstalled)
										A(PKEY_Device_AdditionalSoftwareRequested)
										A(PKEY_Device_SafeRemovalRequired)
										A(PKEY_Device_SafeRemovalRequiredOverride)
										A(PKEY_DrvPkg_Model)
										A(PKEY_DrvPkg_VendorWebSite)
										A(PKEY_DrvPkg_DetailedDescription)
										A(PKEY_DrvPkg_DocumentationLink)
										A(PKEY_DrvPkg_Icon)
										A(PKEY_DrvPkg_BrandingIcon)
										A(PKEY_DeviceClass_UpperFilters)
										A(PKEY_DeviceClass_LowerFilters)
										A(PKEY_DeviceClass_Security)
										A(PKEY_DeviceClass_SecuritySDS)
										A(PKEY_DeviceClass_DevType)
										A(PKEY_DeviceClass_Exclusive)
										A(PKEY_DeviceClass_Characteristics)
										A(PKEY_DeviceClass_Name)
										A(PKEY_DeviceClass_ClassName)
										A(PKEY_DeviceClass_Icon)
										A(PKEY_DeviceClass_ClassInstaller)
										A(PKEY_DeviceClass_PropPageProvider)
										A(PKEY_DeviceClass_NoInstallClass)
										A(PKEY_DeviceClass_NoDisplayClass)
										A(PKEY_DeviceClass_SilentInstall)
										A(PKEY_DeviceClass_NoUseClass)
										A(PKEY_DeviceClass_DefaultService)
										A(PKEY_DeviceClass_IconPath)
										A(PKEY_DeviceClass_ClassCoInstallers)
										A(PKEY_DeviceInterface_FriendlyName)
										A(PKEY_DeviceInterface_Enabled)
										A(PKEY_DeviceInterface_ClassGuid)
										A(PKEY_DeviceInterfaceClass_DefaultInterface)
										#pragma endregion
										#pragma region functiondiscoverykeys_devpkey.h
										A(PKEY_NAME)
										A(PKEY_Device_DeviceDesc)
										A(PKEY_Device_HardwareIds)
										A(PKEY_Device_CompatibleIds)
										A(PKEY_Device_Service)
										A(PKEY_Device_Class)
										A(PKEY_Device_ClassGuid)
										A(PKEY_Device_Driver)
										A(PKEY_Device_ConfigFlags)
										A(PKEY_Device_Manufacturer)
										A(PKEY_Device_FriendlyName)
										A(PKEY_Device_LocationInfo)
										A(PKEY_Device_PDOName)
										A(PKEY_Device_Capabilities)
										A(PKEY_Device_UINumber)
										A(PKEY_Device_UpperFilters)
										A(PKEY_Device_LowerFilters)
										A(PKEY_Device_BusTypeGuid)
										A(PKEY_Device_LegacyBusType)
										A(PKEY_Device_BusNumber)
										A(PKEY_Device_EnumeratorName)
										A(PKEY_Device_Security)
										A(PKEY_Device_SecuritySDS)
										A(PKEY_Device_DevType)
										A(PKEY_Device_Exclusive)
										A(PKEY_Device_Characteristics)
										A(PKEY_Device_Address)
										A(PKEY_Device_UINumberDescFormat)
										A(PKEY_Device_PowerData)
										A(PKEY_Device_RemovalPolicy)
										A(PKEY_Device_RemovalPolicyDefault)
										A(PKEY_Device_RemovalPolicyOverride)
										A(PKEY_Device_InstallState)
										A(PKEY_Device_LocationPaths)
										A(PKEY_Device_BaseContainerId)
										A(PKEY_Device_DevNodeStatus)
										A(PKEY_Device_ProblemCode)
										A(PKEY_Device_EjectionRelations)
										A(PKEY_Device_RemovalRelations)
										A(PKEY_Device_PowerRelations)
										A(PKEY_Device_BusRelations)
										A(PKEY_Device_Parent)
										A(PKEY_Device_Children)
										A(PKEY_Device_Siblings)
										A(PKEY_Device_TransportRelations)
										A(PKEY_Device_Reported)
										A(PKEY_Device_Legacy)
										A(PKEY_Device_InstanceId)
										A(PKEY_Device_ContainerId)
										A(PKEY_Device_ModelId)
										A(PKEY_Device_FriendlyNameAttributes)
										A(PKEY_Device_ManufacturerAttributes)
										A(PKEY_Device_PresenceNotForDevice)
										A(PKEY_Numa_Proximity_Domain)
										A(PKEY_Device_DHP_Rebalance_Policy)
										A(PKEY_Device_Numa_Node)
										A(PKEY_Device_BusReportedDeviceDesc)
										A(PKEY_Device_InstallInProgress)
										A(PKEY_Device_DriverDate)
										A(PKEY_Device_DriverVersion)
										A(PKEY_Device_DriverDesc)
										A(PKEY_Device_DriverInfPath)
										A(PKEY_Device_DriverInfSection)
										A(PKEY_Device_DriverInfSectionExt)
										A(PKEY_Device_MatchingDeviceId)
										A(PKEY_Device_DriverProvider)
										A(PKEY_Device_DriverPropPageProvider)
										A(PKEY_Device_DriverCoInstallers)
										A(PKEY_Device_ResourcePickerTags)
										A(PKEY_Device_ResourcePickerExceptions)
										A(PKEY_Device_DriverRank)
										A(PKEY_Device_DriverLogoLevel)
										A(PKEY_Device_NoConnectSound)
										A(PKEY_Device_GenericDriverInstalled)
										A(PKEY_Device_AdditionalSoftwareRequested)
										A(PKEY_Device_SafeRemovalRequired)
										A(PKEY_Device_SafeRemovalRequiredOverride)
										A(PKEY_DrvPkg_Model)
										A(PKEY_DrvPkg_VendorWebSite)
										A(PKEY_DrvPkg_DetailedDescription)
										A(PKEY_DrvPkg_DocumentationLink)
										A(PKEY_DrvPkg_Icon)
										A(PKEY_DrvPkg_BrandingIcon)
										A(PKEY_DeviceClass_UpperFilters)
										A(PKEY_DeviceClass_LowerFilters)
										A(PKEY_DeviceClass_Security)
										A(PKEY_DeviceClass_SecuritySDS)
										A(PKEY_DeviceClass_DevType)
										A(PKEY_DeviceClass_Exclusive)
										A(PKEY_DeviceClass_Characteristics)
										A(PKEY_DeviceClass_Name)
										A(PKEY_DeviceClass_ClassName)
										A(PKEY_DeviceClass_Icon)
										A(PKEY_DeviceClass_ClassInstaller)
										A(PKEY_DeviceClass_PropPageProvider)
										A(PKEY_DeviceClass_NoInstallClass)
										A(PKEY_DeviceClass_NoDisplayClass)
										A(PKEY_DeviceClass_SilentInstall)
										A(PKEY_DeviceClass_NoUseClass)
										A(PKEY_DeviceClass_DefaultService)
										A(PKEY_DeviceClass_IconPath)
										A(PKEY_DeviceClass_ClassCoInstallers)
										A(PKEY_DeviceInterface_FriendlyName)
										A(PKEY_DeviceInterface_Enabled)
										A(PKEY_DeviceInterface_ClassGuid)
										A(PKEY_DeviceInterfaceClass_DefaultInterface)
										#pragma endregion
										#pragma region mmdeviceapi.h
										A(PKEY_AudioEndpoint_FormFactor)
										A(PKEY_AudioEndpoint_ControlPanelPageProvider)
										A(PKEY_AudioEndpoint_Association)
										A(PKEY_AudioEndpoint_PhysicalSpeakers)
										A(PKEY_AudioEndpoint_GUID)
										A(PKEY_AudioEndpoint_Disable_SysFx)
										A(PKEY_AudioEndpoint_FullRangeSpeakers)
										A(PKEY_AudioEndpoint_Supports_EventDriven_Mode)
										A(PKEY_AudioEndpoint_JackSubType)
										A(PKEY_AudioEngine_DeviceFormat)
										A(PKEY_AudioEngine_OEMFormat)
										#pragma endregion
										#pragma region propkey.h
										A(PKEY_Audio_ChannelCount)
										A(PKEY_Audio_Compression)
										A(PKEY_Audio_EncodingBitrate)
										A(PKEY_Audio_Format)
										A(PKEY_Audio_IsVariableBitRate)
										A(PKEY_Audio_PeakValue)
										A(PKEY_Audio_SampleRate)
										A(PKEY_Audio_SampleSize)
										A(PKEY_Audio_StreamName)
										A(PKEY_Audio_StreamNumber)
										A(PKEY_Calendar_Duration)
										A(PKEY_Calendar_IsOnline)
										A(PKEY_Calendar_IsRecurring)
										A(PKEY_Calendar_Location)
										A(PKEY_Calendar_OptionalAttendeeAddresses)
										A(PKEY_Calendar_OptionalAttendeeNames)
										A(PKEY_Calendar_OrganizerAddress)
										A(PKEY_Calendar_OrganizerName)
										A(PKEY_Calendar_ReminderTime)
										A(PKEY_Calendar_RequiredAttendeeAddresses)
										A(PKEY_Calendar_RequiredAttendeeNames)
										A(PKEY_Calendar_Resources)
										A(PKEY_Calendar_ResponseStatus)
										A(PKEY_Calendar_ShowTimeAs)
										A(PKEY_Calendar_ShowTimeAsText)
										A(PKEY_Communication_AccountName)
										A(PKEY_Communication_DateItemExpires)
										A(PKEY_Communication_FollowupIconIndex)
										A(PKEY_Communication_HeaderItem)
										A(PKEY_Communication_PolicyTag)
										A(PKEY_Communication_SecurityFlags)
										A(PKEY_Communication_Suffix)
										A(PKEY_Communication_TaskStatus)
										A(PKEY_Communication_TaskStatusText)
										A(PKEY_Computer_DecoratedFreeSpace)
										A(PKEY_Contact_Anniversary)
										A(PKEY_Contact_AssistantName)
										A(PKEY_Contact_AssistantTelephone)
										A(PKEY_Contact_Birthday)
										A(PKEY_Contact_BusinessAddress)
										A(PKEY_Contact_BusinessAddressCity)
										A(PKEY_Contact_BusinessAddressCountry)
										A(PKEY_Contact_BusinessAddressPostalCode)
										A(PKEY_Contact_BusinessAddressPostOfficeBox)
										A(PKEY_Contact_BusinessAddressState)
										A(PKEY_Contact_BusinessAddressStreet)
										A(PKEY_Contact_BusinessFaxNumber)
										A(PKEY_Contact_BusinessHomePage)
										A(PKEY_Contact_BusinessTelephone)
										A(PKEY_Contact_CallbackTelephone)
										A(PKEY_Contact_CarTelephone)
										A(PKEY_Contact_Children)
										A(PKEY_Contact_CompanyMainTelephone)
										A(PKEY_Contact_Department)
										A(PKEY_Contact_EmailAddress)
										A(PKEY_Contact_EmailAddress2)
										A(PKEY_Contact_EmailAddress3)
										A(PKEY_Contact_EmailAddresses)
										A(PKEY_Contact_EmailName)
										A(PKEY_Contact_FileAsName)
										A(PKEY_Contact_FirstName)
										A(PKEY_Contact_FullName)
										A(PKEY_Contact_Gender)
										A(PKEY_Contact_GenderValue)
										A(PKEY_Contact_Hobbies)
										A(PKEY_Contact_HomeAddress)
										A(PKEY_Contact_HomeAddressCity)
										A(PKEY_Contact_HomeAddressCountry)
										A(PKEY_Contact_HomeAddressPostalCode)
										A(PKEY_Contact_HomeAddressPostOfficeBox)
										A(PKEY_Contact_HomeAddressState)
										A(PKEY_Contact_HomeAddressStreet)
										A(PKEY_Contact_HomeFaxNumber)
										A(PKEY_Contact_HomeTelephone)
										A(PKEY_Contact_IMAddress)
										A(PKEY_Contact_Initials)
										A(PKEY_Contact_JA_CompanyNamePhonetic)
										A(PKEY_Contact_JA_FirstNamePhonetic)
										A(PKEY_Contact_JA_LastNamePhonetic)
										A(PKEY_Contact_JobTitle)
										A(PKEY_Contact_Label)
										A(PKEY_Contact_LastName)
										A(PKEY_Contact_MailingAddress)
										A(PKEY_Contact_MiddleName)
										A(PKEY_Contact_MobileTelephone)
										A(PKEY_Contact_NickName)
										A(PKEY_Contact_OfficeLocation)
										A(PKEY_Contact_OtherAddress)
										A(PKEY_Contact_OtherAddressCity)
										A(PKEY_Contact_OtherAddressCountry)
										A(PKEY_Contact_OtherAddressPostalCode)
										A(PKEY_Contact_OtherAddressPostOfficeBox)
										A(PKEY_Contact_OtherAddressState)
										A(PKEY_Contact_OtherAddressStreet)
										A(PKEY_Contact_PagerTelephone)
										A(PKEY_Contact_PersonalTitle)
										A(PKEY_Contact_PrimaryAddressCity)
										A(PKEY_Contact_PrimaryAddressCountry)
										A(PKEY_Contact_PrimaryAddressPostalCode)
										A(PKEY_Contact_PrimaryAddressPostOfficeBox)
										A(PKEY_Contact_PrimaryAddressState)
										A(PKEY_Contact_PrimaryAddressStreet)
										A(PKEY_Contact_PrimaryEmailAddress)
										A(PKEY_Contact_PrimaryTelephone)
										A(PKEY_Contact_Profession)
										A(PKEY_Contact_SpouseName)
										A(PKEY_Contact_Suffix)
										A(PKEY_Contact_TelexNumber)
										A(PKEY_Contact_TTYTDDTelephone)
										A(PKEY_Contact_WebPage)
										A(PKEY_AcquisitionID)
										A(PKEY_ApplicationName)
										A(PKEY_Author)
										A(PKEY_Capacity)
										A(PKEY_Category)
										A(PKEY_Comment)
										A(PKEY_Company)
										A(PKEY_ComputerName)
										A(PKEY_ContainedItems)
										A(PKEY_ContentStatus)
										A(PKEY_ContentType)
										A(PKEY_Copyright)
										A(PKEY_DateAccessed)
										A(PKEY_DateAcquired)
										A(PKEY_DateArchived)
										A(PKEY_DateCompleted)
										A(PKEY_DateCreated)
										A(PKEY_DateImported)
										A(PKEY_DateModified)
										A(PKEY_DueDate)
										A(PKEY_EndDate)
										A(PKEY_FileAllocationSize)
										A(PKEY_FileAttributes)
										A(PKEY_FileCount)
										A(PKEY_FileDescription)
										A(PKEY_FileExtension)
										A(PKEY_FileFRN)
										A(PKEY_FileName)
										A(PKEY_FileOwner)
										A(PKEY_FileVersion)
										A(PKEY_FindData)
										A(PKEY_FlagColor)
										A(PKEY_FlagColorText)
										A(PKEY_FlagStatus)
										A(PKEY_FlagStatusText)
										A(PKEY_FreeSpace)
										A(PKEY_FullText)
										A(PKEY_Identity)
										A(PKEY_Identity_Blob)
										A(PKEY_Identity_DisplayName)
										A(PKEY_Identity_IsMeIdentity)
										A(PKEY_Identity_PrimaryEmailAddress)
										A(PKEY_Identity_ProviderID)
										A(PKEY_Identity_UniqueID)
										A(PKEY_Identity_UserName)
										A(PKEY_IdentityProvider_Name)
										A(PKEY_IdentityProvider_Picture)
										A(PKEY_ImageParsingName)
										A(PKEY_Importance)
										A(PKEY_ImportanceText)
										A(PKEY_IsAttachment)
										A(PKEY_IsDefaultNonOwnerSaveLocation)
										A(PKEY_IsDefaultSaveLocation)
										A(PKEY_IsDeleted)
										A(PKEY_IsEncrypted)
										A(PKEY_IsFlagged)
										A(PKEY_IsFlaggedComplete)
										A(PKEY_IsIncomplete)
										A(PKEY_IsLocationSupported)
										A(PKEY_IsPinnedToNameSpaceTree)
										A(PKEY_IsRead)
										A(PKEY_IsSearchOnlyItem)
										A(PKEY_IsSendToTarget)
										A(PKEY_IsShared)
										A(PKEY_ItemAuthors)
										A(PKEY_ItemClassType)
										A(PKEY_ItemDate)
										A(PKEY_ItemFolderNameDisplay)
										A(PKEY_ItemFolderPathDisplay)
										A(PKEY_ItemFolderPathDisplayNarrow)
										A(PKEY_ItemName)
										A(PKEY_ItemNameDisplay)
										A(PKEY_ItemNamePrefix)
										A(PKEY_ItemParticipants)
										A(PKEY_ItemPathDisplay)
										A(PKEY_ItemPathDisplayNarrow)
										A(PKEY_ItemType)
										A(PKEY_ItemTypeText)
										A(PKEY_ItemUrl)
										A(PKEY_Keywords)
										A(PKEY_Kind)
										A(PKEY_KindText)
										A(PKEY_Language)
										A(PKEY_MileageInformation)
										A(PKEY_MIMEType)
										A(PKEY_Null)
										A(PKEY_OfflineAvailability)
										A(PKEY_OfflineStatus)
										A(PKEY_OriginalFileName)
										A(PKEY_OwnerSID)
										A(PKEY_ParentalRating)
										A(PKEY_ParentalRatingReason)
										A(PKEY_ParentalRatingsOrganization)
										A(PKEY_ParsingBindContext)
										A(PKEY_ParsingName)
										A(PKEY_ParsingPath)
										A(PKEY_PerceivedType)
										A(PKEY_PercentFull)
										A(PKEY_Priority)
										A(PKEY_PriorityText)
										A(PKEY_Project)
										A(PKEY_ProviderItemID)
										A(PKEY_Rating)
										A(PKEY_RatingText)
										A(PKEY_Sensitivity)
										A(PKEY_SensitivityText)
										A(PKEY_SFGAOFlags)
										A(PKEY_SharedWith)
										A(PKEY_ShareUserRating)
										A(PKEY_SharingStatus)
										A(PKEY_Shell_OmitFromView)
										A(PKEY_SimpleRating)
										A(PKEY_Size)
										A(PKEY_SoftwareUsed)
										A(PKEY_SourceItem)
										A(PKEY_StartDate)
										A(PKEY_Status)
										A(PKEY_Subject)
										A(PKEY_Thumbnail)
										A(PKEY_ThumbnailCacheId)
										A(PKEY_ThumbnailStream)
										A(PKEY_Title)
										A(PKEY_TotalFileSize)
										A(PKEY_Trademarks)
										A(PKEY_Device_PrinterURL)
										A(PKEY_DeviceInterface_PrinterDriverDirectory)
										A(PKEY_DeviceInterface_PrinterDriverName)
										A(PKEY_DeviceInterface_PrinterName)
										A(PKEY_DeviceInterface_PrinterPortName)
										A(PKEY_Devices_BatteryLife)
										A(PKEY_Devices_BatteryPlusCharging)
										A(PKEY_Devices_BatteryPlusChargingText)
										A(PKEY_Devices_Category_Desc_Singular)
										A(PKEY_Devices_CategoryGroup_Desc)
										A(PKEY_Devices_Category_Desc_Plural)
										A(PKEY_Devices_ChargingState)
										A(PKEY_Devices_IsConnected)
										A(PKEY_Devices_ContainerId)
										A(PKEY_Devices_DefaultTooltip)
										A(PKEY_Devices_DeviceDescription1)
										A(PKEY_Devices_DeviceDescription2)
										A(PKEY_Devices_DiscoveryMethod)
										A(PKEY_Devices_FriendlyName)
										A(PKEY_Devices_FunctionPaths)
										A(PKEY_Devices_InterfacePaths)
										A(PKEY_Devices_IsDefaultDevice)
										A(PKEY_Devices_IsNetworkDevice)
										A(PKEY_Devices_IsSharedDevice)
										A(PKEY_Devices_IsSoftwareInstalling)
										A(PKEY_Devices_LaunchDeviceStageFromExplorer)
										A(PKEY_Devices_IsLocalMachine)
										A(PKEY_Devices_Manufacturer)
										A(PKEY_Devices_MissedCalls)
										A(PKEY_Devices_ModelName)
										A(PKEY_Devices_ModelNumber)
										A(PKEY_Devices_NetworkedTooltip)
										A(PKEY_Devices_NetworkName)
										A(PKEY_Devices_NetworkType)
										A(PKEY_Devices_NewPictures)
										A(PKEY_Devices_Notification)
										A(PKEY_Devices_Notification_LowBattery)
										A(PKEY_Devices_Notification_MissedCall)
										A(PKEY_Devices_Notification_NewMessage)
										A(PKEY_Devices_Notification_NewVoicemail)
										A(PKEY_Devices_Notification_StorageFull)
										A(PKEY_Devices_Notification_StorageFullLinkText)
										A(PKEY_Devices_NotificationStore)
										A(PKEY_Devices_IsNotWorkingProperly)
										A(PKEY_Devices_IsPaired)
										A(PKEY_Devices_PrimaryCategory)
										A(PKEY_Devices_Roaming)
										A(PKEY_Devices_SafeRemovalRequired)
										A(PKEY_Devices_SharedTooltip)
										A(PKEY_Devices_SignalStrength)
										A(PKEY_Devices_Status1)
										A(PKEY_Devices_Status2)
										A(PKEY_Devices_StorageCapacity)
										A(PKEY_Devices_StorageFreeSpace)
										A(PKEY_Devices_StorageFreeSpacePercent)
										A(PKEY_Devices_TextMessages)
										A(PKEY_Devices_Voicemail)
										A(PKEY_Document_ByteCount)
										A(PKEY_Document_CharacterCount)
										A(PKEY_Document_ClientID)
										A(PKEY_Document_Contributor)
										A(PKEY_Document_DateCreated)
										A(PKEY_Document_DatePrinted)
										A(PKEY_Document_DateSaved)
										A(PKEY_Document_Division)
										A(PKEY_Document_DocumentID)
										A(PKEY_Document_HiddenSlideCount)
										A(PKEY_Document_LastAuthor)
										A(PKEY_Document_LineCount)
										A(PKEY_Document_Manager)
										A(PKEY_Document_MultimediaClipCount)
										A(PKEY_Document_NoteCount)
										A(PKEY_Document_PageCount)
										A(PKEY_Document_ParagraphCount)
										A(PKEY_Document_PresentationFormat)
										A(PKEY_Document_RevisionNumber)
										A(PKEY_Document_Security)
										A(PKEY_Document_SlideCount)
										A(PKEY_Document_Template)
										A(PKEY_Document_TotalEditingTime)
										A(PKEY_Document_Version)
										A(PKEY_Document_WordCount)
										A(PKEY_DRM_DatePlayExpires)
										A(PKEY_DRM_DatePlayStarts)
										A(PKEY_DRM_Description)
										A(PKEY_DRM_IsProtected)
										A(PKEY_DRM_PlayCount)
										A(PKEY_GPS_Altitude)
										A(PKEY_GPS_AltitudeDenominator)
										A(PKEY_GPS_AltitudeNumerator)
										A(PKEY_GPS_AltitudeRef)
										A(PKEY_GPS_AreaInformation)
										A(PKEY_GPS_Date)
										A(PKEY_GPS_DestBearing)
										A(PKEY_GPS_DestBearingDenominator)
										A(PKEY_GPS_DestBearingNumerator)
										A(PKEY_GPS_DestBearingRef)
										A(PKEY_GPS_DestDistance)
										A(PKEY_GPS_DestDistanceDenominator)
										A(PKEY_GPS_DestDistanceNumerator)
										A(PKEY_GPS_DestDistanceRef)
										A(PKEY_GPS_DestLatitude)
										A(PKEY_GPS_DestLatitudeDenominator)
										A(PKEY_GPS_DestLatitudeNumerator)
										A(PKEY_GPS_DestLatitudeRef)
										A(PKEY_GPS_DestLongitude)
										A(PKEY_GPS_DestLongitudeDenominator)
										A(PKEY_GPS_DestLongitudeNumerator)
										A(PKEY_GPS_DestLongitudeRef)
										A(PKEY_GPS_Differential)
										A(PKEY_GPS_DOP)
										A(PKEY_GPS_DOPDenominator)
										A(PKEY_GPS_DOPNumerator)
										A(PKEY_GPS_ImgDirection)
										A(PKEY_GPS_ImgDirectionDenominator)
										A(PKEY_GPS_ImgDirectionNumerator)
										A(PKEY_GPS_ImgDirectionRef)
										A(PKEY_GPS_Latitude)
										A(PKEY_GPS_LatitudeDenominator)
										A(PKEY_GPS_LatitudeNumerator)
										A(PKEY_GPS_LatitudeRef)
										A(PKEY_GPS_Longitude)
										A(PKEY_GPS_LongitudeDenominator)
										A(PKEY_GPS_LongitudeNumerator)
										A(PKEY_GPS_LongitudeRef)
										A(PKEY_GPS_MapDatum)
										A(PKEY_GPS_MeasureMode)
										A(PKEY_GPS_ProcessingMethod)
										A(PKEY_GPS_Satellites)
										A(PKEY_GPS_Speed)
										A(PKEY_GPS_SpeedDenominator)
										A(PKEY_GPS_SpeedNumerator)
										A(PKEY_GPS_SpeedRef)
										A(PKEY_GPS_Status)
										A(PKEY_GPS_Track)
										A(PKEY_GPS_TrackDenominator)
										A(PKEY_GPS_TrackNumerator)
										A(PKEY_GPS_TrackRef)
										A(PKEY_GPS_VersionID)
										A(PKEY_Image_BitDepth)
										A(PKEY_Image_ColorSpace)
										A(PKEY_Image_CompressedBitsPerPixel)
										A(PKEY_Image_CompressedBitsPerPixelDenominator)
										A(PKEY_Image_CompressedBitsPerPixelNumerator)
										A(PKEY_Image_Compression)
										A(PKEY_Image_CompressionText)
										A(PKEY_Image_Dimensions)
										A(PKEY_Image_HorizontalResolution)
										A(PKEY_Image_HorizontalSize)
										A(PKEY_Image_ImageID)
										A(PKEY_Image_ResolutionUnit)
										A(PKEY_Image_VerticalResolution)
										A(PKEY_Image_VerticalSize)
										A(PKEY_Journal_Contacts)
										A(PKEY_Journal_EntryType)
										A(PKEY_LayoutPattern_ContentViewModeForBrowse)
										A(PKEY_LayoutPattern_ContentViewModeForSearch)
										A(PKEY_Link_Arguments)
										A(PKEY_Link_Comment)
										A(PKEY_Link_DateVisited)
										A(PKEY_Link_Description)
										A(PKEY_Link_Status)
										A(PKEY_Link_TargetExtension)
										A(PKEY_Link_TargetParsingPath)
										A(PKEY_Link_TargetSFGAOFlags)
										A(PKEY_Media_AuthorUrl)
										A(PKEY_Media_AverageLevel)
										A(PKEY_Media_ClassPrimaryID)
										A(PKEY_Media_ClassSecondaryID)
										A(PKEY_Media_CollectionGroupID)
										A(PKEY_Media_CollectionID)
										A(PKEY_Media_ContentDistributor)
										A(PKEY_Media_ContentID)
										A(PKEY_Media_CreatorApplication)
										A(PKEY_Media_CreatorApplicationVersion)
										A(PKEY_Media_DateEncoded)
										A(PKEY_Media_DateReleased)
										A(PKEY_Media_Duration)
										A(PKEY_Media_DVDID)
										A(PKEY_Media_EncodedBy)
										A(PKEY_Media_EncodingSettings)
										A(PKEY_Media_FrameCount)
										A(PKEY_Media_MCDI)
										A(PKEY_Media_MetadataContentProvider)
										A(PKEY_Media_Producer)
										A(PKEY_Media_PromotionUrl)
										A(PKEY_Media_ProtectionType)
										A(PKEY_Media_ProviderRating)
										A(PKEY_Media_ProviderStyle)
										A(PKEY_Media_Publisher)
										A(PKEY_Media_SubscriptionContentId)
										A(PKEY_Media_SubTitle)
										A(PKEY_Media_UniqueFileIdentifier)
										A(PKEY_Media_UserNoAutoInfo)
										A(PKEY_Media_UserWebUrl)
										A(PKEY_Media_Writer)
										A(PKEY_Media_Year)
										A(PKEY_Message_AttachmentContents)
										A(PKEY_Message_AttachmentNames)
										A(PKEY_Message_BccAddress)
										A(PKEY_Message_BccName)
										A(PKEY_Message_CcAddress)
										A(PKEY_Message_CcName)
										A(PKEY_Message_ConversationID)
										A(PKEY_Message_ConversationIndex)
										A(PKEY_Message_DateReceived)
										A(PKEY_Message_DateSent)
										A(PKEY_Message_Flags)
										A(PKEY_Message_FromAddress)
										A(PKEY_Message_FromName)
										A(PKEY_Message_HasAttachments)
										A(PKEY_Message_IsFwdOrReply)
										A(PKEY_Message_MessageClass)
										A(PKEY_Message_ProofInProgress)
										A(PKEY_Message_SenderAddress)
										A(PKEY_Message_SenderName)
										A(PKEY_Message_Store)
										A(PKEY_Message_ToAddress)
										A(PKEY_Message_ToDoFlags)
										A(PKEY_Message_ToDoTitle)
										A(PKEY_Message_ToName)
										A(PKEY_Music_AlbumArtist)
										A(PKEY_Music_AlbumID)
										A(PKEY_Music_AlbumTitle)
										A(PKEY_Music_Artist)
										A(PKEY_Music_BeatsPerMinute)
										A(PKEY_Music_Composer)
										A(PKEY_Music_Conductor)
										A(PKEY_Music_ContentGroupDescription)
										A(PKEY_Music_DisplayArtist)
										A(PKEY_Music_Genre)
										A(PKEY_Music_InitialKey)
										A(PKEY_Music_IsCompilation)
										A(PKEY_Music_Lyrics)
										A(PKEY_Music_Mood)
										A(PKEY_Music_PartOfSet)
										A(PKEY_Music_Period)
										A(PKEY_Music_SynchronizedLyrics)
										A(PKEY_Music_TrackNumber)
										A(PKEY_Note_Color)
										A(PKEY_Note_ColorText)
										A(PKEY_Photo_Aperture)
										A(PKEY_Photo_ApertureDenominator)
										A(PKEY_Photo_ApertureNumerator)
										A(PKEY_Photo_Brightness)
										A(PKEY_Photo_BrightnessDenominator)
										A(PKEY_Photo_BrightnessNumerator)
										A(PKEY_Photo_CameraManufacturer)
										A(PKEY_Photo_CameraModel)
										A(PKEY_Photo_CameraSerialNumber)
										A(PKEY_Photo_Contrast)
										A(PKEY_Photo_ContrastText)
										A(PKEY_Photo_DateTaken)
										A(PKEY_Photo_DigitalZoom)
										A(PKEY_Photo_DigitalZoomDenominator)
										A(PKEY_Photo_DigitalZoomNumerator)
										A(PKEY_Photo_Event)
										A(PKEY_Photo_EXIFVersion)
										A(PKEY_Photo_ExposureBias)
										A(PKEY_Photo_ExposureBiasDenominator)
										A(PKEY_Photo_ExposureBiasNumerator)
										A(PKEY_Photo_ExposureIndex)
										A(PKEY_Photo_ExposureIndexDenominator)
										A(PKEY_Photo_ExposureIndexNumerator)
										A(PKEY_Photo_ExposureProgram)
										A(PKEY_Photo_ExposureProgramText)
										A(PKEY_Photo_ExposureTime)
										A(PKEY_Photo_ExposureTimeDenominator)
										A(PKEY_Photo_ExposureTimeNumerator)
										A(PKEY_Photo_Flash)
										A(PKEY_Photo_FlashEnergy)
										A(PKEY_Photo_FlashEnergyDenominator)
										A(PKEY_Photo_FlashEnergyNumerator)
										A(PKEY_Photo_FlashManufacturer)
										A(PKEY_Photo_FlashModel)
										A(PKEY_Photo_FlashText)
										A(PKEY_Photo_FNumber)
										A(PKEY_Photo_FNumberDenominator)
										A(PKEY_Photo_FNumberNumerator)
										A(PKEY_Photo_FocalLength)
										A(PKEY_Photo_FocalLengthDenominator)
										A(PKEY_Photo_FocalLengthInFilm)
										A(PKEY_Photo_FocalLengthNumerator)
										A(PKEY_Photo_FocalPlaneXResolution)
										A(PKEY_Photo_FocalPlaneXResolutionDenominator)
										A(PKEY_Photo_FocalPlaneXResolutionNumerator)
										A(PKEY_Photo_FocalPlaneYResolution)
										A(PKEY_Photo_FocalPlaneYResolutionDenominator)
										A(PKEY_Photo_FocalPlaneYResolutionNumerator)
										A(PKEY_Photo_GainControl)
										A(PKEY_Photo_GainControlDenominator)
										A(PKEY_Photo_GainControlNumerator)
										A(PKEY_Photo_GainControlText)
										A(PKEY_Photo_ISOSpeed)
										A(PKEY_Photo_LensManufacturer)
										A(PKEY_Photo_LensModel)
										A(PKEY_Photo_LightSource)
										A(PKEY_Photo_MakerNote)
										A(PKEY_Photo_MakerNoteOffset)
										A(PKEY_Photo_MaxAperture)
										A(PKEY_Photo_MaxApertureDenominator)
										A(PKEY_Photo_MaxApertureNumerator)
										A(PKEY_Photo_MeteringMode)
										A(PKEY_Photo_MeteringModeText)
										A(PKEY_Photo_Orientation)
										A(PKEY_Photo_OrientationText)
										A(PKEY_Photo_PeopleNames)
										A(PKEY_Photo_PhotometricInterpretation)
										A(PKEY_Photo_PhotometricInterpretationText)
										A(PKEY_Photo_ProgramMode)
										A(PKEY_Photo_ProgramModeText)
										A(PKEY_Photo_RelatedSoundFile)
										A(PKEY_Photo_Saturation)
										A(PKEY_Photo_SaturationText)
										A(PKEY_Photo_Sharpness)
										A(PKEY_Photo_SharpnessText)
										A(PKEY_Photo_ShutterSpeed)
										A(PKEY_Photo_ShutterSpeedDenominator)
										A(PKEY_Photo_ShutterSpeedNumerator)
										A(PKEY_Photo_SubjectDistance)
										A(PKEY_Photo_SubjectDistanceDenominator)
										A(PKEY_Photo_SubjectDistanceNumerator)
										A(PKEY_Photo_TagViewAggregate)
										A(PKEY_Photo_TranscodedForSync)
										A(PKEY_Photo_WhiteBalance)
										A(PKEY_Photo_WhiteBalanceText)
										A(PKEY_PropGroup_Advanced)
										A(PKEY_PropGroup_Audio)
										A(PKEY_PropGroup_Calendar)
										A(PKEY_PropGroup_Camera)
										A(PKEY_PropGroup_Contact)
										A(PKEY_PropGroup_Content)
										A(PKEY_PropGroup_Description)
										A(PKEY_PropGroup_FileSystem)
										A(PKEY_PropGroup_General)
										A(PKEY_PropGroup_GPS)
										A(PKEY_PropGroup_Image)
										A(PKEY_PropGroup_Media)
										A(PKEY_PropGroup_MediaAdvanced)
										A(PKEY_PropGroup_Message)
										A(PKEY_PropGroup_Music)
										A(PKEY_PropGroup_Origin)
										A(PKEY_PropGroup_PhotoAdvanced)
										A(PKEY_PropGroup_RecordedTV)
										A(PKEY_PropGroup_Video)
										A(PKEY_InfoTipText)
										A(PKEY_PropList_ConflictPrompt)
										A(PKEY_PropList_ContentViewModeForBrowse)
										A(PKEY_PropList_ContentViewModeForSearch)
										A(PKEY_PropList_ExtendedTileInfo)
										A(PKEY_PropList_FileOperationPrompt)
										A(PKEY_PropList_FullDetails)
										A(PKEY_PropList_InfoTip)
										A(PKEY_PropList_NonPersonal)
										A(PKEY_PropList_PreviewDetails)
										A(PKEY_PropList_PreviewTitle)
										A(PKEY_PropList_QuickTip)
										A(PKEY_PropList_TileInfo)
										A(PKEY_PropList_XPDetailsPanel)
										A(PKEY_RecordedTV_ChannelNumber)
										A(PKEY_RecordedTV_Credits)
										A(PKEY_RecordedTV_DateContentExpires)
										A(PKEY_RecordedTV_EpisodeName)
										A(PKEY_RecordedTV_IsATSCContent)
										A(PKEY_RecordedTV_IsClosedCaptioningAvailable)
										A(PKEY_RecordedTV_IsDTVContent)
										A(PKEY_RecordedTV_IsHDContent)
										A(PKEY_RecordedTV_IsRepeatBroadcast)
										A(PKEY_RecordedTV_IsSAP)
										A(PKEY_RecordedTV_NetworkAffiliation)
										A(PKEY_RecordedTV_OriginalBroadcastDate)
										A(PKEY_RecordedTV_ProgramDescription)
										A(PKEY_RecordedTV_RecordingTime)
										A(PKEY_RecordedTV_StationCallSign)
										A(PKEY_RecordedTV_StationName)
										A(PKEY_Search_AutoSummary)
										A(PKEY_Search_ContainerHash)
										A(PKEY_Search_Contents)
										A(PKEY_Search_EntryID)
										A(PKEY_Search_ExtendedProperties)
										A(PKEY_Search_GatherTime)
										A(PKEY_Search_HitCount)
										A(PKEY_Search_IsClosedDirectory)
										A(PKEY_Search_IsFullyContained)
										A(PKEY_Search_QueryFocusedSummary)
										A(PKEY_Search_QueryFocusedSummaryWithFallback)
										A(PKEY_Search_Rank)
										A(PKEY_Search_Store)
										A(PKEY_Search_UrlToIndex)
										A(PKEY_Search_UrlToIndexWithModificationTime)
										A(PKEY_DescriptionID)
										A(PKEY_InternalName)
										A(PKEY_Link_TargetSFGAOFlagsStrings)
										A(PKEY_Link_TargetUrl)
										A(PKEY_NamespaceCLSID)
										A(PKEY_Shell_SFGAOFlagsStrings)
										A(PKEY_AppUserModel_ExcludeFromShowInNewInstall)
										A(PKEY_AppUserModel_ID)
										A(PKEY_AppUserModel_IsDestListSeparator)
										A(PKEY_AppUserModel_PreventPinning)
										A(PKEY_AppUserModel_RelaunchCommand)
										A(PKEY_AppUserModel_RelaunchDisplayNameResource)
										A(PKEY_AppUserModel_RelaunchIconResource)
										A(PKEY_Software_DateLastUsed)
										A(PKEY_Software_ProductName)
										A(PKEY_Sync_Comments)
										A(PKEY_Sync_ConflictDescription)
										A(PKEY_Sync_ConflictFirstLocation)
										A(PKEY_Sync_ConflictSecondLocation)
										A(PKEY_Sync_HandlerCollectionID)
										A(PKEY_Sync_HandlerID)
										A(PKEY_Sync_HandlerName)
										A(PKEY_Sync_HandlerType)
										A(PKEY_Sync_HandlerTypeLabel)
										A(PKEY_Sync_ItemID)
										A(PKEY_Sync_ItemName)
										A(PKEY_Sync_ProgressPercentage)
										A(PKEY_Sync_State)
										A(PKEY_Sync_Status)
										A(PKEY_Task_BillingInformation)
										A(PKEY_Task_CompletionStatus)
										A(PKEY_Task_Owner)
										A(PKEY_Video_Compression)
										A(PKEY_Video_Director)
										A(PKEY_Video_EncodingBitrate)
										A(PKEY_Video_FourCC)
										A(PKEY_Video_FrameHeight)
										A(PKEY_Video_FrameRate)
										A(PKEY_Video_FrameWidth)
										A(PKEY_Video_HorizontalAspectRatio)
										A(PKEY_Video_SampleSize)
										A(PKEY_Video_StreamName)
										A(PKEY_Video_StreamNumber)
										A(PKEY_Video_TotalBitrate)
										A(PKEY_Video_TranscodedForSync)
										A(PKEY_Video_VerticalAspectRatio)
										A(PKEY_Volume_FileSystem)
										A(PKEY_Volume_IsMappedDrive)
										A(PKEY_Volume_IsRoot)
										#pragma endregion
										#pragma region devpkey.h
										B(DEVPKEY_NAME)
										B(DEVPKEY_Device_DeviceDesc)
										B(DEVPKEY_Device_HardwareIds)
										B(DEVPKEY_Device_CompatibleIds)
										B(DEVPKEY_Device_Service)
										B(DEVPKEY_Device_Class)
										B(DEVPKEY_Device_ClassGuid)
										B(DEVPKEY_Device_Driver)
										B(DEVPKEY_Device_ConfigFlags)
										B(DEVPKEY_Device_Manufacturer)
										B(DEVPKEY_Device_FriendlyName)
										B(DEVPKEY_Device_LocationInfo)
										B(DEVPKEY_Device_PDOName)
										B(DEVPKEY_Device_Capabilities)
										B(DEVPKEY_Device_UINumber)
										B(DEVPKEY_Device_UpperFilters)
										B(DEVPKEY_Device_LowerFilters)
										B(DEVPKEY_Device_BusTypeGuid)
										B(DEVPKEY_Device_LegacyBusType)
										B(DEVPKEY_Device_BusNumber)
										B(DEVPKEY_Device_EnumeratorName)
										B(DEVPKEY_Device_Security)
										B(DEVPKEY_Device_SecuritySDS)
										B(DEVPKEY_Device_DevType)
										B(DEVPKEY_Device_Exclusive)
										B(DEVPKEY_Device_Characteristics)
										B(DEVPKEY_Device_Address)
										B(DEVPKEY_Device_UINumberDescFormat)
										B(DEVPKEY_Device_PowerData)
										B(DEVPKEY_Device_RemovalPolicy)
										B(DEVPKEY_Device_RemovalPolicyDefault)
										B(DEVPKEY_Device_RemovalPolicyOverride)
										B(DEVPKEY_Device_InstallState)
										B(DEVPKEY_Device_LocationPaths)
										B(DEVPKEY_Device_BaseContainerId)
										B(DEVPKEY_Device_DevNodeStatus)
										B(DEVPKEY_Device_ProblemCode)
										B(DEVPKEY_Device_EjectionRelations)
										B(DEVPKEY_Device_RemovalRelations)
										B(DEVPKEY_Device_PowerRelations)
										B(DEVPKEY_Device_BusRelations)
										B(DEVPKEY_Device_Parent)
										B(DEVPKEY_Device_Children)
										B(DEVPKEY_Device_Siblings)
										B(DEVPKEY_Device_TransportRelations)
										B(DEVPKEY_Device_Reported)
										B(DEVPKEY_Device_Legacy)
										B(DEVPKEY_Device_InstanceId)
										B(DEVPKEY_Device_ContainerId)
										B(DEVPKEY_Device_ModelId)
										B(DEVPKEY_Device_FriendlyNameAttributes)
										B(DEVPKEY_Device_ManufacturerAttributes)
										B(DEVPKEY_Device_PresenceNotForDevice)
										B(DEVPKEY_Numa_Proximity_Domain)
										B(DEVPKEY_Device_DHP_Rebalance_Policy)
										B(DEVPKEY_Device_Numa_Node)
										B(DEVPKEY_Device_BusReportedDeviceDesc)
										B(DEVPKEY_Device_SessionId)
										B(DEVPKEY_Device_InstallDate)
										B(DEVPKEY_Device_FirstInstallDate)
										B(DEVPKEY_Device_DriverDate)
										B(DEVPKEY_Device_DriverVersion)
										B(DEVPKEY_Device_DriverDesc)
										B(DEVPKEY_Device_DriverInfPath)
										B(DEVPKEY_Device_DriverInfSection)
										B(DEVPKEY_Device_DriverInfSectionExt)
										B(DEVPKEY_Device_MatchingDeviceId)
										B(DEVPKEY_Device_DriverProvider)
										B(DEVPKEY_Device_DriverPropPageProvider)
										B(DEVPKEY_Device_DriverCoInstallers)
										B(DEVPKEY_Device_ResourcePickerTags)
										B(DEVPKEY_Device_ResourcePickerExceptions)
										B(DEVPKEY_Device_DriverRank)
										B(DEVPKEY_Device_DriverLogoLevel)
										B(DEVPKEY_Device_NoConnectSound)
										B(DEVPKEY_Device_GenericDriverInstalled)
										B(DEVPKEY_Device_AdditionalSoftwareRequested)
										B(DEVPKEY_Device_SafeRemovalRequired)
										B(DEVPKEY_Device_SafeRemovalRequiredOverride)
										B(DEVPKEY_DrvPkg_Model)
										B(DEVPKEY_DrvPkg_VendorWebSite)
										B(DEVPKEY_DrvPkg_DetailedDescription)
										B(DEVPKEY_DrvPkg_DocumentationLink)
										B(DEVPKEY_DrvPkg_Icon)
										B(DEVPKEY_DrvPkg_BrandingIcon)
										B(DEVPKEY_DeviceClass_UpperFilters)
										B(DEVPKEY_DeviceClass_LowerFilters)
										B(DEVPKEY_DeviceClass_Security)
										B(DEVPKEY_DeviceClass_SecuritySDS)
										B(DEVPKEY_DeviceClass_DevType)
										B(DEVPKEY_DeviceClass_Exclusive)
										B(DEVPKEY_DeviceClass_Characteristics)
										B(DEVPKEY_DeviceClass_Name)
										B(DEVPKEY_DeviceClass_ClassName)
										B(DEVPKEY_DeviceClass_Icon)
										B(DEVPKEY_DeviceClass_ClassInstaller)
										B(DEVPKEY_DeviceClass_PropPageProvider)
										B(DEVPKEY_DeviceClass_NoInstallClass)
										B(DEVPKEY_DeviceClass_NoDisplayClass)
										B(DEVPKEY_DeviceClass_SilentInstall)
										B(DEVPKEY_DeviceClass_NoUseClass)
										B(DEVPKEY_DeviceClass_DefaultService)
										B(DEVPKEY_DeviceClass_IconPath)
										B(DEVPKEY_DeviceClass_DHPRebalanceOptOut)
										B(DEVPKEY_DeviceClass_ClassCoInstallers)
										B(DEVPKEY_DeviceInterface_FriendlyName)
										B(DEVPKEY_DeviceInterface_Enabled)
										B(DEVPKEY_DeviceInterface_ClassGuid)
										B(DEVPKEY_DeviceInterfaceClass_DefaultInterface)
										B(DEVPKEY_DeviceDisplay_IsShowInDisconnectedState)
										B(DEVPKEY_DeviceDisplay_IsNotInterestingForDisplay)
										B(DEVPKEY_DeviceDisplay_Category)
										B(DEVPKEY_DeviceDisplay_UnpairUninstall)
										B(DEVPKEY_DeviceDisplay_RequiresUninstallElevation)
										B(DEVPKEY_DeviceDisplay_AlwaysShowDeviceAsConnected)
										#pragma endregion
									};
									#undef A
									#undef B
									#pragma endregion
									for(SIZE_T nIndex = 0; nIndex < DIM(g_pMap); nIndex++)
										if(g_pMap[nIndex].pKey->fmtid == Key.fmtid && g_pMap[nIndex].pKey->pid == Key.pid)
										{
											sKeyName = CA2CT(g_pMap[nIndex].pszName);
											break;
										}
									if(sKeyName.IsEmpty())
										sKeyName = AtlFormatString(_T("%ls, %d"), _PersistHelper::StringFromIdentifier(Key.fmtid), Key.pid);
									#pragma region String Value
									CString sValue;
									HRESULT nChangeTypeResult = E_FAIL;
									// NOTE: See http://msdn.microsoft.com/en-us/library/cc235506%28v=prot.10%29.aspx
									switch(Value.vt)
									{
									case VT_LPSTR:
										sValue = CA2CT(Value.pszVal);
										nChangeTypeResult = S_OK;
										break;
									case VT_LPWSTR:
										sValue = CW2CT(Value.pwszVal);
										nChangeTypeResult = S_OK;
										break;
									case VT_BLOB:
										sValue = AtlFormatString(_T("%d bytes of BLOB"), Value.blob.cbSize);
										if(Value.blob.cbSize)
										{
											sValue += _T(", ");
											CRoArrayT<CString> Array;
											static const SIZE_T g_nMaximalSize = 128;
											if(Value.blob.cbSize <= g_nMaximalSize)
											{
												for(ULONG nIndex = 0; nIndex < Value.blob.cbSize; nIndex++)
													_W(Array.Add(AtlFormatString(_T("%02X"), Value.blob.pBlobData[nIndex])) >= 0);
											} else
											{
												for(ULONG nIndex = 0; nIndex < g_nMaximalSize - 8; nIndex++)
													_W(Array.Add(AtlFormatString(_T("%02X"), Value.blob.pBlobData[nIndex])) >= 0);
												_W(Array.Add(_T("...")) >= 0);
												for(ULONG nIndex = 0; nIndex < 4; nIndex++)
													_W(Array.Add(AtlFormatString(_T("%02X"), Value.blob.pBlobData[Value.blob.cbSize - 4 + nIndex])) >= 0);
											}
											sValue += _StringHelper::Join(Array, _T(" "));
										}
										nChangeTypeResult = S_OK;
										break;
									case VT_CLSID:
										sValue = CW2CT(_PersistHelper::StringFromIdentifier(*Value.puuid));
										nChangeTypeResult = S_OK;
										break;
									}
									#pragma region Variant as String 
									CComVariant vValue;
									if(FAILED(nChangeTypeResult))
									{
										nChangeTypeResult = vValue.ChangeType(VT_BSTR, &reinterpret_cast<VARIANT&>(Value));
										if(SUCCEEDED(nChangeTypeResult))
											sValue = CW2CT(vValue.bstrVal);
										else
											sValue = _T("???");
									}
									#pragma endregion 
									#pragma endregion 
									#pragma region Variant Type
									static const CEnumerationNameT<VARTYPE> g_pVarTypeMap[] = 
									{
										#define A(x) { x, #x },
										A(VT_EMPTY)
										A(VT_NULL)
										A(VT_I2)
										A(VT_I4)
										A(VT_R4)
										A(VT_R8)
										A(VT_CY)
										A(VT_DATE)
										A(VT_BSTR)
										A(VT_DISPATCH)
										A(VT_ERROR)
										A(VT_BOOL)
										A(VT_VARIANT)
										A(VT_UNKNOWN)
										A(VT_DECIMAL)
										A(VT_I1)
										A(VT_UI1)
										A(VT_UI2)
										A(VT_UI4)
										A(VT_I8)
										A(VT_UI8)
										A(VT_INT)
										A(VT_UINT)
										A(VT_VOID)
										A(VT_HRESULT)
										A(VT_PTR)
										A(VT_SAFEARRAY)
										A(VT_CARRAY)
										A(VT_USERDEFINED)
										A(VT_LPSTR)
										A(VT_LPWSTR)
										A(VT_RECORD)
										A(VT_INT_PTR)
										A(VT_UINT_PTR)
										A(VT_FILETIME)
										A(VT_BLOB)
										A(VT_STREAM)
										A(VT_STORAGE)
										A(VT_STREAMED_OBJECT)
										A(VT_STORED_OBJECT)
										A(VT_BLOB_OBJECT)
										A(VT_CF)
										A(VT_CLSID)
										A(VT_VERSIONED_STREAM)
										#undef A
									};
									#pragma endregion 
									#pragma region Detail
									CString sDetail;
									if(Key == PKEY_AudioEndpoint_FormFactor && Value.vt == VT_UI4)
									{
										static const CEnumerationNameT<UINT32> g_pMap[] = 
										{
											#define A(x) { x, #x },
											A(RemoteNetworkDevice)
											A(Speakers)
											A(LineLevel)
											A(Headphones)
											A(Microphone)
											A(Headset)
											A(Handset)
											A(UnknownDigitalPassthrough)
											A(SPDIF)
											A(DigitalAudioDisplayDevice)
											A(UnknownFormFactor)
											#undef A
										};
										sDetail = FormatEnumerationT(g_pMap, Value.uintVal);
									} else
									if(IsWaveFormatExKey(Key) && Value.vt == VT_BLOB && Value.blob.cbSize >= sizeof (WAVEFORMATEX))
									{
										CRoArrayT<CString> Array;
										FormatWaveFormatEx((const WAVEFORMATEX*) Value.blob.pBlobData, Value.blob.cbSize, Array);
										sDetail = _StringHelper::Join(Array, _T("; "));
									}
									#pragma endregion
									sText.Append(_StringHelper::Join<CString>(6, _T("\t"), 
										_T(""),
										_T(""),
										sKeyName, 
										sValue,
										FormatEnumerationT(g_pVarTypeMap, Value.vt),
										sDetail,
										0) + _T("\r\n"));
								}
								_ATLCATCHALL()
								{
									_V(PropVariantClear(&Value));
									_ATLRETHROW;
								}
								__C(PropVariantClear(&Value));
							}
							_ATLCATCH(Exception)
							{
								_Z_ATLEXCEPTION(Exception);
								sText.AppendFormat(_T("\t\t") _T("Error 0x%08X\r\n"), (HRESULT) Exception);
							}
						#pragma endregion 
						#pragma region IDeviceTopology
						_ATLTRY
						{
							// TODO: Make it nice
							// NOTE: http://stackoverflow.com/questions/34025791/how-to-get-jack-information-of-audio-device-in-ms-windows-7
							CComPtr<IDeviceTopology> pDeviceTopology;
							__C(pMmDevice->Activate(__uuidof(IDeviceTopology), CLSCTX_ALL, NULL, (VOID**) &pDeviceTopology));
							HRESULT hr;
							CComPtr<IConnector> pConnector;
							hr = pDeviceTopology->GetConnector(0, &pConnector);
							if(SUCCEEDED(hr))
							{
								CComPtr<IConnector> connectedTo;
								hr = pConnector->GetConnectedTo(&connectedTo);
								if(SUCCEEDED(hr))
								{
									CComPtr<IPart> part;
									hr = connectedTo->QueryInterface(&part);
									if (SUCCEEDED(hr))
									{
										CComPtr<IKsJackDescription> jack;
										hr = part->Activate(CLSCTX_ALL, IID_PPV_ARGS(&jack));
										if(SUCCEEDED(hr))
										{
											sText.AppendFormat(_T("\t") _T("Device Topology\r\n"));
											UINT jackCount = 0;
											jack->GetJackCount(&jackCount);
											for(UINT j = 0; j < jackCount; j++)
											{
												KSJACK_DESCRIPTION desc = { 0 };
												jack->GetJackDescription(j, &desc);
												sText.AppendFormat(_T("\t") _T("\t") _T("ChannelMapping\t%i\r\n"), desc.ChannelMapping);
												sText.AppendFormat(_T("\t") _T("\t") _T("ConnectionType\t%i\r\n"), desc.ConnectionType);
												sText.AppendFormat(_T("\t") _T("\t") _T("IsConnected\t%i\r\n"), desc.IsConnected);
												sText.AppendFormat(_T("\t") _T("\t") _T("Color\t0x%08X\r\n"), desc.Color);
											}
										}
									}
								}
							}
						}
						_ATLCATCHALL()
						{
							_Z_EXCEPTION();
						}
						#pragma endregion
						#pragma region Activation
						sText.AppendFormat(_T("\t") _T("Activation") _T("\r\n"));
						static const CEnumerationNameT<IID> g_pMap[] = 
						{
							#define A(x) { __uuidof(x), #x },
							A(IAudioClient)
							A(IAudioEndpointVolume)
							A(IAudioMeterInformation)
							A(IAudioSessionManager)
							A(IAudioSessionManager2)
							A(IBaseFilter)
							A(IDeviceTopology)
							//A(IDirectSound)
							//A(IDirectSound8) 
							//A(IDirectSoundCapture)
							//A(IDirectSoundCapture8)
							A(IMFTrustedOutput)
							#undef A
						};
						for(auto&& Item: g_pMap)
						{
							CComPtr<IUnknown> pUnknown;
							const HRESULT nActivateResult = pMmDevice->Activate(Item.Value, CLSCTX_ALL, NULL, (VOID**) &pUnknown);
							CRoArrayT<CString> ArrayA;
							ArrayA.Add(CString(Item.pszName));
							ArrayA.Add(MF::FormatResult(nActivateResult));
							sText.AppendFormat(_T("\t") _T("\t") _T("%s") _T("\r\n"), _StringHelper::Join(ArrayA, _T("\t")));
							if(FAILED(nActivateResult))
								continue;
							if(Item.Value == __uuidof(IAudioClient))
							{
								const CComPtr<IAudioClient>& pAudioClient = reinterpret_cast<const CComPtr<IAudioClient>&>(pUnknown);
								WAVEFORMATEX* pWaveFormatEx;
								if(SUCCEEDED(pAudioClient->GetMixFormat(&pWaveFormatEx)))
								{
									ArrayA.RemoveAll();
									ArrayA.Add(_T("Mix Format"));
									CRoArrayT<CString> ArrayB;
									FormatWaveFormatEx(pWaveFormatEx, sizeof *pWaveFormatEx + pWaveFormatEx->cbSize, ArrayB);
									ArrayA.Add(_StringHelper::Join(ArrayB, _T("; ")));
									sText.AppendFormat(_T("\t") _T("\t") _T("\t") _T("%s") _T("\r\n"), _StringHelper::Join(ArrayA, _T("\t")));
								}
								// SUGG: Try explicitly well known formats like mono, stereo, 5.1, 7.1 at 48000 Hz, 16-bit, 24-bit and 32-bit IEEE float
							}
						}
						#pragma endregion 
					}
					_ATLCATCH(Exception)
					{
						_Z_ATLEXCEPTION(Exception);
						sText.AppendFormat(_T("\t") _T("Error 0x%08X\r\n"), (HRESULT) Exception);
					}
			}
			_ATLCATCH(Exception)
			{
				_Z_ATLEXCEPTION(Exception);
				sText.AppendFormat(_T("Error 0x%08X\r\n"), (HRESULT) Exception);
			}
			#pragma endregion 
			m_TextEdit.SetValue(sText);
		}
		_ATLCATCHALL()
		{
			_Z_EXCEPTION();
		}
		return TRUE;
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
	LRESULT OnCommand(UINT, INT nIdentifier, HWND)
	{
		_W(EndDialog(nIdentifier));
		return 0;
	}
};
