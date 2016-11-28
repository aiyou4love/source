#pragma once

namespace cc {
	
	class SelectEngine : public IEngine
	{
	public:
		void runGlobTrigger(EntityPtr& nEntity, int16_t nSinkType, int32_t nValue);
		void runSelfTrigger(EntityPtr& nEntity, int16_t nSinkType, int32_t nValue);
		void runTrigger(EntityPtr& nEntity, int16_t nSinkType, int32_t nValue);
		
		void runIfSelect(EntityPtr& nEntity, ValuePtr& nValue);
		
		template<class T>
		void headSerialize(T& nSerialize, const char * nName)
		{
			if ( 0 == strcmp(streamName(), nName) ) {
				nSerialize.template runMapStreamPtrs<int32_t, IfSelectPtr>(mIfSelects, "ifSelects", "ifSelect");
			} else if ( 0 == strcmp(sinkName(), nName) ) {
				nSerialize.template runMapStreamPtrs<int16_t, SinkPtr>(mSinks, "sinks", "sink");
			} else {
				LOGE("[%s]%s", __METHOD__, nName);
			}
		}
		const char * streamName();
		const char * streamUrl();
		
		const char * sinkName();
		const char * sinkUrl();
		
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
