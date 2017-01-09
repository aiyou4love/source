#pragma once

namespace cc {
	
#ifndef __CLIENT__
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
