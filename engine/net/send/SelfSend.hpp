#pragma once

namespace cc {
	
	class SelfSend : public ISend
	{
	public:
		void setSession(Session * nSession);
		
		void sendValue(ValuePtr& nValue);
		void pushValue(ValuePtr& nValue);
		
		SelfSend();
		~SelfSend();
		
	private:
		Session * mSession;
	};
	
}
