#pragma once

namespace cc {
	
	class TimeStart : noncopyable
	{
	public:
		template <class T>
		void serialize(T * nSerialize, const char * nName, int8_t nCount)
		{
			nSerialize->runNumber(mStartType, "startType");
			nSerialize->runTime(mTimeStart, "timeStart");
		}
		int8_t getStartType();
		int64_t getTimeStart();
		
		TimeStart();
		~TimeStart();
		
	private:
		int8_t mStartType;
		int64_t mTimeStart;
	};
	
}
