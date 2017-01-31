#pragma once

namespace cc {
	
	class ServerTime : noncopyable
	{
	public:
		virtual void runPreinit();
		
		ServerTime();
		virtual ~ServerTime();
		
	protected:
		int32_t mTimeDiff;
	};
	
}
