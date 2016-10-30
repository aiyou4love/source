#pragma once

namespace cc {
	
	class Condition : noncopyable
	{
	public:
		bool runCondition(EntityPtr& nEntity, ValuePtr& nValue);
		
		template<class T>
		void serialize(T * nSerialize, const char * nName, int8_t nCount)
		{
			nSerialize->template runMapStreamPtrsCount<int8_t, DoingPtr>(mDoings, "doings", "doing", 10);
			
			nSerialize->runNumber(mConditionId, "conditionId");
		}
		bool isDefault();
		int32_t getKey();
		
		Condition();
		~Condition();
		
	private:
		map<int8_t, DoingPtr> mDoings;
		int32_t mConditionId;
	};
	typedef SPTR<Condition> ConditionPtr;
	
}
