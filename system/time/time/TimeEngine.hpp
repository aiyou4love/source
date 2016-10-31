#pragma once

namespace cc {
	
	class TimeEngine : noncopyable
	{
	public:
		int8_t checkTimeState(int32_t nTimeId, int64_t nInputTime);
		int64_t getBeginTime(int32_t nTimeId, int64_t nInputTime);
		int64_t getEndTime(int32_t nTimeId, int64_t nInputTime);
		int32_t getLeftTime(int32_t nTimeId, int64_t nInputTime);
		
		template<class T>
		void headSerialize(T& nSerialize, const char * nName)
		{
			nSerialize.runMapStreamPtrs<int32_t, TimeDurationPtr>(mTimeDurations, "timeDurations", "timeDuration");
		}
		const char * streamName();
		const char * streamUrl();
		
		void runPreinit();
		void runLoad();
		void runClear();
		
		static TimeEngine& instance();
		
		TimeEngine();
		~TimeEngine();
		
	private:
		map<int32_t, TimeDurationPtr> mTimeDurations;
		
		static TimeEngine mTimeEngine;
	};
	
}
