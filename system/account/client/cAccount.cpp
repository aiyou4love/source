#include "../../System.hpp"

namespace cc {
	
#ifdef __CLIENT__
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
	
	void cAccount::runLoad()
	{
		UserDefault& userDefault_ = UserDefault::instance();
		userDefault_.runReader<cAccount>(this, streamUrl(), streamName());
	}
	
	void cAccount::runSave()
	{
		UserDefault& userDefault_ = UserDefault::instance();
		userDefault_.runSave<cAccount>(this, streamUrl(), streamName());
	}
	
	const char * cAccount::streamName()
	{
		return "account";
	}
	
	const char * cAccount::streamUrl()
	{
		return "account.json";
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
