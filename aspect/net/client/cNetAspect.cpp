#include "../../Aspect.hpp"

namespace cc {
	
#ifdef __CLIENT__
	struct EnetReward
	{
		static const int16_t mIdleAgent = 1;
		static const int16_t mConnectAgent = 2;
		static const int16_t mSendAgent = 3;
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
		
		if (EnetReward::mIdleAgent == type_) {
			int32_t serverId_ = nValue->getInt32(params_[0]);
			int8_t errorCode_ = getIdleAgent(serverId_);
			nValue->pushInt8(errorCode_);
		} else if (EnetReward::mConnectAgent == type_) {
			ConnectEngine& connectEngine_ = ConnectEngine::instance();
			connectEngine_.initConnect(EappType::mAgentServer);
		} else if (EnetReward::mSendAgent == type_) {
			ConnectorMgr& connectorMgr_ = ConnectorMgr::instance();
			connectorMgr_.sendValue(EappType::mAgentServer, nValue);
		} else {
			LOGE("[%s]type:%d", __METHOD__, type_);
		}
	}
	
	const char * mAgentUrl = "idleAgent";
	int8_t cNetAspect::getIdleAgent(int32_t nServerId)
	{
		WorkDirectory& workDirectory_ = WorkDirectory::instance();
		UrlMgr& urlMgr_ = UrlMgr::instance();
		
		const char * operatorName_ = workDirectory_.getOperatorName();
		int16_t versionNo_ = workDirectory_.getVersionNo();
		
		cAgentResult agentResult_;
		if ( !urlMgr_.runStream(&agentResult_, mAgentUrl, agentResult_.streamName(),
			operatorName_, versionNo_, nServerId) ) {
			LOGE("[%s]%s", __METHOD__, mAgentUrl);
			return 0;
		}
		ServerInfoPtr& serverInfo_ = agentResult_.getServerInfo();
		const char * agentPort_ = agentResult_.getAgentPort();
		const char * agentIp_ = agentResult_.getAgentIp();
		int32_t errorCode_ = agentResult_.getErrorCode();
		if (1 != errorCode_) {
			LOGE("[%s]errorCode:%d", __METHOD__, errorCode_);
			return ((int8_t)errorCode_);
		}
		ServerEngine& serverEngine_ = ServerEngine::instance();
		serverEngine_.pushServerInfo(serverInfo_);
		serverEngine_.runSave();
		
		NetIpPtr netIp_(new NetIp());
		netIp_->setPort(agentPort_);
		netIp_->setIp(agentIp_);
		netIp_->setAppType(EappType::mAgentServer);
		netIp_->setAppNo(0);
		NetIpMgr& netIpMgr_ = NetIpMgr::instance();
		netIpMgr_.pushNetIp(netIp_);
		netIpMgr_.runSave();
		return 1;
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
