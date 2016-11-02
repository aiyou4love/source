#include "../Engine.hpp"

namespace cc {
	
	void ConnectRemove::removeSession(int32_t nSessionId)
	{
	}
	
	void ConnectRemove::removeSession(int64_t nAppId)
	{
		ConnectorMgr& connectorMgr_ = ConnectorMgr::instance();
		connectorMgr_.removeSession(nAppId);
	}
	
	ConnectRemove& ConnectRemove::instance()
	{
		return mConnectRemove;
	}
	
	ConnectRemove::ConnectRemove()
	{
	}
	
	ConnectRemove::~ConnectRemove()
	{
	}
	
	ConnectRemove ConnectRemove::mConnectRemove;
	
}
