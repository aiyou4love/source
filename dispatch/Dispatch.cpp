#include "Dispatch.hpp"

using namespace cc;

void dispatchInit()
{
	systemInit();
	
	LOGI("[%s]1", __METHOD__);
	
	ApplicationEngine& applicationEngine_ = ApplicationEngine::instance();
	applicationEngine_.runPreinit();
	
	LOGI("[%s]2", __METHOD__);
}
