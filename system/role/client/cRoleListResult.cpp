#include "../../System.hpp"

namespace cc {
	
#ifdef __CLIENT__
	list<ServerItemPtr>& cRoleListResult::getServerItems()
	{
		return mServerItems;
	}
	
	list<RoleItemPtr>& cRoleListResult::getRoleItems()
	{
		return mRoleItems;
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
		mServerItems.clear();
		mRoleItems.clear();
	}
	
	cRoleListResult::~cRoleListResult()
	{
		mServerItems.clear();
		mRoleItems.clear();
	}
#endif
	
}
