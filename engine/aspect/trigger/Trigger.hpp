#pragma once

namespace cc {
	
	class Trigger : noncopyable
	{
	public:
		int32_t getTriggerId();
		int16_t getTriggerType();
		int32_t getObjectId();
		int16_t getCount();
		
		Trigger();
		~Trigger();
		
	private:
		int32_t mTriggerId;
		int16_t mTriggerType;
		int32_t mObjectId;
		int16_t mCount;
	};
	typedef SPTR<Trigger> TriggerPtr;
	
}
