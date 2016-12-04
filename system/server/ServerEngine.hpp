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
				nSerialize.template runMapStreamPtrs<int32_t, ServerItemPtr>(mServerItems, "mServerList", "mServerItem");
				
				UpintEngine& upintEngine_ = UpintEngine::instance();
				upintEngine_.headSerialize(nSerialize, upintEngine_.streamName());
				upintEngine_.runSave();
			} else if ( 0 == strcmp(saveName(), nName) ) {
				nSerialize.template runMapStreamPtrs<int32_t, ServerItemPtr>(mServerItems, "mServerItems", "mServerItem");
			} else {
				LOGE("[%s]%s", __METHOD__, nName);
			}
		}
		const char * streamName();
		const char * streamUrl();
		
		const char * saveName();
		const char * saveUrl();
		
		static ServerEngine& instance();
		
		ServerEngine();
		~ServerEngine();
		
	private:
		map<int32_t, ServerItemPtr> mServerItems;
		
		static ServerEngine mServerEngine;
	};
	
}
