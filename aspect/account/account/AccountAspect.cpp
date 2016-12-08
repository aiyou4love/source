#include "../../Aspect.hpp"

namespace cc {
	
	const char * AccountAspect::conditionName()
	{
		return "accountCondition";
	}
	
	const char * AccountAspect::conditionUrl()
	{
		return "accountCondition.json";
	}
	
	const char * AccountAspect::rewardName()
	{
		return "accountReward";
	}
	
	const char * AccountAspect::rewardUrl()
	{
		return "accountReward.json";
	}
	
	void AccountAspect::runPreinit()
	{
		LifeCycle& lifeCycle_ = LifeCycle::instance();
		lifeCycle_.m_tLoadBegin.connect(bind(&AccountAspect::runLoad, this));
		lifeCycle_.m_tClearEnd.connect(bind(&AccountAspect::runClear, this));
		
		AspectEngine& aspectEngine_ = AspectEngine::instance();
		aspectEngine_.registerAspect(EaspectId::mAccountId, this);
	}
	
	void AccountAspect::runLoad()
	{
		TableEngine& tableEngine_ = TableEngine::instance();
		tableEngine_.runReader<AccountAspect>(this, conditionUrl(), conditionName());
		tableEngine_.runReader<AccountAspect>(this, rewardUrl(), rewardName());
	}
	
	void AccountAspect::runClear()
	{
		mAccountConditions.clear();
		mAccountRewards.clear();
	}
	
	AccountAspect::AccountAspect()
	{
		mAccountConditions.clear();
		mAccountRewards.clear();
	}
	
	AccountAspect::~AccountAspect()
	{
		mAccountConditions.clear();
		mAccountRewards.clear();
	}
	
}
