////////////////////////////////////////////////////////////
// Copyright (C) Roman Ryltsov, 2015
// Created by Roman Ryltsov roman@alax.info
// 
// A permission to use the source code is granted as long as reference to 
// source website http://alax.info is retained.

#pragma once

////////////////////////////////////////////////////////////
// CDebugTrace, ATLTRACE, ATLTRACE2

#if !defined(_TRACELEVEL)
	#define _TRACELEVEL 4
#endif // !defined(_TRACELEVEL)

class CDebugTraceBase
{
public:
// CDebugTraceBase
	static const CHAR* ShortFileNameFromFileName(const CHAR* pszFileName)
	{
		if(pszFileName)
		{
			const CHAR* pszShortFileName = strrchr(pszFileName, '\\');
			if(pszShortFileName)
				return pszShortFileName + 1;
		}
		return pszFileName;
	}
};

class CDebugTrace :
	public CDebugTraceBase
{
private:
	LPCSTR m_pszFileName;
	INT m_nLineNumber;
	LPCSTR m_pszFunctionName;

	CDebugTrace& __cdecl operator = (const CDebugTrace&); // Not implemented

	static VOID TraceV(LPCSTR pszFileName, INT nLineNumber, LPCSTR pszFunctionName, DWORD_PTR nCategory, UINT nLevel, LPCSTR pszFormat, va_list& Arguments)
	{
		nCategory;
		nLevel;
		pszFileName = ShortFileNameFromFileName(pszFileName);
		static const SIZE_T g_nTextLength = 8 << 10; // 8 KB
		CHAR pszText[g_nTextLength] = { 0 };
		SIZE_T nTextLength = 0;
		if(pszFileName)
			nTextLength += sprintf_s(pszText + nTextLength, _countof(pszText) - nTextLength, "%hs(%d): %hs: ", pszFileName, nLineNumber, pszFunctionName);
		nTextLength += vsprintf_s(pszText + nTextLength, _countof(pszText) - nTextLength, pszFormat, Arguments);
		OutputDebugStringA(pszText);
	}
	static VOID TraceV(LPCSTR pszFileName, INT nLineNumber, LPCSTR pszFunctionName, DWORD_PTR nCategory, UINT nLevel, LPCWSTR pszFormat, va_list& Arguments)
	{
		nCategory;
		nLevel;
		pszFileName = ShortFileNameFromFileName(pszFileName);
		static const SIZE_T g_nTextLength = 8 << 10; // 8 KB
		WCHAR pszText[g_nTextLength] = { 0 };
		SIZE_T nTextLength = 0;
		if(pszFileName)
			nTextLength += swprintf_s(pszText + nTextLength, _countof(pszText) - nTextLength, L"%hs(%d): %hs: ", pszFileName, nLineNumber, pszFunctionName);
		nTextLength += vswprintf_s(pszText + nTextLength, _countof(pszText) - nTextLength, pszFormat, Arguments);
		OutputDebugStringW(pszText);
	}

public:
	// CDebugTrace
	CDebugTrace() :
		m_pszFileName(NULL),
		m_nLineNumber(0),
		m_pszFunctionName(NULL)
	{
	}
	CDebugTrace(LPCSTR pszFileName, INT nLineNumber, LPCSTR pszFunctionName) :
		m_pszFileName(pszFileName),
		m_nLineNumber(nLineNumber),
		m_pszFunctionName(pszFunctionName)
	{
	}
	__forceinline VOID __cdecl operator () (DWORD_PTR nCategory, UINT nLevel, LPCSTR pszFormat, ...)
	{
		#if defined(_DEBUG)
			if(!nCategory)
				return;
		#endif // defined(_DEBUG)
		if(nLevel > _TRACELEVEL)
			return;
		va_list Arguments;
		va_start(Arguments, pszFormat);
		__try
		{
			TraceV(m_pszFileName, m_nLineNumber, m_pszFunctionName, nCategory, nLevel, pszFormat, Arguments);
		}
		__except(EXCEPTION_EXECUTE_HANDLER)
		{
		}
		va_end(Arguments);
	}
	__forceinline VOID __cdecl operator () (LPCSTR pszFormat, ...)
	{
		//#if defined(_DEBUG)
		//	if(!nCategory)
		//		return;
		//#endif // defined(_DEBUG)
		//if(nLevel > _TRACELEVEL)
		//	return;
		va_list Arguments;
		va_start(Arguments, pszFormat);
		__try
		{
			static const DWORD_PTR g_nCategory = 1;
			static const DWORD_PTR g_nLevel = 2;
			TraceV(m_pszFileName, m_nLineNumber, m_pszFunctionName, g_nCategory, g_nLevel, pszFormat, Arguments);
		}
		__except(EXCEPTION_EXECUTE_HANDLER)
		{
		}
		va_end(Arguments);
	}
	__forceinline VOID __cdecl operator () (DWORD_PTR nCategory, UINT nLevel, LPCWSTR pszFormat, ...)
	{
		#if defined(_DEBUG)
			if(!nCategory)
				return;
		#endif // defined(_DEBUG)
		if(nLevel > _TRACELEVEL)
			return;
		va_list Arguments;
		va_start(Arguments, pszFormat);
		__try
		{
			TraceV(m_pszFileName, m_nLineNumber, m_pszFunctionName, nCategory, nLevel, pszFormat, Arguments);
		}
		__except(EXCEPTION_EXECUTE_HANDLER)
		{
		}
		va_end(Arguments);
	}
	__forceinline VOID __cdecl operator () (LPCWSTR pszFormat, ...)
	{
		//#if defined(_DEBUG)
		//	if(!nCategory)
		//		return;
		//#endif // defined(_DEBUG)
		//if(nLevel > _TRACELEVEL)
		//	return;
		va_list Arguments;
		va_start(Arguments, pszFormat);
		__try
		{
			static const DWORD_PTR g_nCategory = 1;
			static const DWORD_PTR g_nLevel = 2;
			TraceV(m_pszFileName, m_nLineNumber, m_pszFunctionName, g_nCategory, g_nLevel, pszFormat, Arguments);
		}
		__except(EXCEPTION_EXECUTE_HANDLER)
		{
		}
		va_end(Arguments);
	}
};

#undef ATLTRACE
#undef ATLTRACE2
#define ATLTRACE	CDebugTrace(__FILE__, __LINE__, __FUNCTION__)
#define ATLTRACE2	ATLTRACE

#define _Z			ATLTRACE
#define _Z0			ATLTRACE
#define _Z1			ATLTRACE
#define _Z2			ATLTRACE
#define _Z3			ATLTRACE
#define _Z4			ATLTRACE
#define _Z5			ATLTRACE
#define _Z6			ATLTRACE
