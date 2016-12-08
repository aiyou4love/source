#pragma once

namespace cc {
	
	class RoleAspect : public IAspect
	{
	public:
		template<class T>
		void headSerialize(T& nSerialize, const char * nName)
		{
			if ( 0 == strcmp(nName, conditionName()) ) {
				nSerialize.runMapStreamPtrs<int32_t, RoleConditionPtr>(mRoleConditions, "roleConditions", "roleCondition");
			} else if ( 0 == strcmp(nName, rewardName()) ) {
				nSerialize.runMapStreamPtrs<int32_t, RoleRewardPtr>(mRoleRewards, "roleRewards", "roleReward");
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
		
		RoleAspect();
		virtual ~RoleAspect();
		
	protected:
		map<int32_t, RoleConditionPtr> mRoleConditions;
		map<int32_t, RoleRewardPtr> mRoleRewards;
	};
	
}
