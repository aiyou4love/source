#pragma once

namespace cc {
	
	class IEngine : noncopyable
	{
	public:
		virtual void initSink(int16_t nSinkId, EntityPtr& nEntity);
		
		SinkPtr * beginIterator(int16_t nSinkType);
		SinkPtr * nextIterator(int16_t nSinkType);
		SinkPtr * findSink(int16_t nSinkId);
		
		IEngine();
		virtual ~IEngine();
		
	protected:
		typedef map<int16_t, SinkPtr>::iterator SinkIter;
		
		map<int16_t, SinkPtr> mGlobSinks;
		map<int16_t, SinkPtr> mSelfSinks;
		SinkIter mIter;
	};
	
}
