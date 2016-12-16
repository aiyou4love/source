#include "../../System.hpp"

namespace cc {
	
#ifdef __CLIENT__
	ContextPtr ConsoleInputClone::createContext()
	{
		return ContextPtr(new ConsoleInput());
	}
	
	const char * ConsoleInputClone::contextName()
	{
		return "consoleInput";
	}
#endif
	
}
