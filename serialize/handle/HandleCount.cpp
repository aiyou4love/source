#include "../Serialize.hpp"

namespace cc {
	
	int32_t HandleCount::getTicks()
	{
		return mTicks;
	}
	
	bool HandleCount::isDefault()
	{
		return ( 0 == mIndex );
	}
	
	int16_t HandleCount::getKey()
	{
		return mIndex;
	}
	
	HandleCount::HandleCount()
		: mIndex (0)
		, mTicks (0)
	{
	}
	
	HandleCount::~HandleCount()
	{
		mIndex = 0;
		mTicks = 0;
	}
	
}
