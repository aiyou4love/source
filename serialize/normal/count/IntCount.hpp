#pragma once

namespace cc {
	
	class IntCount : noncopyable
	{
	public:
		void setInt(int16_t nId, int32_t nValue);
		int32_t getInt(int16_t nId);
		void addInt(int16_t nId, int32_t nValue, bool nCycle);
		void addInt(int16_t nId, bool nCycle);
		void pushInt(int32_t nValue);
		void popInt(int32_t nValue);
		void runReset(int16_t nId);
		void runReset();
		
		void runInit(IntArrayPtr& nIntArray,
			int16_t nBegin, int16_t nEnd, int16_t nC);
		
		IntCount();
		IntCount(IntArrayPtr& nIntArray, 
			int16_t nBegin, int16_t nEnd, int16_t nC);
		~IntCount();
		
	private:
		IntArrayPtr * mIntArray;
		int32_t * mValue;
		int16_t N;
		int32_t M;
		int16_t C;
		int16_t I;
	};
	
}
