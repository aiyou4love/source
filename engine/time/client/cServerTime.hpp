#pragma once

namespace cc {
	
#ifdef __CLIENT__
	class cServerTime : public ServerTime
	{
	public:
		void setServerTime(int64_t nTime, int32_t nDiff);
		
		int64_t getServerTime();
		int64_t getLocalTime();
		int32_t getBootTime();
		
		void runPreinit();
		
		static cServerTime& instance();
		
		cServerTime();
		~cServerTime();
		
	private:
		static cServerTime mcServerTime;
		
		steady_clock::time_point mStartPoint;
		
		int32_t mNumberTime;
		int32_t mMaxTime;
		int64_t mServerTime;
	};
#endif
	
}
