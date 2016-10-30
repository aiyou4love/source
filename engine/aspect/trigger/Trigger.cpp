#include "../../Engine.hpp"

namespace cc {
	
	int32_t Trigger::getTriggerId()
	{
		return mTriggerId;
	}
	
	int16_t Trigger::getTriggerType()
	{
		return mTriggerType;
	}
	
	int32_t Trigger::getObjectId()
	{
		return mObjectId;
	}
	
	int16_t Trigger::getCount()
	{
		return mCount;
	}
	
	Trigger::Trigger()
		: mTriggerId (0)
		, mTriggerType (0)
		, mObjectId (0)
		, mCount (0)
	{
	}
	
	Trigger::~Trigger()
	{
		mTriggerId = 0;
		mTriggerType = 0;
		mObjectId = 0;
		mCount = 0;
	}
	
}
