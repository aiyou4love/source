#pragma once

namespace cc {
	
	class RoleUpdateClone : public IContextClone
	{
	public:
		ContextPtr createContext();
		const char * contextName();
	};
	
}
