#include "../../System.hpp"

namespace cc {
	
#ifdef __CLIENT__
	const char * cLoginResult::streamName()
	{
		return "loginResult";
	}
	
	const char * cLoginResult::streamUrl()
	{
		return "loginResult.json";
	}
	
	RoleItemPtr& cLoginResult::getRoleItem()
	{
		return mRoleItem;
	}
	
	int64_t cLoginResult::getAccountId()
	{
		return mAccountId;
	}
	
	int16_t cLoginResult::getAuthority()
	{
		return mAuthority;
	}
	
	cLoginResult::cLoginResult()
		: mRoleItem (new RoleItem())
		, mAccountId (0)
		, mAuthority (0)
	{
		mServerItems.clear();
	}
	
	cLoginResult::~cLoginResult()
	{
		mServerItems.clear();
		
		mAccountId = 0;
		mAuthority = 0;
	}
#endif
	
}
