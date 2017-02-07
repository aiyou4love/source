#pragma once

namespace cc {
	
	class Session : public SPTR_THIS<Session>, noncopyable
	{
	public:
		enum { write_timeout = 300 };
		enum { read_timeout = 300 };
		
		void handleWriteTimeout(const boost::system::error_code& nError);
		void handleWrite(const boost::system::error_code& nError);
		void internalWrite();
		void runWrite();
		void startWrite();
		int32_t getWriteSeed();
		
		void runSend(ValuePtr& nValue);
		
		void pushValue(ValuePtr& nValue);
		ValuePtr popValue();
		
		void handleRead(const boost::system::error_code& nError, size_t nBytes);
		void handleReadTimeout(const boost::system::error_code& nError);
		void internalRead(size_t nBytes);
		void runRead();
		void startRead();
		int32_t getReadSeed();
		
		void runAccept(ValuePtr& nValue);
		void runConnect(ValuePtr& nValue);
		void runValue(ValuePtr& nValue);
		void runValue();
		
		void runSelectId(int32_t nSelectId);
		
		void runDisconnect();
		void runException();
		void runVerMaxId();
		void runVerMinId();
		
		void initSelectId(ConnectInfoPtr& nConnectInfo);
		
		void setDisconnect(int32_t nDisconnectId);
		void setException(int32_t nExceptionId);
		
		void setDispatch(int16_t nDispatchId);
		void setSend(PropertyPtr& nSend);
		
		void runAuthority(ValuePtr& nValue);
		void sendAuthority();
		
		void setRemove(ISessionRemove * nSessionRemove);
		void setAppId(int64_t nAppId);
		void runClose();
		void runClear();
		
		asio::ip::tcp::socket& getSocket();
		
		void setIsAccept(bool nIsAccept);
		int32_t getSessionId();
		
		Session(int32_t nSessionId, asio::io_service& nHandle);
		~Session();
		
	private:
		asio::ip::tcp::socket mSocket;
		
		asio::deadline_timer mWriteTimer;
		asio::deadline_timer mReadTimer;
		
		boost::array<int8_t, PACKETSIZE> mReadBuffer;
		BufReader mBufReader;
		
		deque<ValuePtr> mValues;
		atomic<bool> mWriting;
		BufWriter mBufWriter;
		mutex mMutex;
		
		int16_t mWriteValue;
		int32_t mWriteNo;
		int16_t mWriteType;
		bool mIsFirst;
		
		int16_t mReadValue;
		int32_t mReadNo;
		int16_t mReadType;
		
		int32_t mDisconnectId;
		int32_t mExceptionId;
		
		int32_t mVerMaxId;
		int32_t mVerMinId;
		
		IDispatch * mDispatch;
		PropertyPtr * mSend;
		
		ISessionRemove * mSessionRemove;
		atomic<bool> mClosed;
		int64_t mAppId;
		
		int16_t mAuthority;
		bool mIsAccept;
		int32_t mSessionId;
	};
	typedef SPTR<Session> SessionPtr;
	typedef WPTR<Session> SessionWtr;
	
}
