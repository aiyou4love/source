#include "../../Engine.hpp"

namespace cc {
	
	bool IAspect::runCondition(int32_t nDoingId, EntityPtr& nEntity, ValuePtr& nValue)
	{
		return false;
	}
	
	void IAspect::runReward(int32_t nDoingId, EntityPtr& nEntity, ValuePtr& nValue)
	{
	}
	
	void IAspect::runEvent(int32_t nEventId, EntityPtr& nEntity, ValuePtr& nValue)
	{
	}
	
}
