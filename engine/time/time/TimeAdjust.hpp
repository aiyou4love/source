#pragma once

namespace cc {
	
	class TimeAdjust : noncopyable
	{
	public:
		template <class T>
		void serialize(T * nSerialize, const char * nName, int8_t nCount)
		{
			if ( 0 == strcmp("beginTime", nName) ) {
				nSerialize->runNumber(mNeedAdjust, "needBegin");
				nSerialize->runNumber(mAdjustHour, "beginHour");
				nSerialize->runNumber(mAdjustMinute, "beginMinute");
				nSerialize->runNumber(mAdjustSecond, "beginSecond");
			} else if ( 0 == strcmp("endTime", nName) ) {
				nSerialize->runNumber(mNeedAdjust, "needEnd");
				nSerialize->runNumber(mAdjustHour, "EndHour");
				nSerialize->runNumber(mAdjustMinute, "EndMinute");
				nSerialize->runNumber(mAdjustSecond, "EndSecond");
			} else {
				LOGE("[%s]%s", __METHOD__, nName);
			}
		}
		int64_t adjustTime(int64_t nTime);
		
		int8_t getAdjustHour();
		int8_t getAdjustMinute();
		int8_t getAdjustSecond();
		
		TimeAdjust();
		~TimeAdjust();
		
	private:
		bool mNeedAdjust;
		int8_t mAdjustHour;
		int8_t mAdjustMinute;
		int8_t mAdjustSecond;
	};
	
}
