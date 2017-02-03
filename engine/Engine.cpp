#include "Engine.hpp"

using namespace cc;

void engineInit()
{
	serializeInit();
	
	LOGI("[%s]2", __METHOD__);
	
	HandleEngine& handleEngine_ = HandleEngine::instance();
	handleEngine_.runPreinit();
	
	UpintEngine& upintEngine_ = UpintEngine::instance();
	upintEngine_.runPreinit();
	
	ValueMgr& valueMgr_ = ValueMgr::instance();
	valueMgr_.runPreinit();
	
	PacketMgr& packetMgr_ = PacketMgr::instance();
	packetMgr_.runPreinit();
	
	DispatchEngine& dispatchEngine_ = DispatchEngine::instance();
	dispatchEngine_.runPreinit();
	
	ConditionEngine& conditionEngine_ = ConditionEngine::instance();
	conditionEngine_.runPreinit();
	
	RewardEngine& rewardEngine_ = RewardEngine::instance();
	rewardEngine_.runPreinit();
	
	SelectEngine& selectEngine_ = SelectEngine::instance();
	selectEngine_.runPreinit();
	
	AspectEngine::instance();
	
	CurlEngine& curlEngine_ = CurlEngine::instance();
	curlEngine_.runPreinit();
	
	UrlMgr& urlMgr_ = UrlMgr::instance();
	urlMgr_.runPreinit();
	
	NetIpMgr& netIpMgr_ = NetIpMgr::instance();
	netIpMgr_.runPreinit();
	
	IoService& ioService_ = IoService::instance();
	ioService_.runPreinit();
	
#ifndef __CLIENT__
	AcceptorMgr& acceptorMgr_ = AcceptorMgr::instance();
	acceptorMgr_.runPreinit();
	
	SessionMgr& sessionMgr_ = SessionMgr::instance();
	sessionMgr_.runPreinit();
	
	AcceptEngine& acceptEngine_ = AcceptEngine::instance();
	acceptEngine_.runPreinit();
	
	AcceptRemove::instance();
#endif
	
	ConnectorMgr& connectorMgr_ = ConnectorMgr::instance();
	connectorMgr_.runPreinit();
	
	ConnectEngine& connectEngine_ = ConnectEngine::instance();
	connectEngine_.runPreinit();
	
	ConnectRemove::instance();
	
	TimeEngine& timeEngine_ = TimeEngine::instance();
	timeEngine_.runPreinit();
	
	LOGI("[%s]5", __METHOD__);
	
	cServerTime& serverTime_ = cServerTime::instance();
	serverTime_.runPreinit();
}
