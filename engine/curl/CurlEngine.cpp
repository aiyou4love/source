#include "../Engine.hpp"

namespace cc {
	
	void CurlEngine::pushHandle(BaseCurlPtr& nBaseCurl)
	{
		std::lock_guard<mutex> lock_(mMutex);
		mIndex++;
		if ( mIndex == mMultiCurls.size() ) {
			mIndex = 1;
		}
		MultiCurlPtr& multiCurl_ = mMultiCurls[mIndex - 1];
		multiCurl_->pushHandle(nBaseCurl);
	}
	
	ContextPtr CurlEngine::createContext()
	{
		MultiCurlPtr multiCurl_(new MultiCurl());
		mMultiCurls.push_back(multiCurl_);
		return ContextPtr(new CurlContext(multiCurl_));
	}
	
	const char * CurlEngine::contextName()
	{
		return "curlEngine";
	}
	
	void CurlEngine::runPreinit()
	{
		WorkDirectory& workDirectory_ = WorkDirectory::instance();
		int16_t appType_ = workDirectory_.getAppType();
		if ( EappType::mGameClient == appType_ ) {
			return;
		}
		LifeCycle& lifeCycle_ = LifeCycle::instance();
		lifeCycle_.m_tIniting.connect(bind(&CurlEngine::runInit, this));
		lifeCycle_.m_tClearEnd.connect(bind(&CurlEngine::runClear, this));
	}
	
	void CurlEngine::runInit()
	{
		HandleEngine& handleEngine_ = HandleEngine::instance();
		handleEngine_.addContext(this);
	}
	
	void CurlEngine::runClear()
	{
		mMultiCurls.clear();
		mIndex = 0;
	}
	
	CurlEngine& CurlEngine::instance()
	{
		return mCurlEngine;
	}
	
	CurlEngine::CurlEngine()
	{
		this->runClear();
	}
	
	CurlEngine::~CurlEngine()
	{
		this->runClear();
	}
	
	CurlEngine CurlEngine::mCurlEngine;
	
}
