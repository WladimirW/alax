# System

 * Version: 10.0.14393, Windows 10, VER_SUITE_SINGLEUSERTS, VER_NT_WORKSTATION
 * Product: PRODUCT_PROFESSIONAL
 * Computer Name: `ANDREWPC`
 * User Name: `ANDREWPC\Andrew` 
 * Locale: System `en-GB`, User `en-GB`
 * Local Time: `13 November 2017 00:23:18`
 * Architecture: AMD/Intel x64 (x64 Application)
 * Processors: `8`, Active Mask `0xFF`
 * Page Size: `0x1000`
 * Application Address Space: `0x0000000000010000`..`0x00007FFFFFFEFFFF`
 * Physical Memory: `32,711` MB
 * Committed Memory Limit: `36,807` MB
 * Application Version: `1.0.0.520`

# Devices

## `GUID_DEVCLASS_MEDIA`

 * Blackmagic Audio
  * Instance: DECKLINK\AUDIO\5&1F50C5E2&0&0
  * DEVPKEY_Device_Manufacturer: Blackmagic Design
  * DEVPKEY_Device_DriverVersion: 10.9.7.0
 * Realtek High Definition Audio
  * Instance: HDAUDIO\FUNC_01&VEN_10EC&DEV_0900&SUBSYS_1462D821&REV_1000\4&234E0589&0&0001
  * DEVPKEY_Device_Manufacturer: Realtek
  * DEVPKEY_Device_DriverVersion: 6.0.1.8010
 * NVIDIA High Definition Audio
  * Instance: HDAUDIO\FUNC_01&VEN_10DE&DEV_0040&SUBSYS_14622847&REV_1001\5&B5635B8&0&0001
  * DEVPKEY_Device_Manufacturer: NVIDIA
  * DEVPKEY_Device_DriverVersion: 1.3.34.27
 * USB Audio Device
  * Instance: USB\VID_046D&PID_085E&MI_02\6&14F62E31&0&0002
  * DEVPKEY_Device_Manufacturer: (Generic USB Audio)
  * DEVPKEY_Device_DriverVersion: 10.0.14393.0
 * Blackmagic DeckLink 4K Pro
  * Instance: PCI\VEN_BDBD&DEV_A13D&SUBSYS_A13DBDBD&REV_00\4&B857930&0&0009
  * DEVPKEY_Device_Manufacturer: Blackmagic Design
  * DEVPKEY_Device_DriverVersion: 10.9.7.0
 * Blackmagic DeckLink WDM Streaming
  * Instance: DECKLINK\AVSTREAM\5&1F50C5E2&0&0
  * DEVPKEY_Device_Manufacturer: Blackmagic Design
  * DEVPKEY_Device_DriverVersion: 10.9.7.0
 * VB-Audio VoiceMeeter VAIO
  * Instance: ROOT\MEDIA\0000
  * DEVPKEY_Device_Manufacturer: VB-Audio Software
  * DEVPKEY_Device_DriverVersion: 1.0.3.5

# DeckLink API

## API Information

  * 64-Bit Integer `BMDDeckLinkAPIVersion`: `168363776` (`0xA090700`) // 10.9.7
  * String `BMDDeckLinkAPIRCTag`: `a2`
  * Flag (32-Bit Integer) `BMDDeckLinkAPIEngineeringMode`: `1` (`0x1`)

## DeckLink 4K Pro (DeckLink 4K Pro)

 * Model Name: DeckLink 4K Pro
 * Display Name: DeckLink 4K Pro
 * Interfaces:
  * `IDeckLink`
  * `IDeckLink_v8_0`
  * `IDeckLinkStatus`
  * `IDeckLinkInput`
  * `IDeckLinkInput_v7_1`
  * `IDeckLinkInput_v7_3`
  * `IDeckLinkInput_v7_6`
  * `IDeckLinkInput_v9_2`
  * `IDeckLinkOutput`
  * `IDeckLinkOutput_v7_1`
  * `IDeckLinkOutput_v7_3`
  * `IDeckLinkOutput_v7_6`
  * `IDeckLinkOutput_v9_9`
  * `IDeckLinkConfiguration`
  * `IDeckLinkConfiguration_v7_6`
  * `IDeckLinkConfiguration_v10_2`
  * `IDeckLinkConfiguration_v10_4`
  * `IDeckLinkAttributes`
  * `IDeckLinkKeyer`
  * `IDeckLinkDeckControl`
  * `IDeckLinkDeckControl_v7_9`
  * `IDeckLinkDeckControl_v8_1`

### Attributes

  * Flag (32-Bit Integer) `BMDDeckLinkSupportsInternalKeying`: `1` (`0x1`)
  * Flag (32-Bit Integer) `BMDDeckLinkSupportsExternalKeying`: `1` (`0x1`)
  * Flag (32-Bit Integer) `BMDDeckLinkSupportsHDKeying`: `1` (`0x1`)
  * Flag (32-Bit Integer) `BMDDeckLinkSupportsInputFormatDetection`: `1` (`0x1`)
  * Flag (32-Bit Integer) `BMDDeckLinkHasReferenceInput`: `1` (`0x1`)
  * Flag (32-Bit Integer) `BMDDeckLinkHasSerialPort`: `0` (`0x0`)
  * Flag (32-Bit Integer) `BMDDeckLinkHasVideoInputAntiAliasingFilter`: `0` (`0x0`)
  * Flag (32-Bit Integer) `BMDDeckLinkHasBypass`: `0` (`0x0`)
  * Flag (32-Bit Integer) `BMDDeckLinkSupportsClockTimingAdjustment`: `0` (`0x0`)
  * Flag (32-Bit Integer) `BMDDeckLinkSupportsFullDuplex`: `1` (`0x1`)
  * Flag (32-Bit Integer) `BMDDeckLinkSupportsFullFrameReferenceInputTimingOffset`: `1` (`0x1`)
  * Flag (32-Bit Integer) `BMDDeckLinkSupportsSMPTELevelAOutput`: `1` (`0x1`)
  * Flag (32-Bit Integer) `BMDDeckLinkHasAllAnalogOutputConnectionsActive`: `1` (`0x1`)
  * Flag (32-Bit Integer) `BMDDeckLinkSupportsAutoSwitchingPPsFOnInput`: `1` (`0x1`)
  * Flag (32-Bit Integer) `BMDDeckLinkSupportsUltraScope`: `0` (`0x0`)
  * Flag (32-Bit Integer) `BMDDeckLinkSupportsDualLinkSDI`: `1` (`0x1`)
  * Flag (32-Bit Integer) `BMDDeckLinkSupportsQuadLinkSDI`: `0` (`0x0`)
  * Flag (32-Bit Integer) `BMDDeckLinkSupportsIdleOutput`: `1` (`0x1`)
  * Flag (32-Bit Integer) `BMDDeckLinkHasLTCTimecodeInput`: `0` (`0x0`)
  * Flag (32-Bit Integer) `BMDDeckLinkSupportsAudioMixing`: `0` (`0x0`)
  * Flag (32-Bit Integer) `BMDDeckLinkSupportsDuplexModeConfiguration`: `0` (`0x0`)
  * Flag (32-Bit Integer) `BMDDeckLinkSupportsHDRMetadata`: `0` (`0x0`)
  * 64-Bit Integer `BMDDeckLinkMaximumAudioChannels`: `16` (`0x10`)
  * 64-Bit Integer `BMDDeckLinkNumberOfSubDevices`: `1` (`0x1`)
  * 64-Bit Integer `BMDDeckLinkSubDeviceIndex`: `0` (`0x0`)
  * 64-Bit Integer `BMDDeckLinkPersistentID`: `873645584` (`0x3412C610`)
  * 64-Bit Integer `BMDDeckLinkDeviceGroupID`: `873645584` (`0x3412C610`)
  * 64-Bit Integer `BMDDeckLinkTopologicalID`: `5112320` (`0x4E0200`)
  * 64-Bit Integer `BMDDeckLinkVideoOutputConnections`: `1` (`0x1`) // `bmdVideoConnectionSDI`
  * 64-Bit Integer `BMDDeckLinkVideoInputConnections`: `1` (`0x1`) // `bmdVideoConnectionSDI`
  * 64-Bit Integer `BMDDeckLinkAudioOutputConnections`: `1` (`0x1`) // `bmdAudioConnectionEmbedded`
  * 64-Bit Integer `BMDDeckLinkAudioInputConnections`: `1` (`0x1`) // `bmdAudioConnectionEmbedded`
  * 64-Bit Integer `BMDDeckLinkVideoIOSupport`: `3` (`0x3`)
  * 64-Bit Integer `BMDDeckLinkDeckControlConnections`: `0` (`0x0`)
  * 64-Bit Integer `BMDDeckLinkDeviceInterface`: `1885563168` (`0x70636920`)
  * 64-Bit Integer `BMDDeckLinkAudioInputRCAChannelCount`: `0` (`0x0`)
  * 64-Bit Integer `BMDDeckLinkAudioInputXLRChannelCount`: `0` (`0x0`)
  * 64-Bit Integer `BMDDeckLinkAudioOutputRCAChannelCount`: `0` (`0x0`)
  * 64-Bit Integer `BMDDeckLinkAudioOutputXLRChannelCount`: `0` (`0x0`)
  * 64-Bit Integer `BMDDeckLinkParentPCIBridgeBusNumber`: `268435455` (`0xFFFFFFF`)
  * String `BMDDeckLinkVendorName`: `Blackmagic`
  * String `BMDDeckLinkDisplayName`: `DeckLink 4K Pro`
  * String `BMDDeckLinkModelName`: `DeckLink 4K Pro`
  * String `BMDDeckLinkDeviceHandle`: `78:3412c610:00000000`

### Configuration

  * Flag (32-Bit Integer) `bmdDeckLinkConfigUse1080pNotPsF`: `1` (`0x1`)
  * Flag (32-Bit Integer) `bmdDeckLinkConfigFieldFlickerRemoval`: `1` (`0x1`)
  * Flag (32-Bit Integer) `bmdDeckLinkConfig444SDIVideoOutput`: `0` (`0x0`)
  * Flag (32-Bit Integer) `bmdDeckLinkConfigLowLatencyVideoOutput`: `0` (`0x0`)
  * Flag (32-Bit Integer) `bmdDeckLinkConfigSMPTELevelAOutput`: `0` (`0x0`)
  * Flag (32-Bit Integer) `bmdDeckLinkConfigVideoOutputUsesInternalClock`: `1` (`0x1`)
  * Flag (32-Bit Integer) `bmdDeckLinkConfigForceFullRange`: `0` (`0x0`)
  * 64-Bit Integer `bmdDeckLinkConfigVideoOutputConnection`: `1` (`0x1`) // `bmdVideoConnectionSDI`
  * 64-Bit Integer `bmdDeckLinkConfigVideoOutputConversionMode`: `1852796517` (`0x6E6F6E65` - `none`) // `bmdNoVideoOutputConversion`
  * 64-Bit Integer `bmdDeckLinkConfigReferenceInputTimingOffset`: `0` (`0x0`)
  * 64-Bit Integer `bmdDeckLinkConfigVideoOutputIdleOperation`: `1651269987` (`0x626C6163` - `blac`)
  * 64-Bit Integer `bmdDeckLinkConfigDefaultVideoOutputMode`: `1853125475` (`0x6E747363` - `ntsc`) // `bmdModeNTSC`
  * 64-Bit Integer `bmdDeckLinkConfigDefaultVideoOutputModeFlags`: `0` (`0x0`)
  * 64-Bit Integer `bmdDeckLinkConfigSDIOutputLinkConfiguration`: `1818453100` (`0x6C63646C` - `lcdl`)
  * Flag (32-Bit Integer) `bmdDeckLinkConfigSDIInput3DPayloadOverride`: `0` (`0x0`)
  * 64-Bit Integer `bmdDeckLinkConfigVideoInputConnection`: `1` (`0x1`) // `bmdVideoConnectionSDI`
  * 64-Bit Integer `bmdDeckLinkConfigVideoInputConversionMode`: `1852796517` (`0x6E6F6E65` - `none`) // `bmdNoVideoInputConversion`
  * 64-Bit Integer `bmdDeckLinkConfigVANCSourceLine1Mapping`: `0` (`0x0`)
  * 64-Bit Integer `bmdDeckLinkConfigVANCSourceLine2Mapping`: `0` (`0x0`)
  * 64-Bit Integer `bmdDeckLinkConfigVANCSourceLine3Mapping`: `0` (`0x0`)
  * 64-Bit Integer `bmdDeckLinkConfigCapturePassThroughMode`: `1885564014` (`0x70636C6E` - `pcln`)
  * 64-Bit Integer `bmdDeckLinkConfigAudioInputConnection`: `1` (`0x1`) // `bmdAudioConnectionEmbedded`
  * String `bmdDeckLinkConfigDeviceInformationLabel`: ``
  * String `bmdDeckLinkConfigDeviceInformationSerialNumber`: ``
  * String `bmdDeckLinkConfigDeviceInformationCompany`: ``
  * String `bmdDeckLinkConfigDeviceInformationPhone`: ``
  * String `bmdDeckLinkConfigDeviceInformationEmail`: ``
  * String `bmdDeckLinkConfigDeviceInformationDate`: ``
  * 64-Bit Integer `bmdDeckLinkConfigDeckControlConnection`: `1` (`0x1`)

### Status

  * 64-Bit Integer `bmdDeckLinkStatusDetectedVideoInputMode`: `879440437` (`0x346B3235`) // `bmdMode4K2160p25`
  * 64-Bit Integer `bmdDeckLinkStatusDetectedVideoInputFlags`: `0` (`0x0`)
  * 64-Bit Integer `bmdDeckLinkStatusLockedLinks`: `48` (`0x30`)
  * 64-Bit Integer `bmdDeckLinkStatusCurrentVideoInputMode`: `842231923` (`0x32337073`) // `bmdModeHD1080p2398`
  * 64-Bit Integer `bmdDeckLinkStatusCurrentVideoInputPixelFormat`: `1983000880` (`0x76323130`) // `bmdFormat10BitYUV`
  * 64-Bit Integer `bmdDeckLinkStatusCurrentVideoInputFlags`: `0` (`0x0`)
  * 64-Bit Integer `bmdDeckLinkStatusCurrentVideoOutputMode`: `879440437` (`0x346B3235`) // `bmdMode4K2160p25`
  * 64-Bit Integer `bmdDeckLinkStatusCurrentVideoOutputFlags`: `0` (`0x0`)
  * 64-Bit Integer `bmdDeckLinkStatusPCIExpressLinkWidth`: `4` (`0x4`)
  * 64-Bit Integer `bmdDeckLinkStatusPCIExpressLinkSpeed`: `2` (`0x2`)
  * 64-Bit Integer `bmdDeckLinkStatusLastVideoOutputPixelFormat`: `1983000880` (`0x76323130`) // `bmdFormat10BitYUV`
  * 64-Bit Integer `bmdDeckLinkStatusReferenceSignalMode`: `1769303659` (`0x69756E6B`) // `bmdModeUnknown`
  * 64-Bit Integer `bmdDeckLinkStatusReferenceSignalFlags`: `0` (`0x0`)
  * 64-Bit Integer `bmdDeckLinkStatusDuplexMode`: `1717859696` (`0x66647570`) // `bmdDuplexStatusFullDuplex`
  * 64-Bit Integer `bmdDeckLinkStatusBusy`: `0` (`0x0`)
  * Flag (32-Bit Integer) `bmdDeckLinkStatusVideoInputSignalLocked`: `1` (`0x1`)
  * Flag (32-Bit Integer) `bmdDeckLinkStatusReferenceSignalLocked`: `0` (`0x0`)

### Input Display Modes

 * NTSC:
  * Mode: `bmdModeNTSC` (`ntsc`)
  * Resolution: `720` x `486`
  * Frame Duration: `1001` / `30000` (`29.970` fps, `33 3666` per frame)
  * Field Dominance: `bmdLowerFieldFirst` (`lowr`)
  * Flags: `bmdDisplayModeColorspaceRec601`
  * Pixel Formats: `bmdFormat8BitYUV` (`2vuy`), `bmdFormat10BitYUV` (`v210`)
 * PAL:
  * Mode: `bmdModePAL` (`pal `)
  * Resolution: `720` x `576`
  * Frame Duration: `1000` / `25000` (`25.000` fps, `40 0000` per frame)
  * Field Dominance: `bmdUpperFieldFirst` (`uppr`)
  * Flags: `bmdDisplayModeColorspaceRec601`
  * Pixel Formats: `bmdFormat8BitYUV` (`2vuy`), `bmdFormat10BitYUV` (`v210`)
 * 1080p23.98:
  * Mode: `bmdModeHD1080p2398` (`23ps`)
  * Resolution: `1920` x `1080`
  * Frame Duration: `1001` / `24000` (`23.976` fps, `41 7083` per frame)
  * Field Dominance: `bmdProgressiveFrame` (`prog`)
  * Flags: `bmdDisplayModeSupports3D | bmdDisplayModeColorspaceRec709`
  * Pixel Formats: `bmdFormat8BitYUV` (`2vuy`), `bmdFormat10BitYUV` (`v210`), `bmdFormat8BitARGB`, `bmdFormat8BitBGRA` (`BGRA`), `bmdFormat10BitRGB` (`r210`), `bmdFormat12BitRGB` (`R12B`), `bmdFormat12BitRGBLE` (`R12L`), `bmdFormat10BitRGBXLE` (`R10l`), `bmdFormat10BitRGBX` (`R10b`), `bmdFormat10BitRGBXLE_FULL` (`R10L`), `bmdFormat10BitRGBX_FULL` (`R10B`)
 * 1080p24:
  * Mode: `bmdModeHD1080p24` (`24ps`)
  * Resolution: `1920` x `1080`
  * Frame Duration: `1000` / `24000` (`24.000` fps, `41 6666` per frame)
  * Field Dominance: `bmdProgressiveFrame` (`prog`)
  * Flags: `bmdDisplayModeSupports3D | bmdDisplayModeColorspaceRec709`
  * Pixel Formats: `bmdFormat8BitYUV` (`2vuy`), `bmdFormat10BitYUV` (`v210`), `bmdFormat8BitARGB`, `bmdFormat8BitBGRA` (`BGRA`), `bmdFormat10BitRGB` (`r210`), `bmdFormat12BitRGB` (`R12B`), `bmdFormat12BitRGBLE` (`R12L`), `bmdFormat10BitRGBXLE` (`R10l`), `bmdFormat10BitRGBX` (`R10b`), `bmdFormat10BitRGBXLE_FULL` (`R10L`), `bmdFormat10BitRGBX_FULL` (`R10B`)
 * 1080p25:
  * Mode: `bmdModeHD1080p25` (`Hp25`)
  * Resolution: `1920` x `1080`
  * Frame Duration: `1000` / `25000` (`25.000` fps, `40 0000` per frame)
  * Field Dominance: `bmdProgressiveFrame` (`prog`)
  * Flags: `bmdDisplayModeSupports3D | bmdDisplayModeColorspaceRec709`
  * Pixel Formats: `bmdFormat8BitYUV` (`2vuy`), `bmdFormat10BitYUV` (`v210`), `bmdFormat8BitARGB`, `bmdFormat8BitBGRA` (`BGRA`), `bmdFormat10BitRGB` (`r210`), `bmdFormat12BitRGB` (`R12B`), `bmdFormat12BitRGBLE` (`R12L`), `bmdFormat10BitRGBXLE` (`R10l`), `bmdFormat10BitRGBX` (`R10b`), `bmdFormat10BitRGBXLE_FULL` (`R10L`), `bmdFormat10BitRGBX_FULL` (`R10B`)
 * 1080p29.97:
  * Mode: `bmdModeHD1080p2997` (`Hp29`)
  * Resolution: `1920` x `1080`
  * Frame Duration: `1001` / `30000` (`29.970` fps, `33 3666` per frame)
  * Field Dominance: `bmdProgressiveFrame` (`prog`)
  * Flags: `bmdDisplayModeSupports3D | bmdDisplayModeColorspaceRec709`
  * Pixel Formats: `bmdFormat8BitYUV` (`2vuy`), `bmdFormat10BitYUV` (`v210`), `bmdFormat8BitARGB`, `bmdFormat8BitBGRA` (`BGRA`), `bmdFormat10BitRGB` (`r210`), `bmdFormat12BitRGB` (`R12B`), `bmdFormat12BitRGBLE` (`R12L`), `bmdFormat10BitRGBXLE` (`R10l`), `bmdFormat10BitRGBX` (`R10b`), `bmdFormat10BitRGBXLE_FULL` (`R10L`), `bmdFormat10BitRGBX_FULL` (`R10B`)
 * 1080p30:
  * Mode: `bmdModeHD1080p30` (`Hp30`)
  * Resolution: `1920` x `1080`
  * Frame Duration: `1000` / `30000` (`30.000` fps, `33 3333` per frame)
  * Field Dominance: `bmdProgressiveFrame` (`prog`)
  * Flags: `bmdDisplayModeSupports3D | bmdDisplayModeColorspaceRec709`
  * Pixel Formats: `bmdFormat8BitYUV` (`2vuy`), `bmdFormat10BitYUV` (`v210`), `bmdFormat8BitARGB`, `bmdFormat8BitBGRA` (`BGRA`), `bmdFormat10BitRGB` (`r210`), `bmdFormat12BitRGB` (`R12B`), `bmdFormat12BitRGBLE` (`R12L`), `bmdFormat10BitRGBXLE` (`R10l`), `bmdFormat10BitRGBX` (`R10b`), `bmdFormat10BitRGBXLE_FULL` (`R10L`), `bmdFormat10BitRGBX_FULL` (`R10B`)
 * 1080i50:
  * Mode: `bmdModeHD1080i50` (`Hi50`)
  * Resolution: `1920` x `1080`
  * Frame Duration: `1000` / `25000` (`25.000` fps, `40 0000` per frame)
  * Field Dominance: `bmdUpperFieldFirst` (`uppr`)
  * Flags: `bmdDisplayModeSupports3D | bmdDisplayModeColorspaceRec709`
  * Pixel Formats: `bmdFormat8BitYUV` (`2vuy`), `bmdFormat10BitYUV` (`v210`), `bmdFormat8BitARGB`, `bmdFormat8BitBGRA` (`BGRA`), `bmdFormat10BitRGB` (`r210`), `bmdFormat12BitRGB` (`R12B`), `bmdFormat12BitRGBLE` (`R12L`), `bmdFormat10BitRGBXLE` (`R10l`), `bmdFormat10BitRGBX` (`R10b`), `bmdFormat10BitRGBXLE_FULL` (`R10L`), `bmdFormat10BitRGBX_FULL` (`R10B`)
 * 1080i59.94:
  * Mode: `bmdModeHD1080i5994` (`Hi59`)
  * Resolution: `1920` x `1080`
  * Frame Duration: `1001` / `30000` (`29.970` fps, `33 3666` per frame)
  * Field Dominance: `bmdUpperFieldFirst` (`uppr`)
  * Flags: `bmdDisplayModeSupports3D | bmdDisplayModeColorspaceRec709`
  * Pixel Formats: `bmdFormat8BitYUV` (`2vuy`), `bmdFormat10BitYUV` (`v210`), `bmdFormat8BitARGB`, `bmdFormat8BitBGRA` (`BGRA`), `bmdFormat10BitRGB` (`r210`), `bmdFormat12BitRGB` (`R12B`), `bmdFormat12BitRGBLE` (`R12L`), `bmdFormat10BitRGBXLE` (`R10l`), `bmdFormat10BitRGBX` (`R10b`), `bmdFormat10BitRGBXLE_FULL` (`R10L`), `bmdFormat10BitRGBX_FULL` (`R10B`)
 * 1080i60:
  * Mode: `bmdModeHD1080i6000` (`Hi60`)
  * Resolution: `1920` x `1080`
  * Frame Duration: `1000` / `30000` (`30.000` fps, `33 3333` per frame)
  * Field Dominance: `bmdUpperFieldFirst` (`uppr`)
  * Flags: `bmdDisplayModeSupports3D | bmdDisplayModeColorspaceRec709`
  * Pixel Formats: `bmdFormat8BitYUV` (`2vuy`), `bmdFormat10BitYUV` (`v210`), `bmdFormat8BitARGB`, `bmdFormat8BitBGRA` (`BGRA`), `bmdFormat10BitRGB` (`r210`), `bmdFormat12BitRGB` (`R12B`), `bmdFormat12BitRGBLE` (`R12L`), `bmdFormat10BitRGBXLE` (`R10l`), `bmdFormat10BitRGBX` (`R10b`), `bmdFormat10BitRGBXLE_FULL` (`R10L`), `bmdFormat10BitRGBX_FULL` (`R10B`)
 * 1080p50:
  * Mode: `bmdModeHD1080p50` (`Hp50`)
  * Resolution: `1920` x `1080`
  * Frame Duration: `1000` / `50000` (`50.000` fps, `20 0000` per frame)
  * Field Dominance: `bmdProgressiveFrame` (`prog`)
  * Flags: `bmdDisplayModeColorspaceRec709`
  * Pixel Formats: `bmdFormat8BitYUV` (`2vuy`), `bmdFormat10BitYUV` (`v210`)
 * 1080p59.94:
  * Mode: `bmdModeHD1080p5994` (`Hp59`)
  * Resolution: `1920` x `1080`
  * Frame Duration: `1001` / `60000` (`59.940` fps, `16 6833` per frame)
  * Field Dominance: `bmdProgressiveFrame` (`prog`)
  * Flags: `bmdDisplayModeColorspaceRec709`
  * Pixel Formats: `bmdFormat8BitYUV` (`2vuy`), `bmdFormat10BitYUV` (`v210`)
 * 1080p60:
  * Mode: `bmdModeHD1080p6000` (`Hp60`)
  * Resolution: `1920` x `1080`
  * Frame Duration: `1000` / `60000` (`60.000` fps, `16 6666` per frame)
  * Field Dominance: `bmdProgressiveFrame` (`prog`)
  * Flags: `bmdDisplayModeColorspaceRec709`
  * Pixel Formats: `bmdFormat8BitYUV` (`2vuy`), `bmdFormat10BitYUV` (`v210`)
 * 720p50:
  * Mode: `bmdModeHD720p50` (`hp50`)
  * Resolution: `1280` x `720`
  * Frame Duration: `1000` / `50000` (`50.000` fps, `20 0000` per frame)
  * Field Dominance: `bmdProgressiveFrame` (`prog`)
  * Flags: `bmdDisplayModeSupports3D | bmdDisplayModeColorspaceRec709`
  * Pixel Formats: `bmdFormat8BitYUV` (`2vuy`), `bmdFormat10BitYUV` (`v210`), `bmdFormat8BitARGB`, `bmdFormat8BitBGRA` (`BGRA`), `bmdFormat10BitRGB` (`r210`), `bmdFormat10BitRGBXLE` (`R10l`), `bmdFormat10BitRGBX` (`R10b`), `bmdFormat10BitRGBXLE_FULL` (`R10L`), `bmdFormat10BitRGBX_FULL` (`R10B`)
 * 720p59.94:
  * Mode: `bmdModeHD720p5994` (`hp59`)
  * Resolution: `1280` x `720`
  * Frame Duration: `1001` / `60000` (`59.940` fps, `16 6833` per frame)
  * Field Dominance: `bmdProgressiveFrame` (`prog`)
  * Flags: `bmdDisplayModeSupports3D | bmdDisplayModeColorspaceRec709`
  * Pixel Formats: `bmdFormat8BitYUV` (`2vuy`), `bmdFormat10BitYUV` (`v210`), `bmdFormat8BitARGB`, `bmdFormat8BitBGRA` (`BGRA`), `bmdFormat10BitRGB` (`r210`), `bmdFormat10BitRGBXLE` (`R10l`), `bmdFormat10BitRGBX` (`R10b`), `bmdFormat10BitRGBXLE_FULL` (`R10L`), `bmdFormat10BitRGBX_FULL` (`R10B`)
 * 720p60:
  * Mode: `bmdModeHD720p60` (`hp60`)
  * Resolution: `1280` x `720`
  * Frame Duration: `1000` / `60000` (`60.000` fps, `16 6666` per frame)
  * Field Dominance: `bmdProgressiveFrame` (`prog`)
  * Flags: `bmdDisplayModeSupports3D | bmdDisplayModeColorspaceRec709`
  * Pixel Formats: `bmdFormat8BitYUV` (`2vuy`), `bmdFormat10BitYUV` (`v210`), `bmdFormat8BitARGB`, `bmdFormat8BitBGRA` (`BGRA`), `bmdFormat10BitRGB` (`r210`), `bmdFormat10BitRGBXLE` (`R10l`), `bmdFormat10BitRGBX` (`R10b`), `bmdFormat10BitRGBXLE_FULL` (`R10L`), `bmdFormat10BitRGBX_FULL` (`R10B`)
 * 1080p23.98 DCI 2K:
  * Mode: `bmdMode2kDCI2398` (`2d23`)
  * Resolution: `2048` x `1080`
  * Frame Duration: `1001` / `24000` (`23.976` fps, `41 7083` per frame)
  * Field Dominance: `bmdProgressiveFrame` (`prog`)
  * Flags: `bmdDisplayModeSupports3D | bmdDisplayModeColorspaceRec709`
  * Pixel Formats: `bmdFormat8BitYUV` (`2vuy`), `bmdFormat10BitYUV` (`v210`), `bmdFormat8BitARGB`, `bmdFormat8BitBGRA` (`BGRA`), `bmdFormat10BitRGB` (`r210`), `bmdFormat12BitRGB` (`R12B`), `bmdFormat12BitRGBLE` (`R12L`), `bmdFormat10BitRGBXLE` (`R10l`), `bmdFormat10BitRGBX` (`R10b`), `bmdFormat10BitRGBXLE_FULL` (`R10L`), `bmdFormat10BitRGBX_FULL` (`R10B`)
 * 1080p24 DCI 2K:
  * Mode: `bmdMode2kDCI24` (`2d24`)
  * Resolution: `2048` x `1080`
  * Frame Duration: `1000` / `24000` (`24.000` fps, `41 6666` per frame)
  * Field Dominance: `bmdProgressiveFrame` (`prog`)
  * Flags: `bmdDisplayModeSupports3D | bmdDisplayModeColorspaceRec709`
  * Pixel Formats: `bmdFormat8BitYUV` (`2vuy`), `bmdFormat10BitYUV` (`v210`), `bmdFormat8BitARGB`, `bmdFormat8BitBGRA` (`BGRA`), `bmdFormat10BitRGB` (`r210`), `bmdFormat12BitRGB` (`R12B`), `bmdFormat12BitRGBLE` (`R12L`), `bmdFormat10BitRGBXLE` (`R10l`), `bmdFormat10BitRGBX` (`R10b`), `bmdFormat10BitRGBXLE_FULL` (`R10L`), `bmdFormat10BitRGBX_FULL` (`R10B`)
 * 1080p25 DCI 2K:
  * Mode: `bmdMode2kDCI25` (`2d25`)
  * Resolution: `2048` x `1080`
  * Frame Duration: `1000` / `25000` (`25.000` fps, `40 0000` per frame)
  * Field Dominance: `bmdProgressiveFrame` (`prog`)
  * Flags: `bmdDisplayModeSupports3D | bmdDisplayModeColorspaceRec709`
  * Pixel Formats: `bmdFormat8BitYUV` (`2vuy`), `bmdFormat10BitYUV` (`v210`), `bmdFormat8BitARGB`, `bmdFormat8BitBGRA` (`BGRA`), `bmdFormat10BitRGB` (`r210`), `bmdFormat12BitRGB` (`R12B`), `bmdFormat12BitRGBLE` (`R12L`), `bmdFormat10BitRGBXLE` (`R10l`), `bmdFormat10BitRGBX` (`R10b`), `bmdFormat10BitRGBXLE_FULL` (`R10L`), `bmdFormat10BitRGBX_FULL` (`R10B`)
 * 2160p23.98:
  * Mode: `bmdMode4K2160p2398` (`4k23`)
  * Resolution: `3840` x `2160`
  * Frame Duration: `1001` / `24000` (`23.976` fps, `41 7083` per frame)
  * Field Dominance: `bmdProgressiveFrame` (`prog`)
  * Flags: `bmdDisplayModeColorspaceRec709`
  * Pixel Formats: `bmdFormat8BitYUV` (`2vuy`), `bmdFormat10BitYUV` (`v210`), `bmdFormat8BitARGB`, `bmdFormat8BitBGRA` (`BGRA`), `bmdFormat10BitRGB` (`r210`), `bmdFormat12BitRGB` (`R12B`), `bmdFormat12BitRGBLE` (`R12L`), `bmdFormat10BitRGBXLE` (`R10l`), `bmdFormat10BitRGBX` (`R10b`), `bmdFormat10BitRGBXLE_FULL` (`R10L`), `bmdFormat10BitRGBX_FULL` (`R10B`)
 * 2160p24:
  * Mode: `bmdMode4K2160p24` (`4k24`)
  * Resolution: `3840` x `2160`
  * Frame Duration: `1000` / `24000` (`24.000` fps, `41 6666` per frame)
  * Field Dominance: `bmdProgressiveFrame` (`prog`)
  * Flags: `bmdDisplayModeColorspaceRec709`
  * Pixel Formats: `bmdFormat8BitYUV` (`2vuy`), `bmdFormat10BitYUV` (`v210`), `bmdFormat8BitARGB`, `bmdFormat8BitBGRA` (`BGRA`), `bmdFormat10BitRGB` (`r210`), `bmdFormat12BitRGB` (`R12B`), `bmdFormat12BitRGBLE` (`R12L`), `bmdFormat10BitRGBXLE` (`R10l`), `bmdFormat10BitRGBX` (`R10b`), `bmdFormat10BitRGBXLE_FULL` (`R10L`), `bmdFormat10BitRGBX_FULL` (`R10B`)
 * 2160p25:
  * Mode: `bmdMode4K2160p25` (`4k25`)
  * Resolution: `3840` x `2160`
  * Frame Duration: `1000` / `25000` (`25.000` fps, `40 0000` per frame)
  * Field Dominance: `bmdProgressiveFrame` (`prog`)
  * Flags: `bmdDisplayModeColorspaceRec709`
  * Pixel Formats: `bmdFormat8BitYUV` (`2vuy`), `bmdFormat10BitYUV` (`v210`), `bmdFormat8BitARGB`, `bmdFormat8BitBGRA` (`BGRA`), `bmdFormat10BitRGB` (`r210`), `bmdFormat12BitRGB` (`R12B`), `bmdFormat12BitRGBLE` (`R12L`), `bmdFormat10BitRGBXLE` (`R10l`), `bmdFormat10BitRGBX` (`R10b`), `bmdFormat10BitRGBXLE_FULL` (`R10L`), `bmdFormat10BitRGBX_FULL` (`R10B`)
 * 2160p29.97:
  * Mode: `bmdMode4K2160p2997` (`4k29`)
  * Resolution: `3840` x `2160`
  * Frame Duration: `1001` / `30000` (`29.970` fps, `33 3666` per frame)
  * Field Dominance: `bmdProgressiveFrame` (`prog`)
  * Flags: `bmdDisplayModeColorspaceRec709`
  * Pixel Formats: `bmdFormat8BitYUV` (`2vuy`), `bmdFormat10BitYUV` (`v210`), `bmdFormat8BitARGB`, `bmdFormat8BitBGRA` (`BGRA`), `bmdFormat10BitRGB` (`r210`), `bmdFormat12BitRGB` (`R12B`), `bmdFormat12BitRGBLE` (`R12L`), `bmdFormat10BitRGBXLE` (`R10l`), `bmdFormat10BitRGBX` (`R10b`), `bmdFormat10BitRGBXLE_FULL` (`R10L`), `bmdFormat10BitRGBX_FULL` (`R10B`)
 * 2160p30:
  * Mode: `bmdMode4K2160p30` (`4k30`)
  * Resolution: `3840` x `2160`
  * Frame Duration: `1000` / `30000` (`30.000` fps, `33 3333` per frame)
  * Field Dominance: `bmdProgressiveFrame` (`prog`)
  * Flags: `bmdDisplayModeColorspaceRec709`
  * Pixel Formats: `bmdFormat8BitYUV` (`2vuy`), `bmdFormat10BitYUV` (`v210`), `bmdFormat8BitARGB`, `bmdFormat8BitBGRA` (`BGRA`), `bmdFormat10BitRGB` (`r210`), `bmdFormat12BitRGB` (`R12B`), `bmdFormat12BitRGBLE` (`R12L`), `bmdFormat10BitRGBXLE` (`R10l`), `bmdFormat10BitRGBX` (`R10b`), `bmdFormat10BitRGBXLE_FULL` (`R10L`), `bmdFormat10BitRGBX_FULL` (`R10B`)
 * 2160p50:
  * Mode: `bmdMode4K2160p50` (`4k50`)
  * Resolution: `3840` x `2160`
  * Frame Duration: `1000` / `50000` (`50.000` fps, `20 0000` per frame)
  * Field Dominance: `bmdProgressiveFrame` (`prog`)
  * Flags: `bmdDisplayModeColorspaceRec709`
  * Pixel Formats: `bmdFormat8BitYUV` (`2vuy`), `bmdFormat10BitYUV` (`v210`)
 * 2160p59.94:
  * Mode: `bmdMode4K2160p5994` (`4k59`)
  * Resolution: `3840` x `2160`
  * Frame Duration: `1001` / `60000` (`59.940` fps, `16 6833` per frame)
  * Field Dominance: `bmdProgressiveFrame` (`prog`)
  * Flags: `bmdDisplayModeColorspaceRec709`
  * Pixel Formats: `bmdFormat8BitYUV` (`2vuy`), `bmdFormat10BitYUV` (`v210`)
 * 2160p60:
  * Mode: `bmdMode4K2160p60` (`4k60`)
  * Resolution: `3840` x `2160`
  * Frame Duration: `1000` / `60000` (`60.000` fps, `16 6666` per frame)
  * Field Dominance: `bmdProgressiveFrame` (`prog`)
  * Flags: `bmdDisplayModeColorspaceRec709`
  * Pixel Formats: `bmdFormat8BitYUV` (`2vuy`), `bmdFormat10BitYUV` (`v210`)
 * 2160p23.98 DCI 4K:
  * Mode: `bmdMode4kDCI2398` (`4d23`)
  * Resolution: `4096` x `2160`
  * Frame Duration: `1001` / `24000` (`23.976` fps, `41 7083` per frame)
  * Field Dominance: `bmdProgressiveFrame` (`prog`)
  * Flags: `bmdDisplayModeColorspaceRec709`
  * Pixel Formats: `bmdFormat8BitYUV` (`2vuy`), `bmdFormat10BitYUV` (`v210`), `bmdFormat8BitARGB`, `bmdFormat8BitBGRA` (`BGRA`), `bmdFormat10BitRGB` (`r210`), `bmdFormat12BitRGB` (`R12B`), `bmdFormat12BitRGBLE` (`R12L`), `bmdFormat10BitRGBXLE` (`R10l`), `bmdFormat10BitRGBX` (`R10b`), `bmdFormat10BitRGBXLE_FULL` (`R10L`), `bmdFormat10BitRGBX_FULL` (`R10B`)
 * 2160p24 DCI 4K:
  * Mode: `bmdMode4kDCI24` (`4d24`)
  * Resolution: `4096` x `2160`
  * Frame Duration: `1000` / `24000` (`24.000` fps, `41 6666` per frame)
  * Field Dominance: `bmdProgressiveFrame` (`prog`)
  * Flags: `bmdDisplayModeColorspaceRec709`
  * Pixel Formats: `bmdFormat8BitYUV` (`2vuy`), `bmdFormat10BitYUV` (`v210`), `bmdFormat8BitARGB`, `bmdFormat8BitBGRA` (`BGRA`), `bmdFormat10BitRGB` (`r210`), `bmdFormat12BitRGB` (`R12B`), `bmdFormat12BitRGBLE` (`R12L`), `bmdFormat10BitRGBXLE` (`R10l`), `bmdFormat10BitRGBX` (`R10b`), `bmdFormat10BitRGBXLE_FULL` (`R10L`), `bmdFormat10BitRGBX_FULL` (`R10B`)
 * 2160p25 DCI 4K:
  * Mode: `bmdMode4kDCI25` (`4d25`)
  * Resolution: `4096` x `2160`
  * Frame Duration: `1000` / `25000` (`25.000` fps, `40 0000` per frame)
  * Field Dominance: `bmdProgressiveFrame` (`prog`)
  * Flags: `bmdDisplayModeColorspaceRec709`
  * Pixel Formats: `bmdFormat8BitYUV` (`2vuy`), `bmdFormat10BitYUV` (`v210`), `bmdFormat8BitARGB`, `bmdFormat8BitBGRA` (`BGRA`), `bmdFormat10BitRGB` (`r210`), `bmdFormat12BitRGB` (`R12B`), `bmdFormat12BitRGBLE` (`R12L`), `bmdFormat10BitRGBXLE` (`R10l`), `bmdFormat10BitRGBX` (`R10b`), `bmdFormat10BitRGBXLE_FULL` (`R10L`), `bmdFormat10BitRGBX_FULL` (`R10B`)

TSV Formatted:

	Name	Display Mode	Display Mode FourCC	Resolution Width	Resolution Height	Frame Duration	Time Scale	Frame Rate, per second	Frame Length, millisecond	Field Dominance	Field Dominance FourCC	Display Mode Flags	Pixel Formats
	NTSC	bmdModeNTSC	ntsc	720	486	1001	30000	29.970	333666	bmdLowerFieldFirst	lowr	bmdDisplayModeColorspaceRec601	bmdFormat8BitYUV 2vuy, bmdFormat10BitYUV v210
	PAL	bmdModePAL	pal 	720	576	1000	25000	25.000	400000	bmdUpperFieldFirst	uppr	bmdDisplayModeColorspaceRec601	bmdFormat8BitYUV 2vuy, bmdFormat10BitYUV v210
	1080p23.98	bmdModeHD1080p2398	23ps	1920	1080	1001	24000	23.976	417083	bmdProgressiveFrame	prog	bmdDisplayModeSupports3D | bmdDisplayModeColorspaceRec709	bmdFormat8BitYUV 2vuy, bmdFormat10BitYUV v210, bmdFormat8BitARGB , bmdFormat8BitBGRA BGRA, bmdFormat10BitRGB r210, bmdFormat12BitRGB R12B, bmdFormat12BitRGBLE R12L, bmdFormat10BitRGBXLE R10l, bmdFormat10BitRGBX R10b, bmdFormat10BitRGBXLE_FULL R10L, bmdFormat10BitRGBX_FULL R10B
	1080p24	bmdModeHD1080p24	24ps	1920	1080	1000	24000	24.000	416666	bmdProgressiveFrame	prog	bmdDisplayModeSupports3D | bmdDisplayModeColorspaceRec709	bmdFormat8BitYUV 2vuy, bmdFormat10BitYUV v210, bmdFormat8BitARGB , bmdFormat8BitBGRA BGRA, bmdFormat10BitRGB r210, bmdFormat12BitRGB R12B, bmdFormat12BitRGBLE R12L, bmdFormat10BitRGBXLE R10l, bmdFormat10BitRGBX R10b, bmdFormat10BitRGBXLE_FULL R10L, bmdFormat10BitRGBX_FULL R10B
	1080p25	bmdModeHD1080p25	Hp25	1920	1080	1000	25000	25.000	400000	bmdProgressiveFrame	prog	bmdDisplayModeSupports3D | bmdDisplayModeColorspaceRec709	bmdFormat8BitYUV 2vuy, bmdFormat10BitYUV v210, bmdFormat8BitARGB , bmdFormat8BitBGRA BGRA, bmdFormat10BitRGB r210, bmdFormat12BitRGB R12B, bmdFormat12BitRGBLE R12L, bmdFormat10BitRGBXLE R10l, bmdFormat10BitRGBX R10b, bmdFormat10BitRGBXLE_FULL R10L, bmdFormat10BitRGBX_FULL R10B
	1080p29.97	bmdModeHD1080p2997	Hp29	1920	1080	1001	30000	29.970	333666	bmdProgressiveFrame	prog	bmdDisplayModeSupports3D | bmdDisplayModeColorspaceRec709	bmdFormat8BitYUV 2vuy, bmdFormat10BitYUV v210, bmdFormat8BitARGB , bmdFormat8BitBGRA BGRA, bmdFormat10BitRGB r210, bmdFormat12BitRGB R12B, bmdFormat12BitRGBLE R12L, bmdFormat10BitRGBXLE R10l, bmdFormat10BitRGBX R10b, bmdFormat10BitRGBXLE_FULL R10L, bmdFormat10BitRGBX_FULL R10B
	1080p30	bmdModeHD1080p30	Hp30	1920	1080	1000	30000	30.000	333333	bmdProgressiveFrame	prog	bmdDisplayModeSupports3D | bmdDisplayModeColorspaceRec709	bmdFormat8BitYUV 2vuy, bmdFormat10BitYUV v210, bmdFormat8BitARGB , bmdFormat8BitBGRA BGRA, bmdFormat10BitRGB r210, bmdFormat12BitRGB R12B, bmdFormat12BitRGBLE R12L, bmdFormat10BitRGBXLE R10l, bmdFormat10BitRGBX R10b, bmdFormat10BitRGBXLE_FULL R10L, bmdFormat10BitRGBX_FULL R10B
	1080i50	bmdModeHD1080i50	Hi50	1920	1080	1000	25000	25.000	400000	bmdUpperFieldFirst	uppr	bmdDisplayModeSupports3D | bmdDisplayModeColorspaceRec709	bmdFormat8BitYUV 2vuy, bmdFormat10BitYUV v210, bmdFormat8BitARGB , bmdFormat8BitBGRA BGRA, bmdFormat10BitRGB r210, bmdFormat12BitRGB R12B, bmdFormat12BitRGBLE R12L, bmdFormat10BitRGBXLE R10l, bmdFormat10BitRGBX R10b, bmdFormat10BitRGBXLE_FULL R10L, bmdFormat10BitRGBX_FULL R10B
	1080i59.94	bmdModeHD1080i5994	Hi59	1920	1080	1001	30000	29.970	333666	bmdUpperFieldFirst	uppr	bmdDisplayModeSupports3D | bmdDisplayModeColorspaceRec709	bmdFormat8BitYUV 2vuy, bmdFormat10BitYUV v210, bmdFormat8BitARGB , bmdFormat8BitBGRA BGRA, bmdFormat10BitRGB r210, bmdFormat12BitRGB R12B, bmdFormat12BitRGBLE R12L, bmdFormat10BitRGBXLE R10l, bmdFormat10BitRGBX R10b, bmdFormat10BitRGBXLE_FULL R10L, bmdFormat10BitRGBX_FULL R10B
	1080i60	bmdModeHD1080i6000	Hi60	1920	1080	1000	30000	30.000	333333	bmdUpperFieldFirst	uppr	bmdDisplayModeSupports3D | bmdDisplayModeColorspaceRec709	bmdFormat8BitYUV 2vuy, bmdFormat10BitYUV v210, bmdFormat8BitARGB , bmdFormat8BitBGRA BGRA, bmdFormat10BitRGB r210, bmdFormat12BitRGB R12B, bmdFormat12BitRGBLE R12L, bmdFormat10BitRGBXLE R10l, bmdFormat10BitRGBX R10b, bmdFormat10BitRGBXLE_FULL R10L, bmdFormat10BitRGBX_FULL R10B
	1080p50	bmdModeHD1080p50	Hp50	1920	1080	1000	50000	50.000	200000	bmdProgressiveFrame	prog	bmdDisplayModeColorspaceRec709	bmdFormat8BitYUV 2vuy, bmdFormat10BitYUV v210
	1080p59.94	bmdModeHD1080p5994	Hp59	1920	1080	1001	60000	59.940	166833	bmdProgressiveFrame	prog	bmdDisplayModeColorspaceRec709	bmdFormat8BitYUV 2vuy, bmdFormat10BitYUV v210
	1080p60	bmdModeHD1080p6000	Hp60	1920	1080	1000	60000	60.000	166666	bmdProgressiveFrame	prog	bmdDisplayModeColorspaceRec709	bmdFormat8BitYUV 2vuy, bmdFormat10BitYUV v210
	720p50	bmdModeHD720p50	hp50	1280	720	1000	50000	50.000	200000	bmdProgressiveFrame	prog	bmdDisplayModeSupports3D | bmdDisplayModeColorspaceRec709	bmdFormat8BitYUV 2vuy, bmdFormat10BitYUV v210, bmdFormat8BitARGB , bmdFormat8BitBGRA BGRA, bmdFormat10BitRGB r210, bmdFormat10BitRGBXLE R10l, bmdFormat10BitRGBX R10b, bmdFormat10BitRGBXLE_FULL R10L, bmdFormat10BitRGBX_FULL R10B
	720p59.94	bmdModeHD720p5994	hp59	1280	720	1001	60000	59.940	166833	bmdProgressiveFrame	prog	bmdDisplayModeSupports3D | bmdDisplayModeColorspaceRec709	bmdFormat8BitYUV 2vuy, bmdFormat10BitYUV v210, bmdFormat8BitARGB , bmdFormat8BitBGRA BGRA, bmdFormat10BitRGB r210, bmdFormat10BitRGBXLE R10l, bmdFormat10BitRGBX R10b, bmdFormat10BitRGBXLE_FULL R10L, bmdFormat10BitRGBX_FULL R10B
	720p60	bmdModeHD720p60	hp60	1280	720	1000	60000	60.000	166666	bmdProgressiveFrame	prog	bmdDisplayModeSupports3D | bmdDisplayModeColorspaceRec709	bmdFormat8BitYUV 2vuy, bmdFormat10BitYUV v210, bmdFormat8BitARGB , bmdFormat8BitBGRA BGRA, bmdFormat10BitRGB r210, bmdFormat10BitRGBXLE R10l, bmdFormat10BitRGBX R10b, bmdFormat10BitRGBXLE_FULL R10L, bmdFormat10BitRGBX_FULL R10B
	1080p23.98 DCI 2K	bmdMode2kDCI2398	2d23	2048	1080	1001	24000	23.976	417083	bmdProgressiveFrame	prog	bmdDisplayModeSupports3D | bmdDisplayModeColorspaceRec709	bmdFormat8BitYUV 2vuy, bmdFormat10BitYUV v210, bmdFormat8BitARGB , bmdFormat8BitBGRA BGRA, bmdFormat10BitRGB r210, bmdFormat12BitRGB R12B, bmdFormat12BitRGBLE R12L, bmdFormat10BitRGBXLE R10l, bmdFormat10BitRGBX R10b, bmdFormat10BitRGBXLE_FULL R10L, bmdFormat10BitRGBX_FULL R10B
	1080p24 DCI 2K	bmdMode2kDCI24	2d24	2048	1080	1000	24000	24.000	416666	bmdProgressiveFrame	prog	bmdDisplayModeSupports3D | bmdDisplayModeColorspaceRec709	bmdFormat8BitYUV 2vuy, bmdFormat10BitYUV v210, bmdFormat8BitARGB , bmdFormat8BitBGRA BGRA, bmdFormat10BitRGB r210, bmdFormat12BitRGB R12B, bmdFormat12BitRGBLE R12L, bmdFormat10BitRGBXLE R10l, bmdFormat10BitRGBX R10b, bmdFormat10BitRGBXLE_FULL R10L, bmdFormat10BitRGBX_FULL R10B
	1080p25 DCI 2K	bmdMode2kDCI25	2d25	2048	1080	1000	25000	25.000	400000	bmdProgressiveFrame	prog	bmdDisplayModeSupports3D | bmdDisplayModeColorspaceRec709	bmdFormat8BitYUV 2vuy, bmdFormat10BitYUV v210, bmdFormat8BitARGB , bmdFormat8BitBGRA BGRA, bmdFormat10BitRGB r210, bmdFormat12BitRGB R12B, bmdFormat12BitRGBLE R12L, bmdFormat10BitRGBXLE R10l, bmdFormat10BitRGBX R10b, bmdFormat10BitRGBXLE_FULL R10L, bmdFormat10BitRGBX_FULL R10B
	2160p23.98	bmdMode4K2160p2398	4k23	3840	2160	1001	24000	23.976	417083	bmdProgressiveFrame	prog	bmdDisplayModeColorspaceRec709	bmdFormat8BitYUV 2vuy, bmdFormat10BitYUV v210, bmdFormat8BitARGB , bmdFormat8BitBGRA BGRA, bmdFormat10BitRGB r210, bmdFormat12BitRGB R12B, bmdFormat12BitRGBLE R12L, bmdFormat10BitRGBXLE R10l, bmdFormat10BitRGBX R10b, bmdFormat10BitRGBXLE_FULL R10L, bmdFormat10BitRGBX_FULL R10B
	2160p24	bmdMode4K2160p24	4k24	3840	2160	1000	24000	24.000	416666	bmdProgressiveFrame	prog	bmdDisplayModeColorspaceRec709	bmdFormat8BitYUV 2vuy, bmdFormat10BitYUV v210, bmdFormat8BitARGB , bmdFormat8BitBGRA BGRA, bmdFormat10BitRGB r210, bmdFormat12BitRGB R12B, bmdFormat12BitRGBLE R12L, bmdFormat10BitRGBXLE R10l, bmdFormat10BitRGBX R10b, bmdFormat10BitRGBXLE_FULL R10L, bmdFormat10BitRGBX_FULL R10B
	2160p25	bmdMode4K2160p25	4k25	3840	2160	1000	25000	25.000	400000	bmdProgressiveFrame	prog	bmdDisplayModeColorspaceRec709	bmdFormat8BitYUV 2vuy, bmdFormat10BitYUV v210, bmdFormat8BitARGB , bmdFormat8BitBGRA BGRA, bmdFormat10BitRGB r210, bmdFormat12BitRGB R12B, bmdFormat12BitRGBLE R12L, bmdFormat10BitRGBXLE R10l, bmdFormat10BitRGBX R10b, bmdFormat10BitRGBXLE_FULL R10L, bmdFormat10BitRGBX_FULL R10B
	2160p29.97	bmdMode4K2160p2997	4k29	3840	2160	1001	30000	29.970	333666	bmdProgressiveFrame	prog	bmdDisplayModeColorspaceRec709	bmdFormat8BitYUV 2vuy, bmdFormat10BitYUV v210, bmdFormat8BitARGB , bmdFormat8BitBGRA BGRA, bmdFormat10BitRGB r210, bmdFormat12BitRGB R12B, bmdFormat12BitRGBLE R12L, bmdFormat10BitRGBXLE R10l, bmdFormat10BitRGBX R10b, bmdFormat10BitRGBXLE_FULL R10L, bmdFormat10BitRGBX_FULL R10B
	2160p30	bmdMode4K2160p30	4k30	3840	2160	1000	30000	30.000	333333	bmdProgressiveFrame	prog	bmdDisplayModeColorspaceRec709	bmdFormat8BitYUV 2vuy, bmdFormat10BitYUV v210, bmdFormat8BitARGB , bmdFormat8BitBGRA BGRA, bmdFormat10BitRGB r210, bmdFormat12BitRGB R12B, bmdFormat12BitRGBLE R12L, bmdFormat10BitRGBXLE R10l, bmdFormat10BitRGBX R10b, bmdFormat10BitRGBXLE_FULL R10L, bmdFormat10BitRGBX_FULL R10B
	2160p50	bmdMode4K2160p50	4k50	3840	2160	1000	50000	50.000	200000	bmdProgressiveFrame	prog	bmdDisplayModeColorspaceRec709	bmdFormat8BitYUV 2vuy, bmdFormat10BitYUV v210
	2160p59.94	bmdMode4K2160p5994	4k59	3840	2160	1001	60000	59.940	166833	bmdProgressiveFrame	prog	bmdDisplayModeColorspaceRec709	bmdFormat8BitYUV 2vuy, bmdFormat10BitYUV v210
	2160p60	bmdMode4K2160p60	4k60	3840	2160	1000	60000	60.000	166666	bmdProgressiveFrame	prog	bmdDisplayModeColorspaceRec709	bmdFormat8BitYUV 2vuy, bmdFormat10BitYUV v210
	2160p23.98 DCI 4K	bmdMode4kDCI2398	4d23	4096	2160	1001	24000	23.976	417083	bmdProgressiveFrame	prog	bmdDisplayModeColorspaceRec709	bmdFormat8BitYUV 2vuy, bmdFormat10BitYUV v210, bmdFormat8BitARGB , bmdFormat8BitBGRA BGRA, bmdFormat10BitRGB r210, bmdFormat12BitRGB R12B, bmdFormat12BitRGBLE R12L, bmdFormat10BitRGBXLE R10l, bmdFormat10BitRGBX R10b, bmdFormat10BitRGBXLE_FULL R10L, bmdFormat10BitRGBX_FULL R10B
	2160p24 DCI 4K	bmdMode4kDCI24	4d24	4096	2160	1000	24000	24.000	416666	bmdProgressiveFrame	prog	bmdDisplayModeColorspaceRec709	bmdFormat8BitYUV 2vuy, bmdFormat10BitYUV v210, bmdFormat8BitARGB , bmdFormat8BitBGRA BGRA, bmdFormat10BitRGB r210, bmdFormat12BitRGB R12B, bmdFormat12BitRGBLE R12L, bmdFormat10BitRGBXLE R10l, bmdFormat10BitRGBX R10b, bmdFormat10BitRGBXLE_FULL R10L, bmdFormat10BitRGBX_FULL R10B
	2160p25 DCI 4K	bmdMode4kDCI25	4d25	4096	2160	1000	25000	25.000	400000	bmdProgressiveFrame	prog	bmdDisplayModeColorspaceRec709	bmdFormat8BitYUV 2vuy, bmdFormat10BitYUV v210, bmdFormat8BitARGB , bmdFormat8BitBGRA BGRA, bmdFormat10BitRGB r210, bmdFormat12BitRGB R12B, bmdFormat12BitRGBLE R12L, bmdFormat10BitRGBXLE R10l, bmdFormat10BitRGBX R10b, bmdFormat10BitRGBXLE_FULL R10L, bmdFormat10BitRGBX_FULL R10B

### Output Display Modes

 * NTSC:
  * Mode: `bmdModeNTSC` (`ntsc`)
  * Resolution: `720` x `486`
  * Frame Duration: `1001` / `30000` (`29.970` fps, `33 3666` per frame)
  * Field Dominance: `bmdLowerFieldFirst` (`lowr`)
  * Flags: `bmdDisplayModeColorspaceRec601`
  * Pixel Formats: `bmdFormat8BitYUV` (`2vuy`), `bmdFormat10BitYUV` (`v210`), `bmdFormat8BitARGB`, `bmdFormat8BitBGRA` (`BGRA`), `bmdFormat10BitRGB` (`r210`), `bmdFormat10BitRGBXLE` (`R10l`), `bmdFormat10BitRGBX` (`R10b`), `bmdFormat10BitRGBXLE_FULL` (`R10L`), `bmdFormat10BitRGBX_FULL` (`R10B`)
 * PAL:
  * Mode: `bmdModePAL` (`pal `)
  * Resolution: `720` x `576`
  * Frame Duration: `1000` / `25000` (`25.000` fps, `40 0000` per frame)
  * Field Dominance: `bmdUpperFieldFirst` (`uppr`)
  * Flags: `bmdDisplayModeColorspaceRec601`
  * Pixel Formats: `bmdFormat8BitYUV` (`2vuy`), `bmdFormat10BitYUV` (`v210`), `bmdFormat8BitARGB`, `bmdFormat8BitBGRA` (`BGRA`), `bmdFormat10BitRGB` (`r210`), `bmdFormat10BitRGBXLE` (`R10l`), `bmdFormat10BitRGBX` (`R10b`), `bmdFormat10BitRGBXLE_FULL` (`R10L`), `bmdFormat10BitRGBX_FULL` (`R10B`)
 * 1080p23.98:
  * Mode: `bmdModeHD1080p2398` (`23ps`)
  * Resolution: `1920` x `1080`
  * Frame Duration: `1001` / `24000` (`23.976` fps, `41 7083` per frame)
  * Field Dominance: `bmdProgressiveFrame` (`prog`)
  * Flags: `bmdDisplayModeSupports3D | bmdDisplayModeColorspaceRec709`
  * Pixel Formats: `bmdFormat8BitYUV` (`2vuy`), `bmdFormat10BitYUV` (`v210`), `bmdFormat8BitARGB`, `bmdFormat8BitBGRA` (`BGRA`), `bmdFormat10BitRGB` (`r210`), `bmdFormat12BitRGB` (`R12B`), `bmdFormat12BitRGBLE` (`R12L`), `bmdFormat10BitRGBXLE` (`R10l`), `bmdFormat10BitRGBX` (`R10b`), `bmdFormat10BitRGBXLE_FULL` (`R10L`), `bmdFormat10BitRGBX_FULL` (`R10B`)
 * 1080p24:
  * Mode: `bmdModeHD1080p24` (`24ps`)
  * Resolution: `1920` x `1080`
  * Frame Duration: `1000` / `24000` (`24.000` fps, `41 6666` per frame)
  * Field Dominance: `bmdProgressiveFrame` (`prog`)
  * Flags: `bmdDisplayModeSupports3D | bmdDisplayModeColorspaceRec709`
  * Pixel Formats: `bmdFormat8BitYUV` (`2vuy`), `bmdFormat10BitYUV` (`v210`), `bmdFormat8BitARGB`, `bmdFormat8BitBGRA` (`BGRA`), `bmdFormat10BitRGB` (`r210`), `bmdFormat12BitRGB` (`R12B`), `bmdFormat12BitRGBLE` (`R12L`), `bmdFormat10BitRGBXLE` (`R10l`), `bmdFormat10BitRGBX` (`R10b`), `bmdFormat10BitRGBXLE_FULL` (`R10L`), `bmdFormat10BitRGBX_FULL` (`R10B`)
 * 1080p25:
  * Mode: `bmdModeHD1080p25` (`Hp25`)
  * Resolution: `1920` x `1080`
  * Frame Duration: `1000` / `25000` (`25.000` fps, `40 0000` per frame)
  * Field Dominance: `bmdProgressiveFrame` (`prog`)
  * Flags: `bmdDisplayModeSupports3D | bmdDisplayModeColorspaceRec709`
  * Pixel Formats: `bmdFormat8BitYUV` (`2vuy`), `bmdFormat10BitYUV` (`v210`), `bmdFormat8BitARGB`, `bmdFormat8BitBGRA` (`BGRA`), `bmdFormat10BitRGB` (`r210`), `bmdFormat12BitRGB` (`R12B`), `bmdFormat12BitRGBLE` (`R12L`), `bmdFormat10BitRGBXLE` (`R10l`), `bmdFormat10BitRGBX` (`R10b`), `bmdFormat10BitRGBXLE_FULL` (`R10L`), `bmdFormat10BitRGBX_FULL` (`R10B`)
 * 1080p29.97:
  * Mode: `bmdModeHD1080p2997` (`Hp29`)
  * Resolution: `1920` x `1080`
  * Frame Duration: `1001` / `30000` (`29.970` fps, `33 3666` per frame)
  * Field Dominance: `bmdProgressiveFrame` (`prog`)
  * Flags: `bmdDisplayModeSupports3D | bmdDisplayModeColorspaceRec709`
  * Pixel Formats: `bmdFormat8BitYUV` (`2vuy`), `bmdFormat10BitYUV` (`v210`), `bmdFormat8BitARGB`, `bmdFormat8BitBGRA` (`BGRA`), `bmdFormat10BitRGB` (`r210`), `bmdFormat12BitRGB` (`R12B`), `bmdFormat12BitRGBLE` (`R12L`), `bmdFormat10BitRGBXLE` (`R10l`), `bmdFormat10BitRGBX` (`R10b`), `bmdFormat10BitRGBXLE_FULL` (`R10L`), `bmdFormat10BitRGBX_FULL` (`R10B`)
 * 1080p30:
  * Mode: `bmdModeHD1080p30` (`Hp30`)
  * Resolution: `1920` x `1080`
  * Frame Duration: `1000` / `30000` (`30.000` fps, `33 3333` per frame)
  * Field Dominance: `bmdProgressiveFrame` (`prog`)
  * Flags: `bmdDisplayModeSupports3D | bmdDisplayModeColorspaceRec709`
  * Pixel Formats: `bmdFormat8BitYUV` (`2vuy`), `bmdFormat10BitYUV` (`v210`), `bmdFormat8BitARGB`, `bmdFormat8BitBGRA` (`BGRA`), `bmdFormat10BitRGB` (`r210`), `bmdFormat12BitRGB` (`R12B`), `bmdFormat12BitRGBLE` (`R12L`), `bmdFormat10BitRGBXLE` (`R10l`), `bmdFormat10BitRGBX` (`R10b`), `bmdFormat10BitRGBXLE_FULL` (`R10L`), `bmdFormat10BitRGBX_FULL` (`R10B`)
 * 1080i50:
  * Mode: `bmdModeHD1080i50` (`Hi50`)
  * Resolution: `1920` x `1080`
  * Frame Duration: `1000` / `25000` (`25.000` fps, `40 0000` per frame)
  * Field Dominance: `bmdUpperFieldFirst` (`uppr`)
  * Flags: `bmdDisplayModeSupports3D | bmdDisplayModeColorspaceRec709`
  * Pixel Formats: `bmdFormat8BitYUV` (`2vuy`), `bmdFormat10BitYUV` (`v210`), `bmdFormat8BitARGB`, `bmdFormat8BitBGRA` (`BGRA`), `bmdFormat10BitRGB` (`r210`), `bmdFormat12BitRGB` (`R12B`), `bmdFormat12BitRGBLE` (`R12L`), `bmdFormat10BitRGBXLE` (`R10l`), `bmdFormat10BitRGBX` (`R10b`), `bmdFormat10BitRGBXLE_FULL` (`R10L`), `bmdFormat10BitRGBX_FULL` (`R10B`)
 * 1080i59.94:
  * Mode: `bmdModeHD1080i5994` (`Hi59`)
  * Resolution: `1920` x `1080`
  * Frame Duration: `1001` / `30000` (`29.970` fps, `33 3666` per frame)
  * Field Dominance: `bmdUpperFieldFirst` (`uppr`)
  * Flags: `bmdDisplayModeSupports3D | bmdDisplayModeColorspaceRec709`
  * Pixel Formats: `bmdFormat8BitYUV` (`2vuy`), `bmdFormat10BitYUV` (`v210`), `bmdFormat8BitARGB`, `bmdFormat8BitBGRA` (`BGRA`), `bmdFormat10BitRGB` (`r210`), `bmdFormat12BitRGB` (`R12B`), `bmdFormat12BitRGBLE` (`R12L`), `bmdFormat10BitRGBXLE` (`R10l`), `bmdFormat10BitRGBX` (`R10b`), `bmdFormat10BitRGBXLE_FULL` (`R10L`), `bmdFormat10BitRGBX_FULL` (`R10B`)
 * 1080i60:
  * Mode: `bmdModeHD1080i6000` (`Hi60`)
  * Resolution: `1920` x `1080`
  * Frame Duration: `1000` / `30000` (`30.000` fps, `33 3333` per frame)
  * Field Dominance: `bmdUpperFieldFirst` (`uppr`)
  * Flags: `bmdDisplayModeSupports3D | bmdDisplayModeColorspaceRec709`
  * Pixel Formats: `bmdFormat8BitYUV` (`2vuy`), `bmdFormat10BitYUV` (`v210`), `bmdFormat8BitARGB`, `bmdFormat8BitBGRA` (`BGRA`), `bmdFormat10BitRGB` (`r210`), `bmdFormat12BitRGB` (`R12B`), `bmdFormat12BitRGBLE` (`R12L`), `bmdFormat10BitRGBXLE` (`R10l`), `bmdFormat10BitRGBX` (`R10b`), `bmdFormat10BitRGBXLE_FULL` (`R10L`), `bmdFormat10BitRGBX_FULL` (`R10B`)
 * 1080p50:
  * Mode: `bmdModeHD1080p50` (`Hp50`)
  * Resolution: `1920` x `1080`
  * Frame Duration: `1000` / `50000` (`50.000` fps, `20 0000` per frame)
  * Field Dominance: `bmdProgressiveFrame` (`prog`)
  * Flags: `bmdDisplayModeColorspaceRec709`
  * Pixel Formats: `bmdFormat8BitYUV` (`2vuy`), `bmdFormat10BitYUV` (`v210`), `bmdFormat8BitARGB`, `bmdFormat8BitBGRA` (`BGRA`), `bmdFormat10BitRGB` (`r210`), `bmdFormat12BitRGB` (`R12B`), `bmdFormat12BitRGBLE` (`R12L`), `bmdFormat10BitRGBXLE` (`R10l`), `bmdFormat10BitRGBX` (`R10b`), `bmdFormat10BitRGBXLE_FULL` (`R10L`), `bmdFormat10BitRGBX_FULL` (`R10B`)
 * 1080p59.94:
  * Mode: `bmdModeHD1080p5994` (`Hp59`)
  * Resolution: `1920` x `1080`
  * Frame Duration: `1001` / `60000` (`59.940` fps, `16 6833` per frame)
  * Field Dominance: `bmdProgressiveFrame` (`prog`)
  * Flags: `bmdDisplayModeColorspaceRec709`
  * Pixel Formats: `bmdFormat8BitYUV` (`2vuy`), `bmdFormat10BitYUV` (`v210`), `bmdFormat8BitARGB`, `bmdFormat8BitBGRA` (`BGRA`), `bmdFormat10BitRGB` (`r210`), `bmdFormat12BitRGB` (`R12B`), `bmdFormat12BitRGBLE` (`R12L`), `bmdFormat10BitRGBXLE` (`R10l`), `bmdFormat10BitRGBX` (`R10b`), `bmdFormat10BitRGBXLE_FULL` (`R10L`), `bmdFormat10BitRGBX_FULL` (`R10B`)
 * 1080p60:
  * Mode: `bmdModeHD1080p6000` (`Hp60`)
  * Resolution: `1920` x `1080`
  * Frame Duration: `1000` / `60000` (`60.000` fps, `16 6666` per frame)
  * Field Dominance: `bmdProgressiveFrame` (`prog`)
  * Flags: `bmdDisplayModeColorspaceRec709`
  * Pixel Formats: `bmdFormat8BitYUV` (`2vuy`), `bmdFormat10BitYUV` (`v210`), `bmdFormat8BitARGB`, `bmdFormat8BitBGRA` (`BGRA`), `bmdFormat10BitRGB` (`r210`), `bmdFormat12BitRGB` (`R12B`), `bmdFormat12BitRGBLE` (`R12L`), `bmdFormat10BitRGBXLE` (`R10l`), `bmdFormat10BitRGBX` (`R10b`), `bmdFormat10BitRGBXLE_FULL` (`R10L`), `bmdFormat10BitRGBX_FULL` (`R10B`)
 * 720p50:
  * Mode: `bmdModeHD720p50` (`hp50`)
  * Resolution: `1280` x `720`
  * Frame Duration: `1000` / `50000` (`50.000` fps, `20 0000` per frame)
  * Field Dominance: `bmdProgressiveFrame` (`prog`)
  * Flags: `bmdDisplayModeSupports3D | bmdDisplayModeColorspaceRec709`
  * Pixel Formats: `bmdFormat8BitYUV` (`2vuy`), `bmdFormat10BitYUV` (`v210`), `bmdFormat8BitARGB`, `bmdFormat8BitBGRA` (`BGRA`), `bmdFormat10BitRGB` (`r210`), `bmdFormat12BitRGB` (`R12B`) (conversion), `bmdFormat12BitRGBLE` (`R12L`) (conversion), `bmdFormat10BitRGBXLE` (`R10l`), `bmdFormat10BitRGBX` (`R10b`), `bmdFormat10BitRGBXLE_FULL` (`R10L`), `bmdFormat10BitRGBX_FULL` (`R10B`)
 * 720p59.94:
  * Mode: `bmdModeHD720p5994` (`hp59`)
  * Resolution: `1280` x `720`
  * Frame Duration: `1001` / `60000` (`59.940` fps, `16 6833` per frame)
  * Field Dominance: `bmdProgressiveFrame` (`prog`)
  * Flags: `bmdDisplayModeSupports3D | bmdDisplayModeColorspaceRec709`
  * Pixel Formats: `bmdFormat8BitYUV` (`2vuy`), `bmdFormat10BitYUV` (`v210`), `bmdFormat8BitARGB`, `bmdFormat8BitBGRA` (`BGRA`), `bmdFormat10BitRGB` (`r210`), `bmdFormat12BitRGB` (`R12B`) (conversion), `bmdFormat12BitRGBLE` (`R12L`) (conversion), `bmdFormat10BitRGBXLE` (`R10l`), `bmdFormat10BitRGBX` (`R10b`), `bmdFormat10BitRGBXLE_FULL` (`R10L`), `bmdFormat10BitRGBX_FULL` (`R10B`)
 * 720p60:
  * Mode: `bmdModeHD720p60` (`hp60`)
  * Resolution: `1280` x `720`
  * Frame Duration: `1000` / `60000` (`60.000` fps, `16 6666` per frame)
  * Field Dominance: `bmdProgressiveFrame` (`prog`)
  * Flags: `bmdDisplayModeSupports3D | bmdDisplayModeColorspaceRec709`
  * Pixel Formats: `bmdFormat8BitYUV` (`2vuy`), `bmdFormat10BitYUV` (`v210`), `bmdFormat8BitARGB`, `bmdFormat8BitBGRA` (`BGRA`), `bmdFormat10BitRGB` (`r210`), `bmdFormat12BitRGB` (`R12B`) (conversion), `bmdFormat12BitRGBLE` (`R12L`) (conversion), `bmdFormat10BitRGBXLE` (`R10l`), `bmdFormat10BitRGBX` (`R10b`), `bmdFormat10BitRGBXLE_FULL` (`R10L`), `bmdFormat10BitRGBX_FULL` (`R10B`)
 * 1080p23.98 DCI 2K:
  * Mode: `bmdMode2kDCI2398` (`2d23`)
  * Resolution: `2048` x `1080`
  * Frame Duration: `1001` / `24000` (`23.976` fps, `41 7083` per frame)
  * Field Dominance: `bmdProgressiveFrame` (`prog`)
  * Flags: `bmdDisplayModeSupports3D | bmdDisplayModeColorspaceRec709`
  * Pixel Formats: `bmdFormat8BitYUV` (`2vuy`), `bmdFormat10BitYUV` (`v210`), `bmdFormat8BitARGB`, `bmdFormat8BitBGRA` (`BGRA`), `bmdFormat10BitRGB` (`r210`), `bmdFormat12BitRGB` (`R12B`), `bmdFormat12BitRGBLE` (`R12L`), `bmdFormat10BitRGBXLE` (`R10l`), `bmdFormat10BitRGBX` (`R10b`), `bmdFormat10BitRGBXLE_FULL` (`R10L`), `bmdFormat10BitRGBX_FULL` (`R10B`)
 * 1080p24 DCI 2K:
  * Mode: `bmdMode2kDCI24` (`2d24`)
  * Resolution: `2048` x `1080`
  * Frame Duration: `1000` / `24000` (`24.000` fps, `41 6666` per frame)
  * Field Dominance: `bmdProgressiveFrame` (`prog`)
  * Flags: `bmdDisplayModeSupports3D | bmdDisplayModeColorspaceRec709`
  * Pixel Formats: `bmdFormat8BitYUV` (`2vuy`), `bmdFormat10BitYUV` (`v210`), `bmdFormat8BitARGB`, `bmdFormat8BitBGRA` (`BGRA`), `bmdFormat10BitRGB` (`r210`), `bmdFormat12BitRGB` (`R12B`), `bmdFormat12BitRGBLE` (`R12L`), `bmdFormat10BitRGBXLE` (`R10l`), `bmdFormat10BitRGBX` (`R10b`), `bmdFormat10BitRGBXLE_FULL` (`R10L`), `bmdFormat10BitRGBX_FULL` (`R10B`)
 * 1080p25 DCI 2K:
  * Mode: `bmdMode2kDCI25` (`2d25`)
  * Resolution: `2048` x `1080`
  * Frame Duration: `1000` / `25000` (`25.000` fps, `40 0000` per frame)
  * Field Dominance: `bmdProgressiveFrame` (`prog`)
  * Flags: `bmdDisplayModeSupports3D | bmdDisplayModeColorspaceRec709`
  * Pixel Formats: `bmdFormat8BitYUV` (`2vuy`), `bmdFormat10BitYUV` (`v210`), `bmdFormat8BitARGB`, `bmdFormat8BitBGRA` (`BGRA`), `bmdFormat10BitRGB` (`r210`), `bmdFormat12BitRGB` (`R12B`), `bmdFormat12BitRGBLE` (`R12L`), `bmdFormat10BitRGBXLE` (`R10l`), `bmdFormat10BitRGBX` (`R10b`), `bmdFormat10BitRGBXLE_FULL` (`R10L`), `bmdFormat10BitRGBX_FULL` (`R10B`)
 * 2160p23.98:
  * Mode: `bmdMode4K2160p2398` (`4k23`)
  * Resolution: `3840` x `2160`
  * Frame Duration: `1001` / `24000` (`23.976` fps, `41 7083` per frame)
  * Field Dominance: `bmdProgressiveFrame` (`prog`)
  * Flags: `bmdDisplayModeColorspaceRec709`
  * Pixel Formats: `bmdFormat8BitYUV` (`2vuy`), `bmdFormat10BitYUV` (`v210`), `bmdFormat8BitARGB`, `bmdFormat8BitBGRA` (`BGRA`), `bmdFormat10BitRGB` (`r210`), `bmdFormat12BitRGB` (`R12B`), `bmdFormat12BitRGBLE` (`R12L`), `bmdFormat10BitRGBXLE` (`R10l`), `bmdFormat10BitRGBX` (`R10b`), `bmdFormat10BitRGBXLE_FULL` (`R10L`), `bmdFormat10BitRGBX_FULL` (`R10B`)
 * 2160p24:
  * Mode: `bmdMode4K2160p24` (`4k24`)
  * Resolution: `3840` x `2160`
  * Frame Duration: `1000` / `24000` (`24.000` fps, `41 6666` per frame)
  * Field Dominance: `bmdProgressiveFrame` (`prog`)
  * Flags: `bmdDisplayModeColorspaceRec709`
  * Pixel Formats: `bmdFormat8BitYUV` (`2vuy`), `bmdFormat10BitYUV` (`v210`), `bmdFormat8BitARGB`, `bmdFormat8BitBGRA` (`BGRA`), `bmdFormat10BitRGB` (`r210`), `bmdFormat12BitRGB` (`R12B`), `bmdFormat12BitRGBLE` (`R12L`), `bmdFormat10BitRGBXLE` (`R10l`), `bmdFormat10BitRGBX` (`R10b`), `bmdFormat10BitRGBXLE_FULL` (`R10L`), `bmdFormat10BitRGBX_FULL` (`R10B`)
 * 2160p25:
  * Mode: `bmdMode4K2160p25` (`4k25`)
  * Resolution: `3840` x `2160`
  * Frame Duration: `1000` / `25000` (`25.000` fps, `40 0000` per frame)
  * Field Dominance: `bmdProgressiveFrame` (`prog`)
  * Flags: `bmdDisplayModeColorspaceRec709`
  * Pixel Formats: `bmdFormat8BitYUV` (`2vuy`), `bmdFormat10BitYUV` (`v210`), `bmdFormat8BitARGB`, `bmdFormat8BitBGRA` (`BGRA`), `bmdFormat10BitRGB` (`r210`), `bmdFormat12BitRGB` (`R12B`), `bmdFormat12BitRGBLE` (`R12L`), `bmdFormat10BitRGBXLE` (`R10l`), `bmdFormat10BitRGBX` (`R10b`), `bmdFormat10BitRGBXLE_FULL` (`R10L`), `bmdFormat10BitRGBX_FULL` (`R10B`)
 * 2160p29.97:
  * Mode: `bmdMode4K2160p2997` (`4k29`)
  * Resolution: `3840` x `2160`
  * Frame Duration: `1001` / `30000` (`29.970` fps, `33 3666` per frame)
  * Field Dominance: `bmdProgressiveFrame` (`prog`)
  * Flags: `bmdDisplayModeColorspaceRec709`
  * Pixel Formats: `bmdFormat8BitYUV` (`2vuy`), `bmdFormat10BitYUV` (`v210`), `bmdFormat8BitARGB`, `bmdFormat8BitBGRA` (`BGRA`), `bmdFormat10BitRGB` (`r210`), `bmdFormat12BitRGB` (`R12B`), `bmdFormat12BitRGBLE` (`R12L`), `bmdFormat10BitRGBXLE` (`R10l`), `bmdFormat10BitRGBX` (`R10b`), `bmdFormat10BitRGBXLE_FULL` (`R10L`), `bmdFormat10BitRGBX_FULL` (`R10B`)
 * 2160p30:
  * Mode: `bmdMode4K2160p30` (`4k30`)
  * Resolution: `3840` x `2160`
  * Frame Duration: `1000` / `30000` (`30.000` fps, `33 3333` per frame)
  * Field Dominance: `bmdProgressiveFrame` (`prog`)
  * Flags: `bmdDisplayModeColorspaceRec709`
  * Pixel Formats: `bmdFormat8BitYUV` (`2vuy`), `bmdFormat10BitYUV` (`v210`), `bmdFormat8BitARGB`, `bmdFormat8BitBGRA` (`BGRA`), `bmdFormat10BitRGB` (`r210`), `bmdFormat12BitRGB` (`R12B`), `bmdFormat12BitRGBLE` (`R12L`), `bmdFormat10BitRGBXLE` (`R10l`), `bmdFormat10BitRGBX` (`R10b`), `bmdFormat10BitRGBXLE_FULL` (`R10L`), `bmdFormat10BitRGBX_FULL` (`R10B`)
 * 2160p50:
  * Mode: `bmdMode4K2160p50` (`4k50`)
  * Resolution: `3840` x `2160`
  * Frame Duration: `1000` / `50000` (`50.000` fps, `20 0000` per frame)
  * Field Dominance: `bmdProgressiveFrame` (`prog`)
  * Flags: `bmdDisplayModeColorspaceRec709`
  * Pixel Formats: `bmdFormat8BitYUV` (`2vuy`), `bmdFormat10BitYUV` (`v210`)
 * 2160p59.94:
  * Mode: `bmdMode4K2160p5994` (`4k59`)
  * Resolution: `3840` x `2160`
  * Frame Duration: `1001` / `60000` (`59.940` fps, `16 6833` per frame)
  * Field Dominance: `bmdProgressiveFrame` (`prog`)
  * Flags: `bmdDisplayModeColorspaceRec709`
  * Pixel Formats: `bmdFormat8BitYUV` (`2vuy`), `bmdFormat10BitYUV` (`v210`)
 * 2160p60:
  * Mode: `bmdMode4K2160p60` (`4k60`)
  * Resolution: `3840` x `2160`
  * Frame Duration: `1000` / `60000` (`60.000` fps, `16 6666` per frame)
  * Field Dominance: `bmdProgressiveFrame` (`prog`)
  * Flags: `bmdDisplayModeColorspaceRec709`
  * Pixel Formats: `bmdFormat8BitYUV` (`2vuy`), `bmdFormat10BitYUV` (`v210`)
 * 2160p23.98 DCI 4K:
  * Mode: `bmdMode4kDCI2398` (`4d23`)
  * Resolution: `4096` x `2160`
  * Frame Duration: `1001` / `24000` (`23.976` fps, `41 7083` per frame)
  * Field Dominance: `bmdProgressiveFrame` (`prog`)
  * Flags: `bmdDisplayModeColorspaceRec709`
  * Pixel Formats: `bmdFormat8BitYUV` (`2vuy`), `bmdFormat10BitYUV` (`v210`), `bmdFormat8BitARGB`, `bmdFormat8BitBGRA` (`BGRA`), `bmdFormat10BitRGB` (`r210`), `bmdFormat12BitRGB` (`R12B`), `bmdFormat12BitRGBLE` (`R12L`), `bmdFormat10BitRGBXLE` (`R10l`), `bmdFormat10BitRGBX` (`R10b`), `bmdFormat10BitRGBXLE_FULL` (`R10L`), `bmdFormat10BitRGBX_FULL` (`R10B`)
 * 2160p24 DCI 4K:
  * Mode: `bmdMode4kDCI24` (`4d24`)
  * Resolution: `4096` x `2160`
  * Frame Duration: `1000` / `24000` (`24.000` fps, `41 6666` per frame)
  * Field Dominance: `bmdProgressiveFrame` (`prog`)
  * Flags: `bmdDisplayModeColorspaceRec709`
  * Pixel Formats: `bmdFormat8BitYUV` (`2vuy`), `bmdFormat10BitYUV` (`v210`), `bmdFormat8BitARGB`, `bmdFormat8BitBGRA` (`BGRA`), `bmdFormat10BitRGB` (`r210`), `bmdFormat12BitRGB` (`R12B`), `bmdFormat12BitRGBLE` (`R12L`), `bmdFormat10BitRGBXLE` (`R10l`), `bmdFormat10BitRGBX` (`R10b`), `bmdFormat10BitRGBXLE_FULL` (`R10L`), `bmdFormat10BitRGBX_FULL` (`R10B`)
 * 2160p25 DCI 4K:
  * Mode: `bmdMode4kDCI25` (`4d25`)
  * Resolution: `4096` x `2160`
  * Frame Duration: `1000` / `25000` (`25.000` fps, `40 0000` per frame)
  * Field Dominance: `bmdProgressiveFrame` (`prog`)
  * Flags: `bmdDisplayModeColorspaceRec709`
  * Pixel Formats: `bmdFormat8BitYUV` (`2vuy`), `bmdFormat10BitYUV` (`v210`), `bmdFormat8BitARGB`, `bmdFormat8BitBGRA` (`BGRA`), `bmdFormat10BitRGB` (`r210`), `bmdFormat12BitRGB` (`R12B`), `bmdFormat12BitRGBLE` (`R12L`), `bmdFormat10BitRGBXLE` (`R10l`), `bmdFormat10BitRGBX` (`R10b`), `bmdFormat10BitRGBXLE_FULL` (`R10L`), `bmdFormat10BitRGBX_FULL` (`R10B`)

TSV Formatted:

	Name	Display Mode	Display Mode FourCC	Resolution Width	Resolution Height	Frame Duration	Time Scale	Frame Rate, per second	Frame Length, millisecond	Field Dominance	Field Dominance FourCC	Display Mode Flags	Pixel Formats
	NTSC	bmdModeNTSC	ntsc	720	486	1001	30000	29.970	333666	bmdLowerFieldFirst	lowr	bmdDisplayModeColorspaceRec601	bmdFormat8BitYUV 2vuy, bmdFormat10BitYUV v210, bmdFormat8BitARGB , bmdFormat8BitBGRA BGRA, bmdFormat10BitRGB r210, bmdFormat10BitRGBXLE R10l, bmdFormat10BitRGBX R10b, bmdFormat10BitRGBXLE_FULL R10L, bmdFormat10BitRGBX_FULL R10B
	PAL	bmdModePAL	pal 	720	576	1000	25000	25.000	400000	bmdUpperFieldFirst	uppr	bmdDisplayModeColorspaceRec601	bmdFormat8BitYUV 2vuy, bmdFormat10BitYUV v210, bmdFormat8BitARGB , bmdFormat8BitBGRA BGRA, bmdFormat10BitRGB r210, bmdFormat10BitRGBXLE R10l, bmdFormat10BitRGBX R10b, bmdFormat10BitRGBXLE_FULL R10L, bmdFormat10BitRGBX_FULL R10B
	1080p23.98	bmdModeHD1080p2398	23ps	1920	1080	1001	24000	23.976	417083	bmdProgressiveFrame	prog	bmdDisplayModeSupports3D | bmdDisplayModeColorspaceRec709	bmdFormat8BitYUV 2vuy, bmdFormat10BitYUV v210, bmdFormat8BitARGB , bmdFormat8BitBGRA BGRA, bmdFormat10BitRGB r210, bmdFormat12BitRGB R12B, bmdFormat12BitRGBLE R12L, bmdFormat10BitRGBXLE R10l, bmdFormat10BitRGBX R10b, bmdFormat10BitRGBXLE_FULL R10L, bmdFormat10BitRGBX_FULL R10B
	1080p24	bmdModeHD1080p24	24ps	1920	1080	1000	24000	24.000	416666	bmdProgressiveFrame	prog	bmdDisplayModeSupports3D | bmdDisplayModeColorspaceRec709	bmdFormat8BitYUV 2vuy, bmdFormat10BitYUV v210, bmdFormat8BitARGB , bmdFormat8BitBGRA BGRA, bmdFormat10BitRGB r210, bmdFormat12BitRGB R12B, bmdFormat12BitRGBLE R12L, bmdFormat10BitRGBXLE R10l, bmdFormat10BitRGBX R10b, bmdFormat10BitRGBXLE_FULL R10L, bmdFormat10BitRGBX_FULL R10B
	1080p25	bmdModeHD1080p25	Hp25	1920	1080	1000	25000	25.000	400000	bmdProgressiveFrame	prog	bmdDisplayModeSupports3D | bmdDisplayModeColorspaceRec709	bmdFormat8BitYUV 2vuy, bmdFormat10BitYUV v210, bmdFormat8BitARGB , bmdFormat8BitBGRA BGRA, bmdFormat10BitRGB r210, bmdFormat12BitRGB R12B, bmdFormat12BitRGBLE R12L, bmdFormat10BitRGBXLE R10l, bmdFormat10BitRGBX R10b, bmdFormat10BitRGBXLE_FULL R10L, bmdFormat10BitRGBX_FULL R10B
	1080p29.97	bmdModeHD1080p2997	Hp29	1920	1080	1001	30000	29.970	333666	bmdProgressiveFrame	prog	bmdDisplayModeSupports3D | bmdDisplayModeColorspaceRec709	bmdFormat8BitYUV 2vuy, bmdFormat10BitYUV v210, bmdFormat8BitARGB , bmdFormat8BitBGRA BGRA, bmdFormat10BitRGB r210, bmdFormat12BitRGB R12B, bmdFormat12BitRGBLE R12L, bmdFormat10BitRGBXLE R10l, bmdFormat10BitRGBX R10b, bmdFormat10BitRGBXLE_FULL R10L, bmdFormat10BitRGBX_FULL R10B
	1080p30	bmdModeHD1080p30	Hp30	1920	1080	1000	30000	30.000	333333	bmdProgressiveFrame	prog	bmdDisplayModeSupports3D | bmdDisplayModeColorspaceRec709	bmdFormat8BitYUV 2vuy, bmdFormat10BitYUV v210, bmdFormat8BitARGB , bmdFormat8BitBGRA BGRA, bmdFormat10BitRGB r210, bmdFormat12BitRGB R12B, bmdFormat12BitRGBLE R12L, bmdFormat10BitRGBXLE R10l, bmdFormat10BitRGBX R10b, bmdFormat10BitRGBXLE_FULL R10L, bmdFormat10BitRGBX_FULL R10B
	1080i50	bmdModeHD1080i50	Hi50	1920	1080	1000	25000	25.000	400000	bmdUpperFieldFirst	uppr	bmdDisplayModeSupports3D | bmdDisplayModeColorspaceRec709	bmdFormat8BitYUV 2vuy, bmdFormat10BitYUV v210, bmdFormat8BitARGB , bmdFormat8BitBGRA BGRA, bmdFormat10BitRGB r210, bmdFormat12BitRGB R12B, bmdFormat12BitRGBLE R12L, bmdFormat10BitRGBXLE R10l, bmdFormat10BitRGBX R10b, bmdFormat10BitRGBXLE_FULL R10L, bmdFormat10BitRGBX_FULL R10B
	1080i59.94	bmdModeHD1080i5994	Hi59	1920	1080	1001	30000	29.970	333666	bmdUpperFieldFirst	uppr	bmdDisplayModeSupports3D | bmdDisplayModeColorspaceRec709	bmdFormat8BitYUV 2vuy, bmdFormat10BitYUV v210, bmdFormat8BitARGB , bmdFormat8BitBGRA BGRA, bmdFormat10BitRGB r210, bmdFormat12BitRGB R12B, bmdFormat12BitRGBLE R12L, bmdFormat10BitRGBXLE R10l, bmdFormat10BitRGBX R10b, bmdFormat10BitRGBXLE_FULL R10L, bmdFormat10BitRGBX_FULL R10B
	1080i60	bmdModeHD1080i6000	Hi60	1920	1080	1000	30000	30.000	333333	bmdUpperFieldFirst	uppr	bmdDisplayModeSupports3D | bmdDisplayModeColorspaceRec709	bmdFormat8BitYUV 2vuy, bmdFormat10BitYUV v210, bmdFormat8BitARGB , bmdFormat8BitBGRA BGRA, bmdFormat10BitRGB r210, bmdFormat12BitRGB R12B, bmdFormat12BitRGBLE R12L, bmdFormat10BitRGBXLE R10l, bmdFormat10BitRGBX R10b, bmdFormat10BitRGBXLE_FULL R10L, bmdFormat10BitRGBX_FULL R10B
	1080p50	bmdModeHD1080p50	Hp50	1920	1080	1000	50000	50.000	200000	bmdProgressiveFrame	prog	bmdDisplayModeColorspaceRec709	bmdFormat8BitYUV 2vuy, bmdFormat10BitYUV v210, bmdFormat8BitARGB , bmdFormat8BitBGRA BGRA, bmdFormat10BitRGB r210, bmdFormat12BitRGB R12B, bmdFormat12BitRGBLE R12L, bmdFormat10BitRGBXLE R10l, bmdFormat10BitRGBX R10b, bmdFormat10BitRGBXLE_FULL R10L, bmdFormat10BitRGBX_FULL R10B
	1080p59.94	bmdModeHD1080p5994	Hp59	1920	1080	1001	60000	59.940	166833	bmdProgressiveFrame	prog	bmdDisplayModeColorspaceRec709	bmdFormat8BitYUV 2vuy, bmdFormat10BitYUV v210, bmdFormat8BitARGB , bmdFormat8BitBGRA BGRA, bmdFormat10BitRGB r210, bmdFormat12BitRGB R12B, bmdFormat12BitRGBLE R12L, bmdFormat10BitRGBXLE R10l, bmdFormat10BitRGBX R10b, bmdFormat10BitRGBXLE_FULL R10L, bmdFormat10BitRGBX_FULL R10B
	1080p60	bmdModeHD1080p6000	Hp60	1920	1080	1000	60000	60.000	166666	bmdProgressiveFrame	prog	bmdDisplayModeColorspaceRec709	bmdFormat8BitYUV 2vuy, bmdFormat10BitYUV v210, bmdFormat8BitARGB , bmdFormat8BitBGRA BGRA, bmdFormat10BitRGB r210, bmdFormat12BitRGB R12B, bmdFormat12BitRGBLE R12L, bmdFormat10BitRGBXLE R10l, bmdFormat10BitRGBX R10b, bmdFormat10BitRGBXLE_FULL R10L, bmdFormat10BitRGBX_FULL R10B
	720p50	bmdModeHD720p50	hp50	1280	720	1000	50000	50.000	200000	bmdProgressiveFrame	prog	bmdDisplayModeSupports3D | bmdDisplayModeColorspaceRec709	bmdFormat8BitYUV 2vuy, bmdFormat10BitYUV v210, bmdFormat8BitARGB , bmdFormat8BitBGRA BGRA, bmdFormat10BitRGB r210, bmdFormat12BitRGB R12B (conversion), bmdFormat12BitRGBLE R12L (conversion), bmdFormat10BitRGBXLE R10l, bmdFormat10BitRGBX R10b, bmdFormat10BitRGBXLE_FULL R10L, bmdFormat10BitRGBX_FULL R10B
	720p59.94	bmdModeHD720p5994	hp59	1280	720	1001	60000	59.940	166833	bmdProgressiveFrame	prog	bmdDisplayModeSupports3D | bmdDisplayModeColorspaceRec709	bmdFormat8BitYUV 2vuy, bmdFormat10BitYUV v210, bmdFormat8BitARGB , bmdFormat8BitBGRA BGRA, bmdFormat10BitRGB r210, bmdFormat12BitRGB R12B (conversion), bmdFormat12BitRGBLE R12L (conversion), bmdFormat10BitRGBXLE R10l, bmdFormat10BitRGBX R10b, bmdFormat10BitRGBXLE_FULL R10L, bmdFormat10BitRGBX_FULL R10B
	720p60	bmdModeHD720p60	hp60	1280	720	1000	60000	60.000	166666	bmdProgressiveFrame	prog	bmdDisplayModeSupports3D | bmdDisplayModeColorspaceRec709	bmdFormat8BitYUV 2vuy, bmdFormat10BitYUV v210, bmdFormat8BitARGB , bmdFormat8BitBGRA BGRA, bmdFormat10BitRGB r210, bmdFormat12BitRGB R12B (conversion), bmdFormat12BitRGBLE R12L (conversion), bmdFormat10BitRGBXLE R10l, bmdFormat10BitRGBX R10b, bmdFormat10BitRGBXLE_FULL R10L, bmdFormat10BitRGBX_FULL R10B
	1080p23.98 DCI 2K	bmdMode2kDCI2398	2d23	2048	1080	1001	24000	23.976	417083	bmdProgressiveFrame	prog	bmdDisplayModeSupports3D | bmdDisplayModeColorspaceRec709	bmdFormat8BitYUV 2vuy, bmdFormat10BitYUV v210, bmdFormat8BitARGB , bmdFormat8BitBGRA BGRA, bmdFormat10BitRGB r210, bmdFormat12BitRGB R12B, bmdFormat12BitRGBLE R12L, bmdFormat10BitRGBXLE R10l, bmdFormat10BitRGBX R10b, bmdFormat10BitRGBXLE_FULL R10L, bmdFormat10BitRGBX_FULL R10B
	1080p24 DCI 2K	bmdMode2kDCI24	2d24	2048	1080	1000	24000	24.000	416666	bmdProgressiveFrame	prog	bmdDisplayModeSupports3D | bmdDisplayModeColorspaceRec709	bmdFormat8BitYUV 2vuy, bmdFormat10BitYUV v210, bmdFormat8BitARGB , bmdFormat8BitBGRA BGRA, bmdFormat10BitRGB r210, bmdFormat12BitRGB R12B, bmdFormat12BitRGBLE R12L, bmdFormat10BitRGBXLE R10l, bmdFormat10BitRGBX R10b, bmdFormat10BitRGBXLE_FULL R10L, bmdFormat10BitRGBX_FULL R10B
	1080p25 DCI 2K	bmdMode2kDCI25	2d25	2048	1080	1000	25000	25.000	400000	bmdProgressiveFrame	prog	bmdDisplayModeSupports3D | bmdDisplayModeColorspaceRec709	bmdFormat8BitYUV 2vuy, bmdFormat10BitYUV v210, bmdFormat8BitARGB , bmdFormat8BitBGRA BGRA, bmdFormat10BitRGB r210, bmdFormat12BitRGB R12B, bmdFormat12BitRGBLE R12L, bmdFormat10BitRGBXLE R10l, bmdFormat10BitRGBX R10b, bmdFormat10BitRGBXLE_FULL R10L, bmdFormat10BitRGBX_FULL R10B
	2160p23.98	bmdMode4K2160p2398	4k23	3840	2160	1001	24000	23.976	417083	bmdProgressiveFrame	prog	bmdDisplayModeColorspaceRec709	bmdFormat8BitYUV 2vuy, bmdFormat10BitYUV v210, bmdFormat8BitARGB , bmdFormat8BitBGRA BGRA, bmdFormat10BitRGB r210, bmdFormat12BitRGB R12B, bmdFormat12BitRGBLE R12L, bmdFormat10BitRGBXLE R10l, bmdFormat10BitRGBX R10b, bmdFormat10BitRGBXLE_FULL R10L, bmdFormat10BitRGBX_FULL R10B
	2160p24	bmdMode4K2160p24	4k24	3840	2160	1000	24000	24.000	416666	bmdProgressiveFrame	prog	bmdDisplayModeColorspaceRec709	bmdFormat8BitYUV 2vuy, bmdFormat10BitYUV v210, bmdFormat8BitARGB , bmdFormat8BitBGRA BGRA, bmdFormat10BitRGB r210, bmdFormat12BitRGB R12B, bmdFormat12BitRGBLE R12L, bmdFormat10BitRGBXLE R10l, bmdFormat10BitRGBX R10b, bmdFormat10BitRGBXLE_FULL R10L, bmdFormat10BitRGBX_FULL R10B
	2160p25	bmdMode4K2160p25	4k25	3840	2160	1000	25000	25.000	400000	bmdProgressiveFrame	prog	bmdDisplayModeColorspaceRec709	bmdFormat8BitYUV 2vuy, bmdFormat10BitYUV v210, bmdFormat8BitARGB , bmdFormat8BitBGRA BGRA, bmdFormat10BitRGB r210, bmdFormat12BitRGB R12B, bmdFormat12BitRGBLE R12L, bmdFormat10BitRGBXLE R10l, bmdFormat10BitRGBX R10b, bmdFormat10BitRGBXLE_FULL R10L, bmdFormat10BitRGBX_FULL R10B
	2160p29.97	bmdMode4K2160p2997	4k29	3840	2160	1001	30000	29.970	333666	bmdProgressiveFrame	prog	bmdDisplayModeColorspaceRec709	bmdFormat8BitYUV 2vuy, bmdFormat10BitYUV v210, bmdFormat8BitARGB , bmdFormat8BitBGRA BGRA, bmdFormat10BitRGB r210, bmdFormat12BitRGB R12B, bmdFormat12BitRGBLE R12L, bmdFormat10BitRGBXLE R10l, bmdFormat10BitRGBX R10b, bmdFormat10BitRGBXLE_FULL R10L, bmdFormat10BitRGBX_FULL R10B
	2160p30	bmdMode4K2160p30	4k30	3840	2160	1000	30000	30.000	333333	bmdProgressiveFrame	prog	bmdDisplayModeColorspaceRec709	bmdFormat8BitYUV 2vuy, bmdFormat10BitYUV v210, bmdFormat8BitARGB , bmdFormat8BitBGRA BGRA, bmdFormat10BitRGB r210, bmdFormat12BitRGB R12B, bmdFormat12BitRGBLE R12L, bmdFormat10BitRGBXLE R10l, bmdFormat10BitRGBX R10b, bmdFormat10BitRGBXLE_FULL R10L, bmdFormat10BitRGBX_FULL R10B
	2160p50	bmdMode4K2160p50	4k50	3840	2160	1000	50000	50.000	200000	bmdProgressiveFrame	prog	bmdDisplayModeColorspaceRec709	bmdFormat8BitYUV 2vuy, bmdFormat10BitYUV v210
	2160p59.94	bmdMode4K2160p5994	4k59	3840	2160	1001	60000	59.940	166833	bmdProgressiveFrame	prog	bmdDisplayModeColorspaceRec709	bmdFormat8BitYUV 2vuy, bmdFormat10BitYUV v210
	2160p60	bmdMode4K2160p60	4k60	3840	2160	1000	60000	60.000	166666	bmdProgressiveFrame	prog	bmdDisplayModeColorspaceRec709	bmdFormat8BitYUV 2vuy, bmdFormat10BitYUV v210
	2160p23.98 DCI 4K	bmdMode4kDCI2398	4d23	4096	2160	1001	24000	23.976	417083	bmdProgressiveFrame	prog	bmdDisplayModeColorspaceRec709	bmdFormat8BitYUV 2vuy, bmdFormat10BitYUV v210, bmdFormat8BitARGB , bmdFormat8BitBGRA BGRA, bmdFormat10BitRGB r210, bmdFormat12BitRGB R12B, bmdFormat12BitRGBLE R12L, bmdFormat10BitRGBXLE R10l, bmdFormat10BitRGBX R10b, bmdFormat10BitRGBXLE_FULL R10L, bmdFormat10BitRGBX_FULL R10B
	2160p24 DCI 4K	bmdMode4kDCI24	4d24	4096	2160	1000	24000	24.000	416666	bmdProgressiveFrame	prog	bmdDisplayModeColorspaceRec709	bmdFormat8BitYUV 2vuy, bmdFormat10BitYUV v210, bmdFormat8BitARGB , bmdFormat8BitBGRA BGRA, bmdFormat10BitRGB r210, bmdFormat12BitRGB R12B, bmdFormat12BitRGBLE R12L, bmdFormat10BitRGBXLE R10l, bmdFormat10BitRGBX R10b, bmdFormat10BitRGBXLE_FULL R10L, bmdFormat10BitRGBX_FULL R10B
	2160p25 DCI 4K	bmdMode4kDCI25	4d25	4096	2160	1000	25000	25.000	400000	bmdProgressiveFrame	prog	bmdDisplayModeColorspaceRec709	bmdFormat8BitYUV 2vuy, bmdFormat10BitYUV v210, bmdFormat8BitARGB , bmdFormat8BitBGRA BGRA, bmdFormat10BitRGB r210, bmdFormat12BitRGB R12B, bmdFormat12BitRGBLE R12L, bmdFormat10BitRGBXLE R10l, bmdFormat10BitRGBX R10b, bmdFormat10BitRGBXLE_FULL R10L, bmdFormat10BitRGBX_FULL R10B



