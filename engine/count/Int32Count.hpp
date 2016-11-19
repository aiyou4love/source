#pragma once

namespace cc {
	
	class Int32Count : public ICount
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
		
		Int32Count();
		~Int32Count();
	};
	
}
