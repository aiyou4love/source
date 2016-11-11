#include "../System.hpp"

namespace cc {
	
	void TaskFinish::pushTask(int16_t nTaskId)
	{
		mBitCount.runTrue(nTaskId);
	}
	
	void TaskFinish::popTask(int16_t nTaskId)
	{
		mBitCount.runReset(nTaskId);
	}
	
	void TaskFinish::runInit(IntArray * nIntArray)
	{
		int16_t begin_ = 0;
		int16_t end_ = 0;
		mBitCount.runInit(nIntArray, begin_, end_);
	}
	
	TaskFinish::TaskFinish()
	{
	}
	
	TaskFinish::~TaskFinish()
	{
	}
	
}
