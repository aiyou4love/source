#pragma once

namespace cc {
	
	class ConsoleUpdate : public Context
	{
	public:
		void runContext(int64_t nTick);
		
		ConsoleUpdate();
		~ConsoleUpdate();
	};
	
}
