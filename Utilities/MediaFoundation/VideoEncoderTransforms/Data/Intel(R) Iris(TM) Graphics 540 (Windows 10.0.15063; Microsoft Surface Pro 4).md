

# System

 * Version: 10.0.15063, Windows 10, VER_SUITE_SINGLEUSERTS, VER_NT_WORKSTATION
 * Product: PRODUCT_PROFESSIONAL
 * Computer Name: `Rho`
 * User Name: `RHO\livec` 
 * Locale: System `en-US`, User `en-US`
 * Local Time: `2017-04-16 11:29:43`
 * Architecture: AMD/Intel x64 (x64 Application)
 * Processors: `4`, Active Mask `0xF`
 * Page Size: `0x1000`
 * Application Address Space: `0x0000000000010000`..`0x00007FFFFFFEFFFF`
 * Physical Memory: `8,118` MB
 * Committed Memory Limit: `10,038` MB
 * Application Version: `1.0.0.73`

# Display Devices

 * Intel(R) Iris(TM) Graphics 540
  * Instance: PCI\VEN_8086&DEV_1926&SUBSYS_00151414&REV_0A\3&11583659&0&10
  * DEVPKEY_Device_Manufacturer: Intel Corporation
  * DEVPKEY_Device_DriverVersion: 20.19.15.4463

# Category `MFT_CATEGORY_VIDEO_ENCODER`

 * Intel® Quick Sync Video H.264 Encoder MFT (MFT_ENUM_FLAG_HARDWARE)
 * H264 Encoder MFT (MFT_ENUM_FLAG_SYNCMFT)
 * WMVideo8 Encoder MFT (MFT_ENUM_FLAG_SYNCMFT)
 * Microsoft MF VPX Encoder Transform (MFT_ENUM_FLAG_SYNCMFT)
 * Intel® Hardware H265 Encoder MFT (MFT_ENUM_FLAG_HARDWARE)
 * H263 Encoder MFT (MFT_ENUM_FLAG_SYNCMFT)
 * WMVideo9 Encoder MFT (MFT_ENUM_FLAG_SYNCMFT)
 * Microsoft MPEG-2 Video Encoder MFT (MFT_ENUM_FLAG_ASYNCMFT)
 * H265 Encoder MFT (MFT_ENUM_FLAG_SYNCMFT)

## Intel® Quick Sync Video H.264 Encoder MFT

11 Attributes:

 * MFT_TRANSFORM_CLSID_Attribute: {4BE8D3C0-0515-4A37-AD55-E4BAE19AF471} (Type VT_CLSID)
 * MF_TRANSFORM_FLAGS_Attribute: MFT_ENUM_FLAG_HARDWARE
 * MFT_ENUM_HARDWARE_VENDOR_ID_Attribute: VEN_8086 (Type VT_LPWSTR)
 * MFT_ENUM_HARDWARE_URL_Attribute: AA243E5D-2F73-48c7-97F7-F6FA17651651 (Type VT_LPWSTR)
 * MFT_INPUT_TYPES_Attributes: {3231564E-3961-42AE-BA67-FF47CCC13EED}, MFVideoFormat_NV12, MFVideoFormat_ARGB32
 * MFT_OUTPUT_TYPES_Attributes: MFVideoFormat_H264, MFVideoFormat_H264_HDCP
 * MFT_CODEC_MERIT_Attribute: 7 (Type VT_UI4)
 * MFT_SUPPORT_DYNAMIC_FORMAT_CHANGE: 1 (Type VT_UI4)
 * MF_TRANSFORM_ASYNC: 1 (Type VT_UI4)

### IMFTransform

 * Streams: Input 1, Output 1

#### Attributes

 * MF_SA_D3D11_AWARE: 1 (Type VT_UI4)
 * MFT_ENUM_HARDWARE_URL_Attribute: AA243E5D-2F73-48c7-97F7-F6FA17651651 (Type VT_LPWSTR)
 * MFT_ENUM_HARDWARE_VENDOR_ID_Attribute: VEN_8086 (Type VT_LPWSTR)
 * MFT_SUPPORT_DYNAMIC_FORMAT_CHANGE: 1 (Type VT_UI4)
 * MFT_TRANSFORM_CLSID_Attribute: {4BE8D3C0-0515-4A37-AD55-E4BAE19AF471} (Type VT_CLSID)
 * MF_VIDEO_MAX_MB_PER_SEC: 1462540 (Type VT_UI4)
 * {F34B9093-05E0-4B16-993D-3E2A2CDE6AD3}: 0 (Type VT_UI8)
 * MF_TRANSFORM_ASYNC: 1 (Type VT_UI4)

#### Input Stream 0

#### Output Stream 0

### ICodecAPI

 * `CODECAPI_AVEncCommonRateControlMode`: VT_UI4 0, default VT_UI4 0, modifiable
 * `CODECAPI_AVEncCommonLowLatency`: VT_BOOL 0, default VT_BOOL 0, modifiable
 * `CODECAPI_AVEncCommonQuality`: minimal VT_UI4 0, maximal VT_UI4 100, step VT_UI4 1
 * `CODECAPI_AVEncCommonQualityVsSpeed`: VT_UI4 50, default VT_UI4 50, modifiable
 * `CODECAPI_AVEncCommonMeanBitRate`: VT_UI4 1001, default VT_UI4 2222000, modifiable
 * `CODECAPI_AVEncCommonMaxBitRate`: default VT_UI4 0
 * `CODECAPI_AVEncCommonBufferSize`: VT_UI4 0, default VT_UI4 0, modifiable
 * `CODECAPI_AVEncH264CABACEnable`: modifiable
 * `CODECAPI_AVEncVideoEncodeQP`: 
 * `CODECAPI_AVEncVideoForceKeyFrame`: VT_UI4 0, default VT_UI4 0, modifiable
 * `CODECAPI_AVEncVideoSelectLayer`: VT_UI4 0, default VT_UI4 0, modifiable
 * `CODECAPI_AVEncVideoTemporalLayerCount`: default VT_UI4 1, minimal VT_UI4 1, maximal VT_UI4 3, step VT_UI4 1, modifiable
 * `CODECAPI_AVEncVideoEncodeFrameTypeQP`: default VT_UI8 111670853658, minimal VT_UI8 0, maximal VT_UI8 219046674483, step VT_UI8 1
 * `CODECAPI_AVEncSliceControlMode`: VT_UI4 0, default VT_UI4 2, minimal VT_UI4 2, maximal VT_UI4 2, step VT_UI4 0, modifiable
 * `CODECAPI_AVEncSliceControlSize`: VT_UI4 0, minimal VT_UI4 0, maximal VT_UI4 65536, step VT_UI4 1, modifiable
 * `CODECAPI_AVEncVideoMaxNumRefFrame`: minimal VT_UI4 0, maximal VT_UI4 16, step VT_UI4 1, modifiable
 * `CODECAPI_AVEncVideoLTRBufferControl`: VT_UI4 65536, values { VT_UI4 65536, VT_UI4 65537, VT_UI4 65538, VT_UI4 65539, VT_UI4 65540, VT_UI4 65541, VT_UI4 65542, VT_UI4 65543, VT_UI4 65544, VT_UI4 65545, VT_UI4 65546, VT_UI4 65547, VT_UI4 65548, VT_UI4 65549, VT_UI4 65550, VT_UI4 65551, VT_UI4 65552 }, modifiable
 * `CODECAPI_AVEncVideoMarkLTRFrame`: 
 * `CODECAPI_AVEncVideoUseLTRFrame`: 
 * `CODECAPI_AVEncMPVGOPSize`: VT_UI4 128, default VT_UI4 128, modifiable
 * `CODECAPI_AVEncMPVDefaultBPictureCount`: VT_UI4 0, default VT_UI4 0, modifiable
 * `CODECAPI_AVEncMPVProfile`: modifiable
 * `CODECAPI_AVEncMPVLevel`: modifiable
 * `CODECAPI_AVLowLatencyMode`: VT_BOOL 0, default VT_BOOL 0, modifiable

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

## Intel® Hardware H265 Encoder MFT

12 Attributes:

 * MFT_TRANSFORM_CLSID_Attribute: {BC10864D-2B34-408F-912A-102B1B867B6C} (Type VT_CLSID)
 * MF_TRANSFORM_FLAGS_Attribute: MFT_ENUM_FLAG_HARDWARE
 * MFT_ENUM_HARDWARE_VENDOR_ID_Attribute: VEN_8086 (Type VT_LPWSTR)
 * MFT_ENUM_HARDWARE_URL_Attribute: AA243E5D-2F73-48c7-97F7-F6FA17651651 (Type VT_LPWSTR)
 * MFT_INPUT_TYPES_Attributes: {3231564E-3961-42AE-BA67-FF47CCC13EED}, MFVideoFormat_NV12, MFVideoFormat_ARGB32
 * MFT_OUTPUT_TYPES_Attributes: MFVideoFormat_HEVC
 * MFT_CODEC_MERIT_Attribute: 7 (Type VT_UI4)
 * MFT_SUPPORT_DYNAMIC_FORMAT_CHANGE: 1 (Type VT_UI4)
 * MF_TRANSFORM_ASYNC: 1 (Type VT_UI4)
 * MFT_GFX_DRIVER_VERSION_ID_Attribute: 0.0.0.3

### IMFTransform

 * Streams: Input 1, Output 1

#### Attributes

 * MF_SA_D3D11_AWARE: 1 (Type VT_UI4)
 * MFT_ENUM_HARDWARE_URL_Attribute: AA243E5D-2F73-48c7-97F7-F6FA17651651 (Type VT_LPWSTR)
 * MFT_ENUM_HARDWARE_VENDOR_ID_Attribute: VEN_8086 (Type VT_LPWSTR)
 * MFT_SUPPORT_DYNAMIC_FORMAT_CHANGE: 1 (Type VT_UI4)
 * MFT_TRANSFORM_CLSID_Attribute: {BC10864D-2B34-408F-912A-102B1B867B6C} (Type VT_CLSID)
 * {F34B9093-05E0-4B16-993D-3E2A2CDE6AD3}: 0 (Type VT_UI8)
 * MF_TRANSFORM_ASYNC: 1 (Type VT_UI4)

#### Input Stream 0

#### Output Stream 0

### ICodecAPI

 * `CODECAPI_AVEncCommonRateControlMode`: VT_UI4 0, default VT_UI4 0, values { VT_UI4 0, VT_UI4 0, VT_UI4 264149806, VT_UI4 2415944960 }, modifiable
 * `CODECAPI_AVEncCommonLowLatency`: VT_BOOL 0, default VT_BOOL 0, modifiable
 * `CODECAPI_AVEncCommonQuality`: minimal VT_UI4 0, maximal VT_UI4 100, step VT_UI4 1
 * `CODECAPI_AVEncCommonQualityVsSpeed`: VT_UI4 50, default VT_UI4 50, modifiable
 * `CODECAPI_AVEncCommonMeanBitRate`: VT_UI4 5439577, default VT_UI4 2222000, modifiable
 * `CODECAPI_AVEncCommonMaxBitRate`: default VT_UI4 0
 * `CODECAPI_AVEncCommonBufferSize`: VT_UI4 3342413, default VT_UI4 0, modifiable
 * `CODECAPI_AVEncVideoEncodeQP`: 
 * `CODECAPI_AVEncVideoForceKeyFrame`: VT_UI4 0, default VT_UI4 0, modifiable
 * `CODECAPI_AVEncVideoSelectLayer`: VT_UI4 0, default VT_UI4 0, modifiable
 * `CODECAPI_AVEncVideoTemporalLayerCount`: default VT_UI4 1, minimal VT_UI4 1, maximal VT_UI4 3, step VT_UI4 1, modifiable
 * `CODECAPI_AVEncVideoEncodeFrameTypeQP`: default VT_UI8 111670853658, minimal VT_UI8 0, maximal VT_UI8 219046674483, step VT_UI8 1
 * `CODECAPI_AVEncSliceControlMode`: VT_UI4 0, default VT_UI4 0, minimal VT_UI4 0, maximal VT_UI4 0, step VT_UI4 0, modifiable
 * `CODECAPI_AVEncSliceControlSize`: VT_UI4 0, minimal VT_UI4 0, maximal VT_UI4 16384, step VT_UI4 1, modifiable
 * `CODECAPI_AVEncMPVGOPSize`: VT_UI4 128, default VT_UI4 128, modifiable
 * `CODECAPI_AVEncMPVDefaultBPictureCount`: VT_UI4 3, default VT_UI4 3, modifiable
 * `CODECAPI_AVEncMPVProfile`: modifiable
 * `CODECAPI_AVEncMPVLevel`: modifiable
 * `CODECAPI_AVLowLatencyMode`: VT_BOOL 0, default VT_BOOL 0, modifiable

#### Rate Control Modes

Mode Quality

 * Accepted
 * AVEncCommonQuality 70 Accepted

Mode CBR

 * Accepted
 * AVEncCommonMeanBitRate 5120 kBps Accepted

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

#### Rate Control Modes

Mode Quality

 * Accepted
 * AVEncCommonQuality 70 Accepted

Mode CBR

 * Accepted
 * AVEncCommonMeanBitRate 5120 kBps Accepted

