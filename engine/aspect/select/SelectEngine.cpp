#include "../../Engine.hpp"

namespace cc {
	
	void SelectEngine::runIfSelect(EntityPtr& nEntity, ValuePtr& nValue)
	{
		int32_t ifSelectId_ = nValue->getInt32(2);
		auto it = mIfSelects.find(ifSelectId_);
		if ( it == mIfSelects.end() ) {
			LOGE("[%s]%d", __METHOD__, ifSelectId_);
			return;
		}
		IfSelectPtr& ifSelect_ = it->second;
		ifSelect_->runIfSelect(nEntity, nValue);
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
