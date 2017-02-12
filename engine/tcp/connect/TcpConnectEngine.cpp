#include "../../Engine.hpp"

namespace cc {
	
	void TcpConnectEngine::initConnect(int16_t nAppType, int32_t nAppNo)
	{
		NetIpMgr& netIpMgr_ = NetIpMgr::instance();
		NetIp * netIp_ = netIpMgr_.findNetIp(nAppType, nAppNo);
		if (nullptr == netIp_) {
			LOGE("[%s]%d,%d", __METHOD__, nAppType, nAppNo);
			return;
		}
		this->initConnect(netIp_, false);
	}
	
	void TcpConnectEngine::initConnect(int16_t nAppType)
	{
		NetIpMgr& netIpMgr_ = NetIpMgr::instance();
		NetIp * netIp_ = netIpMgr_.findNetIp(nAppType);
		if (nullptr == netIp_) {
			LOGE("[%s]%d", __METHOD__, nAppType);
			return;
		}
		this->initConnect(netIp_, false);
	}
	
	void TcpConnectEngine::initConnect(int64_t nAppId)
	{
		NetIpMgr& netIpMgr_ = NetIpMgr::instance();
		NetIp * netIp_ = netIpMgr_.findNetIp(nAppId);
		if (nullptr == netIp_) {
			LOGE("[%s]%d", __METHOD__, nAppId);
			return;
		}
		this->initConnect(netIp_, true);
	}
	
	void TcpConnectEngine::initConnect(NetIp * nNetIp, bool nReconnect)
	{
		const char * port_ = nNetIp->getPort();
		const char * ip_ = nNetIp->getIp();
		int16_t appType_ = nNetIp->getAppType();
		int64_t appId_ = nNetIp->getKey();
		
		auto it0 = mConnectInfos.find(appType_);
		if ( it0 == mConnectInfos.end() ) {
			LOGE("[%s]%d", __METHOD__, appType_);
			return;
		}
		TcpConnectInfoPtr& tcpConnectInfo_ = it0->second;
		if ( nReconnect && (!tcpConnectInfo_->isReconnect()) ) {
			return;
		}
		
		IoService& ioService_ = IoService::instance();
		LKGUD<mutex> lock_(mMutex);
		auto it1 = mConnectors.find(appId_);
		if ( it1 != mConnectors.end() ) {
			LOGE("[%s]%d", __METHOD__, appId_);
			return;
		}
		asio::io_service& ioHandle_ = ioService_.getIoHandle();
		
		TcpConnectorPtr tcpConnector_(new TcpConnector(appId_, ioHandle_));
		tcpConnector_->runConnect(ip_, port_, tcpConnectInfo_);
		mConnectors[appId_] = tcpConnector_;
	}
	
	void TcpConnectEngine::removeConnector(int64_t nAppId)
	{
		LKGUD<mutex> lock_(mMutex);
		auto it = mConnectors.find(nAppId);
		if ( it == mConnectors.end() ) {
			LOGE("[%s]%d", __METHOD__, nAppId);
			return;
		}
		mConnectors.erase(it);
	}
	
	const char * TcpConnectEngine::streamName()
	{
		return "tcpConnectEngine";
	}
	
	const char * TcpConnectEngine::streamUrl()
	{
		return "tcpConnectEngine.json";
	}
	
	void TcpConnectEngine::runPreinit()
	{
		LifeCycle& lifeCycle_ = LifeCycle::instance();
		lifeCycle_.m_tLoadBegin.connect(bind(&TcpConnectEngine::runLoad, this));
		lifeCycle_.m_tStopBegin.connect(bind(&TcpConnectEngine::runStop, this));
	}
	
	void TcpConnectEngine::runLoad()
	{
		TableEngine& tableEngine_ = TableEngine::instance();
		tableEngine_.runReader<TcpConnectEngine>(this, streamUrl(), streamName());
	}
	
	void TcpConnectEngine::runStop()
	{
		mConnectInfos.clear();
		
		LKGUD<mutex> lock_(mMutex);
		mConnectors.clear();
	}
	
	TcpConnectEngine& TcpConnectEngine::instance()
	{
		return mTcpConnectEngine;
	}
	
	TcpConnectEngine::TcpConnectEngine()
	{
		mConnectInfos.clear();
		mConnectors.clear();
	}
	
	TcpConnectEngine::~TcpConnectEngine()
	{
		mConnectInfos.clear();
		mConnectors.clear();
	}
	
	TcpConnectEngine TcpConnectEngine::mTcpConnectEngine;
	
}
