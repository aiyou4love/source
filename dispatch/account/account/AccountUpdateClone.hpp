#pragma once

namespace cc {
	
	class AccountUpdateClone : public IContextClone
	{
	public:
		ContextPtr createContext();
		const char * contextName();
	};
	
}
