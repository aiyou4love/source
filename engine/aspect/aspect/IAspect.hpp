#pragma once

namespace cc {
	
	class IAspect : public IEngine
	{
	public:
		virtual bool runCondition(int32_t nDoingId, EntityPtr& nEntity, ValuePtr& nValue);
		virtual void runReward(int32_t nDoingId, EntityPtr& nEntity, ValuePtr& nValue);
		virtual void runEvent(int32_t nEventId, EntityPtr& nEntity, ValuePtr& nValue);
	};
	
}
