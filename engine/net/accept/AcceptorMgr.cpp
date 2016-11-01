#include "../../Engine.hpp"

namespace cc {
	
	void AcceptorMgr::removeSession(int32_t nSessionId)
	{
		LKGUD<mutex> lock_(mMutex);
		auto it = mSessions.find(nSessionId);
		if (it == mSessions.end()) {
			LOGE("[%s]%d", __METHOD__, nSessionId);
			return;
		}
		mSessions.erase(it);
	}
	
	SessionPtr& AcceptorMgr::createSession()
	{
		IoService& ioService_ = IoService::instance();
		asio::io_service& ioHandle_ = ioService_.getIoHandle();
		
		LKGUD<mutex> lock_(mMutex);
		SessionPtr session_(new Session(++mSessionId, ioHandle_));
		session_->setDisconnect(mDisconnectId);
		session_->setException(mExceptionId);
		session_->setDispatch(mDispatchId);
		mSessions[mSessionId] = session_;
		return mSessions[mSessionId];
	}
	
	const char * AcceptorMgr::streamName()
	{
		return "acceptorMgr";
	}
	
	const char * AcceptorMgr::streamUrl()
	{
		return "acceptorMgr.json";
	}
	
	void AcceptorMgr::runPreinit()
	{
		LifeCycle& lifeCycle_ = LifeCycle::instance();
		lifeCycle_.m_tLoadBegin.connect(bind(&AcceptorMgr::runLoad, this));
		lifeCycle_.m_tStoping.connect(bind(&AcceptorMgr::runStop, this));
	}
	
	void AcceptorMgr::runLoad()
	{
		TableEngine& tableEngine_ = TableEngine::instance();
		tableEngine_.runReader<AcceptorMgr>(this, streamUrl(), streamName());
	}
	
	void AcceptorMgr::runStop()
	{
		mSessions.clear();
	}
	
	AcceptorMgr& AcceptorMgr::instance()
	{
		return mAcceptorMgr;
	}
	
	AcceptorMgr::AcceptorMgr()
		: mSessionId (0)
		, mDisconnectId (0)
		, mExceptionId (0)
		, mDispatchId (0)
	{
		mSessions.clear();
	}
	
	AcceptorMgr::~AcceptorMgr()
	{
		mSessions.clear();
		mSessionId = 0;
		
		mDisconnectId = 0;
		mExceptionId = 0;
		mDispatchId = 0;
	}
	
	AcceptorMgr AcceptorMgr::mAcceptorMgr;
	
}
