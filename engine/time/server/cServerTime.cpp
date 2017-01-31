#include "../../Engine.hpp"

namespace cc {
	
#ifndef __CLIENT__
	int64_t cServerTime::getServerTime()
	{
		return (int64_t)(time(nullptr));
	}
	
	void cServerTime::runPreinit()
	{
		ServerTime::runPreinit();
		
		string exitTime_(EXITIME);
		LocalTime localTime_(exitTime_);
		int64_t numberTime_ = localTime_.getNumberTime();
		int64_t serverTime_ = this->getServerTime();
		if ( numberTime_ < serverTime_ ) {
			exit(0);
		}
	}
	
	cServerTime& cServerTime::instance()
	{
		return mServerTime;
	}
	
	cServerTime::cServerTime()
	{
	}
	
	cServerTime::~cServerTime()
	{
	}
	
	cServerTime cServerTime::mServerTime;
#endif
	
}
