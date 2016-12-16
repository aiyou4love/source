#pragma once

namespace cc {
	
#ifdef __CLIENT__
	class ConsoleUiUpdateClone : public IContextClone
	{
	public:
		ContextPtr createContext();
		
		const char * contextName();
		
		ConsoleUiUpdateClone();
		~ConsoleUiUpdateClone();
	};
#endif
	
}
