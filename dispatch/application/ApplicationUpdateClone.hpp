#pragma once

namespace cc {
	
	class ApplicationUpdateClone : public IContextClone
	{
	public:
		ContextPtr createContext();
		const char * contextName();
	};
	
}
