#pragma once

namespace cc {
	
	class IntIndex : noncopyable
	{
	public:
		int16_t getN();
		
		template <class T>
		void serialize(T * nSerialize, const char * nName, int8_t nCount)
		{
			nSerialize->runNumber(mId, "key");
			nSerialize->runNumber(N, "N");
		}
		
		bool isDefault();
		int16_t getKey();
		
		IntIndex();
		~IntIndex();
		
	private:
		int16_t mId;
		int16_t N;
	};
	typedef SPTR<IntIndex> IntIndexPtr;
	
}
