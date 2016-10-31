#pragma once

namespace cc {
	
	class AutoupItem : noncopyable
	{
	public:
		bool runUpdate(int16_t nTimeout);
		
		const char * getUpdateName();
		int16_t getUpdateNo();
		
	private:
		static size_t curlFun(void *, size_t, size_t, void *);
		
		bool runDownload(int16_t nTimeout);
		bool runUncompress();
		
	public:
		template<class T>
		void serialize(T nSerialize, int8_t nCount)
		{
			nSerialize->runNumber(mUpdateNo, "mUpdateNo");
			nSerialize->runNumber(mUpdateName, "mUpdateName");
			nSerialize->runNumber(mPacketName, "mPacketName");
			nSerialize->runNumber(mDownloadUrl, "mDownloadUrl");
		}
		
		const char * getKey();
		
		AutoupItem();
		~AutoupItem();
		
	private:
		string mDownloadUrl;
		string mPacketName;
		string mUpdateName;
		int16_t mUpdateNo;
		
		FILE * mHandle;
	};
	typedef std::shared_ptr<AutoupItem> AutoupItemPtr;
	
}
