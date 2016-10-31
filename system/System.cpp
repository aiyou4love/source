#include "System.hpp"

using namespace cc;

void systemInit()
{
	engineInit();
	
	UiManager::instance();
	
	ConsoleEngine& consoleEngine_ = ConsoleEngine::instance();
	consoleEngine_.runPreinit();
	
	ServerEngine& serverEngine_ = ServerEngine::instance();
	serverEngine_.runPreinit();
	
	TimeEngine& timeEngine_ = TimeEngine::instance();
	timeEngine_.runPreinit();
	
	cServerTime& serverTime_ = cServerTime::instance();
	serverTime_.runPreinit();
}
