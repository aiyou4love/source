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
	
	void TaskFinish::runInit(EntityPtr& nEntity)
	{
		CountEngine& countEngine_ = CountEngine::instance();
		countEngine_.initCount(&mBitCount, nEntity, countName());
	}
	
	const char * TaskFinish::countName()
	{
		return "taskFinish";
	}
	
	TaskFinish::TaskFinish()
	{
	}
	
	TaskFinish::~TaskFinish()
	{
	}
	
}
