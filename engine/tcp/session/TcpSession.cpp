#include "../../Engine.hpp"

namespace cc {
	
	void TcpSession::handleWriteTimeout(const boost::system::error_code& nError)
	{
		if (mWriteTimer.expires_at() <= asio::deadline_timer::traits_type::now()) {
			mWriteTimer.expires_at(boost::posix_time::pos_infin);
			
			LOGE("[%s]%s", __METHOD__, nError.message().c_str());
			this->runDisconnect();
		}
	}
	
	void TcpSession::handleWrite(const boost::system::error_code& nError)
	{
		if (nError) {
			LOGE("[%s]%s", __METHOD__, nError.message().c_str());
			this->runException();
			return;
		}
		mWriteTimer.cancel();
		this->internalWrite();
	}
	
	void TcpSession::internalWrite()
	{
		ValuePtr value_ = this->popValue();
		if (!value_) {
			mWriting = false;
			return;
		}
		int32_t seed_ = value_->getSeed();
		
		mBufWriter.runClear();
		IoWriter<BufWriter> ioWriter_(mBufWriter);
		value_->headSerialize(ioWriter_, "");
		mBufWriter.runEncrypt(seed_);
		mBufWriter.runCompress(EcompressType::mZstd);
		this->runWrite();
	}
	
	void TcpSession::runWrite()
	{
		try {
			mWriteTimer.expires_from_now(boost::posix_time::seconds(TcpSession::write_timeout));
			mWriteTimer.async_wait(boost::bind(&TcpSession::handleWriteTimeout,
				SED_THIS(), boost::asio::placeholders::error));
				
			asio::async_write(mSocket, boost::asio::buffer(mBufWriter.getValue(), mBufWriter.getSize()),
				boost::bind(&TcpSession::handleWrite, SED_THIS(), asio::placeholders::error));
		} catch (boost::system::system_error& e) {
			LOGE("[%s]%s", __METHOD__, e.what());
			this->runException();
		}
	}
	
	void TcpSession::startWrite()
	{
		if ( (false == mClosed) && (false == mWriting) ) {
			mWriting = true;
			this->internalWrite();
		}
	}
	
	int32_t TcpSession::getWriteSeed()
	{
		if ( (0 == mWriteValue) || (0 == mWriteNo) || (0 == mWriteType) ) {
			return SEEDDEF;
		}
		if (mIsFirst && mIsAccept) {
			mIsFirst = false;
			return SEEDDEF;
		}
		SeedEngine& seedEngine_ = SeedEngine::instance();
		int32_t result_ = seedEngine_.runSeed(mWriteNo, mWriteValue, mWriteType);
		mWriteNo = result_;
		mWriteType++;
		return result_;
	}
	
	void TcpSession::runSend(ValuePtr& nValue)
	{
		if ( true == mClosed ) {
			LOGE("[%s]", __METHOD__);
			return;
		}
		this->pushValue(nValue);
		this->startWrite();
	}
	
	void TcpSession::pushValue(ValuePtr& nValue)
	{
		LKGUD<mutex> lock_(mMutex);
		int32_t seed_ = this->getWriteSeed();
		nValue->setSeed(seed_);
		mValues.push_back(nValue);
	}
	
	ValuePtr TcpSession::popValue()
	{
		LKGUD<mutex> lock_(mMutex);
		ValuePtr value_;
		if (mValues.size() > 0) {
			value_ = mValues.front();
			mValues.pop_front();
		}
		return value_;
	}
	
	void TcpSession::handleRead(const boost::system::error_code& nError, size_t nBytes)
	{
		if (nError) {
			LOGE("[%s]%s", __METHOD__, nError.message().c_str());
			this->runException();
			return;
		}
		if ( nBytes <= 0 ) {
			LOGE("[%s]nBytes <= 0", __METHOD__);
			return;
		}
		mReadTimer.cancel();
		this->internalRead(nBytes);
	}
	
	void TcpSession::handleReadTimeout(const boost::system::error_code& nError)
	{
		if (mReadTimer.expires_at() <= asio::deadline_timer::traits_type::now()) {
			mReadTimer.expires_at(boost::posix_time::pos_infin);
			
			LOGE("[%s]%s", __METHOD__, nError.message().c_str());
			this->runDisconnect();
		}
	}
	
	void TcpSession::internalRead(size_t nBytes)
	{
		char * buf_ = (char *)(mReadBuffer.data());
		int16_t size_ = (int16_t)nBytes;
		int8_t error_ = mBufReader.pushBuf(buf_, size_);
		while ( 1 == error_ ) {
			int32_t seed_ = this->getReadSeed();
			mBufReader.runDecompress(buf_, EcompressType::mZstd);
			mBufReader.runDecrypt(seed_);
			this->runValue();
			error_ = mBufReader.nextBuf(buf_, size_);
		}
		if ( 0 == error_ ) {
			this->runException();
			return;
		}
		this->runRead();
	}
	
	void TcpSession::runRead()
	{
		try {
			mReadBuffer.assign(0);
			
			mReadTimer.expires_from_now(boost::posix_time::seconds(TcpSession::read_timeout));
			mReadTimer.async_wait(boost::bind(&TcpSession::handleReadTimeout, 
				SED_THIS(), boost::asio::placeholders::error));
				
			mSocket.async_read_some(boost::asio::buffer(mReadBuffer),
				boost::bind(&TcpSession::handleRead, SED_THIS(),
				asio::placeholders::error, asio::placeholders::bytes_transferred));
		} catch (boost::system::system_error& e) {
			LOGE("[%s]%s", __METHOD__, e.what());
			this->runException();
		}
	}
	
	void TcpSession::startRead()
	{
		mClosed = false;
		this->runRead();
	}
	
	int32_t TcpSession::getReadSeed()
	{
		if ( (0 == mReadValue) || (0 == mReadNo) || (0 == mReadType) ) {
			return SEEDDEF;
		}
		SeedEngine& seedEngine_ = SeedEngine::instance();
		int32_t result_ = seedEngine_.runSeed(mReadNo, mReadValue, mReadType);
		mReadNo = result_;
		mReadType++;
		return result_;
	}
	
	void TcpSession::runSeed()
	{
		SeedEngine& seedEngine_ = SeedEngine::instance();
		int16_t size_ = seedEngine_.getSize();
		
		RandomEngine& randomEngine_ = RandomEngine::instance();
		
		mWriteValue = randomEngine_.runRandom(249, 3924);
		mWriteNo = randomEngine_.runRandom(249, 3924);
		mWriteType = randomEngine_.runRandom(1, size_);
		
		mReadValue = randomEngine_.runRandom(249, 3924);
		mReadNo = randomEngine_.runRandom(249, 3924);
		mReadType = randomEngine_.runRandom(1, size_);
	}
	
	void TcpSession::runAccept(ValuePtr& nValue)
	{
		if ( mAuthority > 0 ) {
			SelectEngine& selectEngine_ = SelectEngine::instance();
			int32_t selectId_ = nValue->getInt32(1);
			if ( selectEngine_.isNetSelect(selectId_, mAuthority) ) {
				LOGE("[%s]isNetSelect", __METHOD__);
				this->runValue(nValue);
			} else {
				LOGE("[%s]mAuthority > mTourist", __METHOD__);
				this->runClose();
			}
		} else {
			this->runAuthority(nValue);
		}
	}
	
	void TcpSession::runConnect(ValuePtr& nValue)
	{
		if ( mAuthority <= 0 ) {
			mAuthority = nValue->getInt16(1);
			mWriteValue = nValue->getInt16(2);
			mWriteNo = nValue->getInt32(3);
			mWriteType = nValue->getInt16(4);
			mReadValue = nValue->getInt16(5);
			mReadNo = nValue->getInt32(6);
			mReadType = nValue->getInt16(7);
		#ifdef __CLIENT__
			cServerTime& serverTime_ = cServerTime::instance();
			int64_t numberTime_ = nValue->getInt64(8);
			int32_t timeDiff_ = nValue->getInt32(9);
			serverTime_.setServerTime(numberTime_, timeDiff_);
		#endif
			this->runSelectId(mConnectId);
		} else {
			this->runValue(nValue);
		}
	}
	
	void TcpSession::runValue(ValuePtr& nValue)
	{
		if (nullptr != mSend) {
			Send * send_ = dynamic_cast<ISend *>(mSend);
			send_->pushValue(nValue);
		} else {
			mDispatch->pushValue(nValue);
		}
	}
	
	void TcpSession::runValue()
	{
		ValuePtr value_(new Value());
		IoReader<BufReader> ioReader_(mBufReader);
		value_->headSerialize(ioReader_, "");
		
		int8_t check_ = value_->verCheck(mIsAccept);
		if ( 0 == check_ ) {
			this->runVerMaxId();
			return;
		} else if ( 2 == check_ ) {
			this->runVerMinId();
		} else {
		}
		
		if (mIsAccept) {
			this->runAccept(value_);
		} else {
			this->runConnect(value_);
		}
	}
	
	void TcpSession::runSelectId(int32_t nSelectId)
	{
		if (nSelectId <= 0) {
			return;
		}
		ValuePtr value_(new Value());
		value_->pushInt32(nSelectId);
		this->runValue(value_);
	}
	
	void TcpSession::runDisconnect()
	{
		this->runClose();
		
		this->runSelectId(mDisconnectId);
	}
	
	void TcpSession::runException()
	{
		this->runClose();
		
		this->runSelectId(mExceptionId);
	}
	
	void TcpSession::runVerMaxId()
	{
	#ifdef __AGENT__
		ValuePtr value_(new Value());
		value_->verInit();
		this->runSend(value_);
	#elif defined __CLIENT__
		if (mVerMaxId > 0) {
			this->runSelectId(mVerMaxId);
		}
	#else
		this->runClose();
	#endif
	}
	
	void TcpSession::runVerMinId()
	{
	#ifdef __CLIENT__
		if (mVerMinId > 0) {
			this->runSelectId(mVerMinId);
		}
	#endif
	}
	
	void TcpSession::initSelectId(TcpConnectInfoPtr& nTcpConnectInfo)
	{
		mDisconnectId = nTcpConnectInfo->getDisconnectId();
		mConnectId = nTcpConnectInfo->getConnectId();
		mExceptionId = nTcpConnectInfo->getExceptionId();
		mVerMaxId = nTcpConnectInfo->getVerMaxId();
		mVerMinId = nTcpConnectInfo->getVerMinId();
		int16_t dispatchId_ = nTcpConnectInfo->getDispatchId();
		this->setDispatch(dispatchId_);
	}
	
	void TcpSession::setDisconnect(int32_t nDisconnectId)
	{
		mDisconnectId = nDisconnectId;
	}
	
	void TcpSession::setException(int32_t nExceptionId)
	{
		mExceptionId = nExceptionId;
	}
	
	void TcpSession::setDispatch(int16_t nDispatchId)
	{
		DispatchEngine& dispatchEngine_ = DispatchEngine::instance();
		mDispatch = dispatchEngine_.findDispatch(nDispatchId);
	}
	
	void TcpSession::setSend(Property * nSend)
	{
		mSend = nSend;
	}
	
	void TcpSession::runAuthority(ValuePtr& nValue)
	{
		const char * clientB64_ = nValue->getString(1);
		if ( 0 == strcmp(clientB64_, __CLIENTB64__) ) {
			mAuthority = Eauthority::mTourist;
		} else if ( 0 == strcmp(clientB64_, __GMCLIENTB64__) ) {
			mAuthority = Eauthority::mGM;
		} else if ( 0 == strcmp(clientB64_, __DECLIENTB64__) ) {
			mAuthority = Eauthority::mDeveloper;
		} else if ( 0 == strcmp(clientB64_, __AGENTB64__) ) {
			mAuthority = Eauthority::mSystem;
		} else if ( 0 == strcmp(clientB64_, __SOCIALB64__) ) {
			mAuthority = Eauthority::mSystem;
		} else if ( 0 == strcmp(clientB64_, __GAMEB64__) ) {
			mAuthority = Eauthority::mSystem;
		} else {
			mAuthority = Eauthority::mTourist;
		}
		this->runSeed();
		
		ValuePtr value_(new Value());
		value_->verInit();
		value_->pushInt16(mAuthority);
		value_->pushInt16(mWriteValue);
		value_->pushInt32(mWriteNo);
		value_->pushInt16(mWriteType);
		value_->pushInt16(mReadValue);
		value_->pushInt32(mReadNo);
		value_->pushInt16(mReadType);
	#ifdef __AGENT__
		cServerTime& serverTime_ = cServerTime::instance();
		int64_t numberTime_ = serverTime_.getServerTime();
		int32_t timeDiff_ = serverTime_.getTimeDiff();
		value_->pushInt64(numberTime_);
		value_->pushInt32(timeDiff_);
	#endif
		this->runSend(value_);
	}
	
	void TcpSession::sendAuthority()
	{
		mClosed = false;
		
		ValuePtr value_(new Value());
		value_->verInit();
		value_->pushString(__EXEBASE64__);
		this->runSend(value_);
		
		this->runRead();
	}
	
	void TcpSession::setRemove(ISessionRemove * nSessionRemove)
	{
		mSessionRemove = nSessionRemove;
	}
	
	void TcpSession::setAppId(int64_t nAppId)
	{
		mAppId = nAppId;
	}
	
	void TcpSession::runClose()
	{
		LOGI("[%s]", __METHOD__);
		if (nullptr != mSessionRemove) {
			if (mAppId > 0) {
				mSessionRemove->removeSession(mAppId);
			}
			mSessionRemove->removeSession(mSessionId);
		}
		this->runClear();
	}
	
	void TcpSession::runClear()
	{
		if (mSocket.is_open()) {
			boost::system::error_code error_;
			mSocket.shutdown(asio::socket_base::shutdown_both, error_);
			mSocket.close(error_);
		}
		mWriteTimer.cancel();
		mReadTimer.cancel();
		
		mBufReader.runClear();
		mReadBuffer.fill(0);
		
		mBufWriter.runClear();
		mValues.clear();
		mWriting = false;
		
		mWriteValue = 0;
		mWriteNo = 0;
		mWriteType = 0;
		mIsFirst = true;
		
		mReadValue = 0;
		mReadNo = 0;
		mReadType = 0;
		
		mDisconnectId = 0;
		mConnectId = 0;
		mExceptionId = 0;
		mVerMaxId = 0;
		mVerMinId = 0;
		
		mDispatch = nullptr;
		mSend = nullptr;
		
		mSessionRemove = nullptr;
		mAppId = 0;
		mClosed = true;
		
		mAuthority = 0;
		mSessionId = 0;
		mIsAccept = false;
	}
	
	void TcpSession::setIsAccept(bool nIsAccept)
	{
		mIsAccept = nIsAccept;
	}
	
	asio::ip::tcp::socket& TcpSession::getSocket()
	{
		return mSocket;
	}
	
	int32_t TcpSession::getSessionId()
	{
		return mSessionId;
	}
	
	TcpSession::TcpSession(int32_t nSessionId, asio::io_service& nHandle)
		: mSocket (nHandle)
		, mWriteTimer (nHandle)
		, mReadTimer (nHandle)
		, mWriting(false)
		, mWriteValue (0)
		, mWriteNo (0)
		, mWriteType (0)
		, mIsFirst (true)
		, mReadValue (0)
		, mReadNo (0)
		, mReadType (0)
		, mDisconnectId (0)
		, mConnectId (0)
		, mExceptionId (0)
		, mVerMaxId (0)
		, mVerMinId (0)
		, mDispatch (nullptr)
		, mSend (nullptr)
		, mClosed (true)
		, mSessionRemove (nullptr)
		, mAppId (0)
		, mAuthority (0)
		, mIsAccept (false)
		, mSessionId (nSessionId)
	{
		mReadBuffer.fill(0);
		mValues.clear();
		
		mBufReader.runClear();
		mBufWriter.runClear();
	}
	
	TcpSession::~TcpSession()
	{
		this->runClear();
	}
	
}
