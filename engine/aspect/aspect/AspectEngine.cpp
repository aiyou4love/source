#include "../../Engine.hpp"

namespace cc {
	
	bool AspectEngine::runCondition(EntityPtr& nEntity, DoingPtr& nDoing, ValuePtr& nValue)
	{
		int32_t aspectId_= nDoing->getAspectId();
		int16_t doingType_= nDoing->getDoingType();
		int32_t doingId_= nDoing->getDoingId();
		if ( EdoingType::mCondition != doingType_ ) {
			LOGE("[%s]%d,%d", __METHOD__, aspectId_, doingId_);
			return false;
		}
		auto it = mAspects.find(aspectId_);
		if ( it == mAspects.end() ) {
			LOGE("[%s]%d", __METHOD__, aspectId_);
			return false;
		}
		IAspect * aspect_ = it->second;
		return aspect_->runCondition(doingId_, nEntity, nValue);
	}
	
	void AspectEngine::runReward(EntityPtr& nEntity, DoingPtr& nDoing, ValuePtr& nValue)
	{
		int32_t aspectId_= nDoing->getAspectId();
		int16_t doingType_= nDoing->getDoingType();
		int32_t doingId_= nDoing->getDoingId();
		if ( EdoingType::mCondition == doingType_ ) {
			LOGE("[%s]%d,%d", __METHOD__, aspectId_, doingId_);
			return;
		}
		if ( EdoingType::mEvent == doingType_ ) {
			this->runEvent(doingId_, nEntity, nValue);
			return;
		}
		auto it = mAspects.find(aspectId_);
		if ( it == mAspects.end() ) {
			LOGE("[%s]%d", __METHOD__, aspectId_);
			return;
		}
		IAspect * aspect_ = it->second;
		return aspect_->runReward(doingId_, nEntity, nValue);
	}
	
	void AspectEngine::runEvent(int32_t nEventId, EntityPtr& nEntity, ValuePtr& nValue)
	{
		auto it = mAspects.begin();
		for ( ; it != mAspects.end(); ++it ) {
			IAspect * aspect_ = it->second;
			aspect_->runEvent(nEventId, nEntity, nValue);
		}
	}
	
	void AspectEngine::registerAspect(int32_t nAspectId, IAspect * nAspect)
	{
		auto it = mAspects.find(nAspectId);
		if ( it != mAspects.end() ) {
			LOGE("[%s]%d", __METHOD__, nAspectId);
			return;
		}
		mAspects[nAspectId] = nAspect;
	}
	
	AspectEngine& AspectEngine::instance()
	{
		return mAspectEngine;
	}
	
	AspectEngine::AspectEngine()
	{
		mAspects.clear();
	}
	
	AspectEngine::~AspectEngine()
	{
		mAspects.clear();
	}
	
	AspectEngine AspectEngine::mAspectEngine;
	
}
