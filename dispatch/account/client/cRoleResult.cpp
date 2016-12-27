#include "../../Dispatch.hpp"

namespace cc {
	
#ifdef __CLIENT__
	const char * cRoleResult::streamName()
	{
		return "roleResult";
	}
	
	const char * cRoleResult::streamUrl()
	{
		return "roleResult.json";
	}
	
	RoleItemPtr& cRoleResult::getRoleItem()
	{
		return mRoleItem;
	}
	
	int64_t cRoleResult::getAccountId()
	{
		return mAccountId;
	}
	
	int32_t cRoleResult::getErrorCode()
	{
		return mErrorCode;
	}
	
	cRoleResult::cRoleResult()
		: mAccountId (0)
		, mErrorCode (0)
	{
	}
	
	cRoleResult::~cRoleResult()
	{
		mAccountId = 0;
		mErrorCode = 0;
	}
#endif
	
}
