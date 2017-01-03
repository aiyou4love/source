#pragma once

#ifdef __WINDOW__

#pragma warning(push)
#pragma warning(disable:4091)
#include <windows.h>
#include <dbghelp.h>
#pragma warning(pop)
#endif

namespace cc {
	
#ifdef __WINDOW__
	class Dump
	{
	private:
		PTOP_LEVEL_EXCEPTION_FILTER _filter;
		static Dump mDump;
		
		static LONG WINAPI TopLevelExceptionFilter(EXCEPTION_POINTERS * info);
		
	public:
		void runPreinit();
		
		static Dump& instance();
		
		Dump();
		~Dump();
	};
#endif
	
}
