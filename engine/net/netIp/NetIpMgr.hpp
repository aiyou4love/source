#pragma once

namespace cc {
	
	class NetIpMgr : noncopyable
	{
	public:
		NetInfoPtr * findNetInfo(int32_t nServerId);
		
	private:
		int32_t findAppNo(int32_t nServerId);
		
	public:
		NetIpPtr * findNetIp(int16_t nAppType, int32_t nAppNo);
		NetIpPtr * findNetIp(int16_t nAppType);
		NetIpPtr * findNetIp(int64_t nAppId);
		NetIpPtr * findNetIp();
		
		template<class T>
		void headSerialize(T& nSerialize, const char * nName)
		{
			if ( 0 == strcmp(nName, netName()) ) {
				nSerialize.template runMapStreamPtrs<int32_t, NetInfoPtr>(mNetInfos, "mNetInfos", "mNetInfo");
				nSerialize.template runMapStreamPtrs<int32_t, NetNoPtr>(mNetNos, "mNetNos", "mNetNo");
				nSerialize.template runMapStreamPtrs<int64_t, NetIpPtr>(mNetIps, "mNetIps", "mNetIp");
				
				UpintEngine& upintEngine_ = UpintEngine::instance();
				upintEngine_.headSerialize(nSerialize, upintEngine_.streamName());
				upintEngine_.runSave();
			} else {
				LOGE("[%s]%s", __METHOD__, nName);
			}
		}
		
		const char * netName();
		const char * netUrl();
		
		void runPreinit();
		void runInit();
		void runClear();
		
		void initNet();
		bool isInit();
		
		static NetIpMgr& instance();
		
		NetIpMgr();
		~NetIpMgr();
		
	private:
		map<int32_t, NetInfoPtr> mNetInfos;
		map<int32_t, NetNoPtr> mNetNos;
		map<int64_t, NetIpPtr> mNetIps;
		
		static NetIpMgr mNetIpMgr;
	};
	
}
