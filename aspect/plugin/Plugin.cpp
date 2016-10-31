#include "../Aspect.hpp"

namespace cc {
	
	void Plugin::runPlugin()
	{
		aspectInit();
		
		serializeStart();
	}
	Plugin mPlugin;
	
}
