#pragma once

namespace cc {
	
#ifdef __CLIENT__
	class cAccountEngine : public AccountEngine
	{
	public:
		const char * getAccountPassword();
		const char * getAccountName();
		
		int16_t getAccountType();
		int64_t getAccountId();
		
		int32_t getServerId();
		
		void runPreinit();
		void runLoad();
		void runSave();
		void runClear();
		
		static cAccountEngine& instance();
		
		cAccountEngine();
		~cAccountEngine();
		
	private:
		static cAccountEngine mAccountEngine;
		
		cAccount mAccount;
	};
#endif
	
}
