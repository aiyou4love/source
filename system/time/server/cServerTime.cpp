#include "../../System.hpp"

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
		if ( localTime_.getNumberTime() < getServerTime()) {
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
