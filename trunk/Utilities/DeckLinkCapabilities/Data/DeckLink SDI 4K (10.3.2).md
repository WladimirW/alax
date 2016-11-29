

# System

 * Version: 6.1.7601, Windows 7, Service Pack 1.0, VER_SUITE_SINGLEUSERTS, VER_NT_WORKSTATION
 * Product: PRODUCT_PROFESSIONAL
 * Computer Name: ``
 * User Name: `WINDOWS-9ISNH1I\SYMBIOZ` 
 * Local Time: `11/28/2016 9:22:28 PM`
 * Architecture: x86
 * Processors: `8`, Active Mask `0xFF`
 * Page Size: `0x1000`
 * Application Address Space: `0x00010000`..`0xFFFEFFFF`
 * Physical Memory: `4,003` MB
 * Committed Memory Limit: `8,005` MB
 * Application Version: `1.0.0.503`

# Devices

## `GUID_DEVCLASS_MEDIA`

 * Realtek High Definition Audio
  * Instance: HDAUDIO\FUNC_01&VEN_10EC&DEV_0262&SUBSYS_10EC0262&REV_1003\4&2ABAEA17&0&0001
  * DEVPKEY_Device_Manufacturer: Realtek
  * DEVPKEY_Device_DriverVersion: 6.0.1.7054
 * Blackmagic Audio
  * Instance: DECKLINK\AUDIO\5&12ABE8E&0&0000
  * DEVPKEY_Device_Manufacturer: Blackmagic Design
  * DEVPKEY_Device_DriverVersion: 10.3.2.0
 * Blackmagic DeckLink SDI 4K
  * Instance: PCI\VEN_BDBD&DEV_A138&SUBSYS_A138BDBD&REV_00\4&295CAE01&0&0008
  * DEVPKEY_Device_Manufacturer: Blackmagic Design
  * DEVPKEY_Device_DriverVersion: 10.3.2.0

# DeckLink API

## API Information

  * 64-Bit Integer `BMDDeckLinkAPIVersion`: `167969280` (`0xA030200`) // 10.3.2
  * Flag (32-Bit Integer) `BMDDeckLinkAPIEngineeringMode`: `1` (`0x1`)

## DeckLink SDI 4K (DeckLink SDI 4K)

 * Model Name: DeckLink SDI 4K
 * Display Name: DeckLink SDI 4K
 * Interfaces:
  * `IDeckLink`
  * `IDeckLink_v8_0`
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
  * Flag (32-Bit Integer) `BMDDeckLinkSupportsExternalKeying`: `0` (`0x0`)
  * Flag (32-Bit Integer) `BMDDeckLinkSupportsHDKeying`: `1` (`0x1`)
  * Flag (32-Bit Integer) `BMDDeckLinkSupportsInputFormatDetection`: `1` (`0x1`)
  * Flag (32-Bit Integer) `BMDDeckLinkHasReferenceInput`: `1` (`0x1`)
  * Flag (32-Bit Integer) `BMDDeckLinkHasSerialPort`: `1` (`0x1`)
  * Flag (32-Bit Integer) `BMDDeckLinkHasVideoInputAntiAliasingFilter`: `0` (`0x0`)
  * Flag (32-Bit Integer) `BMDDeckLinkHasBypass`: `0` (`0x0`)
  * Flag (32-Bit Integer) `BMDDeckLinkSupportsClockTimingAdjustment`: `0` (`0x0`)
  * Flag (32-Bit Integer) `BMDDeckLinkSupportsFullDuplex`: `1` (`0x1`)
  * Flag (32-Bit Integer) `BMDDeckLinkSupportsFullFrameReferenceInputTimingOffset`: `1` (`0x1`)
  * 64-Bit Integer `BMDDeckLinkMaximumAudioChannels`: `16` (`0x10`)
  * 64-Bit Integer `BMDDeckLinkNumberOfSubDevices`: `1` (`0x1`)
  * 64-Bit Integer `BMDDeckLinkSubDeviceIndex`: `0` (`0x0`)
  * 64-Bit Integer `BMDDeckLinkPersistentID`: `1010099457` (`0x3C34E501`)
  * 64-Bit Integer `BMDDeckLinkTopologicalID`: `4653312` (`0x470100`)
  * 64-Bit Integer `BMDDeckLinkVideoOutputConnections`: `1` (`0x1`) // `bmdVideoConnectionSDI`
  * 64-Bit Integer `BMDDeckLinkVideoInputConnections`: `1` (`0x1`) // `bmdVideoConnectionSDI`
  * 64-Bit Integer `BMDDeckLinkAudioOutputConnections`: `1` (`0x1`) // `bmdAudioConnectionEmbedded`
  * 64-Bit Integer `BMDDeckLinkAudioInputConnections`: `1` (`0x1`) // `bmdAudioConnectionEmbedded`
  * 64-Bit Integer `BMDDeckLinkVideoIOSupport`: `3` (`0x3`)

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
 * HD 1080p 23.98:
  * Mode: `bmdModeHD1080p2398` (`23ps`)
  * Resolution: `1920` x `1080`
  * Frame Duration: `1001` / `24000` (`23.976` fps, `41 7083` per frame)
  * Field Dominance: `bmdProgressiveFrame` (`prog`)
  * Flags: `bmdDisplayModeColorspaceRec709`
  * Pixel Formats: `bmdFormat8BitYUV` (`2vuy`), `bmdFormat10BitYUV` (`v210`), `bmdFormat8BitARGB`, `bmdFormat8BitBGRA` (`BGRA`), `bmdFormat10BitRGB` (`r210`), `bmdFormat10BitRGBXLE` (`R10l`), `bmdFormat10BitRGBX` (`R10b`), `bmdFormat10BitRGBXLE_FULL` (`R10L`), `bmdFormat10BitRGBX_FULL` (`R10B`)
 * HD 1080p 24:
  * Mode: `bmdModeHD1080p24` (`24ps`)
  * Resolution: `1920` x `1080`
  * Frame Duration: `1000` / `24000` (`24.000` fps, `41 6666` per frame)
  * Field Dominance: `bmdProgressiveFrame` (`prog`)
  * Flags: `bmdDisplayModeColorspaceRec709`
  * Pixel Formats: `bmdFormat8BitYUV` (`2vuy`), `bmdFormat10BitYUV` (`v210`), `bmdFormat8BitARGB`, `bmdFormat8BitBGRA` (`BGRA`), `bmdFormat10BitRGB` (`r210`), `bmdFormat10BitRGBXLE` (`R10l`), `bmdFormat10BitRGBX` (`R10b`), `bmdFormat10BitRGBXLE_FULL` (`R10L`), `bmdFormat10BitRGBX_FULL` (`R10B`)
 * HD 1080p 25:
  * Mode: `bmdModeHD1080p25` (`Hp25`)
  * Resolution: `1920` x `1080`
  * Frame Duration: `1000` / `25000` (`25.000` fps, `40 0000` per frame)
  * Field Dominance: `bmdProgressiveFrame` (`prog`)
  * Flags: `bmdDisplayModeColorspaceRec709`
  * Pixel Formats: `bmdFormat8BitYUV` (`2vuy`), `bmdFormat10BitYUV` (`v210`), `bmdFormat8BitARGB`, `bmdFormat8BitBGRA` (`BGRA`), `bmdFormat10BitRGB` (`r210`), `bmdFormat10BitRGBXLE` (`R10l`), `bmdFormat10BitRGBX` (`R10b`), `bmdFormat10BitRGBXLE_FULL` (`R10L`), `bmdFormat10BitRGBX_FULL` (`R10B`)
 * HD 1080p 29.97:
  * Mode: `bmdModeHD1080p2997` (`Hp29`)
  * Resolution: `1920` x `1080`
  * Frame Duration: `1001` / `30000` (`29.970` fps, `33 3666` per frame)
  * Field Dominance: `bmdProgressiveFrame` (`prog`)
  * Flags: `bmdDisplayModeColorspaceRec709`
  * Pixel Formats: `bmdFormat8BitYUV` (`2vuy`), `bmdFormat10BitYUV` (`v210`), `bmdFormat8BitARGB`, `bmdFormat8BitBGRA` (`BGRA`), `bmdFormat10BitRGB` (`r210`), `bmdFormat10BitRGBXLE` (`R10l`), `bmdFormat10BitRGBX` (`R10b`), `bmdFormat10BitRGBXLE_FULL` (`R10L`), `bmdFormat10BitRGBX_FULL` (`R10B`)
 * HD 1080p 30:
  * Mode: `bmdModeHD1080p30` (`Hp30`)
  * Resolution: `1920` x `1080`
  * Frame Duration: `1000` / `30000` (`30.000` fps, `33 3333` per frame)
  * Field Dominance: `bmdProgressiveFrame` (`prog`)
  * Flags: `bmdDisplayModeColorspaceRec709`
  * Pixel Formats: `bmdFormat8BitYUV` (`2vuy`), `bmdFormat10BitYUV` (`v210`), `bmdFormat8BitARGB`, `bmdFormat8BitBGRA` (`BGRA`), `bmdFormat10BitRGB` (`r210`), `bmdFormat10BitRGBXLE` (`R10l`), `bmdFormat10BitRGBX` (`R10b`), `bmdFormat10BitRGBXLE_FULL` (`R10L`), `bmdFormat10BitRGBX_FULL` (`R10B`)
 * HD 1080i 50:
  * Mode: `bmdModeHD1080i50` (`Hi50`)
  * Resolution: `1920` x `1080`
  * Frame Duration: `1000` / `25000` (`25.000` fps, `40 0000` per frame)
  * Field Dominance: `bmdUpperFieldFirst` (`uppr`)
  * Flags: `bmdDisplayModeColorspaceRec709`
  * Pixel Formats: `bmdFormat8BitYUV` (`2vuy`), `bmdFormat10BitYUV` (`v210`), `bmdFormat8BitARGB`, `bmdFormat8BitBGRA` (`BGRA`), `bmdFormat10BitRGB` (`r210`), `bmdFormat10BitRGBXLE` (`R10l`), `bmdFormat10BitRGBX` (`R10b`), `bmdFormat10BitRGBXLE_FULL` (`R10L`), `bmdFormat10BitRGBX_FULL` (`R10B`)
 * HD 1080i 59.94:
  * Mode: `bmdModeHD1080i5994` (`Hi59`)
  * Resolution: `1920` x `1080`
  * Frame Duration: `1001` / `30000` (`29.970` fps, `33 3666` per frame)
  * Field Dominance: `bmdUpperFieldFirst` (`uppr`)
  * Flags: `bmdDisplayModeColorspaceRec709`
  * Pixel Formats: `bmdFormat8BitYUV` (`2vuy`), `bmdFormat10BitYUV` (`v210`), `bmdFormat8BitARGB`, `bmdFormat8BitBGRA` (`BGRA`), `bmdFormat10BitRGB` (`r210`), `bmdFormat10BitRGBXLE` (`R10l`), `bmdFormat10BitRGBX` (`R10b`), `bmdFormat10BitRGBXLE_FULL` (`R10L`), `bmdFormat10BitRGBX_FULL` (`R10B`)
 * HD 1080i 60:
  * Mode: `bmdModeHD1080i6000` (`Hi60`)
  * Resolution: `1920` x `1080`
  * Frame Duration: `1000` / `30000` (`30.000` fps, `33 3333` per frame)
  * Field Dominance: `bmdUpperFieldFirst` (`uppr`)
  * Flags: `bmdDisplayModeColorspaceRec709`
  * Pixel Formats: `bmdFormat8BitYUV` (`2vuy`), `bmdFormat10BitYUV` (`v210`), `bmdFormat8BitARGB`, `bmdFormat8BitBGRA` (`BGRA`), `bmdFormat10BitRGB` (`r210`), `bmdFormat10BitRGBXLE` (`R10l`), `bmdFormat10BitRGBX` (`R10b`), `bmdFormat10BitRGBXLE_FULL` (`R10L`), `bmdFormat10BitRGBX_FULL` (`R10B`)
 * HD 1080p 50:
  * Mode: `bmdModeHD1080p50` (`Hp50`)
  * Resolution: `1920` x `1080`
  * Frame Duration: `1000` / `50000` (`50.000` fps, `20 0000` per frame)
  * Field Dominance: `bmdProgressiveFrame` (`prog`)
  * Flags: `bmdDisplayModeColorspaceRec709`
  * Pixel Formats: `bmdFormat8BitYUV` (`2vuy`), `bmdFormat10BitYUV` (`v210`)
 * HD 1080p 59.94:
  * Mode: `bmdModeHD1080p5994` (`Hp59`)
  * Resolution: `1920` x `1080`
  * Frame Duration: `1001` / `60000` (`59.940` fps, `16 6833` per frame)
  * Field Dominance: `bmdProgressiveFrame` (`prog`)
  * Flags: `bmdDisplayModeColorspaceRec709`
  * Pixel Formats: `bmdFormat8BitYUV` (`2vuy`), `bmdFormat10BitYUV` (`v210`)
 * HD 1080p 60:
  * Mode: `bmdModeHD1080p6000` (`Hp60`)
  * Resolution: `1920` x `1080`
  * Frame Duration: `1000` / `60000` (`60.000` fps, `16 6666` per frame)
  * Field Dominance: `bmdProgressiveFrame` (`prog`)
  * Flags: `bmdDisplayModeColorspaceRec709`
  * Pixel Formats: `bmdFormat8BitYUV` (`2vuy`), `bmdFormat10BitYUV` (`v210`)
 * HD 720p 50:
  * Mode: `bmdModeHD720p50` (`hp50`)
  * Resolution: `1280` x `720`
  * Frame Duration: `1000` / `50000` (`50.000` fps, `20 0000` per frame)
  * Field Dominance: `bmdProgressiveFrame` (`prog`)
  * Flags: `bmdDisplayModeColorspaceRec709`
  * Pixel Formats: `bmdFormat8BitYUV` (`2vuy`), `bmdFormat10BitYUV` (`v210`)
 * HD 720p 59.94:
  * Mode: `bmdModeHD720p5994` (`hp59`)
  * Resolution: `1280` x `720`
  * Frame Duration: `1001` / `60000` (`59.940` fps, `16 6833` per frame)
  * Field Dominance: `bmdProgressiveFrame` (`prog`)
  * Flags: `bmdDisplayModeColorspaceRec709`
  * Pixel Formats: `bmdFormat8BitYUV` (`2vuy`), `bmdFormat10BitYUV` (`v210`)
 * HD 720p 60:
  * Mode: `bmdModeHD720p60` (`hp60`)
  * Resolution: `1280` x `720`
  * Frame Duration: `1000` / `60000` (`60.000` fps, `16 6666` per frame)
  * Field Dominance: `bmdProgressiveFrame` (`prog`)
  * Flags: `bmdDisplayModeColorspaceRec709`
  * Pixel Formats: `bmdFormat8BitYUV` (`2vuy`), `bmdFormat10BitYUV` (`v210`)
 * 2K DCI 23.98:
  * Mode: `bmdMode2kDCI2398` (`2d23`)
  * Resolution: `2048` x `1080`
  * Frame Duration: `1001` / `24000` (`23.976` fps, `41 7083` per frame)
  * Field Dominance: `bmdProgressiveFrame` (`prog`)
  * Flags: `bmdDisplayModeColorspaceRec709`
  * Pixel Formats: `bmdFormat8BitYUV` (`2vuy`), `bmdFormat10BitYUV` (`v210`), `bmdFormat8BitARGB`, `bmdFormat8BitBGRA` (`BGRA`), `bmdFormat10BitRGB` (`r210`), `bmdFormat10BitRGBXLE` (`R10l`), `bmdFormat10BitRGBX` (`R10b`), `bmdFormat10BitRGBXLE_FULL` (`R10L`), `bmdFormat10BitRGBX_FULL` (`R10B`)
 * 2K DCI 24:
  * Mode: `bmdMode2kDCI24` (`2d24`)
  * Resolution: `2048` x `1080`
  * Frame Duration: `1000` / `24000` (`24.000` fps, `41 6666` per frame)
  * Field Dominance: `bmdProgressiveFrame` (`prog`)
  * Flags: `bmdDisplayModeColorspaceRec709`
  * Pixel Formats: `bmdFormat8BitYUV` (`2vuy`), `bmdFormat10BitYUV` (`v210`), `bmdFormat8BitARGB`, `bmdFormat8BitBGRA` (`BGRA`), `bmdFormat10BitRGB` (`r210`), `bmdFormat10BitRGBXLE` (`R10l`), `bmdFormat10BitRGBX` (`R10b`), `bmdFormat10BitRGBXLE_FULL` (`R10L`), `bmdFormat10BitRGBX_FULL` (`R10B`)
 * 2K DCI 25:
  * Mode: `bmdMode2kDCI25` (`2d25`)
  * Resolution: `2048` x `1080`
  * Frame Duration: `1000` / `25000` (`25.000` fps, `40 0000` per frame)
  * Field Dominance: `bmdProgressiveFrame` (`prog`)
  * Flags: `bmdDisplayModeColorspaceRec709`
  * Pixel Formats: `bmdFormat8BitYUV` (`2vuy`), `bmdFormat10BitYUV` (`v210`), `bmdFormat8BitARGB`, `bmdFormat8BitBGRA` (`BGRA`), `bmdFormat10BitRGB` (`r210`), `bmdFormat10BitRGBXLE` (`R10l`), `bmdFormat10BitRGBX` (`R10b`), `bmdFormat10BitRGBXLE_FULL` (`R10L`), `bmdFormat10BitRGBX_FULL` (`R10B`)
 * 4K Ultra HD 23.98:
  * Mode: `bmdMode4K2160p2398` (`4k23`)
  * Resolution: `3840` x `2160`
  * Frame Duration: `1001` / `24000` (`23.976` fps, `41 7083` per frame)
  * Field Dominance: `bmdProgressiveFrame` (`prog`)
  * Flags: `bmdDisplayModeColorspaceRec709`
  * Pixel Formats: `bmdFormat8BitYUV` (`2vuy`), `bmdFormat10BitYUV` (`v210`)
 * 4K Ultra HD 24:
  * Mode: `bmdMode4K2160p24` (`4k24`)
  * Resolution: `3840` x `2160`
  * Frame Duration: `1000` / `24000` (`24.000` fps, `41 6666` per frame)
  * Field Dominance: `bmdProgressiveFrame` (`prog`)
  * Flags: `bmdDisplayModeColorspaceRec709`
  * Pixel Formats: `bmdFormat8BitYUV` (`2vuy`), `bmdFormat10BitYUV` (`v210`)
 * 4K Ultra HD 25:
  * Mode: `bmdMode4K2160p25` (`4k25`)
  * Resolution: `3840` x `2160`
  * Frame Duration: `1000` / `25000` (`25.000` fps, `40 0000` per frame)
  * Field Dominance: `bmdProgressiveFrame` (`prog`)
  * Flags: `bmdDisplayModeColorspaceRec709`
  * Pixel Formats: `bmdFormat8BitYUV` (`2vuy`), `bmdFormat10BitYUV` (`v210`)
 * 4K Ultra HD 29.97:
  * Mode: `bmdMode4K2160p2997` (`4k29`)
  * Resolution: `3840` x `2160`
  * Frame Duration: `1001` / `30000` (`29.970` fps, `33 3666` per frame)
  * Field Dominance: `bmdProgressiveFrame` (`prog`)
  * Flags: `bmdDisplayModeColorspaceRec709`
  * Pixel Formats: `bmdFormat8BitYUV` (`2vuy`), `bmdFormat10BitYUV` (`v210`)
 * 4K Ultra HD 30:
  * Mode: `bmdMode4K2160p30` (`4k30`)
  * Resolution: `3840` x `2160`
  * Frame Duration: `1000` / `30000` (`30.000` fps, `33 3333` per frame)
  * Field Dominance: `bmdProgressiveFrame` (`prog`)
  * Flags: `bmdDisplayModeColorspaceRec709`
  * Pixel Formats: `bmdFormat8BitYUV` (`2vuy`), `bmdFormat10BitYUV` (`v210`)
 * 4K DCI 23.98:
  * Mode: `bmdMode4kDCI2398` (`4d23`)
  * Resolution: `4096` x `2160`
  * Frame Duration: `1001` / `24000` (`23.976` fps, `41 7083` per frame)
  * Field Dominance: `bmdProgressiveFrame` (`prog`)
  * Flags: `bmdDisplayModeColorspaceRec709`
  * Pixel Formats: `bmdFormat8BitYUV` (`2vuy`), `bmdFormat10BitYUV` (`v210`)
 * 4K DCI 24:
  * Mode: `bmdMode4kDCI24` (`4d24`)
  * Resolution: `4096` x `2160`
  * Frame Duration: `1000` / `24000` (`24.000` fps, `41 6666` per frame)
  * Field Dominance: `bmdProgressiveFrame` (`prog`)
  * Flags: `bmdDisplayModeColorspaceRec709`
  * Pixel Formats: `bmdFormat8BitYUV` (`2vuy`), `bmdFormat10BitYUV` (`v210`)
 * 4K DCI 25:
  * Mode: `bmdMode4kDCI25` (`4d25`)
  * Resolution: `4096` x `2160`
  * Frame Duration: `1000` / `25000` (`25.000` fps, `40 0000` per frame)
  * Field Dominance: `bmdProgressiveFrame` (`prog`)
  * Flags: `bmdDisplayModeColorspaceRec709`
  * Pixel Formats: `bmdFormat8BitYUV` (`2vuy`), `bmdFormat10BitYUV` (`v210`)

TSV Formatted:

	Name	Display Mode	Display Mode FourCC	Resolution Width	Resolution Height	Frame Duration	Time Scale	Frame Rate, per second	Frame Length, millisecond	Field Dominance	Field Dominance FourCC	Display Mode Flags	Pixel Formats
	NTSC	bmdModeNTSC	ntsc	720	486	1001	30000	29.970	333666	bmdLowerFieldFirst	lowr	bmdDisplayModeColorspaceRec601	bmdFormat8BitYUV 2vuy, bmdFormat10BitYUV v210
	PAL	bmdModePAL	pal 	720	576	1000	25000	25.000	400000	bmdUpperFieldFirst	uppr	bmdDisplayModeColorspaceRec601	bmdFormat8BitYUV 2vuy, bmdFormat10BitYUV v210
	HD 1080p 23.98	bmdModeHD1080p2398	23ps	1920	1080	1001	24000	23.976	417083	bmdProgressiveFrame	prog	bmdDisplayModeColorspaceRec709	bmdFormat8BitYUV 2vuy, bmdFormat10BitYUV v210, bmdFormat8BitARGB , bmdFormat8BitBGRA BGRA, bmdFormat10BitRGB r210, bmdFormat10BitRGBXLE R10l, bmdFormat10BitRGBX R10b, bmdFormat10BitRGBXLE_FULL R10L, bmdFormat10BitRGBX_FULL R10B
	HD 1080p 24	bmdModeHD1080p24	24ps	1920	1080	1000	24000	24.000	416666	bmdProgressiveFrame	prog	bmdDisplayModeColorspaceRec709	bmdFormat8BitYUV 2vuy, bmdFormat10BitYUV v210, bmdFormat8BitARGB , bmdFormat8BitBGRA BGRA, bmdFormat10BitRGB r210, bmdFormat10BitRGBXLE R10l, bmdFormat10BitRGBX R10b, bmdFormat10BitRGBXLE_FULL R10L, bmdFormat10BitRGBX_FULL R10B
	HD 1080p 25	bmdModeHD1080p25	Hp25	1920	1080	1000	25000	25.000	400000	bmdProgressiveFrame	prog	bmdDisplayModeColorspaceRec709	bmdFormat8BitYUV 2vuy, bmdFormat10BitYUV v210, bmdFormat8BitARGB , bmdFormat8BitBGRA BGRA, bmdFormat10BitRGB r210, bmdFormat10BitRGBXLE R10l, bmdFormat10BitRGBX R10b, bmdFormat10BitRGBXLE_FULL R10L, bmdFormat10BitRGBX_FULL R10B
	HD 1080p 29.97	bmdModeHD1080p2997	Hp29	1920	1080	1001	30000	29.970	333666	bmdProgressiveFrame	prog	bmdDisplayModeColorspaceRec709	bmdFormat8BitYUV 2vuy, bmdFormat10BitYUV v210, bmdFormat8BitARGB , bmdFormat8BitBGRA BGRA, bmdFormat10BitRGB r210, bmdFormat10BitRGBXLE R10l, bmdFormat10BitRGBX R10b, bmdFormat10BitRGBXLE_FULL R10L, bmdFormat10BitRGBX_FULL R10B
	HD 1080p 30	bmdModeHD1080p30	Hp30	1920	1080	1000	30000	30.000	333333	bmdProgressiveFrame	prog	bmdDisplayModeColorspaceRec709	bmdFormat8BitYUV 2vuy, bmdFormat10BitYUV v210, bmdFormat8BitARGB , bmdFormat8BitBGRA BGRA, bmdFormat10BitRGB r210, bmdFormat10BitRGBXLE R10l, bmdFormat10BitRGBX R10b, bmdFormat10BitRGBXLE_FULL R10L, bmdFormat10BitRGBX_FULL R10B
	HD 1080i 50	bmdModeHD1080i50	Hi50	1920	1080	1000	25000	25.000	400000	bmdUpperFieldFirst	uppr	bmdDisplayModeColorspaceRec709	bmdFormat8BitYUV 2vuy, bmdFormat10BitYUV v210, bmdFormat8BitARGB , bmdFormat8BitBGRA BGRA, bmdFormat10BitRGB r210, bmdFormat10BitRGBXLE R10l, bmdFormat10BitRGBX R10b, bmdFormat10BitRGBXLE_FULL R10L, bmdFormat10BitRGBX_FULL R10B
	HD 1080i 59.94	bmdModeHD1080i5994	Hi59	1920	1080	1001	30000	29.970	333666	bmdUpperFieldFirst	uppr	bmdDisplayModeColorspaceRec709	bmdFormat8BitYUV 2vuy, bmdFormat10BitYUV v210, bmdFormat8BitARGB , bmdFormat8BitBGRA BGRA, bmdFormat10BitRGB r210, bmdFormat10BitRGBXLE R10l, bmdFormat10BitRGBX R10b, bmdFormat10BitRGBXLE_FULL R10L, bmdFormat10BitRGBX_FULL R10B
	HD 1080i 60	bmdModeHD1080i6000	Hi60	1920	1080	1000	30000	30.000	333333	bmdUpperFieldFirst	uppr	bmdDisplayModeColorspaceRec709	bmdFormat8BitYUV 2vuy, bmdFormat10BitYUV v210, bmdFormat8BitARGB , bmdFormat8BitBGRA BGRA, bmdFormat10BitRGB r210, bmdFormat10BitRGBXLE R10l, bmdFormat10BitRGBX R10b, bmdFormat10BitRGBXLE_FULL R10L, bmdFormat10BitRGBX_FULL R10B
	HD 1080p 50	bmdModeHD1080p50	Hp50	1920	1080	1000	50000	50.000	200000	bmdProgressiveFrame	prog	bmdDisplayModeColorspaceRec709	bmdFormat8BitYUV 2vuy, bmdFormat10BitYUV v210
	HD 1080p 59.94	bmdModeHD1080p5994	Hp59	1920	1080	1001	60000	59.940	166833	bmdProgressiveFrame	prog	bmdDisplayModeColorspaceRec709	bmdFormat8BitYUV 2vuy, bmdFormat10BitYUV v210
	HD 1080p 60	bmdModeHD1080p6000	Hp60	1920	1080	1000	60000	60.000	166666	bmdProgressiveFrame	prog	bmdDisplayModeColorspaceRec709	bmdFormat8BitYUV 2vuy, bmdFormat10BitYUV v210
	HD 720p 50	bmdModeHD720p50	hp50	1280	720	1000	50000	50.000	200000	bmdProgressiveFrame	prog	bmdDisplayModeColorspaceRec709	bmdFormat8BitYUV 2vuy, bmdFormat10BitYUV v210
	HD 720p 59.94	bmdModeHD720p5994	hp59	1280	720	1001	60000	59.940	166833	bmdProgressiveFrame	prog	bmdDisplayModeColorspaceRec709	bmdFormat8BitYUV 2vuy, bmdFormat10BitYUV v210
	HD 720p 60	bmdModeHD720p60	hp60	1280	720	1000	60000	60.000	166666	bmdProgressiveFrame	prog	bmdDisplayModeColorspaceRec709	bmdFormat8BitYUV 2vuy, bmdFormat10BitYUV v210
	2K DCI 23.98	bmdMode2kDCI2398	2d23	2048	1080	1001	24000	23.976	417083	bmdProgressiveFrame	prog	bmdDisplayModeColorspaceRec709	bmdFormat8BitYUV 2vuy, bmdFormat10BitYUV v210, bmdFormat8BitARGB , bmdFormat8BitBGRA BGRA, bmdFormat10BitRGB r210, bmdFormat10BitRGBXLE R10l, bmdFormat10BitRGBX R10b, bmdFormat10BitRGBXLE_FULL R10L, bmdFormat10BitRGBX_FULL R10B
	2K DCI 24	bmdMode2kDCI24	2d24	2048	1080	1000	24000	24.000	416666	bmdProgressiveFrame	prog	bmdDisplayModeColorspaceRec709	bmdFormat8BitYUV 2vuy, bmdFormat10BitYUV v210, bmdFormat8BitARGB , bmdFormat8BitBGRA BGRA, bmdFormat10BitRGB r210, bmdFormat10BitRGBXLE R10l, bmdFormat10BitRGBX R10b, bmdFormat10BitRGBXLE_FULL R10L, bmdFormat10BitRGBX_FULL R10B
	2K DCI 25	bmdMode2kDCI25	2d25	2048	1080	1000	25000	25.000	400000	bmdProgressiveFrame	prog	bmdDisplayModeColorspaceRec709	bmdFormat8BitYUV 2vuy, bmdFormat10BitYUV v210, bmdFormat8BitARGB , bmdFormat8BitBGRA BGRA, bmdFormat10BitRGB r210, bmdFormat10BitRGBXLE R10l, bmdFormat10BitRGBX R10b, bmdFormat10BitRGBXLE_FULL R10L, bmdFormat10BitRGBX_FULL R10B
	4K Ultra HD 23.98	bmdMode4K2160p2398	4k23	3840	2160	1001	24000	23.976	417083	bmdProgressiveFrame	prog	bmdDisplayModeColorspaceRec709	bmdFormat8BitYUV 2vuy, bmdFormat10BitYUV v210
	4K Ultra HD 24	bmdMode4K2160p24	4k24	3840	2160	1000	24000	24.000	416666	bmdProgressiveFrame	prog	bmdDisplayModeColorspaceRec709	bmdFormat8BitYUV 2vuy, bmdFormat10BitYUV v210
	4K Ultra HD 25	bmdMode4K2160p25	4k25	3840	2160	1000	25000	25.000	400000	bmdProgressiveFrame	prog	bmdDisplayModeColorspaceRec709	bmdFormat8BitYUV 2vuy, bmdFormat10BitYUV v210
	4K Ultra HD 29.97	bmdMode4K2160p2997	4k29	3840	2160	1001	30000	29.970	333666	bmdProgressiveFrame	prog	bmdDisplayModeColorspaceRec709	bmdFormat8BitYUV 2vuy, bmdFormat10BitYUV v210
	4K Ultra HD 30	bmdMode4K2160p30	4k30	3840	2160	1000	30000	30.000	333333	bmdProgressiveFrame	prog	bmdDisplayModeColorspaceRec709	bmdFormat8BitYUV 2vuy, bmdFormat10BitYUV v210
	4K DCI 23.98	bmdMode4kDCI2398	4d23	4096	2160	1001	24000	23.976	417083	bmdProgressiveFrame	prog	bmdDisplayModeColorspaceRec709	bmdFormat8BitYUV 2vuy, bmdFormat10BitYUV v210
	4K DCI 24	bmdMode4kDCI24	4d24	4096	2160	1000	24000	24.000	416666	bmdProgressiveFrame	prog	bmdDisplayModeColorspaceRec709	bmdFormat8BitYUV 2vuy, bmdFormat10BitYUV v210
	4K DCI 25	bmdMode4kDCI25	4d25	4096	2160	1000	25000	25.000	400000	bmdProgressiveFrame	prog	bmdDisplayModeColorspaceRec709	bmdFormat8BitYUV 2vuy, bmdFormat10BitYUV v210


### Output Display Modes

 * NTSC:
  * Mode: `bmdModeNTSC` (`ntsc`)
  * Resolution: `720` x `486`
  * Frame Duration: `1001` / `30000` (`29.970` fps, `33 3666` per frame)
  * Field Dominance: `bmdLowerFieldFirst` (`lowr`)
  * Flags: `bmdDisplayModeColorspaceRec601`
  * Pixel Formats: `bmdFormat8BitYUV` (`2vuy`), `bmdFormat10BitYUV` (`v210`), `bmdFormat8BitARGB`, `bmdFormat8BitBGRA` (`BGRA`), `bmdFormat10BitRGB` (`r210`)
 * PAL:
  * Mode: `bmdModePAL` (`pal `)
  * Resolution: `720` x `576`
  * Frame Duration: `1000` / `25000` (`25.000` fps, `40 0000` per frame)
  * Field Dominance: `bmdUpperFieldFirst` (`uppr`)
  * Flags: `bmdDisplayModeColorspaceRec601`
  * Pixel Formats: `bmdFormat8BitYUV` (`2vuy`), `bmdFormat10BitYUV` (`v210`), `bmdFormat8BitARGB`, `bmdFormat8BitBGRA` (`BGRA`), `bmdFormat10BitRGB` (`r210`)
 * HD 1080p 23.98:
  * Mode: `bmdModeHD1080p2398` (`23ps`)
  * Resolution: `1920` x `1080`
  * Frame Duration: `1001` / `24000` (`23.976` fps, `41 7083` per frame)
  * Field Dominance: `bmdProgressiveFrame` (`prog`)
  * Flags: `bmdDisplayModeColorspaceRec709`
  * Pixel Formats: `bmdFormat8BitYUV` (`2vuy`), `bmdFormat10BitYUV` (`v210`), `bmdFormat8BitARGB`, `bmdFormat8BitBGRA` (`BGRA`), `bmdFormat10BitRGB` (`r210`), `bmdFormat12BitRGB` (`R12B`), `bmdFormat12BitRGBLE` (`R12L`)
 * HD 1080p 24:
  * Mode: `bmdModeHD1080p24` (`24ps`)
  * Resolution: `1920` x `1080`
  * Frame Duration: `1000` / `24000` (`24.000` fps, `41 6666` per frame)
  * Field Dominance: `bmdProgressiveFrame` (`prog`)
  * Flags: `bmdDisplayModeColorspaceRec709`
  * Pixel Formats: `bmdFormat8BitYUV` (`2vuy`), `bmdFormat10BitYUV` (`v210`), `bmdFormat8BitARGB`, `bmdFormat8BitBGRA` (`BGRA`), `bmdFormat10BitRGB` (`r210`), `bmdFormat12BitRGB` (`R12B`), `bmdFormat12BitRGBLE` (`R12L`)
 * HD 1080p 25:
  * Mode: `bmdModeHD1080p25` (`Hp25`)
  * Resolution: `1920` x `1080`
  * Frame Duration: `1000` / `25000` (`25.000` fps, `40 0000` per frame)
  * Field Dominance: `bmdProgressiveFrame` (`prog`)
  * Flags: `bmdDisplayModeColorspaceRec709`
  * Pixel Formats: `bmdFormat8BitYUV` (`2vuy`), `bmdFormat10BitYUV` (`v210`), `bmdFormat8BitARGB`, `bmdFormat8BitBGRA` (`BGRA`), `bmdFormat10BitRGB` (`r210`), `bmdFormat12BitRGB` (`R12B`), `bmdFormat12BitRGBLE` (`R12L`)
 * HD 1080p 29.97:
  * Mode: `bmdModeHD1080p2997` (`Hp29`)
  * Resolution: `1920` x `1080`
  * Frame Duration: `1001` / `30000` (`29.970` fps, `33 3666` per frame)
  * Field Dominance: `bmdProgressiveFrame` (`prog`)
  * Flags: `bmdDisplayModeColorspaceRec709`
  * Pixel Formats: `bmdFormat8BitYUV` (`2vuy`), `bmdFormat10BitYUV` (`v210`), `bmdFormat8BitARGB`, `bmdFormat8BitBGRA` (`BGRA`), `bmdFormat10BitRGB` (`r210`), `bmdFormat12BitRGB` (`R12B`), `bmdFormat12BitRGBLE` (`R12L`)
 * HD 1080p 30:
  * Mode: `bmdModeHD1080p30` (`Hp30`)
  * Resolution: `1920` x `1080`
  * Frame Duration: `1000` / `30000` (`30.000` fps, `33 3333` per frame)
  * Field Dominance: `bmdProgressiveFrame` (`prog`)
  * Flags: `bmdDisplayModeColorspaceRec709`
  * Pixel Formats: `bmdFormat8BitYUV` (`2vuy`), `bmdFormat10BitYUV` (`v210`), `bmdFormat8BitARGB`, `bmdFormat8BitBGRA` (`BGRA`), `bmdFormat10BitRGB` (`r210`), `bmdFormat12BitRGB` (`R12B`), `bmdFormat12BitRGBLE` (`R12L`)
 * HD 1080i 50:
  * Mode: `bmdModeHD1080i50` (`Hi50`)
  * Resolution: `1920` x `1080`
  * Frame Duration: `1000` / `25000` (`25.000` fps, `40 0000` per frame)
  * Field Dominance: `bmdUpperFieldFirst` (`uppr`)
  * Flags: `bmdDisplayModeColorspaceRec709`
  * Pixel Formats: `bmdFormat8BitYUV` (`2vuy`), `bmdFormat10BitYUV` (`v210`), `bmdFormat8BitARGB`, `bmdFormat8BitBGRA` (`BGRA`), `bmdFormat10BitRGB` (`r210`), `bmdFormat12BitRGB` (`R12B`), `bmdFormat12BitRGBLE` (`R12L`)
 * HD 1080i 59.94:
  * Mode: `bmdModeHD1080i5994` (`Hi59`)
  * Resolution: `1920` x `1080`
  * Frame Duration: `1001` / `30000` (`29.970` fps, `33 3666` per frame)
  * Field Dominance: `bmdUpperFieldFirst` (`uppr`)
  * Flags: `bmdDisplayModeColorspaceRec709`
  * Pixel Formats: `bmdFormat8BitYUV` (`2vuy`), `bmdFormat10BitYUV` (`v210`), `bmdFormat8BitARGB`, `bmdFormat8BitBGRA` (`BGRA`), `bmdFormat10BitRGB` (`r210`), `bmdFormat12BitRGB` (`R12B`), `bmdFormat12BitRGBLE` (`R12L`)
 * HD 1080i 60:
  * Mode: `bmdModeHD1080i6000` (`Hi60`)
  * Resolution: `1920` x `1080`
  * Frame Duration: `1000` / `30000` (`30.000` fps, `33 3333` per frame)
  * Field Dominance: `bmdUpperFieldFirst` (`uppr`)
  * Flags: `bmdDisplayModeColorspaceRec709`
  * Pixel Formats: `bmdFormat8BitYUV` (`2vuy`), `bmdFormat10BitYUV` (`v210`), `bmdFormat8BitARGB`, `bmdFormat8BitBGRA` (`BGRA`), `bmdFormat10BitRGB` (`r210`), `bmdFormat12BitRGB` (`R12B`), `bmdFormat12BitRGBLE` (`R12L`)
 * HD 1080p 50:
  * Mode: `bmdModeHD1080p50` (`Hp50`)
  * Resolution: `1920` x `1080`
  * Frame Duration: `1000` / `50000` (`50.000` fps, `20 0000` per frame)
  * Field Dominance: `bmdProgressiveFrame` (`prog`)
  * Flags: `bmdDisplayModeColorspaceRec709`
  * Pixel Formats: `bmdFormat8BitYUV` (`2vuy`), `bmdFormat10BitYUV` (`v210`), `bmdFormat12BitRGB` (`R12B`), `bmdFormat12BitRGBLE` (`R12L`)
 * HD 1080p 59.94:
  * Mode: `bmdModeHD1080p5994` (`Hp59`)
  * Resolution: `1920` x `1080`
  * Frame Duration: `1001` / `60000` (`59.940` fps, `16 6833` per frame)
  * Field Dominance: `bmdProgressiveFrame` (`prog`)
  * Flags: `bmdDisplayModeColorspaceRec709`
  * Pixel Formats: `bmdFormat8BitYUV` (`2vuy`), `bmdFormat10BitYUV` (`v210`), `bmdFormat12BitRGB` (`R12B`), `bmdFormat12BitRGBLE` (`R12L`)
 * HD 1080p 60:
  * Mode: `bmdModeHD1080p6000` (`Hp60`)
  * Resolution: `1920` x `1080`
  * Frame Duration: `1000` / `60000` (`60.000` fps, `16 6666` per frame)
  * Field Dominance: `bmdProgressiveFrame` (`prog`)
  * Flags: `bmdDisplayModeColorspaceRec709`
  * Pixel Formats: `bmdFormat8BitYUV` (`2vuy`), `bmdFormat10BitYUV` (`v210`), `bmdFormat12BitRGB` (`R12B`), `bmdFormat12BitRGBLE` (`R12L`)
 * HD 720p 50:
  * Mode: `bmdModeHD720p50` (`hp50`)
  * Resolution: `1280` x `720`
  * Frame Duration: `1000` / `50000` (`50.000` fps, `20 0000` per frame)
  * Field Dominance: `bmdProgressiveFrame` (`prog`)
  * Flags: `bmdDisplayModeColorspaceRec709`
  * Pixel Formats: `bmdFormat8BitYUV` (`2vuy`), `bmdFormat10BitYUV` (`v210`), `bmdFormat8BitARGB`, `bmdFormat8BitBGRA` (`BGRA`), `bmdFormat10BitRGB` (`r210`)
 * HD 720p 59.94:
  * Mode: `bmdModeHD720p5994` (`hp59`)
  * Resolution: `1280` x `720`
  * Frame Duration: `1001` / `60000` (`59.940` fps, `16 6833` per frame)
  * Field Dominance: `bmdProgressiveFrame` (`prog`)
  * Flags: `bmdDisplayModeColorspaceRec709`
  * Pixel Formats: `bmdFormat8BitYUV` (`2vuy`), `bmdFormat10BitYUV` (`v210`), `bmdFormat8BitARGB`, `bmdFormat8BitBGRA` (`BGRA`), `bmdFormat10BitRGB` (`r210`)
 * HD 720p 60:
  * Mode: `bmdModeHD720p60` (`hp60`)
  * Resolution: `1280` x `720`
  * Frame Duration: `1000` / `60000` (`60.000` fps, `16 6666` per frame)
  * Field Dominance: `bmdProgressiveFrame` (`prog`)
  * Flags: `bmdDisplayModeColorspaceRec709`
  * Pixel Formats: `bmdFormat8BitYUV` (`2vuy`), `bmdFormat10BitYUV` (`v210`), `bmdFormat8BitARGB`, `bmdFormat8BitBGRA` (`BGRA`), `bmdFormat10BitRGB` (`r210`)
 * 2K 23.98:
  * Mode: `bmdMode2k2398` (`2k23`)
  * Resolution: `2048` x `1556`
  * Frame Duration: `1001` / `24000` (`23.976` fps, `41 7083` per frame)
  * Field Dominance: `bmdProgressiveFrame` (`prog`)
  * Flags: `bmdDisplayModeColorspaceRec709`
  * Pixel Formats: `bmdFormat8BitYUV` (`2vuy`), `bmdFormat10BitYUV` (`v210`), `bmdFormat8BitARGB`, `bmdFormat8BitBGRA` (`BGRA`), `bmdFormat10BitRGB` (`r210`), `bmdFormat12BitRGB` (`R12B`), `bmdFormat12BitRGBLE` (`R12L`)
 * 2K 24:
  * Mode: `bmdMode2k24` (`2k24`)
  * Resolution: `2048` x `1556`
  * Frame Duration: `1000` / `24000` (`24.000` fps, `41 6666` per frame)
  * Field Dominance: `bmdProgressiveFrame` (`prog`)
  * Flags: `bmdDisplayModeColorspaceRec709`
  * Pixel Formats: `bmdFormat8BitYUV` (`2vuy`), `bmdFormat10BitYUV` (`v210`), `bmdFormat8BitARGB`, `bmdFormat8BitBGRA` (`BGRA`), `bmdFormat10BitRGB` (`r210`), `bmdFormat12BitRGB` (`R12B`), `bmdFormat12BitRGBLE` (`R12L`)
 * 2K 25:
  * Mode: `bmdMode2k25` (`2k25`)
  * Resolution: `2048` x `1556`
  * Frame Duration: `1000` / `25000` (`25.000` fps, `40 0000` per frame)
  * Field Dominance: `bmdProgressiveFrame` (`prog`)
  * Flags: `bmdDisplayModeColorspaceRec709`
  * Pixel Formats: `bmdFormat8BitYUV` (`2vuy`), `bmdFormat10BitYUV` (`v210`), `bmdFormat8BitARGB`, `bmdFormat8BitBGRA` (`BGRA`), `bmdFormat10BitRGB` (`r210`), `bmdFormat12BitRGB` (`R12B`), `bmdFormat12BitRGBLE` (`R12L`)
 * 2K DCI 23.98:
  * Mode: `bmdMode2kDCI2398` (`2d23`)
  * Resolution: `2048` x `1080`
  * Frame Duration: `1001` / `24000` (`23.976` fps, `41 7083` per frame)
  * Field Dominance: `bmdProgressiveFrame` (`prog`)
  * Flags: `bmdDisplayModeColorspaceRec709`
  * Pixel Formats: `bmdFormat8BitYUV` (`2vuy`), `bmdFormat10BitYUV` (`v210`), `bmdFormat8BitARGB`, `bmdFormat8BitBGRA` (`BGRA`), `bmdFormat10BitRGB` (`r210`), `bmdFormat12BitRGB` (`R12B`), `bmdFormat12BitRGBLE` (`R12L`)
 * 2K DCI 24:
  * Mode: `bmdMode2kDCI24` (`2d24`)
  * Resolution: `2048` x `1080`
  * Frame Duration: `1000` / `24000` (`24.000` fps, `41 6666` per frame)
  * Field Dominance: `bmdProgressiveFrame` (`prog`)
  * Flags: `bmdDisplayModeColorspaceRec709`
  * Pixel Formats: `bmdFormat8BitYUV` (`2vuy`), `bmdFormat10BitYUV` (`v210`), `bmdFormat8BitARGB`, `bmdFormat8BitBGRA` (`BGRA`), `bmdFormat10BitRGB` (`r210`), `bmdFormat12BitRGB` (`R12B`), `bmdFormat12BitRGBLE` (`R12L`)
 * 2K DCI 25:
  * Mode: `bmdMode2kDCI25` (`2d25`)
  * Resolution: `2048` x `1080`
  * Frame Duration: `1000` / `25000` (`25.000` fps, `40 0000` per frame)
  * Field Dominance: `bmdProgressiveFrame` (`prog`)
  * Flags: `bmdDisplayModeColorspaceRec709`
  * Pixel Formats: `bmdFormat8BitYUV` (`2vuy`), `bmdFormat10BitYUV` (`v210`), `bmdFormat8BitARGB`, `bmdFormat8BitBGRA` (`BGRA`), `bmdFormat10BitRGB` (`r210`), `bmdFormat12BitRGB` (`R12B`), `bmdFormat12BitRGBLE` (`R12L`)
 * 4K Ultra HD 23.98:
  * Mode: `bmdMode4K2160p2398` (`4k23`)
  * Resolution: `3840` x `2160`
  * Frame Duration: `1001` / `24000` (`23.976` fps, `41 7083` per frame)
  * Field Dominance: `bmdProgressiveFrame` (`prog`)
  * Flags: `bmdDisplayModeColorspaceRec709`
  * Pixel Formats: `bmdFormat8BitYUV` (`2vuy`), `bmdFormat10BitYUV` (`v210`), `bmdFormat8BitARGB`, `bmdFormat8BitBGRA` (`BGRA`), `bmdFormat10BitRGB` (`r210`), `bmdFormat12BitRGB` (`R12B`), `bmdFormat12BitRGBLE` (`R12L`)
 * 4K Ultra HD 24:
  * Mode: `bmdMode4K2160p24` (`4k24`)
  * Resolution: `3840` x `2160`
  * Frame Duration: `1000` / `24000` (`24.000` fps, `41 6666` per frame)
  * Field Dominance: `bmdProgressiveFrame` (`prog`)
  * Flags: `bmdDisplayModeColorspaceRec709`
  * Pixel Formats: `bmdFormat8BitYUV` (`2vuy`), `bmdFormat10BitYUV` (`v210`), `bmdFormat8BitARGB`, `bmdFormat8BitBGRA` (`BGRA`), `bmdFormat10BitRGB` (`r210`), `bmdFormat12BitRGB` (`R12B`), `bmdFormat12BitRGBLE` (`R12L`)
 * 4K Ultra HD 25:
  * Mode: `bmdMode4K2160p25` (`4k25`)
  * Resolution: `3840` x `2160`
  * Frame Duration: `1000` / `25000` (`25.000` fps, `40 0000` per frame)
  * Field Dominance: `bmdProgressiveFrame` (`prog`)
  * Flags: `bmdDisplayModeColorspaceRec709`
  * Pixel Formats: `bmdFormat8BitYUV` (`2vuy`), `bmdFormat10BitYUV` (`v210`), `bmdFormat8BitARGB`, `bmdFormat8BitBGRA` (`BGRA`), `bmdFormat10BitRGB` (`r210`), `bmdFormat12BitRGB` (`R12B`), `bmdFormat12BitRGBLE` (`R12L`)
 * 4K Ultra HD 29.97:
  * Mode: `bmdMode4K2160p2997` (`4k29`)
  * Resolution: `3840` x `2160`
  * Frame Duration: `1001` / `30000` (`29.970` fps, `33 3666` per frame)
  * Field Dominance: `bmdProgressiveFrame` (`prog`)
  * Flags: `bmdDisplayModeColorspaceRec709`
  * Pixel Formats: `bmdFormat8BitYUV` (`2vuy`), `bmdFormat10BitYUV` (`v210`), `bmdFormat8BitARGB`, `bmdFormat8BitBGRA` (`BGRA`), `bmdFormat10BitRGB` (`r210`), `bmdFormat12BitRGB` (`R12B`), `bmdFormat12BitRGBLE` (`R12L`)
 * 4K Ultra HD 30:
  * Mode: `bmdMode4K2160p30` (`4k30`)
  * Resolution: `3840` x `2160`
  * Frame Duration: `1000` / `30000` (`30.000` fps, `33 3333` per frame)
  * Field Dominance: `bmdProgressiveFrame` (`prog`)
  * Flags: `bmdDisplayModeColorspaceRec709`
  * Pixel Formats: `bmdFormat8BitYUV` (`2vuy`), `bmdFormat10BitYUV` (`v210`), `bmdFormat8BitARGB`, `bmdFormat8BitBGRA` (`BGRA`), `bmdFormat10BitRGB` (`r210`), `bmdFormat12BitRGB` (`R12B`), `bmdFormat12BitRGBLE` (`R12L`)
 * 4K DCI 23.98:
  * Mode: `bmdMode4kDCI2398` (`4d23`)
  * Resolution: `4096` x `2160`
  * Frame Duration: `1001` / `24000` (`23.976` fps, `41 7083` per frame)
  * Field Dominance: `bmdProgressiveFrame` (`prog`)
  * Flags: `bmdDisplayModeColorspaceRec709`
  * Pixel Formats: `bmdFormat8BitYUV` (`2vuy`), `bmdFormat10BitYUV` (`v210`), `bmdFormat8BitARGB`, `bmdFormat8BitBGRA` (`BGRA`), `bmdFormat10BitRGB` (`r210`), `bmdFormat12BitRGB` (`R12B`), `bmdFormat12BitRGBLE` (`R12L`)
 * 4K DCI 24:
  * Mode: `bmdMode4kDCI24` (`4d24`)
  * Resolution: `4096` x `2160`
  * Frame Duration: `1000` / `24000` (`24.000` fps, `41 6666` per frame)
  * Field Dominance: `bmdProgressiveFrame` (`prog`)
  * Flags: `bmdDisplayModeColorspaceRec709`
  * Pixel Formats: `bmdFormat8BitYUV` (`2vuy`), `bmdFormat10BitYUV` (`v210`), `bmdFormat8BitARGB`, `bmdFormat8BitBGRA` (`BGRA`), `bmdFormat10BitRGB` (`r210`), `bmdFormat12BitRGB` (`R12B`), `bmdFormat12BitRGBLE` (`R12L`)
 * 4K DCI 25:
  * Mode: `bmdMode4kDCI25` (`4d25`)
  * Resolution: `4096` x `2160`
  * Frame Duration: `1000` / `25000` (`25.000` fps, `40 0000` per frame)
  * Field Dominance: `bmdProgressiveFrame` (`prog`)
  * Flags: `bmdDisplayModeColorspaceRec709`
  * Pixel Formats: `bmdFormat8BitYUV` (`2vuy`), `bmdFormat10BitYUV` (`v210`), `bmdFormat8BitARGB`, `bmdFormat8BitBGRA` (`BGRA`), `bmdFormat10BitRGB` (`r210`), `bmdFormat12BitRGB` (`R12B`), `bmdFormat12BitRGBLE` (`R12L`)

TSV Formatted:

	Name	Display Mode	Display Mode FourCC	Resolution Width	Resolution Height	Frame Duration	Time Scale	Frame Rate, per second	Frame Length, millisecond	Field Dominance	Field Dominance FourCC	Display Mode Flags	Pixel Formats
	NTSC	bmdModeNTSC	ntsc	720	486	1001	30000	29.970	333666	bmdLowerFieldFirst	lowr	bmdDisplayModeColorspaceRec601	bmdFormat8BitYUV 2vuy, bmdFormat10BitYUV v210, bmdFormat8BitARGB , bmdFormat8BitBGRA BGRA, bmdFormat10BitRGB r210
	PAL	bmdModePAL	pal 	720	576	1000	25000	25.000	400000	bmdUpperFieldFirst	uppr	bmdDisplayModeColorspaceRec601	bmdFormat8BitYUV 2vuy, bmdFormat10BitYUV v210, bmdFormat8BitARGB , bmdFormat8BitBGRA BGRA, bmdFormat10BitRGB r210
	HD 1080p 23.98	bmdModeHD1080p2398	23ps	1920	1080	1001	24000	23.976	417083	bmdProgressiveFrame	prog	bmdDisplayModeColorspaceRec709	bmdFormat8BitYUV 2vuy, bmdFormat10BitYUV v210, bmdFormat8BitARGB , bmdFormat8BitBGRA BGRA, bmdFormat10BitRGB r210, bmdFormat12BitRGB R12B, bmdFormat12BitRGBLE R12L
	HD 1080p 24	bmdModeHD1080p24	24ps	1920	1080	1000	24000	24.000	416666	bmdProgressiveFrame	prog	bmdDisplayModeColorspaceRec709	bmdFormat8BitYUV 2vuy, bmdFormat10BitYUV v210, bmdFormat8BitARGB , bmdFormat8BitBGRA BGRA, bmdFormat10BitRGB r210, bmdFormat12BitRGB R12B, bmdFormat12BitRGBLE R12L
	HD 1080p 25	bmdModeHD1080p25	Hp25	1920	1080	1000	25000	25.000	400000	bmdProgressiveFrame	prog	bmdDisplayModeColorspaceRec709	bmdFormat8BitYUV 2vuy, bmdFormat10BitYUV v210, bmdFormat8BitARGB , bmdFormat8BitBGRA BGRA, bmdFormat10BitRGB r210, bmdFormat12BitRGB R12B, bmdFormat12BitRGBLE R12L
	HD 1080p 29.97	bmdModeHD1080p2997	Hp29	1920	1080	1001	30000	29.970	333666	bmdProgressiveFrame	prog	bmdDisplayModeColorspaceRec709	bmdFormat8BitYUV 2vuy, bmdFormat10BitYUV v210, bmdFormat8BitARGB , bmdFormat8BitBGRA BGRA, bmdFormat10BitRGB r210, bmdFormat12BitRGB R12B, bmdFormat12BitRGBLE R12L
	HD 1080p 30	bmdModeHD1080p30	Hp30	1920	1080	1000	30000	30.000	333333	bmdProgressiveFrame	prog	bmdDisplayModeColorspaceRec709	bmdFormat8BitYUV 2vuy, bmdFormat10BitYUV v210, bmdFormat8BitARGB , bmdFormat8BitBGRA BGRA, bmdFormat10BitRGB r210, bmdFormat12BitRGB R12B, bmdFormat12BitRGBLE R12L
	HD 1080i 50	bmdModeHD1080i50	Hi50	1920	1080	1000	25000	25.000	400000	bmdUpperFieldFirst	uppr	bmdDisplayModeColorspaceRec709	bmdFormat8BitYUV 2vuy, bmdFormat10BitYUV v210, bmdFormat8BitARGB , bmdFormat8BitBGRA BGRA, bmdFormat10BitRGB r210, bmdFormat12BitRGB R12B, bmdFormat12BitRGBLE R12L
	HD 1080i 59.94	bmdModeHD1080i5994	Hi59	1920	1080	1001	30000	29.970	333666	bmdUpperFieldFirst	uppr	bmdDisplayModeColorspaceRec709	bmdFormat8BitYUV 2vuy, bmdFormat10BitYUV v210, bmdFormat8BitARGB , bmdFormat8BitBGRA BGRA, bmdFormat10BitRGB r210, bmdFormat12BitRGB R12B, bmdFormat12BitRGBLE R12L
	HD 1080i 60	bmdModeHD1080i6000	Hi60	1920	1080	1000	30000	30.000	333333	bmdUpperFieldFirst	uppr	bmdDisplayModeColorspaceRec709	bmdFormat8BitYUV 2vuy, bmdFormat10BitYUV v210, bmdFormat8BitARGB , bmdFormat8BitBGRA BGRA, bmdFormat10BitRGB r210, bmdFormat12BitRGB R12B, bmdFormat12BitRGBLE R12L
	HD 1080p 50	bmdModeHD1080p50	Hp50	1920	1080	1000	50000	50.000	200000	bmdProgressiveFrame	prog	bmdDisplayModeColorspaceRec709	bmdFormat8BitYUV 2vuy, bmdFormat10BitYUV v210, bmdFormat12BitRGB R12B, bmdFormat12BitRGBLE R12L
	HD 1080p 59.94	bmdModeHD1080p5994	Hp59	1920	1080	1001	60000	59.940	166833	bmdProgressiveFrame	prog	bmdDisplayModeColorspaceRec709	bmdFormat8BitYUV 2vuy, bmdFormat10BitYUV v210, bmdFormat12BitRGB R12B, bmdFormat12BitRGBLE R12L
	HD 1080p 60	bmdModeHD1080p6000	Hp60	1920	1080	1000	60000	60.000	166666	bmdProgressiveFrame	prog	bmdDisplayModeColorspaceRec709	bmdFormat8BitYUV 2vuy, bmdFormat10BitYUV v210, bmdFormat12BitRGB R12B, bmdFormat12BitRGBLE R12L
	HD 720p 50	bmdModeHD720p50	hp50	1280	720	1000	50000	50.000	200000	bmdProgressiveFrame	prog	bmdDisplayModeColorspaceRec709	bmdFormat8BitYUV 2vuy, bmdFormat10BitYUV v210, bmdFormat8BitARGB , bmdFormat8BitBGRA BGRA, bmdFormat10BitRGB r210
	HD 720p 59.94	bmdModeHD720p5994	hp59	1280	720	1001	60000	59.940	166833	bmdProgressiveFrame	prog	bmdDisplayModeColorspaceRec709	bmdFormat8BitYUV 2vuy, bmdFormat10BitYUV v210, bmdFormat8BitARGB , bmdFormat8BitBGRA BGRA, bmdFormat10BitRGB r210
	HD 720p 60	bmdModeHD720p60	hp60	1280	720	1000	60000	60.000	166666	bmdProgressiveFrame	prog	bmdDisplayModeColorspaceRec709	bmdFormat8BitYUV 2vuy, bmdFormat10BitYUV v210, bmdFormat8BitARGB , bmdFormat8BitBGRA BGRA, bmdFormat10BitRGB r210
	2K 23.98	bmdMode2k2398	2k23	2048	1556	1001	24000	23.976	417083	bmdProgressiveFrame	prog	bmdDisplayModeColorspaceRec709	bmdFormat8BitYUV 2vuy, bmdFormat10BitYUV v210, bmdFormat8BitARGB , bmdFormat8BitBGRA BGRA, bmdFormat10BitRGB r210, bmdFormat12BitRGB R12B, bmdFormat12BitRGBLE R12L
	2K 24	bmdMode2k24	2k24	2048	1556	1000	24000	24.000	416666	bmdProgressiveFrame	prog	bmdDisplayModeColorspaceRec709	bmdFormat8BitYUV 2vuy, bmdFormat10BitYUV v210, bmdFormat8BitARGB , bmdFormat8BitBGRA BGRA, bmdFormat10BitRGB r210, bmdFormat12BitRGB R12B, bmdFormat12BitRGBLE R12L
	2K 25	bmdMode2k25	2k25	2048	1556	1000	25000	25.000	400000	bmdProgressiveFrame	prog	bmdDisplayModeColorspaceRec709	bmdFormat8BitYUV 2vuy, bmdFormat10BitYUV v210, bmdFormat8BitARGB , bmdFormat8BitBGRA BGRA, bmdFormat10BitRGB r210, bmdFormat12BitRGB R12B, bmdFormat12BitRGBLE R12L
	2K DCI 23.98	bmdMode2kDCI2398	2d23	2048	1080	1001	24000	23.976	417083	bmdProgressiveFrame	prog	bmdDisplayModeColorspaceRec709	bmdFormat8BitYUV 2vuy, bmdFormat10BitYUV v210, bmdFormat8BitARGB , bmdFormat8BitBGRA BGRA, bmdFormat10BitRGB r210, bmdFormat12BitRGB R12B, bmdFormat12BitRGBLE R12L
	2K DCI 24	bmdMode2kDCI24	2d24	2048	1080	1000	24000	24.000	416666	bmdProgressiveFrame	prog	bmdDisplayModeColorspaceRec709	bmdFormat8BitYUV 2vuy, bmdFormat10BitYUV v210, bmdFormat8BitARGB , bmdFormat8BitBGRA BGRA, bmdFormat10BitRGB r210, bmdFormat12BitRGB R12B, bmdFormat12BitRGBLE R12L
	2K DCI 25	bmdMode2kDCI25	2d25	2048	1080	1000	25000	25.000	400000	bmdProgressiveFrame	prog	bmdDisplayModeColorspaceRec709	bmdFormat8BitYUV 2vuy, bmdFormat10BitYUV v210, bmdFormat8BitARGB , bmdFormat8BitBGRA BGRA, bmdFormat10BitRGB r210, bmdFormat12BitRGB R12B, bmdFormat12BitRGBLE R12L
	4K Ultra HD 23.98	bmdMode4K2160p2398	4k23	3840	2160	1001	24000	23.976	417083	bmdProgressiveFrame	prog	bmdDisplayModeColorspaceRec709	bmdFormat8BitYUV 2vuy, bmdFormat10BitYUV v210, bmdFormat8BitARGB , bmdFormat8BitBGRA BGRA, bmdFormat10BitRGB r210, bmdFormat12BitRGB R12B, bmdFormat12BitRGBLE R12L
	4K Ultra HD 24	bmdMode4K2160p24	4k24	3840	2160	1000	24000	24.000	416666	bmdProgressiveFrame	prog	bmdDisplayModeColorspaceRec709	bmdFormat8BitYUV 2vuy, bmdFormat10BitYUV v210, bmdFormat8BitARGB , bmdFormat8BitBGRA BGRA, bmdFormat10BitRGB r210, bmdFormat12BitRGB R12B, bmdFormat12BitRGBLE R12L
	4K Ultra HD 25	bmdMode4K2160p25	4k25	3840	2160	1000	25000	25.000	400000	bmdProgressiveFrame	prog	bmdDisplayModeColorspaceRec709	bmdFormat8BitYUV 2vuy, bmdFormat10BitYUV v210, bmdFormat8BitARGB , bmdFormat8BitBGRA BGRA, bmdFormat10BitRGB r210, bmdFormat12BitRGB R12B, bmdFormat12BitRGBLE R12L
	4K Ultra HD 29.97	bmdMode4K2160p2997	4k29	3840	2160	1001	30000	29.970	333666	bmdProgressiveFrame	prog	bmdDisplayModeColorspaceRec709	bmdFormat8BitYUV 2vuy, bmdFormat10BitYUV v210, bmdFormat8BitARGB , bmdFormat8BitBGRA BGRA, bmdFormat10BitRGB r210, bmdFormat12BitRGB R12B, bmdFormat12BitRGBLE R12L
	4K Ultra HD 30	bmdMode4K2160p30	4k30	3840	2160	1000	30000	30.000	333333	bmdProgressiveFrame	prog	bmdDisplayModeColorspaceRec709	bmdFormat8BitYUV 2vuy, bmdFormat10BitYUV v210, bmdFormat8BitARGB , bmdFormat8BitBGRA BGRA, bmdFormat10BitRGB r210, bmdFormat12BitRGB R12B, bmdFormat12BitRGBLE R12L
	4K DCI 23.98	bmdMode4kDCI2398	4d23	4096	2160	1001	24000	23.976	417083	bmdProgressiveFrame	prog	bmdDisplayModeColorspaceRec709	bmdFormat8BitYUV 2vuy, bmdFormat10BitYUV v210, bmdFormat8BitARGB , bmdFormat8BitBGRA BGRA, bmdFormat10BitRGB r210, bmdFormat12BitRGB R12B, bmdFormat12BitRGBLE R12L
	4K DCI 24	bmdMode4kDCI24	4d24	4096	2160	1000	24000	24.000	416666	bmdProgressiveFrame	prog	bmdDisplayModeColorspaceRec709	bmdFormat8BitYUV 2vuy, bmdFormat10BitYUV v210, bmdFormat8BitARGB , bmdFormat8BitBGRA BGRA, bmdFormat10BitRGB r210, bmdFormat12BitRGB R12B, bmdFormat12BitRGBLE R12L
	4K DCI 25	bmdMode4kDCI25	4d25	4096	2160	1000	25000	25.000	400000	bmdProgressiveFrame	prog	bmdDisplayModeColorspaceRec709	bmdFormat8BitYUV 2vuy, bmdFormat10BitYUV v210, bmdFormat8BitARGB , bmdFormat8BitBGRA BGRA, bmdFormat10BitRGB r210, bmdFormat12BitRGB R12B, bmdFormat12BitRGBLE R12L


