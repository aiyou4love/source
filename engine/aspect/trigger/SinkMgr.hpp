#pragma once

namespace cc {
	
	class SinkMgr : noncopyable
	{
	public:
		SinkPtr * beginIterator(int16_t nSinkType);
		SinkPtr * nextIterator(int16_t nSinkType);
		
		void deleteSink(int16_t nSinkId);
		void pushSink(SinkPtr& nSink);
		
		SinkMgr();
		virtual ~SinkMgr();
		
	protected:
		typedef map<int16_t, SinkPtr *>::iterator SinkIter;
		
		map<int16_t, SinkPtr *> mSinks;
		SinkIter mIter;
	};
	typedef SPTR<SinkMgr> SinkMgrPtr;
	
}
