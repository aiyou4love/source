#include "../Serialize.hpp"

#ifdef __WINDOW__
#include <shlwapi.h>

#pragma comment(lib, "shlwapi.lib")
#endif

namespace cc {
	
#ifdef __WINDOW__
	void Dump::runPreinit()
	{
		_filter = SetUnhandledExceptionFilter(TopLevelExceptionFilter);
	}
	
	Dump& Dump::instance()
	{
		return mDump;
	}
	
	Dump::Dump()
		: _filter(nullptr)
	{
	}
	
	Dump::~Dump()
	{
		SetUnhandledExceptionFilter(_filter);
	}
	
	LONG Dump::TopLevelExceptionFilter(EXCEPTION_POINTERS * e)
	{
		wchar_t dbghelp[MAX_PATH];
		GetModuleFileNameW(NULL, dbghelp, MAX_PATH);
		PathRemoveFileSpecW(dbghelp);
		PathAddBackslashW(dbghelp);
		wcscat_s(dbghelp, L"dbghelp.dll");
		
		HMODULE dll = LoadLibraryW(dbghelp);
		if (!dll)
			return EXCEPTION_CONTINUE_SEARCH;
		
		typedef BOOL (WINAPI *MINIDUMPWRITEDUMP)(IN HANDLE hProcess, IN DWORD ProcessId, IN HANDLE hFile, IN MINIDUMP_TYPE DumpType, IN CONST PMINIDUMP_EXCEPTION_INFORMATION THROWEXCEPTIONParam, OPTIONAL IN CONST PMINIDUMP_USER_STREAM_INFORMATION UserStreamParam, OPTIONAL IN CONST PMINIDUMP_CALLBACK_INFORMATION CallbackParam OPTIONAL);
		MINIDUMPWRITEDUMP MiniDumpWriteDump = (MINIDUMPWRITEDUMP)GetProcAddress(dll, "MiniDumpWriteDump");
		if (!MiniDumpWriteDump)
			return EXCEPTION_CONTINUE_SEARCH;
		
		wchar_t path[MAX_PATH];
		GetModuleFileNameW(NULL, path, MAX_PATH);
		PathRenameExtensionW(path, L".dmp");
		
		HANDLE file = CreateFileW(path, GENERIC_WRITE, FILE_SHARE_WRITE, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
		if (file ==INVALID_HANDLE_VALUE)
			return EXCEPTION_CONTINUE_SEARCH;
		
		MINIDUMP_EXCEPTION_INFORMATION info;
		info.ThreadId = GetCurrentThreadId();
		info.ExceptionPointers = e;
		info.ClientPointers = NULL;
		
		if (!MiniDumpWriteDump(GetCurrentProcess(), GetCurrentProcessId(), file, MiniDumpWithFullMemory, &info, NULL, NULL))
			return EXCEPTION_CONTINUE_SEARCH;
		
		CloseHandle(file);
		
		return EXCEPTION_EXECUTE_HANDLER;
	}
	
	Dump Dump::mDump;
#endif
	
}

