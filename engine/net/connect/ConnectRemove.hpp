#pragma once

namespace cc {
	
	class ConnectRemove : public ISessionRemove
	{
	public:
		void removeSession(int32_t nSessionId);
		void removeSession(int64_t nAppId);
		
		static ISessionRemove * instance();
		
		ConnectRemove();
		~ConnectRemove();
		
	private:
		static ConnectRemove mConnectRemove;
	};
	
}
