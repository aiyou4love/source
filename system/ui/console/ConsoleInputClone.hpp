#pragma once

namespace cc {
	
#ifdef __CLIENT__
	class ConsoleInputClone : public IContextClone
	{
	public:
		ContextPtr createContext();
		
		const char * contextName();
	};
#endif
	
}
