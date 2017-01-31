#pragma once

namespace cc {
	
#ifndef __CLIENT__
	class cServerTime : public ServerTime
	{
	public:
		int64_t getServerTime();
		
		void runPreinit();
		
		static cServerTime& instance();
		
		cServerTime();
		~cServerTime();
		
	private:
		static cServerTime mServerTime;
	};
#endif
	
}
