#pragma once

namespace cc {
	
#ifdef __CLIENT__
	class ActivityEngine : noncopyable
	{
	public:
		template<class T>
		void headSerialize(T& nSerialize, const char * nName)
		{
			if ( 0 == strcmp(streamName(), nName) ) {
				nSerialize.template runMapStreamPtrs<int16_t, ActivityConfigPtr>(mActivityConfigs, "activityConfigs", "activityConfigs");
			} else {
				LOGE("[%s]%s", __METHOD__, nName);
			}
		}
		const char * streamName();
		const char * streamUrl();
		
		void runPreinit();
		void runLoad();
		void runClear();
		
		static ActivityEngine& instance();
		
		ActivityEngine();
		~ActivityEngine();
		
	private:
		map<int16_t, ActivityConfigPtr> mActivityConfigs;
		
		static ActivityEngine mActivityEngine;
	};
#endif
	
}
