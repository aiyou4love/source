#include "../../Engine.hpp"

namespace cc {
	
	void Connector::runConnect(const char * nIp, const char * nPort, ConnectInfoPtr& nConnectInfo)
	{
		this->initSelectId(nConnectInfo);
		
		ConnectorMgr& connectorMgr_ = ConnectorMgr::instance();
		mSession = &(connectorMgr_.createSession(mAppId));
		(*mSession)->initSelectId(nConnectInfo);
		
		IoService& ioService_ = IoService::instance();
		asio::io_service& ioHandle_ = ioService_.getIoHandle();
		
		asio::ip::tcp::resolver resolver_(ioHandle_);
		asio::ip::tcp::resolver::query query_(nIp, nPort);
		asio::ip::tcp::resolver::iterator iterator_ = resolver_.resolve(query_);
		
		try {
			boost::asio::async_connect((*mSession)->getSocket(), iterator_,
			boost::bind(&Connector::handleConnect, SED_THIS(), boost::asio::placeholders::error));
			
			mConnectTimer.expires_from_now(boost::posix_time::seconds(Connector::connect_timeout));
			mConnectTimer.async_wait(boost::bind(&Connector::handleConnectTimeout, 
				SED_THIS(), boost::asio::placeholders::error));
		} catch (boost::system::system_error& e) {
			LOGE("[%s]%s", __METHOD__, e.what());
			mConnectTimer.cancel();
			this->runSelectId(mConnectErrorId);
		}
	}
	
	void Connector::handleConnectTimeout(const boost::system::error_code& nError)
	{
		if (nError) {
			this->runClose();
			return;
		}
		if (mConnectTimer.expires_at() <= asio::deadline_timer::traits_type::now()) {
			mConnectTimer.expires_at(boost::posix_time::pos_infin);
			this->runClose();
			this->runSelectId(mTimeoutId);
		}
	}
	
	void Connector::handleConnect(const boost::system::error_code& nError)
	{
		if (nError) {
			LOGE("[%s]%s", __METHOD__, nError.message().c_str());
			mConnectTimer.cancel();
			this->runSelectId(mConnectErrorId);
			return;
		}
		mConnectTimer.cancel();
		this->runSelectId(mConnectId);
		
		(*mSession)->startRead();
	}
	
	void Connector::initSelectId(ConnectInfoPtr& nConnectInfo)
	{
		mConnectErrorId = nConnectInfo->getConnectErrorId();
		mConnectId = nConnectInfo->getConnectId();
		mTimeoutId = nConnectInfo->getTimeoutId();
		
		int16_t dispatchId_ = nConnectInfo->getConnectDispatch();
		DispatchEngine& dispatchEngine_ = DispatchEngine::instance();
		mDispatch = dispatchEngine_.findDispatch(dispatchId_);
	}
	
	void Connector::runSelectId(int32_t nSelectId)
	{
		this->runClear();
		
		if (nSelectId <= 0) return;
		
		ValuePtr value_(new Value());
		value_->pushInt32(nSelectId);
		mDispatch->pushValue(value_);
	}
	
	void Connector::runClear()
	{
		ConnectEngine& connectEngine_ = ConnectEngine::instance();
		connectEngine_.removeConnector(mAppId);
	}
	
	void Connector::runClose()
	{
		ConnectorMgr& connectorMgr_ = ConnectorMgr::instance();
		connectorMgr_.removeSession(mAppId);
	}
	
	Connector::Connector(int64_t nAppId, asio::io_service& nHandle)
		: mConnectTimer (nHandle)
		, mAppId (nAppId)
		, mConnectErrorId (0)
		, mConnectId (0)
		, mTimeoutId (0)
		, mSession (nullptr)
		, mDispatch (nullptr)
	{
	}
	
	Connector::~Connector()
	{
		mSession = nullptr;
		mDispatch = nullptr;
		mConnectErrorId = 0;
		mConnectId = 0;
		mTimeoutId = 0;
		mAppId = 0;
	}
	
}

