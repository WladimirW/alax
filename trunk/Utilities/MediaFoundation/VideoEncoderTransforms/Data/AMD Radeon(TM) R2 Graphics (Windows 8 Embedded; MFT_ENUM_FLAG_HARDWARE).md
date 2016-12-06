

# System

 * Version: 6.2.9200, Windows 8, VER_SUITE_EMBEDDEDNT | VER_SUITE_SINGLEUSERTS, VER_NT_WORKSTATION
 * Product: PRODUCT_EMBEDDED
 * Computer Name: `IJFQTR1ISPAKI`
 * User Name: `IJFQTR1ISPAKI\Administrator` (Administrator)
 * Local Time: `12/5/2016 3:56:05 PM`
 * Architecture: AMD/Intel x64 (x64 Application)
 * Processors: `2`, Active Mask `0x3`
 * Page Size: `0x1000`
 * Application Address Space: `0x0000000000010000`..`0x000007FFFFFEFFFF`
 * Physical Memory: `3,515` MB
 * Committed Memory Limit: `3,515` MB
 * Application Version: `1.0.0.53`

# Display Devices

 * AMD Radeon(TM) R2 Graphics
  * Instance: PCI\VEN_1002&DEV_9856&SUBSYS_21EF103C&REV_01\3&11583659&0&08
  * DEVPKEY_Device_Manufacturer: Advanced Micro Devices, Inc.
  * DEVPKEY_Device_DriverVersion: 13.302.1501.0

# Category `MFT_CATEGORY_VIDEO_ENCODER`

Note that detail is limited to:

 * Flags: MFT_ENUM_FLAG_HARDWARE

## AMD H.264 Hardware MFT Encoder

12 Attributes:

 * MFT_TRANSFORM_CLSID_Attribute: {ADC9BC80-0F41-46C6-AB75-D693D793597D} (Type VT_CLSID)
 * MF_TRANSFORM_FLAGS_Attribute: MFT_ENUM_FLAG_HARDWARE
 * MFT_ENUM_HARDWARE_VENDOR_ID_Attribute: AMD (Type VT_LPWSTR)
 * MFT_ENUM_HARDWARE_URL_Attribute: AMDh264Encoder (Type VT_LPWSTR)
 * MFT_INPUT_TYPES_Attributes: MFVideoFormat_NV12
 * MFT_OUTPUT_TYPES_Attributes: MFVideoFormat_H264
 * MFT_CODEC_MERIT_Attribute: 8 (Type VT_UI4)
 * MFT_SUPPORT_DYNAMIC_FORMAT_CHANGE: 1 (Type VT_UI4)
 * MF_SA_D3D11_AWARE: 1 (Type VT_UI4)
 * MF_SA_D3D_AWARE: 1 (Type VT_UI4)

### IMFTransform

 * Streams: Input 1, Output 1

#### Attributes

 * MF_SA_D3D11_AWARE: 1 (Type VT_UI4)
 * MFT_ENUM_HARDWARE_URL_Attribute: AMDh264Encoder (Type VT_LPWSTR)
 * MFT_ENUM_HARDWARE_VENDOR_ID_Attribute: AMD (Type VT_LPWSTR)
 * MFT_SUPPORT_DYNAMIC_FORMAT_CHANGE: 1 (Type VT_UI4)
 * MF_VIDEO_MAX_MB_PER_SEC: 352388 (Type VT_UI4)
 * MF_TRANSFORM_ASYNC_UNLOCK: 0 (Type VT_UI4)
 * MF_SA_D3D_AWARE: 1 (Type VT_UI4)
 * MF_TRANSFORM_ASYNC: 1 (Type VT_UI4)

#### Input Stream 0

#### Output Stream 0

### ICodecAPI

 * `CODECAPI_AVEncCommonRateControlMode`: VT_UI4 0
 * `CODECAPI_AVEncCommonLowLatency`: VT_BOOL 0
 * `CODECAPI_AVEncCommonQuality`: VT_UI4 70
 * `CODECAPI_AVEncCommonQualityVsSpeed`: 
 * `CODECAPI_AVEncCommonMeanBitRate`: VT_UI4 100000
 * `CODECAPI_AVEncCommonMaxBitRate`: 
 * `CODECAPI_AVEncCommonBufferSize`: 
 * `CODECAPI_AVEncH264CABACEnable`: 
 * `CODECAPI_AVEncVideoEncodeQP`: 
 * `CODECAPI_AVEncVideoMinQP`: VT_UI4 0
 * `CODECAPI_AVEncVideoForceKeyFrame`: VT_UI4 0
 * `CODECAPI_AVEncVideoSelectLayer`: 
 * `CODECAPI_AVEncVideoTemporalLayerCount`: minimal VT_UI8 0, maximal VT_UI8 3, step VT_UI8 1
 * `CODECAPI_AVEncVideoUsage`: VT_UI4 1
 * `CODECAPI_AVEncVideoEncodeFrameTypeQP`: 
 * `CODECAPI_AVEncSliceControlMode`: VT_UI4 0, minimal VT_UI8 0, maximal VT_UI8 2, step VT_UI8 2
 * `CODECAPI_AVEncSliceControlSize`: 
 * `CODECAPI_AVEncVideoMaxNumRefFrame`: VT_UI4 4, minimal VT_UI8 1, maximal VT_UI8 16, step VT_UI8 1
 * `CODECAPI_AVEncVideoMaxQP`: VT_UI4 51
 * `CODECAPI_AVEncVideoLTRBufferControl`: VT_UI4 0
 * `CODECAPI_AVEncVideoMarkLTRFrame`: 
 * `CODECAPI_AVEncVideoUseLTRFrame`: 
 * `CODECAPI_AVEncVideoROIEnabled`: VT_UI4 0
 * `CODECAPI_AVEncMPVGOPSize`: 
 * `CODECAPI_AVEncMPVDefaultBPictureCount`: VT_UI4 0
 * `CODECAPI_AVEncMPVProfile`: VT_UI4 66
 * `CODECAPI_AVEncMPVLevel`: 
 * `CODECAPI_AVLowLatencyMode`: VT_BOOL 0

