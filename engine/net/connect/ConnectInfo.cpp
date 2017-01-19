#include "../../Engine.hpp"

namespace cc {
	
	int16_t ConnectInfo::getConnectDispatch()
	{
		return mConnectDispatch;
	}
	
	int32_t ConnectInfo::getConnectErrorId()
	{
		return mConnectErrorId;
	}
	
	int32_t ConnectInfo::getConnectId()
	{
		return mConnectId;
	}
	
	int32_t ConnectInfo::getTimeoutId()
	{
		return mTimeoutId;
	}
	
	int32_t ConnectInfo::getDisconnectId()
	{
		return mDisconnectId;
	}
	
	int32_t ConnectInfo::getExceptionId()
	{
		return mExceptionId;
	}
	
	int16_t ConnectInfo::getDispatchId()
	{
		return mDispatchId;
	}
	
	int32_t ConnectInfo::getVerMaxId()
	{
		return mVerMaxId;
	}
	
	int32_t ConnectInfo::getVerMinId()
	{
		return mVerMinId;
	}
	
	bool ConnectInfo::isReconnect()
	{
		return mReconnect;
	}
	
	bool ConnectInfo::isDefault()
	{
		return ((0 == mConnectId) || (0 == mTimeoutId) || (0 == mConnectErrorId)
			|| (0 == mDisconnectId) || (0 == mExceptionId) || (0 == mAppType)
			|| (0 == mDispatchId) || (0 == mConnectDispatch) );
	}
	
	int16_t ConnectInfo::getKey()
	{
		return mAppType;
	}
	
	ConnectInfo::ConnectInfo()
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
	
	ConnectInfo::~ConnectInfo()
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
