#pragma once

namespace cc {
	
	class Int4Count : public ICount
	{
	public:
		void setInt(int16_t nId, int8_t nValue);
		int8_t getInt(int16_t nId);
		
		void addInt(int16_t nId, int8_t nValue);
		void addInt(int16_t nId);
		
		void pushInt(int8_t nValue);
		void popInt(int8_t nValue);
		
		void runReset(int16_t nId);
		
		Int4Count();
		~Int4Count();
	};
	
}
