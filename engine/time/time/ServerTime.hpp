#pragma once

namespace cc {
	
	class ServerTime : noncopyable
	{
	public:
		int32_t getTimeDiff();
		
		virtual void runPreinit();
		
		ServerTime();
		virtual ~ServerTime();
		
	protected:
		int32_t mTimeDiff;
	};
	
}
