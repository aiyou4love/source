#pragma once

namespace cc {
	
	class AccountUpdate : public Context
	{
	public:
		void runContext(int64_t nTick);
		
		AccountUpdate();
		~AccountUpdate();
	};
	
}
