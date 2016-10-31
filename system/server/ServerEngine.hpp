#pragma once

namespace cc {
	
	class ServerEngine : noncopyable
	{
	public:
		void pushServerItem(ServerItemPtr& nServerItem);
		string getServerName(int32_t nServerId);
		string getServerInfos();
		
		void runPreinit();
		void runLoad();
		void runInit();
		void runSave();
		void runClear();
		
		void initServer();
		bool isInit();
		
		template<class T>
		void headSerialize(T& nSerialize, const char * nName)
		{
			if ( 0 == strcmp(streamName(), nName) ) {
				nSerialize.template runMapStreamPtrs<int32_t, ServerItemPtr>(mServerItems, "serverItems", "serverItem");
				
				UpintEngine& upintEngine_ = UpintEngine::instance();
				upintEngine_.headSerialize(nSerialize, nName);
				upintEngine_.runSave();
			} else {
				LOGE("[%s]%s", __METHOD__, nName);
			}
		}
		const char * streamName();
		const char * streamUrl();
		
		static ServerEngine& instance();
		
		ServerEngine();
		~ServerEngine();
		
	private:
		map<int32_t, ServerItemPtr> mServerItems;
		
		static ServerEngine mServerEngine;
	};
	
}
