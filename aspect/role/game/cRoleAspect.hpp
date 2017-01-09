#pragma once

namespace cc {
	
#ifdef __GAME__
	class cRoleAspect : public RoleAspect
	{
	public:
		static cRoleAspect& instance();
		
		cRoleAspect();
		~cRoleAspect();
		
	private:
		static cRoleAspect mRoleAspect;
	};
#endif
	
}
