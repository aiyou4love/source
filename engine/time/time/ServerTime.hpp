#pragma once

namespace cc {
	
	class ServerTime : noncopyable
	{
	public:
		int32_t getBootTime();
		int32_t getTimeDiff();
		
		virtual void runPreinit();
		
		ServerTime();
		virtual ~ServerTime();
		
	protected:
		steady_clock::time_point mStartPoint;
		
		int32_t mTimeDiff;
	};
	
}
