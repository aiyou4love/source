#pragma once

namespace cc {
	
	class AppReward : noncopyable
	{
	public:
		template <class T>
		void serialize(T * nSerialize, const char * nName, int8_t nCount)
		{
			nSerialize->runNumber(mType, "rewardType");
			nSerialize->runNumber(mIndex, "rewardId");
		}
		
		bool isDefault();
		int16_t getType();
		int32_t getKey();
		
		AppReward();
		~AppReward();
		
	private:
		int32_t mIndex;
		int16_t mType;
	};
	typedef SPTR<AppReward> AppRewardPtr;
	
}
