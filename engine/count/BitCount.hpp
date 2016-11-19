#pragma once

namespace cc {
	
	class BitCount : public ICount
	{
	public:
		void runReset(int16_t nId);
		
		void runTrue(int16_t nId);
		bool isTrue(int16_t nId);
		
		BitCount();
		~BitCount();
	};
	
}
