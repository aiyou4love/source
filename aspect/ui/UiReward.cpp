#include "../Aspect.hpp"

namespace cc {
	
	IndexValue& UiReward::getIndexValue()
	{
		return mIndexValue;
	}
	
	const char * UiReward::getName()
	{
		return mName.c_str();
	}
	
	int16_t UiReward::getUiType()
	{
		return mUiType;
	}
	
	int16_t UiReward::getType()
	{
		return mType;
	}
	
	bool UiReward::isDefault()
	{
		return ((0 == mIndex) || (0 == mUiType)
			|| (0 == mType) || ("" == mName));
	}
	
	int32_t UiReward::getKey()
	{
		return mIndex;
	}
	
	UiReward::UiReward()
		: mIndex(0)
		, mType (0)
		, mUiType (0)
		, mName ("")
	{
	}
	
	UiReward::~UiReward()
	{
		mName = "";
		mIndex = 0;
		mType = 0;
		mUiType = 0;
	}
	
}
