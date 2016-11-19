#include "../Engine.hpp"

namespace cc {
	
	void ICount::runReset()
	{
		for (int16_t i = 0; i < N; ++i) {
			mValue[i] = 0;
		}
		(*mIntArray)->runDirty();
	}
	
	void ICount::runInit(IntArrayPtr& nIntArray, CountIndexPtr& nCountIndex)
	{
		int16_t begin_ = nCountIndex->getBegin();
		int16_t end_ = nCountIndex->getEnd();
		
		mValue = nIntArray->rangeInts(begin_, end_);
		mIntArray = (&nIntArray);
		N = end_ - begin_ + 1;
	}
	
	ICount::ICount()
		: mIntArray (nullptr)
		, mValue (nullptr)
		, N (0)
	{
	}
	
	ICount::~ICount()
	{
		mIntArray = nullptr;
		mValue = nullptr;
		N = 0;
	}
	
}
