#include "../../Aspect.hpp"

namespace cc {
	
	vector<int8_t>& ServerReward::getParams()
	{
		return mParams;
	}
	
	int16_t ServerReward::getType()
	{
		return mType;
	}
	
	bool ServerReward::isDefault()
	{
		return ( (0 == mIndex) || (0 == mType) );
	}
	
	int32_t ServerReward::getKey()
	{
		return mIndex;
	}
	
	ServerReward::ServerReward()
		: mIndex(0)
		, mType (0)
	{
		mParams.clear();
	}
	
	ServerReward::~ServerReward()
	{
		mParams.clear();
		mIndex = 0;
		mType = 0;
	}
	
}
