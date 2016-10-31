#pragma once

namespace cc {

	class LuaReward : noncopyable
	{
	public:
		template <class T>
		void serialize(T * nSerialize, const char * nName, int8_t nCount)
		{
			nSerialize->runNumber(mIndex, "rewardId");
			nSerialize->runNumber(mFunction, "function");
			nSerialize->runNumber(mScript, "script");
		}
		const char * getFunction();
		const char * getScript();
		
		bool isDefault();
		int32_t getKey();
		
		LuaReward();
		~LuaReward();
		
	private:
		int32_t mIndex;
		string mFunction;
		string mScript;
	};
	typedef SPTR<LuaReward> LuaRewardPtr;
	
}
