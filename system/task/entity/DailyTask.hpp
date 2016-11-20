#pragma once

namespace cc {
	
	class DailyTask : noncopyable
	{
	public:
		void pushTask(int16_t nTaskId);
		void popTask(int16_t nTaskId);
		bool checkTask(int16_t nTaskId);
		
		void runInit(EntityPtr& nEntity);
		const char * countName();
		
		DailyTask();
		~DailyTask();
		
	private:
		Int16Count mInt16Count;
	};
	
}
