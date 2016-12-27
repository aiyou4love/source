#include "../../Engine.hpp"

namespace cc {
	
	void NetIp::setPort(const char * nPort)
	{
		mPort = nPort;
	}
	
	const char * NetIp::getPort()
	{
		return mPort.c_str();
	}
	
	void NetIp::setIp(const char * nIp)
	{
		mIp = nIp;
	}
	
	const char * NetIp::getIp()
	{
		return mIp.c_str();
	}
	
	void NetIp::setAppType(int16_t nAppType)
	{
		mAppType = nAppType;
	}
	
	int16_t NetIp::getAppType()
	{
		return mAppType;
	}
	
	void NetIp::setAppNo(int32_t nAppNo)
	{
		mAppNo = nAppNo;
	}
	
	int32_t NetIp::getAppNo()
	{
		return mAppNo;
	}
	
	bool NetIp::isDefault()
	{
		return ( (0 == mAppType) || ("" == mPort) || ("" == mIp) );
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
