#include "../../Engine.hpp"

namespace cc {
	
	void TcpConnectorMgr::sendValue(int16_t nAppType, int32_t nAppNo, ValuePtr& nValue)
	{
		int64_t appId_ = linkInt32(nAppType, nAppNo);
		if ( !this->sendValue(appId_, nValue) ) {
			TcpConnectEngine& tcpConnectEngine_ = TcpConnectEngine::instance();
			tcpConnectEngine_.initConnect(nAppType, nAppNo);
			this->sendValue(appId_, nValue);
		}
	}
	
	void TcpConnectorMgr::sendValue(int16_t nAppType, ValuePtr& nValue)
	{
		int64_t appId_ = linkInt32(nAppType, 0);
		if ( !this->sendValue(appId_, nValue) ) {
			TcpConnectEngine& tcpConnectEngine_ = TcpConnectEngine::instance();
			tcpConnectEngine_.initConnect(nAppType);
			this->sendValue(appId_, nValue);
		}
	}
	
	bool TcpConnectorMgr::sendValue(int64_t nAppId, ValuePtr& nValue)
	{
		LKGUD<mutex> lock_(mMutex);
		auto it = mSessions.find(nAppId);
		if ( it == mSessions.end() ) {
			LOGE("[%s]%d", __METHOD__, nAppId);
			return false;
		}
		TcpSessionPtr& tcpSession_ = mSessions[nAppId];
		tcpSession_->pushValue(nValue);
		return true;
	}
	
	TcpSession * TcpConnectorMgr::createSession(int64_t nAppId)
	{
		IoService& ioService_ = IoService::instance();
		
		LKGUD<mutex> lock_(mMutex);
		auto it = mSessions.find(nAppId);
		if ( it == mSessions.end() ) {
			asio::io_service& ioHandle_ = ioService_.getIoHandle();
			TcpSessionPtr tcpSession0_(new TcpSession(++mSessionId, ioHandle_));
			tcpSession0_->setAppId(nAppId);
			mSessions[nAppId] = tcpSession0_;
		}
		TcpSessionPtr& tcpSession1_ = mSessions[nAppId];
		return ( tcpSession1_.get() );
	}
	
	void TcpConnectorMgr::removeSession(int64_t nAppId)
	{
		LKGUD<mutex> lock_(mMutex);
		auto it = mSessions.find(nAppId);
		if ( it == mSessions.end() ) {
			LOGE("[%s]%d", __METHOD__, nAppId);
			return;
		}
		mSessions.erase(it);
	}
	
	void TcpConnectorMgr::runPreinit()
	{
		LifeCycle& lifeCycle_ = LifeCycle::instance();
		lifeCycle_.m_tStopBegin.connect(bind(&TcpConnectorMgr::runStop, this));
	}
	
	void TcpConnectorMgr::runStop()
	{
		LKGUD<mutex> lock_(mMutex);
		mSessions.clear();
		mSessionId = 0;
	}
	
	TcpConnectorMgr& TcpConnectorMgr::instance()
	{
		return mTcpConnectorMgr;
	}
	
	TcpConnectorMgr::TcpConnectorMgr()
		: mSessionId (0)
	{
		mSessions.clear();
	}
	
	TcpConnectorMgr::~TcpConnectorMgr()
	{
		mSessions.clear();
		mSessionId = 0;
	}
	
	TcpConnectorMgr TcpConnectorMgr::mTcpConnectorMgr;
	
}
