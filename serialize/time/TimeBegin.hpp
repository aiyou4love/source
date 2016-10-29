#pragma once

namespace cc {
	
	class TimeBegin : noncopyable
	{
	public:
		template <class T>
		void serialize(T * nSerialize, const char * nName, int8_t nCount)
		{
			nSerialize->runNumber(mBeginCount, "beginCount");
			nSerialize->runNumber(mBeginType, "beginType");
		}
		int32_t getBeginCount();
		int8_t getBeginType();
		
		TimeBegin();
		~TimeBegin();
		
	private:
		int32_t mBeginCount;
		int8_t mBeginType;
	};
	
}
