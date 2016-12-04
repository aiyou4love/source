#include "../../Engine.hpp"

namespace cc {
	
	void EngineMgr::registerEngine(int16_t nEngineId, IEngine * nEngine)
	{
		auto it = mEngines.find(nEngineId);
		if ( it != mEngines.end() ) {
			LOGE("[%s]%d", __METHOD__, nEngineId);
			return;
		}
		mEngines[nEngineId] = nEngine;
	}
	
	IEngine * EngineMgr::findEngine(int16_t nEngineId)
	{
		auto it = mEngines.find(nEngineId);
		if ( it == mEngines.end() ) {
			LOGE("[%s]%d", __METHOD__, nEngineId);
			return nullptr;
		}
		return it->second;
	}
	
	void EngineMgr::initSink(int32_t nSinkId, EntityPtr& nEntity)
	{
		int16_t sinkType_ = int16_t(nSinkId >> 16);
		int16_t sinkId_ = int16_t(nSinkId & 0xFFFF);
		IEngine * engine_ = this->findEngine(sinkType_);
		if (nullptr == engine_) {
			return;
		}
		engine_->initSink(sinkId_, nEntity);
	}
	
	void EngineMgr::runPreinit()
	{
		LifeCycle& lifeCycle_ = LifeCycle::instance();
		lifeCycle_.m_tClearEnd.connect(bind(&EngineMgr::runClear, this));
	}
	
	void EngineMgr::runClear()
	{
		mEngines.clear();
	}
	
	EngineMgr& EngineMgr::instance()
	{
		return mEngineMgr;
	}
	
	EngineMgr::EngineMgr()
	{
		this->runClear();
	}
	
	EngineMgr::~EngineMgr()
	{
		this->runClear();
	}
	
	EngineMgr EngineMgr::mEngineMgr;
	
}
