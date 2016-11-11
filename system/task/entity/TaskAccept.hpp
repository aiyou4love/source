#pragma once

namespace cc {
	
	class TaskAccept : noncopyable
	{
	public:
		void pushTask(int16_t nTaskId, int8_t nIndex);
		void pushTask(int16_t nTaskId);
		
		void popTask(int16_t nTaskId);
		
		void runInit(IntArray * nIntArray);
		
		TaskAccept();
		~TaskAccept();
		
	private:
		Int32Count mInt32Count;
	};
	
}
