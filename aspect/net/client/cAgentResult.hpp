#pragma once

namespace cc {
	
#ifdef __CLIENT__
	class cAgentResult : noncopyable
	{
	public:
		ServerInfoPtr& getServerInfo();
		const char * getAgentPort();
		const char * getAgentIp();
		int32_t getErrorCode();
		
		template<class T>
		void headSerialize(T& nSerialize, const char * nName)
		{
			nSerialize.runNumber(mErrorCode, "mErrorCode");
			nSerialize.runNumber(mAgentIp, "mAgentIp");
			nSerialize.runNumber(mAgentPort, "mAgentPort");
			nSerialize.runStreamPtr(mServerInfo, "mServerInfo");
		}
		
		const char * streamName();
		const char * streamUrl();
		
		cAgentResult();
		~cAgentResult();
		
	private:
		ServerInfoPtr mServerInfo;
		string mAgentPort;
		string mAgentIp;
		int32_t mErrorCode;
	};
	typedef SPTR<cAgentResult> cAgentResultPtr;
#endif
	
}
