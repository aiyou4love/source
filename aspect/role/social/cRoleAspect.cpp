#include "../../Aspect.hpp"

namespace cc {
	
#ifdef __SOCIAL__
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
