#include "../Aspect.hpp"

namespace cc {
	
	void Plugin::runPlugin()
	{
		LOGI("[%s]", __METHOD__);
		
		aspectInit();
		
		serializeStart();
	}
	Plugin mPlugin;
	
}
