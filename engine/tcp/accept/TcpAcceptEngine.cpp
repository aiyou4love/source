#include "../../Engine.hpp"

namespace cc {
	
#ifndef __CLIENT__
	void TcpAcceptEngine::handleAccept(const boost::system::error_code& nError)
	{
		if (nError) {
			LOGE("[%s]%s", __METHOD__, nError.message().c_str());
			this->runStop();
			return;
		}
		mNewSession->startRead();
		mNewSession = nullptr;
		startAccept();
	}
	
	void TcpAcceptEngine::initAccept()
	{
		NetIpMgr& netIpMgr_ = NetIpMgr::instance();
		NetIp * netIp_ = netIpMgr_.findNetIp();
		if (nullptr == netIp_) {
			LOGE("[%s]", __METHOD__);
			return;
		}
		const char * port_ = netIp_->getPort();
		const char * ip_ = netIp_->getIp();
		
		IoService& ioService_ = IoService::instance();
		asio::io_service& ioHandle_ = ioService_.getIoHandle();
		mAcceptor.reset(new asio::ip::tcp::acceptor(ioHandle_));
		
		asio::ip::tcp::resolver resolver_(mAcceptor->get_io_service());
		asio::ip::tcp::resolver::query query_(ip_, port_);
		asio::ip::tcp::endpoint endpoint_ = *resolver_.resolve(query_);
		mAcceptor->open(endpoint_.protocol());
		mAcceptor->set_option(asio::ip::tcp::acceptor::reuse_address(true));
		mAcceptor->bind(endpoint_);
		mAcceptor->listen();
		startAccept();
	}
	
	void TcpAcceptEngine::startAccept()
	{
		try {
			TcpAcceptorMgr& tcpAcceptorMgr_ = TcpAcceptorMgr::instance();
			mNewSession = tcpAcceptorMgr_.createSession();
			
			mAcceptor->async_accept(mNewSession->getSocket(),
				boost::bind(&TcpAcceptEngine::handleAccept, this,
				boost::asio::placeholders::error));
		} catch (boost::system::system_error& e) {
			LOGE("[%s]%s", __METHOD__, e.what());
			this->runStop();
		}
	}
	
	void TcpAcceptEngine::runPreinit()
	{
		LifeCycle& lifeCycle_ = LifeCycle::instance();
		lifeCycle_.m_tStopBegin.connect(bind(&TcpAcceptEngine::runStop, this));
	}
	
	void TcpAcceptEngine::runStop()
	{
		if (nullptr != mNewSession) {
			int32_t sessionId_ = mNewSession->getSessionId();
			TcpAcceptorMgr& tcpAcceptorMgr_ = TcpAcceptorMgr::instance();
			tcpAcceptorMgr_.removeSession(sessionId_);
			mNewSession = nullptr;
		}
		if (!mAcceptor) {
			return;
		}
 		mAcceptor->close();
	}
	
	TcpAcceptEngine& TcpAcceptEngine::instance()
	{
		return mTcpAcceptEngine;
	}
	
	TcpAcceptEngine::TcpAcceptEngine()
		: mNewSession(nullptr)
	{
	}
	
	TcpAcceptEngine::~TcpAcceptEngine()
	{
		mNewSession = nullptr;
	}
	
	TcpAcceptEngine TcpAcceptEngine::mTcpAcceptEngine;
#endif
	
}
