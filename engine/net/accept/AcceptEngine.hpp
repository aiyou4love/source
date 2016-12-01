#pragma once

namespace cc {
	
#ifndef __CLIENT__
	class AcceptEngine : noncopyable
	{
	public:
		void initAccept();
		
	private:
		void handleAccept(const boost::system::error_code& nError);
		void startAccept();
		
	public:
		void runPreinit();
		void runStop();
		
		static AcceptEngine& instance();
		
		AcceptEngine();
		~AcceptEngine();
		
	private:
		SPTR<asio::ip::tcp::acceptor> mAcceptor;
		SessionPtr * mNewSession;
		
		static AcceptEngine mAcceptEngine;
	};
#endif
	
}
