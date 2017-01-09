#include "../../System.hpp"

namespace cc {
	
	ContextPtr RoleUpdateClone::createContext()
	{
		return ContextPtr(new RoleUpdate());
	}
	
	const char * RoleUpdateClone::contextName()
	{
		return "roleUpdate";
	}
	
}
