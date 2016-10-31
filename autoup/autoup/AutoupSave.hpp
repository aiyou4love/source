#pragma once

namespace cc {
	
	class AutoupSave : noncopyable
	{
	public:
		void runUpdate(AutoupItemPtr& nAutoupItem);
		bool isUpdate(AutoupItemPtr& nAutoupItem);
		
		template<class T>
		void serialize(T nSerialize, int8_t nCount)
		{
			nSerialize->runNumber(mUpdateName, "mUpdateName");
			nSerialize->runNumber(mUpdateNo, "mUpdateNo");
		}
		
		const char * getKey();
				
		AutoupSave();
		AutoupSave(AutoupItemPtr& nAutoupItem);
		~AutoupSave();
		
	private:
		string mUpdateName;
		int16_t mUpdateNo;
	};
	typedef std::shared_ptr<AutoupSave> AutoupSavePtr;
	
}
