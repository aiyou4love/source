#pragma once

namespace cc {
	
#ifdef __SOCIAL__
	class cAccount : public Account
	{
	public:
		cAccount();
		~cAccount();
	};
	typedef SPTR<cAccount> cAccountPtr;
#endif
	
}
