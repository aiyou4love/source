#pragma once

namespace cc {
	
#ifdef __CLIENT__
	class cServerTime : public ServerTime
	{
	public:
		void setServerTime(int64_t nTime, int32_t nDiff);
		
		int64_t getServerTime();
		int64_t getLocalTime();
		
		static cServerTime& instance();
		
		cServerTime();
		~cServerTime();
		
	private:
		static cServerTime mcServerTime;
		
		int64_t mServerTime;
	};
#endif
	
}
