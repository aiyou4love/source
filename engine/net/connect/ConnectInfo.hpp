#pragma once

namespace cc {
	
	class ConnectInfo : noncopyable
	{
	public:
		int32_t getConnectErrorId();
		int32_t getConnectId();
		int32_t getTimeoutId();
		
		int16_t getConnectDispatch();
		int32_t getDisconnectId();
		int32_t getExceptionId();
		int16_t getDispatchId();
		
		bool isReconnect();
		
		template<class T>
		void serialize(T * nSerialize, const char * nName, int8_t nCount)
		{
			nSerialize->runNumber(mAppType, "appType");
			
			nSerialize->runNumber(mConnectDispatch, "connectDispatch");
			nSerialize->runNumber(mConnectErrorId, "connectErrorId");
			nSerialize->runNumber(mConnectId, "connectId");
			nSerialize->runNumber(mTimeoutId, "timeoutId");
			
			nSerialize->runNumber(mDisconnectId, "disconnectId");
			nSerialize->runNumber(mExceptionId, "exceptionId");
			nSerialize->runNumber(mDispatchId, "dispatchId");
			
			nSerialize->runNumber(mReconnect, "reconnect");
		}
		bool isDefault();
		int16_t getKey();
		
		ConnectInfo();
		~ConnectInfo();
		
	private:
		int16_t mAppType;
		
		int16_t mConnectDispatch;
		int32_t mConnectErrorId;
		int32_t mConnectId;
		int32_t mTimeoutId;
		
		int32_t mDisconnectId;
		int32_t mExceptionId;
		int16_t mDispatchId;
		
		bool mReconnect;
	};
	typedef SPTR<ConnectInfo> ConnectInfoPtr;
	
}
