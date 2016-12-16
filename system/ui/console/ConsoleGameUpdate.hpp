#pragma once

namespace cc {
	
#ifdef __CLIENT__
	class ConsoleGameUpdate : public Context
	{
	public:
		void runContext(int64_t nTick);
		
		ConsoleGameUpdate();
		~ConsoleGameUpdate();
	};
#endif
	
}
