#pragma once

namespace cc {
	
	class UiReward : noncopyable
	{
	public:
		template <class T>
		void serialize(T * nSerialize, const char * nName, int8_t nCount)
		{
			nSerialize->runStream(mIndexValue, "indexValue");
			
			nSerialize->runNumber(mName, "rewardName");
			nSerialize->runNumber(mType, "rewardType");
			nSerialize->runNumber(mUiType, "uiType");
			nSerialize->runNumber(mIndex, "rewardId");
		}
		
		IndexValue& getIndexValue();
		
		const char * getName();
		
		bool isDefault();
		int8_t getUiType();
		int16_t getType();
		int32_t getKey();
		
		UiReward();
		~UiReward();
		
	private:
		IndexValue mIndexValue;
		
		int32_t mIndex;
		int16_t mUiType;
		int16_t mType;
		string mName;
	};
	typedef SPTR<UiReward> UiRewardPtr;
	
}
