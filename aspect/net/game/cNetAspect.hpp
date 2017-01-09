#pragma once

namespace cc {
	
#ifdef __GAME__
	class cNetAspect : public NetAspect
	{
	public:
		static cNetAspect& instance();
		
		cNetAspect();
		~cNetAspect();
		
	private:
		static cNetAspect mNetAspect;
	};
#endif
	
}
