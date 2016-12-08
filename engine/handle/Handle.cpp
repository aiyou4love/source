#include "../Engine.hpp"

namespace cc {
	
	void Handle::addContext(ContextPtr& nContext)
	{
		mContexts.push_back(nContext);
	}
	
	void Handle::setTicks(int32_t nTicks)
	{
		mTicks = nTicks;
	}
	
	void Handle::runStart()
	{
		mThread.reset(new thread(std::bind(&Handle::runHandle, this)));
	}
	
	void Handle::runHandle()
	{
		mStop = false;
		while (runInternal());
		mStop = true;
	}
	
	void Handle::runStop()
	{
		mStop = true;
	}
	
	void Handle::runJoin()
	{
		mThread->join();
	}
	
	void Handle::runClear()
	{
		mContexts.clear();
		mThread.reset();
		mStop = true;
		mTicks = 0;
		mFrame = 0;
	}
	
	bool Handle::runInternal()
	{
		if (mStop) {
			return false;
		}
		if (mTicks > 0) {
			mFrame++;
		}
		steady_clock::time_point begin_ = steady_clock::now();
		auto it = mContexts.begin();
		for ( ; it != mContexts.end(); ++it ) {
			ContextPtr& context_ = (*it);
			context_->runContext(mFrame);
		}
		steady_clock::time_point end_ = steady_clock::now();
		if (mTicks <= 0) {
			 chrono::milliseconds dura_(1);
			 this_thread::sleep_for(dura_);
			return true;
		}
		milliseconds timeSpan_ = duration_cast<milliseconds>(end_ - begin_);
		int32_t count_ = static_cast<int32_t>(timeSpan_.count());
		if (count_ < mTicks) {
			 chrono::milliseconds dura_(mTicks - count_);
			 this_thread::sleep_for(dura_);
		} else if (count_ > mTicks) {
			LOGE("[%s]ticks:%d", __METHOD__, count_);
		} else {
		}
		return true;
	}
	
	Handle::Handle()
	{
		this->runClear();
	}
	
	Handle::~Handle()
	{
		this->runClear();
	}
	
}
