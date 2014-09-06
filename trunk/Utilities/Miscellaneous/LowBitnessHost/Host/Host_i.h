

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0555 */
/* at Thu Jun 20 22:34:56 2013
 */
/* Compiler settings for Host.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 7.00.0555 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __Host_i_h__
#define __Host_i_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IFoo_FWD_DEFINED__
#define __IFoo_FWD_DEFINED__
typedef interface IFoo IFoo;
#endif 	/* __IFoo_FWD_DEFINED__ */


#ifndef __Foo_FWD_DEFINED__
#define __Foo_FWD_DEFINED__

#ifdef __cplusplus
typedef class Foo Foo;
#else
typedef struct Foo Foo;
#endif /* __cplusplus */

#endif 	/* __Foo_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IFoo_INTERFACE_DEFINED__
#define __IFoo_INTERFACE_DEFINED__

/* interface IFoo */
/* [unique][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IFoo;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("D22A348B-2542-4618-AD41-00EE1EDBAFB7")
    IFoo : public IDispatch
    {
    public:
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Bar( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IFooVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IFoo * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IFoo * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IFoo * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IFoo * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IFoo * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IFoo * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IFoo * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Bar )( 
            IFoo * This);
        
        END_INTERFACE
    } IFooVtbl;

    interface IFoo
    {
        CONST_VTBL struct IFooVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFoo_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IFoo_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IFoo_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IFoo_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IFoo_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IFoo_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IFoo_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IFoo_Bar(This)	\
    ( (This)->lpVtbl -> Bar(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IFoo_INTERFACE_DEFINED__ */



#ifndef __HostLib_LIBRARY_DEFINED__
#define __HostLib_LIBRARY_DEFINED__

/* library HostLib */
/* [version][uuid] */ 


EXTERN_C const IID LIBID_HostLib;

EXTERN_C const CLSID CLSID_Foo;

#ifdef __cplusplus

class DECLSPEC_UUID("D2ACAB10-7550-4726-9535-B7EFACAE9202")
Foo;
#endif
#endif /* __HostLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif

