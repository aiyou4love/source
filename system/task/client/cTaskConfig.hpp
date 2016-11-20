#pragma once

namespace cc {
	
#ifdef __CLIENT__
	class cTaskConfig : public TaskConfig
	{
	public:
		const char * getName();
		const char * getText();
		int16_t getOpenType();
		int32_t getOpenId();
		
		template <class T>
		void serialize(T * nSerialize, const char * nName, int8_t nCount)
		{
			nSerialize->runNumber(mOpenType, "openType");
			nSerialize->runNumber(mOpenId, "openId");
			nSerialize->runNumber(mTaskIndex, "taskIndex");
			nSerialize->runNumber(mTaskType, "taskType");
			nSerialize->runNumber(mTaskId, "taskId");
			nSerialize->runNumber(mName, "name");
			nSerialize->runNumber(mText, "text");
		}
		
		cTaskConfig();
		~cTaskConfig();
		
	private:
		int16_t mOpenType;
		int32_t mOpenId;
		string mName;
		string mText;
	};
	typedef SPTR<cTaskConfig> cTaskConfigPtr;
#endif
	
}
