#include "../Serialize.hpp"

#ifdef __WINDOW__
#include <windows.h>
#include <dbghelp.h>
#pragma comment(lib, "dbghelp.lib")
#endif

namespace cc {
	
#ifdef __WINDOW__
	LONG WINAPI exceptionFilter(struct _EXCEPTION_POINTERS * nExceptionInfo)
	{
		string fileName = APPNAME; fileName += ".dmp";
		HANDLE fileHandle = ::CreateFileA(fileName.c_str(), GENERIC_WRITE,
			FILE_SHARE_READ, nullptr, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, nullptr);
		MINIDUMP_EXCEPTION_INFORMATION miniDumpExceptionInfo;
		miniDumpExceptionInfo.ThreadId = ::GetCurrentThreadId();
		miniDumpExceptionInfo.ExceptionPointers = nExceptionInfo;
		miniDumpExceptionInfo.ClientPointers = FALSE;
		::MiniDumpWriteDump(::GetCurrentProcess(), ::GetCurrentProcessId(),
			fileHandle, MiniDumpNormal, &miniDumpExceptionInfo, nullptr, nullptr);
		return EXCEPTION_CONTINUE_SEARCH;
	}
	
	void Dump::runPreinit()
	{
		::SetUnhandledExceptionFilter( exceptionFilter );
	}
	
	Dump& Dump::instance()
	{
		return mDump;
	}
	
	Dump::Dump()
	{
	}
	
	Dump::~Dump()
	{
	}
	
	Dump Dump::mDump;
#endif
	
}

