# System

 * Version: `6.1` Build `7601`; Windows 7; Service Pack 1; Service Pack `1.0`
 * Computer Name: `ORIONXPC`
 * User Name: `user1` 
 * Local Time: `22/02/2015 21:48:09`
 * Architecture: x86
 * Processors: `2`, Active Mask `0x3`
 * Page Size: `0x1000`
 * Application Address Space: `0x00010000`..`0x7FFEFFFF`
 * Physical Memory: `990` MB
 * Committed Memory Limit: `2,014` MB

# Video

## Device: USB Video Device

 * Moniker Display Name: `@device:pnp:\\?\usb#vid_1871&pid_01f0&mi_00#6&35f8b1c&0&0000#{65e8773d-8f56-11d0-a3b9-00a0c9223196}\global`

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

 * `VideoProcAmp_Brightness`: `30`, flags `0x02`; `0`..`100`, step `1`, default `30`, cap flags `0x02`
 * `VideoProcAmp_Contrast`: `57`, flags `0x02`; `0`..`100`, step `1`, default `57`, cap flags `0x02`
 * `VideoProcAmp_Saturation`: `2`, flags `0x02`; `0`..`4`, step `1`, default `2`, cap flags `0x02`
 * `VideoProcAmp_Sharpness`: `10`, flags `0x02`; `0`..`100`, step `1`, default `10`, cap flags `0x02`
 * `VideoProcAmp_Gamma`: `3`, flags `0x02`; `1`..`8`, step `1`, default `3`, cap flags `0x02`
 * `VideoProcAmp_BacklightCompensation`: `0`, flags `0x02`; `0`..`1`, step `1`, default `0`, cap flags `0x02`

### IAMCameraControl


### Pin: Capture

 * `AMPROPSETID_Pin`, `AMPROPERTY_PIN_CATEGORY`: `{FB6C4281-0353-11D1-905F-0000C0CC16BA} PIN_CATEGORY_CAPTURE`
 * Capabilities:
  * Count: `10`
  * Structure Size: `128` (expected `128`)

#### Capability: 0

 * `AM_MEDIA_TYPE`:
  * Data: `76 69 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 59 55 59 32 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 00 00 00 60 09 00 80 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 00 00 58 00 00 00 E0 3F 56 00`
  * Format Data: `00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 CA 08 00 00 00 00 15 16 05 00 00 00 00 00 28 00 00 00 80 02 00 00 E0 01 00 00 01 00 10 00 59 55 59 32 00 60 09 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00`
  * `.subtype`: `FourCC YUY2`
  * `.bFixedSizeSamples`: `1`
  * `.bTemporalCompression`: `0`
  * `.lSampleSize`: `614,400`
  * `.cbFormat`: `88`
  * `VIDEOINFOHEADER`:
  * `.rcSource`: (`0`, `0`) - (`0`, `0`)
  * `.rcTarget`: (`0`, `0`) - (`0`, `0`)
  * `.dwBitRate`: `147456000`
  * `.dwBitErrorRate`: `0`
  * `.AvgTimePerFrame`: `33 3333`
  * `BITMAPINFOHEADER`:
   * `.biSize`: `40`
   * `.biWidth`: `640`
   * `.biHeight`: `480`
   * `.biPlanes`: `1`
   * `.biBitCount`: `16`
   * `.biCompression`: `844715353` `YUY2`
   * `.biSizeImage`: `614,400`
 * `VIDEO_STREAM_CONFIG_CAPS`:
  * Data: `80 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 00 00 80 02 00 00 E0 01 00 00 80 02 00 00 E0 01 00 00 80 02 00 00 E0 01 00 00 01 00 00 00 01 00 00 00 01 00 00 00 01 00 00 00 80 02 00 00 E0 01 00 00 80 02 00 00 E0 01 00 00 01 00 00 00 01 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 15 16 05 00 00 00 00 00 15 16 05 00 00 00 00 00 00 00 CA 08 00 00 CA 08`
  * `.guid`: `{05589F80-C356-11CE-BF01-00AA0055595A}`
  * `.VideoStandard`: `0`
  * `.InputSize`: `640` x `480`
  * `.MinCroppingSize`: `640` x `480`
  * `.MaxCroppingSize`: `640` x `480`
  * `.CropGranularityX`: `1`
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
  * `.MinFrameInterval`: `33 3333`
  * `.MaxFrameInterval`: `33 3333`
  * `.MinBitsPerSecond`: `147,456,000`
  * `.MaxBitsPerSecond`: `147,456,000`

#### Capability: 1

 * `AM_MEDIA_TYPE`:
  * Data: `76 69 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 59 55 59 32 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 00 00 00 60 09 00 A0 76 2A F7 0A EB D0 11 AC E4 00 00 C0 CC 16 BA 00 00 00 00 70 00 00 00 D8 E2 59 00`
  * Format Data: `00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 CA 08 00 00 00 00 15 16 05 00 00 00 00 00 00 00 00 00 00 00 00 00 04 00 00 00 03 00 00 00 81 26 8D 00 00 00 00 00 28 00 00 00 80 02 00 00 E0 01 00 00 01 00 10 00 59 55 59 32 00 60 09 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00`
  * `.subtype`: `FourCC YUY2`
  * `.bFixedSizeSamples`: `1`
  * `.bTemporalCompression`: `0`
  * `.lSampleSize`: `614,400`
  * `.cbFormat`: `112`
  * `VIDEOINFOHEADER2`:
 * Unknown Capabilities:
  * Type: `{F72A76A0-EB0A-11D0-ACE4-0000C0CC16BA}`
  * Data: `A0 76 2A F7 0A EB D0 11 AC E4 00 00 C0 CC 16 BA 00 00 00 00 80 02 00 00 E0 01 00 00 80 02 00 00 E0 01 00 00 80 02 00 00 E0 01 00 00 01 00 00 00 01 00 00 00 01 00 00 00 01 00 00 00 80 02 00 00 E0 01 00 00 80 02 00 00 E0 01 00 00 01 00 00 00 01 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 15 16 05 00 00 00 00 00 15 16 05 00 00 00 00 00 00 00 CA 08 00 00 CA 08`

#### Capability: 2

 * `AM_MEDIA_TYPE`:
  * Data: `76 69 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 59 55 59 32 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 00 00 00 96 00 00 80 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 00 00 58 00 00 00 E0 3F 56 00`
  * Format Data: `00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 A0 8C 00 00 00 00 00 15 16 05 00 00 00 00 00 28 00 00 00 A0 00 00 00 78 00 00 00 01 00 10 00 59 55 59 32 00 96 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00`
  * `.subtype`: `FourCC YUY2`
  * `.bFixedSizeSamples`: `1`
  * `.bTemporalCompression`: `0`
  * `.lSampleSize`: `38,400`
  * `.cbFormat`: `88`
  * `VIDEOINFOHEADER`:
  * `.rcSource`: (`0`, `0`) - (`0`, `0`)
  * `.rcTarget`: (`0`, `0`) - (`0`, `0`)
  * `.dwBitRate`: `9216000`
  * `.dwBitErrorRate`: `0`
  * `.AvgTimePerFrame`: `33 3333`
  * `BITMAPINFOHEADER`:
   * `.biSize`: `40`
   * `.biWidth`: `160`
   * `.biHeight`: `120`
   * `.biPlanes`: `1`
   * `.biBitCount`: `16`
   * `.biCompression`: `844715353` `YUY2`
   * `.biSizeImage`: `38,400`
 * `VIDEO_STREAM_CONFIG_CAPS`:
  * Data: `80 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 00 00 A0 00 00 00 78 00 00 00 A0 00 00 00 78 00 00 00 A0 00 00 00 78 00 00 00 01 00 00 00 01 00 00 00 01 00 00 00 01 00 00 00 A0 00 00 00 78 00 00 00 A0 00 00 00 78 00 00 00 01 00 00 00 01 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 15 16 05 00 00 00 00 00 15 16 05 00 00 00 00 00 00 A0 8C 00 00 A0 8C 00`
  * `.guid`: `{05589F80-C356-11CE-BF01-00AA0055595A}`
  * `.VideoStandard`: `0`
  * `.InputSize`: `160` x `120`
  * `.MinCroppingSize`: `160` x `120`
  * `.MaxCroppingSize`: `160` x `120`
  * `.CropGranularityX`: `1`
  * `.CropAlignX`: `1`
  * `.CropAlignY`: `1`
  * `.MinOutputSize`: `160` x `120`
  * `.MaxOutputSize`: `160` x `120`
  * `.OutputGranularityX`: `1`
  * `.OutputGranularityY`: `1`
  * `.StretchTapsX`: `0`
  * `.StretchTapsY`: `0`
  * `.ShrinkTapsX`: `0`
  * `.ShrinkTapsY`: `0`
  * `.MinFrameInterval`: `33 3333`
  * `.MaxFrameInterval`: `33 3333`
  * `.MinBitsPerSecond`: `9,216,000`
  * `.MaxBitsPerSecond`: `9,216,000`

#### Capability: 3

 * `AM_MEDIA_TYPE`:
  * Data: `76 69 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 59 55 59 32 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 00 00 00 96 00 00 A0 76 2A F7 0A EB D0 11 AC E4 00 00 C0 CC 16 BA 00 00 00 00 70 00 00 00 D8 E2 59 00`
  * Format Data: `00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 A0 8C 00 00 00 00 00 15 16 05 00 00 00 00 00 00 00 00 00 00 00 00 00 04 00 00 00 03 00 00 00 81 26 8D 00 00 00 00 00 28 00 00 00 A0 00 00 00 78 00 00 00 01 00 10 00 59 55 59 32 00 96 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00`
  * `.subtype`: `FourCC YUY2`
  * `.bFixedSizeSamples`: `1`
  * `.bTemporalCompression`: `0`
  * `.lSampleSize`: `38,400`
  * `.cbFormat`: `112`
  * `VIDEOINFOHEADER2`:
 * Unknown Capabilities:
  * Type: `{F72A76A0-EB0A-11D0-ACE4-0000C0CC16BA}`
  * Data: `A0 76 2A F7 0A EB D0 11 AC E4 00 00 C0 CC 16 BA 00 00 00 00 A0 00 00 00 78 00 00 00 A0 00 00 00 78 00 00 00 A0 00 00 00 78 00 00 00 01 00 00 00 01 00 00 00 01 00 00 00 01 00 00 00 A0 00 00 00 78 00 00 00 A0 00 00 00 78 00 00 00 01 00 00 00 01 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 15 16 05 00 00 00 00 00 15 16 05 00 00 00 00 00 00 A0 8C 00 00 A0 8C 00`

#### Capability: 4

 * `AM_MEDIA_TYPE`:
  * Data: `76 69 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 59 55 59 32 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 00 00 00 58 02 00 80 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 00 00 58 00 00 00 E0 3F 56 00`
  * Format Data: `00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 80 32 02 00 00 00 00 15 16 05 00 00 00 00 00 28 00 00 00 40 01 00 00 F0 00 00 00 01 00 10 00 59 55 59 32 00 58 02 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00`
  * `.subtype`: `FourCC YUY2`
  * `.bFixedSizeSamples`: `1`
  * `.bTemporalCompression`: `0`
  * `.lSampleSize`: `153,600`
  * `.cbFormat`: `88`
  * `VIDEOINFOHEADER`:
  * `.rcSource`: (`0`, `0`) - (`0`, `0`)
  * `.rcTarget`: (`0`, `0`) - (`0`, `0`)
  * `.dwBitRate`: `36864000`
  * `.dwBitErrorRate`: `0`
  * `.AvgTimePerFrame`: `33 3333`
  * `BITMAPINFOHEADER`:
   * `.biSize`: `40`
   * `.biWidth`: `320`
   * `.biHeight`: `240`
   * `.biPlanes`: `1`
   * `.biBitCount`: `16`
   * `.biCompression`: `844715353` `YUY2`
   * `.biSizeImage`: `153,600`
 * `VIDEO_STREAM_CONFIG_CAPS`:
  * Data: `80 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 00 00 40 01 00 00 F0 00 00 00 40 01 00 00 F0 00 00 00 40 01 00 00 F0 00 00 00 01 00 00 00 01 00 00 00 01 00 00 00 01 00 00 00 40 01 00 00 F0 00 00 00 40 01 00 00 F0 00 00 00 01 00 00 00 01 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 15 16 05 00 00 00 00 00 15 16 05 00 00 00 00 00 00 80 32 02 00 80 32 02`
  * `.guid`: `{05589F80-C356-11CE-BF01-00AA0055595A}`
  * `.VideoStandard`: `0`
  * `.InputSize`: `320` x `240`
  * `.MinCroppingSize`: `320` x `240`
  * `.MaxCroppingSize`: `320` x `240`
  * `.CropGranularityX`: `1`
  * `.CropAlignX`: `1`
  * `.CropAlignY`: `1`
  * `.MinOutputSize`: `320` x `240`
  * `.MaxOutputSize`: `320` x `240`
  * `.OutputGranularityX`: `1`
  * `.OutputGranularityY`: `1`
  * `.StretchTapsX`: `0`
  * `.StretchTapsY`: `0`
  * `.ShrinkTapsX`: `0`
  * `.ShrinkTapsY`: `0`
  * `.MinFrameInterval`: `33 3333`
  * `.MaxFrameInterval`: `33 3333`
  * `.MinBitsPerSecond`: `36,864,000`
  * `.MaxBitsPerSecond`: `36,864,000`

#### Capability: 5

 * `AM_MEDIA_TYPE`:
  * Data: `76 69 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 59 55 59 32 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 00 00 00 58 02 00 A0 76 2A F7 0A EB D0 11 AC E4 00 00 C0 CC 16 BA 00 00 00 00 70 00 00 00 D8 E2 59 00`
  * Format Data: `00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 80 32 02 00 00 00 00 15 16 05 00 00 00 00 00 00 00 00 00 00 00 00 00 04 00 00 00 03 00 00 00 81 26 8D 00 00 00 00 00 28 00 00 00 40 01 00 00 F0 00 00 00 01 00 10 00 59 55 59 32 00 58 02 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00`
  * `.subtype`: `FourCC YUY2`
  * `.bFixedSizeSamples`: `1`
  * `.bTemporalCompression`: `0`
  * `.lSampleSize`: `153,600`
  * `.cbFormat`: `112`
  * `VIDEOINFOHEADER2`:
 * Unknown Capabilities:
  * Type: `{F72A76A0-EB0A-11D0-ACE4-0000C0CC16BA}`
  * Data: `A0 76 2A F7 0A EB D0 11 AC E4 00 00 C0 CC 16 BA 00 00 00 00 40 01 00 00 F0 00 00 00 40 01 00 00 F0 00 00 00 40 01 00 00 F0 00 00 00 01 00 00 00 01 00 00 00 01 00 00 00 01 00 00 00 40 01 00 00 F0 00 00 00 40 01 00 00 F0 00 00 00 01 00 00 00 01 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 15 16 05 00 00 00 00 00 15 16 05 00 00 00 00 00 00 80 32 02 00 80 32 02`

#### Capability: 6

 * `AM_MEDIA_TYPE`:
  * Data: `76 69 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 59 55 59 32 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 00 00 00 C6 00 00 80 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 00 00 58 00 00 00 E0 3F 56 00`
  * Format Data: `00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 A0 B9 00 00 00 00 00 15 16 05 00 00 00 00 00 28 00 00 00 B0 00 00 00 90 00 00 00 01 00 10 00 59 55 59 32 00 C6 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00`
  * `.subtype`: `FourCC YUY2`
  * `.bFixedSizeSamples`: `1`
  * `.bTemporalCompression`: `0`
  * `.lSampleSize`: `50,688`
  * `.cbFormat`: `88`
  * `VIDEOINFOHEADER`:
  * `.rcSource`: (`0`, `0`) - (`0`, `0`)
  * `.rcTarget`: (`0`, `0`) - (`0`, `0`)
  * `.dwBitRate`: `12165120`
  * `.dwBitErrorRate`: `0`
  * `.AvgTimePerFrame`: `33 3333`
  * `BITMAPINFOHEADER`:
   * `.biSize`: `40`
   * `.biWidth`: `176`
   * `.biHeight`: `144`
   * `.biPlanes`: `1`
   * `.biBitCount`: `16`
   * `.biCompression`: `844715353` `YUY2`
   * `.biSizeImage`: `50,688`
 * `VIDEO_STREAM_CONFIG_CAPS`:
  * Data: `80 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 00 00 B0 00 00 00 90 00 00 00 B0 00 00 00 90 00 00 00 B0 00 00 00 90 00 00 00 01 00 00 00 01 00 00 00 01 00 00 00 01 00 00 00 B0 00 00 00 90 00 00 00 B0 00 00 00 90 00 00 00 01 00 00 00 01 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 15 16 05 00 00 00 00 00 15 16 05 00 00 00 00 00 00 A0 B9 00 00 A0 B9 00`
  * `.guid`: `{05589F80-C356-11CE-BF01-00AA0055595A}`
  * `.VideoStandard`: `0`
  * `.InputSize`: `176` x `144`
  * `.MinCroppingSize`: `176` x `144`
  * `.MaxCroppingSize`: `176` x `144`
  * `.CropGranularityX`: `1`
  * `.CropAlignX`: `1`
  * `.CropAlignY`: `1`
  * `.MinOutputSize`: `176` x `144`
  * `.MaxOutputSize`: `176` x `144`
  * `.OutputGranularityX`: `1`
  * `.OutputGranularityY`: `1`
  * `.StretchTapsX`: `0`
  * `.StretchTapsY`: `0`
  * `.ShrinkTapsX`: `0`
  * `.ShrinkTapsY`: `0`
  * `.MinFrameInterval`: `33 3333`
  * `.MaxFrameInterval`: `33 3333`
  * `.MinBitsPerSecond`: `12,165,120`
  * `.MaxBitsPerSecond`: `12,165,120`

#### Capability: 7

 * `AM_MEDIA_TYPE`:
  * Data: `76 69 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 59 55 59 32 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 00 00 00 C6 00 00 A0 76 2A F7 0A EB D0 11 AC E4 00 00 C0 CC 16 BA 00 00 00 00 70 00 00 00 D8 E2 59 00`
  * Format Data: `00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 A0 B9 00 00 00 00 00 15 16 05 00 00 00 00 00 00 00 00 00 00 00 00 00 04 00 00 00 03 00 00 00 81 26 8D 00 00 00 00 00 28 00 00 00 B0 00 00 00 90 00 00 00 01 00 10 00 59 55 59 32 00 C6 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00`
  * `.subtype`: `FourCC YUY2`
  * `.bFixedSizeSamples`: `1`
  * `.bTemporalCompression`: `0`
  * `.lSampleSize`: `50,688`
  * `.cbFormat`: `112`
  * `VIDEOINFOHEADER2`:
 * Unknown Capabilities:
  * Type: `{F72A76A0-EB0A-11D0-ACE4-0000C0CC16BA}`
  * Data: `A0 76 2A F7 0A EB D0 11 AC E4 00 00 C0 CC 16 BA 00 00 00 00 B0 00 00 00 90 00 00 00 B0 00 00 00 90 00 00 00 B0 00 00 00 90 00 00 00 01 00 00 00 01 00 00 00 01 00 00 00 01 00 00 00 B0 00 00 00 90 00 00 00 B0 00 00 00 90 00 00 00 01 00 00 00 01 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 15 16 05 00 00 00 00 00 15 16 05 00 00 00 00 00 00 A0 B9 00 00 A0 B9 00`

#### Capability: 8

 * `AM_MEDIA_TYPE`:
  * Data: `76 69 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 59 55 59 32 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 00 00 00 18 03 00 80 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 00 00 58 00 00 00 E0 3F 56 00`
  * Format Data: `00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 80 E6 02 00 00 00 00 15 16 05 00 00 00 00 00 28 00 00 00 60 01 00 00 20 01 00 00 01 00 10 00 59 55 59 32 00 18 03 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00`
  * `.subtype`: `FourCC YUY2`
  * `.bFixedSizeSamples`: `1`
  * `.bTemporalCompression`: `0`
  * `.lSampleSize`: `202,752`
  * `.cbFormat`: `88`
  * `VIDEOINFOHEADER`:
  * `.rcSource`: (`0`, `0`) - (`0`, `0`)
  * `.rcTarget`: (`0`, `0`) - (`0`, `0`)
  * `.dwBitRate`: `48660480`
  * `.dwBitErrorRate`: `0`
  * `.AvgTimePerFrame`: `33 3333`
  * `BITMAPINFOHEADER`:
   * `.biSize`: `40`
   * `.biWidth`: `352`
   * `.biHeight`: `288`
   * `.biPlanes`: `1`
   * `.biBitCount`: `16`
   * `.biCompression`: `844715353` `YUY2`
   * `.biSizeImage`: `202,752`
 * `VIDEO_STREAM_CONFIG_CAPS`:
  * Data: `80 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 00 00 60 01 00 00 20 01 00 00 60 01 00 00 20 01 00 00 60 01 00 00 20 01 00 00 01 00 00 00 01 00 00 00 01 00 00 00 01 00 00 00 60 01 00 00 20 01 00 00 60 01 00 00 20 01 00 00 01 00 00 00 01 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 15 16 05 00 00 00 00 00 15 16 05 00 00 00 00 00 00 80 E6 02 00 80 E6 02`
  * `.guid`: `{05589F80-C356-11CE-BF01-00AA0055595A}`
  * `.VideoStandard`: `0`
  * `.InputSize`: `352` x `288`
  * `.MinCroppingSize`: `352` x `288`
  * `.MaxCroppingSize`: `352` x `288`
  * `.CropGranularityX`: `1`
  * `.CropAlignX`: `1`
  * `.CropAlignY`: `1`
  * `.MinOutputSize`: `352` x `288`
  * `.MaxOutputSize`: `352` x `288`
  * `.OutputGranularityX`: `1`
  * `.OutputGranularityY`: `1`
  * `.StretchTapsX`: `0`
  * `.StretchTapsY`: `0`
  * `.ShrinkTapsX`: `0`
  * `.ShrinkTapsY`: `0`
  * `.MinFrameInterval`: `33 3333`
  * `.MaxFrameInterval`: `33 3333`
  * `.MinBitsPerSecond`: `48,660,480`
  * `.MaxBitsPerSecond`: `48,660,480`

#### Capability: 9

 * `AM_MEDIA_TYPE`:
  * Data: `76 69 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 59 55 59 32 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 00 00 00 18 03 00 A0 76 2A F7 0A EB D0 11 AC E4 00 00 C0 CC 16 BA 00 00 00 00 70 00 00 00 D8 E2 59 00`
  * Format Data: `00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 80 E6 02 00 00 00 00 15 16 05 00 00 00 00 00 00 00 00 00 00 00 00 00 04 00 00 00 03 00 00 00 81 26 8D 00 00 00 00 00 28 00 00 00 60 01 00 00 20 01 00 00 01 00 10 00 59 55 59 32 00 18 03 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00`
  * `.subtype`: `FourCC YUY2`
  * `.bFixedSizeSamples`: `1`
  * `.bTemporalCompression`: `0`
  * `.lSampleSize`: `202,752`
  * `.cbFormat`: `112`
  * `VIDEOINFOHEADER2`:
 * Unknown Capabilities:
  * Type: `{F72A76A0-EB0A-11D0-ACE4-0000C0CC16BA}`
  * Data: `A0 76 2A F7 0A EB D0 11 AC E4 00 00 C0 CC 16 BA 00 00 00 00 60 01 00 00 20 01 00 00 60 01 00 00 20 01 00 00 60 01 00 00 20 01 00 00 01 00 00 00 01 00 00 00 01 00 00 00 01 00 00 00 60 01 00 00 20 01 00 00 60 01 00 00 20 01 00 00 01 00 00 00 01 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 15 16 05 00 00 00 00 00 15 16 05 00 00 00 00 00 00 80 E6 02 00 80 E6 02`

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

### Pin: Still

 * `AMPROPSETID_Pin`, `AMPROPERTY_PIN_CATEGORY`: `{FB6C428A-0353-11D1-905F-0000C0CC16BA} PIN_CATEGORY_STILL`
 * Capabilities:
  * Count: `3`
  * Structure Size: `128` (expected `128`)

#### Capability: 0

 * `AM_MEDIA_TYPE`:
  * Data: `76 69 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 59 55 59 32 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 00 00 00 60 09 00 80 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 00 00 58 00 00 00 E0 3F 56 00`
  * Format Data: `00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 4B 00 00 00 00 00 80 96 98 00 00 00 00 00 28 00 00 00 80 02 00 00 E0 01 00 00 01 00 10 00 59 55 59 32 00 60 09 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00`
  * `.subtype`: `FourCC YUY2`
  * `.bFixedSizeSamples`: `1`
  * `.bTemporalCompression`: `0`
  * `.lSampleSize`: `614,400`
  * `.cbFormat`: `88`
  * `VIDEOINFOHEADER`:
  * `.rcSource`: (`0`, `0`) - (`0`, `0`)
  * `.rcTarget`: (`0`, `0`) - (`0`, `0`)
  * `.dwBitRate`: `4915200`
  * `.dwBitErrorRate`: `0`
  * `.AvgTimePerFrame`: `1 000 0000`
  * `BITMAPINFOHEADER`:
   * `.biSize`: `40`
   * `.biWidth`: `640`
   * `.biHeight`: `480`
   * `.biPlanes`: `1`
   * `.biBitCount`: `16`
   * `.biCompression`: `844715353` `YUY2`
   * `.biSizeImage`: `614,400`
 * `VIDEO_STREAM_CONFIG_CAPS`:
  * Data: `80 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 00 00 80 02 00 00 E0 01 00 00 80 02 00 00 E0 01 00 00 80 02 00 00 E0 01 00 00 01 00 00 00 01 00 00 00 01 00 00 00 01 00 00 00 80 02 00 00 E0 01 00 00 80 02 00 00 E0 01 00 00 01 00 00 00 01 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 80 96 98 00 00 00 00 00 80 96 98 00 00 00 00 00 00 00 4B 00 00 00 4B 00`
  * `.guid`: `{05589F80-C356-11CE-BF01-00AA0055595A}`
  * `.VideoStandard`: `0`
  * `.InputSize`: `640` x `480`
  * `.MinCroppingSize`: `640` x `480`
  * `.MaxCroppingSize`: `640` x `480`
  * `.CropGranularityX`: `1`
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
  * `.MinFrameInterval`: `1 000 0000`
  * `.MaxFrameInterval`: `1 000 0000`
  * `.MinBitsPerSecond`: `4,915,200`
  * `.MaxBitsPerSecond`: `4,915,200`

#### Capability: 1

 * `AM_MEDIA_TYPE`:
  * Data: `76 69 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 59 55 59 32 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 00 00 00 58 02 00 80 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 00 00 58 00 00 00 E0 3F 56 00`
  * Format Data: `00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 C0 12 00 00 00 00 00 80 96 98 00 00 00 00 00 28 00 00 00 40 01 00 00 F0 00 00 00 01 00 10 00 59 55 59 32 00 58 02 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00`
  * `.subtype`: `FourCC YUY2`
  * `.bFixedSizeSamples`: `1`
  * `.bTemporalCompression`: `0`
  * `.lSampleSize`: `153,600`
  * `.cbFormat`: `88`
  * `VIDEOINFOHEADER`:
  * `.rcSource`: (`0`, `0`) - (`0`, `0`)
  * `.rcTarget`: (`0`, `0`) - (`0`, `0`)
  * `.dwBitRate`: `1228800`
  * `.dwBitErrorRate`: `0`
  * `.AvgTimePerFrame`: `1 000 0000`
  * `BITMAPINFOHEADER`:
   * `.biSize`: `40`
   * `.biWidth`: `320`
   * `.biHeight`: `240`
   * `.biPlanes`: `1`
   * `.biBitCount`: `16`
   * `.biCompression`: `844715353` `YUY2`
   * `.biSizeImage`: `153,600`
 * `VIDEO_STREAM_CONFIG_CAPS`:
  * Data: `80 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 00 00 40 01 00 00 F0 00 00 00 40 01 00 00 F0 00 00 00 40 01 00 00 F0 00 00 00 01 00 00 00 01 00 00 00 01 00 00 00 01 00 00 00 40 01 00 00 F0 00 00 00 40 01 00 00 F0 00 00 00 01 00 00 00 01 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 80 96 98 00 00 00 00 00 80 96 98 00 00 00 00 00 00 C0 12 00 00 C0 12 00`
  * `.guid`: `{05589F80-C356-11CE-BF01-00AA0055595A}`
  * `.VideoStandard`: `0`
  * `.InputSize`: `320` x `240`
  * `.MinCroppingSize`: `320` x `240`
  * `.MaxCroppingSize`: `320` x `240`
  * `.CropGranularityX`: `1`
  * `.CropAlignX`: `1`
  * `.CropAlignY`: `1`
  * `.MinOutputSize`: `320` x `240`
  * `.MaxOutputSize`: `320` x `240`
  * `.OutputGranularityX`: `1`
  * `.OutputGranularityY`: `1`
  * `.StretchTapsX`: `0`
  * `.StretchTapsY`: `0`
  * `.ShrinkTapsX`: `0`
  * `.ShrinkTapsY`: `0`
  * `.MinFrameInterval`: `1 000 0000`
  * `.MaxFrameInterval`: `1 000 0000`
  * `.MinBitsPerSecond`: `1,228,800`
  * `.MaxBitsPerSecond`: `1,228,800`

#### Capability: 2

 * `AM_MEDIA_TYPE`:
  * Data: `76 69 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 59 55 59 32 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 00 00 00 96 00 00 80 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 00 00 58 00 00 00 E0 3F 56 00`
  * Format Data: `00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 B0 04 00 00 00 00 00 80 96 98 00 00 00 00 00 28 00 00 00 A0 00 00 00 78 00 00 00 01 00 10 00 59 55 59 32 00 96 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00`
  * `.subtype`: `FourCC YUY2`
  * `.bFixedSizeSamples`: `1`
  * `.bTemporalCompression`: `0`
  * `.lSampleSize`: `38,400`
  * `.cbFormat`: `88`
  * `VIDEOINFOHEADER`:
  * `.rcSource`: (`0`, `0`) - (`0`, `0`)
  * `.rcTarget`: (`0`, `0`) - (`0`, `0`)
  * `.dwBitRate`: `307200`
  * `.dwBitErrorRate`: `0`
  * `.AvgTimePerFrame`: `1 000 0000`
  * `BITMAPINFOHEADER`:
   * `.biSize`: `40`
   * `.biWidth`: `160`
   * `.biHeight`: `120`
   * `.biPlanes`: `1`
   * `.biBitCount`: `16`
   * `.biCompression`: `844715353` `YUY2`
   * `.biSizeImage`: `38,400`
 * `VIDEO_STREAM_CONFIG_CAPS`:
  * Data: `80 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 00 00 A0 00 00 00 78 00 00 00 A0 00 00 00 78 00 00 00 A0 00 00 00 78 00 00 00 01 00 00 00 01 00 00 00 01 00 00 00 01 00 00 00 A0 00 00 00 78 00 00 00 A0 00 00 00 78 00 00 00 01 00 00 00 01 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 80 96 98 00 00 00 00 00 80 96 98 00 00 00 00 00 00 B0 04 00 00 B0 04 00`
  * `.guid`: `{05589F80-C356-11CE-BF01-00AA0055595A}`
  * `.VideoStandard`: `0`
  * `.InputSize`: `160` x `120`
  * `.MinCroppingSize`: `160` x `120`
  * `.MaxCroppingSize`: `160` x `120`
  * `.CropGranularityX`: `1`
  * `.CropAlignX`: `1`
  * `.CropAlignY`: `1`
  * `.MinOutputSize`: `160` x `120`
  * `.MaxOutputSize`: `160` x `120`
  * `.OutputGranularityX`: `1`
  * `.OutputGranularityY`: `1`
  * `.StretchTapsX`: `0`
  * `.StretchTapsY`: `0`
  * `.ShrinkTapsX`: `0`
  * `.ShrinkTapsY`: `0`
  * `.MinFrameInterval`: `1 000 0000`
  * `.MaxFrameInterval`: `1 000 0000`
  * `.MinBitsPerSecond`: `307,200`
  * `.MaxBitsPerSecond`: `307,200`

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

## Device: Microphone (Realtek AC'97 Audio

 * Moniker Display Name: `@device:cm:{33D9A762-90C8-11D0-BD43-00A0C911CE86}\Microphone (Realtek AC'97 Audio`

Interfaces:

  * `ISpecifyPropertyPages`
  * `IAMFilterMiscFlags`

Property Pages:

  * `{2CA8CA52-3C3F-11D2-B73D-00C04FB6BD3D}` - `CLSID_AudioInputMixerProperties`, AudioInputMixer Property Page

### Pin: Capture

 * `AMPROPSETID_Pin`, `AMPROPERTY_PIN_CATEGORY`: `{FB6C4281-0353-11D1-905F-0000C0CC16BA} PIN_CATEGORY_CAPTURE`
 * Capabilities:
  * Count: `23`
  * Structure Size: `52` (expected `52`)

#### Capability: 0

 * `AM_MEDIA_TYPE`:
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 00 00 04 00 00 00 81 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 00 00 12 00 00 00 E8 D3 61 00`
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
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 02 00 00 00 01 00 00 00 08 00 00 00 10 00 00 00 08 00 00 00 11 2B 00 00 44 AC 00 00 11 2B 00 00`
  * `.MinimumChannels`: `1`
  * `.MaximumChannels`: `2`
  * `.ChannelsGranularity`: `1`
  * `.MinimumBitsPerSample`: `8`
  * `.MaximumBitsPerSample`: `16`
  * `.BitsPerSampleGranularity`: `8`
  * `.MinimumSampleFrequency`: `11025`
  * `.MaximumSampleFrequency`: `44100`
  * `.SampleFrequencyGranularity`: `11025`

#### Capability: 1

 * `AM_MEDIA_TYPE`:
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 00 00 04 00 00 00 81 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 00 00 12 00 00 00 C8 D3 61 00`
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
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 02 00 00 00 01 00 00 00 08 00 00 00 10 00 00 00 08 00 00 00 11 2B 00 00 44 AC 00 00 11 2B 00 00`
  * `.MinimumChannels`: `1`
  * `.MaximumChannels`: `2`
  * `.ChannelsGranularity`: `1`
  * `.MinimumBitsPerSample`: `8`
  * `.MaximumBitsPerSample`: `16`
  * `.BitsPerSampleGranularity`: `8`
  * `.MinimumSampleFrequency`: `11025`
  * `.MaximumSampleFrequency`: `44100`
  * `.SampleFrequencyGranularity`: `11025`

#### Capability: 2

 * `AM_MEDIA_TYPE`:
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 00 00 02 00 00 00 81 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 00 00 12 00 00 00 E8 D3 61 00`
  * Format Data: `01 00 01 00 44 AC 00 00 88 58 01 00 02 00 10 00 00 00`
  * `.subtype`: `FourCC 0x00000001`
  * `.bFixedSizeSamples`: `1`
  * `.bTemporalCompression`: `0`
  * `.lSampleSize`: `2`
  * `.cbFormat`: `18`
  * `WAVEFORMATEX`:
   * `.wFormatTag`: `1`
   * `.nChannels`: `1`
   * `.nSamplesPerSec`: `44100`
   * `.nAvgBytesPerSec: `88200`
   * `.nBlockAlign`: `2`
   * `.wBitsPerSample`: `16`
   * `.cbSize`: `0`
 * `AUDIO_STREAM_CONFIG_CAPS`:
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 02 00 00 00 01 00 00 00 08 00 00 00 10 00 00 00 08 00 00 00 11 2B 00 00 44 AC 00 00 11 2B 00 00`
  * `.MinimumChannels`: `1`
  * `.MaximumChannels`: `2`
  * `.ChannelsGranularity`: `1`
  * `.MinimumBitsPerSample`: `8`
  * `.MaximumBitsPerSample`: `16`
  * `.BitsPerSampleGranularity`: `8`
  * `.MinimumSampleFrequency`: `11025`
  * `.MaximumSampleFrequency`: `44100`
  * `.SampleFrequencyGranularity`: `11025`

#### Capability: 3

 * `AM_MEDIA_TYPE`:
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 00 00 04 00 00 00 81 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 00 00 12 00 00 00 C8 D3 61 00`
  * Format Data: `01 00 02 00 00 7D 00 00 00 F4 01 00 04 00 10 00 00 00`
  * `.subtype`: `FourCC 0x00000001`
  * `.bFixedSizeSamples`: `1`
  * `.bTemporalCompression`: `0`
  * `.lSampleSize`: `4`
  * `.cbFormat`: `18`
  * `WAVEFORMATEX`:
   * `.wFormatTag`: `1`
   * `.nChannels`: `2`
   * `.nSamplesPerSec`: `32000`
   * `.nAvgBytesPerSec: `128000`
   * `.nBlockAlign`: `4`
   * `.wBitsPerSample`: `16`
   * `.cbSize`: `0`
 * `AUDIO_STREAM_CONFIG_CAPS`:
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 02 00 00 00 01 00 00 00 08 00 00 00 10 00 00 00 08 00 00 00 11 2B 00 00 44 AC 00 00 11 2B 00 00`
  * `.MinimumChannels`: `1`
  * `.MaximumChannels`: `2`
  * `.ChannelsGranularity`: `1`
  * `.MinimumBitsPerSample`: `8`
  * `.MaximumBitsPerSample`: `16`
  * `.BitsPerSampleGranularity`: `8`
  * `.MinimumSampleFrequency`: `11025`
  * `.MaximumSampleFrequency`: `44100`
  * `.SampleFrequencyGranularity`: `11025`

#### Capability: 4

 * `AM_MEDIA_TYPE`:
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 00 00 02 00 00 00 81 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 00 00 12 00 00 00 E8 D3 61 00`
  * Format Data: `01 00 01 00 00 7D 00 00 00 FA 00 00 02 00 10 00 00 00`
  * `.subtype`: `FourCC 0x00000001`
  * `.bFixedSizeSamples`: `1`
  * `.bTemporalCompression`: `0`
  * `.lSampleSize`: `2`
  * `.cbFormat`: `18`
  * `WAVEFORMATEX`:
   * `.wFormatTag`: `1`
   * `.nChannels`: `1`
   * `.nSamplesPerSec`: `32000`
   * `.nAvgBytesPerSec: `64000`
   * `.nBlockAlign`: `2`
   * `.wBitsPerSample`: `16`
   * `.cbSize`: `0`
 * `AUDIO_STREAM_CONFIG_CAPS`:
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 02 00 00 00 01 00 00 00 08 00 00 00 10 00 00 00 08 00 00 00 11 2B 00 00 44 AC 00 00 11 2B 00 00`
  * `.MinimumChannels`: `1`
  * `.MaximumChannels`: `2`
  * `.ChannelsGranularity`: `1`
  * `.MinimumBitsPerSample`: `8`
  * `.MaximumBitsPerSample`: `16`
  * `.BitsPerSampleGranularity`: `8`
  * `.MinimumSampleFrequency`: `11025`
  * `.MaximumSampleFrequency`: `44100`
  * `.SampleFrequencyGranularity`: `11025`

#### Capability: 5

 * `AM_MEDIA_TYPE`:
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 00 00 04 00 00 00 81 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 00 00 12 00 00 00 C8 D3 61 00`
  * Format Data: `01 00 02 00 22 56 00 00 88 58 01 00 04 00 10 00 00 00`
  * `.subtype`: `FourCC 0x00000001`
  * `.bFixedSizeSamples`: `1`
  * `.bTemporalCompression`: `0`
  * `.lSampleSize`: `4`
  * `.cbFormat`: `18`
  * `WAVEFORMATEX`:
   * `.wFormatTag`: `1`
   * `.nChannels`: `2`
   * `.nSamplesPerSec`: `22050`
   * `.nAvgBytesPerSec: `88200`
   * `.nBlockAlign`: `4`
   * `.wBitsPerSample`: `16`
   * `.cbSize`: `0`
 * `AUDIO_STREAM_CONFIG_CAPS`:
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 02 00 00 00 01 00 00 00 08 00 00 00 10 00 00 00 08 00 00 00 11 2B 00 00 44 AC 00 00 11 2B 00 00`
  * `.MinimumChannels`: `1`
  * `.MaximumChannels`: `2`
  * `.ChannelsGranularity`: `1`
  * `.MinimumBitsPerSample`: `8`
  * `.MaximumBitsPerSample`: `16`
  * `.BitsPerSampleGranularity`: `8`
  * `.MinimumSampleFrequency`: `11025`
  * `.MaximumSampleFrequency`: `44100`
  * `.SampleFrequencyGranularity`: `11025`

#### Capability: 6

 * `AM_MEDIA_TYPE`:
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 00 00 02 00 00 00 81 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 00 00 12 00 00 00 E8 D3 61 00`
  * Format Data: `01 00 01 00 22 56 00 00 44 AC 00 00 02 00 10 00 00 00`
  * `.subtype`: `FourCC 0x00000001`
  * `.bFixedSizeSamples`: `1`
  * `.bTemporalCompression`: `0`
  * `.lSampleSize`: `2`
  * `.cbFormat`: `18`
  * `WAVEFORMATEX`:
   * `.wFormatTag`: `1`
   * `.nChannels`: `1`
   * `.nSamplesPerSec`: `22050`
   * `.nAvgBytesPerSec: `44100`
   * `.nBlockAlign`: `2`
   * `.wBitsPerSample`: `16`
   * `.cbSize`: `0`
 * `AUDIO_STREAM_CONFIG_CAPS`:
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 02 00 00 00 01 00 00 00 08 00 00 00 10 00 00 00 08 00 00 00 11 2B 00 00 44 AC 00 00 11 2B 00 00`
  * `.MinimumChannels`: `1`
  * `.MaximumChannels`: `2`
  * `.ChannelsGranularity`: `1`
  * `.MinimumBitsPerSample`: `8`
  * `.MaximumBitsPerSample`: `16`
  * `.BitsPerSampleGranularity`: `8`
  * `.MinimumSampleFrequency`: `11025`
  * `.MaximumSampleFrequency`: `44100`
  * `.SampleFrequencyGranularity`: `11025`

#### Capability: 7

 * `AM_MEDIA_TYPE`:
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 00 00 04 00 00 00 81 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 00 00 12 00 00 00 C8 D3 61 00`
  * Format Data: `01 00 02 00 11 2B 00 00 44 AC 00 00 04 00 10 00 00 00`
  * `.subtype`: `FourCC 0x00000001`
  * `.bFixedSizeSamples`: `1`
  * `.bTemporalCompression`: `0`
  * `.lSampleSize`: `4`
  * `.cbFormat`: `18`
  * `WAVEFORMATEX`:
   * `.wFormatTag`: `1`
   * `.nChannels`: `2`
   * `.nSamplesPerSec`: `11025`
   * `.nAvgBytesPerSec: `44100`
   * `.nBlockAlign`: `4`
   * `.wBitsPerSample`: `16`
   * `.cbSize`: `0`
 * `AUDIO_STREAM_CONFIG_CAPS`:
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 02 00 00 00 01 00 00 00 08 00 00 00 10 00 00 00 08 00 00 00 11 2B 00 00 44 AC 00 00 11 2B 00 00`
  * `.MinimumChannels`: `1`
  * `.MaximumChannels`: `2`
  * `.ChannelsGranularity`: `1`
  * `.MinimumBitsPerSample`: `8`
  * `.MaximumBitsPerSample`: `16`
  * `.BitsPerSampleGranularity`: `8`
  * `.MinimumSampleFrequency`: `11025`
  * `.MaximumSampleFrequency`: `44100`
  * `.SampleFrequencyGranularity`: `11025`

#### Capability: 8

 * `AM_MEDIA_TYPE`:
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 00 00 02 00 00 00 81 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 00 00 12 00 00 00 E8 D3 61 00`
  * Format Data: `01 00 01 00 11 2B 00 00 22 56 00 00 02 00 10 00 00 00`
  * `.subtype`: `FourCC 0x00000001`
  * `.bFixedSizeSamples`: `1`
  * `.bTemporalCompression`: `0`
  * `.lSampleSize`: `2`
  * `.cbFormat`: `18`
  * `WAVEFORMATEX`:
   * `.wFormatTag`: `1`
   * `.nChannels`: `1`
   * `.nSamplesPerSec`: `11025`
   * `.nAvgBytesPerSec: `22050`
   * `.nBlockAlign`: `2`
   * `.wBitsPerSample`: `16`
   * `.cbSize`: `0`
 * `AUDIO_STREAM_CONFIG_CAPS`:
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 02 00 00 00 01 00 00 00 08 00 00 00 10 00 00 00 08 00 00 00 11 2B 00 00 44 AC 00 00 11 2B 00 00`
  * `.MinimumChannels`: `1`
  * `.MaximumChannels`: `2`
  * `.ChannelsGranularity`: `1`
  * `.MinimumBitsPerSample`: `8`
  * `.MaximumBitsPerSample`: `16`
  * `.BitsPerSampleGranularity`: `8`
  * `.MinimumSampleFrequency`: `11025`
  * `.MaximumSampleFrequency`: `44100`
  * `.SampleFrequencyGranularity`: `11025`

#### Capability: 9

 * `AM_MEDIA_TYPE`:
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 00 00 04 00 00 00 81 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 00 00 12 00 00 00 C8 D3 61 00`
  * Format Data: `01 00 02 00 40 1F 00 00 00 7D 00 00 04 00 10 00 00 00`
  * `.subtype`: `FourCC 0x00000001`
  * `.bFixedSizeSamples`: `1`
  * `.bTemporalCompression`: `0`
  * `.lSampleSize`: `4`
  * `.cbFormat`: `18`
  * `WAVEFORMATEX`:
   * `.wFormatTag`: `1`
   * `.nChannels`: `2`
   * `.nSamplesPerSec`: `8000`
   * `.nAvgBytesPerSec: `32000`
   * `.nBlockAlign`: `4`
   * `.wBitsPerSample`: `16`
   * `.cbSize`: `0`
 * `AUDIO_STREAM_CONFIG_CAPS`:
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 02 00 00 00 01 00 00 00 08 00 00 00 10 00 00 00 08 00 00 00 11 2B 00 00 44 AC 00 00 11 2B 00 00`
  * `.MinimumChannels`: `1`
  * `.MaximumChannels`: `2`
  * `.ChannelsGranularity`: `1`
  * `.MinimumBitsPerSample`: `8`
  * `.MaximumBitsPerSample`: `16`
  * `.BitsPerSampleGranularity`: `8`
  * `.MinimumSampleFrequency`: `11025`
  * `.MaximumSampleFrequency`: `44100`
  * `.SampleFrequencyGranularity`: `11025`

#### Capability: 10

 * `AM_MEDIA_TYPE`:
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 00 00 02 00 00 00 81 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 00 00 12 00 00 00 E8 D3 61 00`
  * Format Data: `01 00 01 00 40 1F 00 00 80 3E 00 00 02 00 10 00 00 00`
  * `.subtype`: `FourCC 0x00000001`
  * `.bFixedSizeSamples`: `1`
  * `.bTemporalCompression`: `0`
  * `.lSampleSize`: `2`
  * `.cbFormat`: `18`
  * `WAVEFORMATEX`:
   * `.wFormatTag`: `1`
   * `.nChannels`: `1`
   * `.nSamplesPerSec`: `8000`
   * `.nAvgBytesPerSec: `16000`
   * `.nBlockAlign`: `2`
   * `.wBitsPerSample`: `16`
   * `.cbSize`: `0`
 * `AUDIO_STREAM_CONFIG_CAPS`:
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 02 00 00 00 01 00 00 00 08 00 00 00 10 00 00 00 08 00 00 00 11 2B 00 00 44 AC 00 00 11 2B 00 00`
  * `.MinimumChannels`: `1`
  * `.MaximumChannels`: `2`
  * `.ChannelsGranularity`: `1`
  * `.MinimumBitsPerSample`: `8`
  * `.MaximumBitsPerSample`: `16`
  * `.BitsPerSampleGranularity`: `8`
  * `.MinimumSampleFrequency`: `11025`
  * `.MaximumSampleFrequency`: `44100`
  * `.SampleFrequencyGranularity`: `11025`

#### Capability: 11

 * `AM_MEDIA_TYPE`:
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 00 00 02 00 00 00 81 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 00 00 12 00 00 00 C8 D3 61 00`
  * Format Data: `01 00 02 00 44 AC 00 00 88 58 01 00 02 00 08 00 00 00`
  * `.subtype`: `FourCC 0x00000001`
  * `.bFixedSizeSamples`: `1`
  * `.bTemporalCompression`: `0`
  * `.lSampleSize`: `2`
  * `.cbFormat`: `18`
  * `WAVEFORMATEX`:
   * `.wFormatTag`: `1`
   * `.nChannels`: `2`
   * `.nSamplesPerSec`: `44100`
   * `.nAvgBytesPerSec: `88200`
   * `.nBlockAlign`: `2`
   * `.wBitsPerSample`: `8`
   * `.cbSize`: `0`
 * `AUDIO_STREAM_CONFIG_CAPS`:
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 02 00 00 00 01 00 00 00 08 00 00 00 10 00 00 00 08 00 00 00 11 2B 00 00 44 AC 00 00 11 2B 00 00`
  * `.MinimumChannels`: `1`
  * `.MaximumChannels`: `2`
  * `.ChannelsGranularity`: `1`
  * `.MinimumBitsPerSample`: `8`
  * `.MaximumBitsPerSample`: `16`
  * `.BitsPerSampleGranularity`: `8`
  * `.MinimumSampleFrequency`: `11025`
  * `.MaximumSampleFrequency`: `44100`
  * `.SampleFrequencyGranularity`: `11025`

#### Capability: 12

 * `AM_MEDIA_TYPE`:
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 00 00 01 00 00 00 81 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 00 00 12 00 00 00 E8 D3 61 00`
  * Format Data: `01 00 01 00 44 AC 00 00 44 AC 00 00 01 00 08 00 00 00`
  * `.subtype`: `FourCC 0x00000001`
  * `.bFixedSizeSamples`: `1`
  * `.bTemporalCompression`: `0`
  * `.lSampleSize`: `1`
  * `.cbFormat`: `18`
  * `WAVEFORMATEX`:
   * `.wFormatTag`: `1`
   * `.nChannels`: `1`
   * `.nSamplesPerSec`: `44100`
   * `.nAvgBytesPerSec: `44100`
   * `.nBlockAlign`: `1`
   * `.wBitsPerSample`: `8`
   * `.cbSize`: `0`
 * `AUDIO_STREAM_CONFIG_CAPS`:
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 02 00 00 00 01 00 00 00 08 00 00 00 10 00 00 00 08 00 00 00 11 2B 00 00 44 AC 00 00 11 2B 00 00`
  * `.MinimumChannels`: `1`
  * `.MaximumChannels`: `2`
  * `.ChannelsGranularity`: `1`
  * `.MinimumBitsPerSample`: `8`
  * `.MaximumBitsPerSample`: `16`
  * `.BitsPerSampleGranularity`: `8`
  * `.MinimumSampleFrequency`: `11025`
  * `.MaximumSampleFrequency`: `44100`
  * `.SampleFrequencyGranularity`: `11025`

#### Capability: 13

 * `AM_MEDIA_TYPE`:
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 00 00 02 00 00 00 81 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 00 00 12 00 00 00 C8 D3 61 00`
  * Format Data: `01 00 02 00 22 56 00 00 44 AC 00 00 02 00 08 00 00 00`
  * `.subtype`: `FourCC 0x00000001`
  * `.bFixedSizeSamples`: `1`
  * `.bTemporalCompression`: `0`
  * `.lSampleSize`: `2`
  * `.cbFormat`: `18`
  * `WAVEFORMATEX`:
   * `.wFormatTag`: `1`
   * `.nChannels`: `2`
   * `.nSamplesPerSec`: `22050`
   * `.nAvgBytesPerSec: `44100`
   * `.nBlockAlign`: `2`
   * `.wBitsPerSample`: `8`
   * `.cbSize`: `0`
 * `AUDIO_STREAM_CONFIG_CAPS`:
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 02 00 00 00 01 00 00 00 08 00 00 00 10 00 00 00 08 00 00 00 11 2B 00 00 44 AC 00 00 11 2B 00 00`
  * `.MinimumChannels`: `1`
  * `.MaximumChannels`: `2`
  * `.ChannelsGranularity`: `1`
  * `.MinimumBitsPerSample`: `8`
  * `.MaximumBitsPerSample`: `16`
  * `.BitsPerSampleGranularity`: `8`
  * `.MinimumSampleFrequency`: `11025`
  * `.MaximumSampleFrequency`: `44100`
  * `.SampleFrequencyGranularity`: `11025`

#### Capability: 14

 * `AM_MEDIA_TYPE`:
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 00 00 01 00 00 00 81 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 00 00 12 00 00 00 E8 D3 61 00`
  * Format Data: `01 00 01 00 22 56 00 00 22 56 00 00 01 00 08 00 00 00`
  * `.subtype`: `FourCC 0x00000001`
  * `.bFixedSizeSamples`: `1`
  * `.bTemporalCompression`: `0`
  * `.lSampleSize`: `1`
  * `.cbFormat`: `18`
  * `WAVEFORMATEX`:
   * `.wFormatTag`: `1`
   * `.nChannels`: `1`
   * `.nSamplesPerSec`: `22050`
   * `.nAvgBytesPerSec: `22050`
   * `.nBlockAlign`: `1`
   * `.wBitsPerSample`: `8`
   * `.cbSize`: `0`
 * `AUDIO_STREAM_CONFIG_CAPS`:
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 02 00 00 00 01 00 00 00 08 00 00 00 10 00 00 00 08 00 00 00 11 2B 00 00 44 AC 00 00 11 2B 00 00`
  * `.MinimumChannels`: `1`
  * `.MaximumChannels`: `2`
  * `.ChannelsGranularity`: `1`
  * `.MinimumBitsPerSample`: `8`
  * `.MaximumBitsPerSample`: `16`
  * `.BitsPerSampleGranularity`: `8`
  * `.MinimumSampleFrequency`: `11025`
  * `.MaximumSampleFrequency`: `44100`
  * `.SampleFrequencyGranularity`: `11025`

#### Capability: 15

 * `AM_MEDIA_TYPE`:
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 00 00 02 00 00 00 81 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 00 00 12 00 00 00 C8 D3 61 00`
  * Format Data: `01 00 02 00 11 2B 00 00 22 56 00 00 02 00 08 00 00 00`
  * `.subtype`: `FourCC 0x00000001`
  * `.bFixedSizeSamples`: `1`
  * `.bTemporalCompression`: `0`
  * `.lSampleSize`: `2`
  * `.cbFormat`: `18`
  * `WAVEFORMATEX`:
   * `.wFormatTag`: `1`
   * `.nChannels`: `2`
   * `.nSamplesPerSec`: `11025`
   * `.nAvgBytesPerSec: `22050`
   * `.nBlockAlign`: `2`
   * `.wBitsPerSample`: `8`
   * `.cbSize`: `0`
 * `AUDIO_STREAM_CONFIG_CAPS`:
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 02 00 00 00 01 00 00 00 08 00 00 00 10 00 00 00 08 00 00 00 11 2B 00 00 44 AC 00 00 11 2B 00 00`
  * `.MinimumChannels`: `1`
  * `.MaximumChannels`: `2`
  * `.ChannelsGranularity`: `1`
  * `.MinimumBitsPerSample`: `8`
  * `.MaximumBitsPerSample`: `16`
  * `.BitsPerSampleGranularity`: `8`
  * `.MinimumSampleFrequency`: `11025`
  * `.MaximumSampleFrequency`: `44100`
  * `.SampleFrequencyGranularity`: `11025`

#### Capability: 16

 * `AM_MEDIA_TYPE`:
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 00 00 01 00 00 00 81 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 00 00 12 00 00 00 E8 D3 61 00`
  * Format Data: `01 00 01 00 11 2B 00 00 11 2B 00 00 01 00 08 00 00 00`
  * `.subtype`: `FourCC 0x00000001`
  * `.bFixedSizeSamples`: `1`
  * `.bTemporalCompression`: `0`
  * `.lSampleSize`: `1`
  * `.cbFormat`: `18`
  * `WAVEFORMATEX`:
   * `.wFormatTag`: `1`
   * `.nChannels`: `1`
   * `.nSamplesPerSec`: `11025`
   * `.nAvgBytesPerSec: `11025`
   * `.nBlockAlign`: `1`
   * `.wBitsPerSample`: `8`
   * `.cbSize`: `0`
 * `AUDIO_STREAM_CONFIG_CAPS`:
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 02 00 00 00 01 00 00 00 08 00 00 00 10 00 00 00 08 00 00 00 11 2B 00 00 44 AC 00 00 11 2B 00 00`
  * `.MinimumChannels`: `1`
  * `.MaximumChannels`: `2`
  * `.ChannelsGranularity`: `1`
  * `.MinimumBitsPerSample`: `8`
  * `.MaximumBitsPerSample`: `16`
  * `.BitsPerSampleGranularity`: `8`
  * `.MinimumSampleFrequency`: `11025`
  * `.MaximumSampleFrequency`: `44100`
  * `.SampleFrequencyGranularity`: `11025`

#### Capability: 17

 * `AM_MEDIA_TYPE`:
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 00 00 02 00 00 00 81 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 00 00 12 00 00 00 C8 D3 61 00`
  * Format Data: `01 00 02 00 40 1F 00 00 80 3E 00 00 02 00 08 00 00 00`
  * `.subtype`: `FourCC 0x00000001`
  * `.bFixedSizeSamples`: `1`
  * `.bTemporalCompression`: `0`
  * `.lSampleSize`: `2`
  * `.cbFormat`: `18`
  * `WAVEFORMATEX`:
   * `.wFormatTag`: `1`
   * `.nChannels`: `2`
   * `.nSamplesPerSec`: `8000`
   * `.nAvgBytesPerSec: `16000`
   * `.nBlockAlign`: `2`
   * `.wBitsPerSample`: `8`
   * `.cbSize`: `0`
 * `AUDIO_STREAM_CONFIG_CAPS`:
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 02 00 00 00 01 00 00 00 08 00 00 00 10 00 00 00 08 00 00 00 11 2B 00 00 44 AC 00 00 11 2B 00 00`
  * `.MinimumChannels`: `1`
  * `.MaximumChannels`: `2`
  * `.ChannelsGranularity`: `1`
  * `.MinimumBitsPerSample`: `8`
  * `.MaximumBitsPerSample`: `16`
  * `.BitsPerSampleGranularity`: `8`
  * `.MinimumSampleFrequency`: `11025`
  * `.MaximumSampleFrequency`: `44100`
  * `.SampleFrequencyGranularity`: `11025`

#### Capability: 18

 * `AM_MEDIA_TYPE`:
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 00 00 01 00 00 00 81 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 00 00 12 00 00 00 E8 D3 61 00`
  * Format Data: `01 00 01 00 40 1F 00 00 40 1F 00 00 01 00 08 00 00 00`
  * `.subtype`: `FourCC 0x00000001`
  * `.bFixedSizeSamples`: `1`
  * `.bTemporalCompression`: `0`
  * `.lSampleSize`: `1`
  * `.cbFormat`: `18`
  * `WAVEFORMATEX`:
   * `.wFormatTag`: `1`
   * `.nChannels`: `1`
   * `.nSamplesPerSec`: `8000`
   * `.nAvgBytesPerSec: `8000`
   * `.nBlockAlign`: `1`
   * `.wBitsPerSample`: `8`
   * `.cbSize`: `0`
 * `AUDIO_STREAM_CONFIG_CAPS`:
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 02 00 00 00 01 00 00 00 08 00 00 00 10 00 00 00 08 00 00 00 11 2B 00 00 44 AC 00 00 11 2B 00 00`
  * `.MinimumChannels`: `1`
  * `.MaximumChannels`: `2`
  * `.ChannelsGranularity`: `1`
  * `.MinimumBitsPerSample`: `8`
  * `.MaximumBitsPerSample`: `16`
  * `.BitsPerSampleGranularity`: `8`
  * `.MinimumSampleFrequency`: `11025`
  * `.MaximumSampleFrequency`: `44100`
  * `.SampleFrequencyGranularity`: `11025`

#### Capability: 19

 * `AM_MEDIA_TYPE`:
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 00 00 04 00 00 00 81 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 00 00 12 00 00 00 C8 D3 61 00`
  * Format Data: `01 00 02 00 80 BB 00 00 00 EE 02 00 04 00 10 00 00 00`
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
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 02 00 00 00 01 00 00 00 08 00 00 00 10 00 00 00 08 00 00 00 11 2B 00 00 44 AC 00 00 11 2B 00 00`
  * `.MinimumChannels`: `1`
  * `.MaximumChannels`: `2`
  * `.ChannelsGranularity`: `1`
  * `.MinimumBitsPerSample`: `8`
  * `.MaximumBitsPerSample`: `16`
  * `.BitsPerSampleGranularity`: `8`
  * `.MinimumSampleFrequency`: `11025`
  * `.MaximumSampleFrequency`: `44100`
  * `.SampleFrequencyGranularity`: `11025`

#### Capability: 20

 * `AM_MEDIA_TYPE`:
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 00 00 02 00 00 00 81 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 00 00 12 00 00 00 E8 D3 61 00`
  * Format Data: `01 00 01 00 80 BB 00 00 00 77 01 00 02 00 10 00 00 00`
  * `.subtype`: `FourCC 0x00000001`
  * `.bFixedSizeSamples`: `1`
  * `.bTemporalCompression`: `0`
  * `.lSampleSize`: `2`
  * `.cbFormat`: `18`
  * `WAVEFORMATEX`:
   * `.wFormatTag`: `1`
   * `.nChannels`: `1`
   * `.nSamplesPerSec`: `48000`
   * `.nAvgBytesPerSec: `96000`
   * `.nBlockAlign`: `2`
   * `.wBitsPerSample`: `16`
   * `.cbSize`: `0`
 * `AUDIO_STREAM_CONFIG_CAPS`:
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 02 00 00 00 01 00 00 00 08 00 00 00 10 00 00 00 08 00 00 00 11 2B 00 00 44 AC 00 00 11 2B 00 00`
  * `.MinimumChannels`: `1`
  * `.MaximumChannels`: `2`
  * `.ChannelsGranularity`: `1`
  * `.MinimumBitsPerSample`: `8`
  * `.MaximumBitsPerSample`: `16`
  * `.BitsPerSampleGranularity`: `8`
  * `.MinimumSampleFrequency`: `11025`
  * `.MaximumSampleFrequency`: `44100`
  * `.SampleFrequencyGranularity`: `11025`

#### Capability: 21

 * `AM_MEDIA_TYPE`:
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 00 00 04 00 00 00 81 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 00 00 12 00 00 00 C8 D3 61 00`
  * Format Data: `01 00 02 00 00 77 01 00 00 DC 05 00 04 00 10 00 00 00`
  * `.subtype`: `FourCC 0x00000001`
  * `.bFixedSizeSamples`: `1`
  * `.bTemporalCompression`: `0`
  * `.lSampleSize`: `4`
  * `.cbFormat`: `18`
  * `WAVEFORMATEX`:
   * `.wFormatTag`: `1`
   * `.nChannels`: `2`
   * `.nSamplesPerSec`: `96000`
   * `.nAvgBytesPerSec: `384000`
   * `.nBlockAlign`: `4`
   * `.wBitsPerSample`: `16`
   * `.cbSize`: `0`
 * `AUDIO_STREAM_CONFIG_CAPS`:
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 02 00 00 00 01 00 00 00 08 00 00 00 10 00 00 00 08 00 00 00 11 2B 00 00 44 AC 00 00 11 2B 00 00`
  * `.MinimumChannels`: `1`
  * `.MaximumChannels`: `2`
  * `.ChannelsGranularity`: `1`
  * `.MinimumBitsPerSample`: `8`
  * `.MaximumBitsPerSample`: `16`
  * `.BitsPerSampleGranularity`: `8`
  * `.MinimumSampleFrequency`: `11025`
  * `.MaximumSampleFrequency`: `44100`
  * `.SampleFrequencyGranularity`: `11025`

#### Capability: 22

 * `AM_MEDIA_TYPE`:
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 00 00 02 00 00 00 81 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 00 00 12 00 00 00 E8 D3 61 00`
  * Format Data: `01 00 01 00 00 77 01 00 00 EE 02 00 02 00 10 00 00 00`
  * `.subtype`: `FourCC 0x00000001`
  * `.bFixedSizeSamples`: `1`
  * `.bTemporalCompression`: `0`
  * `.lSampleSize`: `2`
  * `.cbFormat`: `18`
  * `WAVEFORMATEX`:
   * `.wFormatTag`: `1`
   * `.nChannels`: `1`
   * `.nSamplesPerSec`: `96000`
   * `.nAvgBytesPerSec: `192000`
   * `.nBlockAlign`: `2`
   * `.wBitsPerSample`: `16`
   * `.cbSize`: `0`
 * `AUDIO_STREAM_CONFIG_CAPS`:
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 02 00 00 00 01 00 00 00 08 00 00 00 10 00 00 00 08 00 00 00 11 2B 00 00 44 AC 00 00 11 2B 00 00`
  * `.MinimumChannels`: `1`
  * `.MaximumChannels`: `2`
  * `.ChannelsGranularity`: `1`
  * `.MinimumBitsPerSample`: `8`
  * `.MaximumBitsPerSample`: `16`
  * `.BitsPerSampleGranularity`: `8`
  * `.MinimumSampleFrequency`: `11025`
  * `.MaximumSampleFrequency`: `44100`
  * `.SampleFrequencyGranularity`: `11025`

Interfaces:

  * `IKsPropertySet`
  * `IQualityControl`
  * `IAMBufferNegotiation`
  * `IAMStreamConfig`
  * `IAMStreamControl`

### Pin: Master Volume

 * Direction: `PINDIR_INPUT`
Interfaces:

  * `IQualityControl`

## Device: Line In (Realtek AC'97 Audio)

 * Moniker Display Name: `@device:cm:{33D9A762-90C8-11D0-BD43-00A0C911CE86}\Line In (Realtek AC'97 Audio)`

Interfaces:

  * `ISpecifyPropertyPages`
  * `IAMFilterMiscFlags`

Property Pages:

  * `{2CA8CA52-3C3F-11D2-B73D-00C04FB6BD3D}` - `CLSID_AudioInputMixerProperties`, AudioInputMixer Property Page

### Pin: Capture

 * `AMPROPSETID_Pin`, `AMPROPERTY_PIN_CATEGORY`: `{FB6C4281-0353-11D1-905F-0000C0CC16BA} PIN_CATEGORY_CAPTURE`
 * Capabilities:
  * Count: `23`
  * Structure Size: `52` (expected `52`)

#### Capability: 0

 * `AM_MEDIA_TYPE`:
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 00 00 04 00 00 00 81 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 00 00 12 00 00 00 C8 D3 61 00`
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
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 02 00 00 00 01 00 00 00 08 00 00 00 10 00 00 00 08 00 00 00 11 2B 00 00 44 AC 00 00 11 2B 00 00`
  * `.MinimumChannels`: `1`
  * `.MaximumChannels`: `2`
  * `.ChannelsGranularity`: `1`
  * `.MinimumBitsPerSample`: `8`
  * `.MaximumBitsPerSample`: `16`
  * `.BitsPerSampleGranularity`: `8`
  * `.MinimumSampleFrequency`: `11025`
  * `.MaximumSampleFrequency`: `44100`
  * `.SampleFrequencyGranularity`: `11025`

#### Capability: 1

 * `AM_MEDIA_TYPE`:
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 00 00 04 00 00 00 81 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 00 00 12 00 00 00 C8 D3 61 00`
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
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 02 00 00 00 01 00 00 00 08 00 00 00 10 00 00 00 08 00 00 00 11 2B 00 00 44 AC 00 00 11 2B 00 00`
  * `.MinimumChannels`: `1`
  * `.MaximumChannels`: `2`
  * `.ChannelsGranularity`: `1`
  * `.MinimumBitsPerSample`: `8`
  * `.MaximumBitsPerSample`: `16`
  * `.BitsPerSampleGranularity`: `8`
  * `.MinimumSampleFrequency`: `11025`
  * `.MaximumSampleFrequency`: `44100`
  * `.SampleFrequencyGranularity`: `11025`

#### Capability: 2

 * `AM_MEDIA_TYPE`:
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 00 00 02 00 00 00 81 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 00 00 12 00 00 00 C8 D3 61 00`
  * Format Data: `01 00 01 00 44 AC 00 00 88 58 01 00 02 00 10 00 00 00`
  * `.subtype`: `FourCC 0x00000001`
  * `.bFixedSizeSamples`: `1`
  * `.bTemporalCompression`: `0`
  * `.lSampleSize`: `2`
  * `.cbFormat`: `18`
  * `WAVEFORMATEX`:
   * `.wFormatTag`: `1`
   * `.nChannels`: `1`
   * `.nSamplesPerSec`: `44100`
   * `.nAvgBytesPerSec: `88200`
   * `.nBlockAlign`: `2`
   * `.wBitsPerSample`: `16`
   * `.cbSize`: `0`
 * `AUDIO_STREAM_CONFIG_CAPS`:
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 02 00 00 00 01 00 00 00 08 00 00 00 10 00 00 00 08 00 00 00 11 2B 00 00 44 AC 00 00 11 2B 00 00`
  * `.MinimumChannels`: `1`
  * `.MaximumChannels`: `2`
  * `.ChannelsGranularity`: `1`
  * `.MinimumBitsPerSample`: `8`
  * `.MaximumBitsPerSample`: `16`
  * `.BitsPerSampleGranularity`: `8`
  * `.MinimumSampleFrequency`: `11025`
  * `.MaximumSampleFrequency`: `44100`
  * `.SampleFrequencyGranularity`: `11025`

#### Capability: 3

 * `AM_MEDIA_TYPE`:
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 00 00 04 00 00 00 81 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 00 00 12 00 00 00 C8 D3 61 00`
  * Format Data: `01 00 02 00 00 7D 00 00 00 F4 01 00 04 00 10 00 00 00`
  * `.subtype`: `FourCC 0x00000001`
  * `.bFixedSizeSamples`: `1`
  * `.bTemporalCompression`: `0`
  * `.lSampleSize`: `4`
  * `.cbFormat`: `18`
  * `WAVEFORMATEX`:
   * `.wFormatTag`: `1`
   * `.nChannels`: `2`
   * `.nSamplesPerSec`: `32000`
   * `.nAvgBytesPerSec: `128000`
   * `.nBlockAlign`: `4`
   * `.wBitsPerSample`: `16`
   * `.cbSize`: `0`
 * `AUDIO_STREAM_CONFIG_CAPS`:
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 02 00 00 00 01 00 00 00 08 00 00 00 10 00 00 00 08 00 00 00 11 2B 00 00 44 AC 00 00 11 2B 00 00`
  * `.MinimumChannels`: `1`
  * `.MaximumChannels`: `2`
  * `.ChannelsGranularity`: `1`
  * `.MinimumBitsPerSample`: `8`
  * `.MaximumBitsPerSample`: `16`
  * `.BitsPerSampleGranularity`: `8`
  * `.MinimumSampleFrequency`: `11025`
  * `.MaximumSampleFrequency`: `44100`
  * `.SampleFrequencyGranularity`: `11025`

#### Capability: 4

 * `AM_MEDIA_TYPE`:
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 00 00 02 00 00 00 81 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 00 00 12 00 00 00 C8 D3 61 00`
  * Format Data: `01 00 01 00 00 7D 00 00 00 FA 00 00 02 00 10 00 00 00`
  * `.subtype`: `FourCC 0x00000001`
  * `.bFixedSizeSamples`: `1`
  * `.bTemporalCompression`: `0`
  * `.lSampleSize`: `2`
  * `.cbFormat`: `18`
  * `WAVEFORMATEX`:
   * `.wFormatTag`: `1`
   * `.nChannels`: `1`
   * `.nSamplesPerSec`: `32000`
   * `.nAvgBytesPerSec: `64000`
   * `.nBlockAlign`: `2`
   * `.wBitsPerSample`: `16`
   * `.cbSize`: `0`
 * `AUDIO_STREAM_CONFIG_CAPS`:
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 02 00 00 00 01 00 00 00 08 00 00 00 10 00 00 00 08 00 00 00 11 2B 00 00 44 AC 00 00 11 2B 00 00`
  * `.MinimumChannels`: `1`
  * `.MaximumChannels`: `2`
  * `.ChannelsGranularity`: `1`
  * `.MinimumBitsPerSample`: `8`
  * `.MaximumBitsPerSample`: `16`
  * `.BitsPerSampleGranularity`: `8`
  * `.MinimumSampleFrequency`: `11025`
  * `.MaximumSampleFrequency`: `44100`
  * `.SampleFrequencyGranularity`: `11025`

#### Capability: 5

 * `AM_MEDIA_TYPE`:
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 00 00 04 00 00 00 81 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 00 00 12 00 00 00 C8 D3 61 00`
  * Format Data: `01 00 02 00 22 56 00 00 88 58 01 00 04 00 10 00 00 00`
  * `.subtype`: `FourCC 0x00000001`
  * `.bFixedSizeSamples`: `1`
  * `.bTemporalCompression`: `0`
  * `.lSampleSize`: `4`
  * `.cbFormat`: `18`
  * `WAVEFORMATEX`:
   * `.wFormatTag`: `1`
   * `.nChannels`: `2`
   * `.nSamplesPerSec`: `22050`
   * `.nAvgBytesPerSec: `88200`
   * `.nBlockAlign`: `4`
   * `.wBitsPerSample`: `16`
   * `.cbSize`: `0`
 * `AUDIO_STREAM_CONFIG_CAPS`:
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 02 00 00 00 01 00 00 00 08 00 00 00 10 00 00 00 08 00 00 00 11 2B 00 00 44 AC 00 00 11 2B 00 00`
  * `.MinimumChannels`: `1`
  * `.MaximumChannels`: `2`
  * `.ChannelsGranularity`: `1`
  * `.MinimumBitsPerSample`: `8`
  * `.MaximumBitsPerSample`: `16`
  * `.BitsPerSampleGranularity`: `8`
  * `.MinimumSampleFrequency`: `11025`
  * `.MaximumSampleFrequency`: `44100`
  * `.SampleFrequencyGranularity`: `11025`

#### Capability: 6

 * `AM_MEDIA_TYPE`:
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 00 00 02 00 00 00 81 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 00 00 12 00 00 00 C8 D3 61 00`
  * Format Data: `01 00 01 00 22 56 00 00 44 AC 00 00 02 00 10 00 00 00`
  * `.subtype`: `FourCC 0x00000001`
  * `.bFixedSizeSamples`: `1`
  * `.bTemporalCompression`: `0`
  * `.lSampleSize`: `2`
  * `.cbFormat`: `18`
  * `WAVEFORMATEX`:
   * `.wFormatTag`: `1`
   * `.nChannels`: `1`
   * `.nSamplesPerSec`: `22050`
   * `.nAvgBytesPerSec: `44100`
   * `.nBlockAlign`: `2`
   * `.wBitsPerSample`: `16`
   * `.cbSize`: `0`
 * `AUDIO_STREAM_CONFIG_CAPS`:
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 02 00 00 00 01 00 00 00 08 00 00 00 10 00 00 00 08 00 00 00 11 2B 00 00 44 AC 00 00 11 2B 00 00`
  * `.MinimumChannels`: `1`
  * `.MaximumChannels`: `2`
  * `.ChannelsGranularity`: `1`
  * `.MinimumBitsPerSample`: `8`
  * `.MaximumBitsPerSample`: `16`
  * `.BitsPerSampleGranularity`: `8`
  * `.MinimumSampleFrequency`: `11025`
  * `.MaximumSampleFrequency`: `44100`
  * `.SampleFrequencyGranularity`: `11025`

#### Capability: 7

 * `AM_MEDIA_TYPE`:
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 00 00 04 00 00 00 81 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 00 00 12 00 00 00 C8 D3 61 00`
  * Format Data: `01 00 02 00 11 2B 00 00 44 AC 00 00 04 00 10 00 00 00`
  * `.subtype`: `FourCC 0x00000001`
  * `.bFixedSizeSamples`: `1`
  * `.bTemporalCompression`: `0`
  * `.lSampleSize`: `4`
  * `.cbFormat`: `18`
  * `WAVEFORMATEX`:
   * `.wFormatTag`: `1`
   * `.nChannels`: `2`
   * `.nSamplesPerSec`: `11025`
   * `.nAvgBytesPerSec: `44100`
   * `.nBlockAlign`: `4`
   * `.wBitsPerSample`: `16`
   * `.cbSize`: `0`
 * `AUDIO_STREAM_CONFIG_CAPS`:
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 02 00 00 00 01 00 00 00 08 00 00 00 10 00 00 00 08 00 00 00 11 2B 00 00 44 AC 00 00 11 2B 00 00`
  * `.MinimumChannels`: `1`
  * `.MaximumChannels`: `2`
  * `.ChannelsGranularity`: `1`
  * `.MinimumBitsPerSample`: `8`
  * `.MaximumBitsPerSample`: `16`
  * `.BitsPerSampleGranularity`: `8`
  * `.MinimumSampleFrequency`: `11025`
  * `.MaximumSampleFrequency`: `44100`
  * `.SampleFrequencyGranularity`: `11025`

#### Capability: 8

 * `AM_MEDIA_TYPE`:
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 00 00 02 00 00 00 81 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 00 00 12 00 00 00 C8 D3 61 00`
  * Format Data: `01 00 01 00 11 2B 00 00 22 56 00 00 02 00 10 00 00 00`
  * `.subtype`: `FourCC 0x00000001`
  * `.bFixedSizeSamples`: `1`
  * `.bTemporalCompression`: `0`
  * `.lSampleSize`: `2`
  * `.cbFormat`: `18`
  * `WAVEFORMATEX`:
   * `.wFormatTag`: `1`
   * `.nChannels`: `1`
   * `.nSamplesPerSec`: `11025`
   * `.nAvgBytesPerSec: `22050`
   * `.nBlockAlign`: `2`
   * `.wBitsPerSample`: `16`
   * `.cbSize`: `0`
 * `AUDIO_STREAM_CONFIG_CAPS`:
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 02 00 00 00 01 00 00 00 08 00 00 00 10 00 00 00 08 00 00 00 11 2B 00 00 44 AC 00 00 11 2B 00 00`
  * `.MinimumChannels`: `1`
  * `.MaximumChannels`: `2`
  * `.ChannelsGranularity`: `1`
  * `.MinimumBitsPerSample`: `8`
  * `.MaximumBitsPerSample`: `16`
  * `.BitsPerSampleGranularity`: `8`
  * `.MinimumSampleFrequency`: `11025`
  * `.MaximumSampleFrequency`: `44100`
  * `.SampleFrequencyGranularity`: `11025`

#### Capability: 9

 * `AM_MEDIA_TYPE`:
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 00 00 04 00 00 00 81 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 00 00 12 00 00 00 C8 D3 61 00`
  * Format Data: `01 00 02 00 40 1F 00 00 00 7D 00 00 04 00 10 00 00 00`
  * `.subtype`: `FourCC 0x00000001`
  * `.bFixedSizeSamples`: `1`
  * `.bTemporalCompression`: `0`
  * `.lSampleSize`: `4`
  * `.cbFormat`: `18`
  * `WAVEFORMATEX`:
   * `.wFormatTag`: `1`
   * `.nChannels`: `2`
   * `.nSamplesPerSec`: `8000`
   * `.nAvgBytesPerSec: `32000`
   * `.nBlockAlign`: `4`
   * `.wBitsPerSample`: `16`
   * `.cbSize`: `0`
 * `AUDIO_STREAM_CONFIG_CAPS`:
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 02 00 00 00 01 00 00 00 08 00 00 00 10 00 00 00 08 00 00 00 11 2B 00 00 44 AC 00 00 11 2B 00 00`
  * `.MinimumChannels`: `1`
  * `.MaximumChannels`: `2`
  * `.ChannelsGranularity`: `1`
  * `.MinimumBitsPerSample`: `8`
  * `.MaximumBitsPerSample`: `16`
  * `.BitsPerSampleGranularity`: `8`
  * `.MinimumSampleFrequency`: `11025`
  * `.MaximumSampleFrequency`: `44100`
  * `.SampleFrequencyGranularity`: `11025`

#### Capability: 10

 * `AM_MEDIA_TYPE`:
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 00 00 02 00 00 00 81 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 00 00 12 00 00 00 C8 D3 61 00`
  * Format Data: `01 00 01 00 40 1F 00 00 80 3E 00 00 02 00 10 00 00 00`
  * `.subtype`: `FourCC 0x00000001`
  * `.bFixedSizeSamples`: `1`
  * `.bTemporalCompression`: `0`
  * `.lSampleSize`: `2`
  * `.cbFormat`: `18`
  * `WAVEFORMATEX`:
   * `.wFormatTag`: `1`
   * `.nChannels`: `1`
   * `.nSamplesPerSec`: `8000`
   * `.nAvgBytesPerSec: `16000`
   * `.nBlockAlign`: `2`
   * `.wBitsPerSample`: `16`
   * `.cbSize`: `0`
 * `AUDIO_STREAM_CONFIG_CAPS`:
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 02 00 00 00 01 00 00 00 08 00 00 00 10 00 00 00 08 00 00 00 11 2B 00 00 44 AC 00 00 11 2B 00 00`
  * `.MinimumChannels`: `1`
  * `.MaximumChannels`: `2`
  * `.ChannelsGranularity`: `1`
  * `.MinimumBitsPerSample`: `8`
  * `.MaximumBitsPerSample`: `16`
  * `.BitsPerSampleGranularity`: `8`
  * `.MinimumSampleFrequency`: `11025`
  * `.MaximumSampleFrequency`: `44100`
  * `.SampleFrequencyGranularity`: `11025`

#### Capability: 11

 * `AM_MEDIA_TYPE`:
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 00 00 02 00 00 00 81 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 00 00 12 00 00 00 C8 D3 61 00`
  * Format Data: `01 00 02 00 44 AC 00 00 88 58 01 00 02 00 08 00 00 00`
  * `.subtype`: `FourCC 0x00000001`
  * `.bFixedSizeSamples`: `1`
  * `.bTemporalCompression`: `0`
  * `.lSampleSize`: `2`
  * `.cbFormat`: `18`
  * `WAVEFORMATEX`:
   * `.wFormatTag`: `1`
   * `.nChannels`: `2`
   * `.nSamplesPerSec`: `44100`
   * `.nAvgBytesPerSec: `88200`
   * `.nBlockAlign`: `2`
   * `.wBitsPerSample`: `8`
   * `.cbSize`: `0`
 * `AUDIO_STREAM_CONFIG_CAPS`:
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 02 00 00 00 01 00 00 00 08 00 00 00 10 00 00 00 08 00 00 00 11 2B 00 00 44 AC 00 00 11 2B 00 00`
  * `.MinimumChannels`: `1`
  * `.MaximumChannels`: `2`
  * `.ChannelsGranularity`: `1`
  * `.MinimumBitsPerSample`: `8`
  * `.MaximumBitsPerSample`: `16`
  * `.BitsPerSampleGranularity`: `8`
  * `.MinimumSampleFrequency`: `11025`
  * `.MaximumSampleFrequency`: `44100`
  * `.SampleFrequencyGranularity`: `11025`

#### Capability: 12

 * `AM_MEDIA_TYPE`:
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 00 00 01 00 00 00 81 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 00 00 12 00 00 00 C8 D3 61 00`
  * Format Data: `01 00 01 00 44 AC 00 00 44 AC 00 00 01 00 08 00 00 00`
  * `.subtype`: `FourCC 0x00000001`
  * `.bFixedSizeSamples`: `1`
  * `.bTemporalCompression`: `0`
  * `.lSampleSize`: `1`
  * `.cbFormat`: `18`
  * `WAVEFORMATEX`:
   * `.wFormatTag`: `1`
   * `.nChannels`: `1`
   * `.nSamplesPerSec`: `44100`
   * `.nAvgBytesPerSec: `44100`
   * `.nBlockAlign`: `1`
   * `.wBitsPerSample`: `8`
   * `.cbSize`: `0`
 * `AUDIO_STREAM_CONFIG_CAPS`:
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 02 00 00 00 01 00 00 00 08 00 00 00 10 00 00 00 08 00 00 00 11 2B 00 00 44 AC 00 00 11 2B 00 00`
  * `.MinimumChannels`: `1`
  * `.MaximumChannels`: `2`
  * `.ChannelsGranularity`: `1`
  * `.MinimumBitsPerSample`: `8`
  * `.MaximumBitsPerSample`: `16`
  * `.BitsPerSampleGranularity`: `8`
  * `.MinimumSampleFrequency`: `11025`
  * `.MaximumSampleFrequency`: `44100`
  * `.SampleFrequencyGranularity`: `11025`

#### Capability: 13

 * `AM_MEDIA_TYPE`:
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 00 00 02 00 00 00 81 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 00 00 12 00 00 00 C8 D3 61 00`
  * Format Data: `01 00 02 00 22 56 00 00 44 AC 00 00 02 00 08 00 00 00`
  * `.subtype`: `FourCC 0x00000001`
  * `.bFixedSizeSamples`: `1`
  * `.bTemporalCompression`: `0`
  * `.lSampleSize`: `2`
  * `.cbFormat`: `18`
  * `WAVEFORMATEX`:
   * `.wFormatTag`: `1`
   * `.nChannels`: `2`
   * `.nSamplesPerSec`: `22050`
   * `.nAvgBytesPerSec: `44100`
   * `.nBlockAlign`: `2`
   * `.wBitsPerSample`: `8`
   * `.cbSize`: `0`
 * `AUDIO_STREAM_CONFIG_CAPS`:
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 02 00 00 00 01 00 00 00 08 00 00 00 10 00 00 00 08 00 00 00 11 2B 00 00 44 AC 00 00 11 2B 00 00`
  * `.MinimumChannels`: `1`
  * `.MaximumChannels`: `2`
  * `.ChannelsGranularity`: `1`
  * `.MinimumBitsPerSample`: `8`
  * `.MaximumBitsPerSample`: `16`
  * `.BitsPerSampleGranularity`: `8`
  * `.MinimumSampleFrequency`: `11025`
  * `.MaximumSampleFrequency`: `44100`
  * `.SampleFrequencyGranularity`: `11025`

#### Capability: 14

 * `AM_MEDIA_TYPE`:
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 00 00 01 00 00 00 81 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 00 00 12 00 00 00 C8 D3 61 00`
  * Format Data: `01 00 01 00 22 56 00 00 22 56 00 00 01 00 08 00 00 00`
  * `.subtype`: `FourCC 0x00000001`
  * `.bFixedSizeSamples`: `1`
  * `.bTemporalCompression`: `0`
  * `.lSampleSize`: `1`
  * `.cbFormat`: `18`
  * `WAVEFORMATEX`:
   * `.wFormatTag`: `1`
   * `.nChannels`: `1`
   * `.nSamplesPerSec`: `22050`
   * `.nAvgBytesPerSec: `22050`
   * `.nBlockAlign`: `1`
   * `.wBitsPerSample`: `8`
   * `.cbSize`: `0`
 * `AUDIO_STREAM_CONFIG_CAPS`:
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 02 00 00 00 01 00 00 00 08 00 00 00 10 00 00 00 08 00 00 00 11 2B 00 00 44 AC 00 00 11 2B 00 00`
  * `.MinimumChannels`: `1`
  * `.MaximumChannels`: `2`
  * `.ChannelsGranularity`: `1`
  * `.MinimumBitsPerSample`: `8`
  * `.MaximumBitsPerSample`: `16`
  * `.BitsPerSampleGranularity`: `8`
  * `.MinimumSampleFrequency`: `11025`
  * `.MaximumSampleFrequency`: `44100`
  * `.SampleFrequencyGranularity`: `11025`

#### Capability: 15

 * `AM_MEDIA_TYPE`:
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 00 00 02 00 00 00 81 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 00 00 12 00 00 00 C8 D3 61 00`
  * Format Data: `01 00 02 00 11 2B 00 00 22 56 00 00 02 00 08 00 00 00`
  * `.subtype`: `FourCC 0x00000001`
  * `.bFixedSizeSamples`: `1`
  * `.bTemporalCompression`: `0`
  * `.lSampleSize`: `2`
  * `.cbFormat`: `18`
  * `WAVEFORMATEX`:
   * `.wFormatTag`: `1`
   * `.nChannels`: `2`
   * `.nSamplesPerSec`: `11025`
   * `.nAvgBytesPerSec: `22050`
   * `.nBlockAlign`: `2`
   * `.wBitsPerSample`: `8`
   * `.cbSize`: `0`
 * `AUDIO_STREAM_CONFIG_CAPS`:
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 02 00 00 00 01 00 00 00 08 00 00 00 10 00 00 00 08 00 00 00 11 2B 00 00 44 AC 00 00 11 2B 00 00`
  * `.MinimumChannels`: `1`
  * `.MaximumChannels`: `2`
  * `.ChannelsGranularity`: `1`
  * `.MinimumBitsPerSample`: `8`
  * `.MaximumBitsPerSample`: `16`
  * `.BitsPerSampleGranularity`: `8`
  * `.MinimumSampleFrequency`: `11025`
  * `.MaximumSampleFrequency`: `44100`
  * `.SampleFrequencyGranularity`: `11025`

#### Capability: 16

 * `AM_MEDIA_TYPE`:
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 00 00 01 00 00 00 81 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 00 00 12 00 00 00 C8 D3 61 00`
  * Format Data: `01 00 01 00 11 2B 00 00 11 2B 00 00 01 00 08 00 00 00`
  * `.subtype`: `FourCC 0x00000001`
  * `.bFixedSizeSamples`: `1`
  * `.bTemporalCompression`: `0`
  * `.lSampleSize`: `1`
  * `.cbFormat`: `18`
  * `WAVEFORMATEX`:
   * `.wFormatTag`: `1`
   * `.nChannels`: `1`
   * `.nSamplesPerSec`: `11025`
   * `.nAvgBytesPerSec: `11025`
   * `.nBlockAlign`: `1`
   * `.wBitsPerSample`: `8`
   * `.cbSize`: `0`
 * `AUDIO_STREAM_CONFIG_CAPS`:
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 02 00 00 00 01 00 00 00 08 00 00 00 10 00 00 00 08 00 00 00 11 2B 00 00 44 AC 00 00 11 2B 00 00`
  * `.MinimumChannels`: `1`
  * `.MaximumChannels`: `2`
  * `.ChannelsGranularity`: `1`
  * `.MinimumBitsPerSample`: `8`
  * `.MaximumBitsPerSample`: `16`
  * `.BitsPerSampleGranularity`: `8`
  * `.MinimumSampleFrequency`: `11025`
  * `.MaximumSampleFrequency`: `44100`
  * `.SampleFrequencyGranularity`: `11025`

#### Capability: 17

 * `AM_MEDIA_TYPE`:
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 00 00 02 00 00 00 81 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 00 00 12 00 00 00 C8 D3 61 00`
  * Format Data: `01 00 02 00 40 1F 00 00 80 3E 00 00 02 00 08 00 00 00`
  * `.subtype`: `FourCC 0x00000001`
  * `.bFixedSizeSamples`: `1`
  * `.bTemporalCompression`: `0`
  * `.lSampleSize`: `2`
  * `.cbFormat`: `18`
  * `WAVEFORMATEX`:
   * `.wFormatTag`: `1`
   * `.nChannels`: `2`
   * `.nSamplesPerSec`: `8000`
   * `.nAvgBytesPerSec: `16000`
   * `.nBlockAlign`: `2`
   * `.wBitsPerSample`: `8`
   * `.cbSize`: `0`
 * `AUDIO_STREAM_CONFIG_CAPS`:
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 02 00 00 00 01 00 00 00 08 00 00 00 10 00 00 00 08 00 00 00 11 2B 00 00 44 AC 00 00 11 2B 00 00`
  * `.MinimumChannels`: `1`
  * `.MaximumChannels`: `2`
  * `.ChannelsGranularity`: `1`
  * `.MinimumBitsPerSample`: `8`
  * `.MaximumBitsPerSample`: `16`
  * `.BitsPerSampleGranularity`: `8`
  * `.MinimumSampleFrequency`: `11025`
  * `.MaximumSampleFrequency`: `44100`
  * `.SampleFrequencyGranularity`: `11025`

#### Capability: 18

 * `AM_MEDIA_TYPE`:
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 00 00 01 00 00 00 81 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 00 00 12 00 00 00 C8 D3 61 00`
  * Format Data: `01 00 01 00 40 1F 00 00 40 1F 00 00 01 00 08 00 00 00`
  * `.subtype`: `FourCC 0x00000001`
  * `.bFixedSizeSamples`: `1`
  * `.bTemporalCompression`: `0`
  * `.lSampleSize`: `1`
  * `.cbFormat`: `18`
  * `WAVEFORMATEX`:
   * `.wFormatTag`: `1`
   * `.nChannels`: `1`
   * `.nSamplesPerSec`: `8000`
   * `.nAvgBytesPerSec: `8000`
   * `.nBlockAlign`: `1`
   * `.wBitsPerSample`: `8`
   * `.cbSize`: `0`
 * `AUDIO_STREAM_CONFIG_CAPS`:
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 02 00 00 00 01 00 00 00 08 00 00 00 10 00 00 00 08 00 00 00 11 2B 00 00 44 AC 00 00 11 2B 00 00`
  * `.MinimumChannels`: `1`
  * `.MaximumChannels`: `2`
  * `.ChannelsGranularity`: `1`
  * `.MinimumBitsPerSample`: `8`
  * `.MaximumBitsPerSample`: `16`
  * `.BitsPerSampleGranularity`: `8`
  * `.MinimumSampleFrequency`: `11025`
  * `.MaximumSampleFrequency`: `44100`
  * `.SampleFrequencyGranularity`: `11025`

#### Capability: 19

 * `AM_MEDIA_TYPE`:
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 00 00 04 00 00 00 81 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 00 00 12 00 00 00 C8 D3 61 00`
  * Format Data: `01 00 02 00 80 BB 00 00 00 EE 02 00 04 00 10 00 00 00`
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
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 02 00 00 00 01 00 00 00 08 00 00 00 10 00 00 00 08 00 00 00 11 2B 00 00 44 AC 00 00 11 2B 00 00`
  * `.MinimumChannels`: `1`
  * `.MaximumChannels`: `2`
  * `.ChannelsGranularity`: `1`
  * `.MinimumBitsPerSample`: `8`
  * `.MaximumBitsPerSample`: `16`
  * `.BitsPerSampleGranularity`: `8`
  * `.MinimumSampleFrequency`: `11025`
  * `.MaximumSampleFrequency`: `44100`
  * `.SampleFrequencyGranularity`: `11025`

#### Capability: 20

 * `AM_MEDIA_TYPE`:
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 00 00 02 00 00 00 81 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 00 00 12 00 00 00 C8 D3 61 00`
  * Format Data: `01 00 01 00 80 BB 00 00 00 77 01 00 02 00 10 00 00 00`
  * `.subtype`: `FourCC 0x00000001`
  * `.bFixedSizeSamples`: `1`
  * `.bTemporalCompression`: `0`
  * `.lSampleSize`: `2`
  * `.cbFormat`: `18`
  * `WAVEFORMATEX`:
   * `.wFormatTag`: `1`
   * `.nChannels`: `1`
   * `.nSamplesPerSec`: `48000`
   * `.nAvgBytesPerSec: `96000`
   * `.nBlockAlign`: `2`
   * `.wBitsPerSample`: `16`
   * `.cbSize`: `0`
 * `AUDIO_STREAM_CONFIG_CAPS`:
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 02 00 00 00 01 00 00 00 08 00 00 00 10 00 00 00 08 00 00 00 11 2B 00 00 44 AC 00 00 11 2B 00 00`
  * `.MinimumChannels`: `1`
  * `.MaximumChannels`: `2`
  * `.ChannelsGranularity`: `1`
  * `.MinimumBitsPerSample`: `8`
  * `.MaximumBitsPerSample`: `16`
  * `.BitsPerSampleGranularity`: `8`
  * `.MinimumSampleFrequency`: `11025`
  * `.MaximumSampleFrequency`: `44100`
  * `.SampleFrequencyGranularity`: `11025`

#### Capability: 21

 * `AM_MEDIA_TYPE`:
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 00 00 04 00 00 00 81 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 00 00 12 00 00 00 C8 D3 61 00`
  * Format Data: `01 00 02 00 00 77 01 00 00 DC 05 00 04 00 10 00 00 00`
  * `.subtype`: `FourCC 0x00000001`
  * `.bFixedSizeSamples`: `1`
  * `.bTemporalCompression`: `0`
  * `.lSampleSize`: `4`
  * `.cbFormat`: `18`
  * `WAVEFORMATEX`:
   * `.wFormatTag`: `1`
   * `.nChannels`: `2`
   * `.nSamplesPerSec`: `96000`
   * `.nAvgBytesPerSec: `384000`
   * `.nBlockAlign`: `4`
   * `.wBitsPerSample`: `16`
   * `.cbSize`: `0`
 * `AUDIO_STREAM_CONFIG_CAPS`:
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 02 00 00 00 01 00 00 00 08 00 00 00 10 00 00 00 08 00 00 00 11 2B 00 00 44 AC 00 00 11 2B 00 00`
  * `.MinimumChannels`: `1`
  * `.MaximumChannels`: `2`
  * `.ChannelsGranularity`: `1`
  * `.MinimumBitsPerSample`: `8`
  * `.MaximumBitsPerSample`: `16`
  * `.BitsPerSampleGranularity`: `8`
  * `.MinimumSampleFrequency`: `11025`
  * `.MaximumSampleFrequency`: `44100`
  * `.SampleFrequencyGranularity`: `11025`

#### Capability: 22

 * `AM_MEDIA_TYPE`:
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 00 00 02 00 00 00 81 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 00 00 12 00 00 00 C8 D3 61 00`
  * Format Data: `01 00 01 00 00 77 01 00 00 EE 02 00 02 00 10 00 00 00`
  * `.subtype`: `FourCC 0x00000001`
  * `.bFixedSizeSamples`: `1`
  * `.bTemporalCompression`: `0`
  * `.lSampleSize`: `2`
  * `.cbFormat`: `18`
  * `WAVEFORMATEX`:
   * `.wFormatTag`: `1`
   * `.nChannels`: `1`
   * `.nSamplesPerSec`: `96000`
   * `.nAvgBytesPerSec: `192000`
   * `.nBlockAlign`: `2`
   * `.wBitsPerSample`: `16`
   * `.cbSize`: `0`
 * `AUDIO_STREAM_CONFIG_CAPS`:
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 02 00 00 00 01 00 00 00 08 00 00 00 10 00 00 00 08 00 00 00 11 2B 00 00 44 AC 00 00 11 2B 00 00`
  * `.MinimumChannels`: `1`
  * `.MaximumChannels`: `2`
  * `.ChannelsGranularity`: `1`
  * `.MinimumBitsPerSample`: `8`
  * `.MaximumBitsPerSample`: `16`
  * `.BitsPerSampleGranularity`: `8`
  * `.MinimumSampleFrequency`: `11025`
  * `.MaximumSampleFrequency`: `44100`
  * `.SampleFrequencyGranularity`: `11025`

Interfaces:

  * `IKsPropertySet`
  * `IQualityControl`
  * `IAMBufferNegotiation`
  * `IAMStreamConfig`
  * `IAMStreamControl`

### Pin: Master Volume

 * Direction: `PINDIR_INPUT`
Interfaces:

  * `IQualityControl`

## Device: Phone Line (Realtek AC'97 Audio

 * Moniker Display Name: `@device:cm:{33D9A762-90C8-11D0-BD43-00A0C911CE86}\Phone Line (Realtek AC'97 Audio`

Interfaces:

  * `ISpecifyPropertyPages`
  * `IAMFilterMiscFlags`

Property Pages:

  * `{2CA8CA52-3C3F-11D2-B73D-00C04FB6BD3D}` - `CLSID_AudioInputMixerProperties`, AudioInputMixer Property Page

### Pin: Capture

 * `AMPROPSETID_Pin`, `AMPROPERTY_PIN_CATEGORY`: `{FB6C4281-0353-11D1-905F-0000C0CC16BA} PIN_CATEGORY_CAPTURE`
 * Capabilities:
  * Count: `23`
  * Structure Size: `52` (expected `52`)

#### Capability: 0

 * `AM_MEDIA_TYPE`:
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 00 00 04 00 00 00 81 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 00 00 12 00 00 00 E8 D3 61 00`
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
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 02 00 00 00 01 00 00 00 08 00 00 00 10 00 00 00 08 00 00 00 11 2B 00 00 44 AC 00 00 11 2B 00 00`
  * `.MinimumChannels`: `1`
  * `.MaximumChannels`: `2`
  * `.ChannelsGranularity`: `1`
  * `.MinimumBitsPerSample`: `8`
  * `.MaximumBitsPerSample`: `16`
  * `.BitsPerSampleGranularity`: `8`
  * `.MinimumSampleFrequency`: `11025`
  * `.MaximumSampleFrequency`: `44100`
  * `.SampleFrequencyGranularity`: `11025`

#### Capability: 1

 * `AM_MEDIA_TYPE`:
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 00 00 04 00 00 00 81 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 00 00 12 00 00 00 C8 D3 61 00`
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
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 02 00 00 00 01 00 00 00 08 00 00 00 10 00 00 00 08 00 00 00 11 2B 00 00 44 AC 00 00 11 2B 00 00`
  * `.MinimumChannels`: `1`
  * `.MaximumChannels`: `2`
  * `.ChannelsGranularity`: `1`
  * `.MinimumBitsPerSample`: `8`
  * `.MaximumBitsPerSample`: `16`
  * `.BitsPerSampleGranularity`: `8`
  * `.MinimumSampleFrequency`: `11025`
  * `.MaximumSampleFrequency`: `44100`
  * `.SampleFrequencyGranularity`: `11025`

#### Capability: 2

 * `AM_MEDIA_TYPE`:
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 00 00 02 00 00 00 81 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 00 00 12 00 00 00 E8 D3 61 00`
  * Format Data: `01 00 01 00 44 AC 00 00 88 58 01 00 02 00 10 00 00 00`
  * `.subtype`: `FourCC 0x00000001`
  * `.bFixedSizeSamples`: `1`
  * `.bTemporalCompression`: `0`
  * `.lSampleSize`: `2`
  * `.cbFormat`: `18`
  * `WAVEFORMATEX`:
   * `.wFormatTag`: `1`
   * `.nChannels`: `1`
   * `.nSamplesPerSec`: `44100`
   * `.nAvgBytesPerSec: `88200`
   * `.nBlockAlign`: `2`
   * `.wBitsPerSample`: `16`
   * `.cbSize`: `0`
 * `AUDIO_STREAM_CONFIG_CAPS`:
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 02 00 00 00 01 00 00 00 08 00 00 00 10 00 00 00 08 00 00 00 11 2B 00 00 44 AC 00 00 11 2B 00 00`
  * `.MinimumChannels`: `1`
  * `.MaximumChannels`: `2`
  * `.ChannelsGranularity`: `1`
  * `.MinimumBitsPerSample`: `8`
  * `.MaximumBitsPerSample`: `16`
  * `.BitsPerSampleGranularity`: `8`
  * `.MinimumSampleFrequency`: `11025`
  * `.MaximumSampleFrequency`: `44100`
  * `.SampleFrequencyGranularity`: `11025`

#### Capability: 3

 * `AM_MEDIA_TYPE`:
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 00 00 04 00 00 00 81 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 00 00 12 00 00 00 C8 D3 61 00`
  * Format Data: `01 00 02 00 00 7D 00 00 00 F4 01 00 04 00 10 00 00 00`
  * `.subtype`: `FourCC 0x00000001`
  * `.bFixedSizeSamples`: `1`
  * `.bTemporalCompression`: `0`
  * `.lSampleSize`: `4`
  * `.cbFormat`: `18`
  * `WAVEFORMATEX`:
   * `.wFormatTag`: `1`
   * `.nChannels`: `2`
   * `.nSamplesPerSec`: `32000`
   * `.nAvgBytesPerSec: `128000`
   * `.nBlockAlign`: `4`
   * `.wBitsPerSample`: `16`
   * `.cbSize`: `0`
 * `AUDIO_STREAM_CONFIG_CAPS`:
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 02 00 00 00 01 00 00 00 08 00 00 00 10 00 00 00 08 00 00 00 11 2B 00 00 44 AC 00 00 11 2B 00 00`
  * `.MinimumChannels`: `1`
  * `.MaximumChannels`: `2`
  * `.ChannelsGranularity`: `1`
  * `.MinimumBitsPerSample`: `8`
  * `.MaximumBitsPerSample`: `16`
  * `.BitsPerSampleGranularity`: `8`
  * `.MinimumSampleFrequency`: `11025`
  * `.MaximumSampleFrequency`: `44100`
  * `.SampleFrequencyGranularity`: `11025`

#### Capability: 4

 * `AM_MEDIA_TYPE`:
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 00 00 02 00 00 00 81 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 00 00 12 00 00 00 E8 D3 61 00`
  * Format Data: `01 00 01 00 00 7D 00 00 00 FA 00 00 02 00 10 00 00 00`
  * `.subtype`: `FourCC 0x00000001`
  * `.bFixedSizeSamples`: `1`
  * `.bTemporalCompression`: `0`
  * `.lSampleSize`: `2`
  * `.cbFormat`: `18`
  * `WAVEFORMATEX`:
   * `.wFormatTag`: `1`
   * `.nChannels`: `1`
   * `.nSamplesPerSec`: `32000`
   * `.nAvgBytesPerSec: `64000`
   * `.nBlockAlign`: `2`
   * `.wBitsPerSample`: `16`
   * `.cbSize`: `0`
 * `AUDIO_STREAM_CONFIG_CAPS`:
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 02 00 00 00 01 00 00 00 08 00 00 00 10 00 00 00 08 00 00 00 11 2B 00 00 44 AC 00 00 11 2B 00 00`
  * `.MinimumChannels`: `1`
  * `.MaximumChannels`: `2`
  * `.ChannelsGranularity`: `1`
  * `.MinimumBitsPerSample`: `8`
  * `.MaximumBitsPerSample`: `16`
  * `.BitsPerSampleGranularity`: `8`
  * `.MinimumSampleFrequency`: `11025`
  * `.MaximumSampleFrequency`: `44100`
  * `.SampleFrequencyGranularity`: `11025`

#### Capability: 5

 * `AM_MEDIA_TYPE`:
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 00 00 04 00 00 00 81 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 00 00 12 00 00 00 C8 D3 61 00`
  * Format Data: `01 00 02 00 22 56 00 00 88 58 01 00 04 00 10 00 00 00`
  * `.subtype`: `FourCC 0x00000001`
  * `.bFixedSizeSamples`: `1`
  * `.bTemporalCompression`: `0`
  * `.lSampleSize`: `4`
  * `.cbFormat`: `18`
  * `WAVEFORMATEX`:
   * `.wFormatTag`: `1`
   * `.nChannels`: `2`
   * `.nSamplesPerSec`: `22050`
   * `.nAvgBytesPerSec: `88200`
   * `.nBlockAlign`: `4`
   * `.wBitsPerSample`: `16`
   * `.cbSize`: `0`
 * `AUDIO_STREAM_CONFIG_CAPS`:
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 02 00 00 00 01 00 00 00 08 00 00 00 10 00 00 00 08 00 00 00 11 2B 00 00 44 AC 00 00 11 2B 00 00`
  * `.MinimumChannels`: `1`
  * `.MaximumChannels`: `2`
  * `.ChannelsGranularity`: `1`
  * `.MinimumBitsPerSample`: `8`
  * `.MaximumBitsPerSample`: `16`
  * `.BitsPerSampleGranularity`: `8`
  * `.MinimumSampleFrequency`: `11025`
  * `.MaximumSampleFrequency`: `44100`
  * `.SampleFrequencyGranularity`: `11025`

#### Capability: 6

 * `AM_MEDIA_TYPE`:
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 00 00 02 00 00 00 81 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 00 00 12 00 00 00 E8 D3 61 00`
  * Format Data: `01 00 01 00 22 56 00 00 44 AC 00 00 02 00 10 00 00 00`
  * `.subtype`: `FourCC 0x00000001`
  * `.bFixedSizeSamples`: `1`
  * `.bTemporalCompression`: `0`
  * `.lSampleSize`: `2`
  * `.cbFormat`: `18`
  * `WAVEFORMATEX`:
   * `.wFormatTag`: `1`
   * `.nChannels`: `1`
   * `.nSamplesPerSec`: `22050`
   * `.nAvgBytesPerSec: `44100`
   * `.nBlockAlign`: `2`
   * `.wBitsPerSample`: `16`
   * `.cbSize`: `0`
 * `AUDIO_STREAM_CONFIG_CAPS`:
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 02 00 00 00 01 00 00 00 08 00 00 00 10 00 00 00 08 00 00 00 11 2B 00 00 44 AC 00 00 11 2B 00 00`
  * `.MinimumChannels`: `1`
  * `.MaximumChannels`: `2`
  * `.ChannelsGranularity`: `1`
  * `.MinimumBitsPerSample`: `8`
  * `.MaximumBitsPerSample`: `16`
  * `.BitsPerSampleGranularity`: `8`
  * `.MinimumSampleFrequency`: `11025`
  * `.MaximumSampleFrequency`: `44100`
  * `.SampleFrequencyGranularity`: `11025`

#### Capability: 7

 * `AM_MEDIA_TYPE`:
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 00 00 04 00 00 00 81 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 00 00 12 00 00 00 C8 D3 61 00`
  * Format Data: `01 00 02 00 11 2B 00 00 44 AC 00 00 04 00 10 00 00 00`
  * `.subtype`: `FourCC 0x00000001`
  * `.bFixedSizeSamples`: `1`
  * `.bTemporalCompression`: `0`
  * `.lSampleSize`: `4`
  * `.cbFormat`: `18`
  * `WAVEFORMATEX`:
   * `.wFormatTag`: `1`
   * `.nChannels`: `2`
   * `.nSamplesPerSec`: `11025`
   * `.nAvgBytesPerSec: `44100`
   * `.nBlockAlign`: `4`
   * `.wBitsPerSample`: `16`
   * `.cbSize`: `0`
 * `AUDIO_STREAM_CONFIG_CAPS`:
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 02 00 00 00 01 00 00 00 08 00 00 00 10 00 00 00 08 00 00 00 11 2B 00 00 44 AC 00 00 11 2B 00 00`
  * `.MinimumChannels`: `1`
  * `.MaximumChannels`: `2`
  * `.ChannelsGranularity`: `1`
  * `.MinimumBitsPerSample`: `8`
  * `.MaximumBitsPerSample`: `16`
  * `.BitsPerSampleGranularity`: `8`
  * `.MinimumSampleFrequency`: `11025`
  * `.MaximumSampleFrequency`: `44100`
  * `.SampleFrequencyGranularity`: `11025`

#### Capability: 8

 * `AM_MEDIA_TYPE`:
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 00 00 02 00 00 00 81 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 00 00 12 00 00 00 E8 D3 61 00`
  * Format Data: `01 00 01 00 11 2B 00 00 22 56 00 00 02 00 10 00 00 00`
  * `.subtype`: `FourCC 0x00000001`
  * `.bFixedSizeSamples`: `1`
  * `.bTemporalCompression`: `0`
  * `.lSampleSize`: `2`
  * `.cbFormat`: `18`
  * `WAVEFORMATEX`:
   * `.wFormatTag`: `1`
   * `.nChannels`: `1`
   * `.nSamplesPerSec`: `11025`
   * `.nAvgBytesPerSec: `22050`
   * `.nBlockAlign`: `2`
   * `.wBitsPerSample`: `16`
   * `.cbSize`: `0`
 * `AUDIO_STREAM_CONFIG_CAPS`:
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 02 00 00 00 01 00 00 00 08 00 00 00 10 00 00 00 08 00 00 00 11 2B 00 00 44 AC 00 00 11 2B 00 00`
  * `.MinimumChannels`: `1`
  * `.MaximumChannels`: `2`
  * `.ChannelsGranularity`: `1`
  * `.MinimumBitsPerSample`: `8`
  * `.MaximumBitsPerSample`: `16`
  * `.BitsPerSampleGranularity`: `8`
  * `.MinimumSampleFrequency`: `11025`
  * `.MaximumSampleFrequency`: `44100`
  * `.SampleFrequencyGranularity`: `11025`

#### Capability: 9

 * `AM_MEDIA_TYPE`:
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 00 00 04 00 00 00 81 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 00 00 12 00 00 00 C8 D3 61 00`
  * Format Data: `01 00 02 00 40 1F 00 00 00 7D 00 00 04 00 10 00 00 00`
  * `.subtype`: `FourCC 0x00000001`
  * `.bFixedSizeSamples`: `1`
  * `.bTemporalCompression`: `0`
  * `.lSampleSize`: `4`
  * `.cbFormat`: `18`
  * `WAVEFORMATEX`:
   * `.wFormatTag`: `1`
   * `.nChannels`: `2`
   * `.nSamplesPerSec`: `8000`
   * `.nAvgBytesPerSec: `32000`
   * `.nBlockAlign`: `4`
   * `.wBitsPerSample`: `16`
   * `.cbSize`: `0`
 * `AUDIO_STREAM_CONFIG_CAPS`:
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 02 00 00 00 01 00 00 00 08 00 00 00 10 00 00 00 08 00 00 00 11 2B 00 00 44 AC 00 00 11 2B 00 00`
  * `.MinimumChannels`: `1`
  * `.MaximumChannels`: `2`
  * `.ChannelsGranularity`: `1`
  * `.MinimumBitsPerSample`: `8`
  * `.MaximumBitsPerSample`: `16`
  * `.BitsPerSampleGranularity`: `8`
  * `.MinimumSampleFrequency`: `11025`
  * `.MaximumSampleFrequency`: `44100`
  * `.SampleFrequencyGranularity`: `11025`

#### Capability: 10

 * `AM_MEDIA_TYPE`:
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 00 00 02 00 00 00 81 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 00 00 12 00 00 00 E8 D3 61 00`
  * Format Data: `01 00 01 00 40 1F 00 00 80 3E 00 00 02 00 10 00 00 00`
  * `.subtype`: `FourCC 0x00000001`
  * `.bFixedSizeSamples`: `1`
  * `.bTemporalCompression`: `0`
  * `.lSampleSize`: `2`
  * `.cbFormat`: `18`
  * `WAVEFORMATEX`:
   * `.wFormatTag`: `1`
   * `.nChannels`: `1`
   * `.nSamplesPerSec`: `8000`
   * `.nAvgBytesPerSec: `16000`
   * `.nBlockAlign`: `2`
   * `.wBitsPerSample`: `16`
   * `.cbSize`: `0`
 * `AUDIO_STREAM_CONFIG_CAPS`:
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 02 00 00 00 01 00 00 00 08 00 00 00 10 00 00 00 08 00 00 00 11 2B 00 00 44 AC 00 00 11 2B 00 00`
  * `.MinimumChannels`: `1`
  * `.MaximumChannels`: `2`
  * `.ChannelsGranularity`: `1`
  * `.MinimumBitsPerSample`: `8`
  * `.MaximumBitsPerSample`: `16`
  * `.BitsPerSampleGranularity`: `8`
  * `.MinimumSampleFrequency`: `11025`
  * `.MaximumSampleFrequency`: `44100`
  * `.SampleFrequencyGranularity`: `11025`

#### Capability: 11

 * `AM_MEDIA_TYPE`:
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 00 00 02 00 00 00 81 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 00 00 12 00 00 00 C8 D3 61 00`
  * Format Data: `01 00 02 00 44 AC 00 00 88 58 01 00 02 00 08 00 00 00`
  * `.subtype`: `FourCC 0x00000001`
  * `.bFixedSizeSamples`: `1`
  * `.bTemporalCompression`: `0`
  * `.lSampleSize`: `2`
  * `.cbFormat`: `18`
  * `WAVEFORMATEX`:
   * `.wFormatTag`: `1`
   * `.nChannels`: `2`
   * `.nSamplesPerSec`: `44100`
   * `.nAvgBytesPerSec: `88200`
   * `.nBlockAlign`: `2`
   * `.wBitsPerSample`: `8`
   * `.cbSize`: `0`
 * `AUDIO_STREAM_CONFIG_CAPS`:
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 02 00 00 00 01 00 00 00 08 00 00 00 10 00 00 00 08 00 00 00 11 2B 00 00 44 AC 00 00 11 2B 00 00`
  * `.MinimumChannels`: `1`
  * `.MaximumChannels`: `2`
  * `.ChannelsGranularity`: `1`
  * `.MinimumBitsPerSample`: `8`
  * `.MaximumBitsPerSample`: `16`
  * `.BitsPerSampleGranularity`: `8`
  * `.MinimumSampleFrequency`: `11025`
  * `.MaximumSampleFrequency`: `44100`
  * `.SampleFrequencyGranularity`: `11025`

#### Capability: 12

 * `AM_MEDIA_TYPE`:
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 00 00 01 00 00 00 81 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 00 00 12 00 00 00 E8 D3 61 00`
  * Format Data: `01 00 01 00 44 AC 00 00 44 AC 00 00 01 00 08 00 00 00`
  * `.subtype`: `FourCC 0x00000001`
  * `.bFixedSizeSamples`: `1`
  * `.bTemporalCompression`: `0`
  * `.lSampleSize`: `1`
  * `.cbFormat`: `18`
  * `WAVEFORMATEX`:
   * `.wFormatTag`: `1`
   * `.nChannels`: `1`
   * `.nSamplesPerSec`: `44100`
   * `.nAvgBytesPerSec: `44100`
   * `.nBlockAlign`: `1`
   * `.wBitsPerSample`: `8`
   * `.cbSize`: `0`
 * `AUDIO_STREAM_CONFIG_CAPS`:
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 02 00 00 00 01 00 00 00 08 00 00 00 10 00 00 00 08 00 00 00 11 2B 00 00 44 AC 00 00 11 2B 00 00`
  * `.MinimumChannels`: `1`
  * `.MaximumChannels`: `2`
  * `.ChannelsGranularity`: `1`
  * `.MinimumBitsPerSample`: `8`
  * `.MaximumBitsPerSample`: `16`
  * `.BitsPerSampleGranularity`: `8`
  * `.MinimumSampleFrequency`: `11025`
  * `.MaximumSampleFrequency`: `44100`
  * `.SampleFrequencyGranularity`: `11025`

#### Capability: 13

 * `AM_MEDIA_TYPE`:
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 00 00 02 00 00 00 81 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 00 00 12 00 00 00 C8 D3 61 00`
  * Format Data: `01 00 02 00 22 56 00 00 44 AC 00 00 02 00 08 00 00 00`
  * `.subtype`: `FourCC 0x00000001`
  * `.bFixedSizeSamples`: `1`
  * `.bTemporalCompression`: `0`
  * `.lSampleSize`: `2`
  * `.cbFormat`: `18`
  * `WAVEFORMATEX`:
   * `.wFormatTag`: `1`
   * `.nChannels`: `2`
   * `.nSamplesPerSec`: `22050`
   * `.nAvgBytesPerSec: `44100`
   * `.nBlockAlign`: `2`
   * `.wBitsPerSample`: `8`
   * `.cbSize`: `0`
 * `AUDIO_STREAM_CONFIG_CAPS`:
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 02 00 00 00 01 00 00 00 08 00 00 00 10 00 00 00 08 00 00 00 11 2B 00 00 44 AC 00 00 11 2B 00 00`
  * `.MinimumChannels`: `1`
  * `.MaximumChannels`: `2`
  * `.ChannelsGranularity`: `1`
  * `.MinimumBitsPerSample`: `8`
  * `.MaximumBitsPerSample`: `16`
  * `.BitsPerSampleGranularity`: `8`
  * `.MinimumSampleFrequency`: `11025`
  * `.MaximumSampleFrequency`: `44100`
  * `.SampleFrequencyGranularity`: `11025`

#### Capability: 14

 * `AM_MEDIA_TYPE`:
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 00 00 01 00 00 00 81 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 00 00 12 00 00 00 E8 D3 61 00`
  * Format Data: `01 00 01 00 22 56 00 00 22 56 00 00 01 00 08 00 00 00`
  * `.subtype`: `FourCC 0x00000001`
  * `.bFixedSizeSamples`: `1`
  * `.bTemporalCompression`: `0`
  * `.lSampleSize`: `1`
  * `.cbFormat`: `18`
  * `WAVEFORMATEX`:
   * `.wFormatTag`: `1`
   * `.nChannels`: `1`
   * `.nSamplesPerSec`: `22050`
   * `.nAvgBytesPerSec: `22050`
   * `.nBlockAlign`: `1`
   * `.wBitsPerSample`: `8`
   * `.cbSize`: `0`
 * `AUDIO_STREAM_CONFIG_CAPS`:
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 02 00 00 00 01 00 00 00 08 00 00 00 10 00 00 00 08 00 00 00 11 2B 00 00 44 AC 00 00 11 2B 00 00`
  * `.MinimumChannels`: `1`
  * `.MaximumChannels`: `2`
  * `.ChannelsGranularity`: `1`
  * `.MinimumBitsPerSample`: `8`
  * `.MaximumBitsPerSample`: `16`
  * `.BitsPerSampleGranularity`: `8`
  * `.MinimumSampleFrequency`: `11025`
  * `.MaximumSampleFrequency`: `44100`
  * `.SampleFrequencyGranularity`: `11025`

#### Capability: 15

 * `AM_MEDIA_TYPE`:
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 00 00 02 00 00 00 81 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 00 00 12 00 00 00 C8 D3 61 00`
  * Format Data: `01 00 02 00 11 2B 00 00 22 56 00 00 02 00 08 00 00 00`
  * `.subtype`: `FourCC 0x00000001`
  * `.bFixedSizeSamples`: `1`
  * `.bTemporalCompression`: `0`
  * `.lSampleSize`: `2`
  * `.cbFormat`: `18`
  * `WAVEFORMATEX`:
   * `.wFormatTag`: `1`
   * `.nChannels`: `2`
   * `.nSamplesPerSec`: `11025`
   * `.nAvgBytesPerSec: `22050`
   * `.nBlockAlign`: `2`
   * `.wBitsPerSample`: `8`
   * `.cbSize`: `0`
 * `AUDIO_STREAM_CONFIG_CAPS`:
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 02 00 00 00 01 00 00 00 08 00 00 00 10 00 00 00 08 00 00 00 11 2B 00 00 44 AC 00 00 11 2B 00 00`
  * `.MinimumChannels`: `1`
  * `.MaximumChannels`: `2`
  * `.ChannelsGranularity`: `1`
  * `.MinimumBitsPerSample`: `8`
  * `.MaximumBitsPerSample`: `16`
  * `.BitsPerSampleGranularity`: `8`
  * `.MinimumSampleFrequency`: `11025`
  * `.MaximumSampleFrequency`: `44100`
  * `.SampleFrequencyGranularity`: `11025`

#### Capability: 16

 * `AM_MEDIA_TYPE`:
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 00 00 01 00 00 00 81 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 00 00 12 00 00 00 E8 D3 61 00`
  * Format Data: `01 00 01 00 11 2B 00 00 11 2B 00 00 01 00 08 00 00 00`
  * `.subtype`: `FourCC 0x00000001`
  * `.bFixedSizeSamples`: `1`
  * `.bTemporalCompression`: `0`
  * `.lSampleSize`: `1`
  * `.cbFormat`: `18`
  * `WAVEFORMATEX`:
   * `.wFormatTag`: `1`
   * `.nChannels`: `1`
   * `.nSamplesPerSec`: `11025`
   * `.nAvgBytesPerSec: `11025`
   * `.nBlockAlign`: `1`
   * `.wBitsPerSample`: `8`
   * `.cbSize`: `0`
 * `AUDIO_STREAM_CONFIG_CAPS`:
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 02 00 00 00 01 00 00 00 08 00 00 00 10 00 00 00 08 00 00 00 11 2B 00 00 44 AC 00 00 11 2B 00 00`
  * `.MinimumChannels`: `1`
  * `.MaximumChannels`: `2`
  * `.ChannelsGranularity`: `1`
  * `.MinimumBitsPerSample`: `8`
  * `.MaximumBitsPerSample`: `16`
  * `.BitsPerSampleGranularity`: `8`
  * `.MinimumSampleFrequency`: `11025`
  * `.MaximumSampleFrequency`: `44100`
  * `.SampleFrequencyGranularity`: `11025`

#### Capability: 17

 * `AM_MEDIA_TYPE`:
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 00 00 02 00 00 00 81 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 00 00 12 00 00 00 C8 D3 61 00`
  * Format Data: `01 00 02 00 40 1F 00 00 80 3E 00 00 02 00 08 00 00 00`
  * `.subtype`: `FourCC 0x00000001`
  * `.bFixedSizeSamples`: `1`
  * `.bTemporalCompression`: `0`
  * `.lSampleSize`: `2`
  * `.cbFormat`: `18`
  * `WAVEFORMATEX`:
   * `.wFormatTag`: `1`
   * `.nChannels`: `2`
   * `.nSamplesPerSec`: `8000`
   * `.nAvgBytesPerSec: `16000`
   * `.nBlockAlign`: `2`
   * `.wBitsPerSample`: `8`
   * `.cbSize`: `0`
 * `AUDIO_STREAM_CONFIG_CAPS`:
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 02 00 00 00 01 00 00 00 08 00 00 00 10 00 00 00 08 00 00 00 11 2B 00 00 44 AC 00 00 11 2B 00 00`
  * `.MinimumChannels`: `1`
  * `.MaximumChannels`: `2`
  * `.ChannelsGranularity`: `1`
  * `.MinimumBitsPerSample`: `8`
  * `.MaximumBitsPerSample`: `16`
  * `.BitsPerSampleGranularity`: `8`
  * `.MinimumSampleFrequency`: `11025`
  * `.MaximumSampleFrequency`: `44100`
  * `.SampleFrequencyGranularity`: `11025`

#### Capability: 18

 * `AM_MEDIA_TYPE`:
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 00 00 01 00 00 00 81 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 00 00 12 00 00 00 E8 D3 61 00`
  * Format Data: `01 00 01 00 40 1F 00 00 40 1F 00 00 01 00 08 00 00 00`
  * `.subtype`: `FourCC 0x00000001`
  * `.bFixedSizeSamples`: `1`
  * `.bTemporalCompression`: `0`
  * `.lSampleSize`: `1`
  * `.cbFormat`: `18`
  * `WAVEFORMATEX`:
   * `.wFormatTag`: `1`
   * `.nChannels`: `1`
   * `.nSamplesPerSec`: `8000`
   * `.nAvgBytesPerSec: `8000`
   * `.nBlockAlign`: `1`
   * `.wBitsPerSample`: `8`
   * `.cbSize`: `0`
 * `AUDIO_STREAM_CONFIG_CAPS`:
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 02 00 00 00 01 00 00 00 08 00 00 00 10 00 00 00 08 00 00 00 11 2B 00 00 44 AC 00 00 11 2B 00 00`
  * `.MinimumChannels`: `1`
  * `.MaximumChannels`: `2`
  * `.ChannelsGranularity`: `1`
  * `.MinimumBitsPerSample`: `8`
  * `.MaximumBitsPerSample`: `16`
  * `.BitsPerSampleGranularity`: `8`
  * `.MinimumSampleFrequency`: `11025`
  * `.MaximumSampleFrequency`: `44100`
  * `.SampleFrequencyGranularity`: `11025`

#### Capability: 19

 * `AM_MEDIA_TYPE`:
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 00 00 04 00 00 00 81 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 00 00 12 00 00 00 C8 D3 61 00`
  * Format Data: `01 00 02 00 80 BB 00 00 00 EE 02 00 04 00 10 00 00 00`
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
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 02 00 00 00 01 00 00 00 08 00 00 00 10 00 00 00 08 00 00 00 11 2B 00 00 44 AC 00 00 11 2B 00 00`
  * `.MinimumChannels`: `1`
  * `.MaximumChannels`: `2`
  * `.ChannelsGranularity`: `1`
  * `.MinimumBitsPerSample`: `8`
  * `.MaximumBitsPerSample`: `16`
  * `.BitsPerSampleGranularity`: `8`
  * `.MinimumSampleFrequency`: `11025`
  * `.MaximumSampleFrequency`: `44100`
  * `.SampleFrequencyGranularity`: `11025`

#### Capability: 20

 * `AM_MEDIA_TYPE`:
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 00 00 02 00 00 00 81 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 00 00 12 00 00 00 E8 D3 61 00`
  * Format Data: `01 00 01 00 80 BB 00 00 00 77 01 00 02 00 10 00 00 00`
  * `.subtype`: `FourCC 0x00000001`
  * `.bFixedSizeSamples`: `1`
  * `.bTemporalCompression`: `0`
  * `.lSampleSize`: `2`
  * `.cbFormat`: `18`
  * `WAVEFORMATEX`:
   * `.wFormatTag`: `1`
   * `.nChannels`: `1`
   * `.nSamplesPerSec`: `48000`
   * `.nAvgBytesPerSec: `96000`
   * `.nBlockAlign`: `2`
   * `.wBitsPerSample`: `16`
   * `.cbSize`: `0`
 * `AUDIO_STREAM_CONFIG_CAPS`:
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 02 00 00 00 01 00 00 00 08 00 00 00 10 00 00 00 08 00 00 00 11 2B 00 00 44 AC 00 00 11 2B 00 00`
  * `.MinimumChannels`: `1`
  * `.MaximumChannels`: `2`
  * `.ChannelsGranularity`: `1`
  * `.MinimumBitsPerSample`: `8`
  * `.MaximumBitsPerSample`: `16`
  * `.BitsPerSampleGranularity`: `8`
  * `.MinimumSampleFrequency`: `11025`
  * `.MaximumSampleFrequency`: `44100`
  * `.SampleFrequencyGranularity`: `11025`

#### Capability: 21

 * `AM_MEDIA_TYPE`:
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 00 00 04 00 00 00 81 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 00 00 12 00 00 00 C8 D3 61 00`
  * Format Data: `01 00 02 00 00 77 01 00 00 DC 05 00 04 00 10 00 00 00`
  * `.subtype`: `FourCC 0x00000001`
  * `.bFixedSizeSamples`: `1`
  * `.bTemporalCompression`: `0`
  * `.lSampleSize`: `4`
  * `.cbFormat`: `18`
  * `WAVEFORMATEX`:
   * `.wFormatTag`: `1`
   * `.nChannels`: `2`
   * `.nSamplesPerSec`: `96000`
   * `.nAvgBytesPerSec: `384000`
   * `.nBlockAlign`: `4`
   * `.wBitsPerSample`: `16`
   * `.cbSize`: `0`
 * `AUDIO_STREAM_CONFIG_CAPS`:
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 02 00 00 00 01 00 00 00 08 00 00 00 10 00 00 00 08 00 00 00 11 2B 00 00 44 AC 00 00 11 2B 00 00`
  * `.MinimumChannels`: `1`
  * `.MaximumChannels`: `2`
  * `.ChannelsGranularity`: `1`
  * `.MinimumBitsPerSample`: `8`
  * `.MaximumBitsPerSample`: `16`
  * `.BitsPerSampleGranularity`: `8`
  * `.MinimumSampleFrequency`: `11025`
  * `.MaximumSampleFrequency`: `44100`
  * `.SampleFrequencyGranularity`: `11025`

#### Capability: 22

 * `AM_MEDIA_TYPE`:
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 00 00 02 00 00 00 81 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 00 00 12 00 00 00 E8 D3 61 00`
  * Format Data: `01 00 01 00 00 77 01 00 00 EE 02 00 02 00 10 00 00 00`
  * `.subtype`: `FourCC 0x00000001`
  * `.bFixedSizeSamples`: `1`
  * `.bTemporalCompression`: `0`
  * `.lSampleSize`: `2`
  * `.cbFormat`: `18`
  * `WAVEFORMATEX`:
   * `.wFormatTag`: `1`
   * `.nChannels`: `1`
   * `.nSamplesPerSec`: `96000`
   * `.nAvgBytesPerSec: `192000`
   * `.nBlockAlign`: `2`
   * `.wBitsPerSample`: `16`
   * `.cbSize`: `0`
 * `AUDIO_STREAM_CONFIG_CAPS`:
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 02 00 00 00 01 00 00 00 08 00 00 00 10 00 00 00 08 00 00 00 11 2B 00 00 44 AC 00 00 11 2B 00 00`
  * `.MinimumChannels`: `1`
  * `.MaximumChannels`: `2`
  * `.ChannelsGranularity`: `1`
  * `.MinimumBitsPerSample`: `8`
  * `.MaximumBitsPerSample`: `16`
  * `.BitsPerSampleGranularity`: `8`
  * `.MinimumSampleFrequency`: `11025`
  * `.MaximumSampleFrequency`: `44100`
  * `.SampleFrequencyGranularity`: `11025`

Interfaces:

  * `IKsPropertySet`
  * `IQualityControl`
  * `IAMBufferNegotiation`
  * `IAMStreamConfig`
  * `IAMStreamControl`

### Pin: Master Volume

 * Direction: `PINDIR_INPUT`
Interfaces:

  * `IQualityControl`

## Device: SPDIF (Realtek AC'97 Audio)

 * Moniker Display Name: `@device:cm:{33D9A762-90C8-11D0-BD43-00A0C911CE86}\SPDIF (Realtek AC'97 Audio)`

Interfaces:

  * `ISpecifyPropertyPages`
  * `IAMFilterMiscFlags`

Property Pages:

  * `{2CA8CA52-3C3F-11D2-B73D-00C04FB6BD3D}` - `CLSID_AudioInputMixerProperties`, AudioInputMixer Property Page

### Pin: Capture

 * `AMPROPSETID_Pin`, `AMPROPERTY_PIN_CATEGORY`: `{FB6C4281-0353-11D1-905F-0000C0CC16BA} PIN_CATEGORY_CAPTURE`
 * Capabilities:
  * Count: `23`
  * Structure Size: `52` (expected `52`)

#### Capability: 0

 * `AM_MEDIA_TYPE`:
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 00 00 04 00 00 00 81 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 00 00 12 00 00 00 C8 D3 61 00`
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
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 02 00 00 00 01 00 00 00 08 00 00 00 10 00 00 00 08 00 00 00 11 2B 00 00 44 AC 00 00 11 2B 00 00`
  * `.MinimumChannels`: `1`
  * `.MaximumChannels`: `2`
  * `.ChannelsGranularity`: `1`
  * `.MinimumBitsPerSample`: `8`
  * `.MaximumBitsPerSample`: `16`
  * `.BitsPerSampleGranularity`: `8`
  * `.MinimumSampleFrequency`: `11025`
  * `.MaximumSampleFrequency`: `44100`
  * `.SampleFrequencyGranularity`: `11025`

#### Capability: 1

 * `AM_MEDIA_TYPE`:
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 00 00 04 00 00 00 81 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 00 00 12 00 00 00 C8 D3 61 00`
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
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 02 00 00 00 01 00 00 00 08 00 00 00 10 00 00 00 08 00 00 00 11 2B 00 00 44 AC 00 00 11 2B 00 00`
  * `.MinimumChannels`: `1`
  * `.MaximumChannels`: `2`
  * `.ChannelsGranularity`: `1`
  * `.MinimumBitsPerSample`: `8`
  * `.MaximumBitsPerSample`: `16`
  * `.BitsPerSampleGranularity`: `8`
  * `.MinimumSampleFrequency`: `11025`
  * `.MaximumSampleFrequency`: `44100`
  * `.SampleFrequencyGranularity`: `11025`

#### Capability: 2

 * `AM_MEDIA_TYPE`:
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 00 00 02 00 00 00 81 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 00 00 12 00 00 00 C8 D3 61 00`
  * Format Data: `01 00 01 00 44 AC 00 00 88 58 01 00 02 00 10 00 00 00`
  * `.subtype`: `FourCC 0x00000001`
  * `.bFixedSizeSamples`: `1`
  * `.bTemporalCompression`: `0`
  * `.lSampleSize`: `2`
  * `.cbFormat`: `18`
  * `WAVEFORMATEX`:
   * `.wFormatTag`: `1`
   * `.nChannels`: `1`
   * `.nSamplesPerSec`: `44100`
   * `.nAvgBytesPerSec: `88200`
   * `.nBlockAlign`: `2`
   * `.wBitsPerSample`: `16`
   * `.cbSize`: `0`
 * `AUDIO_STREAM_CONFIG_CAPS`:
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 02 00 00 00 01 00 00 00 08 00 00 00 10 00 00 00 08 00 00 00 11 2B 00 00 44 AC 00 00 11 2B 00 00`
  * `.MinimumChannels`: `1`
  * `.MaximumChannels`: `2`
  * `.ChannelsGranularity`: `1`
  * `.MinimumBitsPerSample`: `8`
  * `.MaximumBitsPerSample`: `16`
  * `.BitsPerSampleGranularity`: `8`
  * `.MinimumSampleFrequency`: `11025`
  * `.MaximumSampleFrequency`: `44100`
  * `.SampleFrequencyGranularity`: `11025`

#### Capability: 3

 * `AM_MEDIA_TYPE`:
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 00 00 04 00 00 00 81 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 00 00 12 00 00 00 C8 D3 61 00`
  * Format Data: `01 00 02 00 00 7D 00 00 00 F4 01 00 04 00 10 00 00 00`
  * `.subtype`: `FourCC 0x00000001`
  * `.bFixedSizeSamples`: `1`
  * `.bTemporalCompression`: `0`
  * `.lSampleSize`: `4`
  * `.cbFormat`: `18`
  * `WAVEFORMATEX`:
   * `.wFormatTag`: `1`
   * `.nChannels`: `2`
   * `.nSamplesPerSec`: `32000`
   * `.nAvgBytesPerSec: `128000`
   * `.nBlockAlign`: `4`
   * `.wBitsPerSample`: `16`
   * `.cbSize`: `0`
 * `AUDIO_STREAM_CONFIG_CAPS`:
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 02 00 00 00 01 00 00 00 08 00 00 00 10 00 00 00 08 00 00 00 11 2B 00 00 44 AC 00 00 11 2B 00 00`
  * `.MinimumChannels`: `1`
  * `.MaximumChannels`: `2`
  * `.ChannelsGranularity`: `1`
  * `.MinimumBitsPerSample`: `8`
  * `.MaximumBitsPerSample`: `16`
  * `.BitsPerSampleGranularity`: `8`
  * `.MinimumSampleFrequency`: `11025`
  * `.MaximumSampleFrequency`: `44100`
  * `.SampleFrequencyGranularity`: `11025`

#### Capability: 4

 * `AM_MEDIA_TYPE`:
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 00 00 02 00 00 00 81 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 00 00 12 00 00 00 C8 D3 61 00`
  * Format Data: `01 00 01 00 00 7D 00 00 00 FA 00 00 02 00 10 00 00 00`
  * `.subtype`: `FourCC 0x00000001`
  * `.bFixedSizeSamples`: `1`
  * `.bTemporalCompression`: `0`
  * `.lSampleSize`: `2`
  * `.cbFormat`: `18`
  * `WAVEFORMATEX`:
   * `.wFormatTag`: `1`
   * `.nChannels`: `1`
   * `.nSamplesPerSec`: `32000`
   * `.nAvgBytesPerSec: `64000`
   * `.nBlockAlign`: `2`
   * `.wBitsPerSample`: `16`
   * `.cbSize`: `0`
 * `AUDIO_STREAM_CONFIG_CAPS`:
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 02 00 00 00 01 00 00 00 08 00 00 00 10 00 00 00 08 00 00 00 11 2B 00 00 44 AC 00 00 11 2B 00 00`
  * `.MinimumChannels`: `1`
  * `.MaximumChannels`: `2`
  * `.ChannelsGranularity`: `1`
  * `.MinimumBitsPerSample`: `8`
  * `.MaximumBitsPerSample`: `16`
  * `.BitsPerSampleGranularity`: `8`
  * `.MinimumSampleFrequency`: `11025`
  * `.MaximumSampleFrequency`: `44100`
  * `.SampleFrequencyGranularity`: `11025`

#### Capability: 5

 * `AM_MEDIA_TYPE`:
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 00 00 04 00 00 00 81 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 00 00 12 00 00 00 C8 D3 61 00`
  * Format Data: `01 00 02 00 22 56 00 00 88 58 01 00 04 00 10 00 00 00`
  * `.subtype`: `FourCC 0x00000001`
  * `.bFixedSizeSamples`: `1`
  * `.bTemporalCompression`: `0`
  * `.lSampleSize`: `4`
  * `.cbFormat`: `18`
  * `WAVEFORMATEX`:
   * `.wFormatTag`: `1`
   * `.nChannels`: `2`
   * `.nSamplesPerSec`: `22050`
   * `.nAvgBytesPerSec: `88200`
   * `.nBlockAlign`: `4`
   * `.wBitsPerSample`: `16`
   * `.cbSize`: `0`
 * `AUDIO_STREAM_CONFIG_CAPS`:
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 02 00 00 00 01 00 00 00 08 00 00 00 10 00 00 00 08 00 00 00 11 2B 00 00 44 AC 00 00 11 2B 00 00`
  * `.MinimumChannels`: `1`
  * `.MaximumChannels`: `2`
  * `.ChannelsGranularity`: `1`
  * `.MinimumBitsPerSample`: `8`
  * `.MaximumBitsPerSample`: `16`
  * `.BitsPerSampleGranularity`: `8`
  * `.MinimumSampleFrequency`: `11025`
  * `.MaximumSampleFrequency`: `44100`
  * `.SampleFrequencyGranularity`: `11025`

#### Capability: 6

 * `AM_MEDIA_TYPE`:
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 00 00 02 00 00 00 81 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 00 00 12 00 00 00 C8 D3 61 00`
  * Format Data: `01 00 01 00 22 56 00 00 44 AC 00 00 02 00 10 00 00 00`
  * `.subtype`: `FourCC 0x00000001`
  * `.bFixedSizeSamples`: `1`
  * `.bTemporalCompression`: `0`
  * `.lSampleSize`: `2`
  * `.cbFormat`: `18`
  * `WAVEFORMATEX`:
   * `.wFormatTag`: `1`
   * `.nChannels`: `1`
   * `.nSamplesPerSec`: `22050`
   * `.nAvgBytesPerSec: `44100`
   * `.nBlockAlign`: `2`
   * `.wBitsPerSample`: `16`
   * `.cbSize`: `0`
 * `AUDIO_STREAM_CONFIG_CAPS`:
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 02 00 00 00 01 00 00 00 08 00 00 00 10 00 00 00 08 00 00 00 11 2B 00 00 44 AC 00 00 11 2B 00 00`
  * `.MinimumChannels`: `1`
  * `.MaximumChannels`: `2`
  * `.ChannelsGranularity`: `1`
  * `.MinimumBitsPerSample`: `8`
  * `.MaximumBitsPerSample`: `16`
  * `.BitsPerSampleGranularity`: `8`
  * `.MinimumSampleFrequency`: `11025`
  * `.MaximumSampleFrequency`: `44100`
  * `.SampleFrequencyGranularity`: `11025`

#### Capability: 7

 * `AM_MEDIA_TYPE`:
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 00 00 04 00 00 00 81 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 00 00 12 00 00 00 C8 D3 61 00`
  * Format Data: `01 00 02 00 11 2B 00 00 44 AC 00 00 04 00 10 00 00 00`
  * `.subtype`: `FourCC 0x00000001`
  * `.bFixedSizeSamples`: `1`
  * `.bTemporalCompression`: `0`
  * `.lSampleSize`: `4`
  * `.cbFormat`: `18`
  * `WAVEFORMATEX`:
   * `.wFormatTag`: `1`
   * `.nChannels`: `2`
   * `.nSamplesPerSec`: `11025`
   * `.nAvgBytesPerSec: `44100`
   * `.nBlockAlign`: `4`
   * `.wBitsPerSample`: `16`
   * `.cbSize`: `0`
 * `AUDIO_STREAM_CONFIG_CAPS`:
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 02 00 00 00 01 00 00 00 08 00 00 00 10 00 00 00 08 00 00 00 11 2B 00 00 44 AC 00 00 11 2B 00 00`
  * `.MinimumChannels`: `1`
  * `.MaximumChannels`: `2`
  * `.ChannelsGranularity`: `1`
  * `.MinimumBitsPerSample`: `8`
  * `.MaximumBitsPerSample`: `16`
  * `.BitsPerSampleGranularity`: `8`
  * `.MinimumSampleFrequency`: `11025`
  * `.MaximumSampleFrequency`: `44100`
  * `.SampleFrequencyGranularity`: `11025`

#### Capability: 8

 * `AM_MEDIA_TYPE`:
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 00 00 02 00 00 00 81 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 00 00 12 00 00 00 C8 D3 61 00`
  * Format Data: `01 00 01 00 11 2B 00 00 22 56 00 00 02 00 10 00 00 00`
  * `.subtype`: `FourCC 0x00000001`
  * `.bFixedSizeSamples`: `1`
  * `.bTemporalCompression`: `0`
  * `.lSampleSize`: `2`
  * `.cbFormat`: `18`
  * `WAVEFORMATEX`:
   * `.wFormatTag`: `1`
   * `.nChannels`: `1`
   * `.nSamplesPerSec`: `11025`
   * `.nAvgBytesPerSec: `22050`
   * `.nBlockAlign`: `2`
   * `.wBitsPerSample`: `16`
   * `.cbSize`: `0`
 * `AUDIO_STREAM_CONFIG_CAPS`:
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 02 00 00 00 01 00 00 00 08 00 00 00 10 00 00 00 08 00 00 00 11 2B 00 00 44 AC 00 00 11 2B 00 00`
  * `.MinimumChannels`: `1`
  * `.MaximumChannels`: `2`
  * `.ChannelsGranularity`: `1`
  * `.MinimumBitsPerSample`: `8`
  * `.MaximumBitsPerSample`: `16`
  * `.BitsPerSampleGranularity`: `8`
  * `.MinimumSampleFrequency`: `11025`
  * `.MaximumSampleFrequency`: `44100`
  * `.SampleFrequencyGranularity`: `11025`

#### Capability: 9

 * `AM_MEDIA_TYPE`:
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 00 00 04 00 00 00 81 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 00 00 12 00 00 00 C8 D3 61 00`
  * Format Data: `01 00 02 00 40 1F 00 00 00 7D 00 00 04 00 10 00 00 00`
  * `.subtype`: `FourCC 0x00000001`
  * `.bFixedSizeSamples`: `1`
  * `.bTemporalCompression`: `0`
  * `.lSampleSize`: `4`
  * `.cbFormat`: `18`
  * `WAVEFORMATEX`:
   * `.wFormatTag`: `1`
   * `.nChannels`: `2`
   * `.nSamplesPerSec`: `8000`
   * `.nAvgBytesPerSec: `32000`
   * `.nBlockAlign`: `4`
   * `.wBitsPerSample`: `16`
   * `.cbSize`: `0`
 * `AUDIO_STREAM_CONFIG_CAPS`:
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 02 00 00 00 01 00 00 00 08 00 00 00 10 00 00 00 08 00 00 00 11 2B 00 00 44 AC 00 00 11 2B 00 00`
  * `.MinimumChannels`: `1`
  * `.MaximumChannels`: `2`
  * `.ChannelsGranularity`: `1`
  * `.MinimumBitsPerSample`: `8`
  * `.MaximumBitsPerSample`: `16`
  * `.BitsPerSampleGranularity`: `8`
  * `.MinimumSampleFrequency`: `11025`
  * `.MaximumSampleFrequency`: `44100`
  * `.SampleFrequencyGranularity`: `11025`

#### Capability: 10

 * `AM_MEDIA_TYPE`:
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 00 00 02 00 00 00 81 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 00 00 12 00 00 00 C8 D3 61 00`
  * Format Data: `01 00 01 00 40 1F 00 00 80 3E 00 00 02 00 10 00 00 00`
  * `.subtype`: `FourCC 0x00000001`
  * `.bFixedSizeSamples`: `1`
  * `.bTemporalCompression`: `0`
  * `.lSampleSize`: `2`
  * `.cbFormat`: `18`
  * `WAVEFORMATEX`:
   * `.wFormatTag`: `1`
   * `.nChannels`: `1`
   * `.nSamplesPerSec`: `8000`
   * `.nAvgBytesPerSec: `16000`
   * `.nBlockAlign`: `2`
   * `.wBitsPerSample`: `16`
   * `.cbSize`: `0`
 * `AUDIO_STREAM_CONFIG_CAPS`:
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 02 00 00 00 01 00 00 00 08 00 00 00 10 00 00 00 08 00 00 00 11 2B 00 00 44 AC 00 00 11 2B 00 00`
  * `.MinimumChannels`: `1`
  * `.MaximumChannels`: `2`
  * `.ChannelsGranularity`: `1`
  * `.MinimumBitsPerSample`: `8`
  * `.MaximumBitsPerSample`: `16`
  * `.BitsPerSampleGranularity`: `8`
  * `.MinimumSampleFrequency`: `11025`
  * `.MaximumSampleFrequency`: `44100`
  * `.SampleFrequencyGranularity`: `11025`

#### Capability: 11

 * `AM_MEDIA_TYPE`:
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 00 00 02 00 00 00 81 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 00 00 12 00 00 00 C8 D3 61 00`
  * Format Data: `01 00 02 00 44 AC 00 00 88 58 01 00 02 00 08 00 00 00`
  * `.subtype`: `FourCC 0x00000001`
  * `.bFixedSizeSamples`: `1`
  * `.bTemporalCompression`: `0`
  * `.lSampleSize`: `2`
  * `.cbFormat`: `18`
  * `WAVEFORMATEX`:
   * `.wFormatTag`: `1`
   * `.nChannels`: `2`
   * `.nSamplesPerSec`: `44100`
   * `.nAvgBytesPerSec: `88200`
   * `.nBlockAlign`: `2`
   * `.wBitsPerSample`: `8`
   * `.cbSize`: `0`
 * `AUDIO_STREAM_CONFIG_CAPS`:
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 02 00 00 00 01 00 00 00 08 00 00 00 10 00 00 00 08 00 00 00 11 2B 00 00 44 AC 00 00 11 2B 00 00`
  * `.MinimumChannels`: `1`
  * `.MaximumChannels`: `2`
  * `.ChannelsGranularity`: `1`
  * `.MinimumBitsPerSample`: `8`
  * `.MaximumBitsPerSample`: `16`
  * `.BitsPerSampleGranularity`: `8`
  * `.MinimumSampleFrequency`: `11025`
  * `.MaximumSampleFrequency`: `44100`
  * `.SampleFrequencyGranularity`: `11025`

#### Capability: 12

 * `AM_MEDIA_TYPE`:
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 00 00 01 00 00 00 81 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 00 00 12 00 00 00 C8 D3 61 00`
  * Format Data: `01 00 01 00 44 AC 00 00 44 AC 00 00 01 00 08 00 00 00`
  * `.subtype`: `FourCC 0x00000001`
  * `.bFixedSizeSamples`: `1`
  * `.bTemporalCompression`: `0`
  * `.lSampleSize`: `1`
  * `.cbFormat`: `18`
  * `WAVEFORMATEX`:
   * `.wFormatTag`: `1`
   * `.nChannels`: `1`
   * `.nSamplesPerSec`: `44100`
   * `.nAvgBytesPerSec: `44100`
   * `.nBlockAlign`: `1`
   * `.wBitsPerSample`: `8`
   * `.cbSize`: `0`
 * `AUDIO_STREAM_CONFIG_CAPS`:
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 02 00 00 00 01 00 00 00 08 00 00 00 10 00 00 00 08 00 00 00 11 2B 00 00 44 AC 00 00 11 2B 00 00`
  * `.MinimumChannels`: `1`
  * `.MaximumChannels`: `2`
  * `.ChannelsGranularity`: `1`
  * `.MinimumBitsPerSample`: `8`
  * `.MaximumBitsPerSample`: `16`
  * `.BitsPerSampleGranularity`: `8`
  * `.MinimumSampleFrequency`: `11025`
  * `.MaximumSampleFrequency`: `44100`
  * `.SampleFrequencyGranularity`: `11025`

#### Capability: 13

 * `AM_MEDIA_TYPE`:
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 00 00 02 00 00 00 81 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 00 00 12 00 00 00 C8 D3 61 00`
  * Format Data: `01 00 02 00 22 56 00 00 44 AC 00 00 02 00 08 00 00 00`
  * `.subtype`: `FourCC 0x00000001`
  * `.bFixedSizeSamples`: `1`
  * `.bTemporalCompression`: `0`
  * `.lSampleSize`: `2`
  * `.cbFormat`: `18`
  * `WAVEFORMATEX`:
   * `.wFormatTag`: `1`
   * `.nChannels`: `2`
   * `.nSamplesPerSec`: `22050`
   * `.nAvgBytesPerSec: `44100`
   * `.nBlockAlign`: `2`
   * `.wBitsPerSample`: `8`
   * `.cbSize`: `0`
 * `AUDIO_STREAM_CONFIG_CAPS`:
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 02 00 00 00 01 00 00 00 08 00 00 00 10 00 00 00 08 00 00 00 11 2B 00 00 44 AC 00 00 11 2B 00 00`
  * `.MinimumChannels`: `1`
  * `.MaximumChannels`: `2`
  * `.ChannelsGranularity`: `1`
  * `.MinimumBitsPerSample`: `8`
  * `.MaximumBitsPerSample`: `16`
  * `.BitsPerSampleGranularity`: `8`
  * `.MinimumSampleFrequency`: `11025`
  * `.MaximumSampleFrequency`: `44100`
  * `.SampleFrequencyGranularity`: `11025`

#### Capability: 14

 * `AM_MEDIA_TYPE`:
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 00 00 01 00 00 00 81 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 00 00 12 00 00 00 C8 D3 61 00`
  * Format Data: `01 00 01 00 22 56 00 00 22 56 00 00 01 00 08 00 00 00`
  * `.subtype`: `FourCC 0x00000001`
  * `.bFixedSizeSamples`: `1`
  * `.bTemporalCompression`: `0`
  * `.lSampleSize`: `1`
  * `.cbFormat`: `18`
  * `WAVEFORMATEX`:
   * `.wFormatTag`: `1`
   * `.nChannels`: `1`
   * `.nSamplesPerSec`: `22050`
   * `.nAvgBytesPerSec: `22050`
   * `.nBlockAlign`: `1`
   * `.wBitsPerSample`: `8`
   * `.cbSize`: `0`
 * `AUDIO_STREAM_CONFIG_CAPS`:
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 02 00 00 00 01 00 00 00 08 00 00 00 10 00 00 00 08 00 00 00 11 2B 00 00 44 AC 00 00 11 2B 00 00`
  * `.MinimumChannels`: `1`
  * `.MaximumChannels`: `2`
  * `.ChannelsGranularity`: `1`
  * `.MinimumBitsPerSample`: `8`
  * `.MaximumBitsPerSample`: `16`
  * `.BitsPerSampleGranularity`: `8`
  * `.MinimumSampleFrequency`: `11025`
  * `.MaximumSampleFrequency`: `44100`
  * `.SampleFrequencyGranularity`: `11025`

#### Capability: 15

 * `AM_MEDIA_TYPE`:
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 00 00 02 00 00 00 81 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 00 00 12 00 00 00 C8 D3 61 00`
  * Format Data: `01 00 02 00 11 2B 00 00 22 56 00 00 02 00 08 00 00 00`
  * `.subtype`: `FourCC 0x00000001`
  * `.bFixedSizeSamples`: `1`
  * `.bTemporalCompression`: `0`
  * `.lSampleSize`: `2`
  * `.cbFormat`: `18`
  * `WAVEFORMATEX`:
   * `.wFormatTag`: `1`
   * `.nChannels`: `2`
   * `.nSamplesPerSec`: `11025`
   * `.nAvgBytesPerSec: `22050`
   * `.nBlockAlign`: `2`
   * `.wBitsPerSample`: `8`
   * `.cbSize`: `0`
 * `AUDIO_STREAM_CONFIG_CAPS`:
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 02 00 00 00 01 00 00 00 08 00 00 00 10 00 00 00 08 00 00 00 11 2B 00 00 44 AC 00 00 11 2B 00 00`
  * `.MinimumChannels`: `1`
  * `.MaximumChannels`: `2`
  * `.ChannelsGranularity`: `1`
  * `.MinimumBitsPerSample`: `8`
  * `.MaximumBitsPerSample`: `16`
  * `.BitsPerSampleGranularity`: `8`
  * `.MinimumSampleFrequency`: `11025`
  * `.MaximumSampleFrequency`: `44100`
  * `.SampleFrequencyGranularity`: `11025`

#### Capability: 16

 * `AM_MEDIA_TYPE`:
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 00 00 01 00 00 00 81 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 00 00 12 00 00 00 C8 D3 61 00`
  * Format Data: `01 00 01 00 11 2B 00 00 11 2B 00 00 01 00 08 00 00 00`
  * `.subtype`: `FourCC 0x00000001`
  * `.bFixedSizeSamples`: `1`
  * `.bTemporalCompression`: `0`
  * `.lSampleSize`: `1`
  * `.cbFormat`: `18`
  * `WAVEFORMATEX`:
   * `.wFormatTag`: `1`
   * `.nChannels`: `1`
   * `.nSamplesPerSec`: `11025`
   * `.nAvgBytesPerSec: `11025`
   * `.nBlockAlign`: `1`
   * `.wBitsPerSample`: `8`
   * `.cbSize`: `0`
 * `AUDIO_STREAM_CONFIG_CAPS`:
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 02 00 00 00 01 00 00 00 08 00 00 00 10 00 00 00 08 00 00 00 11 2B 00 00 44 AC 00 00 11 2B 00 00`
  * `.MinimumChannels`: `1`
  * `.MaximumChannels`: `2`
  * `.ChannelsGranularity`: `1`
  * `.MinimumBitsPerSample`: `8`
  * `.MaximumBitsPerSample`: `16`
  * `.BitsPerSampleGranularity`: `8`
  * `.MinimumSampleFrequency`: `11025`
  * `.MaximumSampleFrequency`: `44100`
  * `.SampleFrequencyGranularity`: `11025`

#### Capability: 17

 * `AM_MEDIA_TYPE`:
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 00 00 02 00 00 00 81 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 00 00 12 00 00 00 C8 D3 61 00`
  * Format Data: `01 00 02 00 40 1F 00 00 80 3E 00 00 02 00 08 00 00 00`
  * `.subtype`: `FourCC 0x00000001`
  * `.bFixedSizeSamples`: `1`
  * `.bTemporalCompression`: `0`
  * `.lSampleSize`: `2`
  * `.cbFormat`: `18`
  * `WAVEFORMATEX`:
   * `.wFormatTag`: `1`
   * `.nChannels`: `2`
   * `.nSamplesPerSec`: `8000`
   * `.nAvgBytesPerSec: `16000`
   * `.nBlockAlign`: `2`
   * `.wBitsPerSample`: `8`
   * `.cbSize`: `0`
 * `AUDIO_STREAM_CONFIG_CAPS`:
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 02 00 00 00 01 00 00 00 08 00 00 00 10 00 00 00 08 00 00 00 11 2B 00 00 44 AC 00 00 11 2B 00 00`
  * `.MinimumChannels`: `1`
  * `.MaximumChannels`: `2`
  * `.ChannelsGranularity`: `1`
  * `.MinimumBitsPerSample`: `8`
  * `.MaximumBitsPerSample`: `16`
  * `.BitsPerSampleGranularity`: `8`
  * `.MinimumSampleFrequency`: `11025`
  * `.MaximumSampleFrequency`: `44100`
  * `.SampleFrequencyGranularity`: `11025`

#### Capability: 18

 * `AM_MEDIA_TYPE`:
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 00 00 01 00 00 00 81 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 00 00 12 00 00 00 C8 D3 61 00`
  * Format Data: `01 00 01 00 40 1F 00 00 40 1F 00 00 01 00 08 00 00 00`
  * `.subtype`: `FourCC 0x00000001`
  * `.bFixedSizeSamples`: `1`
  * `.bTemporalCompression`: `0`
  * `.lSampleSize`: `1`
  * `.cbFormat`: `18`
  * `WAVEFORMATEX`:
   * `.wFormatTag`: `1`
   * `.nChannels`: `1`
   * `.nSamplesPerSec`: `8000`
   * `.nAvgBytesPerSec: `8000`
   * `.nBlockAlign`: `1`
   * `.wBitsPerSample`: `8`
   * `.cbSize`: `0`
 * `AUDIO_STREAM_CONFIG_CAPS`:
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 02 00 00 00 01 00 00 00 08 00 00 00 10 00 00 00 08 00 00 00 11 2B 00 00 44 AC 00 00 11 2B 00 00`
  * `.MinimumChannels`: `1`
  * `.MaximumChannels`: `2`
  * `.ChannelsGranularity`: `1`
  * `.MinimumBitsPerSample`: `8`
  * `.MaximumBitsPerSample`: `16`
  * `.BitsPerSampleGranularity`: `8`
  * `.MinimumSampleFrequency`: `11025`
  * `.MaximumSampleFrequency`: `44100`
  * `.SampleFrequencyGranularity`: `11025`

#### Capability: 19

 * `AM_MEDIA_TYPE`:
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 00 00 04 00 00 00 81 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 00 00 12 00 00 00 C8 D3 61 00`
  * Format Data: `01 00 02 00 80 BB 00 00 00 EE 02 00 04 00 10 00 00 00`
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
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 02 00 00 00 01 00 00 00 08 00 00 00 10 00 00 00 08 00 00 00 11 2B 00 00 44 AC 00 00 11 2B 00 00`
  * `.MinimumChannels`: `1`
  * `.MaximumChannels`: `2`
  * `.ChannelsGranularity`: `1`
  * `.MinimumBitsPerSample`: `8`
  * `.MaximumBitsPerSample`: `16`
  * `.BitsPerSampleGranularity`: `8`
  * `.MinimumSampleFrequency`: `11025`
  * `.MaximumSampleFrequency`: `44100`
  * `.SampleFrequencyGranularity`: `11025`

#### Capability: 20

 * `AM_MEDIA_TYPE`:
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 00 00 02 00 00 00 81 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 00 00 12 00 00 00 C8 D3 61 00`
  * Format Data: `01 00 01 00 80 BB 00 00 00 77 01 00 02 00 10 00 00 00`
  * `.subtype`: `FourCC 0x00000001`
  * `.bFixedSizeSamples`: `1`
  * `.bTemporalCompression`: `0`
  * `.lSampleSize`: `2`
  * `.cbFormat`: `18`
  * `WAVEFORMATEX`:
   * `.wFormatTag`: `1`
   * `.nChannels`: `1`
   * `.nSamplesPerSec`: `48000`
   * `.nAvgBytesPerSec: `96000`
   * `.nBlockAlign`: `2`
   * `.wBitsPerSample`: `16`
   * `.cbSize`: `0`
 * `AUDIO_STREAM_CONFIG_CAPS`:
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 02 00 00 00 01 00 00 00 08 00 00 00 10 00 00 00 08 00 00 00 11 2B 00 00 44 AC 00 00 11 2B 00 00`
  * `.MinimumChannels`: `1`
  * `.MaximumChannels`: `2`
  * `.ChannelsGranularity`: `1`
  * `.MinimumBitsPerSample`: `8`
  * `.MaximumBitsPerSample`: `16`
  * `.BitsPerSampleGranularity`: `8`
  * `.MinimumSampleFrequency`: `11025`
  * `.MaximumSampleFrequency`: `44100`
  * `.SampleFrequencyGranularity`: `11025`

#### Capability: 21

 * `AM_MEDIA_TYPE`:
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 00 00 04 00 00 00 81 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 00 00 12 00 00 00 C8 D3 61 00`
  * Format Data: `01 00 02 00 00 77 01 00 00 DC 05 00 04 00 10 00 00 00`
  * `.subtype`: `FourCC 0x00000001`
  * `.bFixedSizeSamples`: `1`
  * `.bTemporalCompression`: `0`
  * `.lSampleSize`: `4`
  * `.cbFormat`: `18`
  * `WAVEFORMATEX`:
   * `.wFormatTag`: `1`
   * `.nChannels`: `2`
   * `.nSamplesPerSec`: `96000`
   * `.nAvgBytesPerSec: `384000`
   * `.nBlockAlign`: `4`
   * `.wBitsPerSample`: `16`
   * `.cbSize`: `0`
 * `AUDIO_STREAM_CONFIG_CAPS`:
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 02 00 00 00 01 00 00 00 08 00 00 00 10 00 00 00 08 00 00 00 11 2B 00 00 44 AC 00 00 11 2B 00 00`
  * `.MinimumChannels`: `1`
  * `.MaximumChannels`: `2`
  * `.ChannelsGranularity`: `1`
  * `.MinimumBitsPerSample`: `8`
  * `.MaximumBitsPerSample`: `16`
  * `.BitsPerSampleGranularity`: `8`
  * `.MinimumSampleFrequency`: `11025`
  * `.MaximumSampleFrequency`: `44100`
  * `.SampleFrequencyGranularity`: `11025`

#### Capability: 22

 * `AM_MEDIA_TYPE`:
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 00 00 00 00 02 00 00 00 81 9F 58 05 56 C3 CE 11 BF 01 00 AA 00 55 59 5A 00 00 00 00 12 00 00 00 C8 D3 61 00`
  * Format Data: `01 00 01 00 00 77 01 00 00 EE 02 00 02 00 10 00 00 00`
  * `.subtype`: `FourCC 0x00000001`
  * `.bFixedSizeSamples`: `1`
  * `.bTemporalCompression`: `0`
  * `.lSampleSize`: `2`
  * `.cbFormat`: `18`
  * `WAVEFORMATEX`:
   * `.wFormatTag`: `1`
   * `.nChannels`: `1`
   * `.nSamplesPerSec`: `96000`
   * `.nAvgBytesPerSec: `192000`
   * `.nBlockAlign`: `2`
   * `.wBitsPerSample`: `16`
   * `.cbSize`: `0`
 * `AUDIO_STREAM_CONFIG_CAPS`:
  * Data: `61 75 64 73 00 00 10 00 80 00 00 AA 00 38 9B 71 01 00 00 00 02 00 00 00 01 00 00 00 08 00 00 00 10 00 00 00 08 00 00 00 11 2B 00 00 44 AC 00 00 11 2B 00 00`
  * `.MinimumChannels`: `1`
  * `.MaximumChannels`: `2`
  * `.ChannelsGranularity`: `1`
  * `.MinimumBitsPerSample`: `8`
  * `.MaximumBitsPerSample`: `16`
  * `.BitsPerSampleGranularity`: `8`
  * `.MinimumSampleFrequency`: `11025`
  * `.MaximumSampleFrequency`: `44100`
  * `.SampleFrequencyGranularity`: `11025`

Interfaces:

  * `IKsPropertySet`
  * `IQualityControl`
  * `IAMBufferNegotiation`
  * `IAMStreamConfig`
  * `IAMStreamControl`

### Pin: Master Volume

 * Direction: `PINDIR_INPUT`
Interfaces:

  * `IQualityControl`

