#include "../../Engine.hpp"

namespace cc {
	
	void TcpConnectRemove::removeSession(int32_t nSessionId)
	{
	}
	
	void TcpConnectRemove::removeSession(int64_t nAppId)
	{
		TcpConnectorMgr& tcpConnectorMgr_ = TcpConnectorMgr::instance();
		tcpConnectorMgr_.removeSession(nAppId);
		
		TcpConnectEngine& tcpConnectEngine_ = TcpConnectEngine::instance();
		tcpConnectEngine_.initConnect(nAppId);
	}
	
	ISessionRemove * TcpConnectRemove::instance()
	{
		return (&mTcpConnectRemove);
	}
	
	TcpConnectRemove::TcpConnectRemove()
	{
	}
	
	TcpConnectRemove::~TcpConnectRemove()
	{
	}
	
	TcpConnectRemove TcpConnectRemove::mTcpConnectRemove;
	
}
