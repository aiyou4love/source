#pragma once

namespace cc {
	
	class Int32Count : noncopyable
	{
	public:
		void setInt(int16_t nId, int32_t nValue);
		int32_t getInt(int16_t nId);
		void addInt(int16_t nId, int32_t nValue);
		void addInt(int16_t nId);
		void pushInt(int32_t nValue);
		void popInt16(int16_t nValue);
		void popInt(int32_t nValue);
		void runReset(int16_t nId);
		void runReset();
		
		void runInit(IntArrayPtr& nIntArray, int16_t nBegin, int16_t nEnd, int16_t nC);
		void runInit(IntArrayPtr& nIntArray, int16_t nBegin, int16_t nEnd);
		
		Int32Count();
		Int32Count(IntArrayPtr& nIntArray, int16_t nBegin, int16_t nEnd);
		~Int32Count();
		
	private:
		IntArrayPtr * mIntArray;
		int32_t * mValue;
		int16_t N;
	};
	
}
