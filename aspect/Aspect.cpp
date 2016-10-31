#include "Aspect.hpp"

using namespace cc;

void aspectInit()
{
	dispatchInit();
	
	LuaAspect& luaAspect_ = LuaAspect::instance();
	luaAspect_.runPreinit();
}
