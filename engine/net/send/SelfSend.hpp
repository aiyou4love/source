#pragma once

namespace cc {
	
	class SelfSend : public ISend
	{
	public:
		void setSession(SessionPtr& nSession);
		
		void sendValue(ValuePtr& nValue);
		void pushValue(ValuePtr& nValue);
		
		SelfSend();
		~SelfSend();
		
	private:
		SessionPtr * mSession;
	};
	
}
