////////////////////////////////////////////////////////////
// Copyright (C) Roman Ryltsov, 2008-2012
// Created by Roman Ryltsov roman@alax.info
// 
// $Id$

#pragma once

////////////////////////////////////////////////////////////
// CMaxMindGeoLiteModule

class CMaxMindGeoLiteModule : 
	public CAtlDllModuleT<CMaxMindGeoLiteModule>
{
public:

DECLARE_LIBID(LIBID_AlaxInfoMaxMindGeoLite)

DECLARE_REGISTRY_APPID_RESOURCEID(IDR_MODULE, "{F80BC862-E43E-4809-ACFC-1A608209C860}")

public:
// CMaxMindGeoLiteModule
	CMaxMindGeoLiteModule() throw()
	{
		#if defined(_DEBUG)
		AtlTraceLoadSettings(NULL);
		#endif // defined(_DEBUG)
		_W(CExceptionFilter::Initialize());
		TraceModuleVersion();
		//TraceModuleTerminationLockCount();
		_Z4(atlTraceRefcount, 4, _T("this 0x%p\n"), this);
	}
	~CMaxMindGeoLiteModule() throw()
	{
		_Z4(atlTraceRefcount, 4, _T("this 0x%p\n"), this);
		CExceptionFilter::Terminate();
	}

// CAtlModule
	HRESULT AddCommonRGSReplacements(IRegistrarBase* pRegistrar) throw()
	{
		_A(pRegistrar);
		_ATLTRY
		{
			__C(__super::AddCommonRGSReplacements(pRegistrar));
			_A(m_libid != GUID_NULL);
			__C(pRegistrar->AddReplacement(L"LIBID", _PersistHelper::StringFromIdentifier(m_libid)));
			TCHAR pszPath[MAX_PATH] = { 0 };
			_W(GetModuleFileName(_AtlBaseModule.GetModuleInstance(), pszPath, DIM(pszPath)));
			__C(pRegistrar->AddReplacement(L"FILENAME", CStringW(PathFindFileName(pszPath))));
			__C(pRegistrar->AddReplacement(L"DESCRIPTION", CStringW(AtlLoadString(IDS_PROJNAME))));
		}
		_ATLCATCH(Exception)
		{
			_C(Exception);
		}
		return S_OK;
	}
	BOOL WINAPI DllMain(DWORD nReason, VOID* pvReserved) throw()
	{
		return __super::DllMain(nReason, pvReserved);
	}
};

extern class CMaxMindGeoLiteModule _AtlModule;
