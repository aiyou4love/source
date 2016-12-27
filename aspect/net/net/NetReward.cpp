#include "../../Aspect.hpp"

namespace cc {
	
	vector<int8_t>& NetReward::getParams()
	{
		return mParams;
	}
	
	int16_t NetReward::getType()
	{
		return mType;
	}
	
	bool NetReward::isDefault()
	{
		return ( (0 == mIndex) || (0 == mType) );
	}
	
	int32_t NetReward::getKey()
	{
		return mIndex;
	}
	
	NetReward::NetReward()
		: mIndex(0)
		, mType (0)
	{
		mParams.clear();
	}
	
	NetReward::~NetReward()
	{
		mParams.clear();
		mIndex = 0;
		mType = 0;
	}
	
}
