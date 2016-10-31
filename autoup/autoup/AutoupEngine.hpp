#pragma once

namespace cc {
	
	class AutoupEngine : noncopyable
	{
	public:
		int16_t runAutoup();
		
		template<class __t>
		void headSerialize(__t& nSerialize, const char * nName)
		{
			if ( 0 == strcmp(streamName(), nName) ) {
				nSerialize.runNumber(mVersionNo, "versionNo");
				nSerialize.runNumber(mOperatorName, "operatorName");
				nSerialize.runNumber(mUpdateUrl, "updateUrl");
				nSerialize.runNumber(mTimeout, "timeout");
			} else if ( 0 == strcmp(updateName(), nName) ) {
				nSerialize.runNumber(mErrorCode, "mErrorCode");
				nSerialize.runNumber(mUpdateNo, "mVersionNo");
				nSerialize.template runMapStreamPtrs<string, AutoupItemPtr>(mUpdateItems, "mUpdateItems", "updateItem");
			} else if ( 0 == strcmp(saveName(), nName) ) {
				nSerialize.template runMapStreamPtrs<string, AutoupSavePtr>(mSaveItems, "saveItems", "saveItem");
			} else {
				LOGERROR("[%s]%s", __METHOD__, nName);
			}
		}
		const char * streamName();
		const char * streamUrl();
		
		const char * updateName();
		
		const char * saveName();
		const char * saveUrl();
		
		void runInit();
		
		AutoupEngine();
		~AutoupEngine();
		
	private:
		static size_t curlFun(void *, size_t, size_t, void *);
		
		bool getVersionInfo();
		bool versionCheck();
		bool runUpdate();
		void runSave();
		
	private:
		map<string, AutoupItemPtr> mUpdateItems;
		int16_t mErrorCode;
		int16_t mUpdateNo;
		
		map<string, AutoupSavePtr> mSaveItems;
		
		string mOperatorName;
		int16_t mVersionNo;
		string mUpdateUrl;
		int16_t mTimeout;
		
		string mValue;
	};
	
}
