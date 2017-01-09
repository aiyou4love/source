#pragma once

namespace cc {
	
#ifdef __CLIENT__
	class cAccountEngine : public AccountEngine
	{
	public:
		void setServerId(int32_t nServerId);
		
		int8_t roleCreate(const char * nRoleName, int16_t nRoleRace);
		
		void runCancel();
		
		int8_t runLogin(const char * nName, const char * nPassword, int16_t nType);
		
		int8_t runRegister(const char * nName, const char * nPassword);
		int8_t isRegister(const char * nName);
		
		const char * getAccountPassword();
		const char * getAccountName();
		
		int16_t getAccountType();
		int64_t getAccountId();
		
		int32_t getServerId();
		int32_t getRoleId();
		
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
