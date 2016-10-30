#pragma once

namespace cc {
	
	class ApplicationEngine : public IDispatch
	{
	public:
		void pushValue(ValuePtr& nValue);
		
		template<class T>
		void headSerialize(T& nSerialize, const char * nName)
		{
			nSerialize.template runNumbers<vector<int32_t>, int32_t>(mStartIds, "startIds", "startId");
		}
		const char * streamName();
		const char * streamUrl();
		
		void runPreinit();
		void runLoad();
		void runInit();
		void runStart();
		void runUpdate();
		void runClear();
		
		static ApplicationEngine& instance();
		
		ApplicationEngine();
		~ApplicationEngine();
		
	private:
		static ApplicationEngine mApplicationEngine;
		
		vector<int32_t> mStartIds;
		EntityPtr mEntity;
	};
	
}
