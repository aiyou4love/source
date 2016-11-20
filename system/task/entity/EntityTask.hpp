#pragma once

namespace cc {
	
	class EntityTask : public Property
	{
	public:
		void finishSingle(int16_t nIndex, int16_t nTaskId);
		int16_t getSingle(int16_t nIndex);
		void resetSingle(int16_t nIndex);
		
		void acceptTask(int16_t nTaskId);
		bool isAccept(int16_t nTaskId);
		void giveupTask(int16_t nTaskId);
		
		void finishTask(int16_t nTaskId);
		bool isFinish(int16_t nTaskId);
		void resetTask(int16_t nTaskId);
		
		void finishDaily(int16_t nTaskId);
		bool isDaily(int16_t nTaskId);
		void resetDaily(int16_t nTaskId);
		
		void runInit(EntityPtr& nEntity);
		
		EntityTask();
		~EntityTask();
		
	private:
		TaskAccept mTaskAccept;
		TaskFinish mTaskFinish;
		DailyTask mDailyTask;
		SingleTask mSingleTask;
	};
	typedef SPTR<EntityTask> EntityTaskPtr;
	
}
