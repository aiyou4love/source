#pragma once

namespace cc {
	
	extern tuple<int32_t, string> classInfoInteral(const char * nValue);
	
	extern int32_t classIdInteral(const char * nValue);
	
	template<typename T>
	tuple<int32_t, string> classInfo()
	{
		const char * className_ = typeid(T).name();
		return classInfoInteral(className_);
	}
	
	template<typename T>
	int32_t classId()
	{
		const char * className_ = typeid(T).name();
		return classIdInteral(className_);
	}
	
}
