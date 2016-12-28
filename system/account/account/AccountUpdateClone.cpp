#include "../../System.hpp"

namespace cc {
	
	ContextPtr AccountUpdateClone::createContext()
	{
		return ContextPtr(new AccountUpdate());
	}
	
	const char * AccountUpdateClone::contextName()
	{
		return "accountUpdate";
	}
	
}
