#include "../../System.hpp"

namespace cc {

	int8_t TimeCount::getCountType()
	{
		return mCountType;
	}
	
	int32_t TimeCount::getCountSpace()
	{
		if ( EtimeCount::mDay == mCountType ) {
			return ( mCountSpace * 86400 );
		}
		if ( EtimeCount::mHour == mCountType ) {
			return ( mCountSpace * 3600 );
		}
		if ( EtimeCount::mMinute == mCountType ) {
			return ( mCountSpace * 60 );
		}
		return mCountSpace;
	}
	
	int32_t TimeCount::getCountCount()
	{
		if ( EtimeCount::mDay == mCountType ) {
			return ( mCountCount * 86400 );
		}
		if ( EtimeCount::mMinute == mCountType ) {
			return ( mCountCount * 60 );
		}
		return mCountCount;
	}
	
	int32_t TimeCount::getCountNext()
	{
		if ( EtimeCount::mDay == mCountType ) {
			return ( mCountNext * 86400 );
		}
		if ( EtimeCount::mMinute == mCountType ) {
			return ( mCountNext * 60 );
		}
		return mCountNext;
	}
	
	int32_t TimeCount::getCountCycle()
	{
		if ( EtimeCount::mDay == mCountType ) {
			return ( mCountCycle * 86400 );
		}
		if ( EtimeCount::mMinute == mCountType ) {
			return ( mCountCycle * 60 );
		}
		return mCountCycle;
	}
	
	TimeCount::TimeCount()
		: mCountType(EtimeCount::mDay)
		, mCountSpace(0)
		, mCountCount(0)
		, mCountNext(0)
		, mCountCycle(0)
	{
	}
	
	TimeCount::~TimeCount()
	{
		mCountType = EtimeCount::mDay;
		mCountSpace = 0;
		mCountCount = 0;
		mCountNext = 0;
		mCountCycle = 0;
	}
	
}
