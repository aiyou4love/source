#pragma once

namespace cc {
	
	typedef int32_t (*Seed_t)(int32_t, int16_t);
	class SeedEngine : noncopyable
	{
	public:
		int32_t runSeed(int32_t nSeed, int16_t nValue, int16_t nType);
		int16_t getType(int16_t nType);
		int16_t getSize();
		
		void runPreinit();
		
		static SeedEngine& instance();
		
		SeedEngine();
		~SeedEngine();
		
	private:
		static SeedEngine mSeedEngine;
		
		vector<Seed_t> mSeeds;
	};
	
}
