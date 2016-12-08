#pragma once

namespace cc {
	
#ifdef __AGENT__
	class cAccountAspect : public AccountAspect
	{
	public:
		static cAccountAspect& instance();
		
		cAccountAspect();
		~cAccountAspect();
		
	private:
		static cAccountAspect mAccountAspect;
	};
#endif
	
}
