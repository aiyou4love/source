#pragma once

namespace cc {
	
#ifdef __CLIENT__
	class cAccountEngine : public AccountEngine
	{
	public:
		int8_t runLogin(const char * nName, const char * nPassword, int16_t nType);
		const char * getAccountName();
		int64_t getAccountId();
		int8_t runRegister(const char * nName, const char * nPassword);
		int8_t isRegister(const char * nName);
		void runCancel();
		int32_t getRoleId();
		void setServerId(int32_t nServerId);
		int32_t getServerId();
		
		int8_t roleCreate(const char * nRoleName, int16_t nRoleRace);
		
		void pushValue(ValuePtr& nValue);
		void runUpdate();
		
		EntityPtr& getAccount();
		
		void runPreinit();
		void runLuaApi();
		void runLoad();
		void runInit();
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
