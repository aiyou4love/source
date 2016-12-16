#pragma once

namespace cc {
	
#ifdef __CLIENT__
	class ConsoleGameUpdateClone : public IContextClone
	{
	public:
		ContextPtr createContext();
		
		const char * contextName();
		
		ConsoleGameUpdateClone();
		~ConsoleGameUpdateClone();
	};
#endif
	
}
