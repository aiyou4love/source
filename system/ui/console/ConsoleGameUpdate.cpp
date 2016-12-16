#include "../../System.hpp"

namespace cc {
	
#ifdef __CLIENT__
	void ConsoleGameUpdate::runContext(int64_t nTick)
	{
		ConsoleEngine& consoleEngine_ = ConsoleEngine::instance();
		consoleEngine_.runUpdateGame();
	}
	
	ConsoleGameUpdate::ConsoleGameUpdate()
	{
	}
	
	ConsoleGameUpdate::~ConsoleGameUpdate()
	{
	}
#endif
	
}
