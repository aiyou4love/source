#include "../Aspect.hpp"

namespace cc {
	
	struct EappReward
	{
		static const int16_t mExistApp = 1;
		static const int16_t mCancelExist = 2;
	};
	
	void AppAspect::runReward(int32_t nDoingId, EntityPtr& nEntity, ValuePtr& nValue)
	{
		auto it = mAppRewards.find(nDoingId);
		if ( it == mAppRewards.end() ) {
			LOGE("[%s]doingId:%d", __METHOD__, nDoingId);
			return;
		}
		AppRewardPtr& appReward_ = it->second;
		int16_t type_ = appReward_->getType();
		if (EappReward::mExistApp == type_) {
			LifeCycle& lifeCycle_ = LifeCycle::instance();
			lifeCycle_.stopJoin();
		} else if (EappReward::mCancelExist == type_) {
			LifeCycle& lifeCycle_ = LifeCycle::instance();
			lifeCycle_.noticeStart();
		} else {
			LOGE("[%s]type:%d", __METHOD__, type_);
		}
	}
	
	const char * AppAspect::rewardName()
	{
		return "appReward";
	}
	
	const char * AppAspect::rewardUrl()
	{
		return "appReward.json";
	}
	
	void AppAspect::runPreinit()
	{
		LifeCycle& lifeCycle_ = LifeCycle::instance();
		lifeCycle_.m_tLoadBegin.connect(bind(&AppAspect::runLoad, this));
		lifeCycle_.m_tStopEnd.connect(bind(&AppAspect::runClear, this));
		
		AspectEngine& aspectEngine_ = AspectEngine::instance();
		aspectEngine_.registerAspect(EaspectId::mAppId, this);
	}
	
	void AppAspect::runLoad()
	{
		TableEngine& tableEngine_ = TableEngine::instance();
		tableEngine_.runReader<AppAspect>(this, rewardUrl(), rewardName());
	}
	
	void AppAspect::runClear()
	{
		mAppRewards.clear();
	}
	
	AppAspect& AppAspect::instance()
	{
		return mAppAspect;
	}
	
	AppAspect::AppAspect()
	{
	}
	
	AppAspect::~AppAspect()
	{
	}
	
	AppAspect AppAspect::mAppAspect;
	
}
