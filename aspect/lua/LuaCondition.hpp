#pragma once

namespace cc {

	class LuaCondition : noncopyable
	{
	public:
		template <class T>
		void serialize(T * nSerialize, const char * nName, int8_t nCount)
		{
			nSerialize->runNumber(mIndex, "conditionId");
			nSerialize->runNumber(mFunction, "function");
			nSerialize->runNumber(mScript, "script");
		}
		const char * getFunction();
		const char * getScript();
		
		bool isDefault();
		int32_t getKey();
		
		LuaCondition();
		~LuaCondition();
		
	private:
		int32_t mIndex;
		
		string mFunction;
		string mScript;
	};
	typedef SPTR<LuaCondition> LuaConditionPtr;
	
}
