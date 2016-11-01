#include "../../Engine.hpp"

namespace cc {
	
	void ConnectorMgr::sendValue(int16_t nAppType, int32_t nAppNo, ValuePtr& nValue)
	{
		int64_t appId_ = linkInt32(nAppType, nAppNo);
		if ( !this->sendValue(appId_, nValue) ) {
			ConnectEngine& connectEngine_ = ConnectEngine::instance();
			connectEngine_initConnect(nAppType, nAppNo);
			this->sendValue(appId_, nValue);
		}
	}
	
	void ConnectorMgr::sendValue(int16_t nAppType, ValuePtr& nValue)
	{
		int64_t appId_ = linkInt32(nAppType, 0);
		if ( !this->sendValue(appId_, nValue) ) {
			ConnectEngine& connectEngine_ = ConnectEngine::instance();
			connectEngine_initConnect(nAppType);
			this->sendValue(appId_, nValue);
		}
	}
	
	bool ConnectorMgr::sendValue(int64_t nAppId, ValuePtr& nValue)
	{
		LKGUD<mutex> lock_(mMutex);
		auto it = mSessions.find(nAppId);
		if ( it == mSessions.end() ) {
			LOGE("[%s]%d", __METHOD__, nAppId);
			return false;
		}
		SessionPtr& session_ = mSessions[nAppId];
		session_->pushValue(nValue);
		return true;
	}
	
	SessionPtr& ConnectorMgr::createSession(int64_t nAppId)
	{
		LKGUD<mutex> lock_(mMutex);
		auto it = mSessions.find(nAppId);
		if ( it != mSessions.end() ) {
			return mSessions[nAppId];
		}
		IoService& ioService_ = IoService::instance();
		asio::io_service& ioHandle_ = ioService_.getIoHandle();
		SessionPtr session_(new Session(++mSessionId, ioHandle_));
		mSessions[nAppId] = session_;
		return mSessions[nAppId];
	}
	
	void ConnectorMgr::removeSession(int64_t nAppId)
	{
		LKGUD<mutex> lock_(mMutex);
		auto it = mSessions.find(nAppId);
		if ( it == mSessions.end() ) {
			LOGE("[%s]%d", __METHOD__, nAppId);
			return;
		}
		mSessions.erase(it);
	}
	
	void ConnectorMgr::runPreinit()
	{
		LifeCycle& lifeCycle_ = LifeCycle::instance();
		lifeCycle_.m_tStopBegin.connect(bind(&ConnectorMgr::runStop, this));
	}
	
	void ConnectorMgr::runStop()
	{
		LKGUD<mutex> lock_(mMutex);
		mSessions.clear();
		mSessionId = 0;
	}
	
	ConnectorMgr& ConnectorMgr::instance()
	{
		return mConnectorMgr;
	}
	
	ConnectorMgr::ConnectorMgr()
		: mSessionId (0)
	{
		mSessions.clear();
	}
	
	ConnectorMgr::~ConnectorMgr()
	{
		mSessions.clear();
		mSessionId = 0;
	}
	
	ConnectorMgr ConnectorMgr::mConnectorMgr;
	
}
