#pragma once

namespace cc {
	
	class SelectEngine : public IEngine
	{
	public:
		void runGlobTrigger(EntityPtr& nEntity, int16_t nSinkType, int32_t nValue);
		void runSelfTrigger(EntityPtr& nEntity, int16_t nSinkType, int32_t nValue);
		void runTrigger(EntityPtr& nEntity, int16_t nSinkType, int32_t nValue);
		
		void runIfSelect(EntityPtr& nEntity, ValuePtr& nValue);
		
		void initSink(int16_t nSinkId, EntityPtr& nEntity);
		
		template<class T>
		void headSerialize(T& nSerialize, const char * nName)
		{
			if ( 0 == strcmp(streamName(), nName) ) {
				nSerialize.template runMapStreamPtrs<int32_t, IfSelectPtr>(mIfSelects, "ifSelects", "ifSelect");
			} else if ( 0 == strcmp(globName(), nName) ) {
				nSerialize.template runMapStreamPtrs<int16_t, SinkPtr>(mGlobSinks, "sinks", "sink");
			} else if ( 0 == strcmp(selfName(), nName) ) {
				nSerialize.template runMapStreamPtrs<int16_t, SinkPtr>(mSelfSinks, "sinks", "sink");
			} else {
				LOGE("[%s]%s", __METHOD__, nName);
			}
		}
		const char * streamName();
		const char * streamUrl();
		
		const char * globName();
		const char * globUrl();
		
		const char * selfName();
		const char * selfUrl();
		
		void runPreinit();
		void runLuaApi();
		void runLoad();
		void runClear();
		
		static SelectEngine& instance();
		
		SelectEngine();
		~SelectEngine();
		
	private:
		map<int32_t, IfSelectPtr> mIfSelects;
		
		static SelectEngine mSelectEngine;
	};
	
}
