#include "../../Engine.hpp"

namespace cc {
	
	void Reward::runReward(EntityPtr& nEntity, ValuePtr& nValue)
	{
		AspectEngine& aspectEngine_ = AspectEngine::instance();
		
		auto it = mDoings.begin();
		for ( ; it != mDoings.end(); ++it ) {
			DoingPtr& doing_ = it->second;
			aspectEngine_.runReward(nEntity, doing_, nValue);
		}
	}
	
	bool Reward::isDefault()
	{
		return ( (0 == mRewardId) || (mDoings.size() <= 0) );
	}
	
	int32_t Reward::getKey()
	{
		return mRewardId;
	}
	
	Reward::Reward()
		: mRewardId (0)
	{
		mDoings.clear();
	}
	
	Reward::~Reward()
	{
		mRewardId = 0;
		
		mDoings.clear();
	}
	
}
