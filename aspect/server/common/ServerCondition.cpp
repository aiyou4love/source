#include "../../Aspect.hpp"

namespace cc {
	
	int8_t ServerCondition::getParam()
	{
		return mParam;
	}
	
	int16_t ServerCondition::getType()
	{
		return mType;
	}
	
	bool ServerCondition::isDefault()
	{
		return ( (0 == mIndex) || (0 == mType) );
	}
	
	int32_t ServerCondition::getKey()
	{
		return mIndex;
	}
	
	ServerCondition::ServerCondition()
		: mParam (0)
		, mIndex(0)
		, mType (0)
	{
	}
	
	ServerCondition::~ServerCondition()
	{
		mParam = 0;
		mIndex = 0;
		mType = 0;
	}
	
}
