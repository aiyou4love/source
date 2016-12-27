#pragma once

namespace cc {
	
	class NetAspect : public IAspect
	{
	public:
		template<class T>
		void headSerialize(T& nSerialize, const char * nName)
		{
			if ( 0 == strcmp(nName, rewardName()) ) {
				nSerialize.runMapStreamPtrs<int32_t, NetRewardPtr>(mNetRewards, "netRewards", "netReward");
			} else {
				LOGE("[%s]%s", __METHOD__, nName);
			}
		}
		const char * rewardName();
		const char * rewardUrl();
		
		void runPreinit();
		void runLoad();
		void runClear();
		
		NetAspect();
		virtual ~NetAspect();
		
	protected:
		map<int32_t, NetRewardPtr> mNetRewards;
	};
	
}
