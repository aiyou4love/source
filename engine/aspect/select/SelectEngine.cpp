#include "../../Engine.hpp"

namespace cc {
	
	void SelectEngine::runGlobTrigger(EntityPtr& nEntity, int16_t nSinkType, int32_t nValue)
	{
		SinkPtr * sink_ = this->beginIterator(nSinkType);
		while (nullptr != sink_) {
			if ( nValue == (*sink_)->getSinkValue() ) {
				nEntity->pushTrigger(nEntity, (*sink_));
			}
			sink_ = this->nextIterator(nSinkType);
		}
	}
	
	void SelectEngine::runSelfTrigger(EntityPtr& nEntity, int16_t nSinkType, int32_t nValue)
	{
		SinkPtr * sink_ = nEntity->beginIterator(nSinkType);
		while (nullptr != sink_) {
			if ( nValue == (*sink_)->getSinkValue() ) {
				nEntity->pushTrigger(nEntity, (*sink_));
			}
			sink_ = nEntity->nextIterator(nSinkType);
		}
	}
	
	void SelectEngine::runTrigger(EntityPtr& nEntity, int16_t nSinkType, int32_t nValue)
	{
		this->runGlobTrigger(nEntity, nSinkType, nValue);
		this->runSelfTrigger(nEntity, nSinkType, nValue);
	}
	
	void SelectEngine::runIfSelect(EntityPtr& nEntity, ValuePtr& nValue)
	{
		int32_t ifSelectId0_ = nValue->getInt32(1);
		auto it = mIfSelects.find(ifSelectId0_);
		if ( it == mIfSelects.end() ) {
			LOGE("[%s]%d", __METHOD__, ifSelectId0_);
			return;
		}
		IfSelectPtr& ifSelect_ = it->second;
		int32_t selectId_ = ifSelect_->runIfSelect(nEntity, nValue);
		int32_t ifSelectId1_ = ifSelect_->getIfSelectId();
		if (selectId_ > 0) {
			this->runTrigger(nEntity, EselectSink::mIfSelect, ifSelectId1_);
			this->runTrigger(nEntity, EselectSink::mSelect, selectId_);
		}
		nEntity->runTrigger();
	}
	
	void SelectEngine::runPreinit()
	{
		LifeCycle& lifeCycle_ = LifeCycle::instance();
		lifeCycle_.m_tRunLuaApi.connect(bind(&SelectEngine::runLuaApi, this));
		lifeCycle_.m_tLoadBegin.connect(bind(&SelectEngine::runLoad, this));
		lifeCycle_.m_tClearEnd.connect(bind(&SelectEngine::runClear, this));
	}
	
	void SelectEngine::runLuaApi()
	{
		LuaEngine& luaEngine_ = LuaEngine::instance();
		luaEngine_.runClass<SelectEngine>("SelectEngine");
		luaEngine_.runStatic<SelectEngine>(SelectEngine::instance, "instance");
		luaEngine_.runMethod<SelectEngine>(&SelectEngine::runIfSelect, "runIfSelect");
	}
	
	void SelectEngine::runLoad()
	{
		TableEngine& tableEngine_ = TableEngine::instance();
		tableEngine_.runReader<SelectEngine>(this, streamUrl(), streamName());
		tableEngine_.runReader<SelectEngine>(this, sinkUrl(), sinkName());
	}
	
	void SelectEngine::runClear()
	{
		mIfSelects.clear();
	}
	
	const char * SelectEngine::streamName()
	{
		return "selectEngine";
	}
	
	const char * SelectEngine::streamUrl()
	{
		return "selectEngine.json";
	}
	
	const char * SelectEngine::sinkName()
	{
		return "selectSink";
	}
	
	const char * SelectEngine::sinkUrl()
	{
		return "selectSink.json";
	}
	
	SelectEngine& SelectEngine::instance()
	{
		return mSelectEngine;
	}
	
	SelectEngine::SelectEngine()
	{
		mIfSelects.clear();
	}
	
	SelectEngine::~SelectEngine()
	{
		mIfSelects.clear();
	}
	
	SelectEngine SelectEngine::mSelectEngine;
	
}
