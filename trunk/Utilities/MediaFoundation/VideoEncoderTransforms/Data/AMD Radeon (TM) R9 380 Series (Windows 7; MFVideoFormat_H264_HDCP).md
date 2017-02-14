

# System

 * Version: 6.1.7601, Windows 7, Service Pack 1.0, VER_SUITE_SINGLEUSERTS, VER_NT_WORKSTATION
 * Product: PRODUCT_ULTIMATE
 * Computer Name: `Boss-PC`
 * User Name: `Boss-PC\Boss` 
 * Local Time: `2017-02-13 04:54:57`
 * Architecture: AMD/Intel x64 (x64 Application)
 * Processors: `4`, Active Mask `0xF`
 * Page Size: `0x1000`
 * Application Address Space: `0x0000000000010000`..`0x000007FFFFFEFFFF`
 * Physical Memory: `8 142` MB
 * Committed Memory Limit: `20 429` MB
 * Application Version: `1.0.0.53`

# Display Devices

 * AMD Radeon (TM) R9 380 Series
  * Instance: PCI\VEN_1002&DEV_6939&SUBSYS_04E31043&REV_F1\4&63638AD&0&0008
  * DEVPKEY_Device_Manufacturer: Advanced Micro Devices, Inc.
  * DEVPKEY_Device_DriverVersion: 21.19.413.0

# Category `MFT_CATEGORY_VIDEO_ENCODER`

Note that detail is limited to:

 * Subtype: MFVideoFormat_H264_HDCP

## AMDh264Encoder

15 Attributes:

 * MFT_TRANSFORM_CLSID_Attribute: {ADC9BC80-0F41-46C6-AB75-D693D793597D} (Type VT_CLSID)
 * MF_TRANSFORM_FLAGS_Attribute: MFT_ENUM_FLAG_HARDWARE
 * MFT_ENUM_HARDWARE_VENDOR_ID_Attribute: VEN_1002 (Type VT_LPWSTR)
 * MFT_ENUM_HARDWARE_URL_Attribute: AMDh264Encoder (Type VT_LPWSTR)
 * MFT_INPUT_TYPES_Attributes: MFVideoFormat_NV12, MFVideoFormat_ARGB32
 * MFT_OUTPUT_TYPES_Attributes: MFVideoFormat_H264, MFVideoFormat_H264_HDCP
 * MFT_CODEC_MERIT_Attribute: 8 (Type VT_UI4)
 * MFT_SUPPORT_DYNAMIC_FORMAT_CHANGE: 1 (Type VT_UI4)
 * MF_TRANSFORM_ASYNC: 1 (Type VT_UI4)
 * MF_SA_D3D11_AWARE: 1 (Type VT_UI4)
 * MF_SA_D3D_AWARE: 1 (Type VT_UI4)
 * MF_TRANSFORM_ASYNC_UNLOCK: 0 (Type VT_UI4)
 * MFT_GFX_DRIVER_VERSION_ID_Attribute: 1.2.3.4

### IMFTransform

 * Streams: Input 1, Output 1

#### Attributes

 * MFT_ENUM_HARDWARE_URL_Attribute: AMDh264Encoder (Type VT_LPWSTR)
 * MFT_ENUM_HARDWARE_VENDOR_ID_Attribute: VEN_1002 (Type VT_LPWSTR)
 * MF_TRANSFORM_ASYNC: 1 (Type VT_UI4)
 * MF_TRANSFORM_ASYNC_UNLOCK: 0 (Type VT_UI4)
 * MFT_SUPPORT_DYNAMIC_FORMAT_CHANGE: 1 (Type VT_UI4)
 * {F34B9093-05E0-4B16-993D-3E2A2CDE6AD3}: 281483566841860 (Type VT_UI8, 0x00010002 0x00030004, 65538 196612)
 * MF_SA_D3D_AWARE: 1 (Type VT_UI4)
 * MF_SA_D3D11_AWARE: 1 (Type VT_UI4)
 * MFT_CODEC_MERIT_Attribute: 8 (Type VT_UI4)
 * MF_VIDEO_MAX_MB_PER_SEC: 2031079 (Type VT_UI4)

#### Input Stream 0

#### Output Stream 0

### ICodecAPI

 * `CODECAPI_AVEncCommonRateControlMode`: VT_UI4 0, minimal VT_UI4 3, maximal VT_UI4 3, step VT_UI4 1
 * `CODECAPI_AVEncCommonLowLatency`: VT_BOOL 0, minimal VT_BOOL 0, maximal VT_BOOL 0, step VT_BOOL -1
 * `CODECAPI_AVEncCommonQuality`: VT_UI4 70, minimal VT_UI4 0, maximal VT_UI4 0, step VT_UI4 1
 * `CODECAPI_AVEncCommonQualityVsSpeed`: minimal VT_UI4 50, maximal VT_UI4 50, step VT_UI4 1
 * `CODECAPI_AVEncCommonMeanBitRate`: VT_UI4 10000000, minimal VT_UI4 1000, maximal VT_UI4 100000000, step VT_UI4 1
 * `CODECAPI_AVEncCommonMaxBitRate`: VT_UI4 10000000, minimal VT_UI4 10000, maximal VT_UI4 100000000, step VT_UI4 1
 * `CODECAPI_AVEncCommonBufferSize`: minimal VT_UI4 0, maximal VT_UI4 100000000, step VT_UI4 1
 * `CODECAPI_AVEncH264CABACEnable`: VT_BOOL -1, minimal VT_BOOL 0, maximal VT_BOOL 0, step VT_BOOL -1
 * `CODECAPI_AVEncVideoEncodeQP`: VT_UI8 25, minimal VT_UI8 0, maximal VT_UI8 51, step VT_UI8 1
 * `CODECAPI_AVEncVideoMinQP`: VT_UI4 0, minimal VT_UI4 0, maximal VT_UI4 51, step VT_UI4 1
 * `CODECAPI_AVEncVideoForceKeyFrame`: VT_UI4 0, values { VT_UI4 0, VT_UI4 1 }
 * `CODECAPI_AVEncAdaptiveMode`: VT_UI4 0, minimal VT_UI4 0, maximal VT_UI4 0, step VT_UI4 0
 * `CODECAPI_AVEncVideoSelectLayer`: VT_UI4 0, minimal VT_UI4 0, maximal VT_UI4 0, step VT_UI4 1
 * `CODECAPI_AVEncVideoTemporalLayerCount`: VT_UI4 0, minimal VT_UI4 0, maximal VT_UI4 3, step VT_UI4 1
 * `CODECAPI_AVEncVideoUsage`: VT_UI4 3, minimal VT_UI4 0, maximal VT_UI4 0, step VT_UI4 1
 * `CODECAPI_AVEncVideoEncodeFrameTypeQP`: minimal VT_UI8 0, maximal VT_UI8 51, step VT_UI8 1
 * `CODECAPI_AVEncSliceControlMode`: VT_UI4 0, minimal VT_UI4 0, maximal VT_UI4 2, step VT_UI4 2
 * `CODECAPI_AVEncSliceControlSize`: VT_UI4 0, minimal VT_UI4 0, maximal VT_UI4 2147483647, step VT_UI4 1
 * `CODECAPI_AVEncVideoMaxNumRefFrame`: VT_UI4 4, minimal VT_UI4 1, maximal VT_UI4 16, step VT_UI4 1
 * `CODECAPI_AVEncVideoMaxQP`: VT_UI4 51, minimal VT_UI4 0, maximal VT_UI4 51, step VT_UI4 1
 * `CODECAPI_AVEncVideoLTRBufferControl`: VT_UI4 2, values { VT_UI4 65536, VT_UI4 65537, VT_UI4 65538, VT_UI4 65539 }
 * `CODECAPI_AVEncVideoMarkLTRFrame`: 
 * `CODECAPI_AVEncVideoUseLTRFrame`: 
 * `CODECAPI_AVEncVideoROIEnabled`: VT_UI4 0, values { VT_UI4 0, VT_UI4 1 }
 * `CODECAPI_AVEncMPVGOPSize`: VT_UI4 60, minimal VT_UI4 0, maximal VT_UI4 2147483647, step VT_UI4 1
 * `CODECAPI_AVEncMPVDefaultBPictureCount`: VT_UI4 0, minimal VT_UI4 0, maximal VT_UI4 3, step VT_UI4 1
 * `CODECAPI_AVEncMPVProfile`: VT_UI4 2, minimal VT_UI4 0, maximal VT_UI4 0, step VT_UI4 0
 * `CODECAPI_AVEncMPVLevel`: VT_UI4 2, minimal VT_UI4 0, maximal VT_UI4 0, step VT_UI4 0
 * `CODECAPI_AVLowLatencyMode`: VT_BOOL 0, minimal VT_BOOL 0, maximal VT_BOOL 0, step VT_BOOL -1

