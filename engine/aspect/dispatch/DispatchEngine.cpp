#include "../../Engine.hpp"

namespace cc {
	
	void DispatchEngine::registerDispatch(int16_t nDispatchId, IDispatch * nDispatch)
	{
		auto it = mDispatchs.find(nDispatchId);
		if ( it != mDispatchs.end() ) {
			LOGE("[%s]%d", __METHOD__, nDispatchId);
			return;
		}
		mDispatchs[nDispatchId] = nDispatch;
	}
	
	IDispatch * DispatchEngine::findDispatch(int16_t nDispatchId)
	{
		auto it = mDispatchs.find(nDispatchId);
		if ( it == mDispatchs.end() ) {
			LOGE("[%s]%d", __METHOD__, nDispatchId);
			return nullptr;
		}
		return it->second;
	}
	
	void DispatchEngine::runPreinit()
	{
		LifeCycle& lifeCycle_ = LifeCycle::instance();
		lifeCycle_.m_tClearEnd.connect(bind(&DispatchEngine::runClear, this));
	}
	
	void DispatchEngine::runClear()
	{
		mDispatchs.clear();
	}
	
	DispatchEngine& DispatchEngine::instance()
	{
		return mDispatchEngine;
	}
	
	DispatchEngine::DispatchEngine()
	{
		this->runClear();
	}
	
	DispatchEngine::~DispatchEngine()
	{
		this->runClear();
	}
	
	DispatchEngine DispatchEngine::mDispatchEngine;
	
}
