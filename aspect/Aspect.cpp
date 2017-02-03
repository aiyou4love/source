#include "Aspect.hpp"

using namespace cc;

void aspectInit()
{
	systemInit();
	
	LOGI("[%s]1", __METHOD__);
	
	LuaAspect& luaAspect_ = LuaAspect::instance();
	luaAspect_.runPreinit();
	
	UiAspect& uiAspect_ = UiAspect::instance();
	uiAspect_.runPreinit();
	
#if ( (defined __CLIENT__) || (defined __AGENT__) )
	cAccountAspect& accountAspect_ = cAccountAspect::instance();
	accountAspect_.runPreinit();
#endif
	
	cRoleAspect& roleAspect_ = cRoleAspect::instance();
	roleAspect_.runPreinit();
	
	cServerAspect& serverAspect_ = cServerAspect::instance();
	serverAspect_.runPreinit();
	
	AppAspect& appAspect_ = AppAspect::instance();
	appAspect_.runPreinit();
	
	cNetAspect& netAspect_ = cNetAspect::instance();
	netAspect_.runPreinit();
}
