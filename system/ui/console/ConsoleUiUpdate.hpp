#pragma once

namespace cc {
	
#ifdef __CLIENT__
	class ConsoleUiUpdate : public Context
	{
	public:
		void runContext(int64_t nTick);
		
		ConsoleUiUpdate();
		~ConsoleUiUpdate();
	};
#endif
	
}
