#pragma once

namespace cc {
	
	class SinkMgr : noncopyable
	{
	public:
		Sink * beginIterator(int16_t nSinkType);
		Sink * nextIterator(int16_t nSinkType);
		
		void deleteSink(int16_t nSinkId);
		void pushSink(Sink * nSink);
		
		SinkMgr();
		virtual ~SinkMgr();
		
	protected:
		typedef map<int16_t, Sink *>::iterator SinkIter;
		
		map<int16_t, Sink *> mSinks;
		SinkIter mIter;
	};
	typedef SPTR<SinkMgr> SinkMgrPtr;
	
}
