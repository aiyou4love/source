#include "../../Aspect.hpp"

namespace cc {
	
	const char * RoleAspect::conditionName()
	{
		return "roleCondition";
	}
	
	const char * RoleAspect::conditionUrl()
	{
		return "roleCondition.json";
	}
	
	const char * RoleAspect::rewardName()
	{
		return "roleReward";
	}
	
	const char * RoleAspect::rewardUrl()
	{
		return "roleReward.json";
	}
	
	void RoleAspect::runPreinit()
	{
		LifeCycle& lifeCycle_ = LifeCycle::instance();
		lifeCycle_.m_tLoadBegin.connect(bind(&RoleAspect::runLoad, this));
		lifeCycle_.m_tClearEnd.connect(bind(&RoleAspect::runClear, this));
		
		AspectEngine& aspectEngine_ = AspectEngine::instance();
		aspectEngine_.registerAspect(EaspectId::mRoleId, this);
	}
	
	void RoleAspect::runLoad()
	{
		TableEngine& tableEngine_ = TableEngine::instance();
		tableEngine_.runReader<RoleAspect>(this, conditionUrl(), conditionName());
		tableEngine_.runReader<RoleAspect>(this, rewardUrl(), rewardName());
	}
	
	void RoleAspect::runClear()
	{
		mRoleConditions.clear();
		mRoleRewards.clear();
	}
	
	RoleAspect::RoleAspect()
	{
		mRoleConditions.clear();
		mRoleRewards.clear();
	}
	
	RoleAspect::~RoleAspect()
	{
		mRoleConditions.clear();
		mRoleRewards.clear();
	}
	
}
