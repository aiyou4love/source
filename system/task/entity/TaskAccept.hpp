#pragma once

namespace cc {
	
	class TaskAccept : noncopyable
	{
	public:
		void pushTask(int16_t nTaskId);
		void popTask(int16_t nTaskId);
		
		void runInit(EntityPtr& nEntity);
		const char * countName();
		
		TaskAccept();
		~TaskAccept();
		
	private:
		Int16Count mInt16Count;
	};
	
}
