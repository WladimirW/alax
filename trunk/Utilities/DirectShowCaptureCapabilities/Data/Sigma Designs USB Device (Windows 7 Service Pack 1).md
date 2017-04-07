

# System

 * Version: 6.1.7601, Windows 7, Service Pack 1.0, VER_SUITE_SINGLEUSERTS, VER_NT_WORKSTATION
 * Product: PRODUCT_PROFESSIONAL
 * Computer Name: `MESA`
 * User Name: `MESA\Administrador` (Administrator)
 * Locale: System `es-ES`, User `es-ES`
 * Local Time: `24/03/2017 13:48:39`
 * Architecture: AMD/Intel x64 (x64 Application)
 * Processors: `4`, Active Mask `0xF`
 * Page Size: `0x1000`
 * Application Address Space: `0x0000000000010000`..`0x000007FFFFFEFFFF`
 * CPU: `GenuineIntel`, 0x1 EDX `0xBFEBFBFF` (MMX, SSE, SSE2), 0x1 ECX `0x0008E39D` (SSE3, SSSE3, SSE41), Brand `Intel(R) Core(TM)2 Quad  CPU   Q8200  @ 2.33GHz`
 * Physical Memory: `4.095` MB
 * Committed Memory Limit: `8.188` MB
 * Application Version: `1.0.0.548`

# Devices

## `GUID_DEVCLASS_MEDIA`

 * HD Capture Pro Device
  * Instance: USB\VID_1B80&PID_E006\FFFFFFFF
  * DEVPKEY_Device_Manufacturer: HD Capture Pro 
  * DEVPKEY_Device_DriverVersion: 1.0.15.612
 * Realtek High Definition Audio
  * Instance: HDAUDIO\FUNC_01&VEN_10EC&DEV_0888&SUBSYS_104382FE&REV_1001\4&22BA60&0&0001
  * DEVPKEY_Device_Manufacturer: Realtek
  * DEVPKEY_Device_DriverVersion: 6.0.1.7209

# API

Version information (file version):

 * quartz.dll: Product 6.6.7601.19091, File 6.6.7601.19091
 * mfplat.dll: Product 12.0.7601.19091, File 12.0.7601.19091

# Video

 * Sigma Designs USB Device

## Device: Sigma Designs USB Device

 * Moniker Display Name: @device:pnp:\\?\usb#vid_1b80&pid_e006#ffffffff#{65e8773d-8f56-11d0-a3b9-00a0c9223196}\{9cbcb401-4d80-4b32-885a-43e9686b811f}

Interfaces:

  * `ISpecifyPropertyPages`
  * `IKsPropertySet`
  * `IAMAnalogVideoDecoder`
  * `IAMDeviceRemoval`
  * `IAMFilterMiscFlags`
  * `IAMVideoProcAmp`

Property Pages:

  * `{71F96466-78F3-11D0-A18C-00A0C9118956}` - `CLSID_AnalogVideoDecoderPropertyPage`, VideoDecoder Property Page
  * `{71F96464-78F3-11D0-A18C-00A0C9118956}` - `CLSID_VideoProcAmpPropertyPage`, VideoProcAmp Property Page

### IAMVideoProcAmp

 * `VideoProcAmp_Brightness`: 128, flags VideoProcAmp_Flags_Manual, 0..255, step 1, default 128, cap flags VideoProcAmp_Flags_Manual
 * `VideoProcAmp_Contrast`: 128, flags VideoProcAmp_Flags_Manual, 0..255, step 1, default 128, cap flags VideoProcAmp_Flags_Manual
 * `VideoProcAmp_Hue`: 128, flags VideoProcAmp_Flags_Manual, 0..255, step 1, default 128, cap flags VideoProcAmp_Flags_Manual
 * `VideoProcAmp_Saturation`: 128, flags VideoProcAmp_Flags_Manual, 0..255, step 1, default 128, cap flags VideoProcAmp_Flags_Manual

### IAMAnalogVideoDecoder

 * Available TV Formats: AnalogVideo_NTSC_M | AnalogVideo_PAL_B
 * TV Format: 0
 * Horizontal Locked: 0
 * Number of Lines: 0

### Pin: Entrada de vídeo analógico

 * Direction: `PINDIR_INPUT`

 * `AMPROPSETID_Pin`, `AMPROPERTY_PIN_CATEGORY`: `{FB6C4283-0353-11D1-905F-0000C0CC16BA} PIN_CATEGORY_ANALOGVIDEOIN`
Interfaces:

  * `ISpecifyPropertyPages`
  * `IKsPropertySet`
  * `IQualityControl`

### Pin: Analog Audio In

 * Direction: `PINDIR_INPUT`

 * `AMPROPSETID_Pin`, `AMPROPERTY_PIN_CATEGORY`: `{3E2D189F-B15C-4447-96F1-BD1D64FB99BD}`
Interfaces:

  * `ISpecifyPropertyPages`
  * `IKsPropertySet`
  * `IQualityControl`

### Pin: Capturar

 * `AMPROPSETID_Pin`, `AMPROPERTY_PIN_CATEGORY`: `{6994AD05-93EF-11D0-A3CC-00A0C9223196}`
 * Capabilities:
  * Count: `1`
  * Structure Size: `128` (expected `128`)

#### Capability: 0

 * `AM_MEDIA_TYPE`:
  * Data: `76 69 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 59 55 59 32 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 00 00 00 60 09 00 80 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 00 00 00 00 00 00 00 00 00 00 58 00 00 00 00 00 00 00 80 82 31 00 00 00 00 00`
  * Format Data: `00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 40 19 01 00 00 00 00 63 17 05 00 00 00 00 00 28 00 00 00 80 02 00 00 E0 01 00 00 01 00 10 00 59 55 59 32 00 60 09 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00`
  * `.subtype`: `FourCC YUY2`
  * `.bFixedSizeSamples`: `1`
  * `.bTemporalCompression`: `0`
  * `.lSampleSize`: `614.400`
  * `.cbFormat`: `88`
  * `VIDEOINFOHEADER`:
  * `.rcSource`: (`0`, `0`) - (`0`, `0`)
  * `.rcTarget`: (`0`, `0`) - (`0`, `0`)
  * `.dwBitRate`: `18432000`
  * `.dwBitErrorRate`: `0`
  * `.AvgTimePerFrame`: `33 3667`
  * `BITMAPINFOHEADER`:
   * `.biSize`: `40`
   * `.biWidth`: `640`
   * `.biHeight`: `480`
   * `.biPlanes`: `1`
   * `.biBitCount`: `16`
   * `.biCompression`: `844715353` `YUY2`
   * `.biSizeImage`: `614.400`
 * `VIDEO_STREAM_CONFIG_CAPS`:
  * Data: `80 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 11 00 00 00 80 02 00 00 E0 01 00 00 80 02 00 00 E0 01 00 00 80 02 00 00 E0 01 00 00 08 00 00 00 01 00 00 00 08 00 00 00 01 00 00 00 80 02 00 00 E0 01 00 00 80 02 00 00 E0 01 00 00 08 00 00 00 01 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 63 17 05 00 00 00 00 00 00 A0 25 26 00 00 00 00 00 00 CA 08 00 00 CA 08`
  * `.guid`: `{05589F80-C356-11CE-BF01-00AA0055595A}`
  * `.VideoStandard`: `17`
  * `.InputSize`: `640` x `480`
  * `.MinCroppingSize`: `640` x `480`
  * `.MaxCroppingSize`: `640` x `480`
  * `.CropGranularityX`: `8`
  * `.CropAlignX`: `8`
  * `.CropAlignY`: `1`
  * `.MinOutputSize`: `640` x `480`
  * `.MaxOutputSize`: `640` x `480`
  * `.OutputGranularityX`: `8`
  * `.OutputGranularityY`: `1`
  * `.StretchTapsX`: `0`
  * `.StretchTapsY`: `0`
  * `.ShrinkTapsX`: `0`
  * `.ShrinkTapsY`: `0`
  * `.MinFrameInterval`: `33 3667`
  * `.MaxFrameInterval`: `64 000 0000`
  * `.MinBitsPerSecond`: `147.456.000`
  * `.MaxBitsPerSecond`: `147.456.000`

Capability Summary: 

 * Subtypes: FourCC YUY2
 * Resolutions: 640x480

Interfaces:

  * `ISpecifyPropertyPages`
  * `IKsPropertySet`
  * `IQualityControl`
  * `IAMBufferNegotiation`
  * `IAMStreamConfig`
  * `IAMStreamControl`

### Pin: Audio Out

 * `AMPROPSETID_Pin`, `AMPROPERTY_PIN_CATEGORY`: `{FB6C4281-0353-11D1-905F-0000C0CC16BA} PIN_CATEGORY_CAPTURE`
 * Capabilities:
  * Count: `1`
  * Structure Size: `128` (expected `128`)

#### Capability: 0

 * `AM_MEDIA_TYPE`:
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 00 00 04 00 00 00 81 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 00 00 00 00 00 00 00 00 00 00 12 00 00 00 00 00 00 00 90 0B 2F 00 00 00 00 00`
  * Format Data: `01 00 02 00 80 BB 00 00 00 EE 02 00 04 00 10 00 00 00`
  * `.majortype`: `MEDIATYPE_Audio`
  * `.subtype`: `FourCC 0x00000001`
  * `.bFixedSizeSamples`: `1`
  * `.bTemporalCompression`: `0`
  * `.lSampleSize`: `4`
  * `.cbFormat`: `18`
  * `WAVEFORMATEX`:
   * `.wFormatTag`: `1`
   * `.nChannels`: `2`
   * `.nSamplesPerSec`: `48000`
   * `.nAvgBytesPerSec: `192000`
   * `.nBlockAlign`: `4`
   * `.wBitsPerSample`: `16`
   * `.cbSize`: `0`
 * `AUDIO_STREAM_CONFIG_CAPS`:
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 02 00 00 00 01 00 00 00 10 00 00 00 10 00 00 00 01 00 00 00 00 7D 00 00 00 77 01 00 01 00 00 00`
  * `.MinimumChannels`: `1`
  * `.MaximumChannels`: `2`
  * `.ChannelsGranularity`: `1`
  * `.MinimumBitsPerSample`: `16`
  * `.MaximumBitsPerSample`: `16`
  * `.BitsPerSampleGranularity`: `1`
  * `.MinimumSampleFrequency`: `32000`
  * `.MaximumSampleFrequency`: `96000`
  * `.SampleFrequencyGranularity`: `1`

Interfaces:

  * `ISpecifyPropertyPages`
  * `IKsPropertySet`
  * `IQualityControl`
  * `IAMBufferNegotiation`
  * `IAMStreamConfig`
  * `IAMStreamControl`

Property Pages:

  * `{71F96467-78F3-11D0-A18C-00A0C9118956}` - `CLSID_VideoStreamConfigPropertyPage`, VideoStreamConfig Property Page

### Pin: TS

 * `AMPROPSETID_Pin`, `AMPROPERTY_PIN_CATEGORY`: `{FB6C4281-0353-11D1-905F-0000C0CC16BA} PIN_CATEGORY_CAPTURE`
 * Capabilities:
  * Count: `1`
  * Structure Size: `128` (expected `128`)

#### Capability: 0

 * `AM_MEDIA_TYPE`:
  * Data: `83 EB 36 E4 4F 52 CE 11 9F 53 00 20 AF 0B A7 70 42 B3 AE F4 29 03 DD 4F A8 FD 4A FF 49 26 C9 78 00 00 00 00 00 00 00 00 00 00 00 00 D6 17 64 0F 18 C3 D0 11 A4 3F 00 A0 C9 22 31 96 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00`
  * `.majortype`: `MEDIATYPE_Stream`
  * `.bFixedSizeSamples`: `0`
  * `.bTemporalCompression`: `0`
  * `.lSampleSize`: `0`
  * `.cbFormat`: `0`
 * `VIDEO_STREAM_CONFIG_CAPS`:
  * Data: `00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 01 00 00 00 02 00 00 00 01 00 00 00 10 00 00 00 10 00 00 00 01 00 00 00 00 7D 00 00 00 77 01 00 01 00 00 00 08 00 00 00 01 00 00 00 80 02 00 00 E0 01 00 00 80 02 00 00 E0 01 00 00 08 00 00 00 01 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 63 17 05 00 00 00 00 00 00 A0 25 26 00 00 00 00 00 00 CA 08 00 00 CA 08`
  * `.guid`: `{00000000-0000-0000-0000-000000000000}`
  * `.VideoStandard`: `1`
  * `.InputSize`: `2` x `1`
  * `.MinCroppingSize`: `16` x `16`
  * `.MaxCroppingSize`: `1` x `32000`
  * `.CropGranularityX`: `96000`
  * `.CropAlignX`: `8`
  * `.CropAlignY`: `1`
  * `.MinOutputSize`: `640` x `480`
  * `.MaxOutputSize`: `640` x `480`
  * `.OutputGranularityX`: `8`
  * `.OutputGranularityY`: `1`
  * `.StretchTapsX`: `0`
  * `.StretchTapsY`: `0`
  * `.ShrinkTapsX`: `0`
  * `.ShrinkTapsY`: `0`
  * `.MinFrameInterval`: `33 3667`
  * `.MaxFrameInterval`: `64 000 0000`
  * `.MinBitsPerSecond`: `147.456.000`
  * `.MaxBitsPerSecond`: `147.456.000`

Capability Summary: 

 * Resolutions: 2x1

Interfaces:

  * `ISpecifyPropertyPages`
  * `IKsPropertySet`
  * `IQualityControl`
  * `IAMBufferNegotiation`
  * `IAMStreamConfig`
  * `IAMStreamControl`

Property Pages:

  * `{71F96467-78F3-11D0-A18C-00A0C9118956}` - `CLSID_VideoStreamConfigPropertyPage`, VideoStreamConfig Property Page

# Audio

