#pragma once

namespace cc {
	
	class NetIpMgr : noncopyable
	{
	public:
		NetIpPtr * findNetIp(int16_t nAppType, int32_t nAppNo);
		NetIpPtr * findNetIp(int16_t nAppType);
		NetIpPtr * findNetIp(int64_t nAppId);
		NetIpPtr * findNetIp();
		
		template<class T>
		void headSerialize(T& nSerialize, const char * nName)
		{
			if ( 0 == strcmp(nName, netName()) ) {
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
		map<int64_t, NetIpPtr> mNetIps;
		
		static NetIpMgr mNetIpMgr;
	};
	
}
