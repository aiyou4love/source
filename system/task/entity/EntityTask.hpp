#pragma once

namespace cc {
	
	class EntityTask : noncopyable
	{
	public:
		void pushTask(int16_t nTaskId);
		void popTask(int16_t nTaskId);
		
		void runInit(IntArray * nIntArray);
		
		EntityTask();
		~EntityTask();
		
	private:
		BitCount mBitCount;
	};
	typedef SPTR<EntityTask> EntityTaskPtr;
	
}
