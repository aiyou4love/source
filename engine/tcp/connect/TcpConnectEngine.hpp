#pragma once

namespace cc {
	
	class TcpConnectEngine : noncopyable
	{
	public:
		void initConnect(int16_t nAppType, int32_t nAppNo);
		void initConnect(int16_t nAppType);
		void initConnect(int64_t nAppId);
		
		void removeConnector(int64_t nAppId);
		
	private:
		void initConnect(NetIp * nNetIp, bool nReconnect);
		
	public:
		template<class T>
		void headSerialize(T& nSerialize, const char * nName)
		{
			nSerialize.template runMapStreamPtrs<int16_t, TcpConnectInfoPtr>(mConnectInfos, "connectInfos", "connectInfo");
		}
		const char * streamName();
		const char * streamUrl();
		
		void runPreinit();
		void runLoad();
		void runStop();
		
		static TcpConnectEngine& instance();
		
		TcpConnectEngine();
		~TcpConnectEngine();
		
	private:
		map<int16_t, TcpConnectInfoPtr> mConnectInfos;
		
		map<int64_t, TcpConnectorPtr> mConnectors;
		mutex mMutex;
		
		static TcpConnectEngine mTcpConnectEngine;
	};
	
}
