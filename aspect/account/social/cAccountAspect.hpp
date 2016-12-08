#pragma once

namespace cc {
	
#ifdef __SOCIAL__
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
