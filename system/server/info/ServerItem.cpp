#include "../../System.hpp"

namespace cc {
	
	int32_t ServerItem::getServerId()
	{
		return mServerId;
	}
	
	const char * ServerItem::getServerName()
	{
		return mServerName.c_str();
	}
	
	int32_t ServerItem::getServerNo()
	{
		return mServerNo;
	}
	
	int16_t ServerItem::getServerState()
	{
		return mServerState;
	}
	
	bool ServerItem::isDefault()
	{
		return (0 == mServerId);
	}
	
	int32_t ServerItem::getKey()
	{
		return mServerId;
	}
	
	ServerItem::ServerItem()
		: mServerId (0)
		, mServerName ("")
		, mServerNo (0)
		, mServerState (0)
	{
	}
	
	ServerItem::~ServerItem()
	{
		mServerId = 0;
		mServerName = "";
		mServerNo = 0;
		mServerState = 0;
	}
	
}
