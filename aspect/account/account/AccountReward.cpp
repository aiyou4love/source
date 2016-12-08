#include "../../Aspect.hpp"

namespace cc {
	
	vector<int8_t>& AccountReward::getParams()
	{
		return mParams;
	}
	
	int16_t AccountReward::getType()
	{
		return mType;
	}
	
	bool AccountReward::isDefault()
	{
		return ( (0 == mIndex) || (0 == mType) );
	}
	
	int32_t AccountReward::getKey()
	{
		return mIndex;
	}
	
	AccountReward::AccountReward()
		: mIndex(0)
		, mType (0)
	{
		mParams.clear();
	}
	
	AccountReward::~AccountReward()
	{
		mParams.clear();
		mIndex = 0;
		mType = 0;
	}
	
}
