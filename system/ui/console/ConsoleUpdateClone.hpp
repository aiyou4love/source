#pragma once

namespace cc {
	
	class ConsoleUpdateClone : public IContextClone
	{
	public:
		ContextPtr createContext();
		
		const char * contextName();
		
		ConsoleUpdateClone();
		~ConsoleUpdateClone();
	};
	
}
