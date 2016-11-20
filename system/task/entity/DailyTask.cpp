#include "../../System.hpp"

namespace cc {
	
	void DailyTask::pushTask(int16_t nTaskId)
	{
		mInt16Count.pushInt(nTaskId);
	}
	
	void DailyTask::popTask(int16_t nTaskId)
	{
		mInt16Count.popInt(nTaskId);
	}
	
	bool DailyTask::checkTask(int16_t nTaskId)
	{
		return mInt16Count.checkValue(nTaskId);
	}
	
	void DailyTask::runInit(EntityPtr& nEntity)
	{
		CountEngine& countEngine_ = CountEngine::instance();
		countEngine_.initCount(&mInt16Count, nEntity, countName());
	}
	
	const char * DailyTask::countName()
	{
		return "dailyTask";
	}
	
	DailyTask::DailyTask()
	{
	}
	
	DailyTask::~DailyTask()
	{
	}
	
}
