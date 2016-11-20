#include "../../System.hpp"

namespace cc {
	
	void SingleTask::pushTask(int16_t nIndex, int16_t nTaskId)
	{
		mInt16Count.setInt(nIndex, nTaskId);
	}
	
	void SingleTask::popTask(int16_t nIndex)
	{
		mInt16Count.setInt(nIndex, 0);
	}
	
	int16_t SingleTask::getTask(int16_t nIndex)
	{
		return mInt16Count.getInt(nIndex);
	}
	
	void SingleTask::runInit(EntityPtr& nEntity)
	{
		CountEngine& countEngine_ = CountEngine::instance();
		countEngine_.initCount(&mInt16Count, nEntity, countName());
	}
	
	const char * SingleTask::countName()
	{
		return "singleTask";
	}
	
	SingleTask::SingleTask()
	{
	}
	
	SingleTask::~SingleTask()
	{
	}
	
}
