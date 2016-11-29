#pragma once

namespace cc {
	
#ifdef __CLIENT__
	class cServerTime : public ServerTime
	{
	public:
		void finishAdjust(int64_t nTime, int32_t nDiff);
		void startAdjust();
		
		int64_t getServerTime();
		
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
