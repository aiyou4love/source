#pragma once

namespace cc {
	
	class BitCount : noncopyable
	{
	public:
		void runReset(int16_t nId);
		void runTrue(int16_t nId);
		bool isTrue(int16_t nId);
		void runReset();
		
		void runInit(IntArray * nIntArray, int16_t nBegin, int16_t nEnd, int16_t nC);
		void runInit(IntArray * nIntArray, int16_t nBegin, int16_t nEnd);
		
		
		BitCount();
		BitCount(IntArray * nIntArray, int16_t nBegin, int16_t nEnd);
		~BitCount();
		
	private:
		IntArray * mIntArray;
		int32_t * mValue;
		int16_t N;
	};
	
}
