#include "../Serialize.hpp"

namespace cc {
	
	int8_t TimeEnd::getEndType()
	{
		return mEndType;
	}
	
	int32_t TimeEnd::getEndCount()
	{
		return mEndCount;
	}
	
	TimeEnd::TimeEnd()
		: mEndType(0)
		, mEndCount(0)
	{
	}
	
	TimeEnd::~TimeEnd()
	{
		mEndCount = 0;
		mEndType = 0;
	}
	
}
