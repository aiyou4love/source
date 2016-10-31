#include "../../System.hpp"

namespace cc {
	
	void ConsoleUpdate::runContext(int64_t nTick)
	{
		ConsoleEngine& consoleEngine_ = ConsoleEngine::instance();
		consoleEngine_.runCommandArgs();
	}
	
	ConsoleUpdate::ConsoleUpdate()
	{
		
	}
	
	ConsoleUpdate::~ConsoleUpdate()
	{
		
	}
	
}
