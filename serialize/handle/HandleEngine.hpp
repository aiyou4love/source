#pragma once

namespace cc {
	
	class HandleEngine : noncopyable
	{
	public:
		template<class T>
		void headSerialize(T& nSerialize, const char * nName)
		{
			if ( 0 == strcmp(configName(), nName) ) {
				nSerialize.template runMapStreamPtrs<string, HandleConfigPtr>(mHandleConfigs, "handleConfigs", "handleConfig");
			} else if ( 0 == strcmp(streamName(), nName) ) {
				nSerialize.template runMapStreamPtrs<int16_t, HandleCountPtr>(mHandleCounts, "handleCounts", "handleCount");
			} else {
				LOGE("[%s]%s", __METHOD__, nName);
			}
		}
		const char * streamName();
		const char * streamUrl();
		
		const char * configName();
		const char * configUrl();
		
		void addContext(IContextClone * nContextClone);
		
		void runPreinit();
		void runLoad();
		void runInit();
		void runEnd();
		void runStop();
		void runClear();
		
		static HandleEngine& instance();
		
		HandleEngine();
		~HandleEngine();
		
	private:
		map<string, HandleConfigPtr> mHandleConfigs;
		map<int16_t, HandleCountPtr> mHandleCounts;
		map<int16_t, HandlePtr> mHandles;
		
		static HandleEngine mHandleEngine;
	};
	
}
