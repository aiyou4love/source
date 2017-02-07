#include "../Aspect.hpp"

namespace cc {
	
	bool LuaAspect::runCondition(int32_t nDoingId, EntityPtr& nEntity, ValuePtr& nValue)
	{
		auto it = mLuaConditions.find(nDoingId);
		if ( it == mLuaConditions.end() ) {
			LOGE("[%s]doingId:%d", __METHOD__, nDoingId);
			return false;
		}
		LuaConditionPtr& luaCondition_ = it->second;
		const char * function_ = luaCondition_->getFunction();
		const char * script_ = luaCondition_->getScript();
		
		auto it1 = mLuaThreads.find(script_);
		if (it1 == mLuaThreads.end()) {
			LOGE("[%s]script:%s", __METHOD__, script_);
			return false;
		}
		LuaThreadPtr& luaThread_ = it1->second;
		return luaThread_->runCall<bool>(function_, nEntity, nValue);
	}
	
	void LuaAspect::runReward(int32_t nDoingId, EntityPtr& nEntity, ValuePtr& nValue)
	{
		auto it = mLuaRewards.find(nDoingId);
		if (it == mLuaRewards.end()) {
			LOGE("[%s]doingId:%d", __METHOD__, nDoingId);
			return;
		}
		LuaRewardPtr& luaReward_ = it->second;
		const char * function_ = luaReward_->getFunction();
		const char * script_ = luaReward_->getScript();
		
		auto it1 = mLuaThreads.find(script_);
		if (it1 == mLuaThreads.end()) {
			LOGE("[%s]script:%s", __METHOD__, script_);
			return;
		}
		LuaThreadPtr& luaThread_ = it1->second;
		luaThread_->runCall<void>(function_, nEntity, nValue);
	}
	
	const char * LuaAspect::conditionName()
	{
		return "luaCondition";
	}
	
	const char * LuaAspect::conditionUrl()
	{
		return "luaCondition.json";
	}
	
	const char * LuaAspect::rewardName()
	{
		return "luaReward";
	}
	
	const char * LuaAspect::rewardUrl()
	{
		return "luaReward.json";
	}
	
	const char * LuaAspect::streamName()
	{
		return "luaAspect";
	}
	
	const char * LuaAspect::streamUrl()
	{
		return "luaAspect.json";
	}
	
	void LuaAspect::runPreinit()
	{
		LifeCycle& lifeCycle_ = LifeCycle::instance();
		lifeCycle_.m_tLoadBegin.connect(bind(&LuaAspect::runLoad, this));
		lifeCycle_.m_tStarting.connect(bind(&LuaAspect::runStart, this));
		lifeCycle_.m_tStopEnd.connect(bind(&LuaAspect::runClear, this));
		
		AspectEngine& aspectEngine_ = AspectEngine::instance();
		aspectEngine_.registerAspect(EaspectId::mLuaId, this);
	}
	
	void LuaAspect::runLoad()
	{
		TableEngine& tableEngine_ = TableEngine::instance();
		tableEngine_.runReader<LuaAspect>(this, streamUrl(), streamName());
		tableEngine_.runReader<LuaAspect>(this, conditionUrl(), conditionName());
		tableEngine_.runReader<LuaAspect>(this, rewardUrl(), rewardName());
	}
	
	void LuaAspect::runStart()
	{
		WorkDirectory& workDirectory_ = WorkDirectory::instance();
		LuaEngine& luaEngine_ = LuaEngine::instance();
		
		auto it = mLuaScripts.begin();
		for ( ; it != mLuaScripts.end(); ++it ) {
			string& value_ = (*it);
			LuaThreadPtr luaThread_ = luaEngine_.createLuaThread(value_.c_str());
			string luaPath_ = workDirectory_.luaPath(value_.c_str());
			luaThread_->openFile(luaPath_.c_str());
			mLuaThreads[value_] = luaThread_;
		}
	}
	
	void LuaAspect::runClear()
	{
		mLuaConditions.clear();
		mLuaRewards.clear();
		mLuaScripts.clear();
		
		mLuaThreads.clear();
	}
	
	LuaAspect& LuaAspect::instance()
	{
		return mLuaAspect;
	}
	
	LuaAspect::LuaAspect()
	{
	}
	
	LuaAspect::~LuaAspect()
	{
	}
	
	LuaAspect LuaAspect::mLuaAspect;
	
}
