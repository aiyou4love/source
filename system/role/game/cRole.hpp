#pragma once

namespace cc {
	
#ifdef __GAME__
	class cRole : public Role
	{
	public:
		int64_t getId();
		
		cRole();
		~cRole();
	};
	typedef SPTR<cRole> cRolePtr;
#endif
	
}
