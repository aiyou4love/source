#pragma once

namespace cc {
	
#ifdef __GAME__
	class cRoleEngine : public RoleEngine
	{
	public:
		void pushValue(ValuePtr& nValue);
		void runUpdate();
		
		void runPreinit();
		
		static cRoleEngine& instance();
		
		cRoleEngine();
		~cRoleEngine();
		
	private:
		static cRoleEngine mRoleEngine;
	};
#endif
	
}
