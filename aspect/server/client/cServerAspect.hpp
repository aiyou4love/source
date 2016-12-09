#pragma once

namespace cc {
	
#ifdef __CLIENT__
	class cServerAspect : public ServerAspect
	{
	public:
		void runReward(int32_t nDoingId, EntityPtr& nEntity, ValuePtr& nValue);
		
		static cServerAspect& instance();
		
		cServerAspect();
		~cServerAspect();
		
	private:
		static cServerAspect mServerAspect;
	};
#endif
	
}
