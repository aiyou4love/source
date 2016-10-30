#pragma once

namespace cc {
	
	class CurlEngine : public IContextClone
	{
	public:
		void pushHandle(BaseCurlPtr& nBaseCurl);
		
		ContextPtr createContext();
		const char * contextName();
		
		void runPreinit();
		void runInit();
		void runClear();
		
		static CurlEngine& instance();
		
		CurlEngine();
		~CurlEngine();
		
	private:
		vector<MultiCurlPtr> mMultiCurls;
		
		int8_t mIndex;
		mutex mMutex;
		
		static CurlEngine mCurlEngine;
	};
	
}
