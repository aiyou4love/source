#include "../../Aspect.hpp"

namespace cc {
	
	const char * ServerAspect::conditionName()
	{
		return "serverCondition";
	}
	
	const char * ServerAspect::conditionUrl()
	{
		return "serverCondition.json";
	}
	
	const char * ServerAspect::rewardName()
	{
		return "serverReward";
	}
	
	const char * ServerAspect::rewardUrl()
	{
		return "serverReward.json";
	}
	
	void ServerAspect::runPreinit()
	{
		LifeCycle& lifeCycle_ = LifeCycle::instance();
		lifeCycle_.m_tLoadBegin.connect(bind(&ServerAspect::runLoad, this));
		lifeCycle_.m_tClearEnd.connect(bind(&ServerAspect::runClear, this));
		
		AspectEngine& aspectEngine_ = AspectEngine::instance();
		aspectEngine_.registerAspect(EaspectId::mServerId, this);
	}
	
	void ServerAspect::runLoad()
	{
		TableEngine& tableEngine_ = TableEngine::instance();
		tableEngine_.runReader<ServerAspect>(this, conditionUrl(), conditionName());
		tableEngine_.runReader<ServerAspect>(this, rewardUrl(), rewardName());
	}
	
	void ServerAspect::runClear()
	{
		mServerConditions.clear();
		mServerRewards.clear();
	}
	
	ServerAspect::ServerAspect()
	{
		mServerConditions.clear();
		mServerRewards.clear();
	}
	
	ServerAspect::~ServerAspect()
	{
		mServerConditions.clear();
		mServerRewards.clear();
	}
	
}
