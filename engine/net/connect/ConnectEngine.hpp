#pragma once

namespace cc {
	
	class ConnectEngine : noncopyable
	{
	public:
		void initConnect(int16_t nAppType, int32_t nAppNo);
		void initConnect(int16_t nAppType);
		
		void removeConnector(int64_t nAppId);
		
	private:
		void initConnect(NetIpPtr& nNetIp);
		
	public:
		template<class T>
		void headSerialize(T& nSerialize, const char * nName)
		{
			nSerialize.template runMapStreamPtrs<int16_t, ConnectInfoPtr>(mConnectInfos, "connectInfos", "connectInfo");
		}
		const char * streamName();
		const char * streamUrl();
		
		void runPreinit();
		void runLoad();
		void runStop();
		
		static ConnectEngine& instance();
		
		ConnectEngine();
		~ConnectEngine();
		
	private:
		map<int16_t, ConnectInfoPtr> mConnectInfos;
		
		map<int64_t, ConnectorPtr> mConnectors;
		mutex mMutex;
		
		static ConnectEngine mConnectEngine;
	};
	
}
