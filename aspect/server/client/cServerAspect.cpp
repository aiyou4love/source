#include "../../Aspect.hpp"

namespace cc {
	
#ifdef __CLIENT__
	struct EserverReward
	{
		static const int16_t mGetInfo = 1;
		static const int16_t mGetName = 2;
	};
	
	void cServerAspect::runReward(int32_t nDoingId, EntityPtr& nEntity, ValuePtr& nValue)
	{
		auto it = mServerRewards.find(nDoingId);
		if ( it == mServerRewards.end() ) {
			LOGE("[%s]doingId:%d", __METHOD__, nDoingId);
			return;
		}
		ServerRewardPtr& serverReward_ = it->second;
		vector<int8_t>& params_ = serverReward_->getParams();
		int16_t type_ = serverReward_->getType();
		if (EserverReward::mGetInfo == type_) {
			ServerEngine& serverEngine_ = ServerEngine::instance();
			string serverInfos_ = serverEngine_.getServerInfos();
			nValue->pushString(serverInfos_.c_str());
		} else if (EserverReward::mGetName == type_) {
			ServerEngine& serverEngine_ = ServerEngine::instance();
			int32_t serverId_ = nValue->getInt32(params_[0]);
			string serverName_ = serverEngine_.getServerName(serverId_);
			nValue->pushString(serverName_.c_str());
		} else {
			LOGE("[%s]type:%d", __METHOD__, type_);
		}
	}
	
	cServerAspect& cServerAspect::instance()
	{
		return mServerAspect;
	}
	
	cServerAspect::cServerAspect()
	{
	}
	
	cServerAspect::~cServerAspect()
	{
	}
	cServerAspect cServerAspect::mServerAspect;
#endif
	
}
