#pragma once

namespace cc {
	
	class Selector : noncopyable
	{
	public:
		bool runSelect(EntityPtr& nEntity, ValuePtr& nValue);
		
		template<class T>
		void serialize(T * nSerialize, const char * nName, int8_t nCount)
		{
			nSerialize->runNumberCount(mConditionId, "conditionId", nCount);
			nSerialize->runNumberCount(mRewardId, "rewardId", nCount);
			nSerialize->runNumberCount(mSelectId, "selectId", nCount);
		}
		
		bool isDefault();
		int8_t getKey();
		
		Selector();
		~Selector();
		
	private:
		int32_t mConditionId;
		int32_t mRewardId;
		int8_t mSelectId;
	};
	typedef SPTR<Selector> SelectorPtr;
	
}
