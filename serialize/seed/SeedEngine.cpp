#include "../Serialize.hpp"

namespace cc {
	
	int32_t assignment(int32_t nSeed, int16_t nValue)
	{
		return nSeed;
	}
	
	int32_t assignment1(int32_t nSeed, int16_t nValue)
	{
		return ( int32_t(nValue) );
	}
	
	int32_t addition(int32_t nSeed, int16_t nValue)
	{
		return ( int32_t(nSeed * nValue) );
	}
	
	int32_t addition1(int32_t nSeed, int16_t nValue)
	{
		return ( int32_t(nSeed + 1) );
	}
	
	int32_t addition2(int32_t nSeed, int16_t nValue)
	{
		return ( int32_t(nValue + 1) );
	}
	
	int32_t subtraction(int32_t nSeed, int16_t nValue)
	{
		return ( int32_t(nSeed - nValue) );
	}
	
	int32_t subtraction1(int32_t nSeed, int16_t nValue)
	{
		return ( int32_t(nSeed - 1) );
	}
	
	int32_t subtraction2(int32_t nSeed, int16_t nValue)
	{
		return ( int32_t(nValue - 1) );
	}
	
	int32_t multiplication(int32_t nSeed, int16_t nValue)
	{
		return ( int32_t(nSeed * nValue) );
	}
	
	int32_t division(int32_t nSeed, int16_t nValue)
	{
		return ( int32_t(nSeed / nValue) );
	}
	
	int32_t modulo(int32_t nSeed, int16_t nValue)
	{
		return ( int32_t(nSeed % nValue) );
	}
	
	int32_t andLogic(int32_t nSeed, int16_t nValue)
	{
		return ( int32_t(nSeed & nValue) );
	}
	
	int32_t orLogic(int32_t nSeed, int16_t nValue)
	{
		return ( int32_t(nSeed | nValue) );
	}
	
	int32_t nonLogic(int32_t nSeed, int16_t nValue)
	{
		return ( !nSeed );
	}
	
	int32_t nonLogic1(int32_t nSeed, int16_t nValue)
	{
		return ( int32_t(!nValue) );
	}
	
	int32_t greater(int32_t nSeed, int16_t nValue)
	{
		return ( int32_t(nSeed > nValue ? nSeed : nValue) );
	}
	
	int32_t small(int32_t nSeed, int16_t nValue)
	{
		return ( int32_t(nSeed < nValue ? nSeed : nValue) );
	}
	
	int32_t abs1(int32_t nSeed, int16_t nValue)
	{
		return ( int32_t(abs(nSeed)) );
	}
	
	int32_t abs2(int32_t nSeed, int16_t nValue)
	{
		return ( int32_t(abs(nValue)) );
	}
	
	int32_t sqrt1(int32_t nSeed, int16_t nValue)
	{
		return ( int32_t(sqrt(nSeed)) );
	}
	
	int32_t sqrt2(int32_t nSeed, int16_t nValue)
	{
		return ( int32_t(sqrt(nValue)) );
	}
	
	int32_t fun1(int32_t nSeed, int16_t nValue)
	{
		return ( int32_t(sqrt(nValue) + nSeed) );
	}
	
	int32_t fun2(int32_t nSeed, int16_t nValue)
	{
		return ( int32_t(sqrt(nSeed) + nValue) );
	}
	
	int32_t fun3(int32_t nSeed, int16_t nValue)
	{
		return ( int32_t(nSeed * nValue + nValue) );
	}
	
	int32_t fun4(int32_t nSeed, int16_t nValue)
	{
		return ( int32_t(nSeed / nValue + nValue) );
	}
	
	int32_t fun5(int32_t nSeed, int16_t nValue)
	{
		return ( int32_t(sqrt(nSeed + nValue)) );
	}
	
	int32_t fun6(int32_t nSeed, int16_t nValue)
	{
		return ( int32_t(sqrt(nSeed - nValue)) );
	}
	
	int32_t fun7(int32_t nSeed, int16_t nValue)
	{
		return ( int32_t(sqrt(nSeed * nValue)) );
	}
	
	int32_t fun8(int32_t nSeed, int16_t nValue)
	{
		return ( int32_t(sqrt(nSeed / nValue)) );
	}
	
	int32_t fun9(int32_t nSeed, int16_t nValue)
	{
		return ( int32_t(sqrt(nSeed % nValue)) );
	}
	
	int32_t SeedEngine::runSeed(int32_t nSeed, int16_t nValue, int16_t nType)
	{
		return ( (*(mSeeds[nType - 1]))(nSeed, nValue) );
	}
	
	int16_t SeedEngine::getType(int16_t nType)
	{
		int16_t result_ = nType + 1;
		if ( result_ > mSeeds.size() ) {
			result_ = 1;
		}
		return result_;
	}
	
	int16_t SeedEngine::getSize()
	{
		return ( int16_t(mSeeds.size()) );
	}
	
	void SeedEngine::runPreinit()
	{
		mSeeds.push_back(&assignment);
		mSeeds.push_back(&assignment1);
		mSeeds.push_back(&addition);
		mSeeds.push_back(&addition1);
		mSeeds.push_back(&addition2);
		mSeeds.push_back(&subtraction);
		mSeeds.push_back(&subtraction1);
		mSeeds.push_back(&subtraction2);
		mSeeds.push_back(&multiplication);
		mSeeds.push_back(&division);
		mSeeds.push_back(&modulo);
		mSeeds.push_back(&andLogic);
		mSeeds.push_back(&orLogic);
		mSeeds.push_back(&nonLogic);
		mSeeds.push_back(&nonLogic1);
		mSeeds.push_back(&greater);
		mSeeds.push_back(&small);
		mSeeds.push_back(&abs1);
		mSeeds.push_back(&abs2);
		mSeeds.push_back(&sqrt1);
		mSeeds.push_back(&sqrt2);
		mSeeds.push_back(&fun1);
		mSeeds.push_back(&fun2);
		mSeeds.push_back(&fun3);
		mSeeds.push_back(&fun4);
		mSeeds.push_back(&fun5);
		mSeeds.push_back(&fun6);
		mSeeds.push_back(&fun7);
		mSeeds.push_back(&fun8);
		mSeeds.push_back(&fun9);
	}
	
	SeedEngine& SeedEngine::instance()
	{
		return mSeedEngine;
	}
	
	SeedEngine::SeedEngine()
	{
		mSeeds.clear();
	}
	
	SeedEngine::~SeedEngine()
	{
		mSeeds.clear();
	}
	
	SeedEngine SeedEngine::mSeedEngine;
	
}
