#pragma once

namespace cc {
	
#ifdef __CLIENT__
	class cRoleEngine : public RoleEngine
	{
	public:
		int32_t setServerId(int32_t nServerId);
		
		void runCancel();
		
		void setRoleItem(RoleItemPtr& nRoleItem);
		
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
