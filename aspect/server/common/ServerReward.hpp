#pragma once

namespace cc {
	
	class ServerReward : noncopyable
	{
	public:
		template <class T>
		void serialize(T * nSerialize, const char * nName, int8_t nCount)
		{
			nSerialize->runNumbersCount<vector<int8_t>, int8_t>(mParams, "rewardParam", 8);
			
			nSerialize->runNumber(mType, "rewardType");
			nSerialize->runNumber(mIndex, "rewardId");
		}
		vector<int8_t>& getParams();
		
		bool isDefault();
		int16_t getType();
		int32_t getKey();
		
		ServerReward();
		~ServerReward();
		
	private:
		vector<int8_t> mParams;
		
		int32_t mIndex;
		int16_t mType;
	};
	typedef SPTR<ServerReward> ServerRewardPtr;
	
}
