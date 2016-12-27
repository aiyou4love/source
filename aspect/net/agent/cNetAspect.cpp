#include "../../Aspect.hpp"

namespace cc {
	
#ifdef __AGENT__
	cNetAspect& cNetAspect::instance()
	{
		return mNetAspect;
	}
	
	cNetAspect::cNetAspect()
	{
	}
	
	cNetAspect::~cNetAspect()
	{
	}
	cNetAspect cNetAspect::mNetAspect;
#endif
	
}
