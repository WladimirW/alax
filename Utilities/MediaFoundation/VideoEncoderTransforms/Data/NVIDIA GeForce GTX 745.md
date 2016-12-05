

# System

 * Version: 10.0.14393, Windows 10, VER_SUITE_SINGLEUSERTS | VER_SUITE_PERSONAL, VER_NT_WORKSTATION
 * Product: PRODUCT_CORE
 * Computer Name: ``
 * User Name: `DESKTOP-IV7VAQ6\DELF` 
 * Local Time: `05.12.2016 14:50:55`
 * Architecture: AMD/Intel x64 (x64 Application)
 * Processors: `4`, Active Mask `0xF`
 * Page Size: `0x1000`
 * Application Address Space: `0x0000000000010000`..`0x00007FFFFFFEFFFF`
 * Physical Memory: `8.148` MB
 * Committed Memory Limit: `9.428` MB
 * Application Version: `1.0.0.53`

# Display Devices

 * NVIDIA GeForce GTX 745
  * Instance: PCI\VEN_10DE&DEV_1382&SUBSYS_249A174B&REV_A2\4&B2705F2&0&0008
  * DEVPKEY_Device_Manufacturer: NVIDIA
  * DEVPKEY_Device_DriverVersion: 21.21.13.6909

# Category `MFT_CATEGORY_VIDEO_ENCODER`

## NVIDIA H.264 Encoder MFT

11 Attributes:

 * MFT_TRANSFORM_CLSID_Attribute: {60F44560-5A20-4857-BFEF-D29773CB8040} (Type VT_CLSID)
 * MF_TRANSFORM_FLAGS_Attribute: MFT_ENUM_FLAG_HARDWARE
 * MFT_ENUM_HARDWARE_VENDOR_ID_Attribute: VEN_10DE (Type VT_LPWSTR)
 * MFT_ENUM_HARDWARE_URL_Attribute: NVIDIA H.264 Encoder MFT (Type VT_LPWSTR)
 * MFT_INPUT_TYPES_Attributes: MFVideoFormat_420O, MFVideoFormat_NV12
 * MFT_OUTPUT_TYPES_Attributes: MFVideoFormat_H264, TIME_FORMAT_NONE
 * MFT_CODEC_MERIT_Attribute: 8 (Type VT_UI4)
 * MF_TRANSFORM_ASYNC: 1 (Type VT_UI4)
 * MFT_GFX_DRIVER_VERSION_ID_Attribute: 9.18.13.5204

### IMFTransform

 * Streams: Input 1, Output 1

#### Attributes

 * MF_SA_D3D11_AWARE: 1 (Type VT_UI4)
 * MFT_ENUM_HARDWARE_URL_Attribute: NVIDIA H.264 Encoder MFT (Type VT_LPWSTR)
 * MFT_FRIENDLY_NAME_Attribute: NVIDIA H.264 Encoder MFT (Type VT_LPWSTR)
 * MFT_ENUM_HARDWARE_VENDOR_ID_Attribute: VEN_10DE (Type VT_LPWSTR)
 * MF_MT_MAJOR_TYPE: {73646976-0000-0010-8000-00AA00389B71} (Type VT_CLSID, MFMediaType_Video, FourCC vids)
 * MFT_SUPPORT_DYNAMIC_FORMAT_CHANGE: 1 (Type VT_UI4)
 * MFT_ENCODER_SUPPORTS_CONFIG_EVENT: 1 (Type VT_UI4)
 * MFT_CODEC_MERIT_Attribute: 8 (Type VT_UI4)
 * MF_VIDEO_MAX_MB_PER_SEC: 983040 (Type VT_UI4)
 * {F34B9093-05E0-4B16-993D-3E2A2CDE6AD3}: 5911064706095869 (Type VT_UI8, 0x00150015 0x000D1AFD, 1376277 858877)
 * MF_MT_SUBTYPE: {00000000-0000-0010-8000-00AA00389B71} (Type VT_CLSID, MFVideoFormat_Base, FourCC 0x00000000)
 * MF_TRANSFORM_ASYNC: 1 (Type VT_UI4)

#### Input Stream 0

#### Output Stream 0

### ICodecAPI

 * `CODECAPI_AVEncCommonRateControlMode`: VT_UI4 0
 * `CODECAPI_AVEncCommonQuality`: VT_UI4 65
 * `CODECAPI_AVEncCommonQualityVsSpeed`: VT_UI4 33
 * `CODECAPI_AVEncCommonMeanBitRate`: 
 * `CODECAPI_AVEncCommonMaxBitRate`: VT_UI4 0
 * `CODECAPI_AVEncCommonBufferSize`: 
 * `CODECAPI_AVEncH264CABACEnable`: VT_BOOL -1
 * `CODECAPI_AVEncVideoEncodeQP`: VT_UI8 26
 * `CODECAPI_AVEncVideoMinQP`: VT_UI4 0, minimal VT_UI4 0, maximal VT_UI4 51, step VT_UI4 1
 * `CODECAPI_AVEncVideoForceKeyFrame`: 
 * `CODECAPI_AVEncVideoSelectLayer`: VT_UI4 0
 * `CODECAPI_AVEncVideoTemporalLayerCount`: VT_UI4 1, minimal VT_UI4 1, maximal VT_UI4 3, step VT_UI4 1
 * `CODECAPI_AVEncVideoEncodeFrameTypeQP`: VT_UI8 111670853658
 * `CODECAPI_AVEncSliceControlMode`: VT_UI4 2, minimal VT_UI4 0, maximal VT_UI4 2, step VT_UI4 1
 * `CODECAPI_AVEncSliceControlSize`: minimal VT_UI4 0, maximal VT_UI4 3, step VT_UI4 1
 * `CODECAPI_AVEncVideoMaxNumRefFrame`: VT_UI4 2, minimal VT_UI4 0, maximal VT_UI4 16, step VT_UI4 1
 * `CODECAPI_AVEncVideoMeanAbsoluteDifference`: VT_UI4 0
 * `CODECAPI_AVEncVideoMaxQP`: VT_UI4 51, minimal VT_UI4 0, maximal VT_UI4 51, step VT_UI4 1
 * `CODECAPI_AVEncVideoLTRBufferControl`: VT_UI4 0, values { VT_I4 65537, VT_I4 65538 }
 * `CODECAPI_AVEncVideoMarkLTRFrame`: 
 * `CODECAPI_AVEncVideoUseLTRFrame`: 
 * `CODECAPI_AVEncVideoROIEnabled`: VT_UI4 0
 * `CODECAPI_AVEncMPVGOPSize`: 
 * `CODECAPI_AVLowLatencyMode`: VT_BOOL 0

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

## Microsoft MF VPX Encoder Transform

6 Attributes:

 * MFT_TRANSFORM_CLSID_Attribute: {AEB6C755-2546-4881-82CC-E15AE5EBFF3D} (Type VT_CLSID)
 * MF_TRANSFORM_FLAGS_Attribute: MFT_ENUM_FLAG_SYNCMFT
 * MFT_INPUT_TYPES_Attributes: MFVideoFormat_IYUV, MFVideoFormat_YV12, MFVideoFormat_NV12, MFVideoFormat_YUY2
 * MFT_OUTPUT_TYPES_Attributes: MFVideoFormat_VP80, MFVideoFormat_VP90

### IMFTransform

 * Stream Limits: Input 1..1, Output 1..1
 * Streams: Input 1, Output 1

#### Attributes

 * MFT_ENCODER_SUPPORTS_CONFIG_EVENT: 1 (Type VT_UI4)

#### Input Stream 0

#### Output Stream 0

### ICodecAPI

 * `CODECAPI_AVEncCommonRateControlMode`: VT_UI4 0
 * `CODECAPI_AVEncCommonQuality`: VT_UI4 63
 * `CODECAPI_AVEncCommonQualityVsSpeed`: VT_UI4 0
 * `CODECAPI_AVEncCommonMeanBitRate`: VT_UI4 500000
 * `CODECAPI_AVEncCommonMaxBitRate`: VT_UI4 0
 * `CODECAPI_AVEncCommonBufferSize`: VT_UI4 0
 * `CODECAPI_AVEncVideoContentType`: VT_UI4 0
 * `CODECAPI_AVEncNumWorkerThreads`: VT_UI4 0
 * `CODECAPI_AVEncVideoEncodeQP`: VT_UI8 26
 * `CODECAPI_AVEncVideoMinQP`: VT_UI4 0, minimal VT_UI4 0, maximal VT_UI4 51, step VT_UI4 1
 * `CODECAPI_AVEncVideoForceKeyFrame`: VT_UI4 0
 * `CODECAPI_AVEncVideoEncodeFrameTypeQP`: VT_UI8 18446744073709551615
 * `CODECAPI_AVEncVideoMaxQP`: VT_UI4 63, minimal VT_UI4 0, maximal VT_UI4 51, step VT_UI4 1
 * `CODECAPI_AVEncMPVGOPSize`: VT_UI4 0
 * `CODECAPI_AVLowLatencyMode`: VT_BOOL 0

## H263 Encoder MFT

6 Attributes:

 * MFT_TRANSFORM_CLSID_Attribute: {BC47FCFE-98A0-4F27-BB07-698AF24F2B38} (Type VT_CLSID)
 * MF_TRANSFORM_FLAGS_Attribute: MFT_ENUM_FLAG_SYNCMFT
 * MFT_INPUT_TYPES_Attributes: MFVideoFormat_IYUV
 * MFT_OUTPUT_TYPES_Attributes: MFVideoFormat_H263

### IMFTransform

 * Stream Limits: Input 1..1, Output 1..1
 * Streams: Input 1, Output 1

#### Attributes


#### Input Stream 0

#### Output Stream 0

### ICodecAPI

 * `CODECAPI_AVEncCommonRateControlMode`: VT_UI4 0
 * `CODECAPI_AVEncCommonMeanBitRate`: VT_UI4 64000
 * `CODECAPI_AVEncMPVGOPSize`: VT_UI4 10

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

## H265 Encoder MFT

6 Attributes:

 * MFT_TRANSFORM_CLSID_Attribute: {F2F84074-8BCA-40BD-9159-E880F673DD3B} (Type VT_CLSID)
 * MF_TRANSFORM_FLAGS_Attribute: MFT_ENUM_FLAG_SYNCMFT
 * MFT_INPUT_TYPES_Attributes: MFVideoFormat_IYUV, MFVideoFormat_YV12, MFVideoFormat_NV12, MFVideoFormat_YUY2
 * MFT_OUTPUT_TYPES_Attributes: MFVideoFormat_HEVC

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
 * `CODECAPI_AVEncCommonQualityVsSpeed`: VT_UI4 0
 * `CODECAPI_AVEncCommonMeanBitRate`: VT_UI4 500000
 * `CODECAPI_AVEncCommonMaxBitRate`: VT_UI4 0
 * `CODECAPI_AVEncCommonBufferSize`: VT_UI4 0
 * `CODECAPI_AVEncVideoContentType`: VT_UI4 0
 * `CODECAPI_AVEncNumWorkerThreads`: VT_UI4 0
 * `CODECAPI_AVEncVideoEncodeQP`: VT_UI8 26
 * `CODECAPI_AVEncVideoMinQP`: VT_UI4 0, minimal VT_UI4 0, maximal VT_UI4 51, step VT_UI4 1
 * `CODECAPI_AVEncVideoForceKeyFrame`: VT_UI4 0
 * `CODECAPI_AVEncH264SPSID`: VT_UI4 0
 * `CODECAPI_AVEncH264PPSID`: VT_UI4 0
 * `CODECAPI_AVEncVideoEncodeFrameTypeQP`: VT_UI8 18446744073709551615
 * `CODECAPI_AVEncVideoMaxQP`: VT_UI4 51, minimal VT_UI4 0, maximal VT_UI4 51, step VT_UI4 1
 * `CODECAPI_AVEncMPVGOPSize`: VT_UI4 0
 * `CODECAPI_AVLowLatencyMode`: VT_BOOL 0

