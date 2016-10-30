#pragma once

namespace cc {
	
	class SelectEngine : noncopyable
	{
	public:
		void runIfSelect(EntityPtr& nEntity, ValuePtr& nValue);
				
		template<class T>
		void headSerialize(T& nSerialize, const char * nName)
		{
			nSerialize.template runMapStreamPtrs<int32_t, IfSelectPtr>(mIfSelects, "ifSelects", "ifSelect");
		}
		const char * streamName();
		const char * streamUrl();
		
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
