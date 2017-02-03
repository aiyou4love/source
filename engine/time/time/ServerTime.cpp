#include "../../Engine.hpp"

namespace cc {
	
	int32_t ServerTime::getTimeDiff()
	{
		return mTimeDiff;
	}
	
	void ServerTime::runPreinit()
	{
		time_t ltime_ = time(nullptr);
		tm * tm_ = gmtime(&ltime_);
		time_t gtime_ = mktime(tm_);
		mTimeDiff = (int32_t)(ltime_ - gtime_);
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
