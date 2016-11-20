#pragma once

namespace cc {
	
	class Int16Count : public ICount
	{
	public:
		void setInt(int16_t nId, int16_t nValue);
		int16_t getInt(int16_t nId);
		
		bool checkValue(int16_t nValue);
		
		void addInt(int16_t nId, int16_t nValue);
		void addInt(int16_t nId);
		
		void pushInt(int16_t nValue);
		void popInt(int16_t nValue);
		
		void runReset(int16_t nId);
		
		Int16Count();
		~Int16Count();
	};
	
}
