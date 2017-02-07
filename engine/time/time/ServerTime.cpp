#include "../../Engine.hpp"

namespace cc {
	
	int32_t ServerTime::getTimeDiff()
	{
		return mTimeDiff;
	}
	
	int32_t ServerTime::getBootTime()
	{
		steady_clock::time_point nowPoint_ = steady_clock::now();
		duration<int32_t> timeSpan_ = duration_cast<duration<int32_t> >(nowPoint_ - mStartPoint);
		return timeSpan_.count();
	}
	
	void ServerTime::runPreinit()
	{
		time_t ltime_ = time(nullptr);
		tm * tm_ = gmtime(&ltime_);
		time_t gtime_ = mktime(tm_);
		mTimeDiff = (int32_t)(ltime_ - gtime_);
		
		mStartPoint = steady_clock::now();
	}
	
	ServerTime::ServerTime()
		: mTimeDiff (0)
	{
	}
	
	ServerTime::~ServerTime()
	{
		mTimeDiff = 0;
	}
	
}
