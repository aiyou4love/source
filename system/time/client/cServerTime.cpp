#include "../../System.hpp"

namespace cc {
	
#ifdef __CLIENT__
	void cServerTime::setServerDiff(int32_t nServerDiff)
	{
		int32_t timeDiff_ = mTimeDiff - nServerDiff;
		mServerTime += timeDiff_;
	}
	
	void cServerTime::setServerTime(int64_t nServerTime)
	{
		mStartPoint = steady_clock::now();
		mServerTime = nServerTime;
	}
	
	int64_t cServerTime::getServerTime()
	{
		steady_clock::time_point nowPoint_ = steady_clock::now();
		duration<int32_t> timeSpan_ = duration_cast<duration<int32_t> >(nowPoint_ - mStartPoint);
		return (mServerTime + timeSpan_.count());
	}
	
	cServerTime& cServerTime::instance()
	{
		return mcServerTime;
	}
	
	cServerTime::cServerTime()
		: mServerTime (0)
	{
	}
	
	cServerTime::~cServerTime()
	{
		mServerTime = 0;
	}
	
	cServerTime cServerTime::mcServerTime;
#endif
	
}
