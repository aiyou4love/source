#include "../../System.hpp"

namespace cc {
	
#ifdef __CLIENT__
	void cRoleEngine::pushValue(ValuePtr& nValue)
	{
		mRole->pushValue(nValue);
	}
	
	void cRoleEngine::runUpdate()
	{
		SelectEngine& selectEngine_ = SelectEngine::instance();
		
		ValuePtr value_ = mRole->popValue();
		if (!value_) return;
		selectEngine_.runIfSelect(mRole, value_);
	}
	
	EntityPtr& cRoleEngine::getRole()
	{
		return mRole;
	}
	
	void cRoleEngine::runLuaApi()
	{
		LuaEngine& luaEngine_ = LuaEngine::instance();
		luaEngine_.runClass<cRoleEngine>("cRoleEngine");
		luaEngine_.runStatic<cRoleEngine>(cRoleEngine::instance, "instance");
		luaEngine_.runMethod<cRoleEngine>(&cRoleEngine::getRole, "getRole");
	}
	
	void cRoleEngine::runPreinit()
	{
		DispatchEngine& dispatchEngine_ = DispatchEngine::instance();
		dispatchEngine_.registerDispatch(EdispatchId::mRoleId, this);
		
		LifeCycle& lifeCycle_ = LifeCycle::instance();
		
		lifeCycle_.m_tRunLuaApi.connect(bind(&cRoleEngine::runLuaApi, this));
		
		mRole.reset(new cRole());
	}
	
	cRoleEngine& cRoleEngine::instance()
	{
		return mRoleEngine;
	}
	
	cRoleEngine::cRoleEngine()
	{
	}
	
	cRoleEngine::~cRoleEngine()
	{
	}
	
	cRoleEngine cRoleEngine::mRoleEngine;
#endif
	
}
