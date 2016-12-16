#include "../../System.hpp"

namespace cc {
	
#ifdef __CLIENT__
	void ConsoleUiUpdate::runContext(int64_t nTick)
	{
		ConsoleEngine& consoleEngine_ = ConsoleEngine::instance();
		consoleEngine_.runUpdateUi();
	}
	
	ConsoleUiUpdate::ConsoleUiUpdate()
	{
	}
	
	ConsoleUiUpdate::~ConsoleUiUpdate()
	{
	}
#endif
	
}
