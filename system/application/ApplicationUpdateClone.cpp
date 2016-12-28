#include "../System.hpp"

namespace cc {
	
	ContextPtr ApplicationUpdateClone::createContext()
	{
		return ContextPtr(new ApplicationUpdate());
	}
	
	const char * ApplicationUpdateClone::contextName()
	{
		return "applicationUpdate";
	}
	
}
