#include "../../Engine.hpp"

namespace cc {
	
#ifndef __CLIENT__
	void TcpAcceptorMgr::removeSession(int32_t nSessionId)
	{
		LKGUD<mutex> lock_(mMutex);
		auto it = mSessions.find(nSessionId);
		if (it == mSessions.end()) {
			LOGE("[%s]%d", __METHOD__, nSessionId);
			return;
		}
		mSessions.erase(it);
	}
	
	TcpSession * TcpAcceptorMgr::createSession()
	{
		ISessionRemove * sessionRemove_ = TcpAcceptRemove::instance();
		IoService& ioService_ = IoService::instance();
		
		LKGUD<mutex> lock_(mMutex);
		asio::io_service& ioHandle_ = ioService_.getIoHandle();
		TcpSessionPtr tcpSession_(new TcpSession(++mSessionId, ioHandle_));
		tcpSession_->setDisconnect(mDisconnectId);
		tcpSession_->setException(mExceptionId);
		tcpSession_->setDispatch(mDispatchId);
		tcpSession_->setRemove(sessionRemove_);
		tcpSession_->setIsAccept(true);
		mSessions[mSessionId] = tcpSession_;
		return ( tcpSession_.get() );
	}
	
	const char * TcpAcceptorMgr::streamName()
	{
		return "tcpAcceptorMgr";
	}
	
	const char * TcpAcceptorMgr::streamUrl()
	{
		return "tcpAcceptorMgr.json";
	}
	
	void TcpAcceptorMgr::runPreinit()
	{
		LifeCycle& lifeCycle_ = LifeCycle::instance();
		lifeCycle_.m_tLoadBegin.connect(bind(&TcpAcceptorMgr::runLoad, this));
		lifeCycle_.m_tStoping.connect(bind(&TcpAcceptorMgr::runStop, this));
	}
	
	void TcpAcceptorMgr::runLoad()
	{
		TableEngine& tableEngine_ = TableEngine::instance();
		tableEngine_.runReader<TcpAcceptorMgr>(this, streamUrl(), streamName());
	}
	
	void TcpAcceptorMgr::runStop()
	{
		mSessions.clear();
	}
	
	TcpAcceptorMgr& TcpAcceptorMgr::instance()
	{
		return mTcpAcceptorMgr;
	}
	
	TcpAcceptorMgr::TcpAcceptorMgr()
		: mSessionId (0)
		, mDisconnectId (0)
		, mExceptionId (0)
		, mDispatchId (0)
	{
		mSessions.clear();
	}
	
	TcpAcceptorMgr::~TcpAcceptorMgr()
	{
		mSessions.clear();
		mSessionId = 0;
		
		mDisconnectId = 0;
		mExceptionId = 0;
		mDispatchId = 0;
	}
	
	TcpAcceptorMgr TcpAcceptorMgr::mTcpAcceptorMgr;
#endif
	
}
