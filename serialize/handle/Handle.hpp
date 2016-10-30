#pragma once

namespace cc {
	
	class Handle : noncopyable
	{
	public:
		void addContext(ContextPtr& nContext);
		void setTicks(int32_t nTicks);
		
		void runStart();
		void runStop();
		void runJoin();
		
	private:
		bool runInternal();
		void runHandle();
		void runClear();
		
	public:
		Handle();
		~Handle();
		
	private:
		list<ContextPtr> mContexts;
		
		SPTR<thread> mThread;
		atomic<bool> mStop;
		int32_t mTicks;
		int32_t mFrame;
	};
	typedef SPTR<Handle> HandlePtr;
	typedef WPTR<Handle> HandleWtr;
	
}
