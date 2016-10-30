#pragma once

namespace cc {
	
	class AspectEngine : noncopyable
	{
	public:
		bool runCondition(EntityPtr& nEntity, DoingPtr& nDoing, ValuePtr& nValue);
		void runReward(EntityPtr& nEntity, DoingPtr& nDoing, ValuePtr& nValue);
		void runEvent(int32_t nEventId, EntityPtr& nEntity, ValuePtr& nValue);
		
		void registerAspect(int32_t nAspectId, IAspect * nAspect);
		
		static AspectEngine& instance();
		
		AspectEngine();
		~AspectEngine();
		
	protected:
		map<int32_t, IAspect *> mAspects;
		
		static AspectEngine mAspectEngine;
	};
	
}
