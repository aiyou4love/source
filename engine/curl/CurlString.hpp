#pragma once

namespace cc {
	
	class CurlString : public CurlValue
	{
	public:
		CurlFun_t getCurlFun();
		void * getCurlValue();
		
		const char * getValue();
		
		CurlString();
		~CurlString();
		
	private:
		static size_t curlFun(void *, size_t, size_t, void *);
		
	protected:
		string mValue;
	};
	
}
