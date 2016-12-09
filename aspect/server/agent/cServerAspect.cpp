#include "../../Aspect.hpp"

namespace cc {
	
#ifdef __AGENT__
	cServerAspect& cServerAspect::instance()
	{
		return mServerAspect;
	}
	
	cServerAspect::cServerAspect()
	{
	}
	
	cServerAspect::~cServerAspect()
	{
	}
	cServerAspect cServerAspect::mServerAspect;
#endif
	
}
