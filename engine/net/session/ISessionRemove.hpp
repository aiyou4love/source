#pragma once

namespace cc {
	
	class ISessionRemove : noncopyable
	{
	public:
		virtual void removeSession(int32_t nSessionId) = 0;
		virtual void removeSession(int64_t nAppId) = 0;
		
		ISessionRemove();
		virtual ~ISessionRemove();
	};
	
}
