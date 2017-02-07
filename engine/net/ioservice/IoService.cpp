#include "../../Engine.hpp"

namespace cc {
	
	void IoService::runPreinit()
	{
		LifeCycle& lifeCycle_ = LifeCycle::instance();
		lifeCycle_.m_tLoadBegin.connect(bind(&IoService::runLoad, this));
		lifeCycle_.m_tInitBegin.connect(bind(&IoService::runInit, this));
		lifeCycle_.m_tStartBegin.connect(bind(&IoService::runStart, this));
		lifeCycle_.m_tNoticeStart.connect(bind(&IoService::noticeStart, this));
		lifeCycle_.m_tRunJoin.connect(bind(&IoService::runJoin, this));
		lifeCycle_.m_tStopJoin.connect(bind(&IoService::runStop, this));
		lifeCycle_.m_tClearEnd.connect(bind(&IoService::runClear, this));
	}
	
	void IoService::runLoad()
	{
		ConfigEngine& configEngine_ = ConfigEngine::instance();
		configEngine_.runReader<IoService>(this, streamUrl(), streamName());
	}
	
	void IoService::runInit()
	{
		for (int16_t i = 0; i < mIoCount; ++i) {
			IoServicePtr ioService_(new asio::io_service());
			WorkPtr work_(new asio::io_service::work(*ioService_));
			mIoServices.push_back(ioService_);
			mWorks.push_back(work_);
		}
	}
	
	void IoService::runStart()
	{
		mSignals.reset(new asio::signal_set(this->getIoHandle()));
		mSignals->add(SIGINT); mSignals->add(SIGTERM);
	#ifdef __WINDOW__
		mSignals->add(SIGBREAK);
	#endif
		LifeCycle& lifeCycle_ = LifeCycle::instance();
		mSignals->async_wait(boost::bind(&LifeCycle::noticeStop, &lifeCycle_));
	}
	
	void IoService::noticeStart()
	{
		mSignals->add(SIGINT); mSignals->add(SIGTERM);
	#ifdef __WINDOW__
		mSignals->add(SIGBREAK);
	#endif
		LifeCycle& lifeCycle_ = LifeCycle::instance();
		mSignals->async_wait(boost::bind(&LifeCycle::noticeStop, &lifeCycle_));
	}
	
	void IoService::runJoin()
	{
		for (size_t i = 0; i < mIoServices.size(); ++i) {
			ThreadPtr thread_(new std::thread(boost::bind(&asio::io_service::run, mIoServices[i])));
			mThreads.push_back(thread_);
		}
		WorkDirectory& workDirectory_ = WorkDirectory::instance();
		bool running_ = workDirectory_.isRunning();
		if (running_) {
			for (size_t i = 0; i < mThreads.size(); ++i) {
				mThreads[i]->join();
			}
			mThreads.clear();
		}
	}
	
	void IoService::runStop()
	{
		for (size_t i = 0; i < mIoServices.size(); ++i) {
			mIoServices[i]->stop();
		}
	}
	
	asio::io_service& IoService::getIoHandle()
	{
		asio::io_service& ioService_ = (*(mIoServices[mNextIo]));
		++mNextIo;
		if (mNextIo == mIoServices.size()) {
			mNextIo = 0;
		}
		return ioService_;
	}
	
	void IoService::runClear()
	{
		//mIoServices.clear();
		//mWorks.clear();
		mIoCount = 1;
		mNextIo = 0;
	}
	
	const char * IoService::streamName()
	{
		return "workDirectory";
	}
	
	const char * IoService::streamUrl()
	{
		return "workDirectory.json";
	}
	
	IoService& IoService::instance()
	{
		return mIoService;
	}
	
	IoService::IoService()
	{
		this->runClear();
	}
	
	IoService::~IoService()
	{
		this->runClear();
	}
	
	IoService IoService::mIoService;
	
}
