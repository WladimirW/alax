

# System

 * Version: 10.0.14393, Windows 10, VER_SUITE_SINGLEUSERTS, VER_NT_WORKSTATION
 * Product: PRODUCT_PROFESSIONAL
 * Computer Name: `PP-leon-PC2`
 * User Name: `PP-LEON-PC2\user` 
 * Locale: System `zh-TW`, User `zh-TW`
 * Local Time: `2017/3/31 上午 09:37:54`
 * Architecture: AMD/Intel x64 (x64 Application)
 * Processors: `4`, Active Mask `0xF`
 * Page Size: `0x1000`
 * Application Address Space: `0x0000000000010000`..`0x00007FFFFFFEFFFF`
 * Physical Memory: `16,311` MB
 * Committed Memory Limit: `18,743` MB
 * Application Version: `1.0.0.69`

# Display Devices

 * NVIDIA GeForce GTX 970
  * Instance: PCI\VEN_10DE&DEV_13C2&SUBSYS_853F1043&REV_A1\4&2D78AB8F&0&0008
  * DEVPKEY_Device_Manufacturer: NVIDIA
  * DEVPKEY_Device_DriverVersion: 21.21.13.7653

# Category `MFT_CATEGORY_VIDEO_ENCODER`

Note that detail is limited to:

 * Subtype: MFVideoFormat_H264

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
 * {F34B9093-05E0-4B16-993D-3E2A2CDE6AD3}: 5911064706096613 (Type VT_UI8, 0x00150015 0x000D1DE5, 1376277 859621)
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

