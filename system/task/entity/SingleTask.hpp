#pragma once

namespace cc {
	
	class SingleTask : noncopyable
	{
	public:
		void pushTask(int16_t nIndex, int16_t nTaskId);
		void popTask(int16_t nIndex);
		int16_t getTask(int16_t nIndex);
		
		void runInit(EntityPtr& nEntity);
		const char * countName();
		
		SingleTask();
		~SingleTask();
		
	private:
		Int16Count mInt16Count;
	};
	
}
