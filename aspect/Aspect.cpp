#include "Aspect.hpp"

using namespace cc;

void aspectInit()
{
	dispatchInit();
	
	LuaAspect& luaAspect_ = LuaAspect::instance();
	luaAspect_.runPreinit();
	
	UiAspect& uiAspect_ = UiAspect::instance();
	uiAspect_.runPreinit();
	
	cAccountAspect& accountAspect_ = cAccountAspect::instance();
	accountAspect_.runPreinit();
	
	cRoleAspect& roleAspect_ = cRoleAspect::instance();
	roleAspect_.runPreinit();
}
