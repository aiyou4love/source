#include "../../Engine.hpp"

namespace cc {
	
	int16_t TcpConnectInfo::getConnectDispatch()
	{
		return mConnectDispatch;
	}
	
	int32_t TcpConnectInfo::getConnectErrorId()
	{
		return mConnectErrorId;
	}
	
	int32_t TcpConnectInfo::getConnectId()
	{
		return mConnectId;
	}
	
	int32_t TcpConnectInfo::getTimeoutId()
	{
		return mTimeoutId;
	}
	
	int32_t TcpConnectInfo::getDisconnectId()
	{
		return mDisconnectId;
	}
	
	int32_t TcpConnectInfo::getExceptionId()
	{
		return mExceptionId;
	}
	
	int16_t TcpConnectInfo::getDispatchId()
	{
		return mDispatchId;
	}
	
	int32_t TcpConnectInfo::getVerMaxId()
	{
		return mVerMaxId;
	}
	
	int32_t TcpConnectInfo::getVerMinId()
	{
		return mVerMinId;
	}
	
	bool TcpConnectInfo::isReconnect()
	{
		return mReconnect;
	}
	
	bool TcpConnectInfo::isDefault()
	{
		return ((0 == mConnectId) || (0 == mTimeoutId) || (0 == mConnectErrorId)
			|| (0 == mDisconnectId) || (0 == mExceptionId) || (0 == mAppType)
			|| (0 == mDispatchId) || (0 == mConnectDispatch) );
	}
	
	int16_t TcpConnectInfo::getKey()
	{
		return mAppType;
	}
	
	TcpConnectInfo::TcpConnectInfo()
		: mAppType (0)
		, mConnectDispatch (0)
		, mConnectErrorId (0)
		, mConnectId (0)
		, mTimeoutId (0)
		, mDisconnectId (0)
		, mExceptionId (0)
		, mDispatchId (0)
		, mVerMaxId (0)
		, mVerMinId (0)
		, mReconnect (false)
	{
	}
	
	TcpConnectInfo::~TcpConnectInfo()
	{
		mAppType = 0;
		
		mConnectDispatch = 0;
		mConnectErrorId = 0;
		mConnectId = 0;
		mTimeoutId = 0;
		
		mDisconnectId = 0;
		mExceptionId = 0;
		mVerMaxId = 0;
		mVerMaxId = 0;
		mDispatchId = 0;
		
		mReconnect = false;
	}
	
}
