#include "../../Aspect.hpp"

namespace cc {
	
	int8_t RoleCondition::getParam()
	{
		return mParam;
	}
	
	int16_t RoleCondition::getType()
	{
		return mType;
	}
	
	bool RoleCondition::isDefault()
	{
		return ( (0 == mIndex) || (0 == mType) );
	}
	
	int32_t RoleCondition::getKey()
	{
		return mIndex;
	}
	
	RoleCondition::RoleCondition()
		: mParam (0)
		, mIndex(0)
		, mType (0)
	{
	}
	
	RoleCondition::~RoleCondition()
	{
		mParam = 0;
		mIndex = 0;
		mType = 0;
	}
	
}
