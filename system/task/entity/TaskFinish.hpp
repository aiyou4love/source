#pragma once

namespace cc {
	
	class TaskFinish : noncopyable
	{
	public:
		void pushTask(int16_t nTaskId);
		void popTask(int16_t nTaskId);
		bool checkTask(int16_t nTaskId);
		
		void runInit(EntityPtr& nEntity);
		const char * countName();
		
		TaskFinish();
		~TaskFinish();
		
	private:
		Int16Count mInt16Count;
	};
	
}
