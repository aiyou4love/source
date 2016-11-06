#include "../../Engine.hpp"

namespace cc {
	
	int8_t Trigger::getTriggerType()
	{
		return mTriggerType;
	}
	
	int32_t Trigger::getObjectId()
	{
		return mObjectId;
	}
	
	int32_t Trigger::getTriggerId()
	{
		return mTriggerId;
	}
	
	int32_t Trigger::getActionId()
	{
		return mActionId;
	}
	
	int32_t Trigger::getDeleteId()
	{
		return mDeleteId;
	}
	
	Trigger::Trigger()
		: mTriggerType (0)
		, mObjectId (0)
		, mTriggerId (0)
		, mActionId (0)
		, mDeleteId (0)
	{
	}
	
	Trigger::~Trigger()
	{
		mTriggerType = 0;
		mObjectId = 0;
		mTriggerId = 0;
		mActionId = 0;
		mDeleteId = 0;
	}
	
}
