#include "../System.hpp"

namespace cc {
	
	void EntityTask::runInit(EntityPtr& nEntity)
	{
		mTaskAccept.runInit(nEntity);
		mTaskFinish.runInit(nEntity);
	}
	
	EntityTask::EntityTask()
	{
	}
	
	EntityTask::~EntityTask()
	{
	}
	
}
