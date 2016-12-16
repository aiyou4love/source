#include "../Aspect.hpp"

namespace cc {
	
	IndexValue& UiReward::getIndexValue()
	{
		return mIndexValue;
	}
	
	UiName& UiReward::getUiName()
	{
		return mUiName;
	}
	
	int16_t UiReward::getType()
	{
		return mType;
	}
	
	bool UiReward::isDefault()
	{
		return ( (0 == mIndex) || (0 == mType) );
	}
	
	int32_t UiReward::getKey()
	{
		return mIndex;
	}
	
	UiReward::UiReward()
		: mIndex(0)
		, mType (0)
	{
	}
	
	UiReward::~UiReward()
	{
		mIndex = 0;
		mType = 0;
	}
	
}
