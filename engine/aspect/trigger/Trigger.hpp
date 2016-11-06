#pragma once

namespace cc {
	
	class Trigger : noncopyable
	{
	public:
		int8_t getTriggerType();
		int32_t getObjectId();
		int32_t getTriggerId();
		int32_t getActionId();
		int32_t getDeleteId();
		
		Trigger();
		~Trigger();
		
	private:
		int8_t mTriggerType;
		int32_t mObjectId;
		int32_t mTriggerId;
		int32_t mActionId;
		int32_t mDeleteId;
	};
	typedef SPTR<Trigger> TriggerPtr;
	
}
