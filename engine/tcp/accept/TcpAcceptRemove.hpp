#pragma once

namespace cc {
	
#ifndef __CLIENT__
	class TcpAcceptRemove : public ISessionRemove
	{
	public:
		void removeSession(int32_t nSessionId);
		void removeSession(int64_t nAppId);
		
		static ISessionRemove * instance();
		
		TcpAcceptRemove();
		~TcpAcceptRemove();
		
	private:
		static TcpAcceptRemove mTcpAcceptRemove;
	};
#endif
	
}
