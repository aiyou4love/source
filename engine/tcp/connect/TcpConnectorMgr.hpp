#pragma once

namespace cc {
	
	class TcpConnectorMgr : noncopyable
	{
	public:
		void sendValue(int16_t nAppType, int32_t nAppNo, ValuePtr& nValue);
		void sendValue(int16_t nAppType, ValuePtr& nValue);
		bool sendValue(int64_t nAppId, ValuePtr& nValue);
		
		TcpSession * createSession(int64_t nAppId);
		void removeSession(int64_t nAppId);
		
		void runPreinit();
		void runStop();
		
		static TcpConnectorMgr& instance();
		
		TcpConnectorMgr();
		~TcpConnectorMgr();
		
	private:
		map<int64_t, TcpSessionPtr> mSessions;
		int32_t mSessionId;
		mutex mMutex;
		
		static TcpConnectorMgr mTcpConnectorMgr;
	};
	
}
