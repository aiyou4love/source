#include "../../Engine.hpp"

namespace cc {
	
	int8_t TimeDuration::checkTimeState(int64_t nInputTime, int64_t nNowTime)
	{
		if ( EtimeType::mOpen == mTimeType ) return EtimeState::mOpen;
		if ( EtimeType::mClose == mTimeType ) return EtimeState::mClose;
		if ( EtimeType::mAfter == mTimeType ) {
			int64_t beginTime_ = this->getBeginTime(nInputTime, nNowTime);
			if ( 0 == beginTime_ ) return EtimeState::mOpen;
			if ( nNowTime <= beginTime_ ) return EtimeState::mBefore;
			int64_t endTime_ = this->gainEndTime(beginTime_, nNowTime);
			if ( nNowTime > endTime_ ) return EtimeState::mOpen;
			return EtimeState::mBefore;
		}
		int64_t beginTime_ = this->getBeginTime(nInputTime, nNowTime);
		if ( 0 == beginTime_ ) return EtimeState::mAfter;
		if ( nNowTime <= beginTime_ ) return EtimeState::mBefore;
		int64_t endTime_ = this->gainEndTime(beginTime_, nNowTime);
		if ( nNowTime > endTime_ ) return EtimeState::mAfter;
		return EtimeState::mOpen;
	}
	
	int64_t TimeDuration::getStartTime(int64_t nInputTime, int64_t nNowTime)
	{
		int64_t result_ = nInputTime;
		int8_t timeStart_ = mTimeStart.getStartType();
		if (timeStart_ == EtimeStart::mNowTime) {
			result_ = nNowTime;
		} else if (timeStart_ == EtimeStart::mConfigure) {
			result_ = mTimeStart.getTimeStart();
		} else {
			result_ = nInputTime;
		}
		result_ += mTimeCount.getCountSpace();
		result_ = this->adjustBeginTime(result_, nNowTime);
		return mBeginTime.adjustTime(result_);
	}
	
	int64_t TimeDuration::getBeginTime(int64_t nInputTime, int64_t nNowTime)
	{
		int64_t startTime_ = this->getStartTime(nInputTime, nNowTime);
		if ( nNowTime <= startTime_ ) return startTime_;
		int32_t countCount_ = mTimeCount.getCountCount();
		int32_t countNext_ = mTimeCount.getCountNext();
		int32_t countCycle_ = mTimeCount.getCountCycle();
		if ( (countCount_ > 0) && (countNext_ > 0) ) {
			int64_t leftStart_ = nNowTime - startTime_;
			int64_t cycleCount_ = leftStart_ / (countCount_ + countNext_);
			startTime_ += ( cycleCount_ * (countCount_ + countNext_) );
			if ( ( countCycle_<= cycleCount_ ) && (countCycle_ > 0) ) {
				startTime_ = 0;
			}
		}
		return startTime_;
	}
	
	int64_t TimeDuration::getEndTime(int64_t nInputTime, int64_t nNowTime)
	{
		int64_t beginTime_ = this->getBeginTime(nInputTime, nNowTime);
		if ( 0 == beginTime_ ) return 0;
		return this->gainEndTime(beginTime_, nNowTime);
	}
	
	int32_t TimeDuration::getLeftTime(int64_t nInputTime, int64_t nNowTime)
	{
		int64_t beginTime_ = this->getBeginTime(nInputTime, nNowTime);
		if ( 0 == beginTime_ ) return 0;
		int64_t endTime_ = this->gainEndTime(beginTime_, nNowTime);
		return (int32_t(endTime_ - nNowTime));
	}
	
	int64_t TimeDuration::gainEndTime(int64_t nBeginTime, int64_t nNowTime)
	{
		int64_t endTime_ = ( nBeginTime + mTimeCount.getCountCount() );
		endTime_ = this->adjustEndTime(endTime_, nNowTime);
		return mEndTime.adjustTime(endTime_);
	}
	
	int64_t TimeDuration::adjustBeginTime(int64_t nBeginTime, int64_t nNowTime)
	{
		int64_t result_ = nBeginTime;
		
		int8_t timeBegin_ = mTimeBegin.getBeginType();
		if ( timeBegin_ == EtimeBegin::mEveryWeek ) {
			LocalTime localTime_(result_);
			int8_t wday_ = localTime_.getWeek();
			int32_t count_ = mTimeBegin.getBeginCount();
			for ( int8_t i = 0; i < 7; ++i ) {
				if ( ( wday_ & count_ ) > 0 ) {
					result_ += (i * 86400);
					break;
				}
				wday_++;
			}
		} else if ( timeBegin_ == EtimeBegin::mEveryDay ) {
			if ( result_ < nNowTime ) {
				result_ = nNowTime;
			}
		} else {
		}
		
		return result_;
	}
	
	int64_t TimeDuration::adjustEndTime(int64_t nEndTime, int64_t nNowTime)
	{
		int64_t result_ = nEndTime;
		
		//int8_t timeEnd_ = mTimeEnd.getEndType();
		//if ( timeEnd_ == EtimeEnd::mNull ) {
		//} else {
		//}
		
		return result_;
	}
	
	bool TimeDuration::isDefault()
	{
		return ( (0 == mId) || (0 == mTimeType) );
	}
	
	int32_t TimeDuration::getKey()
	{
		return mId;
	}
	
	TimeDuration::TimeDuration()
		: mTimeType(0)
		, mId(0)
	{
	}
	
	TimeDuration::~TimeDuration()
	{
		mTimeType = 0;
		mId = 0;
	}
	
}
