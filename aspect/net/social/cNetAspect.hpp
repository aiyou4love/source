#pragma once

namespace cc {
	
#ifdef __SOCIAL__
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
