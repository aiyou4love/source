#include "../System.hpp"

namespace cc {
	
	void ApplicationUpdate::initContext()
	{
		ApplicationEngine& applicationEngine_ = ApplicationEngine::instance();
		applicationEngine_.initUpdate();
	}
	
	void ApplicationUpdate::runContext(int64_t nTick)
	{
		ApplicationEngine& applicationEngine_ = ApplicationEngine::instance();
		applicationEngine_.runUpdate();
	}
	
	ApplicationUpdate::ApplicationUpdate()
	{
	}
	
	ApplicationUpdate::~ApplicationUpdate()
	{
	}
	
}
