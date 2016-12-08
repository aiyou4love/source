#pragma once

namespace cc {
	
#ifdef __AGENT__
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
