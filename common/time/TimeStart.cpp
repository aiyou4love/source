#include "../Serialize.hpp"

namespace cc {
	
	int8_t TimeStart::getStartType()
	{
		return mStartType;
	}
	
	int64_t TimeStart::getTimeStart()
	{
		return mTimeStart;
	}
	
	TimeStart::TimeStart()
		: mStartType(EtimeStart::mNowTime)
		, mTimeStart(0)
	{
	}
	
	TimeStart::~TimeStart()
	{
		mStartType = EtimeStart::mNowTime;
		mTimeStart = 0;
	}
	
}
