#pragma once

namespace cc {
	
#ifndef __CLIENT__
	class TcpAcceptorMgr : noncopyable
	{
	public:
		void removeSession(int32_t nSessionId);
		TcpSession * createSession();
		
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
		
		static TcpAcceptorMgr& instance();
		
		TcpAcceptorMgr();
		~TcpAcceptorMgr();
		
	private:
		map<int32_t, TcpSessionPtr> mSessions;
		
		int32_t mSessionId;
		mutex mMutex;
		
		int32_t mDisconnectId;
		int32_t mExceptionId;
		int16_t mDispatchId;
		
		static TcpAcceptorMgr mTcpAcceptorMgr;
	};
#endif
	
}
