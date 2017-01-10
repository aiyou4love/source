#include "../../System.hpp"

namespace cc {
	
#ifndef __CLIENT__
	void ServerEngine::runPreinit()
	{
		LifeCycle& lifeCycle_ = LifeCycle::instance();
		lifeCycle_.m_tLoadBegin.connect(bind(&ServerEngine::runLoad, this));
		lifeCycle_.m_tInitBegin.connect(bind(&ServerEngine::runInit, this));
		lifeCycle_.m_tSaveBegin.connect(bind(&ServerEngine::runSave, this));
		lifeCycle_.m_tClearEnd.connect(bind(&ServerEngine::runClear, this));
	}
	
	void ServerEngine::runLoad()
	{
		UserDefault& userDefault_ = UserDefault::instance();
		userDefault_.runReader<ServerEngine>(this, saveUrl(), saveName());
	}
	
	const char * mServerListUrl = "serverList";
	void ServerEngine::runInit()
	{
		cServerTime& serverTime_ = cServerTime::instance();
		int64_t nowTime_ = serverTime_.getServerTime();
		int64_t seconds_ = nowTime_ - mUpdateTime;
		if ( (mUpdateTime > 0) && (seconds_ < 21600) ) {
			return;
		}
		
		UrlMgr& urlMgr_ = UrlMgr::instance();
		
		WorkDirectory& workDirectory_ = WorkDirectory::instance();
		const char * operatorName_ = workDirectory_.getOperatorName();
		int16_t versionNo_ = workDirectory_.getVersionNo();
		int16_t classifyId_ = workDirectory_.getClassifyId();
		
		while ( !urlMgr_.runStream(this, mServerListUrl, streamName(),
			operatorName_, versionNo_, classifyId_) ) {
			LOGE("[%s]", __METHOD__);
			chrono::milliseconds dura_(2000);
			this_thread::sleep_for(dura_);
		}
		this->runSave();
	}
	
	void ServerEngine::runSave()
	{
		UserDefault& userDefault_ = UserDefault::instance();
		userDefault_.runSave<ServerEngine>(this, saveUrl(), saveName());
	}
	
	void ServerEngine::runClear()
	{
		mServerInfos.clear();
		mServerItems.clear();
	}
	
	const char * ServerEngine::streamName()
	{
		return "serverEngine";
	}
	
	const char * ServerEngine::streamUrl()
	{
		return "serverEngine.json";
	}
	
	const char * ServerEngine::saveName()
	{
		return "serverSave";
	}
	
	const char * ServerEngine::saveUrl()
	{
		return "serverSave.json";
	}
	
	ServerEngine& ServerEngine::instance()
	{
		return mServerEngine;
	}
	
	ServerEngine::ServerEngine()
	{
		mServerInfos.clear();
		mServerItems.clear();
	}
	
	ServerEngine::~ServerEngine()
	{
		mServerInfos.clear();
		mServerItems.clear();
	}
	
	ServerEngine ServerEngine::mServerEngine;
#endif
	
}
