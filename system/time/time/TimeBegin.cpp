#include "../../System.hpp"

namespace cc {
	
	int8_t TimeBegin::getBeginType()
	{
		return mBeginType;
	}
	
	int32_t TimeBegin::getBeginCount()
	{
		return mBeginCount;
	}
	
	TimeBegin::TimeBegin()
		: mBeginType(0)
		, mBeginCount(0)
	{
	}
	
	TimeBegin::~TimeBegin()
	{
		mBeginCount = 0;
		mBeginType = 0;
	}
	
}
