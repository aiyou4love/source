#include "../../Engine.hpp"

namespace cc {
	
	size_t CurlString::curlFun(void * nPtr, size_t nSize, size_t nMemb, void * nStream)
	{
		string * value_ = (string *)nStream;
		value_->append((const char *)nPtr);
		return (nSize * nMemb);
	}
	
	CurlFun_t CurlString::getCurlFun()
	{
		return curlFun;
	}
	
	void * CurlString::getCurlValue()
	{
		return (&mValue);
	}
	
	const char * CurlString::getValue()
	{
		return mValue.c_str();
	}
	
	CurlString::CurlString()
		: mValue ("")
	{
	}
	
	CurlString::~CurlString()
	{
		mValue = "";
	}
	
}
