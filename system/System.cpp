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
	
	TaskEngine& taskEngine_ = TaskEngine::instance();
	taskEngine_.runPreinit();
	
#ifdef __CLIENT__
	ActivityEngine& activityEngine_ = ActivityEngine::instance();
	activityEngine_.runPreinit();
#endif
}
