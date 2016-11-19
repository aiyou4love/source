#pragma once

namespace cc {
	
	class TaskEngine : noncopyable
	{
	public:
		template<class T>
		void headSerialize(T& nSerialize, const char * nName)
		{
			if ( 0 == strcmp(streamName(), nName) ) {
				nSerialize.template runMapStreamPtrs<int16_t, TaskConfigPtr>(mTaskConfigs, "taskConfigs", "taskConfig");
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
		map<int16_t, TaskConfigPtr> mTaskConfigs;
		
		static TaskEngine mTaskEngine;
	};
	
}
