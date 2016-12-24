#include "../Aspect.hpp"

namespace cc {
	
	void Plugin::runPlugin()
	{
		aspectInit();
		
		LOGI("[%s]", __METHOD__);
		
		serializeStart();
	}
	Plugin mPlugin;
	
}
