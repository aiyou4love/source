#include "../../Serialize.hpp"

#include <ctype.h>

#ifndef __WINDOW__
#include <cxxabi.h>
#include <stdlib.h>
#endif

namespace cc {
	
	tuple<int32_t, string> classInfoInteral(const char * nValue)
	{
	#ifdef __WINDOW__
		int32_t classId_ = stringCrc(nValue + 6);
		string className_ = nValue + 6;
	#else
		char * realName_ = abi::__cxa_demangle(nValue, 0, 0, 0);
		int32_t classId_ = stringCrc(realName_);
		string className_ = realName_;
		::free(realName_);
	#endif
		return make_tuple(classId_, className_);
	}
	
	int32_t classIdInteral(const char * nValue)
	{
		int32_t result_ = 0;
	#ifdef __WINDOW__
		result_ = stringCrc(nValue + 6);
	#else
		char * realName_ = abi::__cxa_demangle(nValue, 0, 0, 0);
		result_ = stringCrc(realName_);
		::free(realName_);
	#endif
		return result_;
	}
	
}
