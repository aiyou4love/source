#pragma once

namespace cc {
	
	class SessionMgr : noncopyable
	{
	public:
		void addSession(int16_t nAppType, int32_t nAppNo, SessionPtr& nSession);
		void removeSession(int64_t nAppId);
		
		void sendValue(int16_t nAppType, int32_t nAppNo, ValuePtr& nValue);
		
		void runPreinit();
		void runStop();
		
		static SessionMgr& instance();
		
		SessionMgr();
		~SessionMgr();
		
	private:
		map<int64_t, SessionPtr *> mSessions;
		mutex mMutex;
		
		static SessionMgr mSessionMgr;
	};
	
}
