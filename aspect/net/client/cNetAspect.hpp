#pragma once

namespace cc {
	
#ifdef __CLIENT__
	class cNetAspect : public NetAspect
	{
	public:
		void runReward(int32_t nDoingId, EntityPtr& nEntity, ValuePtr& nValue);
		
		int8_t getIdleAgent(int32_t nServerId);
		
		static cNetAspect& instance();
		
		cNetAspect();
		~cNetAspect();
		
	private:
		static cNetAspect mNetAspect;
	};
#endif
	
}
