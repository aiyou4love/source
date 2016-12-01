#pragma once

namespace cc {
	
#ifndef __CLIENT__
	class AcceptRemove : public ISessionRemove
	{
	public:
		void removeSession(int32_t nSessionId);
		void removeSession(int64_t nAppId);
		
		static AcceptRemove& instance();
		
		AcceptRemove();
		~AcceptRemove();
		
	private:
		static AcceptRemove mAcceptRemove;
	};
#endif
	
}
