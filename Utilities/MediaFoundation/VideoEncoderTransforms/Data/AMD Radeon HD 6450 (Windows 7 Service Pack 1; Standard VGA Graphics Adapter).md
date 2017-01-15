

# System

 * Version: 6.1.7601, Windows 7, Service Pack 1.0, VER_SUITE_SINGLEUSERTS | VER_SUITE_PERSONAL, VER_NT_WORKSTATION
 * Product: PRODUCT_HOME_PREMIUM
 * Computer Name: `lostjhow-PC`
 * User Name: `lostjhow-PC\lostjhow` 
 * Local Time: `14/01/2017 07:33:41`
 * Architecture: AMD/Intel x64 (x64 Application)
 * Processors: `2`, Active Mask `0x3`
 * Page Size: `0x1000`
 * Application Address Space: `0x0000000000010000`..`0x000007FFFFFEFFFF`
 * Physical Memory: `3.071` MB
 * Committed Memory Limit: `6.140` MB
 * Application Version: `1.0.0.53`

# Display Devices

 * Standard VGA Graphics Adapter
  * Instance: PCI\VEN_1002&DEV_6779&SUBSYS_32001682&REV_00\4&26BFB1BA&0&0008
  * DEVPKEY_Device_Manufacturer: (Tipos padrão de vídeo)
  * DEVPKEY_Device_DriverVersion: 6.1.7600.16385

# Category `MFT_CATEGORY_VIDEO_ENCODER`

## H264 Encoder MFT

6 Attributes:

 * MFT_TRANSFORM_CLSID_Attribute: {6CA50344-051A-4DED-9779-A43305165E35} (Type VT_CLSID)
 * MF_TRANSFORM_FLAGS_Attribute: MFT_ENUM_FLAG_SYNCMFT
 * MFT_INPUT_TYPES_Attributes: MFVideoFormat_IYUV, MFVideoFormat_YV12, MFVideoFormat_NV12, MFVideoFormat_YUY2
 * MFT_OUTPUT_TYPES_Attributes: MFVideoFormat_H264

### IMFTransform

 * Stream Limits: Input 1..1, Output 1..1
 * Streams: Input 1, Output 1

#### Input Stream 0

#### Output Stream 0

### ICodecAPI

 * `CODECAPI_AVEncCommonRateControlMode`: VT_UI4 0
 * `CODECAPI_AVEncCommonQuality`: VT_UI4 0

## WMVideo8 Encoder MFT

6 Attributes:

 * MFT_TRANSFORM_CLSID_Attribute: {7E320092-596A-41B2-BBEB-175D10504EB6} (Type VT_CLSID)
 * MF_TRANSFORM_FLAGS_Attribute: MFT_ENUM_FLAG_SYNCMFT
 * MFT_INPUT_TYPES_Attributes: MFVideoFormat_IYUV, MFVideoFormat_I420, MFVideoFormat_YV12, MFVideoFormat_NV11, MFVideoFormat_NV12, MFVideoFormat_YUY2, MFVideoFormat_UYVY, MFVideoFormat_YVYU, MFVideoFormat_YVU9, {00000016-524F-11CE-9F53-0020AF0BA770}, {00000014-524F-11CE-9F53-0020AF0BA770}, {00000017-524F-11CE-9F53-0020AF0BA770}, {00000018-524F-11CE-9F53-0020AF0BA770}, {00000029-524F-11CE-9F53-0020AF0BA770}
 * MFT_OUTPUT_TYPES_Attributes: MFVideoFormat_WMV1, MFVideoFormat_WMV2

### IMFTransform

 * Stream Limits: Input 1..1, Output 2..2
 * Streams: Input 1, Output 2

#### Input Stream 0

#### Output Stream 0

#### Output Stream 1

## AMD H.264 Hardware MFT Encoder

10 Attributes:

 * MFT_TRANSFORM_CLSID_Attribute: {ADC9BC80-0F41-46C6-AB75-D693D793597D} (Type VT_CLSID)
 * MF_TRANSFORM_FLAGS_Attribute: MFT_ENUM_FLAG_HARDWARE
 * MFT_ENUM_HARDWARE_VENDOR_ID_Attribute: AMD (Type VT_LPWSTR)
 * MFT_ENUM_HARDWARE_URL_Attribute: AMDh264Encoder (Type VT_LPWSTR)
 * MFT_INPUT_TYPES_Attributes: MFVideoFormat_NV12
 * MFT_OUTPUT_TYPES_Attributes: MFVideoFormat_H264
 * MFT_CODEC_MERIT_Attribute: 8 (Type VT_UI4)
 * MFT_SUPPORT_DYNAMIC_FORMAT_CHANGE: 1 (Type VT_UI4)

## WMVideo9 Encoder MFT

6 Attributes:

 * MFT_TRANSFORM_CLSID_Attribute: {D23B90D0-144F-46BD-841D-59E4EB19DC59} (Type VT_CLSID)
 * MF_TRANSFORM_FLAGS_Attribute: MFT_ENUM_FLAG_SYNCMFT
 * MFT_INPUT_TYPES_Attributes: MFVideoFormat_IYUV, MFVideoFormat_I420, MFVideoFormat_YV12, MFVideoFormat_NV11, MFVideoFormat_NV12, MFVideoFormat_YUY2, MFVideoFormat_UYVY, MFVideoFormat_YVYU, MFVideoFormat_YVU9, {00000016-524F-11CE-9F53-0020AF0BA770}, {00000014-524F-11CE-9F53-0020AF0BA770}, {00000017-524F-11CE-9F53-0020AF0BA770}, {00000018-524F-11CE-9F53-0020AF0BA770}, {00000029-524F-11CE-9F53-0020AF0BA770}, WMMEDIASUBTYPE_VIDEOIMAGE
 * MFT_OUTPUT_TYPES_Attributes: MFVideoFormat_WMV3, WMMEDIASUBTYPE_WMVP, WMMEDIASUBTYPE_WVP2, WMMEDIASUBTYPE_WMVA, MFVideoFormat_WVC1

### IMFTransform

 * Stream Limits: Input 1..1, Output 2..2
 * Streams: Input 1, Output 2

#### Input Stream 0

#### Output Stream 0

#### Output Stream 1

