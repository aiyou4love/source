#include "../../Engine.hpp"

namespace cc {
	
	int32_t NetNo::getAppNo()
	{
		return mAppNo;
	}
	
	bool NetNo::isDefault()
	{
		return ( (0 == mServerId) || (0 == mAppNo) );
	}
	
	int32_t NetNo::getKey()
	{
		return mServerId;
	}
	
	NetNo::NetNo()
		: mServerId (0)
		, mAppNo (0)
	{
	}
	
	NetNo::~NetNo()
	{
		mServerId = 0;
		mAppNo = 0;
	}
	
}
