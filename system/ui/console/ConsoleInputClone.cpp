#include "../../System.hpp"

namespace cc {
	
	ContextPtr ConsoleInputClone::createContext()
	{
		return ContextPtr(new ConsoleInput());
	}
	
	const char * ConsoleInputClone::contextName()
	{
		return "consoleInput";
	}
	
}
