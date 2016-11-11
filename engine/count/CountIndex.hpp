#pragma once

namespace cc {
	
	class CountIndex : noncopyable
	{
	public:
		template <class T>
		void runInit(T * nCount, IntArray * nIntArray)
		{
			nCount->runInit(nIntArray, mBegin, mEnd, mCount);
		}
		
		int16_t getBegin();
		int16_t getEnd();
		int16_t getCount();
		
		template <class T>
		void serialize(T * nSerialize, const char * nName, int8_t nCount)
		{
			nSerialize->runNumber(mBegin, "begin");
			nSerialize->runNumber(mEnd, "end");
			nSerialize->runNumber(mCount, "count");
			nSerialize->runNumber(mId, "key");
		}
		
		bool isDefault();
		int16_t getKey();
		
		CountIndex();
		~CountIndex();
		
	private:
		int16_t mBegin;
		int16_t mEnd;
		int16_t mCount;
		int16_t mId;
	};
	typedef SPTR<CountIndex> CountIndexPtr;
	
}
