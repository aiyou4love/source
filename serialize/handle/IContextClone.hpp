#pragma once

namespace cc {
	
	class IContextClone : noncopyable
	{
	public:
		virtual ContextPtr createContext() = 0;
		virtual const char * contextName() = 0;
		
		IContextClone();
		virtual ~IContextClone();
	};
	
}
