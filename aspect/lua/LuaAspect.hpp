#pragma once

namespace cc {
	
	class LuaAspect : public IAspect
	{
	public:
		bool runCondition(int32_t nDoingId, EntityPtr& nEntity, ValuePtr& nValue);
		void runReward(int32_t nDoingId, EntityPtr& nEntity, ValuePtr& nValue);
		
	public:
		template<class T>
		void headSerialize(T& nSerialize, const char * nName)
		{
			if ( 0 == strcmp(streamName(), nName) ) {
				nSerialize.runNumbers<list<string>, string>(mLuaScripts, "luaScripts", "luaScript");
			} else if ( 0 == strcmp(conditionName(), nName) ) {
				nSerialize.runMapStreamPtrs<int32_t, LuaConditionPtr>(mLuaConditions, "luaConditions", "luaCondition");
			} else if ( 0 == strcmp(rewardName(), nName) ) {
				nSerialize.runMapStreamPtrs<int32_t, LuaRewardPtr>(mLuaRewards, "luaRewards", "luaReward");
			} else {
				LOGE("[%s]%s", __METHOD__, nName);
			}
		}
		const char * conditionName();
		const char * conditionUrl();
		
		const char * rewardName();
		const char * rewardUrl();
		
		const char * streamName();
		const char * streamUrl();
		
		void runPreinit();
		void runLoad();
		void runStart();
		void runClear();
		
		static LuaAspect& instance();
		
		LuaAspect();
		~LuaAspect();
		
	private:
		map<int32_t, LuaConditionPtr> mLuaConditions;
		map<int32_t, LuaRewardPtr> mLuaRewards;
		
		list<string> mLuaScripts;
		
		map<string, LuaThreadPtr> mLuaThreads;
		
		static LuaAspect mLuaAspect;
	};
	
}
