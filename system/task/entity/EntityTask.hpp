#pragma once

namespace cc {
	
	class EntityTask : public Property
	{
	public:
		void runInit(EntityPtr& nEntity);
		
		EntityTask();
		~EntityTask();
		
	private:
		TaskAccept mTaskAccept;
		TaskFinish mTaskFinish;
	};
	typedef SPTR<EntityTask> EntityTaskPtr;
	
}
