#pragma once

namespace cc {
	
	class ServerAspect : public IAspect
	{
	public:
		template<class T>
		void headSerialize(T& nSerialize, const char * nName)
		{
			if ( 0 == strcmp(nName, conditionName()) ) {
				nSerialize.runMapStreamPtrs<int32_t, ServerConditionPtr>(mServerConditions, "serverConditions", "serverCondition");
			} else if ( 0 == strcmp(nName, rewardName()) ) {
				nSerialize.runMapStreamPtrs<int32_t, ServerRewardPtr>(mServerRewards, "serverRewards", "serverReward");
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
		
		ServerAspect();
		virtual ~ServerAspect();
		
	protected:
		map<int32_t, ServerConditionPtr> mServerConditions;
		map<int32_t, ServerRewardPtr> mServerRewards;
	};
	
}
