#include "../../System.hpp"

namespace cc {
	
#ifdef __GAME__
	void cRoleEngine::pushValue(ValuePtr& nValue)
	{;
	}
	
	void cRoleEngine::runUpdate()
	{
	}
	
	void cRoleEngine::runPreinit()
	{
		DispatchEngine& dispatchEngine_ = DispatchEngine::instance();
		dispatchEngine_.registerDispatch(EdispatchId::mRoleId, this);
	}
	
	cRoleEngine& cRoleEngine::instance()
	{
		return mRoleEngine;
	}
	
	cRoleEngine::cRoleEngine()
	{
	}
	
	cRoleEngine::~cRoleEngine()
	{
	}
	
	cRoleEngine cRoleEngine::mRoleEngine;
#endif
	
}
