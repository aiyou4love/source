#include "../Aspect.hpp"

namespace cc {
	
	struct EuiReward
	{
		static const int16_t mLoadUi = 1;
		static const int16_t mShowUi = 2;
		static const int16_t mRefreshUi = 3;
		static const int16_t mCloseUi = 4;
		static const int16_t mClearUi = 5;
	};
	
	void UiAspect::runReward(int32_t nDoingId, EntityPtr& nEntity, ValuePtr& nValue)
	{
		auto it = mUiRewards.find(nDoingId);
		if (it == mUiRewards.end()) {
			LOGE("[%s]doingId:%d", __METHOD__, nDoingId);
			return;
		}
		UiRewardPtr& uiReward_ = it->second;
		
		UiManager& uiManager_ = UiManager::instance();
		
		IndexValue& indexValue_ = uiReward_->getIndexValue();
		const char * name_ = uiReward_->getName();
		int8_t uiType_ = uiReward_->getUiType();
		int16_t type_ = uiReward_->getType();
		
		if (EuiReward::mLoadUi == type_) {
			uiManager_.loadUi(name_, uiType_);
		} else if (EuiReward::mShowUi == type_) {
			uiManager_.showUi(name_, uiType_);
		} else if (EuiReward::mRefreshUi == type_) {
			uiManager_.refreshUi(name_, indexValue_, nValue, uiType_);
		} else if (EuiReward::mCloseUi == type_) {
			uiManager_.closeUi(name_, uiType_);
		} else if (EuiReward::mClearUi == type_) {
			uiManager_.runClose(uiType_);
		} else {
			LOGE("[%s]type:%d", __METHOD__, type_);
		}
	}
	
	const char * UiAspect::rewardName()
	{
		return "uiReward";
	}
	
	const char * UiAspect::rewardUrl()
	{
		return "uiReward.json";
	}
	
	void UiAspect::runPreinit()
	{
		LifeCycle& lifeCycle_ = LifeCycle::instance();
		lifeCycle_.m_tLoadBegin.connect(bind(&UiAspect::runLoad, this));
		
		AspectEngine& aspectEngine_ = AspectEngine::instance();
		aspectEngine_.registerAspect(EaspectId::mUiId, this);
	}
	
	void UiAspect::runLoad()
	{
		TableEngine& tableEngine_ = TableEngine::instance();
		tableEngine_.runReader<UiAspect>(this, rewardUrl(), rewardName());
	}
	
	UiAspect& UiAspect::instance()
	{
		return mUiAspect;
	}
	
	UiAspect::UiAspect()
	{
		mUiRewards.clear();
	}
	
	UiAspect::~UiAspect()
	{
		mUiRewards.clear();
	}
	
	UiAspect UiAspect::mUiAspect;
	
}
