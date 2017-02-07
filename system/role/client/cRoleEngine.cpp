#include "../../System.hpp"

namespace cc {
	
#ifdef __CLIENT__
	int32_t cRoleEngine::setServerId(int32_t nServerId)
	{
		cRoleList& roleList_ = cRoleList::instance();
		RoleItem * roleItem_ = roleList_.getRoleItem(nServerId);
		if (nullptr == roleItem_) {
			return 0;
		}
		cRolePtr role_ = PTR_DCST<cRole>(mRole);
		role_->setRoleItem(roleItem_);
		
		return (roleItem_->getServerId());
	}
	
	void cRoleEngine::runCancel()
	{
		cRolePtr role_ = PTR_DCST<cRole>(mRole);
		role_->runClear();
		
		cRoleList& roleList_ = cRoleList::instance();
		roleList_.runClear();
		roleList_.runSave();
	}
	
	void cRoleEngine::setRoleItem(RoleItemPtr& nRoleItem)
	{
		cRolePtr role_ = PTR_DCST<cRole>(mRole);
		role_->setRoleItem(nRoleItem);
		
		cRoleList& roleList_ = cRoleList::instance();
		roleList_.pushRoleItem(nRoleItem);
	}
	
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
