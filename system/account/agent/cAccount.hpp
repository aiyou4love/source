#pragma once

namespace cc {
	
#ifdef __AGENT__
	class cAccount : public Account
	{
	public:
		cAccount();
		~cAccount();
	};
	typedef SPTR<cAccount> cAccountPtr;
#endif
	
}
