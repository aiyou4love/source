#pragma once

namespace cc {
	
#ifdef __SOCIAL__
	class cAccountEngine : public AccountEngine
	{
	public:
		void runPreinit();
		
		static cAccountEngine& instance();
		
		cAccountEngine();
		~cAccountEngine();
		
	private:
		static cAccountEngine mAccountEngine;
		
		map<int64_t, cAccountPtr> mAccounts;
	};
#endif
	
}
