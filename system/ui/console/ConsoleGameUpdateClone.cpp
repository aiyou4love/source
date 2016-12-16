#include "../../System.hpp"

namespace cc {
	
#ifdef __CLIENT__
	ContextPtr ConsoleGameUpdateClone::createContext()
	{
		return ContextPtr(new ConsoleUiUpdate());
	}
	
	const char * ConsoleGameUpdateClone::contextName()
	{
		return "consoleGameUpdate";
	}
	
	ConsoleGameUpdateClone::ConsoleGameUpdateClone()
	{
	}
	
	ConsoleGameUpdateClone::~ConsoleGameUpdateClone()
	{
	}
#endif
	
}
