#pragma once

namespace cc {
	
	class CountIndex : noncopyable
	{
	public:
		int16_t getBegin();
		int16_t getEnd();
		int16_t getCount();
		int16_t getInt();
		int16_t getClassify();
		int32_t getCrcId();
		
		template <class T>
		void serialize(T * nSerialize, const char * nName, int8_t nCount)
		{
			nSerialize->runNumber(mBegin, "begin");
			nSerialize->runNumber(mEnd, "end");
			nSerialize->runNumber(mCount, "count");
			nSerialize->runNumber(mInt, "int");
			nSerialize->runCrc32(mCrcId, "crcId");
			nSerialize->runNumber(mClassify, "classify");
			nSerialize->runNumber(mId, "id");
		}
		
		bool isDefault();
		int32_t getKey();
		
		CountIndex();
		~CountIndex();
		
	private:
		int16_t mBegin;
		int16_t mEnd;
		int16_t mCount;
		int16_t mInt;
		int32_t mCrcId;
		int16_t mClassify;
		int16_t mId;
	};
	typedef SPTR<CountIndex> CountIndexPtr;
	
}
