#pragma once

namespace cc {
	
#ifdef __CLIENT__
	class cServerTime : public ServerTime
	{
	public:
		void setServerDiff(int32_t nServerDiff);
		
		void setServerTime(int64_t nServerTime);
		int64_t getServerTime();
		
		static cServerTime& instance();
		
		cServerTime();
		~cServerTime();
		
	private:
		static cServerTime mcServerTime;
		
		steady_clock::time_point mStartPoint;
		int64_t mServerTime;
	};
#endif
	
}
