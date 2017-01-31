#include "../../Engine.hpp"

namespace cc {
	
#ifdef __CLIENT__
	void cServerTime::finishAdjust(int64_t nTime, int32_t nDiff)
	{
		steady_clock::time_point nowPoint_ = steady_clock::now();
		duration<int32_t> timeSpan_ = duration_cast<duration<int32_t> >(nowPoint_ - mStartPoint);
		int32_t value_ = timeSpan_.count() - mNumberTime;
		if ( (mMaxTime > 0) && (mMaxTime <= value_) ) {
			return;
		}
		mMaxTime = value_;
		mServerTime = nTime - timeSpan_.count();
		mServerTime += (mMaxTime / 2);
		
		int32_t timeDiff_ = mTimeDiff - nDiff;
		mServerTime += timeDiff_;
	}
	
	void cServerTime::startAdjust()
	{
		steady_clock::time_point nowPoint_ = steady_clock::now();
		duration<int32_t> timeSpan_ = duration_cast<duration<int32_t> >(nowPoint_ - mStartPoint);
		mNumberTime = timeSpan_.count();
	}
	
	int64_t cServerTime::getServerTime()
	{
		steady_clock::time_point nowPoint_ = steady_clock::now();
		duration<int32_t> timeSpan_ = duration_cast<duration<int32_t> >(nowPoint_ - mStartPoint);
		return (mServerTime + timeSpan_.count());
	}
	
	int64_t cServerTime::getLocalTime()
	{
		return (int64_t)(time(nullptr));
	}
	
	int32_t cServerTime::getBootTime()
	{
		steady_clock::time_point nowPoint_ = steady_clock::now();
		duration<int32_t> timeSpan_ = duration_cast<duration<int32_t> >(nowPoint_ - mStartPoint);
		return timeSpan_.count();
	}
	
	void cServerTime::runPreinit()
	{
		mStartPoint = steady_clock::now();
	}
	
	cServerTime& cServerTime::instance()
	{
		return mcServerTime;
	}
	
	cServerTime::cServerTime()
		: mServerTime (0)
		, mNumberTime (0)
		, mMaxTime (0)
	{
	}
	
	cServerTime::~cServerTime()
	{
		mServerTime = 0;
		mNumberTime = 0;
		mMaxTime = 0;
	}
	
	cServerTime cServerTime::mcServerTime;
#endif
	
}
