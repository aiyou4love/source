#include "../../Aspect.hpp"

namespace cc {
	
#ifdef __SOCIAL__
	struct EnetReward
	{
		static const int16_t mRunAccept = 1;
	};
	
	void cNetAspect::runReward(int32_t nDoingId, EntityPtr& nEntity, ValuePtr& nValue)
	{
		auto it = mNetRewards.find(nDoingId);
		if ( it == mNetRewards.end() ) {
			LOGE("[%s]doingId:%d", __METHOD__, nDoingId);
			return;
		}
		NetRewardPtr& netReward_ = it->second;
		vector<int8_t>& params_ = netReward_->getParams();
		int16_t type_ = netReward_->getType();
		
		if (EnetReward::mRunAccept == type_) {
			AcceptEngine& acceptEngine_ = AcceptEngine::instance();
			acceptEngine_.initAccept();
		} else {
			LOGE("[%s]type:%d", __METHOD__, type_);
		}
	}
	
	cNetAspect& cNetAspect::instance()
	{
		return mNetAspect;
	}
	
	cNetAspect::cNetAspect()
	{
	}
	
	cNetAspect::~cNetAspect()
	{
	}
	cNetAspect cNetAspect::mNetAspect;
#endif
	
}
