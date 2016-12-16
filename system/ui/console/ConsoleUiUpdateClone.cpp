#include "../../System.hpp"

namespace cc {
	
#ifdef __CLIENT__
	ContextPtr ConsoleUiUpdateClone::createContext()
	{
		return ContextPtr(new ConsoleUiUpdate());
	}
	
	const char * ConsoleUiUpdateClone::contextName()
	{
		return "consoleUiUpdate";
	}
	
	ConsoleUiUpdateClone::ConsoleUiUpdateClone()
	{
		
	}
	
	ConsoleUiUpdateClone::~ConsoleUiUpdateClone()
	{
		
	}
#endif
	
}
