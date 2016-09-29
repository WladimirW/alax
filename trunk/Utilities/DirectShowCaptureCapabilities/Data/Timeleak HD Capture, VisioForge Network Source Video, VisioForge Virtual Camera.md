# System

 * Version: 10.0.14393, Windows 10, VER_SUITE_SINGLEUSERTS, VER_NT_WORKSTATION
 * Product: PRODUCT_PROFESSIONAL
 * Computer Name: ``
 * User Name: `DESKTOP-CDO4R6V\R1CH` 
 * Local Time: `29/09/2016 19:44:18`
 * Architecture: x86
 * Processors: `8`, Active Mask `0xFF`
 * Page Size: `0x1000`
 * Application Address Space: `0x00010000`..`0xFFFEFFFF`
 * CPU: `GenuineIntel`, 0x1 EDX `0xBFEBFBFF` (MMX, SSE, SSE2), 0x1 ECX `0x7FFAFBFF` (SSE3, SSSE3, SSE41, SSE42, AVX), 0x7 EBX `0x029C6FBB` (AVX2), Brand `Intel(R) Core(TM) i7-6700 CPU @ 3.40GHz`
 * Physical Memory: `16,261` MB
 * Committed Memory Limit: `18,693` MB
 * Application Version: `1.0.0.540`

# Devices

## `GUID_DEVCLASS_MEDIA`

 * High Definition Audio Device
  * Instance: HDAUDIO\FUNC_01&VEN_10EC&DEV_0900&SUBSYS_1458A0B2&REV_1000\4&1C3E785F&0&0001
  * DEVPKEY_Device_Manufacturer: Microsoft
  * DEVPKEY_Device_DriverVersion: 10.0.14393.0
 * Intel(R) Display Audio
  * Instance: HDAUDIO\FUNC_01&VEN_8086&DEV_2809&SUBSYS_80860101&REV_1000\4&1C3E785F&0&0201
  * DEVPKEY_Device_Manufacturer: Intel(R) Corporation
  * DEVPKEY_Device_DriverVersion: 8.20.0.922
 * Timeleak HD72A Capture Device
  * Instance: PCI\VEN_1131&DEV_7160&SUBSYS_00021131&REV_03\4&B93B4A2&0&00DA
  * DEVPKEY_Device_Manufacturer: Timeleak Electronics, Ltd.
  * DEVPKEY_Device_DriverVersion: 1.0.6.4
 * Microsoft Streaming Quality Manager Proxy
  * Instance: SW\{DDF4358E-BB2C-11D0-A42F-00A0C9223196}\{97EBAACB-95BD-11D0-A3EA-00A0C9223196}
  * DEVPKEY_Device_Manufacturer: Microsoft
  * DEVPKEY_Device_DriverVersion: 10.0.14393.0

# API

Version information (file version):

 * quartz.dll: 10.0.14393.0
 * mfplat.dll: 10.0.14393.187
 * mfcore.dll: 10.0.14393.187
 * fsclient.dll: 10.0.14393.105

# Video

 * Timeleak HD Capture
 * VisioForge Network Source Video
 * VisioForge Virtual Camera

## Device: Timeleak HD Capture

 * Moniker Display Name: @device:pnp:\\?\pci#ven_1131&dev_7160&subsys_00021131&rev_03#4&b93b4a2&0&00da#{65e8773d-8f56-11d0-a3b9-00a0c9223196}\{1efd5893-fc95-4f1f-81f6-386700000000}

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

 * `VideoProcAmp_Brightness`: 0, flags 0, 0..0, step 1, default 0, cap flags VideoProcAmp_Flags_Manual
 * `VideoProcAmp_Contrast`: 0, flags 0, 0..0, step 1, default 0, cap flags VideoProcAmp_Flags_Manual

### IAMAnalogVideoDecoder

 * TV Format: AnalogVideo_PAL_N_COMBO

### Pin: Capture

 * `AMPROPSETID_Pin`, `AMPROPERTY_PIN_CATEGORY`: `{FB6C4281-0353-11D1-905F-0000C0CC16BA} PIN_CATEGORY_CAPTURE`
 * Capabilities:
  * Count: `10`
  * Structure Size: `128` (expected `128`)

#### Capability: 0

 * `AM_MEDIA_TYPE`:
  * Data: `76 69 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 59 55 59 32 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 00 00 00 8C 0A 00 80 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 00 00 58 00 00 00 80 26 E6 02`
  * Format Data: `00 00 00 00 00 00 00 00 D0 02 00 00 E0 01 00 00 00 00 00 00 00 00 00 00 D0 02 00 00 E0 01 00 00 00 CC 4E D9 00 00 00 00 B1 8B 02 00 00 00 00 00 28 00 00 00 D0 02 00 00 E0 01 00 00 01 00 10 00 59 55 59 32 00 8C 0A 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00`
  * `.subtype`: `FourCC YUY2`
  * `.bFixedSizeSamples`: `1`
  * `.bTemporalCompression`: `0`
  * `.lSampleSize`: `691,200`
  * `.cbFormat`: `88`
  * `VIDEOINFOHEADER`:
  * `.rcSource`: (`0`, `0`) - (`720`, `480`)
  * `.rcTarget`: (`0`, `0`) - (`720`, `480`)
  * `.dwBitRate`: `-649147392`
  * `.dwBitErrorRate`: `0`
  * `.AvgTimePerFrame`: `16 6833`
  * `BITMAPINFOHEADER`:
   * `.biSize`: `40`
   * `.biWidth`: `720`
   * `.biHeight`: `480`
   * `.biPlanes`: `1`
   * `.biBitCount`: `16`
   * `.biCompression`: `844715353` `YUY2`
   * `.biSizeImage`: `691,200`
 * `VIDEO_STREAM_CONFIG_CAPS`:
  * Data: `80 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 00 02 D0 02 00 00 E0 01 00 00 D0 02 00 00 E0 01 00 00 D0 02 00 00 E0 01 00 00 D0 02 00 00 E0 01 00 00 01 00 00 00 01 00 00 00 D0 02 00 00 E0 01 00 00 D0 02 00 00 E0 01 00 00 01 00 00 00 01 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 B1 8B 02 00 00 00 00 00 B1 8B 02 00 00 00 00 00 00 80 C6 13 00 80 C6 13`
  * `.guid`: `{05589F80-C356-11CE-BF01-00AA0055595A}`
  * `.VideoStandard`: `33554432`
  * `.InputSize`: `720` x `480`
  * `.MinCroppingSize`: `720` x `480`
  * `.MaxCroppingSize`: `720` x `480`
  * `.CropGranularityX`: `720`
  * `.CropAlignX`: `1`
  * `.CropAlignY`: `1`
  * `.MinOutputSize`: `720` x `480`
  * `.MaxOutputSize`: `720` x `480`
  * `.OutputGranularityX`: `1`
  * `.OutputGranularityY`: `1`
  * `.StretchTapsX`: `0`
  * `.StretchTapsY`: `0`
  * `.ShrinkTapsX`: `0`
  * `.ShrinkTapsY`: `0`
  * `.MinFrameInterval`: `16 6833`
  * `.MaxFrameInterval`: `16 6833`
  * `.MinBitsPerSecond`: `331,776,000`
  * `.MaxBitsPerSecond`: `331,776,000`

#### Capability: 1

 * `AM_MEDIA_TYPE`:
  * Data: `76 69 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 59 55 59 32 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 00 00 00 8C 0A 00 80 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 00 00 58 00 00 00 80 26 E6 02`
  * Format Data: `00 00 00 00 00 00 00 00 D0 02 00 00 E0 01 00 00 00 00 00 00 00 00 00 00 D0 02 00 00 E0 01 00 00 00 AC 07 01 00 00 00 00 80 1A 06 00 00 00 00 00 28 00 00 00 D0 02 00 00 E0 01 00 00 01 00 10 00 59 55 59 32 00 8C 0A 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00`
  * `.subtype`: `FourCC YUY2`
  * `.bFixedSizeSamples`: `1`
  * `.bTemporalCompression`: `0`
  * `.lSampleSize`: `691,200`
  * `.cbFormat`: `88`
  * `VIDEOINFOHEADER`:
  * `.rcSource`: (`0`, `0`) - (`720`, `480`)
  * `.rcTarget`: (`0`, `0`) - (`720`, `480`)
  * `.dwBitRate`: `17280000`
  * `.dwBitErrorRate`: `0`
  * `.AvgTimePerFrame`: `40 0000`
  * `BITMAPINFOHEADER`:
   * `.biSize`: `40`
   * `.biWidth`: `720`
   * `.biHeight`: `480`
   * `.biPlanes`: `1`
   * `.biBitCount`: `16`
   * `.biCompression`: `844715353` `YUY2`
   * `.biSizeImage`: `691,200`
 * `VIDEO_STREAM_CONFIG_CAPS`:
  * Data: `80 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 00 01 D0 02 00 00 E0 01 00 00 D0 02 00 00 E0 01 00 00 D0 02 00 00 E0 01 00 00 01 00 00 00 01 00 00 00 01 00 00 00 01 00 00 00 D0 02 00 00 E0 01 00 00 D0 02 00 00 E0 01 00 00 01 00 00 00 01 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 63 17 05 00 00 00 00 00 63 17 05 00 00 00 00 00 00 40 E3 09 00 40 E3 09`
  * `.guid`: `{05589F80-C356-11CE-BF01-00AA0055595A}`
  * `.VideoStandard`: `16777216`
  * `.InputSize`: `720` x `480`
  * `.MinCroppingSize`: `720` x `480`
  * `.MaxCroppingSize`: `720` x `480`
  * `.CropGranularityX`: `1`
  * `.CropAlignX`: `1`
  * `.CropAlignY`: `1`
  * `.MinOutputSize`: `720` x `480`
  * `.MaxOutputSize`: `720` x `480`
  * `.OutputGranularityX`: `1`
  * `.OutputGranularityY`: `1`
  * `.StretchTapsX`: `0`
  * `.StretchTapsY`: `0`
  * `.ShrinkTapsX`: `0`
  * `.ShrinkTapsY`: `0`
  * `.MinFrameInterval`: `33 3667`
  * `.MaxFrameInterval`: `33 3667`
  * `.MinBitsPerSecond`: `165,888,000`
  * `.MaxBitsPerSecond`: `165,888,000`

#### Capability: 2

 * `AM_MEDIA_TYPE`:
  * Data: `76 69 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 59 55 59 32 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 00 00 00 A8 0C 00 80 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 00 00 58 00 00 00 80 26 E6 02`
  * Format Data: `00 00 00 00 00 00 00 00 D0 02 00 00 40 02 00 00 00 00 00 00 00 00 00 00 D0 02 00 00 40 02 00 00 00 00 B2 9F 00 00 00 00 40 0D 03 00 00 00 00 00 28 00 00 00 D0 02 00 00 40 02 00 00 01 00 10 00 59 55 59 32 00 A8 0C 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00`
  * `.subtype`: `FourCC YUY2`
  * `.bFixedSizeSamples`: `1`
  * `.bTemporalCompression`: `0`
  * `.lSampleSize`: `829,440`
  * `.cbFormat`: `88`
  * `VIDEOINFOHEADER`:
  * `.rcSource`: (`0`, `0`) - (`720`, `576`)
  * `.rcTarget`: (`0`, `0`) - (`720`, `576`)
  * `.dwBitRate`: `-1615724544`
  * `.dwBitErrorRate`: `0`
  * `.AvgTimePerFrame`: `20 0000`
  * `BITMAPINFOHEADER`:
   * `.biSize`: `40`
   * `.biWidth`: `720`
   * `.biHeight`: `576`
   * `.biPlanes`: `1`
   * `.biBitCount`: `16`
   * `.biCompression`: `844715353` `YUY2`
   * `.biSizeImage`: `829,440`
 * `VIDEO_STREAM_CONFIG_CAPS`:
  * Data: `80 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 00 08 D0 02 00 00 40 02 00 00 D0 02 00 00 40 02 00 00 D0 02 00 00 40 02 00 00 D0 02 00 00 40 02 00 00 01 00 00 00 01 00 00 00 D0 02 00 00 40 02 00 00 D0 02 00 00 40 02 00 00 01 00 00 00 01 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 40 0D 03 00 00 00 00 00 40 0D 03 00 00 00 00 00 00 80 C6 13 00 80 C6 13`
  * `.guid`: `{05589F80-C356-11CE-BF01-00AA0055595A}`
  * `.VideoStandard`: `134217728`
  * `.InputSize`: `720` x `576`
  * `.MinCroppingSize`: `720` x `576`
  * `.MaxCroppingSize`: `720` x `576`
  * `.CropGranularityX`: `720`
  * `.CropAlignX`: `1`
  * `.CropAlignY`: `1`
  * `.MinOutputSize`: `720` x `576`
  * `.MaxOutputSize`: `720` x `576`
  * `.OutputGranularityX`: `1`
  * `.OutputGranularityY`: `1`
  * `.StretchTapsX`: `0`
  * `.StretchTapsY`: `0`
  * `.ShrinkTapsX`: `0`
  * `.ShrinkTapsY`: `0`
  * `.MinFrameInterval`: `20 0000`
  * `.MaxFrameInterval`: `20 0000`
  * `.MinBitsPerSecond`: `331,776,000`
  * `.MaxBitsPerSecond`: `331,776,000`

#### Capability: 3

 * `AM_MEDIA_TYPE`:
  * Data: `76 69 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 59 55 59 32 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 00 00 00 A8 0C 00 80 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 00 00 58 00 00 00 80 26 E6 02`
  * Format Data: `00 00 00 00 00 00 00 00 D0 02 00 00 40 02 00 00 00 00 00 00 00 00 00 00 D0 02 00 00 40 02 00 00 00 68 3C 01 00 00 00 00 80 1A 06 00 00 00 00 00 28 00 00 00 D0 02 00 00 40 02 00 00 01 00 10 00 59 55 59 32 00 A8 0C 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00`
  * `.subtype`: `FourCC YUY2`
  * `.bFixedSizeSamples`: `1`
  * `.bTemporalCompression`: `0`
  * `.lSampleSize`: `829,440`
  * `.cbFormat`: `88`
  * `VIDEOINFOHEADER`:
  * `.rcSource`: (`0`, `0`) - (`720`, `576`)
  * `.rcTarget`: (`0`, `0`) - (`720`, `576`)
  * `.dwBitRate`: `20736000`
  * `.dwBitErrorRate`: `0`
  * `.AvgTimePerFrame`: `40 0000`
  * `BITMAPINFOHEADER`:
   * `.biSize`: `40`
   * `.biWidth`: `720`
   * `.biHeight`: `576`
   * `.biPlanes`: `1`
   * `.biBitCount`: `16`
   * `.biCompression`: `844715353` `YUY2`
   * `.biSizeImage`: `829,440`
 * `VIDEO_STREAM_CONFIG_CAPS`:
  * Data: `80 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 00 04 D0 02 00 00 40 02 00 00 D0 02 00 00 40 02 00 00 D0 02 00 00 40 02 00 00 01 00 00 00 01 00 00 00 01 00 00 00 01 00 00 00 D0 02 00 00 40 02 00 00 D0 02 00 00 40 02 00 00 01 00 00 00 01 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 80 1A 06 00 00 00 00 00 80 1A 06 00 00 00 00 00 00 40 E3 09 00 40 E3 09`
  * `.guid`: `{05589F80-C356-11CE-BF01-00AA0055595A}`
  * `.VideoStandard`: `67108864`
  * `.InputSize`: `720` x `576`
  * `.MinCroppingSize`: `720` x `576`
  * `.MaxCroppingSize`: `720` x `576`
  * `.CropGranularityX`: `1`
  * `.CropAlignX`: `1`
  * `.CropAlignY`: `1`
  * `.MinOutputSize`: `720` x `576`
  * `.MaxOutputSize`: `720` x `576`
  * `.OutputGranularityX`: `1`
  * `.OutputGranularityY`: `1`
  * `.StretchTapsX`: `0`
  * `.StretchTapsY`: `0`
  * `.ShrinkTapsX`: `0`
  * `.ShrinkTapsY`: `0`
  * `.MinFrameInterval`: `40 0000`
  * `.MaxFrameInterval`: `40 0000`
  * `.MinBitsPerSecond`: `165,888,000`
  * `.MaxBitsPerSecond`: `165,888,000`

#### Capability: 4

 * `AM_MEDIA_TYPE`:
  * Data: `76 69 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 59 55 59 32 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 00 00 00 60 09 00 80 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 00 00 58 00 00 00 80 26 E6 02`
  * Format Data: `00 00 00 00 00 00 00 00 80 02 00 00 E0 01 00 00 00 00 00 00 00 00 00 00 80 02 00 00 E0 01 00 00 00 60 9B DD 00 00 00 00 B1 8B 02 00 00 00 00 00 28 00 00 00 80 02 00 00 E0 01 00 00 01 00 10 00 59 55 59 32 00 60 09 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00`
  * `.subtype`: `FourCC YUY2`
  * `.bFixedSizeSamples`: `1`
  * `.bTemporalCompression`: `0`
  * `.lSampleSize`: `614,400`
  * `.cbFormat`: `88`
  * `VIDEOINFOHEADER`:
  * `.rcSource`: (`0`, `0`) - (`640`, `480`)
  * `.rcTarget`: (`0`, `0`) - (`640`, `480`)
  * `.dwBitRate`: `-577019904`
  * `.dwBitErrorRate`: `0`
  * `.AvgTimePerFrame`: `16 6833`
  * `BITMAPINFOHEADER`:
   * `.biSize`: `40`
   * `.biWidth`: `640`
   * `.biHeight`: `480`
   * `.biPlanes`: `1`
   * `.biBitCount`: `16`
   * `.biCompression`: `844715353` `YUY2`
   * `.biSizeImage`: `614,400`
 * `VIDEO_STREAM_CONFIG_CAPS`:
  * Data: `80 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 08 00 80 02 00 00 E0 01 00 00 80 02 00 00 E0 01 00 00 80 02 00 00 E0 01 00 00 80 02 00 00 E0 01 00 00 01 00 00 00 01 00 00 00 80 02 00 00 E0 01 00 00 80 02 00 00 E0 01 00 00 01 00 00 00 01 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 B1 8B 02 00 00 00 00 00 B1 8B 02 00 00 00 00 00 00 00 94 11 00 00 94 11`
  * `.guid`: `{05589F80-C356-11CE-BF01-00AA0055595A}`
  * `.VideoStandard`: `524288`
  * `.InputSize`: `640` x `480`
  * `.MinCroppingSize`: `640` x `480`
  * `.MaxCroppingSize`: `640` x `480`
  * `.CropGranularityX`: `640`
  * `.CropAlignX`: `1`
  * `.CropAlignY`: `1`
  * `.MinOutputSize`: `640` x `480`
  * `.MaxOutputSize`: `640` x `480`
  * `.OutputGranularityX`: `1`
  * `.OutputGranularityY`: `1`
  * `.StretchTapsX`: `0`
  * `.StretchTapsY`: `0`
  * `.ShrinkTapsX`: `0`
  * `.ShrinkTapsY`: `0`
  * `.MinFrameInterval`: `16 6833`
  * `.MaxFrameInterval`: `16 6833`
  * `.MinBitsPerSecond`: `294,912,000`
  * `.MaxBitsPerSecond`: `294,912,000`

#### Capability: 5

 * `AM_MEDIA_TYPE`:
  * Data: `76 69 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 59 55 59 32 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 00 00 00 48 3F 00 80 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 00 00 58 00 00 00 80 26 E6 02`
  * Format Data: `00 00 00 00 00 00 00 00 80 07 00 00 38 04 00 00 00 00 00 00 00 00 00 00 80 07 00 00 38 04 00 00 00 08 2E 06 00 00 00 00 80 1A 06 00 00 00 00 00 28 00 00 00 80 07 00 00 38 04 00 00 01 00 10 00 59 55 59 32 00 48 3F 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00`
  * `.subtype`: `FourCC YUY2`
  * `.bFixedSizeSamples`: `1`
  * `.bTemporalCompression`: `0`
  * `.lSampleSize`: `4,147,200`
  * `.cbFormat`: `88`
  * `VIDEOINFOHEADER`:
  * `.rcSource`: (`0`, `0`) - (`1920`, `1080`)
  * `.rcTarget`: (`0`, `0`) - (`1920`, `1080`)
  * `.dwBitRate`: `103680000`
  * `.dwBitErrorRate`: `0`
  * `.AvgTimePerFrame`: `40 0000`
  * `BITMAPINFOHEADER`:
   * `.biSize`: `40`
   * `.biWidth`: `1920`
   * `.biHeight`: `1080`
   * `.biPlanes`: `1`
   * `.biBitCount`: `16`
   * `.biCompression`: `844715353` `YUY2`
   * `.biSizeImage`: `4,147,200`
 * `VIDEO_STREAM_CONFIG_CAPS`:
  * Data: `80 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 80 80 80 07 00 00 38 04 00 00 80 07 00 00 38 04 00 00 80 07 00 00 38 04 00 00 01 00 00 00 01 00 00 00 01 00 00 00 01 00 00 00 80 07 00 00 38 04 00 00 80 07 00 00 38 04 00 00 01 00 00 00 01 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 63 17 05 00 00 00 00 00 63 17 05 00 00 00 00 00 00 A0 F1 04 00 80 53 3B`
  * `.guid`: `{05589F80-C356-11CE-BF01-00AA0055595A}`
  * `.VideoStandard`: `-2139095040`
  * `.InputSize`: `1920` x `1080`
  * `.MinCroppingSize`: `1920` x `1080`
  * `.MaxCroppingSize`: `1920` x `1080`
  * `.CropGranularityX`: `1`
  * `.CropAlignX`: `1`
  * `.CropAlignY`: `1`
  * `.MinOutputSize`: `1920` x `1080`
  * `.MaxOutputSize`: `1920` x `1080`
  * `.OutputGranularityX`: `1`
  * `.OutputGranularityY`: `1`
  * `.StretchTapsX`: `0`
  * `.StretchTapsY`: `0`
  * `.ShrinkTapsX`: `0`
  * `.ShrinkTapsY`: `0`
  * `.MinFrameInterval`: `33 3667`
  * `.MaxFrameInterval`: `33 3667`
  * `.MinBitsPerSecond`: `82,944,000`
  * `.MaxBitsPerSecond`: `995,328,000`

#### Capability: 6

 * `AM_MEDIA_TYPE`:
  * Data: `76 69 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 59 55 59 32 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 00 00 00 48 3F 00 80 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 00 00 58 00 00 00 80 26 E6 02`
  * Format Data: `00 00 00 00 00 00 00 00 80 07 00 00 38 04 00 00 00 00 00 00 00 00 00 00 80 07 00 00 38 04 00 00 00 08 2E 06 00 00 00 00 80 1A 06 00 00 00 00 00 28 00 00 00 80 07 00 00 38 04 00 00 01 00 10 00 59 55 59 32 00 48 3F 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00`
  * `.subtype`: `FourCC YUY2`
  * `.bFixedSizeSamples`: `1`
  * `.bTemporalCompression`: `0`
  * `.lSampleSize`: `4,147,200`
  * `.cbFormat`: `88`
  * `VIDEOINFOHEADER`:
  * `.rcSource`: (`0`, `0`) - (`1920`, `1080`)
  * `.rcTarget`: (`0`, `0`) - (`1920`, `1080`)
  * `.dwBitRate`: `103680000`
  * `.dwBitErrorRate`: `0`
  * `.AvgTimePerFrame`: `40 0000`
  * `BITMAPINFOHEADER`:
   * `.biSize`: `40`
   * `.biWidth`: `1920`
   * `.biHeight`: `1080`
   * `.biPlanes`: `1`
   * `.biBitCount`: `16`
   * `.biCompression`: `844715353` `YUY2`
   * `.biSizeImage`: `4,147,200`
 * `VIDEO_STREAM_CONFIG_CAPS`:
  * Data: `80 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 40 40 80 07 00 00 38 04 00 00 80 07 00 00 38 04 00 00 80 07 00 00 38 04 00 00 01 00 00 00 01 00 00 00 01 00 00 00 01 00 00 00 80 07 00 00 38 04 00 00 80 07 00 00 38 04 00 00 01 00 00 00 01 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 80 1A 06 00 00 00 00 00 80 1A 06 00 00 00 00 00 00 B0 1E 04 00 40 70 31`
  * `.guid`: `{05589F80-C356-11CE-BF01-00AA0055595A}`
  * `.VideoStandard`: `1077936128`
  * `.InputSize`: `1920` x `1080`
  * `.MinCroppingSize`: `1920` x `1080`
  * `.MaxCroppingSize`: `1920` x `1080`
  * `.CropGranularityX`: `1`
  * `.CropAlignX`: `1`
  * `.CropAlignY`: `1`
  * `.MinOutputSize`: `1920` x `1080`
  * `.MaxOutputSize`: `1920` x `1080`
  * `.OutputGranularityX`: `1`
  * `.OutputGranularityY`: `1`
  * `.StretchTapsX`: `0`
  * `.StretchTapsY`: `0`
  * `.ShrinkTapsX`: `0`
  * `.ShrinkTapsY`: `0`
  * `.MinFrameInterval`: `40 0000`
  * `.MaxFrameInterval`: `40 0000`
  * `.MinBitsPerSecond`: `69,120,000`
  * `.MaxBitsPerSecond`: `829,440,000`

#### Capability: 7

 * `AM_MEDIA_TYPE`:
  * Data: `76 69 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 59 55 59 32 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 00 00 00 48 3F 00 80 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 00 00 58 00 00 00 80 26 E6 02`
  * Format Data: `00 00 00 00 00 00 00 00 80 07 00 00 38 04 00 00 00 00 00 00 00 00 00 00 80 07 00 00 38 04 00 00 00 C0 EE 05 00 00 00 00 9B 5B 06 00 00 00 00 00 28 00 00 00 80 07 00 00 38 04 00 00 01 00 10 00 59 55 59 32 00 48 3F 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00`
  * `.subtype`: `FourCC YUY2`
  * `.bFixedSizeSamples`: `1`
  * `.bTemporalCompression`: `0`
  * `.lSampleSize`: `4,147,200`
  * `.cbFormat`: `88`
  * `VIDEOINFOHEADER`:
  * `.rcSource`: (`0`, `0`) - (`1920`, `1080`)
  * `.rcTarget`: (`0`, `0`) - (`1920`, `1080`)
  * `.dwBitRate`: `99532800`
  * `.dwBitErrorRate`: `0`
  * `.AvgTimePerFrame`: `41 6667`
  * `BITMAPINFOHEADER`:
   * `.biSize`: `40`
   * `.biWidth`: `1920`
   * `.biHeight`: `1080`
   * `.biPlanes`: `1`
   * `.biBitCount`: `16`
   * `.biCompression`: `844715353` `YUY2`
   * `.biSizeImage`: `4,147,200`
 * `VIDEO_STREAM_CONFIG_CAPS`:
  * Data: `80 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 20 00 80 07 00 00 38 04 00 00 80 07 00 00 38 04 00 00 80 07 00 00 38 04 00 00 01 00 00 00 01 00 00 00 01 00 00 00 01 00 00 00 80 07 00 00 38 04 00 00 80 07 00 00 38 04 00 00 01 00 00 00 01 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 9B 5B 06 00 00 00 00 00 9B 5B 06 00 00 00 00 00 00 80 F4 03 00 00 76 2F`
  * `.guid`: `{05589F80-C356-11CE-BF01-00AA0055595A}`
  * `.VideoStandard`: `2097152`
  * `.InputSize`: `1920` x `1080`
  * `.MinCroppingSize`: `1920` x `1080`
  * `.MaxCroppingSize`: `1920` x `1080`
  * `.CropGranularityX`: `1`
  * `.CropAlignX`: `1`
  * `.CropAlignY`: `1`
  * `.MinOutputSize`: `1920` x `1080`
  * `.MaxOutputSize`: `1920` x `1080`
  * `.OutputGranularityX`: `1`
  * `.OutputGranularityY`: `1`
  * `.StretchTapsX`: `0`
  * `.StretchTapsY`: `0`
  * `.ShrinkTapsX`: `0`
  * `.ShrinkTapsY`: `0`
  * `.MinFrameInterval`: `41 6667`
  * `.MaxFrameInterval`: `41 6667`
  * `.MinBitsPerSecond`: `66,355,200`
  * `.MaxBitsPerSecond`: `796,262,400`

#### Capability: 8

 * `AM_MEDIA_TYPE`:
  * Data: `76 69 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 59 55 59 32 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 00 00 00 20 1C 00 80 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 00 00 58 00 00 00 80 26 E6 02`
  * Format Data: `00 00 00 00 00 00 00 00 00 05 00 00 D0 02 00 00 00 00 00 00 00 00 00 00 00 05 00 00 D0 02 00 00 00 20 D2 98 00 00 00 00 B1 8B 02 00 00 00 00 00 28 00 00 00 00 05 00 00 D0 02 00 00 01 00 10 00 59 55 59 32 00 20 1C 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00`
  * `.subtype`: `FourCC YUY2`
  * `.bFixedSizeSamples`: `1`
  * `.bTemporalCompression`: `0`
  * `.lSampleSize`: `1,843,200`
  * `.cbFormat`: `88`
  * `VIDEOINFOHEADER`:
  * `.rcSource`: (`0`, `0`) - (`1280`, `720`)
  * `.rcTarget`: (`0`, `0`) - (`1280`, `720`)
  * `.dwBitRate`: `-1731059712`
  * `.dwBitErrorRate`: `0`
  * `.AvgTimePerFrame`: `16 6833`
  * `BITMAPINFOHEADER`:
   * `.biSize`: `40`
   * `.biWidth`: `1280`
   * `.biHeight`: `720`
   * `.biPlanes`: `1`
   * `.biBitCount`: `16`
   * `.biCompression`: `844715353` `YUY2`
   * `.biSizeImage`: `1,843,200`
 * `VIDEO_STREAM_CONFIG_CAPS`:
  * Data: `80 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 00 20 00 05 00 00 D0 02 00 00 00 05 00 00 D0 02 00 00 00 05 00 00 D0 02 00 00 01 00 00 00 01 00 00 00 01 00 00 00 01 00 00 00 00 05 00 00 D0 02 00 00 00 05 00 00 D0 02 00 00 01 00 00 00 01 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 B1 8B 02 00 00 00 00 00 B1 8B 02 00 00 00 00 00 00 80 97 06 00 00 BC 34`
  * `.guid`: `{05589F80-C356-11CE-BF01-00AA0055595A}`
  * `.VideoStandard`: `536870912`
  * `.InputSize`: `1280` x `720`
  * `.MinCroppingSize`: `1280` x `720`
  * `.MaxCroppingSize`: `1280` x `720`
  * `.CropGranularityX`: `1`
  * `.CropAlignX`: `1`
  * `.CropAlignY`: `1`
  * `.MinOutputSize`: `1280` x `720`
  * `.MaxOutputSize`: `1280` x `720`
  * `.OutputGranularityX`: `1`
  * `.OutputGranularityY`: `1`
  * `.StretchTapsX`: `0`
  * `.StretchTapsY`: `0`
  * `.ShrinkTapsX`: `0`
  * `.ShrinkTapsY`: `0`
  * `.MinFrameInterval`: `16 6833`
  * `.MaxFrameInterval`: `16 6833`
  * `.MinBitsPerSecond`: `110,592,000`
  * `.MaxBitsPerSecond`: `884,736,000`

#### Capability: 9

 * `AM_MEDIA_TYPE`:
  * Data: `76 69 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 59 55 59 32 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 00 00 00 20 1C 00 80 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 00 00 58 00 00 00 80 26 E6 02`
  * Format Data: `00 00 00 00 00 00 00 00 00 05 00 00 D0 02 00 00 00 00 00 00 00 00 00 00 00 05 00 00 D0 02 00 00 00 00 A8 D4 00 00 00 00 40 0D 03 00 00 00 00 00 28 00 00 00 00 05 00 00 D0 02 00 00 01 00 10 00 59 55 59 32 00 20 1C 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00`
  * `.subtype`: `FourCC YUY2`
  * `.bFixedSizeSamples`: `1`
  * `.bTemporalCompression`: `0`
  * `.lSampleSize`: `1,843,200`
  * `.cbFormat`: `88`
  * `VIDEOINFOHEADER`:
  * `.rcSource`: (`0`, `0`) - (`1280`, `720`)
  * `.rcTarget`: (`0`, `0`) - (`1280`, `720`)
  * `.dwBitRate`: `-727187456`
  * `.dwBitErrorRate`: `0`
  * `.AvgTimePerFrame`: `20 0000`
  * `BITMAPINFOHEADER`:
   * `.biSize`: `40`
   * `.biWidth`: `1280`
   * `.biHeight`: `720`
   * `.biPlanes`: `1`
   * `.biBitCount`: `16`
   * `.biCompression`: `844715353` `YUY2`
   * `.biSizeImage`: `1,843,200`
 * `VIDEO_STREAM_CONFIG_CAPS`:
  * Data: `80 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 00 10 00 05 00 00 D0 02 00 00 00 05 00 00 D0 02 00 00 00 05 00 00 D0 02 00 00 01 00 00 00 01 00 00 00 01 00 00 00 01 00 00 00 00 05 00 00 D0 02 00 00 00 05 00 00 D0 02 00 00 01 00 00 00 01 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 40 0D 03 00 00 00 00 00 40 0D 03 00 00 00 00 00 00 40 7E 05 00 00 F2 2B`
  * `.guid`: `{05589F80-C356-11CE-BF01-00AA0055595A}`
  * `.VideoStandard`: `268435456`
  * `.InputSize`: `1280` x `720`
  * `.MinCroppingSize`: `1280` x `720`
  * `.MaxCroppingSize`: `1280` x `720`
  * `.CropGranularityX`: `1`
  * `.CropAlignX`: `1`
  * `.CropAlignY`: `1`
  * `.MinOutputSize`: `1280` x `720`
  * `.MaxOutputSize`: `1280` x `720`
  * `.OutputGranularityX`: `1`
  * `.OutputGranularityY`: `1`
  * `.StretchTapsX`: `0`
  * `.StretchTapsY`: `0`
  * `.ShrinkTapsX`: `0`
  * `.ShrinkTapsY`: `0`
  * `.MinFrameInterval`: `20 0000`
  * `.MaxFrameInterval`: `20 0000`
  * `.MinBitsPerSecond`: `92,160,000`
  * `.MaxBitsPerSecond`: `737,280,000`

Capability Summary: 

 * Subtypes: FourCC YUY2
 * Resolutions: 720x480, 720x576, 640x480, 1920x1080, 1280x720

Interfaces:

  * `ISpecifyPropertyPages`
  * `IKsPropertySet`
  * `IQualityControl`
  * `IAMBufferNegotiation`
  * `IAMStreamConfig`
  * `IAMStreamControl`

Property Pages:

  * `{71F96467-78F3-11D0-A18C-00A0C9118956}` - `CLSID_VideoStreamConfigPropertyPage`, VideoStreamConfig Property Page

### Pin: Audio

 * `AMPROPSETID_Pin`, `AMPROPERTY_PIN_CATEGORY`: `{FB6C4281-0353-11D1-905F-0000C0CC16BA} PIN_CATEGORY_CAPTURE`
 * Capabilities:
  * Count: `1`
  * Structure Size: `128` (expected `128`)

#### Capability: 0

 * `AM_MEDIA_TYPE`:
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 00 00 04 00 00 00 81 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 00 00 12 00 00 00 D0 71 EC 02`
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
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 02 00 00 00 01 00 00 00 10 00 00 00 10 00 00 00 01 00 00 00 00 7D 00 00 80 BB 00 00 01 00 00 00`
  * `.MinimumChannels`: `1`
  * `.MaximumChannels`: `2`
  * `.ChannelsGranularity`: `1`
  * `.MinimumBitsPerSample`: `16`
  * `.MaximumBitsPerSample`: `16`
  * `.BitsPerSampleGranularity`: `1`
  * `.MinimumSampleFrequency`: `32000`
  * `.MaximumSampleFrequency`: `48000`
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

## Device: VisioForge Network Source Video

 * Moniker Display Name: @device:sw:{860BB310-5D01-11D0-BD3B-00A0C911CE86}\VisioForge Network Source Video

Interfaces:

  * `IAMFilterMiscFlags`

### Pin: Capture

 * `AMPROPSETID_Pin`, `AMPROPERTY_PIN_CATEGORY`: `{FB6C4281-0353-11D1-905F-0000C0CC16BA} PIN_CATEGORY_CAPTURE`
 * Capabilities:
  * Count: `0`
  * Structure Size: `128` (expected `128`)

Interfaces:

  * `IKsPropertySet`
  * `IQualityControl`
  * `IAMBufferNegotiation`
  * `IAMStreamConfig`
  * `IAMStreamControl`

## Device: VisioForge Virtual Camera

 * Moniker Display Name: @device:sw:{860BB310-5D01-11D0-BD3B-00A0C911CE86}\VisioForge Virtual Camera

Interfaces:

  * `IAMFilterMiscFlags`

### Pin: Capture

 * `AMPROPSETID_Pin`, `AMPROPERTY_PIN_CATEGORY`: `{FB6C4281-0353-11D1-905F-0000C0CC16BA} PIN_CATEGORY_CAPTURE`
 * Capabilities:
  * Count: `23`
  * Structure Size: `128` (expected `128`)

#### Capability: 0

 * `AM_MEDIA_TYPE`:
  * Data: `76 69 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 59 55 59 32 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 00 00 00 00 18 00 80 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 00 00 58 00 00 00 C0 F9 EB 02`
  * Format Data: `00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 20 A1 07 00 00 00 00 00 28 00 00 00 00 04 00 00 00 03 00 00 01 00 10 00 59 55 59 32 00 00 18 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00`
  * `.subtype`: `FourCC YUY2`
  * `.bFixedSizeSamples`: `1`
  * `.bTemporalCompression`: `0`
  * `.lSampleSize`: `1,572,864`
  * `.cbFormat`: `88`
  * `VIDEOINFOHEADER`:
  * `.rcSource`: (`0`, `0`) - (`0`, `0`)
  * `.rcTarget`: (`0`, `0`) - (`0`, `0`)
  * `.dwBitRate`: `0`
  * `.dwBitErrorRate`: `0`
  * `.AvgTimePerFrame`: `50 0000`
  * `BITMAPINFOHEADER`:
   * `.biSize`: `40`
   * `.biWidth`: `1024`
   * `.biHeight`: `768`
   * `.biPlanes`: `1`
   * `.biBitCount`: `16`
   * `.biCompression`: `844715353` `YUY2`
   * `.biSizeImage`: `1,572,864`
 * `VIDEO_STREAM_CONFIG_CAPS`:
  * Data: `80 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 00 00 00 04 00 00 00 03 00 00 40 01 00 00 B4 00 00 00 80 07 00 00 38 04 00 00 10 00 00 00 09 00 00 00 00 00 00 00 00 00 00 00 40 01 00 00 B4 00 00 00 80 07 00 00 38 04 00 00 10 00 00 00 09 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 F2 01 00 00 15 16 05 00 00 00 00 00 80 96 98 00 00 00 00 00 00 10 0E 00 00 80 53 3B`
  * `.guid`: `{05589F80-C356-11CE-BF01-00AA0055595A}`
  * `.VideoStandard`: `0`
  * `.InputSize`: `1024` x `768`
  * `.MinCroppingSize`: `320` x `180`
  * `.MaxCroppingSize`: `1920` x `1080`
  * `.CropGranularityX`: `16`
  * `.CropAlignX`: `0`
  * `.CropAlignY`: `0`
  * `.MinOutputSize`: `320` x `180`
  * `.MaxOutputSize`: `1920` x `1080`
  * `.OutputGranularityX`: `16`
  * `.OutputGranularityY`: `9`
  * `.StretchTapsX`: `0`
  * `.StretchTapsY`: `0`
  * `.ShrinkTapsX`: `0`
  * `.ShrinkTapsY`: `0`
  * `.MinFrameInterval`: `33 3333`
  * `.MaxFrameInterval`: `1 000 0000`
  * `.MinBitsPerSecond`: `921,600`
  * `.MaxBitsPerSecond`: `995,328,000`

#### Capability: 1

 * `AM_MEDIA_TYPE`:
  * Data: `76 69 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 59 55 59 32 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 00 00 00 C2 01 00 80 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 00 00 58 00 00 00 C0 F9 EB 02`
  * Format Data: `00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 20 A1 07 00 00 00 00 00 28 00 00 00 40 01 00 00 B4 00 00 00 01 00 10 00 59 55 59 32 00 C2 01 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00`
  * `.subtype`: `FourCC YUY2`
  * `.bFixedSizeSamples`: `1`
  * `.bTemporalCompression`: `0`
  * `.lSampleSize`: `115,200`
  * `.cbFormat`: `88`
  * `VIDEOINFOHEADER`:
  * `.rcSource`: (`0`, `0`) - (`0`, `0`)
  * `.rcTarget`: (`0`, `0`) - (`0`, `0`)
  * `.dwBitRate`: `0`
  * `.dwBitErrorRate`: `0`
  * `.AvgTimePerFrame`: `50 0000`
  * `BITMAPINFOHEADER`:
   * `.biSize`: `40`
   * `.biWidth`: `320`
   * `.biHeight`: `180`
   * `.biPlanes`: `1`
   * `.biBitCount`: `16`
   * `.biCompression`: `844715353` `YUY2`
   * `.biSizeImage`: `115,200`
 * `VIDEO_STREAM_CONFIG_CAPS`:
  * Data: `80 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 00 00 00 04 00 00 00 03 00 00 40 01 00 00 B4 00 00 00 80 07 00 00 38 04 00 00 10 00 00 00 09 00 00 00 00 00 00 00 00 00 00 00 40 01 00 00 B4 00 00 00 80 07 00 00 38 04 00 00 10 00 00 00 09 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 F2 01 00 00 15 16 05 00 00 00 00 00 80 96 98 00 00 00 00 00 00 10 0E 00 00 80 53 3B`
  * `.guid`: `{05589F80-C356-11CE-BF01-00AA0055595A}`
  * `.VideoStandard`: `0`
  * `.InputSize`: `1024` x `768`
  * `.MinCroppingSize`: `320` x `180`
  * `.MaxCroppingSize`: `1920` x `1080`
  * `.CropGranularityX`: `16`
  * `.CropAlignX`: `0`
  * `.CropAlignY`: `0`
  * `.MinOutputSize`: `320` x `180`
  * `.MaxOutputSize`: `1920` x `1080`
  * `.OutputGranularityX`: `16`
  * `.OutputGranularityY`: `9`
  * `.StretchTapsX`: `0`
  * `.StretchTapsY`: `0`
  * `.ShrinkTapsX`: `0`
  * `.ShrinkTapsY`: `0`
  * `.MinFrameInterval`: `33 3333`
  * `.MaxFrameInterval`: `1 000 0000`
  * `.MinBitsPerSecond`: `921,600`
  * `.MaxBitsPerSecond`: `995,328,000`

#### Capability: 2

 * `AM_MEDIA_TYPE`:
  * Data: `76 69 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 59 55 59 32 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 00 00 80 F4 03 00 80 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 00 00 58 00 00 00 C0 F9 EB 02`
  * Format Data: `00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 20 A1 07 00 00 00 00 00 28 00 00 00 E0 01 00 00 0E 01 00 00 01 00 10 00 59 55 59 32 80 F4 03 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00`
  * `.subtype`: `FourCC YUY2`
  * `.bFixedSizeSamples`: `1`
  * `.bTemporalCompression`: `0`
  * `.lSampleSize`: `259,200`
  * `.cbFormat`: `88`
  * `VIDEOINFOHEADER`:
  * `.rcSource`: (`0`, `0`) - (`0`, `0`)
  * `.rcTarget`: (`0`, `0`) - (`0`, `0`)
  * `.dwBitRate`: `0`
  * `.dwBitErrorRate`: `0`
  * `.AvgTimePerFrame`: `50 0000`
  * `BITMAPINFOHEADER`:
   * `.biSize`: `40`
   * `.biWidth`: `480`
   * `.biHeight`: `270`
   * `.biPlanes`: `1`
   * `.biBitCount`: `16`
   * `.biCompression`: `844715353` `YUY2`
   * `.biSizeImage`: `259,200`
 * `VIDEO_STREAM_CONFIG_CAPS`:
  * Data: `80 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 00 00 00 04 00 00 00 03 00 00 40 01 00 00 B4 00 00 00 80 07 00 00 38 04 00 00 10 00 00 00 09 00 00 00 00 00 00 00 00 00 00 00 40 01 00 00 B4 00 00 00 80 07 00 00 38 04 00 00 10 00 00 00 09 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 F2 01 00 00 15 16 05 00 00 00 00 00 80 96 98 00 00 00 00 00 00 10 0E 00 00 80 53 3B`
  * `.guid`: `{05589F80-C356-11CE-BF01-00AA0055595A}`
  * `.VideoStandard`: `0`
  * `.InputSize`: `1024` x `768`
  * `.MinCroppingSize`: `320` x `180`
  * `.MaxCroppingSize`: `1920` x `1080`
  * `.CropGranularityX`: `16`
  * `.CropAlignX`: `0`
  * `.CropAlignY`: `0`
  * `.MinOutputSize`: `320` x `180`
  * `.MaxOutputSize`: `1920` x `1080`
  * `.OutputGranularityX`: `16`
  * `.OutputGranularityY`: `9`
  * `.StretchTapsX`: `0`
  * `.StretchTapsY`: `0`
  * `.ShrinkTapsX`: `0`
  * `.ShrinkTapsY`: `0`
  * `.MinFrameInterval`: `33 3333`
  * `.MaxFrameInterval`: `1 000 0000`
  * `.MinBitsPerSecond`: `921,600`
  * `.MaxBitsPerSecond`: `995,328,000`

#### Capability: 3

 * `AM_MEDIA_TYPE`:
  * Data: `76 69 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 59 55 59 32 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 00 00 00 08 07 00 80 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 00 00 58 00 00 00 C0 F9 EB 02`
  * Format Data: `00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 20 A1 07 00 00 00 00 00 28 00 00 00 80 02 00 00 68 01 00 00 01 00 10 00 59 55 59 32 00 08 07 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00`
  * `.subtype`: `FourCC YUY2`
  * `.bFixedSizeSamples`: `1`
  * `.bTemporalCompression`: `0`
  * `.lSampleSize`: `460,800`
  * `.cbFormat`: `88`
  * `VIDEOINFOHEADER`:
  * `.rcSource`: (`0`, `0`) - (`0`, `0`)
  * `.rcTarget`: (`0`, `0`) - (`0`, `0`)
  * `.dwBitRate`: `0`
  * `.dwBitErrorRate`: `0`
  * `.AvgTimePerFrame`: `50 0000`
  * `BITMAPINFOHEADER`:
   * `.biSize`: `40`
   * `.biWidth`: `640`
   * `.biHeight`: `360`
   * `.biPlanes`: `1`
   * `.biBitCount`: `16`
   * `.biCompression`: `844715353` `YUY2`
   * `.biSizeImage`: `460,800`
 * `VIDEO_STREAM_CONFIG_CAPS`:
  * Data: `80 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 00 00 00 04 00 00 00 03 00 00 40 01 00 00 B4 00 00 00 80 07 00 00 38 04 00 00 10 00 00 00 09 00 00 00 00 00 00 00 00 00 00 00 40 01 00 00 B4 00 00 00 80 07 00 00 38 04 00 00 10 00 00 00 09 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 F2 01 00 00 15 16 05 00 00 00 00 00 80 96 98 00 00 00 00 00 00 10 0E 00 00 80 53 3B`
  * `.guid`: `{05589F80-C356-11CE-BF01-00AA0055595A}`
  * `.VideoStandard`: `0`
  * `.InputSize`: `1024` x `768`
  * `.MinCroppingSize`: `320` x `180`
  * `.MaxCroppingSize`: `1920` x `1080`
  * `.CropGranularityX`: `16`
  * `.CropAlignX`: `0`
  * `.CropAlignY`: `0`
  * `.MinOutputSize`: `320` x `180`
  * `.MaxOutputSize`: `1920` x `1080`
  * `.OutputGranularityX`: `16`
  * `.OutputGranularityY`: `9`
  * `.StretchTapsX`: `0`
  * `.StretchTapsY`: `0`
  * `.ShrinkTapsX`: `0`
  * `.ShrinkTapsY`: `0`
  * `.MinFrameInterval`: `33 3333`
  * `.MaxFrameInterval`: `1 000 0000`
  * `.MinBitsPerSecond`: `921,600`
  * `.MaxBitsPerSecond`: `995,328,000`

#### Capability: 4

 * `AM_MEDIA_TYPE`:
  * Data: `76 69 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 59 55 59 32 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 00 00 80 FC 0A 00 80 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 00 00 58 00 00 00 C0 F9 EB 02`
  * Format Data: `00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 20 A1 07 00 00 00 00 00 28 00 00 00 20 03 00 00 C2 01 00 00 01 00 10 00 59 55 59 32 80 FC 0A 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00`
  * `.subtype`: `FourCC YUY2`
  * `.bFixedSizeSamples`: `1`
  * `.bTemporalCompression`: `0`
  * `.lSampleSize`: `720,000`
  * `.cbFormat`: `88`
  * `VIDEOINFOHEADER`:
  * `.rcSource`: (`0`, `0`) - (`0`, `0`)
  * `.rcTarget`: (`0`, `0`) - (`0`, `0`)
  * `.dwBitRate`: `0`
  * `.dwBitErrorRate`: `0`
  * `.AvgTimePerFrame`: `50 0000`
  * `BITMAPINFOHEADER`:
   * `.biSize`: `40`
   * `.biWidth`: `800`
   * `.biHeight`: `450`
   * `.biPlanes`: `1`
   * `.biBitCount`: `16`
   * `.biCompression`: `844715353` `YUY2`
   * `.biSizeImage`: `720,000`
 * `VIDEO_STREAM_CONFIG_CAPS`:
  * Data: `80 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 00 00 00 04 00 00 00 03 00 00 40 01 00 00 B4 00 00 00 80 07 00 00 38 04 00 00 10 00 00 00 09 00 00 00 00 00 00 00 00 00 00 00 40 01 00 00 B4 00 00 00 80 07 00 00 38 04 00 00 10 00 00 00 09 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 F2 01 00 00 15 16 05 00 00 00 00 00 80 96 98 00 00 00 00 00 00 10 0E 00 00 80 53 3B`
  * `.guid`: `{05589F80-C356-11CE-BF01-00AA0055595A}`
  * `.VideoStandard`: `0`
  * `.InputSize`: `1024` x `768`
  * `.MinCroppingSize`: `320` x `180`
  * `.MaxCroppingSize`: `1920` x `1080`
  * `.CropGranularityX`: `16`
  * `.CropAlignX`: `0`
  * `.CropAlignY`: `0`
  * `.MinOutputSize`: `320` x `180`
  * `.MaxOutputSize`: `1920` x `1080`
  * `.OutputGranularityX`: `16`
  * `.OutputGranularityY`: `9`
  * `.StretchTapsX`: `0`
  * `.StretchTapsY`: `0`
  * `.ShrinkTapsX`: `0`
  * `.ShrinkTapsY`: `0`
  * `.MinFrameInterval`: `33 3333`
  * `.MaxFrameInterval`: `1 000 0000`
  * `.MinBitsPerSecond`: `921,600`
  * `.MaxBitsPerSecond`: `995,328,000`

#### Capability: 5

 * `AM_MEDIA_TYPE`:
  * Data: `76 69 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 59 55 59 32 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 00 00 00 D2 0F 00 80 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 00 00 58 00 00 00 C0 F9 EB 02`
  * Format Data: `00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 20 A1 07 00 00 00 00 00 28 00 00 00 C0 03 00 00 1C 02 00 00 01 00 10 00 59 55 59 32 00 D2 0F 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00`
  * `.subtype`: `FourCC YUY2`
  * `.bFixedSizeSamples`: `1`
  * `.bTemporalCompression`: `0`
  * `.lSampleSize`: `1,036,800`
  * `.cbFormat`: `88`
  * `VIDEOINFOHEADER`:
  * `.rcSource`: (`0`, `0`) - (`0`, `0`)
  * `.rcTarget`: (`0`, `0`) - (`0`, `0`)
  * `.dwBitRate`: `0`
  * `.dwBitErrorRate`: `0`
  * `.AvgTimePerFrame`: `50 0000`
  * `BITMAPINFOHEADER`:
   * `.biSize`: `40`
   * `.biWidth`: `960`
   * `.biHeight`: `540`
   * `.biPlanes`: `1`
   * `.biBitCount`: `16`
   * `.biCompression`: `844715353` `YUY2`
   * `.biSizeImage`: `1,036,800`
 * `VIDEO_STREAM_CONFIG_CAPS`:
  * Data: `80 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 00 00 00 04 00 00 00 03 00 00 40 01 00 00 B4 00 00 00 80 07 00 00 38 04 00 00 10 00 00 00 09 00 00 00 00 00 00 00 00 00 00 00 40 01 00 00 B4 00 00 00 80 07 00 00 38 04 00 00 10 00 00 00 09 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 F2 01 00 00 15 16 05 00 00 00 00 00 80 96 98 00 00 00 00 00 00 10 0E 00 00 80 53 3B`
  * `.guid`: `{05589F80-C356-11CE-BF01-00AA0055595A}`
  * `.VideoStandard`: `0`
  * `.InputSize`: `1024` x `768`
  * `.MinCroppingSize`: `320` x `180`
  * `.MaxCroppingSize`: `1920` x `1080`
  * `.CropGranularityX`: `16`
  * `.CropAlignX`: `0`
  * `.CropAlignY`: `0`
  * `.MinOutputSize`: `320` x `180`
  * `.MaxOutputSize`: `1920` x `1080`
  * `.OutputGranularityX`: `16`
  * `.OutputGranularityY`: `9`
  * `.StretchTapsX`: `0`
  * `.StretchTapsY`: `0`
  * `.ShrinkTapsX`: `0`
  * `.ShrinkTapsY`: `0`
  * `.MinFrameInterval`: `33 3333`
  * `.MaxFrameInterval`: `1 000 0000`
  * `.MinBitsPerSecond`: `921,600`
  * `.MaxBitsPerSecond`: `995,328,000`

#### Capability: 6

 * `AM_MEDIA_TYPE`:
  * Data: `76 69 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 59 55 59 32 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 00 00 80 88 15 00 80 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 00 00 58 00 00 00 C0 F9 EB 02`
  * Format Data: `00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 20 A1 07 00 00 00 00 00 28 00 00 00 60 04 00 00 76 02 00 00 01 00 10 00 59 55 59 32 80 88 15 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00`
  * `.subtype`: `FourCC YUY2`
  * `.bFixedSizeSamples`: `1`
  * `.bTemporalCompression`: `0`
  * `.lSampleSize`: `1,411,200`
  * `.cbFormat`: `88`
  * `VIDEOINFOHEADER`:
  * `.rcSource`: (`0`, `0`) - (`0`, `0`)
  * `.rcTarget`: (`0`, `0`) - (`0`, `0`)
  * `.dwBitRate`: `0`
  * `.dwBitErrorRate`: `0`
  * `.AvgTimePerFrame`: `50 0000`
  * `BITMAPINFOHEADER`:
   * `.biSize`: `40`
   * `.biWidth`: `1120`
   * `.biHeight`: `630`
   * `.biPlanes`: `1`
   * `.biBitCount`: `16`
   * `.biCompression`: `844715353` `YUY2`
   * `.biSizeImage`: `1,411,200`
 * `VIDEO_STREAM_CONFIG_CAPS`:
  * Data: `80 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 00 00 00 04 00 00 00 03 00 00 40 01 00 00 B4 00 00 00 80 07 00 00 38 04 00 00 10 00 00 00 09 00 00 00 00 00 00 00 00 00 00 00 40 01 00 00 B4 00 00 00 80 07 00 00 38 04 00 00 10 00 00 00 09 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 F2 01 00 00 15 16 05 00 00 00 00 00 80 96 98 00 00 00 00 00 00 10 0E 00 00 80 53 3B`
  * `.guid`: `{05589F80-C356-11CE-BF01-00AA0055595A}`
  * `.VideoStandard`: `0`
  * `.InputSize`: `1024` x `768`
  * `.MinCroppingSize`: `320` x `180`
  * `.MaxCroppingSize`: `1920` x `1080`
  * `.CropGranularityX`: `16`
  * `.CropAlignX`: `0`
  * `.CropAlignY`: `0`
  * `.MinOutputSize`: `320` x `180`
  * `.MaxOutputSize`: `1920` x `1080`
  * `.OutputGranularityX`: `16`
  * `.OutputGranularityY`: `9`
  * `.StretchTapsX`: `0`
  * `.StretchTapsY`: `0`
  * `.ShrinkTapsX`: `0`
  * `.ShrinkTapsY`: `0`
  * `.MinFrameInterval`: `33 3333`
  * `.MaxFrameInterval`: `1 000 0000`
  * `.MinBitsPerSecond`: `921,600`
  * `.MaxBitsPerSecond`: `995,328,000`

#### Capability: 7

 * `AM_MEDIA_TYPE`:
  * Data: `76 69 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 59 55 59 32 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 00 00 00 20 1C 00 80 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 00 00 58 00 00 00 C0 F9 EB 02`
  * Format Data: `00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 20 A1 07 00 00 00 00 00 28 00 00 00 00 05 00 00 D0 02 00 00 01 00 10 00 59 55 59 32 00 20 1C 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00`
  * `.subtype`: `FourCC YUY2`
  * `.bFixedSizeSamples`: `1`
  * `.bTemporalCompression`: `0`
  * `.lSampleSize`: `1,843,200`
  * `.cbFormat`: `88`
  * `VIDEOINFOHEADER`:
  * `.rcSource`: (`0`, `0`) - (`0`, `0`)
  * `.rcTarget`: (`0`, `0`) - (`0`, `0`)
  * `.dwBitRate`: `0`
  * `.dwBitErrorRate`: `0`
  * `.AvgTimePerFrame`: `50 0000`
  * `BITMAPINFOHEADER`:
   * `.biSize`: `40`
   * `.biWidth`: `1280`
   * `.biHeight`: `720`
   * `.biPlanes`: `1`
   * `.biBitCount`: `16`
   * `.biCompression`: `844715353` `YUY2`
   * `.biSizeImage`: `1,843,200`
 * `VIDEO_STREAM_CONFIG_CAPS`:
  * Data: `80 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 00 00 00 04 00 00 00 03 00 00 40 01 00 00 B4 00 00 00 80 07 00 00 38 04 00 00 10 00 00 00 09 00 00 00 00 00 00 00 00 00 00 00 40 01 00 00 B4 00 00 00 80 07 00 00 38 04 00 00 10 00 00 00 09 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 F2 01 00 00 15 16 05 00 00 00 00 00 80 96 98 00 00 00 00 00 00 10 0E 00 00 80 53 3B`
  * `.guid`: `{05589F80-C356-11CE-BF01-00AA0055595A}`
  * `.VideoStandard`: `0`
  * `.InputSize`: `1024` x `768`
  * `.MinCroppingSize`: `320` x `180`
  * `.MaxCroppingSize`: `1920` x `1080`
  * `.CropGranularityX`: `16`
  * `.CropAlignX`: `0`
  * `.CropAlignY`: `0`
  * `.MinOutputSize`: `320` x `180`
  * `.MaxOutputSize`: `1920` x `1080`
  * `.OutputGranularityX`: `16`
  * `.OutputGranularityY`: `9`
  * `.StretchTapsX`: `0`
  * `.StretchTapsY`: `0`
  * `.ShrinkTapsX`: `0`
  * `.ShrinkTapsY`: `0`
  * `.MinFrameInterval`: `33 3333`
  * `.MaxFrameInterval`: `1 000 0000`
  * `.MinBitsPerSecond`: `921,600`
  * `.MaxBitsPerSecond`: `995,328,000`

#### Capability: 8

 * `AM_MEDIA_TYPE`:
  * Data: `76 69 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 59 55 59 32 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 00 00 80 98 23 00 80 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 00 00 58 00 00 00 C0 F9 EB 02`
  * Format Data: `00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 20 A1 07 00 00 00 00 00 28 00 00 00 A0 05 00 00 2A 03 00 00 01 00 10 00 59 55 59 32 80 98 23 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00`
  * `.subtype`: `FourCC YUY2`
  * `.bFixedSizeSamples`: `1`
  * `.bTemporalCompression`: `0`
  * `.lSampleSize`: `2,332,800`
  * `.cbFormat`: `88`
  * `VIDEOINFOHEADER`:
  * `.rcSource`: (`0`, `0`) - (`0`, `0`)
  * `.rcTarget`: (`0`, `0`) - (`0`, `0`)
  * `.dwBitRate`: `0`
  * `.dwBitErrorRate`: `0`
  * `.AvgTimePerFrame`: `50 0000`
  * `BITMAPINFOHEADER`:
   * `.biSize`: `40`
   * `.biWidth`: `1440`
   * `.biHeight`: `810`
   * `.biPlanes`: `1`
   * `.biBitCount`: `16`
   * `.biCompression`: `844715353` `YUY2`
   * `.biSizeImage`: `2,332,800`
 * `VIDEO_STREAM_CONFIG_CAPS`:
  * Data: `80 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 00 00 00 04 00 00 00 03 00 00 40 01 00 00 B4 00 00 00 80 07 00 00 38 04 00 00 10 00 00 00 09 00 00 00 00 00 00 00 00 00 00 00 40 01 00 00 B4 00 00 00 80 07 00 00 38 04 00 00 10 00 00 00 09 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 F2 01 00 00 15 16 05 00 00 00 00 00 80 96 98 00 00 00 00 00 00 10 0E 00 00 80 53 3B`
  * `.guid`: `{05589F80-C356-11CE-BF01-00AA0055595A}`
  * `.VideoStandard`: `0`
  * `.InputSize`: `1024` x `768`
  * `.MinCroppingSize`: `320` x `180`
  * `.MaxCroppingSize`: `1920` x `1080`
  * `.CropGranularityX`: `16`
  * `.CropAlignX`: `0`
  * `.CropAlignY`: `0`
  * `.MinOutputSize`: `320` x `180`
  * `.MaxOutputSize`: `1920` x `1080`
  * `.OutputGranularityX`: `16`
  * `.OutputGranularityY`: `9`
  * `.StretchTapsX`: `0`
  * `.StretchTapsY`: `0`
  * `.ShrinkTapsX`: `0`
  * `.ShrinkTapsY`: `0`
  * `.MinFrameInterval`: `33 3333`
  * `.MaxFrameInterval`: `1 000 0000`
  * `.MinBitsPerSecond`: `921,600`
  * `.MaxBitsPerSecond`: `995,328,000`

#### Capability: 9

 * `AM_MEDIA_TYPE`:
  * Data: `76 69 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 59 55 59 32 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 00 00 00 F2 2B 00 80 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 00 00 58 00 00 00 C0 F9 EB 02`
  * Format Data: `00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 20 A1 07 00 00 00 00 00 28 00 00 00 40 06 00 00 84 03 00 00 01 00 10 00 59 55 59 32 00 F2 2B 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00`
  * `.subtype`: `FourCC YUY2`
  * `.bFixedSizeSamples`: `1`
  * `.bTemporalCompression`: `0`
  * `.lSampleSize`: `2,880,000`
  * `.cbFormat`: `88`
  * `VIDEOINFOHEADER`:
  * `.rcSource`: (`0`, `0`) - (`0`, `0`)
  * `.rcTarget`: (`0`, `0`) - (`0`, `0`)
  * `.dwBitRate`: `0`
  * `.dwBitErrorRate`: `0`
  * `.AvgTimePerFrame`: `50 0000`
  * `BITMAPINFOHEADER`:
   * `.biSize`: `40`
   * `.biWidth`: `1600`
   * `.biHeight`: `900`
   * `.biPlanes`: `1`
   * `.biBitCount`: `16`
   * `.biCompression`: `844715353` `YUY2`
   * `.biSizeImage`: `2,880,000`
 * `VIDEO_STREAM_CONFIG_CAPS`:
  * Data: `80 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 00 00 00 04 00 00 00 03 00 00 40 01 00 00 B4 00 00 00 80 07 00 00 38 04 00 00 10 00 00 00 09 00 00 00 00 00 00 00 00 00 00 00 40 01 00 00 B4 00 00 00 80 07 00 00 38 04 00 00 10 00 00 00 09 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 F2 01 00 00 15 16 05 00 00 00 00 00 80 96 98 00 00 00 00 00 00 10 0E 00 00 80 53 3B`
  * `.guid`: `{05589F80-C356-11CE-BF01-00AA0055595A}`
  * `.VideoStandard`: `0`
  * `.InputSize`: `1024` x `768`
  * `.MinCroppingSize`: `320` x `180`
  * `.MaxCroppingSize`: `1920` x `1080`
  * `.CropGranularityX`: `16`
  * `.CropAlignX`: `0`
  * `.CropAlignY`: `0`
  * `.MinOutputSize`: `320` x `180`
  * `.MaxOutputSize`: `1920` x `1080`
  * `.OutputGranularityX`: `16`
  * `.OutputGranularityY`: `9`
  * `.StretchTapsX`: `0`
  * `.StretchTapsY`: `0`
  * `.ShrinkTapsX`: `0`
  * `.ShrinkTapsY`: `0`
  * `.MinFrameInterval`: `33 3333`
  * `.MaxFrameInterval`: `1 000 0000`
  * `.MinBitsPerSecond`: `921,600`
  * `.MaxBitsPerSecond`: `995,328,000`

#### Capability: 10

 * `AM_MEDIA_TYPE`:
  * Data: `76 69 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 59 55 59 32 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 00 00 80 2C 35 00 80 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 00 00 58 00 00 00 C0 F9 EB 02`
  * Format Data: `00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 20 A1 07 00 00 00 00 00 28 00 00 00 E0 06 00 00 DE 03 00 00 01 00 10 00 59 55 59 32 80 2C 35 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00`
  * `.subtype`: `FourCC YUY2`
  * `.bFixedSizeSamples`: `1`
  * `.bTemporalCompression`: `0`
  * `.lSampleSize`: `3,484,800`
  * `.cbFormat`: `88`
  * `VIDEOINFOHEADER`:
  * `.rcSource`: (`0`, `0`) - (`0`, `0`)
  * `.rcTarget`: (`0`, `0`) - (`0`, `0`)
  * `.dwBitRate`: `0`
  * `.dwBitErrorRate`: `0`
  * `.AvgTimePerFrame`: `50 0000`
  * `BITMAPINFOHEADER`:
   * `.biSize`: `40`
   * `.biWidth`: `1760`
   * `.biHeight`: `990`
   * `.biPlanes`: `1`
   * `.biBitCount`: `16`
   * `.biCompression`: `844715353` `YUY2`
   * `.biSizeImage`: `3,484,800`
 * `VIDEO_STREAM_CONFIG_CAPS`:
  * Data: `80 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 00 00 00 04 00 00 00 03 00 00 40 01 00 00 B4 00 00 00 80 07 00 00 38 04 00 00 10 00 00 00 09 00 00 00 00 00 00 00 00 00 00 00 40 01 00 00 B4 00 00 00 80 07 00 00 38 04 00 00 10 00 00 00 09 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 F2 01 00 00 15 16 05 00 00 00 00 00 80 96 98 00 00 00 00 00 00 10 0E 00 00 80 53 3B`
  * `.guid`: `{05589F80-C356-11CE-BF01-00AA0055595A}`
  * `.VideoStandard`: `0`
  * `.InputSize`: `1024` x `768`
  * `.MinCroppingSize`: `320` x `180`
  * `.MaxCroppingSize`: `1920` x `1080`
  * `.CropGranularityX`: `16`
  * `.CropAlignX`: `0`
  * `.CropAlignY`: `0`
  * `.MinOutputSize`: `320` x `180`
  * `.MaxOutputSize`: `1920` x `1080`
  * `.OutputGranularityX`: `16`
  * `.OutputGranularityY`: `9`
  * `.StretchTapsX`: `0`
  * `.StretchTapsY`: `0`
  * `.ShrinkTapsX`: `0`
  * `.ShrinkTapsY`: `0`
  * `.MinFrameInterval`: `33 3333`
  * `.MaxFrameInterval`: `1 000 0000`
  * `.MinBitsPerSecond`: `921,600`
  * `.MaxBitsPerSecond`: `995,328,000`

#### Capability: 11

 * `AM_MEDIA_TYPE`:
  * Data: `76 69 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 59 55 59 32 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 00 00 00 48 3F 00 80 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 00 00 58 00 00 00 C0 F9 EB 02`
  * Format Data: `00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 20 A1 07 00 00 00 00 00 28 00 00 00 80 07 00 00 38 04 00 00 01 00 10 00 59 55 59 32 00 48 3F 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00`
  * `.subtype`: `FourCC YUY2`
  * `.bFixedSizeSamples`: `1`
  * `.bTemporalCompression`: `0`
  * `.lSampleSize`: `4,147,200`
  * `.cbFormat`: `88`
  * `VIDEOINFOHEADER`:
  * `.rcSource`: (`0`, `0`) - (`0`, `0`)
  * `.rcTarget`: (`0`, `0`) - (`0`, `0`)
  * `.dwBitRate`: `0`
  * `.dwBitErrorRate`: `0`
  * `.AvgTimePerFrame`: `50 0000`
  * `BITMAPINFOHEADER`:
   * `.biSize`: `40`
   * `.biWidth`: `1920`
   * `.biHeight`: `1080`
   * `.biPlanes`: `1`
   * `.biBitCount`: `16`
   * `.biCompression`: `844715353` `YUY2`
   * `.biSizeImage`: `4,147,200`
 * `VIDEO_STREAM_CONFIG_CAPS`:
  * Data: `80 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 00 00 00 04 00 00 00 03 00 00 40 01 00 00 F0 00 00 00 80 07 00 00 A0 05 00 00 10 00 00 00 0C 00 00 00 00 00 00 00 00 00 00 00 40 01 00 00 F0 00 00 00 80 07 00 00 A0 05 00 00 10 00 00 00 0C 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 F2 01 00 00 15 16 05 00 00 00 00 00 80 96 98 00 00 00 00 00 00 C0 12 00 00 00 1A 4F`
  * `.guid`: `{05589F80-C356-11CE-BF01-00AA0055595A}`
  * `.VideoStandard`: `0`
  * `.InputSize`: `1024` x `768`
  * `.MinCroppingSize`: `320` x `240`
  * `.MaxCroppingSize`: `1920` x `1440`
  * `.CropGranularityX`: `16`
  * `.CropAlignX`: `0`
  * `.CropAlignY`: `0`
  * `.MinOutputSize`: `320` x `240`
  * `.MaxOutputSize`: `1920` x `1440`
  * `.OutputGranularityX`: `16`
  * `.OutputGranularityY`: `12`
  * `.StretchTapsX`: `0`
  * `.StretchTapsY`: `0`
  * `.ShrinkTapsX`: `0`
  * `.ShrinkTapsY`: `0`
  * `.MinFrameInterval`: `33 3333`
  * `.MaxFrameInterval`: `1 000 0000`
  * `.MinBitsPerSecond`: `1,228,800`
  * `.MaxBitsPerSecond`: `1,327,104,000`

#### Capability: 12

 * `AM_MEDIA_TYPE`:
  * Data: `76 69 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 59 55 59 32 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 00 00 00 58 02 00 80 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 00 00 58 00 00 00 C0 F9 EB 02`
  * Format Data: `00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 20 A1 07 00 00 00 00 00 28 00 00 00 40 01 00 00 F0 00 00 00 01 00 10 00 59 55 59 32 00 58 02 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00`
  * `.subtype`: `FourCC YUY2`
  * `.bFixedSizeSamples`: `1`
  * `.bTemporalCompression`: `0`
  * `.lSampleSize`: `153,600`
  * `.cbFormat`: `88`
  * `VIDEOINFOHEADER`:
  * `.rcSource`: (`0`, `0`) - (`0`, `0`)
  * `.rcTarget`: (`0`, `0`) - (`0`, `0`)
  * `.dwBitRate`: `0`
  * `.dwBitErrorRate`: `0`
  * `.AvgTimePerFrame`: `50 0000`
  * `BITMAPINFOHEADER`:
   * `.biSize`: `40`
   * `.biWidth`: `320`
   * `.biHeight`: `240`
   * `.biPlanes`: `1`
   * `.biBitCount`: `16`
   * `.biCompression`: `844715353` `YUY2`
   * `.biSizeImage`: `153,600`
 * `VIDEO_STREAM_CONFIG_CAPS`:
  * Data: `80 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 00 00 00 04 00 00 00 03 00 00 40 01 00 00 F0 00 00 00 80 07 00 00 A0 05 00 00 10 00 00 00 0C 00 00 00 00 00 00 00 00 00 00 00 40 01 00 00 F0 00 00 00 80 07 00 00 A0 05 00 00 10 00 00 00 0C 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 F2 01 00 00 15 16 05 00 00 00 00 00 80 96 98 00 00 00 00 00 00 C0 12 00 00 00 1A 4F`
  * `.guid`: `{05589F80-C356-11CE-BF01-00AA0055595A}`
  * `.VideoStandard`: `0`
  * `.InputSize`: `1024` x `768`
  * `.MinCroppingSize`: `320` x `240`
  * `.MaxCroppingSize`: `1920` x `1440`
  * `.CropGranularityX`: `16`
  * `.CropAlignX`: `0`
  * `.CropAlignY`: `0`
  * `.MinOutputSize`: `320` x `240`
  * `.MaxOutputSize`: `1920` x `1440`
  * `.OutputGranularityX`: `16`
  * `.OutputGranularityY`: `12`
  * `.StretchTapsX`: `0`
  * `.StretchTapsY`: `0`
  * `.ShrinkTapsX`: `0`
  * `.ShrinkTapsY`: `0`
  * `.MinFrameInterval`: `33 3333`
  * `.MaxFrameInterval`: `1 000 0000`
  * `.MinBitsPerSecond`: `1,228,800`
  * `.MaxBitsPerSecond`: `1,327,104,000`

#### Capability: 13

 * `AM_MEDIA_TYPE`:
  * Data: `76 69 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 59 55 59 32 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 00 00 00 46 05 00 80 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 00 00 58 00 00 00 C0 F9 EB 02`
  * Format Data: `00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 20 A1 07 00 00 00 00 00 28 00 00 00 E0 01 00 00 68 01 00 00 01 00 10 00 59 55 59 32 00 46 05 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00`
  * `.subtype`: `FourCC YUY2`
  * `.bFixedSizeSamples`: `1`
  * `.bTemporalCompression`: `0`
  * `.lSampleSize`: `345,600`
  * `.cbFormat`: `88`
  * `VIDEOINFOHEADER`:
  * `.rcSource`: (`0`, `0`) - (`0`, `0`)
  * `.rcTarget`: (`0`, `0`) - (`0`, `0`)
  * `.dwBitRate`: `0`
  * `.dwBitErrorRate`: `0`
  * `.AvgTimePerFrame`: `50 0000`
  * `BITMAPINFOHEADER`:
   * `.biSize`: `40`
   * `.biWidth`: `480`
   * `.biHeight`: `360`
   * `.biPlanes`: `1`
   * `.biBitCount`: `16`
   * `.biCompression`: `844715353` `YUY2`
   * `.biSizeImage`: `345,600`
 * `VIDEO_STREAM_CONFIG_CAPS`:
  * Data: `80 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 00 00 00 04 00 00 00 03 00 00 40 01 00 00 F0 00 00 00 80 07 00 00 A0 05 00 00 10 00 00 00 0C 00 00 00 00 00 00 00 00 00 00 00 40 01 00 00 F0 00 00 00 80 07 00 00 A0 05 00 00 10 00 00 00 0C 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 F2 01 00 00 15 16 05 00 00 00 00 00 80 96 98 00 00 00 00 00 00 C0 12 00 00 00 1A 4F`
  * `.guid`: `{05589F80-C356-11CE-BF01-00AA0055595A}`
  * `.VideoStandard`: `0`
  * `.InputSize`: `1024` x `768`
  * `.MinCroppingSize`: `320` x `240`
  * `.MaxCroppingSize`: `1920` x `1440`
  * `.CropGranularityX`: `16`
  * `.CropAlignX`: `0`
  * `.CropAlignY`: `0`
  * `.MinOutputSize`: `320` x `240`
  * `.MaxOutputSize`: `1920` x `1440`
  * `.OutputGranularityX`: `16`
  * `.OutputGranularityY`: `12`
  * `.StretchTapsX`: `0`
  * `.StretchTapsY`: `0`
  * `.ShrinkTapsX`: `0`
  * `.ShrinkTapsY`: `0`
  * `.MinFrameInterval`: `33 3333`
  * `.MaxFrameInterval`: `1 000 0000`
  * `.MinBitsPerSecond`: `1,228,800`
  * `.MaxBitsPerSecond`: `1,327,104,000`

#### Capability: 14

 * `AM_MEDIA_TYPE`:
  * Data: `76 69 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 59 55 59 32 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 00 00 00 60 09 00 80 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 00 00 58 00 00 00 C0 F9 EB 02`
  * Format Data: `00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 20 A1 07 00 00 00 00 00 28 00 00 00 80 02 00 00 E0 01 00 00 01 00 10 00 59 55 59 32 00 60 09 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00`
  * `.subtype`: `FourCC YUY2`
  * `.bFixedSizeSamples`: `1`
  * `.bTemporalCompression`: `0`
  * `.lSampleSize`: `614,400`
  * `.cbFormat`: `88`
  * `VIDEOINFOHEADER`:
  * `.rcSource`: (`0`, `0`) - (`0`, `0`)
  * `.rcTarget`: (`0`, `0`) - (`0`, `0`)
  * `.dwBitRate`: `0`
  * `.dwBitErrorRate`: `0`
  * `.AvgTimePerFrame`: `50 0000`
  * `BITMAPINFOHEADER`:
   * `.biSize`: `40`
   * `.biWidth`: `640`
   * `.biHeight`: `480`
   * `.biPlanes`: `1`
   * `.biBitCount`: `16`
   * `.biCompression`: `844715353` `YUY2`
   * `.biSizeImage`: `614,400`
 * `VIDEO_STREAM_CONFIG_CAPS`:
  * Data: `80 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 00 00 00 04 00 00 00 03 00 00 40 01 00 00 F0 00 00 00 80 07 00 00 A0 05 00 00 10 00 00 00 0C 00 00 00 00 00 00 00 00 00 00 00 40 01 00 00 F0 00 00 00 80 07 00 00 A0 05 00 00 10 00 00 00 0C 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 F2 01 00 00 15 16 05 00 00 00 00 00 80 96 98 00 00 00 00 00 00 C0 12 00 00 00 1A 4F`
  * `.guid`: `{05589F80-C356-11CE-BF01-00AA0055595A}`
  * `.VideoStandard`: `0`
  * `.InputSize`: `1024` x `768`
  * `.MinCroppingSize`: `320` x `240`
  * `.MaxCroppingSize`: `1920` x `1440`
  * `.CropGranularityX`: `16`
  * `.CropAlignX`: `0`
  * `.CropAlignY`: `0`
  * `.MinOutputSize`: `320` x `240`
  * `.MaxOutputSize`: `1920` x `1440`
  * `.OutputGranularityX`: `16`
  * `.OutputGranularityY`: `12`
  * `.StretchTapsX`: `0`
  * `.StretchTapsY`: `0`
  * `.ShrinkTapsX`: `0`
  * `.ShrinkTapsY`: `0`
  * `.MinFrameInterval`: `33 3333`
  * `.MaxFrameInterval`: `1 000 0000`
  * `.MinBitsPerSecond`: `1,228,800`
  * `.MaxBitsPerSecond`: `1,327,104,000`

#### Capability: 15

 * `AM_MEDIA_TYPE`:
  * Data: `76 69 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 59 55 59 32 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 00 00 00 A6 0E 00 80 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 00 00 58 00 00 00 C0 F9 EB 02`
  * Format Data: `00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 20 A1 07 00 00 00 00 00 28 00 00 00 20 03 00 00 58 02 00 00 01 00 10 00 59 55 59 32 00 A6 0E 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00`
  * `.subtype`: `FourCC YUY2`
  * `.bFixedSizeSamples`: `1`
  * `.bTemporalCompression`: `0`
  * `.lSampleSize`: `960,000`
  * `.cbFormat`: `88`
  * `VIDEOINFOHEADER`:
  * `.rcSource`: (`0`, `0`) - (`0`, `0`)
  * `.rcTarget`: (`0`, `0`) - (`0`, `0`)
  * `.dwBitRate`: `0`
  * `.dwBitErrorRate`: `0`
  * `.AvgTimePerFrame`: `50 0000`
  * `BITMAPINFOHEADER`:
   * `.biSize`: `40`
   * `.biWidth`: `800`
   * `.biHeight`: `600`
   * `.biPlanes`: `1`
   * `.biBitCount`: `16`
   * `.biCompression`: `844715353` `YUY2`
   * `.biSizeImage`: `960,000`
 * `VIDEO_STREAM_CONFIG_CAPS`:
  * Data: `80 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 00 00 00 04 00 00 00 03 00 00 40 01 00 00 F0 00 00 00 80 07 00 00 A0 05 00 00 10 00 00 00 0C 00 00 00 00 00 00 00 00 00 00 00 40 01 00 00 F0 00 00 00 80 07 00 00 A0 05 00 00 10 00 00 00 0C 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 F2 01 00 00 15 16 05 00 00 00 00 00 80 96 98 00 00 00 00 00 00 C0 12 00 00 00 1A 4F`
  * `.guid`: `{05589F80-C356-11CE-BF01-00AA0055595A}`
  * `.VideoStandard`: `0`
  * `.InputSize`: `1024` x `768`
  * `.MinCroppingSize`: `320` x `240`
  * `.MaxCroppingSize`: `1920` x `1440`
  * `.CropGranularityX`: `16`
  * `.CropAlignX`: `0`
  * `.CropAlignY`: `0`
  * `.MinOutputSize`: `320` x `240`
  * `.MaxOutputSize`: `1920` x `1440`
  * `.OutputGranularityX`: `16`
  * `.OutputGranularityY`: `12`
  * `.StretchTapsX`: `0`
  * `.StretchTapsY`: `0`
  * `.ShrinkTapsX`: `0`
  * `.ShrinkTapsY`: `0`
  * `.MinFrameInterval`: `33 3333`
  * `.MaxFrameInterval`: `1 000 0000`
  * `.MinBitsPerSecond`: `1,228,800`
  * `.MaxBitsPerSecond`: `1,327,104,000`

#### Capability: 16

 * `AM_MEDIA_TYPE`:
  * Data: `76 69 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 59 55 59 32 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 00 00 00 18 15 00 80 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 00 00 58 00 00 00 C0 F9 EB 02`
  * Format Data: `00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 20 A1 07 00 00 00 00 00 28 00 00 00 C0 03 00 00 D0 02 00 00 01 00 10 00 59 55 59 32 00 18 15 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00`
  * `.subtype`: `FourCC YUY2`
  * `.bFixedSizeSamples`: `1`
  * `.bTemporalCompression`: `0`
  * `.lSampleSize`: `1,382,400`
  * `.cbFormat`: `88`
  * `VIDEOINFOHEADER`:
  * `.rcSource`: (`0`, `0`) - (`0`, `0`)
  * `.rcTarget`: (`0`, `0`) - (`0`, `0`)
  * `.dwBitRate`: `0`
  * `.dwBitErrorRate`: `0`
  * `.AvgTimePerFrame`: `50 0000`
  * `BITMAPINFOHEADER`:
   * `.biSize`: `40`
   * `.biWidth`: `960`
   * `.biHeight`: `720`
   * `.biPlanes`: `1`
   * `.biBitCount`: `16`
   * `.biCompression`: `844715353` `YUY2`
   * `.biSizeImage`: `1,382,400`
 * `VIDEO_STREAM_CONFIG_CAPS`:
  * Data: `80 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 00 00 00 04 00 00 00 03 00 00 40 01 00 00 F0 00 00 00 80 07 00 00 A0 05 00 00 10 00 00 00 0C 00 00 00 00 00 00 00 00 00 00 00 40 01 00 00 F0 00 00 00 80 07 00 00 A0 05 00 00 10 00 00 00 0C 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 F2 01 00 00 15 16 05 00 00 00 00 00 80 96 98 00 00 00 00 00 00 C0 12 00 00 00 1A 4F`
  * `.guid`: `{05589F80-C356-11CE-BF01-00AA0055595A}`
  * `.VideoStandard`: `0`
  * `.InputSize`: `1024` x `768`
  * `.MinCroppingSize`: `320` x `240`
  * `.MaxCroppingSize`: `1920` x `1440`
  * `.CropGranularityX`: `16`
  * `.CropAlignX`: `0`
  * `.CropAlignY`: `0`
  * `.MinOutputSize`: `320` x `240`
  * `.MaxOutputSize`: `1920` x `1440`
  * `.OutputGranularityX`: `16`
  * `.OutputGranularityY`: `12`
  * `.StretchTapsX`: `0`
  * `.StretchTapsY`: `0`
  * `.ShrinkTapsX`: `0`
  * `.ShrinkTapsY`: `0`
  * `.MinFrameInterval`: `33 3333`
  * `.MaxFrameInterval`: `1 000 0000`
  * `.MinBitsPerSecond`: `1,228,800`
  * `.MaxBitsPerSecond`: `1,327,104,000`

#### Capability: 17

 * `AM_MEDIA_TYPE`:
  * Data: `76 69 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 59 55 59 32 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 00 00 00 B6 1C 00 80 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 00 00 58 00 00 00 C0 F9 EB 02`
  * Format Data: `00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 20 A1 07 00 00 00 00 00 28 00 00 00 60 04 00 00 48 03 00 00 01 00 10 00 59 55 59 32 00 B6 1C 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00`
  * `.subtype`: `FourCC YUY2`
  * `.bFixedSizeSamples`: `1`
  * `.bTemporalCompression`: `0`
  * `.lSampleSize`: `1,881,600`
  * `.cbFormat`: `88`
  * `VIDEOINFOHEADER`:
  * `.rcSource`: (`0`, `0`) - (`0`, `0`)
  * `.rcTarget`: (`0`, `0`) - (`0`, `0`)
  * `.dwBitRate`: `0`
  * `.dwBitErrorRate`: `0`
  * `.AvgTimePerFrame`: `50 0000`
  * `BITMAPINFOHEADER`:
   * `.biSize`: `40`
   * `.biWidth`: `1120`
   * `.biHeight`: `840`
   * `.biPlanes`: `1`
   * `.biBitCount`: `16`
   * `.biCompression`: `844715353` `YUY2`
   * `.biSizeImage`: `1,881,600`
 * `VIDEO_STREAM_CONFIG_CAPS`:
  * Data: `80 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 00 00 00 04 00 00 00 03 00 00 40 01 00 00 F0 00 00 00 80 07 00 00 A0 05 00 00 10 00 00 00 0C 00 00 00 00 00 00 00 00 00 00 00 40 01 00 00 F0 00 00 00 80 07 00 00 A0 05 00 00 10 00 00 00 0C 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 F2 01 00 00 15 16 05 00 00 00 00 00 80 96 98 00 00 00 00 00 00 C0 12 00 00 00 1A 4F`
  * `.guid`: `{05589F80-C356-11CE-BF01-00AA0055595A}`
  * `.VideoStandard`: `0`
  * `.InputSize`: `1024` x `768`
  * `.MinCroppingSize`: `320` x `240`
  * `.MaxCroppingSize`: `1920` x `1440`
  * `.CropGranularityX`: `16`
  * `.CropAlignX`: `0`
  * `.CropAlignY`: `0`
  * `.MinOutputSize`: `320` x `240`
  * `.MaxOutputSize`: `1920` x `1440`
  * `.OutputGranularityX`: `16`
  * `.OutputGranularityY`: `12`
  * `.StretchTapsX`: `0`
  * `.StretchTapsY`: `0`
  * `.ShrinkTapsX`: `0`
  * `.ShrinkTapsY`: `0`
  * `.MinFrameInterval`: `33 3333`
  * `.MaxFrameInterval`: `1 000 0000`
  * `.MinBitsPerSecond`: `1,228,800`
  * `.MaxBitsPerSecond`: `1,327,104,000`

#### Capability: 18

 * `AM_MEDIA_TYPE`:
  * Data: `76 69 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 59 55 59 32 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 00 00 00 80 25 00 80 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 00 00 58 00 00 00 C0 F9 EB 02`
  * Format Data: `00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 20 A1 07 00 00 00 00 00 28 00 00 00 00 05 00 00 C0 03 00 00 01 00 10 00 59 55 59 32 00 80 25 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00`
  * `.subtype`: `FourCC YUY2`
  * `.bFixedSizeSamples`: `1`
  * `.bTemporalCompression`: `0`
  * `.lSampleSize`: `2,457,600`
  * `.cbFormat`: `88`
  * `VIDEOINFOHEADER`:
  * `.rcSource`: (`0`, `0`) - (`0`, `0`)
  * `.rcTarget`: (`0`, `0`) - (`0`, `0`)
  * `.dwBitRate`: `0`
  * `.dwBitErrorRate`: `0`
  * `.AvgTimePerFrame`: `50 0000`
  * `BITMAPINFOHEADER`:
   * `.biSize`: `40`
   * `.biWidth`: `1280`
   * `.biHeight`: `960`
   * `.biPlanes`: `1`
   * `.biBitCount`: `16`
   * `.biCompression`: `844715353` `YUY2`
   * `.biSizeImage`: `2,457,600`
 * `VIDEO_STREAM_CONFIG_CAPS`:
  * Data: `80 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 00 00 00 04 00 00 00 03 00 00 40 01 00 00 F0 00 00 00 80 07 00 00 A0 05 00 00 10 00 00 00 0C 00 00 00 00 00 00 00 00 00 00 00 40 01 00 00 F0 00 00 00 80 07 00 00 A0 05 00 00 10 00 00 00 0C 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 F2 01 00 00 15 16 05 00 00 00 00 00 80 96 98 00 00 00 00 00 00 C0 12 00 00 00 1A 4F`
  * `.guid`: `{05589F80-C356-11CE-BF01-00AA0055595A}`
  * `.VideoStandard`: `0`
  * `.InputSize`: `1024` x `768`
  * `.MinCroppingSize`: `320` x `240`
  * `.MaxCroppingSize`: `1920` x `1440`
  * `.CropGranularityX`: `16`
  * `.CropAlignX`: `0`
  * `.CropAlignY`: `0`
  * `.MinOutputSize`: `320` x `240`
  * `.MaxOutputSize`: `1920` x `1440`
  * `.OutputGranularityX`: `16`
  * `.OutputGranularityY`: `12`
  * `.StretchTapsX`: `0`
  * `.StretchTapsY`: `0`
  * `.ShrinkTapsX`: `0`
  * `.ShrinkTapsY`: `0`
  * `.MinFrameInterval`: `33 3333`
  * `.MaxFrameInterval`: `1 000 0000`
  * `.MinBitsPerSecond`: `1,228,800`
  * `.MaxBitsPerSecond`: `1,327,104,000`

#### Capability: 19

 * `AM_MEDIA_TYPE`:
  * Data: `76 69 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 59 55 59 32 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 00 00 00 76 2F 00 80 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 00 00 58 00 00 00 C0 F9 EB 02`
  * Format Data: `00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 20 A1 07 00 00 00 00 00 28 00 00 00 A0 05 00 00 38 04 00 00 01 00 10 00 59 55 59 32 00 76 2F 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00`
  * `.subtype`: `FourCC YUY2`
  * `.bFixedSizeSamples`: `1`
  * `.bTemporalCompression`: `0`
  * `.lSampleSize`: `3,110,400`
  * `.cbFormat`: `88`
  * `VIDEOINFOHEADER`:
  * `.rcSource`: (`0`, `0`) - (`0`, `0`)
  * `.rcTarget`: (`0`, `0`) - (`0`, `0`)
  * `.dwBitRate`: `0`
  * `.dwBitErrorRate`: `0`
  * `.AvgTimePerFrame`: `50 0000`
  * `BITMAPINFOHEADER`:
   * `.biSize`: `40`
   * `.biWidth`: `1440`
   * `.biHeight`: `1080`
   * `.biPlanes`: `1`
   * `.biBitCount`: `16`
   * `.biCompression`: `844715353` `YUY2`
   * `.biSizeImage`: `3,110,400`
 * `VIDEO_STREAM_CONFIG_CAPS`:
  * Data: `80 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 00 00 00 04 00 00 00 03 00 00 40 01 00 00 F0 00 00 00 80 07 00 00 A0 05 00 00 10 00 00 00 0C 00 00 00 00 00 00 00 00 00 00 00 40 01 00 00 F0 00 00 00 80 07 00 00 A0 05 00 00 10 00 00 00 0C 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 F2 01 00 00 15 16 05 00 00 00 00 00 80 96 98 00 00 00 00 00 00 C0 12 00 00 00 1A 4F`
  * `.guid`: `{05589F80-C356-11CE-BF01-00AA0055595A}`
  * `.VideoStandard`: `0`
  * `.InputSize`: `1024` x `768`
  * `.MinCroppingSize`: `320` x `240`
  * `.MaxCroppingSize`: `1920` x `1440`
  * `.CropGranularityX`: `16`
  * `.CropAlignX`: `0`
  * `.CropAlignY`: `0`
  * `.MinOutputSize`: `320` x `240`
  * `.MaxOutputSize`: `1920` x `1440`
  * `.OutputGranularityX`: `16`
  * `.OutputGranularityY`: `12`
  * `.StretchTapsX`: `0`
  * `.StretchTapsY`: `0`
  * `.ShrinkTapsX`: `0`
  * `.ShrinkTapsY`: `0`
  * `.MinFrameInterval`: `33 3333`
  * `.MaxFrameInterval`: `1 000 0000`
  * `.MinBitsPerSecond`: `1,228,800`
  * `.MaxBitsPerSecond`: `1,327,104,000`

#### Capability: 20

 * `AM_MEDIA_TYPE`:
  * Data: `76 69 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 59 55 59 32 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 00 00 00 98 3A 00 80 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 00 00 58 00 00 00 C0 F9 EB 02`
  * Format Data: `00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 20 A1 07 00 00 00 00 00 28 00 00 00 40 06 00 00 B0 04 00 00 01 00 10 00 59 55 59 32 00 98 3A 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00`
  * `.subtype`: `FourCC YUY2`
  * `.bFixedSizeSamples`: `1`
  * `.bTemporalCompression`: `0`
  * `.lSampleSize`: `3,840,000`
  * `.cbFormat`: `88`
  * `VIDEOINFOHEADER`:
  * `.rcSource`: (`0`, `0`) - (`0`, `0`)
  * `.rcTarget`: (`0`, `0`) - (`0`, `0`)
  * `.dwBitRate`: `0`
  * `.dwBitErrorRate`: `0`
  * `.AvgTimePerFrame`: `50 0000`
  * `BITMAPINFOHEADER`:
   * `.biSize`: `40`
   * `.biWidth`: `1600`
   * `.biHeight`: `1200`
   * `.biPlanes`: `1`
   * `.biBitCount`: `16`
   * `.biCompression`: `844715353` `YUY2`
   * `.biSizeImage`: `3,840,000`
 * `VIDEO_STREAM_CONFIG_CAPS`:
  * Data: `80 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 00 00 00 04 00 00 00 03 00 00 40 01 00 00 F0 00 00 00 80 07 00 00 A0 05 00 00 10 00 00 00 0C 00 00 00 00 00 00 00 00 00 00 00 40 01 00 00 F0 00 00 00 80 07 00 00 A0 05 00 00 10 00 00 00 0C 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 F2 01 00 00 15 16 05 00 00 00 00 00 80 96 98 00 00 00 00 00 00 C0 12 00 00 00 1A 4F`
  * `.guid`: `{05589F80-C356-11CE-BF01-00AA0055595A}`
  * `.VideoStandard`: `0`
  * `.InputSize`: `1024` x `768`
  * `.MinCroppingSize`: `320` x `240`
  * `.MaxCroppingSize`: `1920` x `1440`
  * `.CropGranularityX`: `16`
  * `.CropAlignX`: `0`
  * `.CropAlignY`: `0`
  * `.MinOutputSize`: `320` x `240`
  * `.MaxOutputSize`: `1920` x `1440`
  * `.OutputGranularityX`: `16`
  * `.OutputGranularityY`: `12`
  * `.StretchTapsX`: `0`
  * `.StretchTapsY`: `0`
  * `.ShrinkTapsX`: `0`
  * `.ShrinkTapsY`: `0`
  * `.MinFrameInterval`: `33 3333`
  * `.MaxFrameInterval`: `1 000 0000`
  * `.MinBitsPerSecond`: `1,228,800`
  * `.MaxBitsPerSecond`: `1,327,104,000`

#### Capability: 21

 * `AM_MEDIA_TYPE`:
  * Data: `76 69 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 59 55 59 32 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 00 00 00 E6 46 00 80 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 00 00 58 00 00 00 C0 F9 EB 02`
  * Format Data: `00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 20 A1 07 00 00 00 00 00 28 00 00 00 E0 06 00 00 28 05 00 00 01 00 10 00 59 55 59 32 00 E6 46 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00`
  * `.subtype`: `FourCC YUY2`
  * `.bFixedSizeSamples`: `1`
  * `.bTemporalCompression`: `0`
  * `.lSampleSize`: `4,646,400`
  * `.cbFormat`: `88`
  * `VIDEOINFOHEADER`:
  * `.rcSource`: (`0`, `0`) - (`0`, `0`)
  * `.rcTarget`: (`0`, `0`) - (`0`, `0`)
  * `.dwBitRate`: `0`
  * `.dwBitErrorRate`: `0`
  * `.AvgTimePerFrame`: `50 0000`
  * `BITMAPINFOHEADER`:
   * `.biSize`: `40`
   * `.biWidth`: `1760`
   * `.biHeight`: `1320`
   * `.biPlanes`: `1`
   * `.biBitCount`: `16`
   * `.biCompression`: `844715353` `YUY2`
   * `.biSizeImage`: `4,646,400`
 * `VIDEO_STREAM_CONFIG_CAPS`:
  * Data: `80 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 00 00 00 04 00 00 00 03 00 00 40 01 00 00 F0 00 00 00 80 07 00 00 A0 05 00 00 10 00 00 00 0C 00 00 00 00 00 00 00 00 00 00 00 40 01 00 00 F0 00 00 00 80 07 00 00 A0 05 00 00 10 00 00 00 0C 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 F2 01 00 00 15 16 05 00 00 00 00 00 80 96 98 00 00 00 00 00 00 C0 12 00 00 00 1A 4F`
  * `.guid`: `{05589F80-C356-11CE-BF01-00AA0055595A}`
  * `.VideoStandard`: `0`
  * `.InputSize`: `1024` x `768`
  * `.MinCroppingSize`: `320` x `240`
  * `.MaxCroppingSize`: `1920` x `1440`
  * `.CropGranularityX`: `16`
  * `.CropAlignX`: `0`
  * `.CropAlignY`: `0`
  * `.MinOutputSize`: `320` x `240`
  * `.MaxOutputSize`: `1920` x `1440`
  * `.OutputGranularityX`: `16`
  * `.OutputGranularityY`: `12`
  * `.StretchTapsX`: `0`
  * `.StretchTapsY`: `0`
  * `.ShrinkTapsX`: `0`
  * `.ShrinkTapsY`: `0`
  * `.MinFrameInterval`: `33 3333`
  * `.MaxFrameInterval`: `1 000 0000`
  * `.MinBitsPerSecond`: `1,228,800`
  * `.MaxBitsPerSecond`: `1,327,104,000`

#### Capability: 22

 * `AM_MEDIA_TYPE`:
  * Data: `76 69 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 59 55 59 32 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 00 00 00 60 54 00 80 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 00 00 58 00 00 00 C0 F9 EB 02`
  * Format Data: `00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 20 A1 07 00 00 00 00 00 28 00 00 00 80 07 00 00 A0 05 00 00 01 00 10 00 59 55 59 32 00 60 54 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00`
  * `.subtype`: `FourCC YUY2`
  * `.bFixedSizeSamples`: `1`
  * `.bTemporalCompression`: `0`
  * `.lSampleSize`: `5,529,600`
  * `.cbFormat`: `88`
  * `VIDEOINFOHEADER`:
  * `.rcSource`: (`0`, `0`) - (`0`, `0`)
  * `.rcTarget`: (`0`, `0`) - (`0`, `0`)
  * `.dwBitRate`: `0`
  * `.dwBitErrorRate`: `0`
  * `.AvgTimePerFrame`: `50 0000`
  * `BITMAPINFOHEADER`:
   * `.biSize`: `40`
   * `.biWidth`: `1920`
   * `.biHeight`: `1440`
   * `.biPlanes`: `1`
   * `.biBitCount`: `16`
   * `.biCompression`: `844715353` `YUY2`
   * `.biSizeImage`: `5,529,600`
 * `VIDEO_STREAM_CONFIG_CAPS`:
  * Data: `80 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 00 00 00 04 00 00 00 03 00 00 40 01 00 00 F0 00 00 00 80 07 00 00 A0 05 00 00 10 00 00 00 0C 00 00 00 00 00 00 00 00 00 00 00 40 01 00 00 F0 00 00 00 80 07 00 00 A0 05 00 00 10 00 00 00 0C 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 F2 01 00 00 15 16 05 00 00 00 00 00 80 96 98 00 00 00 00 00 00 C0 12 00 00 00 1A 4F`
  * `.guid`: `{05589F80-C356-11CE-BF01-00AA0055595A}`
  * `.VideoStandard`: `0`
  * `.InputSize`: `1024` x `768`
  * `.MinCroppingSize`: `320` x `240`
  * `.MaxCroppingSize`: `1920` x `1440`
  * `.CropGranularityX`: `16`
  * `.CropAlignX`: `0`
  * `.CropAlignY`: `0`
  * `.MinOutputSize`: `320` x `240`
  * `.MaxOutputSize`: `1920` x `1440`
  * `.OutputGranularityX`: `16`
  * `.OutputGranularityY`: `12`
  * `.StretchTapsX`: `0`
  * `.StretchTapsY`: `0`
  * `.ShrinkTapsX`: `0`
  * `.ShrinkTapsY`: `0`
  * `.MinFrameInterval`: `33 3333`
  * `.MaxFrameInterval`: `1 000 0000`
  * `.MinBitsPerSecond`: `1,228,800`
  * `.MaxBitsPerSecond`: `1,327,104,000`

Capability Summary: 

 * Subtypes: FourCC YUY2
 * Resolutions: 1024x768

Interfaces:

  * `IKsPropertySet`
  * `IQualityControl`
  * `IAMBufferNegotiation`
  * `IAMStreamConfig`
  * `IAMStreamControl`

# Audio

 * VisioForge Network Streamer Audio Source
 * VisioForge Virtual Audio Card
 * VisioForge What You Hear Source

## Device: VisioForge Network Streamer Audio Source

 * Moniker Display Name: @device:sw:{33D9A762-90C8-11D0-BD43-00A0C911CE86}\VisioForge Network Streamer Audio Source

Interfaces:

  * `IAMFilterMiscFlags`

### Pin: Capture

 * `AMPROPSETID_Pin`, `AMPROPERTY_PIN_CATEGORY`: `{FB6C4281-0353-11D1-905F-0000C0CC16BA} PIN_CATEGORY_CAPTURE`
 * Capabilities:
  * Count: `0`
  * Structure Size: `52` (expected `52`)

Interfaces:

  * `IKsPropertySet`
  * `IQualityControl`
  * `IAMBufferNegotiation`
  * `IAMStreamConfig`
  * `IAMStreamControl`

## Device: VisioForge Virtual Audio Card

 * Moniker Display Name: @device:sw:{33D9A762-90C8-11D0-BD43-00A0C911CE86}\VisioForge Virtual Audio Card

Interfaces:

  * `IAMFilterMiscFlags`

### Pin: Capture

 * `AMPROPSETID_Pin`, `AMPROPERTY_PIN_CATEGORY`: `{FB6C4281-0353-11D1-905F-0000C0CC16BA} PIN_CATEGORY_CAPTURE`
 * Capabilities:
  * Count: `0`
  * Structure Size: `52` (expected `52`)

Interfaces:

  * `IKsPropertySet`
  * `IQualityControl`
  * `IAMBufferNegotiation`
  * `IAMStreamConfig`
  * `IAMStreamControl`

## Device: VisioForge What You Hear Source

 * Moniker Display Name: @device:sw:{33D9A762-90C8-11D0-BD43-00A0C911CE86}\{8C09C235-4C92-4DC0-B297-AE1CB663056B}
 * Path: C:\Program Files\VisioForge\VisioForge SDKs .Net TRIAL x64 .Net 4.0\Redist\Filters\VisioForge_WhatYouHear_Source.ax

Interfaces:

  * `IKsPropertySet`

### Pin: Capture Virtual Audio Pin

 * `AMPROPSETID_Pin`, `AMPROPERTY_PIN_CATEGORY`: `{FB6C4281-0353-11D1-905F-0000C0CC16BA} PIN_CATEGORY_CAPTURE`
 * Capabilities:
  * Count: `1`
  * Structure Size: `52` (expected `52`)

#### Capability: 0

 * `AM_MEDIA_TYPE`:
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 00 00 04 00 00 00 81 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 00 00 12 00 00 00 F0 73 EC 02`
  * Format Data: `01 00 02 00 44 AC 00 00 10 B1 02 00 04 00 10 00 00 00`
  * `.subtype`: `FourCC 0x00000001`
  * `.bFixedSizeSamples`: `1`
  * `.bTemporalCompression`: `0`
  * `.lSampleSize`: `4`
  * `.cbFormat`: `18`
  * `WAVEFORMATEX`:
   * `.wFormatTag`: `1`
   * `.nChannels`: `2`
   * `.nSamplesPerSec`: `44100`
   * `.nAvgBytesPerSec: `176400`
   * `.nBlockAlign`: `4`
   * `.wBitsPerSample`: `16`
   * `.cbSize`: `0`
 * `AUDIO_STREAM_CONFIG_CAPS`:
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 02 00 00 00 02 00 00 00 01 00 00 00 10 00 00 00 10 00 00 00 10 00 00 00 44 AC 00 00 44 AC 00 00 11 2B 00 00`
  * `.MinimumChannels`: `2`
  * `.MaximumChannels`: `2`
  * `.ChannelsGranularity`: `1`
  * `.MinimumBitsPerSample`: `16`
  * `.MaximumBitsPerSample`: `16`
  * `.BitsPerSampleGranularity`: `16`
  * `.MinimumSampleFrequency`: `44100`
  * `.MaximumSampleFrequency`: `44100`
  * `.SampleFrequencyGranularity`: `11025`

Interfaces:

  * `IKsPropertySet`
  * `IQualityControl`
  * `IAMBufferNegotiation`
  * `IAMStreamConfig`

