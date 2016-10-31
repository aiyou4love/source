#pragma once

namespace cc {
	
	class ConsoleInputClone : public IContextClone
	{
	public:
		ContextPtr createContext();
		
		const char * contextName();
	};
	
}
