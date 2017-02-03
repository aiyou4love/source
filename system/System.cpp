#include "System.hpp"

using namespace cc;

void systemInit()
{
	engineInit();
	
	LOGI("[%s]1", __METHOD__);
	
	UiManager::instance();
	
#ifdef __CLIENT__
	ConsoleEngine& consoleEngine_ = ConsoleEngine::instance();
	consoleEngine_.runPreinit();
#endif
	
	ServerEngine& serverEngine_ = ServerEngine::instance();
	serverEngine_.runPreinit();
	
	TaskEngine& taskEngine_ = TaskEngine::instance();
	taskEngine_.runPreinit();
	
#ifdef __CLIENT__
	ActivityEngine& activityEngine_ = ActivityEngine::instance();
	activityEngine_.runPreinit();
	
	cRoleList& roleList_ = cRoleList::instance();
	roleList_.runPreinit();
#endif
	
	cRoleEngine& roleEngine_ = cRoleEngine::instance();
	roleEngine_.runPreinit();
	
	ApplicationEngine& applicationEngine_ = ApplicationEngine::instance();
	applicationEngine_.runPreinit();
	
#if ( (defined __CLIENT__) || (defined __AGENT__) )
	cAccountEngine& accountEngine_ = cAccountEngine::instance();
	accountEngine_.runPreinit();
#endif
	
}
