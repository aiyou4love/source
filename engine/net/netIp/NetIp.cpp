#include "../../Engine.hpp"

namespace cc {
	
	const char * NetIp::getPort()
	{
		return mPort.c_str();
	}
	
	const char * NetIp::getIp()
	{
		return mIp.c_str();
	}
	
	int16_t NetIp::getAppType()
	{
		return mAppType;
	}
	
	int32_t NetIp::getAppNo()
	{
		return mAppNo;
	}
	
	bool NetIp::isDefault()
	{
		return ( (0 == mAppNo) || (0 == mAppType)
			|| ("" == mPort) || ("" == mIp) );
	}
	
	int64_t NetIp::getKey()
	{
		return linkInt32(mAppType, mAppNo);
	}
	
	NetIp::NetIp()
		: mAppNo (0)
		, mPort ("")
		, mIp ("")
		, mAppType (0)
	{
	}
	
	NetIp::~NetIp()
	{
		mAppNo = 0;
		mPort = "";
		mIp = "";
		mAppType = 0;
	}
	
}
