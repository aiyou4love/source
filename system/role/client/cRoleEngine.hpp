#pragma once

namespace cc {
	
#ifdef __CLIENT__
	class cRoleEngine : public RoleEngine
	{
	public:
		void pushValue(ValuePtr& nValue);
		void runUpdate();
		
		EntityPtr& getRole();
		
		void runPreinit();
		void runLuaApi();
		
		static cRoleEngine& instance();
		
		cRoleEngine();
		~cRoleEngine();
		
	private:
		static cRoleEngine mRoleEngine;
		
		EntityPtr mRole;
	};
#endif
	
}
