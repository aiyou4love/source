#pragma once

namespace cc {
	
	class ServerCondition : noncopyable
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
		
		ServerCondition();
		~ServerCondition();
		
	private:
		int32_t mIndex;
		int16_t mType;
		int8_t mParam;
	};
	typedef SPTR<ServerCondition> ServerConditionPtr;
	
}
