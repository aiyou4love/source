#include "../../System.hpp"

namespace cc {
	
	int64_t ServerInfo::getServerStart()
	{
		return mServerStart;
	}
	
	int32_t ServerInfo::getServerNo()
	{
		return mServerNo;
	}
	
	bool ServerInfo::isDefault()
	{
		return ( (0 == mServerNo) || (0 == mServerStart) );
	}
	
	int32_t ServerInfo::getKey()
	{
		return mServerNo;
	}
	
	ServerInfo::ServerInfo()
		: mServerStart (0)
		, mServerNo (0)
	{
	}
	
	ServerInfo::~ServerInfo()
	{
		mServerStart = 0;
		mServerNo = 0;
	}
	
}
