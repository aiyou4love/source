#include "../../Aspect.hpp"

namespace cc {
	
	int8_t AccountCondition::getParam()
	{
		return mParam;
	}
	
	int16_t AccountCondition::getType()
	{
		return mType;
	}
	
	bool AccountCondition::isDefault()
	{
		return ((0 == mIndex) || (0 == mType));
	}
	
	int32_t AccountCondition::getKey()
	{
		return mIndex;
	}
	
	AccountCondition::AccountCondition()
		: mParam (0)
		, mIndex(0)
		, mType (0)
	{
	}
	
	AccountCondition::~AccountCondition()
	{
		mParam = 0;
		mIndex = 0;
		mType = 0;
	}
	
}
