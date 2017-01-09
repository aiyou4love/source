#pragma once

namespace cc {
	
#ifndef __CLIENT__
	class ServerEngine : noncopyable
	{
	public:
		template<class T>
		void headSerialize(T& nSerialize, const char * nName)
		{
			if ( 0 == strcmp(nName, streamName()) ) {
				nSerialize.template runMapStreamPtrs<int32_t, ServerInfoPtr>(mServerInfos, "mServerInfos", "mServerInfo");
				nSerialize.template runMapStreamPtrs<int32_t, ServerItemPtr>(mServerItems, "mServerList", "mServerItem");
				
				NetIpMgr& netIpMgr_ = NetIpMgr::instance();
				netIpMgr_.headSerialize(nSerialize, netIpMgr_.netName());
				netIpMgr_.runSave();
			} else if ( 0 == strcmp(saveName(), nName) ) {
				nSerialize.template runMapStreamPtrs<int32_t, ServerInfoPtr>(mServerInfos, "mServerInfos", "mServerInfo");
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
		void runInit();
		void runSave();
		void runClear();
		
		static ServerEngine& instance();
		
		ServerEngine();
		~ServerEngine();
		
	private:
		map<int32_t, ServerInfoPtr> mServerInfos;
		map<int32_t, ServerItemPtr> mServerItems;
		
		int64_t mUpdateTime;
		
		static ServerEngine mServerEngine;
	};
#endif
	
}
