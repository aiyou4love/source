#include "../Dispatch.hpp"

namespace cc {
	
	void ApplicationEngine::pushValue(ValuePtr& nValue)
	{
		mEntity->pushValue(nValue);
	}
	
	void ApplicationEngine::runPreinit()
	{
		mEntity.reset(new Application());
		
		DispatchEngine& dispatchEngine_ = DispatchEngine::instance();
		dispatchEngine_.registerDispatch(EdispatchId::mApplicationId, this);
		
		LifeCycle& lifeCycle_ = LifeCycle::instance();
		lifeCycle_.m_tLoadBegin.connect(bind(&ApplicationEngine::runLoad, this));
		lifeCycle_.m_tIniting.connect(bind(&ApplicationEngine::runInit, this));
		lifeCycle_.m_tRunning.connect(bind(&ApplicationEngine::runStart, this));
		lifeCycle_.m_tNoticeStop.connect(bind(&ApplicationEngine::runStop, this));
		lifeCycle_.m_tClearEnd.connect(bind(&ApplicationEngine::runClear, this));
	}
	
	void ApplicationEngine::runLoad()
	{
		TableEngine& tableEngine_ = TableEngine::instance();
		tableEngine_.runReader<ApplicationEngine>(this, streamUrl(), streamName());
	}
	
	void ApplicationEngine::runInit()
	{
		ApplicationUpdateClone applicationUpdateClone_;
		
		HandleEngine& handleEngine_ = HandleEngine::instance();
		handleEngine_.addContext(&applicationUpdateClone_);
	}
	
	void ApplicationEngine::runStart()
	{
		SelectEngine& selectEngine_ = SelectEngine::instance();
		
		for ( auto it : mStartIds ) {
			ValuePtr value_(new Value());
			value_->pushInt32(it);
			selectEngine_.runIfSelect(mEntity, value_);
		}
	}
	
	void ApplicationEngine::runStop()
	{
		for ( auto it : mStopIds ) {
			ValuePtr value_(new Value());
			value_->pushInt32(it);
			mEntity->pushValue(value_);
		}
	}
	
	void ApplicationEngine::runUpdate()
	{
		SelectEngine& selectEngine_ = SelectEngine::instance();
		
		ValuePtr value_ = mEntity->popValue();
		if (!value_) return;
		selectEngine_.runIfSelect(mEntity, value_);
	}
	
	void ApplicationEngine::runClear()
	{
		mStartIds.clear();
		mEntity.reset();
	}
	
	const char * ApplicationEngine::streamName()
	{
		return "applicationEngine";
	}
	
	const char * ApplicationEngine::streamUrl()
	{
		return "applicationEngine.json";
	}
	
	ApplicationEngine& ApplicationEngine::instance()
	{
		return mApplicationEngine;
	}
	
	ApplicationEngine::ApplicationEngine()
	{
		this->runClear();
	}
	
	ApplicationEngine::~ApplicationEngine()
	{
		this->runClear();
	}
	
	ApplicationEngine ApplicationEngine::mApplicationEngine;
	
}
