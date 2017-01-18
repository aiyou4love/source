#pragma once

namespace cc {
	
#ifdef __WINDOW__
	class Dump : noncopyable
	{
	public:
		void runPreinit();
		
		static Dump& instance();
		
		Dump();
		~Dump();
		
	private:
		static Dump mDump;
	};
#endif
	
}
