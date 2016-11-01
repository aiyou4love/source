#include "../../Engine.hpp"

namespace cc {
	
	void ConnectEngine::initConnect(int16_t nAppType, int32_t nAppNo)
	{
		NetIpMgr& netIpMgr_ = NetIpMgr::instance();
		NetIpPtr * netIp_ = netIpMgr_.findNetIp(nAppType, nAppNo);
		if (nullptr == netIp_) {
			LOGE("[%s]%d,%d", __METHOD__, nAppType, nAppNo);
			return;
		}
		this->initConnect(*netIp_);
	}
	
	void ConnectEngine::initConnect(int16_t nAppType)
	{
		NetIpMgr& netIpMgr_ = NetIpMgr::instance();
		NetIpPtr * netIp_ = netIpMgr_.findNetIp(nAppType);
		if (nullptr == netIp_) {
			LOGE("[%s]%d", __METHOD__, nAppType);
			return;
		}
		this->initConnect(*netIp_);
	}
	
	void ConnectEngine::initConnect(NetIpPtr& nNetIp)
	{
		const char * port_ = nNetIp->getPort();
		const char * ip_ = nNetIp->getIp();
		int16_t appType_ = nNetIp->getAppType();
		int64_t appId_ = nNetIp->getKey();
		
		auto it0 = mConnectInfos.find(appType_);
		if ( it0 == mConnectInfos.end() ) {
			LOGE("[%s]%s", __METHOD__, appType_);
			return;
		}
		ConnectInfoPtr& connectInfo_ = it0->second;
		
		LKGUD<mutex> lock_(mMutex);
		auto it1 = mConnectors.find(appId_);
		if (it1 != mConnectors.end()) {
			LOGE("[%s]%d", __METHOD__, appId_);
			return;
		}
		IoService& ioService_ = IoService::instance();
		asio::io_service& ioHandle_ = ioService_.getIoHandle();
		
		ConnectorPtr connector_(new Connector(appId_, ioHandle_));
		connector_->runConnect(ip_, port_, connectInfo_);
		mConnectors[appId_] = connector_;
	}
	
	void ConnectEngine::removeConnector(int64_t nAppId)
	{
		LKGUD<mutex> lock_(mMutex);
		auto it = mConnectors.find(nAppId);
		if ( it == mConnectors.end() ) {
			LOGE("[%s]%d", __METHOD__, nAppId);
			return;
		}
		mConnectors.erase(it);
	}
	
	const char * ConnectEngine::streamName()
	{
		return "connectEngine";
	}
	
	const char * ConnectEngine::streamUrl()
	{
		return "connectEngine.json";
	}
	
	void ConnectEngine::runPreinit()
	{
		LifeCycle& lifeCycle_ = LifeCycle::instance();
		lifeCycle_.m_tLoadBegin.connect(bind(&ConnectEngine::runLoad, this));
		lifeCycle_.m_tStopBegin.connect(bind(&ConnectEngine::runStop, this));
	}
	
	void ConnectEngine::runLoad()
	{
		TableEngine& tableEngine_ = TableEngine::instance();
		tableEngine_.runReader<ConnectEngine>(this, streamUrl(), streamName());
	}
	
	void ConnectEngine::runStop()
	{
		mConnectInfos.clear();
		
		LKGUD<mutex> lock_(mMutex);
		mConnectors.clear();
	}
	
	ConnectEngine& ConnectEngine::instance()
	{
		return mConnectEngine;
	}
	
	ConnectEngine::ConnectEngine()
	{
		mConnectInfos.clear();
		mConnectors.clear();
	}
	
	ConnectEngine::~ConnectEngine()
	{
		mConnectInfos.clear(); 
		mConnectors.clear();
	}
	
	ConnectEngine ConnectEngine::mConnectEngine;
	
}
