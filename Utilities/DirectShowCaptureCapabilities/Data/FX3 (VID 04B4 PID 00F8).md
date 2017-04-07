

# System

 * Version: 10.0.14393, Windows 10, VER_SUITE_SINGLEUSERTS, VER_NT_WORKSTATION
 * Product: PRODUCT_PROFESSIONAL
 * Computer Name: `SCLEMENTS8.`
 * User Name: `HQ\s.clements` 
 * Locale: System `en-GB`, User `en-GB`
 * Local Time: `07/04/2017 15:07:42`
 * Architecture: AMD/Intel x64 (x64 Application)
 * Processors: `8`, Active Mask `0xFF`
 * Page Size: `0x1000`
 * Application Address Space: `0x0000000000010000`..`0x00007FFFFFFEFFFF`
 * CPU: `GenuineIntel`, 0x1 EDX `0xBFEBFBFF` (MMX, SSE, SSE2), 0x1 ECX `0x7FFAFBFF` (SSE3, SSSE3, SSE41, SSE42, AVX), 0x7 EBX `0x000027AB` (AVX2), Brand `Intel(R) Core(TM) i7-4770 CPU @ 3.40GHz`
 * Physical Memory: `8,097` MB
 * Committed Memory Limit: `9,377` MB
 * Application Version: `1.0.0.548`

# Devices

## `GUID_DEVCLASS_IMAGE`

 * USB Video Device
  * Instance: USB\VID_04B4&PID_00F8&MI_00\8&3A26599F&0&0000
  * DEVPKEY_Device_Manufacturer: Microsoft
  * DEVPKEY_Device_DriverVersion: 10.0.14393.82

## `GUID_DEVCLASS_MEDIA`

 * Realtek High Definition Audio
  * Instance: HDAUDIO\FUNC_01&VEN_10EC&DEV_0280&SUBSYS_102805A4&REV_1000\4&A201051&0&0001
  * DEVPKEY_Device_Manufacturer: Realtek
  * DEVPKEY_Device_DriverVersion: 6.0.1.6086
 * Microsoft Streaming Quality Manager Proxy
  * Instance: SW\{DDF4358E-BB2C-11D0-A42F-00A0C9223196}\{97EBAACB-95BD-11D0-A3EA-00A0C9223196}
  * DEVPKEY_Device_Manufacturer: Microsoft
  * DEVPKEY_Device_DriverVersion: 10.0.14393.0
 * Microsoft Streaming Clock Proxy
  * Instance: SW\{97EBAACC-95BD-11D0-A3EA-00A0C9223196}\{53172480-4791-11D0-A5D6-28DB04C10000}
  * DEVPKEY_Device_Manufacturer: Microsoft
  * DEVPKEY_Device_DriverVersion: 10.0.14393.0

# API

Version information (file version):

 * quartz.dll: Product 10.0.14393.953, File 10.0.14393.953
 * mfcore.dll: Product 10.0.14393.953, File 10.0.14393.953
 * mfplat.dll: Product 10.0.14393.953, File 10.0.14393.953
 * fsclient.dll: Product 10.0.14393.447, File 10.0.14393.447
 * frameserver.dll: Product 10.0.14393.953, File 10.0.14393.953

# Video

 * FX3

## Device: FX3

 * Moniker Display Name: @device:pnp:\\?\usb#vid_04b4&pid_00f8&mi_00#8&3a26599f&0&0000#{65e8773d-8f56-11d0-a3b9-00a0c9223196}\global

Interfaces:

  * `ISpecifyPropertyPages`
  * `IKsPropertySet`
  * `IAMCameraControl`
  * `IAMDeviceRemoval`
  * `IAMDroppedFrames`
  * `IAMFilterMiscFlags`
  * `IAMVideoControl`
  * `IAMVideoProcAmp`

Property Pages:

  * `{71F96464-78F3-11D0-A18C-00A0C9118956}` - `CLSID_VideoProcAmpPropertyPage`, VideoProcAmp Property Page
  * `{71F96465-78F3-11D0-A18C-00A0C9118956}` - `CLSID_CameraControlPropertyPage`, CameraControl Property Page

### IAMVideoProcAmp

 * `VideoProcAmp_Brightness`: 55, flags VideoProcAmp_Flags_Manual, 0..255, step 1, default 55, cap flags VideoProcAmp_Flags_Manual

### IAMCameraControl


### Pin: Capture

 * `AMPROPSETID_Pin`, `AMPROPERTY_PIN_CATEGORY`: `{FB6C4281-0353-11D1-905F-0000C0CC16BA} PIN_CATEGORY_CAPTURE`
 * Capabilities:
  * Count: `2`
  * Structure Size: `128` (expected `128`)

#### Capability: 0

 * `AM_MEDIA_TYPE`:
  * Data: `76 69 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 59 55 59 32 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 00 00 00 80 0D 00 80 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 00 00 00 00 00 00 00 00 00 00 58 00 00 00 00 00 00 00 10 98 79 E5 08 02 00 00`
  * Format Data: `00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 CC 03 00 00 00 00 47 F4 10 00 00 00 00 00 28 00 00 00 00 03 00 00 40 02 00 00 01 00 10 00 59 55 59 32 00 80 0D 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00`
  * `.subtype`: `FourCC YUY2`
  * `.bFixedSizeSamples`: `1`
  * `.bTemporalCompression`: `0`
  * `.lSampleSize`: `884,736`
  * `.cbFormat`: `88`
  * `VIDEOINFOHEADER`:
  * `.rcSource`: (`0`, `0`) - (`0`, `0`)
  * `.rcTarget`: (`0`, `0`) - (`0`, `0`)
  * `.dwBitRate`: `63700992`
  * `.dwBitErrorRate`: `0`
  * `.AvgTimePerFrame`: `111 1111`
  * `BITMAPINFOHEADER`:
   * `.biSize`: `40`
   * `.biWidth`: `768`
   * `.biHeight`: `576`
   * `.biPlanes`: `1`
   * `.biBitCount`: `16`
   * `.biCompression`: `844715353` `YUY2`
   * `.biSizeImage`: `884,736`
 * `VIDEO_STREAM_CONFIG_CAPS`:
  * Data: `80 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 00 00 00 03 00 00 40 02 00 00 00 03 00 00 40 02 00 00 00 03 00 00 40 02 00 00 01 00 00 00 01 00 00 00 01 00 00 00 01 00 00 00 00 03 00 00 40 02 00 00 00 03 00 00 40 02 00 00 01 00 00 00 01 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 47 F4 10 00 00 00 00 00 47 F4 10 00 00 00 00 00 00 00 E6 01 00 00 E6 01`
  * `.guid`: `{05589F80-C356-11CE-BF01-00AA0055595A}`
  * `.VideoStandard`: `0`
  * `.InputSize`: `768` x `576`
  * `.MinCroppingSize`: `768` x `576`
  * `.MaxCroppingSize`: `768` x `576`
  * `.CropGranularityX`: `1`
  * `.CropAlignX`: `1`
  * `.CropAlignY`: `1`
  * `.MinOutputSize`: `768` x `576`
  * `.MaxOutputSize`: `768` x `576`
  * `.OutputGranularityX`: `1`
  * `.OutputGranularityY`: `1`
  * `.StretchTapsX`: `0`
  * `.StretchTapsY`: `0`
  * `.ShrinkTapsX`: `0`
  * `.ShrinkTapsY`: `0`
  * `.MinFrameInterval`: `111 1111`
  * `.MaxFrameInterval`: `111 1111`
  * `.MinBitsPerSecond`: `31,850,496`
  * `.MaxBitsPerSecond`: `31,850,496`

#### Capability: 1

 * `AM_MEDIA_TYPE`:
  * Data: `76 69 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 59 55 59 32 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 00 00 00 80 0D 00 A0 76 2A F7 0A EB D0 11 AC E4 00 00 C0 CC 16 BA 00 00 00 00 00 00 00 00 00 00 00 00 70 00 00 00 00 00 00 00 80 76 76 E5 08 02 00 00`
  * Format Data: `00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 CC 03 00 00 00 00 47 F4 10 00 00 00 00 00 00 00 00 00 00 00 00 00 04 00 00 00 03 00 00 00 81 26 8D 00 00 00 00 00 28 00 00 00 00 03 00 00 40 02 00 00 01 00 10 00 59 55 59 32 00 80 0D 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00`
  * `.subtype`: `FourCC YUY2`
  * `.bFixedSizeSamples`: `1`
  * `.bTemporalCompression`: `0`
  * `.lSampleSize`: `884,736`
  * `.cbFormat`: `112`
  * `VIDEOINFOHEADER2`:
 * Unknown Capabilities:
  * Type: `{F72A76A0-EB0A-11D0-ACE4-0000C0CC16BA}`
  * Data: `A0 76 2A F7 0A EB D0 11 AC E4 00 00 C0 CC 16 BA 00 00 00 00 00 03 00 00 40 02 00 00 00 03 00 00 40 02 00 00 00 03 00 00 40 02 00 00 01 00 00 00 01 00 00 00 01 00 00 00 01 00 00 00 00 03 00 00 40 02 00 00 00 03 00 00 40 02 00 00 01 00 00 00 01 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 47 F4 10 00 00 00 00 00 47 F4 10 00 00 00 00 00 00 00 E6 01 00 00 E6 01`

Capability Summary: 

 * Subtypes: FourCC YUY2
 * Resolutions: 768x576

Interfaces:

  * `ISpecifyPropertyPages`
  * `IKsPropertySet`
  * `IQualityControl`
  * `IAMBufferNegotiation`
  * `IAMStreamConfig`
  * `IAMStreamControl`

Property Pages:

  * `{71F96467-78F3-11D0-A18C-00A0C9118956}` - `CLSID_VideoStreamConfigPropertyPage`, VideoStreamConfig Property Page

### Pin: Video Camera Terminal

 * Direction: `PINDIR_INPUT`

 * `AMPROPSETID_Pin`, `AMPROPERTY_PIN_CATEGORY`: `{3EBC7959-3310-493B-AA81-C7E132D56F71}`
Interfaces:

  * `ISpecifyPropertyPages`
  * `IKsPropertySet`
  * `IQualityControl`
  * `IStreamBuilder`

# Audio

