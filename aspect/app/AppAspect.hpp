#pragma once

namespace cc {
	
	class AppAspect : public IAspect
	{
	public:
		void runReward(int32_t nDoingId, EntityPtr& nEntity, ValuePtr& nValue);
		
	public:
		template<class T>
		void headSerialize(T& nSerialize, const char * nName)
		{
			if ( 0 == strcmp(rewardName(), nName) ) {
				nSerialize.template runMapStreamPtrs<int32_t, AppRewardPtr>(mAppRewards, "appRewards", "appReward");
			} else {
				LOGE("[%s]%s", __METHOD__, nName);
			}
		}
		const char * rewardName();
		const char * rewardUrl();
		
		void runPreinit();
		void runLoad();
		void runStart();
		void runClear();
		
		static AppAspect& instance();
		
		AppAspect();
		~AppAspect();
		
	private:
		map<int32_t, AppRewardPtr> mAppRewards;
		
		static AppAspect mAppAspect;
	};
	
}
