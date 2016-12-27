#pragma once

namespace cc {
	
#ifdef __CLIENT__
	class ServerEngine : noncopyable
	{
	public:
		void pushServerItem(ServerItemPtr& nServerItem);
		const char * getServerName(int32_t nServerId);
		void pushServerInfo(ServerInfoPtr& nServerInfo);
		string getServerInfos();
		
		template<class T>
		void headSerialize(T& nSerialize, const char * nName)
		{
			if ( 0 == strcmp(saveName(), nName) ) {
				nSerialize.template runMapStreamPtrs<int32_t, ServerInfoPtr>(mServerInfos, "mServerInfos", "mServerInfo");
				nSerialize.template runMapStreamPtrs<int32_t, ServerItemPtr>(mServerItems, "mServerList", "mServerItem");
			} else if ( 0 == strcmp(streamName(), nName) ) {
				nSerialize.template runMapStreamPtrs<int32_t, ServerItemPtr>(mServerItems, "mServerList", "mServerItem");
			} else {
				LOGE("[%s]%s", __METHOD__, nName);
			}
		}
		const char * streamName();
		const char * streamUrl();
		
		const char * saveName();
		const char * saveUrl();
		
		void runPreinit();
		void runLoad();
		void runSave();
		void runClear();
		
		static ServerEngine& instance();
		
		ServerEngine();
		~ServerEngine();
		
	private:
		map<int32_t, ServerInfoPtr> mServerInfos;
		map<int32_t, ServerItemPtr> mServerItems;
		
		static ServerEngine mServerEngine;
	};
#endif
	
}
