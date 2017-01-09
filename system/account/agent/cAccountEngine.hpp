#pragma once

namespace cc {
	
#ifdef __AGENT__
	class cAccountEngine : public AccountEngine
	{
	public:
		void runPreinit();
		
		static cAccountEngine& instance();
		
		cAccountEngine();
		~cAccountEngine();
		
	private:
		static cAccountEngine mAccountEngine;
	};
#endif
	
}
