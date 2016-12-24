#include "Engine.hpp"

using namespace cc;

void engineInit()
{
	serializeInit();
	
	LOGI("[%s]2", __METHOD__);
	
	HandleEngine& handleEngine_ = HandleEngine::instance();
	handleEngine_.runPreinit();
	
	LOGI("[%s]3", __METHOD__);
	
	UpintEngine& upintEngine_ = UpintEngine::instance();
	upintEngine_.runPreinit();
	
	LOGI("[%s]4", __METHOD__);
	
	ValueMgr& valueMgr_ = ValueMgr::instance();
	valueMgr_.runPreinit();
	
	LOGI("[%s]5", __METHOD__);
	
	PacketMgr& packetMgr_ = PacketMgr::instance();
	packetMgr_.runPreinit();
	
	LOGI("[%s]6", __METHOD__);
	
	DispatchEngine& dispatchEngine_ = DispatchEngine::instance();
	dispatchEngine_.runPreinit();
	
	LOGI("[%s]7", __METHOD__);
	
	ConditionEngine& conditionEngine_ = ConditionEngine::instance();
	conditionEngine_.runPreinit();
	
	LOGI("[%s]8", __METHOD__);
	
	RewardEngine& rewardEngine_ = RewardEngine::instance();
	rewardEngine_.runPreinit();
	
	LOGI("[%s]9", __METHOD__);
	
	SelectEngine& selectEngine_ = SelectEngine::instance();
	selectEngine_.runPreinit();
	
	LOGI("[%s]10", __METHOD__);
	
	AspectEngine::instance();
	
	CurlEngine& curlEngine_ = CurlEngine::instance();
	curlEngine_.runPreinit();
	
	UrlMgr& urlMgr_ = UrlMgr::instance();
	urlMgr_.runPreinit();
	
	NetIpMgr::instance();
	
	LOGI("[%s]11", __METHOD__);
	
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
	
	LOGI("[%s]12", __METHOD__);
	
	ConnectorMgr& connectorMgr_ = ConnectorMgr::instance();
	connectorMgr_.runPreinit();
	
	ConnectEngine& connectEngine_ = ConnectEngine::instance();
	connectEngine_.runPreinit();
	
	ConnectRemove::instance();
	
	LOGI("[%s]13", __METHOD__);
}
