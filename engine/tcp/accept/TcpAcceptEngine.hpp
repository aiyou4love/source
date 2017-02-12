#pragma once

namespace cc {
	
#ifndef __CLIENT__
	class TcpAcceptEngine : noncopyable
	{
	public:
		void initAccept();
		
	private:
		void handleAccept(const boost::system::error_code& nError);
		void startAccept();
		
	public:
		void runPreinit();
		void runStop();
		
		static TcpAcceptEngine& instance();
		
		TcpAcceptEngine();
		~TcpAcceptEngine();
		
	private:
		SPTR<asio::ip::tcp::acceptor> mAcceptor;
		TcpSession * mNewSession;
		
		static TcpAcceptEngine mTcpAcceptEngine;
	};
#endif
	
}
