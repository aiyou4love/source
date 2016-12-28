#include "../../System.hpp"

namespace cc {
	
	void AccountUpdate::runContext(int64_t nTick)
	{
		cAccountEngine& accountEngine_ = cAccountEngine::instance();
		accountEngine_.runUpdate();
	}
	
	AccountUpdate::AccountUpdate()
	{
	}
	
	AccountUpdate::~AccountUpdate()
	{
	}
	
}
