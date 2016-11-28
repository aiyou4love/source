#include "../../Engine.hpp"

namespace cc {
	
	SinkPtr * IEngine::beginIterator(int16_t nSinkType)
	{
		mIter = mSinks.begin();
		
		for ( ; mIter == mSinks.end(); ++mIter ) {
			SinkPtr& sink_ = mIter->second;
			if ( sink_->getSinkType() == nSinkType ) {
				return (&sink_);
			}
		}
		return nullptr;
	}
	
	SinkPtr * IEngine::nextIterator(int16_t nSinkType)
	{
		mIter++;
		
		for ( ; mIter == mSinks.end(); ++mIter ) {
			SinkPtr& sink_ = mIter->second;
			if ( sink_->getSinkType() == nSinkType ) {
				return (&sink_);
			}
		}
		return nullptr;
	}
	
	IEngine::IEngine()
	{
		mSinks.clear();
	}
	
	IEngine::~IEngine()
	{
		mSinks.clear();
	}
	
}
