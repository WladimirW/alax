

# System

 * Version: 6.3.9600, Windows 8.1, VER_SUITE_SINGLEUSERTS, VER_NT_WORKSTATION
 * Product: PRODUCT_ENTERPRISE
 * Computer Name: `E50`
 * User Name: `E50\80JA` (Administrator)
 * Local Time: `2/13/2017 5:09:26 PM`
 * Architecture: AMD/Intel x64 (x64 Application)
 * Processors: `4`, Active Mask `0xF`
 * Page Size: `0x1000`
 * Application Address Space: `0x0000000000010000`..`0x00007FFFFFFEFFFF`
 * Physical Memory: `3,992` MB
 * Committed Memory Limit: `3,992` MB
 * Application Version: `1.0.0.53`

# Display Devices

 * Intel(R) HD Graphics Family
  * Instance: PCI\VEN_8086&DEV_0A16&SUBSYS_397817AA&REV_0B\3&11583659&1&10
  * DEVPKEY_Device_Manufacturer: Intel Corporation
  * DEVPKEY_Device_DriverVersion: 10.18.14.4414

# Category `MFT_CATEGORY_VIDEO_ENCODER`

Note that detail is limited to:

 * Flags: MFT_ENUM_FLAG_HARDWARE

## Intel® Quick Sync Video H.264 Encoder MFT

11 Attributes:

 * MFT_TRANSFORM_CLSID_Attribute: {4BE8D3C0-0515-4A37-AD55-E4BAE19AF471} (Type VT_CLSID)
 * MF_TRANSFORM_FLAGS_Attribute: MFT_ENUM_FLAG_HARDWARE
 * MFT_ENUM_HARDWARE_VENDOR_ID_Attribute: VEN_8086 (Type VT_LPWSTR)
 * MFT_ENUM_HARDWARE_URL_Attribute: AA243E5D-2F73-48c7-97F7-F6FA17651651 (Type VT_LPWSTR)
 * MFT_INPUT_TYPES_Attributes: {3231564E-3961-42AE-BA67-FF47CCC13EED}, MFVideoFormat_NV12
 * MFT_OUTPUT_TYPES_Attributes: MFVideoFormat_H264
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
 * MF_VIDEO_MAX_MB_PER_SEC: 628582 (Type VT_UI4)
 * {F34B9093-05E0-4B16-993D-3E2A2CDE6AD3}: 2814827077439806 (Type VT_UI8, 0x000A0012 0x000E113E, 655378 921918)
 * MF_TRANSFORM_ASYNC: 1 (Type VT_UI4)

#### Input Stream 0

#### Output Stream 0

### ICodecAPI

 * `CODECAPI_AVEncCommonRateControlMode`: VT_UI4 0, default VT_UI4 0, modifiable
 * `CODECAPI_AVEncCommonLowLatency`: VT_BOOL 0, default VT_BOOL 0, modifiable
 * `CODECAPI_AVEncCommonQuality`: 
 * `CODECAPI_AVEncCommonQualityVsSpeed`: VT_UI4 50, default VT_UI4 50, modifiable
 * `CODECAPI_AVEncCommonMeanBitRate`: VT_UI4 7471215, default VT_UI4 2222000, modifiable
 * `CODECAPI_AVEncCommonMaxBitRate`: default VT_UI4 0
 * `CODECAPI_AVEncCommonBufferSize`: VT_UI4 2687076, default VT_UI4 0, modifiable
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

