#pragma once

namespace cc {
	
	class ServerEngine : noncopyable
	{
	public:
		void pushServerItem(ServerItemPtr& nServerItem);
		string getServerName(int32_t nServerId);
		string getServerInfos();
		
		template<class T>
		void headSerialize(T& nSerialize, const char * nName)
		{
			nSerialize.template runMapStreamPtrs<int32_t, ServerItemPtr>(mServerItems, "mServerList", "mServerItem");
		}
		const char * streamName();
		const char * streamUrl();
		
		void runPreinit();
		void runLoad();
		void runInit();
		void runSave();
		void runClear();
		
		void initServer();
		bool isInit();
		
		static ServerEngine& instance();
		
		ServerEngine();
		~ServerEngine();
		
	private:
		map<int32_t, ServerInfoPtr> mServerInfos;
		map<int32_t, ServerItemPtr> mServerItems;
		
		static ServerEngine mServerEngine;
	};
	
}
