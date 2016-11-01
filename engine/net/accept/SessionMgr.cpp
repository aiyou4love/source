#include "../../Engine.hpp"

namespace cc {
	
	void SessionMgr::sendValue(int16_t nAppType, int32_t nAppNo, ValuePtr& nValue)
	{
		int64_t appId_ = linkInt32(nAppType, nAppNo);
		LKGUD<mutex> lock_(mMutex);
		auto it = mSessions.find(appId_);
		if (it == mSessions.end()) {
			LOGE("[%s]%d,%d", __METHOD__, nAppType, nAppNo);
			return;
		}
		SessionPtr * session_ = it->second;
		(*session_)->runSend(nValue);
	}
	
	void SessionMgr::addSession(int16_t nAppType, int32_t nAppNo, SessionPtr& nSession)
	{
		int64_t appId_ = linkInt32(nAppType, nAppNo);
		LKGUD<mutex> lock_(mMutex);
		auto it = mSessions.find(appId_);
		if (it != mSessions.end()) {
			LOGE("[%s]%d,%d", __METHOD__, nAppType, nAppNo);
			return;
		}
		mSessions[appId_] = &nSession;
	}
	
	void SessionMgr::removeSession(int16_t nAppType, int32_t nAppNo)
	{
		int64_t appId_ = linkInt32(nAppType, nAppNo);
		LKGUD<mutex> lock_(mMutex);
		auto it = mSessions.find(appId_);
		if (it == mSessions.end()) {
			LOGE("[%s]%d,%d", __METHOD__, nAppType, nAppNo);
			return;
		}
		SessionPtr * session_ = it->second;
		int32_t sessionId_ = (*session_)->getSessionId();
		AcceptorMgr& acceptorMgr_ = AcceptorMgr::instance();
		acceptorMgr_.removeSession(sessionId_);
		mSessions.erase(it);
	}
	
	void SessionMgr::runPreinit()
	{
		LifeCycle& lifeCycle_ = LifeCycle::instance();
		lifeCycle_.m_tStopBegin.connect(bind(&SessionMgr::runStop, this));
	}
	
	void SessionMgr::runStop()
	{
		mSessions.clear();
	}
	
	SessionMgr& SessionMgr::instance()
	{
		return mSessionMgr;
	}
	
	SessionMgr::SessionMgr()
	{
		mSessions.clear();
	}
	
	SessionMgr::~SessionMgr()
	{
		mSessions.clear();
	}
	
	SessionMgr SessionMgr::mSessionMgr;
	
}
