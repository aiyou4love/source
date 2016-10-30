#include "../../Engine.hpp"

namespace cc {
	
	void RewardEngine::runReward(int32_t nRewardId, EntityPtr& nEntity, ValuePtr& nValue)
	{
		auto it = mRewards.find(nRewardId);
		if ( it == mRewards.end() ) {
			LOGE("[%s]%d", __METHOD__, nRewardId);
			return;
		}
		RewardPtr& reward_ = it->second;
		reward_->runReward(nEntity, nValue);
	}
	
	void RewardEngine::runPreinit()
	{
		LifeCycle& lifeCycle_ = LifeCycle::instance();
		lifeCycle_.m_tRunLuaApi.connect(bind(&RewardEngine::runLuaApi, this));
		lifeCycle_.m_tLoadBegin.connect(bind(&RewardEngine::runLoad, this));
		lifeCycle_.m_tClearEnd.connect(bind(&RewardEngine::runClear, this));
	}
	
	void RewardEngine::runLuaApi()
	{
		LuaEngine& luaEngine_ = LuaEngine::instance();
		luaEngine_.runClass<RewardEngine>("RewardEngine");
		luaEngine_.runStatic<RewardEngine>(RewardEngine::instance, "instance");
		luaEngine_.runMethod<RewardEngine>(&RewardEngine::runReward, "runReward");
	}
	
	void RewardEngine::runLoad()
	{
		TableEngine& tableEngine_ = TableEngine::instance();
		tableEngine_.runReader<RewardEngine>(this, streamUrl(), streamName());
	}
	
	void RewardEngine::runClear()
	{
		mRewards.clear();
	}
	
	const char * RewardEngine::streamName()
	{
		return "rewardEngine";
	}
	
	const char * RewardEngine::streamUrl()
	{
		return "rewardEngine.json";
	}
	
	RewardEngine& RewardEngine::instance()
	{
		return mRewardEngine;
	}
	
	RewardEngine::RewardEngine()
	{
		mRewards.clear();
	}
	
	RewardEngine::~RewardEngine()
	{
		mRewards.clear();
	}
	
	RewardEngine RewardEngine::mRewardEngine;
	
}
