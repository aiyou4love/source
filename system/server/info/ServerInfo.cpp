#include "../../System.hpp"

namespace cc {
	
	int64_t ServerInfo::getServerStart()
	{
		return mServerStart;
	}
	
	int16_t ServerInfo::getClassify()
	{
		return mClassify;
	}
	
	int32_t ServerInfo::getServerNo()
	{
		return mServerNo;
	}
	
	bool ServerInfo::isDefault()
	{
		return ( (0 == mServerNo) || (0 == mServerStart) || (0 == mClassify) );
	}
	
	int32_t ServerInfo::getKey()
	{
		return mServerNo;
	}
	
	ServerInfo::ServerInfo()
		: mServerStart (0)
		, mServerNo (0)
		, mClassify (0)
	{
	}
	
	ServerInfo::~ServerInfo()
	{
		mServerStart = 0;
		mServerNo = 0;
		mClassify = 0;
	}
	
}
