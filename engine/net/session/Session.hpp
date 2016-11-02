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
		
		void pushValue(ValuePtr& nValue);
		ValuePtr popValue();
		
		void runSend(ValuePtr& nValue);
		
		void handleRead(const boost::system::error_code& nError, size_t nBytes);
		void handleReadTimeout(const boost::system::error_code& nError);
		void internalRead(size_t nBytes);
		void runRead();
		
		void runDisconnect();
		void runException();
		
		void runClear();
		void runClose();
		
		void initSelectId(ConnectInfoPtr& nConnectInfo);
		void runSelectId(int32_t nSelectId);
		void runValue(ValuePtr& nValue);
		
		void setDisconnect(int32_t nDisconnectId);
		void setException(int32_t nExceptionId);
		
		void setDispatch(int16_t nDispatchId);
		void setSend(PropertyPtr& nSend);
		
		void setRemove(ISessionRemove * nSessionRemove);
		
		asio::ip::tcp::socket& getSocket();
		
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
		
		int32_t mDisconnectId;
		int32_t mExceptionId;
		
		IDispatch * mDispatch;
		PropertyPtr * mSend;
		
		ISessionRemove * mSessionRemove;
		
		atomic<bool> mClosed;
		atomic<bool> mReading;
		int32_t mSessionId;
	};
	typedef SPTR<Session> SessionPtr;
	typedef WPTR<Session> SessionWtr;
	
}
