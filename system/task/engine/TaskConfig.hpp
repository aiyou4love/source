#pragma once

namespace cc {
	
	class TaskConfig : noncopyable
	{
	public:
		template <class T>
		void serialize(T * nSerialize, const char * nName, int8_t nCount)
		{
			nSerialize->runNumber(mAcceptId, "acceptId");
			nSerialize->runNumber(mFinishId, "finishId");
			nSerialize->runNumber(mTaskId, "taskId");
		}
		
		bool isDefault();
		int16_t getKey();
		
		TaskConfig();
		~TaskConfig();
		
	private:
		int32_t mAcceptId;
		int32_t mFinishId;
		int16_t mTaskId;
	};
	typedef SPTR<TaskConfig> TaskConfigPtr;
	
}
