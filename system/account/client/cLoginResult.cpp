#include "../../System.hpp"

namespace cc {
	
#ifdef __CLIENT__
	ServerItemPtr& cLoginResult::getServerItem()
	{
		return mServerItem;
	}
	
	RoleItemPtr& cLoginResult::getRoleItem()
	{
		return mRoleItem;
	}
	
	int64_t cLoginResult::getAccountId()
	{
		return mAccountId;
	}
	
	const char * cLoginResult::streamName()
	{
		return "loginResult";
	}
	
	const char * cLoginResult::streamUrl()
	{
		return "loginResult.json";
	}
	
	cLoginResult::cLoginResult()
		: mServerItem (new ServerItem())
		, mRoleItem (new RoleItem())
		, mAccountId (0)
	{
	}
	
	cLoginResult::~cLoginResult()
	{
		mServerItem.reset();
		mRoleItem.reset();
		
		mAccountId = 0;
	}
#endif
	
}
