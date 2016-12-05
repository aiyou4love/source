#include "../../System.hpp"

namespace cc {
	
#ifdef __CLIENT__
	list<RoleItemPtr>& cRoleListResult::getRoleItems()
	{
		return mRoleItems;;
	}
	
	const char * cRoleListResult::streamName()
	{
		return "roleListResult";
	}
	
	const char * cRoleListResult::streamUrl()
	{
		return "roleListResult.json";
	}
	
	cRoleListResult::cRoleListResult()
	{
		mRoleItems.clear();
	}
	
	cRoleListResult::~cRoleListResult()
	{
		mRoleItems.clear();
	}
#endif
	
}
