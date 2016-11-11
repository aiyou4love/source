#pragma once

namespace cc {
	
	class Trigger : noncopyable
	{
	public:
		int32_t getTriggerId();
		int8_t getTriggerType();
		int32_t getObjectId();
		int32_t getSelectId();
		int32_t getActionId();
		int32_t getDeleteId();
		
		Trigger();
		~Trigger();
		
	private:
		int32_t mTriggerId;
		int8_t mTriggerType;
		int32_t mObjectId;
		int32_t mSelectId;
		int32_t mActionId;
		int32_t mDeleteId;
	};
	typedef SPTR<Trigger> TriggerPtr;
	
}
