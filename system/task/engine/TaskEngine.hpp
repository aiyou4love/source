#pragma once

namespace cc {
	
	class TaskEngine : noncopyable
	{
	public:
		void acceptTask(int16_t nTaskId, EntityPtr& nEntity);
		bool isAccept(int16_t nTaskId, EntityPtr& nEntity);
		void giveupTask(int16_t nTaskId, EntityPtr& nEntity);
		void finishTask(int16_t nTaskId, EntityPtr& nEntity);
		bool isFinish(int16_t nTaskId, EntityPtr& nEntity);
		void resetTask(int16_t nTaskId, EntityPtr& nEntity);
		
		void initEntity(EntityPtr& nEntity);
		
		template<class T>
		void headSerialize(T& nSerialize, const char * nName)
		{
			if ( 0 == strcmp(streamName(), nName) ) {
				nSerialize.template runMapStreamPtrs<int16_t, cTaskConfigPtr>(mTaskConfigs, "taskConfigs", "taskConfig");
			} else {
				LOGE("[%s]%s", __METHOD__, nName);
			}
		}
		const char * streamName();
		const char * streamUrl();
		
		void runPreinit();
		void runLoad();
		void runClear();
		
		static TaskEngine& instance();
		
		TaskEngine();
		~TaskEngine();
		
	private:
		map<int16_t, cTaskConfigPtr> mTaskConfigs;
		
		static TaskEngine mTaskEngine;
	};
	
}
