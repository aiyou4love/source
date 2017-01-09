#include "../../Aspect.hpp"

namespace cc {
	
#ifdef __SOCIAL__
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
