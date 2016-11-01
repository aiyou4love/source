#pragma once

namespace cc {
	
	class ConnectorMgr : noncopyable
	{
	public:
		void sendValue(int16_t nAppType, int32_t nAppNo, ValuePtr& nValue);
		void sendValue(int16_t nAppType, ValuePtr& nValue);
		bool sendValue(int64_t nAppId, ValuePtr& nValue);
		
		SessionPtr& createSession(int64_t nAppId);
		void removeSession(int64_t nAppId);
		
		void runPreinit();
		void runStop();
		
		static ConnectorMgr& instance();
		
		ConnectorMgr();
		~ConnectorMgr();
		
	private:
		map<int64_t, SessionPtr> mSessions;
		int32_t mSessionId;
		mutex mMutex;
		
		static ConnectorMgr mConnectorMgr;
	};
	
}
