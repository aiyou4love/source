#include "../../Engine.hpp"

namespace cc {
	
#ifndef __CLIENT__
	void TcpSessionMgr::addSession(int16_t nAppType, int32_t nAppNo, TcpSession * nTcpSession)
	{
		int64_t appId_ = linkInt32(nAppType, nAppNo);
		LKGUD<mutex> lock_(mMutex);
		auto it = mSessions.find(appId_);
		if (it != mSessions.end()) {
			LOGE("[%s]%d,%d", __METHOD__, nAppType, nAppNo);
			return;
		}
		nTcpSession->setAppId(appId_);
		mSessions[appId_] = nTcpSession;
	}
	
	void TcpSessionMgr::removeSession(int64_t nAppId)
	{
		LKGUD<mutex> lock_(mMutex);
		auto it = mSessions.find(nAppId);
		if (it == mSessions.end()) {
			LOGE("[%s]%d", __METHOD__, nAppId);
			return;
		}
		mSessions.erase(it);
	}
	
	void TcpSessionMgr::sendValue(int16_t nAppType, int32_t nAppNo, ValuePtr& nValue)
	{
		int64_t appId_ = linkInt32(nAppType, nAppNo);
		LKGUD<mutex> lock_(mMutex);
		auto it = mSessions.find(appId_);
		if (it == mSessions.end()) {
			LOGE("[%s]%d,%d", __METHOD__, nAppType, nAppNo);
			return;
		}
		TcpSession * tcpSession_ = it->second;
		tcpSession_->runSend(nValue);
	}
	
	void TcpSessionMgr::runPreinit()
	{
		LifeCycle& lifeCycle_ = LifeCycle::instance();
		lifeCycle_.m_tStopBegin.connect(bind(&TcpSessionMgr::runStop, this));
	}
	
	void TcpSessionMgr::runStop()
	{
		mSessions.clear();
	}
	
	TcpSessionMgr& TcpSessionMgr::instance()
	{
		return mSessionMgr;
	}
	
	TcpSessionMgr::TcpSessionMgr()
	{
		mSessions.clear();
	}
	
	TcpSessionMgr::~TcpSessionMgr()
	{
		mSessions.clear();
	}
	
	TcpSessionMgr TcpSessionMgr::mTcpSessionMgr;
#endif
	
}
