#pragma once

namespace cc {
	
	class TimeDuration : noncopyable
	{
	public:
		int8_t checkTimeState(int64_t nInputTime, int64_t nNowTime);
		int64_t getBeginTime(int64_t nInputTime, int64_t nNowTime);
		int64_t getEndTime(int64_t nInputTime, int64_t nNowTime);
		int32_t getLeftTime(int64_t nInputTime, int64_t nNowTime);
		
		template <class T>
		void serialize(T * nSerialize, const char * nName, int8_t nCount)
		{
			nSerialize->runNumber(mId, "timeId");
			
			nSerialize->runNumber(mTimeType, "timeType");
			nSerialize->runStream(mTimeStart, "timeStart");
			nSerialize->runStream(mTimeBegin, "timeBegin");
			nSerialize->runStream(mBeginTime, "beginTime");
			nSerialize->runStream(mTimeCount, "timeCount");
			nSerialize->runStream(mTimeEnd, "timeEnd");
			nSerialize->runStream(mEndTime, "endTime");
		}
		bool isDefault();
		int32_t getKey();
		
	private:
		int64_t getStartTime(int64_t nInputTime, int64_t nNowTime);
		int64_t adjustBeginTime(int64_t nBeginTime, int64_t nNowTime);
		int64_t adjustEndTime(int64_t nEndTime, int64_t nNowTime);
		int64_t gainEndTime(int64_t nBeginTime, int64_t nNowTime);
		
	public:
		TimeDuration();
		~TimeDuration();
		
	private:
		int8_t mTimeType;
		
		TimeStart mTimeStart;
		TimeBegin mTimeBegin;
		TimeAdjust mBeginTime;
		
		TimeCount mTimeCount;
		
		TimeEnd mTimeEnd;
		TimeAdjust mEndTime;
		
		int32_t mId;
	};
	typedef SPTR<TimeDuration> TimeDurationPtr;
	
}
