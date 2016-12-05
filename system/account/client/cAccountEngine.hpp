#pragma once

namespace cc {
	
#ifdef __CLIENT__
	class cAccountEngine : public AccountEngine
	{
	public:
		int8_t runLogin(const char * nName, const char * nPassword, int16_t nType);
		bool isLogin();
		int8_t runRegister(const char * nName, const char * nPassword);
		int8_t isRegister(const char * nName);
		void runCancel();
		bool haveRole();
		int32_t getServerId();
		
		int8_t roleCreate(const char * nRoleName, int16_t nRoleRace);
		
		EntityPtr& getAccount();
		
		void runPreinit();
		void runLuaApi();
		void runLoad();
		void runClear();
		
		static cAccountEngine& instance();
		
		cAccountEngine();
		~cAccountEngine();
		
	private:
		static cAccountEngine mAccountEngine;
		
		EntityPtr mAccount;
	};
#endif
	
}
