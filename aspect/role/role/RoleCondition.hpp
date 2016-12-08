#pragma once

namespace cc {
	
	class RoleCondition : noncopyable
	{
	public:
		template <class T>
		void serialize(T * nSerialize, const char * nName, int8_t nCount)
		{
			nSerialize->runNumber(mIndex, "conditionId");
			nSerialize->runNumber(mType, "conditionType");
			nSerialize->runNumber(mParam, "conditionParam");
		}
		int8_t getParam();
		int16_t getType();
		
		bool isDefault();
		int32_t getKey();
		
		RoleCondition();
		~RoleCondition();
		
	private:
		int32_t mIndex;
		int16_t mType;
		int8_t mParam;
	};
	typedef SPTR<RoleCondition> RoleConditionPtr;
	
}
