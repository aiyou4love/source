#pragma once

namespace cc {
	
	class TaskAccept : noncopyable
	{
	public:
		void pushTask(int16_t nTaskId);
		void popTask(int16_t nTaskId);
		
		TaskAccept();
		~TaskAccept();
		
	private:
		Int16Count mIntCount;
	};
	
}
