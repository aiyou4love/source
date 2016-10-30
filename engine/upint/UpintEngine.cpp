#include "../Engine.hpp"

namespace cc {
	
	void UpintEngine::saveUpdate(const char * nUpdateName)
	{
		int32_t crcInt_ = stringCrc(nUpdateName);
		auto it = mUrls.find(crcInt_);
		if ( it == mUrls.end() ) {
			LOGE("[%s]%s", __METHOD__, nUpdateName);
			return;
		}
		UpintPtr& upint_ = it->second;
		mNows[crcInt_] = upint_;
		this->runSave();
	}
	
	bool UpintEngine::isUpdate(const char * nUpdateName)
	{
		int32_t crcInt_ = stringCrc(nUpdateName);
		auto it0 = mNows.find(crcInt_);
		if ( it0 == mNows.end() ) {
			return true;
		}
		auto it1 = mUrls.find(crcInt_);
		if ( it1 == mUrls.end() ) {
			return true;
		}
		UpintPtr& upint0_ = it0->second;
		int32_t updateNo0_ = upint0_->getUpdateNo();
		UpintPtr& upint1_ = it1->second;
		int32_t updateNo1_ = upint1_->getUpdateNo();
		if (updateNo0_ < updateNo1_) {
			return true;
		}
		return false;
	}
	
	void UpintEngine::runPreinit()
	{
		LifeCycle& lifeCycle_ = LifeCycle::instance();
		lifeCycle_.m_tLoadBegin.connect(bind(&UpintEngine::runLoad, this));
		lifeCycle_.m_tClearEnd.connect(bind(&UpintEngine::runClear, this));
	}
	
	void UpintEngine::runLoad()
	{
		UserDefault& userDefault_ = UserDefault::instance();
		userDefault_.runReader<UpintEngine>(this, saveUrl(), saveName());
	}
	
	void UpintEngine::runSave()
	{
		UserDefault& userDefault_ = UserDefault::instance();
		userDefault_.runSave<UpintEngine>(this, saveUrl(), saveName());
	}
	
	void UpintEngine::runClear()
	{
		mUrls.clear();
		mNows.clear();
	}
	
	const char * UpintEngine::streamName()
	{
		return "netUrl";
	}
	
	const char * UpintEngine::streamUrl()
	{
		return "netUrl.json";
	}
	
	const char * UpintEngine::saveName()
	{
		return "upintEngine";
	}
	
	const char * UpintEngine::saveUrl()
	{
		return "upintEngine.json";
	}
	
	UpintEngine& UpintEngine::instance()
	{
		return mUpintEngine;
	}
	
	UpintEngine::UpintEngine()
	{
		mUrls.clear();
		mNows.clear();
	}
	
	UpintEngine::~UpintEngine()
	{
		mUrls.clear();
		mNows.clear();
	}
	
	UpintEngine UpintEngine::mUpintEngine;
	
}
