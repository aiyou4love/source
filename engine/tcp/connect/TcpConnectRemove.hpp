#pragma once

namespace cc {
	
	class TcpConnectRemove : public ISessionRemove
	{
	public:
		void removeSession(int32_t nSessionId);
		void removeSession(int64_t nAppId);
		
		static ISessionRemove * instance();
		
		TcpConnectRemove();
		~TcpConnectRemove();
		
	private:
		static TcpConnectRemove mTcpConnectRemove;
	};
	
}
