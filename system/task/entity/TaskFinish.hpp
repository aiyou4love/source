#pragma once

namespace cc {
	
	class TaskFinish : noncopyable
	{
	public:
		void pushTask(int16_t nTaskId);
		void popTask(int16_t nTaskId);
		
		void runInit(IntArray * nIntArray);
		
		TaskFinish();
		~TaskFinish();
		
	private:
		BitCount mBitCount;
	};
	typedef SPTR<TaskFinish> TaskFinishPtr;
	
}
