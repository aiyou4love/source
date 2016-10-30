#pragma once

namespace cc {
	
	class Reward : noncopyable
	{
	public:
		void runReward(EntityPtr& nEntity, ValuePtr& nValue);
		
		template<class T>
		void serialize(T * nSerialize, const char * nName, int8_t nCount)
		{
			nSerialize->template runMapStreamPtrsCount<int8_t, DoingPtr>(mDoings, "doings", "doing", 10);
			
			nSerialize->runNumber(mRewardId, "rewardId");
		}
		bool isDefault();
		int32_t getKey();
		
		Reward();
		~Reward();
		
	private:
		map<int8_t, DoingPtr> mDoings;
		int32_t mRewardId;
	};
	typedef SPTR<Reward> RewardPtr;
	
}
