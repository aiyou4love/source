#include "../../Engine.hpp"

namespace cc {
	
#ifndef __CLIENT__
	void ServerSend::sendValue(ValuePtr& nValue)
	{
		TcpSessionMgr& tcpSessionMgr_ = TcpSessionMgr::instance();
		tcpSessionMgr_.sendValue(mAppType, mAppNo, nValue);
	}
	
	void ServerSend::setAppType(int16_t nAppType)
	{
		mAppType = nAppType;
	}
	
	void ServerSend::setAppNo(int32_t nAppNo)
	{
		mAppNo = nAppNo;
	}
	
	ServerSend::ServerSend()
		: mAppType (0)
		, mAppNo (0)
	{
	}
	
	ServerSend::~ServerSend()
	{
		mAppType = 0;
		mAppNo = 0;
	}
#endif
	
}
