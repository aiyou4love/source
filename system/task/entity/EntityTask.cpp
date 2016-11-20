#include "../../System.hpp"

namespace cc {
	
	void EntityTask::acceptTask(int16_t nTaskId)
	{
		mTaskAccept.pushTask(nTaskId);
	}
	
	bool EntityTask::isAccept(int16_t nTaskId)
	{
		return mTaskAccept.checkTask(nTaskId);
	}
	
	void EntityTask::giveupTask(int16_t nTaskId)
	{
		mTaskAccept.popTask(nTaskId);
	}
	
	void EntityTask::finishTask(int16_t nTaskId)
	{
		mTaskFinish.pushTask(nTaskId);
	}
	
	bool EntityTask::isFinish(int16_t nTaskId)
	{
		return mTaskAccept.checkTask(nTaskId);
	}
	
	void EntityTask::resetTask(int16_t nTaskId)
	{
		mTaskFinish.popTask(nTaskId);
	}
	
	void EntityTask::finishDaily(int16_t nTaskId)
	{
		mDailyTask.pushTask(nTaskId);
	}
	
	bool EntityTask::isDaily(int16_t nTaskId)
	{
		return mTaskAccept.checkTask(nTaskId);
	}
	
	void EntityTask::resetDaily(int16_t nTaskId)
	{
		mDailyTask.popTask(nTaskId);
	}
	
	void EntityTask::finishSingle(int16_t nIndex, int16_t nTaskId)
	{
		mSingleTask.pushTask(nIndex, nTaskId);
	}
	
	int16_t EntityTask::getSingle(int16_t nIndex)
	{
		return mSingleTask.getTask(nIndex);
	}
	
	void EntityTask::resetSingle(int16_t nIndex)
	{
		mSingleTask.popTask(nIndex);
	}
	
	void EntityTask::runInit(EntityPtr& nEntity)
	{
		mTaskAccept.runInit(nEntity);
		mTaskFinish.runInit(nEntity);
		mDailyTask.runInit(nEntity);
		mSingleTask.runInit(nEntity);
	}
	
	EntityTask::EntityTask()
	{
	}
	
	EntityTask::~EntityTask()
	{
	}
	
}
