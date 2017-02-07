#pragma once

namespace cc {
	
	class IntCount : public ICount
	{
	public:
		void setInt(int16_t nId, int32_t nValue);
		int32_t getInt(int16_t nId);
		
		void addInt(int16_t nId, int32_t nValue, bool nCycle);
		void addInt(int16_t nId, bool nCycle);
		
		void pushInt(int32_t nValue);
		void popInt(int32_t nValue);
		
		void runReset(int16_t nId);
		
		void runInit(IntArray * nIntArray, CountIndexPtr& nCountIndex);
		
		IntCount();
		~IntCount();
		
	private:
		int32_t M;
		int16_t C;
		int16_t I;
	};
	
}
