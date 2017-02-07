#pragma once

namespace cc {
	
#ifndef __CLIENT__
	class SessionMgr : noncopyable
	{
	public:
		void addSession(int16_t nAppType, int32_t nAppNo, Session * nSession);
		void removeSession(int64_t nAppId);
		
		void sendValue(int16_t nAppType, int32_t nAppNo, ValuePtr& nValue);
		
		void runPreinit();
		void runStop();
		
		static SessionMgr& instance();
		
		SessionMgr();
		~SessionMgr();
		
	private:
		map<int64_t, Session *> mSessions;
		mutex mMutex;
		
		static SessionMgr mSessionMgr;
	};
#endif
	
}
