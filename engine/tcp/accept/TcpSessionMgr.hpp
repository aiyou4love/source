#pragma once

namespace cc {
	
#ifndef __CLIENT__
	class TcpSessionMgr : noncopyable
	{
	public:
		void addSession(int16_t nAppType, int32_t nAppNo, TcpSession * nTcpSession);
		void removeSession(int64_t nAppId);
		
		void sendValue(int16_t nAppType, int32_t nAppNo, ValuePtr& nValue);
		
		void runPreinit();
		void runStop();
		
		static TcpSessionMgr& instance();
		
		TcpSessionMgr();
		~TcpSessionMgr();
		
	private:
		map<int64_t, TcpSession *> mSessions;
		mutex mMutex;
		
		static TcpSessionMgr mTcpSessionMgr;
	};
#endif
	
}
