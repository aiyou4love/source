#pragma once

namespace cc {
	
	class Int8Count : noncopyable
	{
	public:
		void setInt(int16_t nId, int8_t nValue);
		int8_t getInt(int16_t nId);
		void addInt(int16_t nId, int8_t nValue);
		void addInt(int16_t nId);
		void pushInt(int8_t nValue);
		void popInt(int8_t nValue);
		void runReset(int16_t nId);
		void runReset();
		
		void runInit(IntArrayPtr& nIntArray, int16_t nBegin, int16_t nEnd, int16_t nC);
		void runInit(IntArrayPtr& nIntArray, int16_t nBegin, int16_t nEnd);
		
		Int8Count();
		Int8Count(IntArrayPtr& nIntArray, int16_t nBegin, int16_t nEnd);
		~Int8Count();
		
	private:
		IntArrayPtr * mIntArray;
		int32_t * mValue;
		int16_t N;
	};
	
}
