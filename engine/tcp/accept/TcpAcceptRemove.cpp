#include "../../Engine.hpp"

namespace cc {
	
#ifndef __CLIENT__
	void TcpAcceptRemove::removeSession(int32_t nSessionId)
	{
		TcpAcceptorMgr& tcpAcceptorMgr_ = TcpAcceptorMgr::instance();
		tcpAcceptorMgr_.removeSession(nSessionId);
	}
	
	void TcpAcceptRemove::removeSession(int64_t nAppId)
	{
		TcpSessionMgr& tcpSessionMgr_ = TcpSessionMgr::instance();
		tcpSessionMgr_.removeSession(nAppId);
	}
	
	ISessionRemove * TcpAcceptRemove::instance()
	{
		return (&mTcpAcceptRemove);
	}
	
	TcpAcceptRemove::TcpAcceptRemove()
	{
	}
	
	TcpAcceptRemove::~TcpAcceptRemove()
	{
	}
	
	TcpAcceptRemove TcpAcceptRemove::mTcpAcceptRemove;
#endif
	
}
