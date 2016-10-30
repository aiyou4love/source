#pragma once

namespace cc {
	
	class Context : noncopyable
	{
	public:
		virtual void runContext(int64_t nTick) = 0;
		
		Context();
		virtual ~Context();
	};
	typedef WPTR<Context> ContextWtr;
	typedef SPTR<Context> ContextPtr;
	
}
