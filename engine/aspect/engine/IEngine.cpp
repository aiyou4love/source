#include "../../Engine.hpp"

namespace cc {
	
	void IEngine::initSink(int16_t nSinkId, EntityPtr& nEntity)
	{
		
	}
	
	Sink * IEngine::beginIterator(int16_t nSinkType)
	{
		mIter = mGlobSinks.begin();
		
		for ( ; mIter != mGlobSinks.end(); ++mIter ) {
			SinkPtr& sink_ = mIter->second;
			if ( sink_->getSinkType() == nSinkType ) {
				return ( sink_.get() );
			}
		}
		return nullptr;
	}
	
	Sink * IEngine::nextIterator(int16_t nSinkType)
	{
		mIter++;
		
		for ( ; mIter != mGlobSinks.end(); ++mIter ) {
			SinkPtr& sink_ = mIter->second;
			if ( sink_->getSinkType() == nSinkType ) {
				return ( sink_.get() );
			}
		}
		return nullptr;
	}
	
	Sink * IEngine::findSink(int16_t nSinkId)
	{
		auto it = mSelfSinks.find(nSinkId);
		if ( it == mSelfSinks.end() ) {
			LOGE("[%s]%d", __METHOD__, nSinkId);
			return nullptr;
		}
		SinkPtr& sink_ = it->second;
		return ( sink_.get() );
	}
	
	IEngine::IEngine()
	{
		mGlobSinks.clear();
		mSelfSinks.clear();
	}
	
	IEngine::~IEngine()
	{
		mGlobSinks.clear();
		mSelfSinks.clear();
	}
	
}
