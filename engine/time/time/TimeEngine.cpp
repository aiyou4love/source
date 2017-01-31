#include "../../Engine.hpp"

namespace cc {
	
	int8_t TimeEngine::checkTimeState(int32_t nTimeId, int64_t nInputTime)
	{
		auto it = mTimeDurations.find(nTimeId);
		if ( it == mTimeDurations.end() ) {
			LOGE("[%s]%s", __METHOD__, nTimeId);
			return EtimeState::mClose;
		}
		TimeDurationPtr& timeDuration_ = it->second;
		
		cServerTime& serverTime_ = cServerTime::instance();
		int64_t nowTime_ = serverTime_.getServerTime();
		
		return timeDuration_->checkTimeState(nInputTime, nowTime_);
	}
	
	int64_t TimeEngine::getBeginTime(int32_t nTimeId, int64_t nInputTime)
	{
		auto it = mTimeDurations.find(nTimeId);
		if ( it == mTimeDurations.end() ) {
			LOGE("[%s]%s", __METHOD__, nTimeId);
			return EtimeState::mClose;
		}
		TimeDurationPtr& timeDuration_ = it->second;
		
		cServerTime& serverTime_ = cServerTime::instance();
		int64_t nowTime_ = serverTime_.getServerTime();
		
		return timeDuration_->getBeginTime(nInputTime, nowTime_);
	}
	
	int64_t TimeEngine::getEndTime(int32_t nTimeId, int64_t nInputTime)
	{
		auto it = mTimeDurations.find(nTimeId);
		if ( it == mTimeDurations.end() ) {
			LOGE("[%s]%s", __METHOD__, nTimeId);
			return EtimeState::mClose;
		}
		TimeDurationPtr& timeDuration_ = it->second;
		
		cServerTime& serverTime_ = cServerTime::instance();
		int64_t nowTime_ = serverTime_.getServerTime();
		
		return timeDuration_->getEndTime(nInputTime, nowTime_);
	}
	
	int32_t TimeEngine::getLeftTime(int32_t nTimeId, int64_t nInputTime)
	{
		auto it = mTimeDurations.find(nTimeId);
		if ( it == mTimeDurations.end() ) {
			LOGE("[%s]%s", __METHOD__, nTimeId);
			return EtimeState::mClose;
		}
		TimeDurationPtr& timeDuration_ = it->second;
		
		cServerTime& serverTime_ = cServerTime::instance();
		int64_t nowTime_ = serverTime_.getServerTime();
		
		return timeDuration_->getLeftTime(nInputTime, nowTime_);
	}
	
	const char * TimeEngine::streamName()
	{
		return "timeEngine";
	}
	
	const char * TimeEngine::streamUrl()
	{
		return "timeEngine.json";
	}
	
	void TimeEngine::runPreinit()
	{
		LifeCycle& lifeCycle_ = LifeCycle::instance();
		lifeCycle_.m_tLoadBegin.connect(bind(&TimeEngine::runLoad, this));
		lifeCycle_.m_tClearEnd.connect(bind(&TimeEngine::runClear, this));
	}
	
	void TimeEngine::runLoad()
	{
		TableEngine& tableEngine_ = TableEngine::instance();
		tableEngine_.runReader<TimeEngine>(this, streamUrl(), streamName());
	}
	
	void TimeEngine::runClear()
	{
		mTimeDurations.clear();
	}
	
	TimeEngine& TimeEngine::instance()
	{
		return mTimeEngine;
	}
	
	TimeEngine::TimeEngine()
	{
		this->runClear();
	}
	
	TimeEngine::~TimeEngine()
	{
		this->runClear();
	}
	
	TimeEngine TimeEngine::mTimeEngine;
	
}
