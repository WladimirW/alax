////////////////////////////////////////////////////////////
// Copyright (C) Roman Ryltsov, 2006-2017
// Created by Roman Ryltsov roman@alax.info
//
// A permission to use the source code is granted as long as reference to 
// source website http://alax.info is retained.

#include "stdafx.h"
#include "resource.h"
//#include "Module_i.h"
#include "MainDialog.h"

////////////////////////////////////////////////////////////
// CLogicalProcessorInformationModule

class CLogicalProcessorInformationModule : 
	public CAtlExeModuleT<CLogicalProcessorInformationModule>,
	public CWtlExeModuleT<CLogicalProcessorInformationModule>
{
public:

//DECLARE_LIBID(LIBID_AlaxInfoLogicalProcessorInformationModule)

//DECLARE_REGISTRY_APPID_RESOURCEID(IDI_MODULE, "{...}")

public:
// CLogicalProcessorInformationModule
	CLogicalProcessorInformationModule()
	{
		AtlTraceSetDefaultSettings();
		_Z4_THIS();
		_W(CExceptionFilter::Initialize());
	}
	~CLogicalProcessorInformationModule()
	{
		_Z4_THIS();
		CExceptionFilter::Terminate();
	}
	HRESULT PreMessageLoop(INT nShowCommand)
	{
		_ATLTRY
		{
			TraceModuleVersion();
			__E(AtlInitCommonControls(ICC_WIN95_CLASSES | ICC_DATE_CLASSES | ICC_COOL_CLASSES));
			//__C(CWtlExeModule::Initialize());
			__C(__super::PreMessageLoop(nShowCommand));
		}
		_ATLCATCH(Exception)
		{
			_C(Exception);
		}
		return S_OK;
	}
	VOID RunMessageLoop()
	{
		Lock();
		{
			CMainDialog MainDialog;
			MainDialog.DoModal();
		}
		if(GetLockCount() == 1)
		{
			m_dwTimeOut = 0L;
			m_dwPause = 0L;
		}
		Unlock();
	}
	HRESULT PostMessageLoop()
	{
		_ATLTRY
		{
			_V(__super::PostMessageLoop());
			//CWtlExeModule::Terminate();
		}
		_ATLCATCH(Exception)
		{
			_C(Exception);
		}
		return S_OK;
	}
};

CLogicalProcessorInformationModule _AtlModule;

////////////////////////////////////////////////////////////
// Main

extern "C" int WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, INT nShowCommand)
{
    return _AtlModule.WinMain(nShowCommand);
}

