#include "../Aspect.hpp"

namespace cc {
	
	struct EuiReward
	{
		static const int16_t mTopScene = 1;
		static const int16_t mClearScene = 2;
		static const int16_t mRefreshScene = 3;
		static const int16_t mDrawScene = 4;
		static const int16_t mBackScene = 5;
		static const int16_t mLoadUi = 6;
		static const int16_t mNoticeUi = 7;
		static const int16_t mCloseUi = 8;
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
		UiName& uiName_ = uiReward_->getUiName();
		int16_t type_ = uiReward_->getType();
		
		if (EuiReward::mTopScene == type_) {
			uiManager_.topScene(uiName_);
		} else if (EuiReward::mClearScene == type_) {
			uiManager_.clearScene(uiName_);
		} else if (EuiReward::mRefreshScene == type_) {
			uiManager_.refreshScene(uiName_);
		} else if (EuiReward::mDrawScene == type_) {
			uiManager_.drawScene(uiName_);
		} else if (EuiReward::mBackScene == type_) {
			uiManager_.backScene(uiName_);
		} else if (EuiReward::mLoadUi == type_) {
			uiManager_.loadUi(uiName_);
		} else if (EuiReward::mNoticeUi == type_) {
			OrderValue orderValue_(indexValue_, nValue);
			uiManager_.noticeUi(uiName_, orderValue_);
		} else if (EuiReward::mCloseUi == type_) {
			uiManager_.closeUi(uiName_);
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
