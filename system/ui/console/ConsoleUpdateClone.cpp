#include "../../System.hpp"

namespace cc {
	
	ContextPtr ConsoleUpdateClone::createContext()
	{
		return ContextPtr(new ConsoleUpdate());
	}
	
	const char * ConsoleUpdateClone::contextName()
	{
		return "consoleUpdate";
	}
	
	ConsoleUpdateClone::ConsoleUpdateClone()
	{
		
	}
	
	ConsoleUpdateClone::~ConsoleUpdateClone()
	{
		
	}
	
}
