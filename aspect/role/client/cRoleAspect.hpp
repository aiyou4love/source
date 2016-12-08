#pragma once

namespace cc {
	
#ifdef __CLIENT__
	class cRoleAspect : public RoleAspect
	{
	public:
		void runReward(int32_t nDoingId, EntityPtr& nEntity, ValuePtr& nValue);
		
		static cRoleAspect& instance();
		
		cRoleAspect();
		~cRoleAspect();
		
	private:
		static cRoleAspect mRoleAspect;
	};
#endif
	
}
