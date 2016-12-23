#pragma once

namespace cc {
	
	class ApplicationUpdate : public Context
	{
	public:
		void runContext(int64_t nTick);
		void initContext();
		
		ApplicationUpdate();
		~ApplicationUpdate();
	};
	
}
