#include "../../Engine.hpp"

namespace cc {
	
	bool Condition::runCondition(EntityPtr& nEntity, ValuePtr& nValue)
	{
		AspectEngine& aspectEngine_ = AspectEngine::instance();
		
		auto it = mDoings.begin();
		for ( ; it != mDoings.end(); ++it ) {
			DoingPtr& doing_ = it->second;
			if ( !aspectEngine_.runCondition(nEntity, doing_, nValue) ) {
				return false;
			}
		}
		return true;
	}
	
	bool Condition::isDefault()
	{
		return ( (0 == mConditionId) || (mDoings.size() <= 0) );
	}
	
	int32_t Condition::getKey()
	{
		return mConditionId;
	}
	
	Condition::Condition()
		: mConditionId (0)
	{
		mDoings.clear();
	}
	
	Condition::~Condition()
	{
		mConditionId = 0;
		
		mDoings.clear();
	}
	
}
