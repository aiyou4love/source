#pragma once

namespace cc {
	
#ifdef __CLIENT__
	class ConsoleInput : public Context
	{
	public:
		void runContext(int64_t nTick);
	};
#endif
	
}
