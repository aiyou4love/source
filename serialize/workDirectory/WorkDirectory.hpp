#pragma once

namespace cc {
	
	class WorkDirectory : noncopyable
	{
	public:
		string getUiPath(const char * nPath, const char * nType);
		
		string storagePath(const char * nPath);
		string resourcePath(const char * nPath);
		string configPath(const char * nPath);
		string tablePath(const char * nPath);
		string luaPath(const char * nPath);
		
		const char * logPath();
		
		void setLanguage(const char * nValue);
		const char * getLanguage();
		
		const char * getOperatorName();
		int16_t getVersionNo();
		int16_t getAppType();
		int16_t getClassifyId();
		int32_t getAppNo();
		int64_t getAppId(int16_t nAppType);
		int64_t getAppId();
		int16_t getUpdateNo();
		
		bool isConsole();
		bool isRunning();
		bool isLog();
		bool isJson();
		
		template<class T>
		void headSerialize(T& nSerialize, const char * nName)
		{
			if ( 0 == strcmp(configName(), nName) ) {
				nSerialize.runNumber(mAppType, "appType");
				nSerialize.runNumber(mVersionNo, "versionNo");
				nSerialize.runNumber(mOperatorName, "operatorName");
			} else if ( 0 == strcmp(streamName(), nName) ) {
				nSerialize.runNumber(mClassifyId, "classifyId");
				nSerialize.runNumber(mUpdateNo, "updateNo");
				nSerialize.runNumber(mAppNo, "appNo");
				nSerialize.runNumber(mIsJson, "isJson");
				nSerialize.runNumber(mRunning, "running");
				nSerialize.runNumber(mIsLog, "isLog");
				nSerialize.runNumber(mIsConsole, "isConsole");
			} else {
				LOGE("[%s]%s", __METHOD__, nName);
			}
		}
		const char * streamName();
		const char * streamUrl();
		
		const char * configName();
		const char * configUrl();
		
		void runPreinit();
		void runLoad();
		void runClear();
		
		static WorkDirectory& instance();
		
		WorkDirectory();
		~WorkDirectory();
		
	private:
		static WorkDirectory mWorkDirectory;
		
		string mLanguage;
		
		string mRootPath;
		string mLogPath;
		string mStoragePath;
		string mAssetPath;
		string mUpdatePath;
		string mConfigPath;
		
		string mLuaPath;
		string mUpdateLua;
		string mTablePath;
		string mUpdateTable;
		string mUiPath;
		string mUpdateUi;
		
		string mOperatorName;
		int16_t mVersionNo;
		int16_t mAppType;
		int16_t mClassifyId;
		int32_t mAppNo;
		int16_t mUpdateNo;
		
		bool mRunning;
		bool mIsJson;
		bool mIsLog;
		bool mIsConsole;
	};
	
}
