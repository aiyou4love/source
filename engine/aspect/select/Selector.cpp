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
		
		SelectEngine& selectEngine_ = SelectEngine::instance();
		
		list<TriggerPtr>& triggers_ = nEntity->getTriggers();
		auto it = triggers_.begin();
		for ( ; it != triggers_.end(); ++it ) {
			TriggerPtr& trigger_ = (*it);
			int8_t triggerType_ = trigger_->getTriggerType();
			if ( EtriggerType::mAspect != triggerType_ ) {
				continue;
			}
			int32_t triggerId_ = trigger_->getTriggerId();
			if ( mRewardId != triggerId_ ) {
				continue;
			}
			int32_t actionId_ = trigger_->getActionId();
			selectEngine_.runIfSelectId(nEntity, actionId_, nValue);
			int32_t deleteId_ = trigger_->getDeleteId();
			selectEngine_.runIfSelectId(nEntity, deleteId_, nValue);
		}
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
