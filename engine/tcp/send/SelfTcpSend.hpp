#pragma once

namespace cc {
	
	class SelfTcpSend : public ISend
	{
	public:
		void setSession(TcpSession * nTcpSession);
		
		void sendValue(ValuePtr& nValue);
		void pushValue(ValuePtr& nValue);
		
		SelfTcpSend();
		~SelfTcpSend();
		
	private:
		TcpSession * mTcpSession;
	};
	
}
