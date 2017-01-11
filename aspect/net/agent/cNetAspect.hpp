#pragma once

namespace cc {
	
#ifdef __AGENT__
	class cNetAspect : public NetAspect
	{
	public:
		void runReward(int32_t nDoingId, EntityPtr& nEntity, ValuePtr& nValue);
		
		static cNetAspect& instance();
		
		cNetAspect();
		~cNetAspect();
		
	private:
		static cNetAspect mNetAspect;
	};
#endif
	
}
