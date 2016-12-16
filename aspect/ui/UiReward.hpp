#pragma once

namespace cc {
	
	class UiReward : noncopyable
	{
	public:
		template <class T>
		void serialize(T * nSerialize, const char * nName, int8_t nCount)
		{
			nSerialize->runStream(mIndexValue, "indexValue");
			nSerialize->runStream(mUiName, "uiName");
			
			nSerialize->runNumber(mType, "rewardType");
			nSerialize->runNumber(mIndex, "rewardId");
		}
		
		IndexValue& getIndexValue();
		UiName& getUiName();
		
		int16_t getType();
		
		bool isDefault();
		int32_t getKey();
		
		UiReward();
		~UiReward();
		
	private:
		IndexValue mIndexValue;
		UiName mUiName;
		
		int32_t mIndex;
		int16_t mType;
	};
	typedef SPTR<UiReward> UiRewardPtr;
	
}
