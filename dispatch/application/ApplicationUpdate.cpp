#include "../Engine.hpp"

namespace cc {
	
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
