#include "../../Aspect.hpp"

namespace cc {
	
	const char * NetAspect::rewardName()
	{
		return "netReward";
	}
	
	const char * NetAspect::rewardUrl()
	{
		return "netReward.json";
	}
	
	void NetAspect::runPreinit()
	{
		LifeCycle& lifeCycle_ = LifeCycle::instance();
		lifeCycle_.m_tLoadBegin.connect(bind(&NetAspect::runLoad, this));
		lifeCycle_.m_tClearEnd.connect(bind(&NetAspect::runClear, this));
		
		AspectEngine& aspectEngine_ = AspectEngine::instance();
		aspectEngine_.registerAspect(EaspectId::mNetId, this);
	}
	
	void NetAspect::runLoad()
	{
		TableEngine& tableEngine_ = TableEngine::instance();
		tableEngine_.runReader<NetAspect>(this, rewardUrl(), rewardName());
	}
	
	void NetAspect::runClear()
	{
		mNetRewards.clear();
	}
	
	NetAspect::NetAspect()
	{
		mNetRewards.clear();
	}
	
	NetAspect::~NetAspect()
	{
		mNetRewards.clear();
	}
	
}
