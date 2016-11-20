#pragma once

namespace cc {
	
	class TaskConfig : noncopyable
	{
	public:
		int16_t getTaskIndex();
		int16_t getTaskType();
		int16_t getTaskId();
		
		bool isDefault();
		int16_t getKey();
		
		TaskConfig();
		virtual ~TaskConfig();
		
	protected:
		int16_t mTaskIndex;
		int16_t mTaskType;
		int16_t mTaskId;
	};
	typedef SPTR<TaskConfig> TaskConfigPtr;
	
}
