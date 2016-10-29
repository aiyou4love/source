#pragma once

namespace cc {
	
	class IntCount : noncopyable
	{
	public:
		void setInt(int16_t nId, int16_t nValue);
		int16_t getInt(int16_t nId);
		void addInt(int16_t nId, int16_t nValue, bool nCycle);
		void addInt(int16_t nId, bool nCycle);
		void pushInt(int16_t nValue);
		void popInt(int16_t nValue);
		void runReset(int16_t nId);
		void runReset();
		
		void runInit(IntArray * nIntArray,
			int16_t nBegin, int16_t nEnd, int16_t nC);
		
		IntCount();
		IntCount(IntArray * nIntArray, 
			int16_t nBegin, int16_t nEnd, int16_t nC);
		~IntCount();
		
	private:
		IntArray * mIntArray;
		int32_t * mValue;
		int16_t N;
		int16_t M;
		int16_t C;
		int16_t I;
	};
	
}
