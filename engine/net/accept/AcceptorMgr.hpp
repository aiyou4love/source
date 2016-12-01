#pragma once

namespace cc {
	
#ifndef __CLIENT__
	class AcceptorMgr : noncopyable
	{
	public:
		void removeSession(int32_t nSessionId);
		SessionPtr& createSession();
		
		template<class T>
		void headSerialize(T& nSerialize, const char * nName)
		{
			nSerialize.runNumber(mDisconnectId, "disconnectId");
			nSerialize.runNumber(mExceptionId, "exceptionId");
			nSerialize.runNumber(mDispatchId, "dispatchId");
		}
		const char * streamName();
		const char * streamUrl();
		
		void runPreinit();
		void runLoad();
		void runStop();
		
		static AcceptorMgr& instance();
		
		AcceptorMgr();
		~AcceptorMgr();
		
	private:
		map<int32_t, SessionPtr> mSessions;
		
		int32_t mSessionId;
		mutex mMutex;
		
		int32_t mDisconnectId;
		int32_t mExceptionId;
		int16_t mDispatchId;
		
		static AcceptorMgr mAcceptorMgr;
	};
#endif
	
}
