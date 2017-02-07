#pragma once

namespace cc {
	
	class Connector : noncopyable
	{
	public:
		void runConnect(const char * nIp, const char * nPort, ConnectInfoPtr& nConnectInfo);
		
	private:
		void handleConnectTimeout(const boost::system::error_code& nError);
		void handleConnect(const boost::system::error_code& nError);
		
		void initSelectId(ConnectInfoPtr& nConnectInfo);
		void runSelectId(int32_t nSelectId);
		void runClear();
		void runClose();
		
	public:
		enum { connect_timeout = 120 };
		
		Connector(int64_t nAppId, asio::io_service& nHandle);
		~Connector();
		
	private:
		asio::deadline_timer mConnectTimer;
		
		IDispatch * mDispatch;
		Session * mSession;
		
		int32_t mConnectErrorId;
		int32_t mTimeoutId;
		
		int64_t mAppId;
	};
	typedef SPTR<Connector> ConnectorPtr;
	
}
