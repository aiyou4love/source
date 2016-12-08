#pragma once

namespace cc {
	
	class UiAspect : public IAspect
	{
	public:
		void runReward(int32_t nDoingId, EntityPtr& nEntity, ValuePtr& nValue);
		
		template<class T>
		void headSerialize(T& nSerialize, const char * nName)
		{
			if ( 0 == strcmp(nName, rewardName()) ) {
				nSerialize.runMapStreamPtrs<int32_t, UiRewardPtr>(mUiRewards, "uiRewards", "uiReward");
			} else {
				LOGE("[%s]%s", __METHOD__, nName);
			}
		}
		const char * rewardName();
		const char * rewardUrl();
		
		void runPreinit();
		void runLoad();
		
		static UiAspect& instance();
		
		UiAspect();
		~UiAspect();
		
	private:
		map<int32_t, UiRewardPtr> mUiRewards;
		
		static UiAspect mUiAspect;
	};
	
}
