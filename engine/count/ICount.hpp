#pragma once

namespace cc {
	
	class ICount : noncopyable
	{
	public:
		virtual void runReset(int16_t nId) = 0;
		void runReset();
		
		int16_t getN();
		
		virtual void runInit(IntArray * nIntArray, CountIndexPtr& nCountIndex);
		
		ICount();
		virtual ~ICount();
		
	protected:
		IntArray * mIntArray;
		int32_t * mValue;
		int16_t N;
	};
	
}
