

# System

 * System Version: `6.2` Build `9200`; Windows 8; Suite Mask `0x100`; Product Type `0x1`
 * Computer Name: `TENSEN`
 * User Name: `Sen` 
 * Local Time: `4/08/2016 16:20:19`
 * Architecture: AMD/Intel x64 (x64 Application)
 * Processors: `16`, Active Mask `0xFFFF`
 * Page Size: `0x1000`
 * Application Address Space: `0x0000000000010000`..`0x00007FFFFFFEFFFF`
 * Physical Memory: `65 448` MB
 * Committed Memory Limit: `65 448` MB

# DeckLink API

## API Information

  * 64-Bit Integer `BMDDeckLinkAPIVersion`: `168230912` (`0xA070000`) // 10.7
  * String `BMDDeckLinkAPIRCTag`: `a18`
  * Flag (32-Bit Integer) `BMDDeckLinkAPIEngineeringMode`: `1` (`0x1`)

## Intensity Pro (Intensity Pro)

 * Model Name: Intensity Pro
 * Display Name: Intensity Pro
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
  * `IDeckLinkConfiguration`
  * `IDeckLinkConfiguration_v7_6`
  * `IDeckLinkConfiguration_v10_2`
  * `IDeckLinkAttributes`
  * `IDeckLinkDeckControl`
  * `IDeckLinkDeckControl_v7_9`
  * `IDeckLinkDeckControl_v8_1`

### Attributes

  * Flag (32-Bit Integer) `BMDDeckLinkSupportsInternalKeying`: `0` (`0x0`)
  * Flag (32-Bit Integer) `BMDDeckLinkSupportsExternalKeying`: `0` (`0x0`)
  * Flag (32-Bit Integer) `BMDDeckLinkSupportsHDKeying`: `0` (`0x0`)
  * Flag (32-Bit Integer) `BMDDeckLinkSupportsInputFormatDetection`: `0` (`0x0`)
  * Flag (32-Bit Integer) `BMDDeckLinkHasReferenceInput`: `0` (`0x0`)
  * Flag (32-Bit Integer) `BMDDeckLinkHasSerialPort`: `0` (`0x0`)
  * Flag (32-Bit Integer) `BMDDeckLinkHasAnalogVideoOutputGain`: `1` (`0x1`)
  * Flag (32-Bit Integer) `BMDDeckLinkCanOnlyAdjustOverallVideoOutputGain`: `1` (`0x1`)
  * Flag (32-Bit Integer) `BMDDeckLinkHasVideoInputAntiAliasingFilter`: `0` (`0x0`)
  * Flag (32-Bit Integer) `BMDDeckLinkHasBypass`: `0` (`0x0`)
  * Flag (32-Bit Integer) `BMDDeckLinkSupportsDesktopDisplay`: `0` (`0x0`)
  * Flag (32-Bit Integer) `BMDDeckLinkSupportsClockTimingAdjustment`: `0` (`0x0`)
  * Flag (32-Bit Integer) `BMDDeckLinkSupportsFullDuplex`: `0` (`0x0`)
  * Flag (32-Bit Integer) `BMDDeckLinkSupportsFullFrameReferenceInputTimingOffset`: `0` (`0x0`)
  * Flag (32-Bit Integer) `BMDDeckLinkSupportsSMPTELevelAOutput`: `0` (`0x0`)
  * Flag (32-Bit Integer) `BMDDeckLinkHasAllAnalogOutputConnectionsActive`: `0` (`0x0`)
  * Flag (32-Bit Integer) `BMDDeckLinkSupportsAutoSwitchingPPsFOnInput`: `0` (`0x0`)
  * Flag (32-Bit Integer) `BMDDeckLinkSupportsDualLinkSDI`: `0` (`0x0`)
  * Flag (32-Bit Integer) `BMDDeckLinkSupportsIdleOutput`: `1` (`0x1`)
  * 64-Bit Integer `BMDDeckLinkMaximumAudioChannels`: `2` (`0x2`)
  * 64-Bit Integer `BMDDeckLinkMaximumAnalogAudioChannels`: `2` (`0x2`)
  * 64-Bit Integer `BMDDeckLinkNumberOfSubDevices`: `1` (`0x1`)
  * 64-Bit Integer `BMDDeckLinkSubDeviceIndex`: `0` (`0x0`)
  * 64-Bit Integer `BMDDeckLinkTopologicalID`: `1967360` (`0x1E0500`)
  * 64-Bit Integer `BMDDeckLinkVideoOutputConnections`: `58` (`0x3A`) // `bmdVideoConnectionHDMI | bmdVideoConnectionComponent | bmdVideoConnectionComposite | bmdVideoConnectionSVideo`
  * 64-Bit Integer `BMDDeckLinkVideoInputConnections`: `58` (`0x3A`) // `bmdVideoConnectionHDMI | bmdVideoConnectionComponent | bmdVideoConnectionComposite | bmdVideoConnectionSVideo`
  * 64-Bit Integer `BMDDeckLinkAudioOutputConnections`: `23` (`0x17`) // `bmdAudioConnectionEmbedded | bmdAudioConnectionAESEBU | bmdAudioConnectionAnalog | bmdAudioConnectionAnalogRCA`
  * 64-Bit Integer `BMDDeckLinkAudioInputConnections`: `21` (`0x15`) // `bmdAudioConnectionEmbedded | bmdAudioConnectionAnalog | bmdAudioConnectionAnalogRCA`
  * 64-Bit Integer `BMDDeckLinkDeviceBusyState`: `0` (`0x0`)
  * 64-Bit Integer `BMDDeckLinkVideoIOSupport`: `3` (`0x3`)
  * Float `BMDDeckLinkVideoInputGainMinimum`: `-1,800`
  * Float `BMDDeckLinkVideoInputGainMaximum`: `1,800`
  * Float `BMDDeckLinkVideoOutputGainMinimum`: `-1,800`
  * Float `BMDDeckLinkVideoOutputGainMaximum`: `1,800`

### Configuration

  * Flag (32-Bit Integer) `bmdDeckLinkConfigUse1080pNotPsF`: `1` (`0x1`)
  * Flag (32-Bit Integer) `bmdDeckLinkConfigFieldFlickerRemoval`: `0` (`0x0`)
  * Flag (32-Bit Integer) `bmdDeckLinkConfigHD1080p24ToHD1080i5994Conversion`: `0` (`0x0`)
  * Flag (32-Bit Integer) `bmdDeckLinkConfigSingleLinkVideoOutput`: `1` (`0x1`)
  * Flag (32-Bit Integer) `bmdDeckLinkConfigLowLatencyVideoOutput`: `0` (`0x0`)
  * 64-Bit Integer `bmdDeckLinkConfigVideoOutputConnection`: `10` (`0xA`) // `bmdVideoConnectionHDMI | bmdVideoConnectionComponent`
  * 64-Bit Integer `bmdDeckLinkConfigVideoOutputConversionMode`: `1852796517` (`0x6E6F6E65` - `none`) // `bmdNoVideoOutputConversion`
  * 64-Bit Integer `bmdDeckLinkConfigAnalogVideoOutputFlags`: `1` (`0x1`) // `bmdAnalogVideoFlagCompositeSetup75`
  * 64-Bit Integer `bmdDeckLinkConfigVideoOutputIdleOperation`: `1651269987` (`0x626C6163` - `blac`)
  * 64-Bit Integer `bmdDeckLinkConfigDefaultVideoOutputMode`: `1214854448` (`0x48693530` - `Hi50`) // `bmdModeHD1080i50`
  * 64-Bit Integer `bmdDeckLinkConfigDefaultVideoOutputModeFlags`: `0` (`0x0`)
  * Float `bmdDeckLinkConfigVideoOutputComponentLumaGain`: `0,000`
  * Float `bmdDeckLinkConfigVideoOutputCompositeLumaGain`: `0,000`
  * Float `bmdDeckLinkConfigVideoOutputSVideoLumaGain`: `0,000`
  * 64-Bit Integer `bmdDeckLinkConfigVideoInputConnection`: `2` (`0x2`) // `bmdVideoConnectionHDMI`
  * 64-Bit Integer `bmdDeckLinkConfigAnalogVideoInputFlags`: `1` (`0x1`) // `bmdAnalogVideoFlagCompositeSetup75`
  * 64-Bit Integer `bmdDeckLinkConfigVideoInputConversionMode`: `1852796517` (`0x6E6F6E65` - `none`) // `bmdNoVideoInputConversion`
  * 64-Bit Integer `bmdDeckLinkConfig32PulldownSequenceInitialTimecodeFrame`: `0` (`0x0`)
  * 64-Bit Integer `bmdDeckLinkConfigVANCSourceLine1Mapping`: `0` (`0x0`)
  * 64-Bit Integer `bmdDeckLinkConfigVANCSourceLine2Mapping`: `0` (`0x0`)
  * 64-Bit Integer `bmdDeckLinkConfigVANCSourceLine3Mapping`: `0` (`0x0`)
  * Float `bmdDeckLinkConfigVideoInputComponentLumaGain`: `0,000`
  * Float `bmdDeckLinkConfigVideoInputComponentChromaBlueGain`: `0,000`
  * Float `bmdDeckLinkConfigVideoInputComponentChromaRedGain`: `0,000`
  * Float `bmdDeckLinkConfigVideoInputCompositeLumaGain`: `0,000`
  * Float `bmdDeckLinkConfigVideoInputCompositeChromaGain`: `0,000`
  * Float `bmdDeckLinkConfigVideoInputSVideoLumaGain`: `0,000`
  * Float `bmdDeckLinkConfigVideoInputSVideoChromaGain`: `0,000`
  * 64-Bit Integer `bmdDeckLinkConfigAudioInputConnection`: `1` (`0x1`) // `bmdAudioConnectionEmbedded`

### Input Display Modes

 * NTSC:
  * Mode: `bmdModeNTSC` (`ntsc`)
  * Resolution: `720` x `486`
  * Frame Duration: `1001` / `30000` (`29,970` fps, `33 3666` per frame)
  * Field Dominance: `bmdLowerFieldFirst` (`lowr`)
  * Flags: `bmdDisplayModeColorspaceRec601`
  * Pixel Formats: `bmdFormat8BitYUV` (`2vuy`), `bmdFormat10BitYUV` (`v210`), `bmdFormat12BitRAW` (`r12p`)
 * NTSC 23.98:
  * Mode: `bmdModeNTSC2398` (`nt23`)
  * Resolution: `720` x `486`
  * Frame Duration: `1001` / `24000` (`23,976` fps, `41 7083` per frame)
  * Field Dominance: `bmdProgressiveFrame` (`prog`)
  * Flags: `bmdDisplayModeColorspaceRec601`
  * Pixel Formats: `bmdFormat8BitYUV` (`2vuy`), `bmdFormat10BitYUV` (`v210`), `bmdFormat12BitRAW` (`r12p`)
 * PAL:
  * Mode: `bmdModePAL` (`pal `)
  * Resolution: `720` x `576`
  * Frame Duration: `1000` / `25000` (`25,000` fps, `40 0000` per frame)
  * Field Dominance: `bmdUpperFieldFirst` (`uppr`)
  * Flags: `bmdDisplayModeColorspaceRec601`
  * Pixel Formats: `bmdFormat8BitYUV` (`2vuy`), `bmdFormat10BitYUV` (`v210`), `bmdFormat12BitRAW` (`r12p`)
 * NTSC Progressive:
  * Mode: `bmdModeNTSCp` (`ntsp`)
  * Resolution: `720` x `486`
  * Frame Duration: `1001` / `60000` (`59,940` fps, `16 6833` per frame)
  * Field Dominance: `bmdProgressiveFrame` (`prog`)
  * Flags: `bmdDisplayModeColorspaceRec601`
  * Pixel Formats: `bmdFormat8BitYUV` (`2vuy`), `bmdFormat10BitYUV` (`v210`), `bmdFormat12BitRAW` (`r12p`)
 * PAL Progressive:
  * Mode: `bmdModePALp` (`palp`)
  * Resolution: `720` x `576`
  * Frame Duration: `1000` / `50000` (`50,000` fps, `20 0000` per frame)
  * Field Dominance: `bmdProgressiveFrame` (`prog`)
  * Flags: `bmdDisplayModeColorspaceRec601`
  * Pixel Formats: `bmdFormat8BitYUV` (`2vuy`), `bmdFormat10BitYUV` (`v210`), `bmdFormat12BitRAW` (`r12p`)
 * 1080p23.98:
  * Mode: `bmdModeHD1080p2398` (`23ps`)
  * Resolution: `1920` x `1080`
  * Frame Duration: `1001` / `24000` (`23,976` fps, `41 7083` per frame)
  * Field Dominance: `bmdProgressiveFrame` (`prog`)
  * Flags: `bmdDisplayModeColorspaceRec709`
  * Pixel Formats: `bmdFormat8BitYUV` (`2vuy`), `bmdFormat12BitRAW` (`r12p`)
 * 1080p24:
  * Mode: `bmdModeHD1080p24` (`24ps`)
  * Resolution: `1920` x `1080`
  * Frame Duration: `1000` / `24000` (`24,000` fps, `41 6666` per frame)
  * Field Dominance: `bmdProgressiveFrame` (`prog`)
  * Flags: `bmdDisplayModeColorspaceRec709`
  * Pixel Formats: `bmdFormat8BitYUV` (`2vuy`), `bmdFormat12BitRAW` (`r12p`)
 * 1080p25:
  * Mode: `bmdModeHD1080p25` (`Hp25`)
  * Resolution: `1920` x `1080`
  * Frame Duration: `1000` / `25000` (`25,000` fps, `40 0000` per frame)
  * Field Dominance: `bmdProgressiveFrame` (`prog`)
  * Flags: `bmdDisplayModeColorspaceRec709`
  * Pixel Formats: `bmdFormat8BitYUV` (`2vuy`), `bmdFormat12BitRAW` (`r12p`)
 * 1080p29.97:
  * Mode: `bmdModeHD1080p2997` (`Hp29`)
  * Resolution: `1920` x `1080`
  * Frame Duration: `1001` / `30000` (`29,970` fps, `33 3666` per frame)
  * Field Dominance: `bmdProgressiveFrame` (`prog`)
  * Flags: `bmdDisplayModeColorspaceRec709`
  * Pixel Formats: `bmdFormat8BitYUV` (`2vuy`), `bmdFormat12BitRAW` (`r12p`)
 * 1080p30:
  * Mode: `bmdModeHD1080p30` (`Hp30`)
  * Resolution: `1920` x `1080`
  * Frame Duration: `1000` / `30000` (`30,000` fps, `33 3333` per frame)
  * Field Dominance: `bmdProgressiveFrame` (`prog`)
  * Flags: `bmdDisplayModeColorspaceRec709`
  * Pixel Formats: `bmdFormat8BitYUV` (`2vuy`), `bmdFormat12BitRAW` (`r12p`)
 * 1080i50:
  * Mode: `bmdModeHD1080i50` (`Hi50`)
  * Resolution: `1920` x `1080`
  * Frame Duration: `1000` / `25000` (`25,000` fps, `40 0000` per frame)
  * Field Dominance: `bmdUpperFieldFirst` (`uppr`)
  * Flags: `bmdDisplayModeColorspaceRec709`
  * Pixel Formats: `bmdFormat8BitYUV` (`2vuy`), `bmdFormat12BitRAW` (`r12p`)
 * 1080i59.94:
  * Mode: `bmdModeHD1080i5994` (`Hi59`)
  * Resolution: `1920` x `1080`
  * Frame Duration: `1001` / `30000` (`29,970` fps, `33 3666` per frame)
  * Field Dominance: `bmdUpperFieldFirst` (`uppr`)
  * Flags: `bmdDisplayModeColorspaceRec709`
  * Pixel Formats: `bmdFormat8BitYUV` (`2vuy`), `bmdFormat12BitRAW` (`r12p`)
 * 1080i60:
  * Mode: `bmdModeHD1080i6000` (`Hi60`)
  * Resolution: `1920` x `1080`
  * Frame Duration: `1000` / `30000` (`30,000` fps, `33 3333` per frame)
  * Field Dominance: `bmdUpperFieldFirst` (`uppr`)
  * Flags: `bmdDisplayModeColorspaceRec709`
  * Pixel Formats: `bmdFormat8BitYUV` (`2vuy`), `bmdFormat12BitRAW` (`r12p`)
 * 720p50:
  * Mode: `bmdModeHD720p50` (`hp50`)
  * Resolution: `1280` x `720`
  * Frame Duration: `1000` / `50000` (`50,000` fps, `20 0000` per frame)
  * Field Dominance: `bmdProgressiveFrame` (`prog`)
  * Flags: `bmdDisplayModeColorspaceRec709`
  * Pixel Formats: `bmdFormat8BitYUV` (`2vuy`), `bmdFormat12BitRAW` (`r12p`)
 * 720p59.94:
  * Mode: `bmdModeHD720p5994` (`hp59`)
  * Resolution: `1280` x `720`
  * Frame Duration: `1001` / `60000` (`59,940` fps, `16 6833` per frame)
  * Field Dominance: `bmdProgressiveFrame` (`prog`)
  * Flags: `bmdDisplayModeColorspaceRec709`
  * Pixel Formats: `bmdFormat8BitYUV` (`2vuy`), `bmdFormat12BitRAW` (`r12p`)
 * 720p60:
  * Mode: `bmdModeHD720p60` (`hp60`)
  * Resolution: `1280` x `720`
  * Frame Duration: `1000` / `60000` (`60,000` fps, `16 6666` per frame)
  * Field Dominance: `bmdProgressiveFrame` (`prog`)
  * Flags: `bmdDisplayModeColorspaceRec709`
  * Pixel Formats: `bmdFormat8BitYUV` (`2vuy`), `bmdFormat12BitRAW` (`r12p`)

TSV Formatted:

	Name	Display Mode	Display Mode FourCC	Resolution Width	Resolution Height	Frame Duration	Time Scale	Frame Rate, per second	Frame Length, millisecond	Field Dominance	Field Dominance FourCC	Display Mode Flags	Pixel Formats
	NTSC	bmdModeNTSC	ntsc	720	486	1001	30000	29.970	333666	bmdLowerFieldFirst	lowr	bmdDisplayModeColorspaceRec601	bmdFormat8BitYUV 2vuy, bmdFormat10BitYUV v210, bmdFormat12BitRAW r12p
	NTSC 23.98	bmdModeNTSC2398	nt23	720	486	1001	24000	23.976	417083	bmdProgressiveFrame	prog	bmdDisplayModeColorspaceRec601	bmdFormat8BitYUV 2vuy, bmdFormat10BitYUV v210, bmdFormat12BitRAW r12p
	PAL	bmdModePAL	pal 	720	576	1000	25000	25.000	400000	bmdUpperFieldFirst	uppr	bmdDisplayModeColorspaceRec601	bmdFormat8BitYUV 2vuy, bmdFormat10BitYUV v210, bmdFormat12BitRAW r12p
	NTSC Progressive	bmdModeNTSCp	ntsp	720	486	1001	60000	59.940	166833	bmdProgressiveFrame	prog	bmdDisplayModeColorspaceRec601	bmdFormat8BitYUV 2vuy, bmdFormat10BitYUV v210, bmdFormat12BitRAW r12p
	PAL Progressive	bmdModePALp	palp	720	576	1000	50000	50.000	200000	bmdProgressiveFrame	prog	bmdDisplayModeColorspaceRec601	bmdFormat8BitYUV 2vuy, bmdFormat10BitYUV v210, bmdFormat12BitRAW r12p
	1080p23.98	bmdModeHD1080p2398	23ps	1920	1080	1001	24000	23.976	417083	bmdProgressiveFrame	prog	bmdDisplayModeColorspaceRec709	bmdFormat8BitYUV 2vuy, bmdFormat12BitRAW r12p
	1080p24	bmdModeHD1080p24	24ps	1920	1080	1000	24000	24.000	416666	bmdProgressiveFrame	prog	bmdDisplayModeColorspaceRec709	bmdFormat8BitYUV 2vuy, bmdFormat12BitRAW r12p
	1080p25	bmdModeHD1080p25	Hp25	1920	1080	1000	25000	25.000	400000	bmdProgressiveFrame	prog	bmdDisplayModeColorspaceRec709	bmdFormat8BitYUV 2vuy, bmdFormat12BitRAW r12p
	1080p29.97	bmdModeHD1080p2997	Hp29	1920	1080	1001	30000	29.970	333666	bmdProgressiveFrame	prog	bmdDisplayModeColorspaceRec709	bmdFormat8BitYUV 2vuy, bmdFormat12BitRAW r12p
	1080p30	bmdModeHD1080p30	Hp30	1920	1080	1000	30000	30.000	333333	bmdProgressiveFrame	prog	bmdDisplayModeColorspaceRec709	bmdFormat8BitYUV 2vuy, bmdFormat12BitRAW r12p
	1080i50	bmdModeHD1080i50	Hi50	1920	1080	1000	25000	25.000	400000	bmdUpperFieldFirst	uppr	bmdDisplayModeColorspaceRec709	bmdFormat8BitYUV 2vuy, bmdFormat12BitRAW r12p
	1080i59.94	bmdModeHD1080i5994	Hi59	1920	1080	1001	30000	29.970	333666	bmdUpperFieldFirst	uppr	bmdDisplayModeColorspaceRec709	bmdFormat8BitYUV 2vuy, bmdFormat12BitRAW r12p
	1080i60	bmdModeHD1080i6000	Hi60	1920	1080	1000	30000	30.000	333333	bmdUpperFieldFirst	uppr	bmdDisplayModeColorspaceRec709	bmdFormat8BitYUV 2vuy, bmdFormat12BitRAW r12p
	720p50	bmdModeHD720p50	hp50	1280	720	1000	50000	50.000	200000	bmdProgressiveFrame	prog	bmdDisplayModeColorspaceRec709	bmdFormat8BitYUV 2vuy, bmdFormat12BitRAW r12p
	720p59.94	bmdModeHD720p5994	hp59	1280	720	1001	60000	59.940	166833	bmdProgressiveFrame	prog	bmdDisplayModeColorspaceRec709	bmdFormat8BitYUV 2vuy, bmdFormat12BitRAW r12p
	720p60	bmdModeHD720p60	hp60	1280	720	1000	60000	60.000	166666	bmdProgressiveFrame	prog	bmdDisplayModeColorspaceRec709	bmdFormat8BitYUV 2vuy, bmdFormat12BitRAW r12p


### Output Display Modes

 * NTSC:
  * Mode: `bmdModeNTSC` (`ntsc`)
  * Resolution: `720` x `486`
  * Frame Duration: `1001` / `30000` (`29,970` fps, `33 3666` per frame)
  * Field Dominance: `bmdLowerFieldFirst` (`lowr`)
  * Flags: `bmdDisplayModeColorspaceRec601`
  * Pixel Formats: `bmdFormat8BitYUV` (`2vuy`), `bmdFormat10BitYUV` (`v210`)
 * NTSC 23.98:
  * Mode: `bmdModeNTSC2398` (`nt23`)
  * Resolution: `720` x `486`
  * Frame Duration: `1001` / `24000` (`23,976` fps, `41 7083` per frame)
  * Field Dominance: `bmdProgressiveFrame` (`prog`)
  * Flags: `bmdDisplayModeColorspaceRec601`
  * Pixel Formats: `bmdFormat8BitYUV` (`2vuy`), `bmdFormat10BitYUV` (`v210`)
 * PAL:
  * Mode: `bmdModePAL` (`pal `)
  * Resolution: `720` x `576`
  * Frame Duration: `1000` / `25000` (`25,000` fps, `40 0000` per frame)
  * Field Dominance: `bmdUpperFieldFirst` (`uppr`)
  * Flags: `bmdDisplayModeColorspaceRec601`
  * Pixel Formats: `bmdFormat8BitYUV` (`2vuy`), `bmdFormat10BitYUV` (`v210`)
 * NTSC Progressive:
  * Mode: `bmdModeNTSCp` (`ntsp`)
  * Resolution: `720` x `486`
  * Frame Duration: `1001` / `60000` (`59,940` fps, `16 6833` per frame)
  * Field Dominance: `bmdProgressiveFrame` (`prog`)
  * Flags: `bmdDisplayModeColorspaceRec601`
  * Pixel Formats: `bmdFormat8BitYUV` (`2vuy`), `bmdFormat10BitYUV` (`v210`)
 * PAL Progressive:
  * Mode: `bmdModePALp` (`palp`)
  * Resolution: `720` x `576`
  * Frame Duration: `1000` / `50000` (`50,000` fps, `20 0000` per frame)
  * Field Dominance: `bmdProgressiveFrame` (`prog`)
  * Flags: `bmdDisplayModeColorspaceRec601`
  * Pixel Formats: `bmdFormat8BitYUV` (`2vuy`), `bmdFormat10BitYUV` (`v210`)
 * 1080p23.98:
  * Mode: `bmdModeHD1080p2398` (`23ps`)
  * Resolution: `1920` x `1080`
  * Frame Duration: `1001` / `24000` (`23,976` fps, `41 7083` per frame)
  * Field Dominance: `bmdProgressiveFrame` (`prog`)
  * Flags: `bmdDisplayModeColorspaceRec709`
  * Pixel Formats: `bmdFormat8BitYUV` (`2vuy`)
 * 1080p24:
  * Mode: `bmdModeHD1080p24` (`24ps`)
  * Resolution: `1920` x `1080`
  * Frame Duration: `1000` / `24000` (`24,000` fps, `41 6666` per frame)
  * Field Dominance: `bmdProgressiveFrame` (`prog`)
  * Flags: `bmdDisplayModeColorspaceRec709`
  * Pixel Formats: `bmdFormat8BitYUV` (`2vuy`)
 * 1080p25:
  * Mode: `bmdModeHD1080p25` (`Hp25`)
  * Resolution: `1920` x `1080`
  * Frame Duration: `1000` / `25000` (`25,000` fps, `40 0000` per frame)
  * Field Dominance: `bmdProgressiveFrame` (`prog`)
  * Flags: `bmdDisplayModeColorspaceRec709`
  * Pixel Formats: `bmdFormat8BitYUV` (`2vuy`)
 * 1080p29.97:
  * Mode: `bmdModeHD1080p2997` (`Hp29`)
  * Resolution: `1920` x `1080`
  * Frame Duration: `1001` / `30000` (`29,970` fps, `33 3666` per frame)
  * Field Dominance: `bmdProgressiveFrame` (`prog`)
  * Flags: `bmdDisplayModeColorspaceRec709`
  * Pixel Formats: `bmdFormat8BitYUV` (`2vuy`)
 * 1080p30:
  * Mode: `bmdModeHD1080p30` (`Hp30`)
  * Resolution: `1920` x `1080`
  * Frame Duration: `1000` / `30000` (`30,000` fps, `33 3333` per frame)
  * Field Dominance: `bmdProgressiveFrame` (`prog`)
  * Flags: `bmdDisplayModeColorspaceRec709`
  * Pixel Formats: `bmdFormat8BitYUV` (`2vuy`)
 * 1080i50:
  * Mode: `bmdModeHD1080i50` (`Hi50`)
  * Resolution: `1920` x `1080`
  * Frame Duration: `1000` / `25000` (`25,000` fps, `40 0000` per frame)
  * Field Dominance: `bmdUpperFieldFirst` (`uppr`)
  * Flags: `bmdDisplayModeColorspaceRec709`
  * Pixel Formats: `bmdFormat8BitYUV` (`2vuy`)
 * 1080i59.94:
  * Mode: `bmdModeHD1080i5994` (`Hi59`)
  * Resolution: `1920` x `1080`
  * Frame Duration: `1001` / `30000` (`29,970` fps, `33 3666` per frame)
  * Field Dominance: `bmdUpperFieldFirst` (`uppr`)
  * Flags: `bmdDisplayModeColorspaceRec709`
  * Pixel Formats: `bmdFormat8BitYUV` (`2vuy`)
 * 1080i60:
  * Mode: `bmdModeHD1080i6000` (`Hi60`)
  * Resolution: `1920` x `1080`
  * Frame Duration: `1000` / `30000` (`30,000` fps, `33 3333` per frame)
  * Field Dominance: `bmdUpperFieldFirst` (`uppr`)
  * Flags: `bmdDisplayModeColorspaceRec709`
  * Pixel Formats: `bmdFormat8BitYUV` (`2vuy`)
 * 720p50:
  * Mode: `bmdModeHD720p50` (`hp50`)
  * Resolution: `1280` x `720`
  * Frame Duration: `1000` / `50000` (`50,000` fps, `20 0000` per frame)
  * Field Dominance: `bmdProgressiveFrame` (`prog`)
  * Flags: `bmdDisplayModeColorspaceRec709`
  * Pixel Formats: `bmdFormat8BitYUV` (`2vuy`)
 * 720p59.94:
  * Mode: `bmdModeHD720p5994` (`hp59`)
  * Resolution: `1280` x `720`
  * Frame Duration: `1001` / `60000` (`59,940` fps, `16 6833` per frame)
  * Field Dominance: `bmdProgressiveFrame` (`prog`)
  * Flags: `bmdDisplayModeColorspaceRec709`
  * Pixel Formats: `bmdFormat8BitYUV` (`2vuy`)
 * 720p60:
  * Mode: `bmdModeHD720p60` (`hp60`)
  * Resolution: `1280` x `720`
  * Frame Duration: `1000` / `60000` (`60,000` fps, `16 6666` per frame)
  * Field Dominance: `bmdProgressiveFrame` (`prog`)
  * Flags: `bmdDisplayModeColorspaceRec709`
  * Pixel Formats: `bmdFormat8BitYUV` (`2vuy`)

TSV Formatted:

	Name	Display Mode	Display Mode FourCC	Resolution Width	Resolution Height	Frame Duration	Time Scale	Frame Rate, per second	Frame Length, millisecond	Field Dominance	Field Dominance FourCC	Display Mode Flags	Pixel Formats
	NTSC	bmdModeNTSC	ntsc	720	486	1001	30000	29.970	333666	bmdLowerFieldFirst	lowr	bmdDisplayModeColorspaceRec601	bmdFormat8BitYUV 2vuy, bmdFormat10BitYUV v210
	NTSC 23.98	bmdModeNTSC2398	nt23	720	486	1001	24000	23.976	417083	bmdProgressiveFrame	prog	bmdDisplayModeColorspaceRec601	bmdFormat8BitYUV 2vuy, bmdFormat10BitYUV v210
	PAL	bmdModePAL	pal 	720	576	1000	25000	25.000	400000	bmdUpperFieldFirst	uppr	bmdDisplayModeColorspaceRec601	bmdFormat8BitYUV 2vuy, bmdFormat10BitYUV v210
	NTSC Progressive	bmdModeNTSCp	ntsp	720	486	1001	60000	59.940	166833	bmdProgressiveFrame	prog	bmdDisplayModeColorspaceRec601	bmdFormat8BitYUV 2vuy, bmdFormat10BitYUV v210
	PAL Progressive	bmdModePALp	palp	720	576	1000	50000	50.000	200000	bmdProgressiveFrame	prog	bmdDisplayModeColorspaceRec601	bmdFormat8BitYUV 2vuy, bmdFormat10BitYUV v210
	1080p23.98	bmdModeHD1080p2398	23ps	1920	1080	1001	24000	23.976	417083	bmdProgressiveFrame	prog	bmdDisplayModeColorspaceRec709	bmdFormat8BitYUV 2vuy
	1080p24	bmdModeHD1080p24	24ps	1920	1080	1000	24000	24.000	416666	bmdProgressiveFrame	prog	bmdDisplayModeColorspaceRec709	bmdFormat8BitYUV 2vuy
	1080p25	bmdModeHD1080p25	Hp25	1920	1080	1000	25000	25.000	400000	bmdProgressiveFrame	prog	bmdDisplayModeColorspaceRec709	bmdFormat8BitYUV 2vuy
	1080p29.97	bmdModeHD1080p2997	Hp29	1920	1080	1001	30000	29.970	333666	bmdProgressiveFrame	prog	bmdDisplayModeColorspaceRec709	bmdFormat8BitYUV 2vuy
	1080p30	bmdModeHD1080p30	Hp30	1920	1080	1000	30000	30.000	333333	bmdProgressiveFrame	prog	bmdDisplayModeColorspaceRec709	bmdFormat8BitYUV 2vuy
	1080i50	bmdModeHD1080i50	Hi50	1920	1080	1000	25000	25.000	400000	bmdUpperFieldFirst	uppr	bmdDisplayModeColorspaceRec709	bmdFormat8BitYUV 2vuy
	1080i59.94	bmdModeHD1080i5994	Hi59	1920	1080	1001	30000	29.970	333666	bmdUpperFieldFirst	uppr	bmdDisplayModeColorspaceRec709	bmdFormat8BitYUV 2vuy
	1080i60	bmdModeHD1080i6000	Hi60	1920	1080	1000	30000	30.000	333333	bmdUpperFieldFirst	uppr	bmdDisplayModeColorspaceRec709	bmdFormat8BitYUV 2vuy
	720p50	bmdModeHD720p50	hp50	1280	720	1000	50000	50.000	200000	bmdProgressiveFrame	prog	bmdDisplayModeColorspaceRec709	bmdFormat8BitYUV 2vuy
	720p59.94	bmdModeHD720p5994	hp59	1280	720	1001	60000	59.940	166833	bmdProgressiveFrame	prog	bmdDisplayModeColorspaceRec709	bmdFormat8BitYUV 2vuy
	720p60	bmdModeHD720p60	hp60	1280	720	1000	60000	60.000	166666	bmdProgressiveFrame	prog	bmdDisplayModeColorspaceRec709	bmdFormat8BitYUV 2vuy



