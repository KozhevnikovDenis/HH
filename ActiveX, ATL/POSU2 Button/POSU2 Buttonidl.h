

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0622 */
/* at Tue Jan 19 06:14:07 2038
 */
/* Compiler settings for POSU2Button.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 8.01.0622 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */



/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 500
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif /* __RPCNDR_H_VERSION__ */


#ifndef __POSU2_Buttonidl_h__
#define __POSU2_Buttonidl_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef ___DPOSU2Button_FWD_DEFINED__
#define ___DPOSU2Button_FWD_DEFINED__
typedef interface _DPOSU2Button _DPOSU2Button;

#endif 	/* ___DPOSU2Button_FWD_DEFINED__ */


#ifndef ___DPOSU2ButtonEvents_FWD_DEFINED__
#define ___DPOSU2ButtonEvents_FWD_DEFINED__
typedef interface _DPOSU2ButtonEvents _DPOSU2ButtonEvents;

#endif 	/* ___DPOSU2ButtonEvents_FWD_DEFINED__ */


#ifndef __POSU2Button_FWD_DEFINED__
#define __POSU2Button_FWD_DEFINED__

#ifdef __cplusplus
typedef class POSU2Button POSU2Button;
#else
typedef struct POSU2Button POSU2Button;
#endif /* __cplusplus */

#endif 	/* __POSU2Button_FWD_DEFINED__ */


#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_POSU2Button_0000_0000 */
/* [local] */ 

#pragma warning(push)
#pragma warning(disable:4001) 
#pragma once
#pragma warning(push)
#pragma warning(disable:4001) 
#pragma once
#pragma warning(pop)
#pragma warning(pop)
#pragma region Desktop Family
#pragma endregion


extern RPC_IF_HANDLE __MIDL_itf_POSU2Button_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_POSU2Button_0000_0000_v0_0_s_ifspec;


#ifndef __POSU2ButtonLib_LIBRARY_DEFINED__
#define __POSU2ButtonLib_LIBRARY_DEFINED__

/* library POSU2ButtonLib */
/* [control][version][uuid] */ 


EXTERN_C const IID LIBID_POSU2ButtonLib;

#ifndef ___DPOSU2Button_DISPINTERFACE_DEFINED__
#define ___DPOSU2Button_DISPINTERFACE_DEFINED__

/* dispinterface _DPOSU2Button */
/* [uuid] */ 


EXTERN_C const IID DIID__DPOSU2Button;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("334d5076-f138-4947-8125-f351af761391")
    _DPOSU2Button : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _DPOSU2ButtonVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _DPOSU2Button * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _DPOSU2Button * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _DPOSU2Button * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _DPOSU2Button * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _DPOSU2Button * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _DPOSU2Button * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _DPOSU2Button * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        END_INTERFACE
    } _DPOSU2ButtonVtbl;

    interface _DPOSU2Button
    {
        CONST_VTBL struct _DPOSU2ButtonVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _DPOSU2Button_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _DPOSU2Button_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _DPOSU2Button_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _DPOSU2Button_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _DPOSU2Button_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _DPOSU2Button_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _DPOSU2Button_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___DPOSU2Button_DISPINTERFACE_DEFINED__ */


#ifndef ___DPOSU2ButtonEvents_DISPINTERFACE_DEFINED__
#define ___DPOSU2ButtonEvents_DISPINTERFACE_DEFINED__

/* dispinterface _DPOSU2ButtonEvents */
/* [uuid] */ 


EXTERN_C const IID DIID__DPOSU2ButtonEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("7afe8d83-95ae-44f1-9ab4-878e815f0954")
    _DPOSU2ButtonEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _DPOSU2ButtonEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _DPOSU2ButtonEvents * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _DPOSU2ButtonEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _DPOSU2ButtonEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _DPOSU2ButtonEvents * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _DPOSU2ButtonEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _DPOSU2ButtonEvents * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _DPOSU2ButtonEvents * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        END_INTERFACE
    } _DPOSU2ButtonEventsVtbl;

    interface _DPOSU2ButtonEvents
    {
        CONST_VTBL struct _DPOSU2ButtonEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _DPOSU2ButtonEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _DPOSU2ButtonEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _DPOSU2ButtonEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _DPOSU2ButtonEvents_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _DPOSU2ButtonEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _DPOSU2ButtonEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _DPOSU2ButtonEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___DPOSU2ButtonEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_POSU2Button;

#ifdef __cplusplus

class DECLSPEC_UUID("d7187b45-b33b-4408-aefa-af36d2845529")
POSU2Button;
#endif
#endif /* __POSU2ButtonLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


