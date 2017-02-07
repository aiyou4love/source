#pragma once

namespace cc {
	
	class NetIpMgr : noncopyable
	{
	public:
		NetIp * findNetIp(int16_t nAppType, int32_t nAppNo);
		NetIp * findNetIp(int16_t nAppType);
		NetIp * findNetIp(int64_t nAppId);
		NetIp * findNetIp();
		
		void pushNetIp(NetIpPtr& nNetIp);
		
		template<class T>
		void headSerialize(T& nSerialize, const char * nName)
		{
			nSerialize.template runMapStreamPtrs<int64_t, NetIpPtr>(mNetIps, "mNetIps", "mNetIp");
		}
		
		const char * netName();
		const char * netUrl();
		
		void runPreinit();
		void runLoad();
		void runSave();
		void runClear();
		
		static NetIpMgr& instance();
		
		NetIpMgr();
		~NetIpMgr();
		
	private:
		map<int64_t, NetIpPtr> mNetIps;
		
		static NetIpMgr mNetIpMgr;
	};
	
}
