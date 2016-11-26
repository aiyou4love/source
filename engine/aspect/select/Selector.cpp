#include "../../Engine.hpp"

namespace cc {
	
	bool Selector::runSelect(EntityPtr& nEntity, ValuePtr& nValue)
	{
		if (mConditionId > 0) {
			ConditionEngine& conditionEngine_ = ConditionEngine::instance();
			if ( !conditionEngine_.runCondition(mConditionId, nEntity, nValue) ) {
				return false;
			}
		}
		RewardEngine& rewardEngine_ = RewardEngine::instance();
		rewardEngine_.runReward(mRewardId, nEntity, nValue);
		return true;
	}
	
	bool Selector::isDefault()
	{
		return ( (0 == mSelectId) || (0 == mRewardId) );
	}
	
	int8_t Selector::getKey()
	{
		return mSelectId;
	}
	
	Selector::Selector()
		: mConditionId (0)
		, mRewardId (0)
		, mSelectId (0)
	{
	}
	
	Selector::~Selector()
	{
		mConditionId = 0;
		mRewardId = 0;
		mSelectId = 0;
	}
	
}
