#pragma once

namespace cc {
	
	class TcpConnector : noncopyable
	{
	public:
		void runConnect(const char * nIp, const char * nPort, TcpConnectInfoPtr& nTcpConnectInfo);
		
	private:
		void handleConnectTimeout(const boost::system::error_code& nError);
		void handleConnect(const boost::system::error_code& nError);
		
		void initSelectId(TcpConnectInfoPtr& nTcpConnectInfo);
		void runSelectId(int32_t nSelectId);
		void runClear();
		void runClose();
		
	public:
		enum { connect_timeout = 120 };
		
		TcpConnector(int64_t nAppId, asio::io_service& nHandle);
		~TcpConnector();
		
	private:
		asio::deadline_timer mConnectTimer;
		
		IDispatch * mDispatch;
		TcpSession * mSession;
		
		int32_t mConnectErrorId;
		int32_t mTimeoutId;
		
		int64_t mAppId;
	};
	typedef SPTR<TcpConnector> TcpConnectorPtr;
	
}
