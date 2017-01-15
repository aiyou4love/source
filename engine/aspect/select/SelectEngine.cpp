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
		int32_t ifSelectId_ = nValue->getInt32(1);
		auto it = mIfSelects.find(ifSelectId_);
		if ( it == mIfSelects.end() ) {
			LOGE("[%s]%d", __METHOD__, ifSelectId_);
			return;
		}
		IfSelectPtr& ifSelect_ = it->second;
		
		int16_t authority0_ = ifSelect_->getAuthority();
		int16_t authority1_ = nEntity->getAuthority();
		if (authority0_ > authority1_) {
			LOGE("[%s]%d,%d,%d", __METHOD__, ifSelectId_, authority0_, authority1_);
			return;
		}
		
		int32_t selectId_ = ifSelect_->runIfSelect(nEntity, nValue);
		if (selectId_ > 0) {
			this->runTrigger(nEntity, EselectSink::mIfSelect, ifSelectId_);
			this->runTrigger(nEntity, EselectSink::mSelect, selectId_);
		}
		nEntity->runTrigger();
	}
	
	bool SelectEngine::isNetSelect(int32_t nSelectId, int16_t nAuthority)
	{
		auto it = mIfSelects.find(nSelectId);
		if ( it == mIfSelects.end() ) {
			LOGE("[%s]%d", __METHOD__, nSelectId);
			return false;
		}
		IfSelectPtr& select_ = it->second;
		return select_->isNet(nAuthority);
	}
	
	void SelectEngine::initSink(int16_t nSinkId, EntityPtr& nEntity)
	{
		SinkPtr * sink_ = this->findSink(nSinkId);
		if (nullptr == sink_) {
			LOGE("[%s]", __METHOD__);
			return;
		}
		nEntity->pushTrigger(nEntity, (*sink_));
	}
	
	void SelectEngine::runPreinit()
	{
		LifeCycle& lifeCycle_ = LifeCycle::instance();
		lifeCycle_.m_tRunLuaApi.connect(bind(&SelectEngine::runLuaApi, this));
		lifeCycle_.m_tLoadBegin.connect(bind(&SelectEngine::runLoad, this));
		lifeCycle_.m_tInitBegin.connect(bind(&SelectEngine::runInit, this));
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
		tableEngine_.runReader<SelectEngine>(this, globUrl(), globName());
		tableEngine_.runReader<SelectEngine>(this, selfUrl(), selfName());
	}
	
	void SelectEngine::runInit()
	{
		EngineMgr& engineMgr_ = EngineMgr::instance();
		engineMgr_.registerEngine(Eengine::mSelect, this);
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
	
	const char * SelectEngine::globName()
	{
		return "selectGlob";
	}
	
	const char * SelectEngine::globUrl()
	{
		return "selectGlob.json";
	}
	
	const char * SelectEngine::selfName()
	{
		return "selectSelf";
	}
	
	const char * SelectEngine::selfUrl()
	{
		return "selectSelf.json";
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
