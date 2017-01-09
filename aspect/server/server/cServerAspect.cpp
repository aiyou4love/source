#include "../../Aspect.hpp"

namespace cc {
	
#ifndef __CLIENT__
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
