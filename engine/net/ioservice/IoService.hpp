#pragma once

namespace cc {
	
	class IoService : boost::noncopyable
	{
	public:
		asio::io_service& getIoHandle();
		
		template<class T>
		void headSerialize(T& nSerialize, const char * nName)
		{
			nSerialize.runNumber(mIoCount, "ioCount");
		}
		const char * streamName();
		const char * streamUrl();
		
		void runPreinit();
		void runLoad();
		void runInit();
		void runStart();
		void runStop();
		void runRun();
		
		static IoService& instance();
		
		IoService();
		~IoService();
		
	private:
		void runClear();
		
	private:
		typedef SPTR<asio::io_service> IoServicePtr;
		typedef SPTR<asio::io_service::work> WorkPtr;
		SPTR<asio::signal_set> mSignals;
		vector<IoServicePtr> mIoServices;
		vector<ThreadPtr> mThreads;
		vector<WorkPtr> mWorks;
		size_t mNextIo;
		int16_t mIoCount;
		
		static IoService mIoService;
	};
	
}
