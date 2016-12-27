#include "System.hpp"

using namespace cc;

void systemInit()
{
	engineInit();
	
	LOGI("[%s]1", __METHOD__);
	
	UiManager::instance();
	
	LOGI("[%s]2", __METHOD__);
	
#ifdef __CLIENT__
	ConsoleEngine& consoleEngine_ = ConsoleEngine::instance();
	consoleEngine_.runPreinit();
#endif
	
	LOGI("[%s]3", __METHOD__);
	
	ServerEngine& serverEngine_ = ServerEngine::instance();
	serverEngine_.runPreinit();
	
	LOGI("[%s]4", __METHOD__);
	
	TimeEngine& timeEngine_ = TimeEngine::instance();
	timeEngine_.runPreinit();
	
	LOGI("[%s]5", __METHOD__);
	
	cServerTime& serverTime_ = cServerTime::instance();
	serverTime_.runPreinit();
	
	LOGI("[%s]6", __METHOD__);
	
	TaskEngine& taskEngine_ = TaskEngine::instance();
	taskEngine_.runPreinit();
	
	LOGI("[%s]7", __METHOD__);
	
#ifdef __CLIENT__
	ActivityEngine& activityEngine_ = ActivityEngine::instance();
	activityEngine_.runPreinit();
	
	RoleEngine& roleEngine_ = RoleEngine::instance();
	roleEngine_.runPreinit();
#endif
	
	LOGI("[%s]8", __METHOD__);
	
}
