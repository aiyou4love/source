#pragma once

namespace cc {
	
	class RandomEngine : noncopyable
	{
	public:
		int32_t runRandom(int32_t nMin, int32_t nMax);
		int32_t runRandom(int32_t nMax);
		int32_t runRandom();
		
		void runPreinit();
		
		static RandomEngine& instance();
		
		RandomEngine();
		~RandomEngine();
		
	private:
		random_device mDevice;
		mt19937 mEngine;
	};
	
}
