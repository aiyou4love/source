#pragma once

namespace cc {
	
	class IEngine : noncopyable
	{
	public:
		SinkPtr * beginIterator(int16_t nSinkType);
		SinkPtr * nextIterator(int16_t nSinkType);
		
		IEngine();
		virtual ~IEngine();
		
	protected:
		typedef map<int16_t, SinkPtr>::iterator SinkIter;
		
		map<int16_t, SinkPtr> mSinks;
		SinkIter mIter;
	};
	
}
