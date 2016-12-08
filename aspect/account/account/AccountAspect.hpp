#pragma once

namespace cc {
	
	class AccountAspect : public IAspect
	{
	public:		
		template<class T>
		void headSerialize(T& nSerialize, const char * nName)
		{
			if ( 0 == strcmp(nName, conditionName()) ) {
				nSerialize.runMapStreamPtrs<int32_t, AccountConditionPtr>(mAccountConditions, "accountConditions", "accountCondition");
			} else if ( 0 == strcmp(nName, rewardName()) ) {
				nSerialize.runMapStreamPtrs<int32_t, AccountRewardPtr>(mAccountRewards, "accountRewards", "accountReward");
			} else {
				LOGE("[%s]%s", __METHOD__, nName);
			}
		}
		const char * conditionName();
		const char * conditionUrl();
		
		const char * rewardName();
		const char * rewardUrl();
		
		void runPreinit();
		void runLoad();
		void runClear();
		
		AccountAspect();
		virtual ~AccountAspect();
		
	protected:
		map<int32_t, AccountConditionPtr> mAccountConditions;
		map<int32_t, AccountRewardPtr> mAccountRewards;
	};
	
}
