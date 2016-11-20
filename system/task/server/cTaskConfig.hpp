#pragma once

namespace cc {
	
#ifndef __CLIENT__
	class cTaskConfig : public TaskConfig
	{
	public:
		template <class T>
		void serialize(T * nSerialize, const char * nName, int8_t nCount)
		{
			nSerialize->runNumber(mTaskIndex, "taskIndex");
			nSerialize->runNumber(mTaskType, "taskType");
			nSerialize->runNumber(mTaskId, "taskId");
		}
		
		cTaskConfig();
		~cTaskConfig();
	};
	typedef SPTR<cTaskConfig> TaskConfigPtr;
#endif
	
}
