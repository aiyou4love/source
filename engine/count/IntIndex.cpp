#include "../Engine.hpp"

namespace cc {
	
	int16_t IntIndex::getN()
	{
		return N;
	}
	
	bool IntIndex::isDefault()
	{
		return ( (0 == mId) || (0 == N) );
	}
	
	int16_t IntIndex::getKey()
	{
		return mId;
	}
	
	IntIndex::IntIndex()
		: mId (0)
		, N (0)
	{
	}
	
	IntIndex::~IntIndex()
	{
		mId = 0;
		N = 0;
	}
	
}
