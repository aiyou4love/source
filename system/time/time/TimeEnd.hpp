#pragma once

namespace cc {
	
	class TimeEnd : noncopyable
	{
	public:
		template <class T>
		void serialize(T * nSerialize, const char * nName, int8_t nCount)
		{
			nSerialize->runNumber(mEndCount, "endCount");
			nSerialize->runNumber(mEndType, "endType");
		}
		int32_t getEndCount();
		int8_t getEndType();
		
		TimeEnd();
		~TimeEnd();
		
	private:
		int32_t mEndCount;
		int8_t mEndType;
	};
	
}
