#include "../../System.hpp"

namespace cc {
	
#ifdef __AGENT__
	void cAccount::setPassword(const char * nPassword)
	{
		mPassword = nPassword;
	}
	
	const char * cAccount::getPassword()
	{
		return mPassword.c_str();
	}
	
	void cAccount::setName(const char * nName)
	{
		mName = nName;
	}
	
	const char * cAccount::getName()
	{
		return mName.c_str();
	}
	
	void cAccount::runClear()
	{
		Account::runClear();
		
		mPassword = "";
		mName = "";
	}
	
	cAccount::cAccount()
		: mPassword ("")
		, mName ("")
	{
	}
	
	cAccount::~cAccount()
	{
		mPassword = "";
		mName = "";
	}
#endif
	
}
