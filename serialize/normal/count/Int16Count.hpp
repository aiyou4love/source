#pragma once

namespace cc {
	
	class Int16Count : noncopyable
	{
	public:
		void setInt(int16_t nId, int16_t nValue);
		int16_t getInt(int16_t nId);
		void addInt(int16_t nId, int16_t nValue);
		void addInt(int16_t nId);
		void pushInt(int16_t nValue);
		void popInt(int16_t nValue);
		void runReset(int16_t nId);
		void runReset();
		
		void runInit(IntArrayPtr& nIntArray, int16_t nBegin, int16_t nEnd, int16_t nC);
		void runInit(IntArrayPtr& nIntArray, int16_t nBegin, int16_t nEnd);
		
		Int16Count();
		Int16Count(IntArrayPtr& nIntArray, int16_t nBegin, int16_t nEnd);
		~Int16Count();
		
	private:
		IntArrayPtr * mIntArray;
		int32_t * mValue;
		int16_t N;
	};
	
}
