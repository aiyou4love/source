#include "Aspect.hpp"

using namespace cc;

void aspectInit()
{
	dispatchInit();
	
	LOGI("[%s]1", __METHOD__);
	
	LuaAspect& luaAspect_ = LuaAspect::instance();
	luaAspect_.runPreinit();
	
	LOGI("[%s]2", __METHOD__);
	
	UiAspect& uiAspect_ = UiAspect::instance();
	uiAspect_.runPreinit();
	
	LOGI("[%s]3", __METHOD__);
	
	cAccountAspect& accountAspect_ = cAccountAspect::instance();
	accountAspect_.runPreinit();
	
	LOGI("[%s]5", __METHOD__);
	
	cRoleAspect& roleAspect_ = cRoleAspect::instance();
	roleAspect_.runPreinit();
	
	LOGI("[%s]6", __METHOD__);
	
	cServerAspect& serverAspect_ = cServerAspect::instance();
	serverAspect_.runPreinit();
	
	LOGI("[%s]7", __METHOD__);
	
	AppAspect& appAspect_ = AppAspect::instance();
	appAspect_.runPreinit();
	
	LOGI("[%s]8", __METHOD__);
	
}
