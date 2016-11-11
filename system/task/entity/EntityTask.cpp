#include "../System.hpp"

namespace cc {
	
	void TodayFinish::pushTask(int16_t nTaskId)
	{
		mBitCount.runTrue(nTaskId);
	}
	
	void TodayFinish::popTask(int16_t nTaskId)
	{
		mBitCount.runReset(nTaskId);
	}
	
	void TodayFinish::runInit(IntArray * nIntArray)
	{
		int16_t begin_ = 0;
		int16_t end_ = 0;
		mBitCount.runInit(nIntArray, begin_, end_);
	}
	
	TodayFinish::TodayFinish()
	{
	}
	
	TodayFinish::~TodayFinish()
	{
	}
	
}
