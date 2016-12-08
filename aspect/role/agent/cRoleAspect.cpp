#include "../../Aspect.hpp"

namespace cc {
	
#ifdef __AGENT__
	cRoleAspect& cRoleAspect::instance()
	{
		return mRoleAspect;
	}
	
	cRoleAspect::cRoleAspect()
	{
	}
	
	cRoleAspect::~cRoleAspect()
	{
	}
	
	cRoleAspect cRoleAspect::mRoleAspect;
#endif
	
}
