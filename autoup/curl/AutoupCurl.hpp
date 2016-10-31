#pragma once

namespace cc {
	
	typedef size_t (* CurlFun)(void *, size_t, size_t, void *);
	class AutoupCurl : noncopyable
	{
	public:
		void runCurlValue(CurlFun nCurlFun, void * nCurlValue);
		void runTimeout(int16_t nTimeout);
		void runInit(const char * nUrl);
		bool runPerform();
		
		AutoupCurl();
		~AutoupCurl();
		
	private:
		CURL * mHandle;
	};
	
}
