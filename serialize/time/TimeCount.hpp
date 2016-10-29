#pragma once

namespace cc {
	
	class TimeCount : noncopyable
	{
	public:
		template <class T>
		void serialize(T * nSerialize, const char * nName, int8_t nCount)
		{
			nSerialize->runNumber(mCountType, "countType");
			nSerialize->runNumber(mCountSpace, "countSpace");
			nSerialize->runNumber(mCountCount, "countCount");
			nSerialize->runNumber(mCountNext, "countNext");
			nSerialize->runNumber(mCountCycle, "countCycle");
		}
		int8_t getCountType();
		int32_t getCountSpace();
		int32_t getCountCount();
		int32_t getCountNext();
		int32_t getCountCycle();
		
		TimeCount();
		~TimeCount();
		
	private:
		int8_t mCountType;
		int32_t mCountSpace;
		int32_t mCountCount;
		int32_t mCountNext;
		int32_t mCountCycle;
	};
	
}
