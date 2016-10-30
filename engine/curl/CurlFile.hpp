#pragma once

namespace cc {
	
	class CurlFile : public CurlValue
	{
	public:
		CurlFun_t getCurlFun();
		void * getCurlValue();
		
		void runOpen(const char * nPath);
		void runClose();
		
		const char * getValue();
		
		CurlFile();
		CurlFile(const char * nPath);
		~CurlFile();
		
	private:
		static size_t curlFun(void *, size_t, size_t, void *);
		
	protected:
		string mPathName;
		
		FILE * mHandle;
	};
	
}
