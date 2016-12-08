#include "../../Aspect.hpp"

namespace cc {
	
#ifdef __SOCIAL__
	cAccountAspect& cAccountAspect::instance()
	{
		return mAccountAspect;
	}
	
	cAccountAspect::cAccountAspect()
	{
	}
	
	cAccountAspect::~cAccountAspect()
	{
	}
	
	cAccountAspect cAccountAspect::mAccountAspect;
#endif
	
}
