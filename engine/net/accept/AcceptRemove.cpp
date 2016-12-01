#include "../../Engine.hpp"

namespace cc {
	
#ifndef __CLIENT__
	void AcceptRemove::removeSession(int32_t nSessionId)
	{
		AcceptorMgr& acceptorMgr_ = AcceptorMgr::instance();
		acceptorMgr_.removeSession(nSessionId);
	}
	
	void AcceptRemove::removeSession(int64_t nAppId)
	{
		SessionMgr& sessionMgr_ = SessionMgr::instance();
		sessionMgr_.removeSession(nAppId);
	}
	
	AcceptRemove& AcceptRemove::instance()
	{
		return mAcceptRemove;
	}
	
	AcceptRemove::AcceptRemove()
	{
	}
	
	AcceptRemove::~AcceptRemove()
	{
	}
	
	AcceptRemove AcceptRemove::mAcceptRemove;
#endif
	
}
