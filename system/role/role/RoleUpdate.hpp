#pragma once

namespace cc {
	
	class RoleUpdate : public Context
	{
	public:
		void runContext(int64_t nTick);
		
		RoleUpdate();
		~RoleUpdate();
	};
	
}
