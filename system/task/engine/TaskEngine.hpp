#pragma once

namespace cc {
	
	class TaskEngine : noncopyable
	{
	public:
		template<class T>
		void headSerialize(T& nSerialize, const char * nName)
		{
			if ( 0 == strcmp(streamName(), nName) ) {
				
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
		static TaskEngine mTaskEngine;
		
		int16_t mFinishCount;
		int16_t mFinishIndex;
		
		int16_t mAcceptCount;
		int16_t mAcceptIndex;
	};
	
}
