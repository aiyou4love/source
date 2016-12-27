#include "../../Aspect.hpp"

namespace cc {
	
#ifdef __CLIENT__
	ServerInfoPtr& cAgentResult::getServerInfo()
	{
		return mServerInfo;
	}
	
	const char * cAgentResult::getAgentPort()
	{
		return mAgentPort.c_str();
	}
	
	const char * cAgentResult::getAgentIp()
	{
		return mAgentIp.c_str();
	}
	
	int32_t cAgentResult::getErrorCode()
	{
		return mErrorCode;
	}
	
	const char * cAgentResult::streamName()
	{
		return "agentResult";
	}
	
	const char * cAgentResult::streamUrl()
	{
		return "agentResult.json";
	}
	
	cAgentResult::cAgentResult()
		: mServerInfo (new ServerInfo())
		, mAgentPort ("")
		, mAgentIp ("")
		, mErrorCode (0)
	{
	}
	
	cAgentResult::~cAgentResult()
	{
		mServerInfo.reset();
		
		mAgentPort = "";
		mAgentIp = "";
		mErrorCode = 0;
	}
#endif
	
}
