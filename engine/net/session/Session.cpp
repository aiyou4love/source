#include "../../Engine.hpp"

namespace cc {
	
	void Session::handleWriteTimeout(const boost::system::error_code& nError)
	{
		if (mWriteTimer.expires_at() <= asio::deadline_timer::traits_type::now()) {
			mWriteTimer.expires_at(boost::posix_time::pos_infin);
			
			LOGE("[%s]%s", __METHOD__, nError.message().c_str());
			this->runDisconnect();
		}
	}
	
	void Session::handleWrite(const boost::system::error_code& nError)
	{
		if (nError) {
			LOGE("[%s]%s", __METHOD__, nError.message().c_str());
			this->runException();
			return;
		}
		mWriteTimer.cancel();
		this->internalWrite();
	}
	
	void Session::internalWrite()
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
	
	void Session::runWrite()
	{
		try {
			mWriteTimer.expires_from_now(boost::posix_time::seconds(Session::write_timeout));
			mWriteTimer.async_wait(boost::bind(&Session::handleWriteTimeout,
				SED_THIS(), boost::asio::placeholders::error));
				
			asio::async_write(mSocket, boost::asio::buffer(mBufWriter.getValue(), mBufWriter.getSize()),
				boost::bind(&Session::handleWrite, SED_THIS(), asio::placeholders::error));
		} catch (boost::system::system_error& e) {
			LOGE("[%s]%s", __METHOD__, e.what());
			this->runException();
		}
	}
	
	void Session::startWrite()
	{
		if ( mReading && (!mWriting) ) {
			mWriting = true;
			this->internalWrite();
		}
	}
	
	int32_t Session::getWriteSeed()
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
	
	void Session::runSend(ValuePtr& nValue)
	{
		if ( mClosed ) {
			LOGE("[%s]", __METHOD__);
			return;
		}
		this->pushValue(nValue);
		this->startWrite();
	}
	
	void Session::pushValue(ValuePtr& nValue)
	{
		LKGUD<mutex> lock_(mMutex);
		int32_t seed_ = this->getWriteSeed();
		nValue->setSeed(seed_);
		mValues.push_back(nValue);
	}
	
	ValuePtr Session::popValue()
	{
		LKGUD<mutex> lock_(mMutex);
		ValuePtr value_;
		if (mValues.size() > 0) {
			value_ = mValues.front();
			mValues.pop_front();
		}
		return value_;
	}
	
	void Session::handleRead(const boost::system::error_code& nError, size_t nBytes)
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
	
	void Session::handleReadTimeout(const boost::system::error_code& nError)
	{
		if (mReadTimer.expires_at() <= asio::deadline_timer::traits_type::now()) {
			mReadTimer.expires_at(boost::posix_time::pos_infin);
			
			LOGE("[%s]%s", __METHOD__, nError.message().c_str());
			this->runDisconnect();
		}
	}
	
	void Session::internalRead(size_t nBytes)
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
	
	void Session::runRead()
	{
		try {
			mReadBuffer.assign(0);
			
			mReadTimer.expires_from_now(boost::posix_time::seconds(Session::read_timeout));
			mReadTimer.async_wait(boost::bind(&Session::handleReadTimeout, 
				SED_THIS(), boost::asio::placeholders::error));
				
			mSocket.async_read_some(boost::asio::buffer(mReadBuffer),
				boost::bind(&Session::handleRead, SED_THIS(),
				asio::placeholders::error, asio::placeholders::bytes_transferred));
		} catch (boost::system::system_error& e) {
			LOGE("[%s]%s", __METHOD__, e.what());
			this->runException();
		}
	}
	
	void Session::startRead()
	{
		mReading = true;
		this->runRead();
		this->startWrite();
	}
	
	int32_t Session::getReadSeed()
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
	
	void Session::runAccept(ValuePtr& nValue)
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
	
	void Session::runConnect(ValuePtr& nValue)
	{
		if ( mAuthority <= 0 ) {
			mAuthority = nValue->getInt16(1);
		#ifdef __CLIENT__
			cServerTime& serverTime_ = cServerTime::instance();
			int64_t numberTime_ = nValue->getInt64(2);
			int32_t timeDiff_ = nValue->getInt32(3);
			serverTime_.setServerTime(numberTime_, timeDiff_);
			LOGE("[%s]%lld,%d", __METHOD__, numberTime_, timeDiff_);
		#endif
		} else {
			this->runValue(nValue);
		}
	}
	
	void Session::runValue(ValuePtr& nValue)
	{
		if (nullptr != mSend) {
			SendPtr send_ = PTR_DCST<ISend>(*mSend);
			send_->pushValue(nValue);
		} else {
			mDispatch->pushValue(nValue);
		}
	}
	
	void Session::runValue()
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
	
	void Session::runSelectId(int32_t nSelectId)
	{
		if (nSelectId <= 0) {
			return;
		}
		ValuePtr value_(new Value());
		value_->pushInt32(nSelectId);
		this->runValue(value_);
	}
	
	void Session::runDisconnect()
	{
		this->runClose();
		
		this->runSelectId(mDisconnectId);
	}
	
	void Session::runException()
	{
		this->runClose();
		
		this->runSelectId(mExceptionId);
	}
	
	void Session::runVerMaxId()
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
	
	void Session::runVerMinId()
	{
	#ifdef __CLIENT__
		if (mVerMinId > 0) {
			this->runSelectId(mVerMinId);
		}
	#endif
	}
	
	void Session::initSelectId(ConnectInfoPtr& nConnectInfo)
	{
		mDisconnectId = nConnectInfo->getDisconnectId();
		mExceptionId = nConnectInfo->getExceptionId();
		mVerMaxId = nConnectInfo->getVerMaxId();
		mVerMinId = nConnectInfo->getVerMinId();
		int16_t dispatchId_ = nConnectInfo->getDispatchId();
		this->setDispatch(dispatchId_);
	}
	
	void Session::setDisconnect(int32_t nDisconnectId)
	{
		mDisconnectId = nDisconnectId;
	}
	
	void Session::setException(int32_t nExceptionId)
	{
		mExceptionId = nExceptionId;
	}
	
	void Session::setDispatch(int16_t nDispatchId)
	{
		DispatchEngine& dispatchEngine_ = DispatchEngine::instance();
		mDispatch = dispatchEngine_.findDispatch(nDispatchId);
	}
	
	void Session::setSend(PropertyPtr& nSend)
	{
		mSend = &nSend;
	}
	
	void Session::runAuthority(ValuePtr& nValue)
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
		ValuePtr value_(new Value());
		value_->verInit();
		value_->pushInt16(mAuthority);
	#ifdef __AGENT__
		cServerTime& serverTime_ = cServerTime::instance();
		int64_t numberTime_ = serverTime_.getServerTime();
		int32_t timeDiff_ = serverTime_.getTimeDiff();
		LOGE("[%s]%lld,%d", __METHOD__, numberTime_, timeDiff_);
		value_->pushInt64(numberTime_);
		value_->pushInt32(timeDiff_);
	#endif
		this->runSend(value_);
	}
	
	void Session::sendAuthority()
	{
		ValuePtr value_(new Value());
		value_->verInit();
		value_->pushString(__EXEBASE64__);
		this->runSend(value_);
	}
	
	void Session::setRemove(ISessionRemove * nSessionRemove)
	{
		mSessionRemove = nSessionRemove;
	}
	
	void Session::setAppId(int64_t nAppId)
	{
		mAppId = nAppId;
	}
	
	void Session::runClose()
	{
		if (nullptr != mSessionRemove) {
			if (mAppId > 0) {
				mSessionRemove->removeSession(mAppId);
			}
			mSessionRemove->removeSession(mSessionId);
		}
		this->runClear();
	}
	
	void Session::runClear()
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
		mReading = false;
		
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
	
	void Session::setIsAccept(bool nIsAccept)
	{
		mIsAccept = nIsAccept;
	}
	
	void Session::setAuthority(int16_t nAuthority)
	{
		mAuthority = nAuthority;
	}
	
	asio::ip::tcp::socket& Session::getSocket()
	{
		return mSocket;
	}
	
	int32_t Session::getSessionId()
	{
		return mSessionId;
	}
	
	Session::Session(int32_t nSessionId, asio::io_service& nHandle)
		: mSocket (nHandle)
		, mWriteTimer (nHandle)
		, mReadTimer (nHandle)
		, mReading(false)
		, mWriting(false)
		, mWriteValue (0)
		, mWriteNo (0)
		, mWriteType (0)
		, mIsFirst (true)
		, mReadValue (0)
		, mReadNo (0)
		, mReadType (0)
		, mDisconnectId (0)
		, mExceptionId (0)
		, mVerMaxId (0)
		, mVerMinId (0)
		, mDispatch (nullptr)
		, mSend (nullptr)
		, mClosed (false)
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
	
	Session::~Session()
	{
		this->runClear();
	}
	
}
