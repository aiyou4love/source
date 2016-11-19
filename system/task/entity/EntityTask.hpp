#pragma once

namespace cc {
	
	class EntityTask : noncopyable
	{
	public:
		void pushTask(int16_t nTaskId);
		void popTask(int16_t nTaskId);
		
		void runInit(IntArray * nIntArray);
		
		EntityTask();
		~EntityTask();
		
	private:
		TaskAccept mTaskAccept;
		TaskFinish mTaskFinish;
	};
	typedef SPTR<EntityTask> EntityTaskPtr;
	
}
