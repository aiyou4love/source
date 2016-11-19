#pragma once

namespace cc {
	
	class IntIndex : noncopyable
	{
	public:
		int16_t getClassify();
		int16_t getType();
		int16_t getCount();
		
		template <class T>
		void serialize(T * nSerialize, const char * nName, int8_t nCount)
		{
			nSerialize->runNumber(mClassify, "classify");
			nSerialize->runNumber(mType, "type");
			nSerialize->runNumber(mCount, "count");
			
			nSerialize->runNumber(mId, "key");
		}
		
		bool isDefault();
		int16_t getKey();
		
		IntIndex();
		~IntIndex();
		
	private:
		int16_t mClassify;
		int16_t mType;
		int16_t mCount;
		
		int16_t mId;
	};
	typedef SPTR<IntIndex> IntIndexPtr;
	
}
