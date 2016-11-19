#include "../System.hpp"

namespace cc {
	
	void TaskAccept::pushTask(int16_t nTaskId)
	{
		mInt16Count.pushInt(nTaskId);
	}
	
	void TaskAccept::popTask(int16_t nTaskId)
	{
		mInt16Count.popInt(nTaskId);
	}
	
	void TaskAccept::runInit(EntityPtr& nEntity)
	{
		CountEngine& countEngine_ = CountEngine::instance();
		countEngine_.initCount(&mInt16Count, nEntity, countName());
	}
	
	const char * TaskAccept::countName()
	{
		return "taskAccept";
	}
	
	TaskAccept::TaskAccept()
	{
	}
	
	TaskAccept::~TaskAccept()
	{
	}
	
}
