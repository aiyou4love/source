#pragma once

namespace cc {
	
	class HandleCount : noncopyable
	{
	public:
		template <class T>
		void serialize(T * nSerialize, const char * nName, int8_t nCount)
		{
			nSerialize->runNumber(mIndex, "index");
			nSerialize->runNumber(mTicks, "ticks");
		}
		int32_t getTicks();
		
		int16_t getKey();
		bool isDefault();
		
		HandleCount();
		~HandleCount();
		
	private:
		int16_t mIndex;
		int32_t mTicks;
	};
	typedef SPTR<HandleCount> HandleCountPtr;
	
}
