#pragma once

namespace cc {
	
	class CurlContext : public Context
	{
	public:
		void runContext(int64_t nTick);
		
		CurlContext(MultiCurlPtr& nMultiCurl);
		~CurlContext();
		
	private:
		MultiCurlPtr mMultiCurl;
	};
	
}
