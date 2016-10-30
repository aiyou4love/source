#include "../Serialize.hpp"

namespace cc {
	
	void HandleEngine::addContext(IContextClone * nContextClone)
	{
		const char * contextName_ = nContextClone->contextName();
		auto it0 = mHandleConfigs.find(contextName_);
		if (it0 == mHandleConfigs.end()) {
			LOGE("[%s]%s", __METHOD__, contextName_);
			return;
		}
		HandleConfigPtr& handleConfig_ = it0->second;
		list<int16_t>& indexs_ = handleConfig_->getIndexs();
		auto it1 = indexs_.begin();
		for ( ; it1 != indexs_.end(); ++it1 ) {
			int16_t index_ = (*it1);
			auto it2 = mHandles.find(index_);
			if ( it2 == mHandles.end() ) {
				LOGE("[%s]%s,index:%d", __METHOD__, contextName_, index_);
				continue;
			}
			HandlePtr& handle_ = mHandles[index_];
			ContextPtr context_ = nContextClone->createContext();
			handle_->addContext(context_);
		}
	}
	
	const char * HandleEngine::streamName()
	{
		return "handleEngine";
	}
	
	const char * HandleEngine::streamUrl()
	{
		return "handleEngine.json";
	}
	
	const char * HandleEngine::configName()
	{
		return "handleConfig";
	}
	
	const char * HandleEngine::configUrl()
	{
		return "handleConfig.json";
	}
	
	void HandleEngine::runPreinit()
	{
		LifeCycle& lifeCycle_ = LifeCycle::instance();
		lifeCycle_.m_tLoadBegin.connect(bind(&HandleEngine::runLoad, this));
		lifeCycle_.m_tInitBegin.connect(bind(&HandleEngine::runInit, this));
		lifeCycle_.m_tRunEnd.connect(bind(&HandleEngine::runEnd, this));
		lifeCycle_.m_tStopEnd.connect(bind(&HandleEngine::runStop, this));
		lifeCycle_.m_tClearEnd.connect(bind(&HandleEngine::runClear, this));
	}
	
	void HandleEngine::runLoad()
	{
		ConfigEngine& configEngine_ = ConfigEngine::instance();
		configEngine_.runReader<HandleEngine>(this, streamUrl(), streamName());
		configEngine_.runReader<HandleEngine>(this, configUrl(), configName());
	}
	
	void HandleEngine::runInit()
	{
		auto it = mHandleCounts.begin();
		for ( ; it != mHandleCounts.end(); ++it ) {
			HandleCountPtr& handleCount_ = it->second;
			int32_t ticks_ = handleCount_->getTicks();
			int16_t index_ = it->first;
			HandlePtr handle_(new Handle());
			handle_->setTicks(ticks_);
			mHandles[index_] = handle_;
		}
	}
	
	void HandleEngine::runEnd()
	{
		for (auto it : mHandles) {
			HandlePtr& handle_ = it.second;
			handle_->runStart();
		}
	}
	
	void HandleEngine::runStop()
	{
		for (auto it : mHandles) {
			HandlePtr& handle_ = it.second;
			handle_->runStop();
		}
		for (auto it : mHandles) {
			HandlePtr& handle_ = it.second;
			handle_->runJoin();
		}
	}
	
	void HandleEngine::runClear()
	{
		mHandleConfigs.clear();
		mHandleCounts.clear();
		mHandles.clear();
	}
	
	HandleEngine& HandleEngine::instance()
	{
		return mHandleEngine;
	}
	
	HandleEngine::HandleEngine()
	{
	}
	
	HandleEngine::~HandleEngine()
	{
	}
	
	HandleEngine HandleEngine::mHandleEngine;
	
}
