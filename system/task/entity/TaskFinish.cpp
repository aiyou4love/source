#include "../../System.hpp"

namespace cc {
	
	void TaskFinish::pushTask(int16_t nTaskId)
	{
		mInt16Count.pushInt(nTaskId);
	}
	
	void TaskFinish::popTask(int16_t nTaskId)
	{
		mInt16Count.popInt(nTaskId);
	}
	
	bool TaskFinish::checkTask(int16_t nTaskId)
	{
		return mInt16Count.checkValue(nTaskId);
	}
	
	void TaskFinish::runInit(EntityPtr& nEntity)
	{
		CountEngine& countEngine_ = CountEngine::instance();
		countEngine_.initCount(&mInt16Count, nEntity, countName());
	}
	
	const char * TaskFinish::countName()
	{
		return "taskAccept";
	}
	
	TaskFinish::TaskFinish()
	{
	}
	
	TaskFinish::~TaskFinish()
	{
	}
	
}
