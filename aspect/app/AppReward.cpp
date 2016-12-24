#include "../Aspect.hpp"

namespace cc {
	
	bool AppReward::isDefault()
	{
		return ( (0 == mIndex) || (0 == mType) );
	}
	
	int16_t AppReward::getType()
	{
		return mType;
	}
	
	int32_t AppReward::getKey()
	{
		return mIndex;
	}
	
	AppReward::AppReward()
		: mIndex(0)
		, mType (0)
	{
	}
	
	AppReward::~AppReward()
	{
		mIndex = 0;
		mType = 0;
	}
	
}
