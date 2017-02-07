#include "../../Engine.hpp"

namespace cc {
	
	void ConnectRemove::removeSession(int32_t nSessionId)
	{
	}
	
	void ConnectRemove::removeSession(int64_t nAppId)
	{
		ConnectorMgr& connectorMgr_ = ConnectorMgr::instance();
		connectorMgr_.removeSession(nAppId);
		
		ConnectEngine& connectEngine_ = ConnectEngine::instance();
		connectEngine_.initConnect(nAppId);
	}
	
	ISessionRemove * ConnectRemove::instance()
	{
		return (&mConnectRemove);
	}
	
	ConnectRemove::ConnectRemove()
	{
	}
	
	ConnectRemove::~ConnectRemove()
	{
	}
	
	ConnectRemove ConnectRemove::mConnectRemove;
	
}
