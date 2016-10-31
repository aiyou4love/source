#include "Dispatch.hpp"

using namespace cc;

void dispatchInit()
{
	systemInit();
	
	ApplicationEngine& applicationEngine_ = ApplicationEngine::instance();
	applicationEngine_.runPreinit();
}
