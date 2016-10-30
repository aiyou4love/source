#pragma once

namespace cc {
	
	typedef size_t (* CurlFun_t)(void *, size_t, size_t, void *);
	class CurlValue : noncopyable
	{
	public:
		virtual CurlFun_t getCurlFun() = 0;
		virtual void * getCurlValue() = 0;
		
		virtual const char * getValue() = 0;
		
		CurlValue();
		virtual ~CurlValue();
	};
	typedef SPTR<CurlValue> CurlValuePtr;
	
}
