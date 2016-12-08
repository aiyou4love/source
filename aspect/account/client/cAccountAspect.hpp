#pragma once

namespace cc {
	
#ifdef __CLIENT__
	class cAccountAspect : public AccountAspect
	{
	public:
		bool runCondition(int32_t nDoingId, EntityPtr& nEntity, ValuePtr& nValue);
		void runReward(int32_t nDoingId, EntityPtr& nEntity, ValuePtr& nValue);
		
		bool runLoginCondition(AccountConditionPtr& nAccountCondition, EntityPtr& nEntity, ValuePtr& nValue);
		bool runEnterCondition(AccountConditionPtr& nAccountCondition, EntityPtr& nEntity, ValuePtr& nValue);
		
		void runRegisterReward(AccountRewardPtr& nAccountReward, EntityPtr& nEntity, ValuePtr& nValue);
		void runLoginReward(AccountRewardPtr& nAccountReward, EntityPtr& nEntity, ValuePtr& nValue);
		void runEnterReward(AccountRewardPtr& nAccountReward, EntityPtr& nEntity, ValuePtr& nValue);
		void runCreateReward(AccountRewardPtr& nAccountReward, EntityPtr& nEntity, ValuePtr& nValue);
		
		static cAccountAspect& instance();
		
		cAccountAspect();
		~cAccountAspect();
		
	private:
		static cAccountAspect mAccountAspect;
	};
#endif
	
}
