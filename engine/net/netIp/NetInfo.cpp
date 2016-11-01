#include "../../Engine.hpp"

namespace cc {
	
	int64_t NetInfo::getStartTime()
	{
		return mStartTime;
	}
	
	bool NetInfo::isDefault()
	{
		return ( (0 == mAppNo) || (0 == mStartTime) );
	}
	
	int32_t NetInfo::getKey()
	{
		return mAppNo;
	}
	
	NetInfo::NetInfo()
		: mAppNo (0)
		, mStartTime (0)
	{
	}
	
	NetInfo::~NetInfo()
	{
		mStartTime = 0;
		
		mAppNo = 0;
	}
	
}
