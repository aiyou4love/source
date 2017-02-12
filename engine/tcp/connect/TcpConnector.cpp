#include "../../Engine.hpp"

namespace cc {
	
	void TcpConnector::runConnect(const char * nIp, const char * nPort, TcpConnectInfoPtr& nTcpConnectInfo)
	{
		this->initSelectId(nTcpConnectInfo);
		
		TcpConnectorMgr& tcpConnectorMgr_ = TcpConnectorMgr::instance();
		mSession = tcpConnectorMgr_.createSession(mAppId);
		mSession->initSelectId(nTcpConnectInfo);
		
		IoService& ioService_ = IoService::instance();
		asio::io_service& ioHandle_ = ioService_.getIoHandle();
		
		asio::ip::tcp::resolver resolver_(ioHandle_);
		asio::ip::tcp::resolver::query query_(nIp, nPort);
		asio::ip::tcp::resolver::iterator iterator_ = resolver_.resolve(query_);
		
		try {
			boost::asio::async_connect(mSession->getSocket(), iterator_,
			boost::bind(&TcpConnector::handleConnect, this, boost::asio::placeholders::error));
			
			mConnectTimer.expires_from_now(boost::posix_time::seconds(TcpConnector::connect_timeout));
			mConnectTimer.async_wait(boost::bind(&TcpConnector::handleConnectTimeout, 
				this, boost::asio::placeholders::error));
		} catch (boost::system::system_error& e) {
			LOGE("[%s]%s", __METHOD__, e.what());
			mConnectTimer.cancel();
			this->runSelectId(mConnectErrorId);
		}
	}
	
	void TcpConnector::handleConnectTimeout(const boost::system::error_code& nError)
	{
		if (nError) {
			return;
		}
		if (mConnectTimer.expires_at() <= asio::deadline_timer::traits_type::now()) {
			mConnectTimer.expires_at(boost::posix_time::pos_infin);
			this->runClose();
			this->runSelectId(mTimeoutId);
		}
	}
	
	void TcpConnector::handleConnect(const boost::system::error_code& nError)
	{
		if (nError) {
			LOGE("[%s]%s", __METHOD__, nError.message().c_str());
			mConnectTimer.cancel();
			this->runSelectId(mConnectErrorId);
			return;
		}
		mConnectTimer.cancel();
		
		ISessionRemove * sessionRemove_ = TcpConnectRemove::instance();
		mSession->setRemove(sessionRemove_);
		mSession->sendAuthority();
		this->runClear();
	}
	
	void TcpConnector::initSelectId(TcpConnectInfoPtr& nTcpConnectInfo)
	{
		mConnectErrorId = nTcpConnectInfo->getConnectErrorId();
		mTimeoutId = nTcpConnectInfo->getTimeoutId();
		
		int16_t dispatchId_ = nTcpConnectInfo->getConnectDispatch();
		DispatchEngine& dispatchEngine_ = DispatchEngine::instance();
		mDispatch = dispatchEngine_.findDispatch(dispatchId_);
	}
	
	void TcpConnector::runSelectId(int32_t nSelectId)
	{
		this->runClose();
		
		if (nSelectId <= 0) return;
		
		ValuePtr value_(new Value());
		value_->pushInt32(nSelectId);
		mDispatch->pushValue(value_);
	}
	
	void TcpConnector::runClear()
	{
		TcpConnectEngine& tcpConnectEngine_ = TcpConnectEngine::instance();
		tcpConnectEngine_.removeConnector(mAppId);
	}
	
	void TcpConnector::runClose()
	{
		TcpConnectEngine& tcpConnectEngine_ = TcpConnectEngine::instance();
		tcpConnectEngine_.removeConnector(mAppId);
		
		TcpConnectorMgr& tcpConnectorMgr_ = TcpConnectorMgr::instance();
		tcpConnectorMgr_.removeSession(mAppId);
	}
	
	TcpConnector::TcpConnector(int64_t nAppId, asio::io_service& nHandle)
		: mConnectTimer (nHandle)
		, mAppId (nAppId)
		, mConnectErrorId (0)
		, mTimeoutId (0)
		, mSession (nullptr)
		, mDispatch (nullptr)
	{
	}
	
	TcpConnector::~TcpConnector()
	{
		mSession = nullptr;
		mDispatch = nullptr;
		mConnectErrorId = 0;
		mTimeoutId = 0;
		mAppId = 0;
	}
	
}

