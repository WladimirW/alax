

# System

 * Version: 6.3.9600, Windows 8.1, VER_SUITE_SINGLEUSERTS, VER_NT_WORKSTATION
 * Product: PRODUCT_PROFESSIONAL
 * Computer Name: `chris`
 * User Name: `chris\chris2` 
 * Locale: System `zh-TW`, User `en-US`
 * Local Time: `4/12/2017 2:32:52 PM`
 * Architecture: AMD/Intel x64 (x64 Application)
 * Processors: `4`, Active Mask `0xF`
 * Page Size: `0x1000`
 * Application Address Space: `0x0000000000010000`..`0x00007FFFFFFEFFFF`
 * Physical Memory: `8,151` MB
 * Committed Memory Limit: `16,343` MB
 * Application Version: `1.0.0.69`

# Display Devices

 * NVIDIA GeForce GT 220 
  * Instance: PCI\VEN_10DE&DEV_0A20&SUBSYS_34D81458&REV_A2\4&932E434&0&0018
  * DEVPKEY_Device_Manufacturer: NVIDIA
  * DEVPKEY_Device_DriverVersion: 9.18.13.4192

# Category `MFT_CATEGORY_VIDEO_ENCODER`

## NVIDIA Video Encoder MFT

7 Attributes:

 * MFT_TRANSFORM_CLSID_Attribute: {305AFD76-ADD0-417E-AA99-3AC4FDB22B21} (Type VT_CLSID)
 * MF_TRANSFORM_FLAGS_Attribute: MFT_ENUM_FLAG_HARDWARE
 * MFT_INPUT_TYPES_Attributes: MFVideoFormat_NV12
 * MFT_OUTPUT_TYPES_Attributes: MFVideoFormat_H264, MFVideoFormat_WMV3
 * MFT_CODEC_MERIT_Attribute: 8 (Type VT_UI4)

## H264 Encoder MFT

6 Attributes:

 * MFT_TRANSFORM_CLSID_Attribute: {6CA50344-051A-4DED-9779-A43305165E35} (Type VT_CLSID)
 * MF_TRANSFORM_FLAGS_Attribute: MFT_ENUM_FLAG_SYNCMFT
 * MFT_INPUT_TYPES_Attributes: MFVideoFormat_IYUV, MFVideoFormat_YV12, MFVideoFormat_NV12, MFVideoFormat_YUY2
 * MFT_OUTPUT_TYPES_Attributes: MFVideoFormat_H264

### IMFTransform

 * Stream Limits: Input 1..1, Output 1..1
 * Streams: Input 1, Output 1

#### Attributes

 * MFT_ENCODER_SUPPORTS_CONFIG_EVENT: 1 (Type VT_UI4)

#### Input Stream 0

#### Output Stream 0

### ICodecAPI

 * `CODECAPI_AVEncCommonRateControlMode`: VT_UI4 0
 * `CODECAPI_AVEncCommonQuality`: VT_UI4 65
 * `CODECAPI_AVEncCommonQualityVsSpeed`: VT_UI4 33
 * `CODECAPI_AVEncCommonMeanBitRate`: VT_UI4 500000
 * `CODECAPI_AVEncCommonMaxBitRate`: VT_UI4 0
 * `CODECAPI_AVEncCommonBufferSize`: VT_UI4 0
 * `CODECAPI_AVEncH264CABACEnable`: VT_BOOL 0
 * `CODECAPI_AVEncVideoContentType`: VT_UI4 0
 * `CODECAPI_AVEncNumWorkerThreads`: VT_UI4 0
 * `CODECAPI_AVEncVideoEncodeQP`: VT_UI8 26
 * `CODECAPI_AVEncVideoMinQP`: VT_UI4 0, minimal VT_UI4 0, maximal VT_UI4 51, step VT_UI4 1
 * `CODECAPI_AVEncVideoForceKeyFrame`: VT_UI4 0
 * `CODECAPI_AVEncH264SPSID`: VT_UI4 0
 * `CODECAPI_AVEncH264PPSID`: VT_UI4 0
 * `CODECAPI_AVEncAdaptiveMode`: VT_UI4 0
 * `CODECAPI_AVEncVideoSelectLayer`: VT_UI4 0
 * `CODECAPI_AVEncVideoTemporalLayerCount`: VT_UI4 1, minimal VT_UI4 1, maximal VT_UI4 3, step VT_UI4 1
 * `CODECAPI_AVEncVideoEncodeFrameTypeQP`: VT_UI8 18446744073709551615
 * `CODECAPI_AVEncSliceControlMode`: minimal VT_UI4 0, maximal VT_UI4 2, step VT_UI4 1
 * `CODECAPI_AVEncSliceControlSize`: VT_UI4 0, minimal VT_UI4 0, maximal VT_UI4 4294967295, step VT_UI4 1
 * `CODECAPI_AVEncVideoMaxNumRefFrame`: VT_UI4 2, minimal VT_UI4 1, maximal VT_UI4 7, step VT_UI4 1
 * `CODECAPI_AVEncVideoMeanAbsoluteDifference`: VT_UI4 0
 * `CODECAPI_AVEncVideoMaxQP`: VT_UI4 51, minimal VT_UI4 0, maximal VT_UI4 51, step VT_UI4 1
 * `CODECAPI_AVEncVideoLTRBufferControl`: VT_UI4 0, values { VT_UI4 65536, VT_UI4 65537, VT_UI4 65538, VT_UI4 65539, VT_UI4 65540, VT_UI4 65541 }
 * `CODECAPI_AVEncVideoMarkLTRFrame`: VT_UI4 0
 * `CODECAPI_AVEncVideoUseLTRFrame`: VT_UI4 0
 * `CODECAPI_AVEncVideoROIEnabled`: VT_UI4 0
 * `CODECAPI_AVEncMPVGOPSize`: VT_UI4 0
 * `CODECAPI_AVEncMPVDefaultBPictureCount`: VT_UI4 1
 * `CODECAPI_AVLowLatencyMode`: VT_BOOL 0

#### Rate Control Modes

Mode UnconstrainedVBR

 * Accepted
 * AVEncCommonMeanBitRate 5120 kBps Accepted

Mode Quality

 * Accepted
 * AVEncCommonQuality 70 Accepted

Mode CBR

 * Accepted
 * AVEncCommonMeanBitRate 5120 kBps Accepted

Mode PeakConstrainedVBR

 * Accepted
 * AVEncCommonMeanBitRate 5120 kBps Accepted
 * AVEncCommonMaxBitRate 12288 kBps Accepted

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

### ICodecAPI

 * `CODECAPI_AVEncCommonRateControlMode`: 
 * `CODECAPI_AVEncCommonQuality`: 
 * `CODECAPI_AVEncCommonQualityVsSpeed`: 
 * `CODECAPI_AVEncCommonTranscodeEncodingProfile`: 
 * `CODECAPI_AVEncCommonMeanBitRate`: 
 * `CODECAPI_AVEncCommonMaxBitRate`: 
 * `CODECAPI_AVEncCommonBufferSize`: 
 * `CODECAPI_AVEncVideoEncodeQP`: 
 * `CODECAPI_AVEncVideoForceKeyFrame`: 
 * `CODECAPI_AVEncMPVGOPSize`: 
 * `CODECAPI_AVEncMPVDefaultBPictureCount`: 
 * `CODECAPI_AVLowLatencyMode`: 

## Microsoft MPEG-2 Video Encoder MFT

6 Attributes:

 * MFT_TRANSFORM_CLSID_Attribute: {E6335F02-80B7-4DC4-ADFA-DFE7210D20D5} (Type VT_CLSID)
 * MF_TRANSFORM_FLAGS_Attribute: MFT_ENUM_FLAG_ASYNCMFT
 * MFT_INPUT_TYPES_Attributes: MFVideoFormat_IYUV, MFVideoFormat_NV12, MFVideoFormat_YV12
 * MFT_OUTPUT_TYPES_Attributes: MFVideoFormat_MPEG2

