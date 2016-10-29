#include "../Serialize.hpp"

namespace cc {
	
	int64_t TimeAdjust::adjustTime(int64_t nTime)
	{
		if (!mNeedAdjust) return nTime;
		LocalTime localTime_(nTime);
		localTime_.adjustTime(mAdjustHour, mAdjustMinute, mAdjustSecond);
		return localTime_.getNumberTime();
	}
	
	int8_t TimeAdjust::getAdjustHour()
	{
		return mAdjustHour;
	}
	
	int8_t TimeAdjust::getAdjustMinute()
	{
		return mAdjustMinute;
	}
	
	int8_t TimeAdjust::getAdjustSecond()
	{
		return mAdjustSecond;
	}
	
	TimeAdjust::TimeAdjust()
		: mNeedAdjust(false)
		, mAdjustHour(0)
		, mAdjustMinute(0)
		, mAdjustSecond(0)
	{
	}
	
	TimeAdjust::~TimeAdjust()
	{
		mNeedAdjust = false;
		mAdjustHour = 0;
		mAdjustMinute = 0;
		mAdjustSecond = 0;
	}
	
}
