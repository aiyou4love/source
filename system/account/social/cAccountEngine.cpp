#include "../../System.hpp"

namespace cc {
	
#ifdef __SOCIAL__
	void cAccountEngine::runPreinit()
	{
	}
	
	cAccountEngine& cAccountEngine::instance()
	{
		return mAccountEngine;
	}
	
	cAccountEngine::cAccountEngine()
	{
	}
	
	cAccountEngine::~cAccountEngine()
	{
	}
	
	cAccountEngine cAccountEngine::mAccountEngine;
#endif
	
}
