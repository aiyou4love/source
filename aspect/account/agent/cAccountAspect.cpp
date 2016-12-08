#include "../../Aspect.hpp"

namespace cc {
	
#ifdef __AGENT__
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
