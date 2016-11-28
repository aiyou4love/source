#include "../../Engine.hpp"

namespace cc {
	
	SinkPtr * SinkMgr::beginIterator(int16_t nSinkType)
	{
		mIter = mSinks.begin();
		
		for ( ; mIter == mSinks.end(); ++mIter ) {
			SinkPtr * sink_ = mIter->second;
			if ( (*sink_)->getSinkType() == nSinkType ) {
				return sink_;
			}
		}
		return nullptr;
	}
	
	SinkPtr * SinkMgr::nextIterator(int16_t nSinkType)
	{
		mIter++;
		
		for ( ; mIter == mSinks.end(); ++mIter ) {
			SinkPtr * sink_ = mIter->second;
			if ( (*sink_)->getSinkType() == nSinkType ) {
				return sink_;
			}
		}
		return nullptr;
	}
	
	void SinkMgr::deleteSink(int16_t nSinkId)
	{
		mSinks.erase(nSinkId);
	}
	
	void SinkMgr::pushSink(SinkPtr& nSink)
	{
		mSinks[nSink->getSinkId()] = (&nSink);
	}
	
	SinkMgr::SinkMgr()
	{
		mSinks.clear();
	}
	
	SinkMgr::~SinkMgr()
	{
		mSinks.clear();
	}
	
}
