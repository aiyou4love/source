#pragma once

namespace cc {
	
#ifdef __AGENT__
	class cAccount : public Account
	{
	public:
		void setPassword(const char * nPassword);
		const char * getPassword();
		
		void setName(const char * nName);
		const char * getName();
		
		void runClear();
		
		cAccount();
		~cAccount();
		
	private:
		string mPassword;
		string mName;
	};
	typedef SPTR<cAccount> cAccountPtr;
#endif
	
}
