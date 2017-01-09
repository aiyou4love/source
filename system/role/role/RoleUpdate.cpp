#include "../../System.hpp"

namespace cc {
	
	void RoleUpdate::runContext(int64_t nTick)
	{
		cRoleEngine& roleEngine_ = cRoleEngine::instance();
		roleEngine_.runUpdate();
	}
	
	RoleUpdate::RoleUpdate()
	{
	}
	
	RoleUpdate::~RoleUpdate()
	{
	}
	
}
