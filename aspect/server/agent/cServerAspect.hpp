#pragma once

namespace cc {
	
#ifdef __AGENT__
	class cServerAspect : public ServerAspect
	{
	public:
		static cServerAspect& instance();
		
		cServerAspect();
		~cServerAspect();
		
	private:
		static cServerAspect mServerAspect;
	};
#endif
	
}
