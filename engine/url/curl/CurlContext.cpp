#include "../../Engine.hpp"

namespace cc {
	
	void CurlContext::runContext(int64_t nTick)
	{
		mMultiCurl->runHandle();
	}
	
	CurlContext::CurlContext(MultiCurlPtr& nMultiCurl)
		: mMultiCurl(nMultiCurl)
	{
	}
	
	CurlContext::~CurlContext()
	{
		mMultiCurl.reset();
	}
	
}
