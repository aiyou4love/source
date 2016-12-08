#include "../../Aspect.hpp"

namespace cc {
	
	vector<int8_t>& RoleReward::getParams()
	{
		return mParams;
	}
	
	int16_t RoleReward::getType()
	{
		return mType;
	}
	
	bool RoleReward::isDefault()
	{
		return ( (0 == mIndex) || (0 == mType) );
	}
	
	int32_t RoleReward::getKey()
	{
		return mIndex;
	}
	
	RoleReward::RoleReward()
		: mIndex(0)
		, mType (0)
	{
		mParams.clear();
	}
	
	RoleReward::~RoleReward()
	{
		mParams.clear();
		mIndex = 0;
		mType = 0;
	}
	
}
