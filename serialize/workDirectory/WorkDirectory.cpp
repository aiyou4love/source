#include "../Serialize.hpp"

namespace cc {
	
	string WorkDirectory::uiEventPath(const char * nPath)
	{
		string value_ = mUpdateUi + nPath;
		value_ += "/event.json";
		filesystem::path path_(value_);
		if (filesystem::exists(value_)) {
			return value_;
		}
		value_ = mUiPath + nPath;
		value_ += "/event.json";
		if (filesystem::exists(value_)) {
			return value_;
		}
		value_ = "";
		return value_;
	}
	
	string WorkDirectory::uiJsonPath(const char * nPath)
	{
		string value_ = mUpdateUi + nPath;
		value_ += "/ui";
		if (mIsJson) {
			value_ += ".json";
		} else {
			value_ += ".xml";
		}
		filesystem::path path_(value_);
		if (filesystem::exists(value_)) {
			return value_;
		}
		value_ = mUiPath + nPath;
		value_ += "/ui";
		if (mIsJson) {
			value_ += ".json";
		} else {
			value_ += ".xml";
		}
		if (filesystem::exists(value_)) {
			return value_;
		}
		value_ = "";
		return value_;
	}
	
	string WorkDirectory::uiLuaPath(const char * nPath)
	{
		string value_ = mUpdateUi + nPath;
		value_ += "/ui.lua";
		filesystem::path path_(value_);
		if (filesystem::exists(value_)) {
			return value_;
		}
		value_ = mUiPath + nPath;
		value_ += "/ui.lua";
		if (filesystem::exists(value_)) {
			return value_;
		}
		value_ = "";
		return value_;
	}
	
	string WorkDirectory::uiStringPath(const char * nPath)
	{
		string value_ = mUpdateUi + nPath;
		value_ += "/string.json";
		filesystem::path path_(value_);
		if (filesystem::exists(value_)) {
			return value_;
		}
		value_ = mUiPath + nPath;
		value_ += "/string.json";
		if (filesystem::exists(value_)) {
			return value_;
		}
		value_ = "";
		return value_;
	}
	
	string WorkDirectory::uiCorePath(const char * nPath)
	{
		string value_ = mUpdateUi + nPath;
		value_ += "/core.lua";
		filesystem::path path_(value_);
		if (filesystem::exists(value_)) {
			return value_;
		}
		value_ = mUiPath + nPath;
		value_ += "/core.lua";
		if (filesystem::exists(value_)) {
			return value_;
		}
		value_ = "";
		return value_;
	}
	
	string WorkDirectory::storagePath(const char * nPath)
	{
		return (mStoragePath + nPath);
	}
	
	string WorkDirectory::tablePath(const char * nPath)
	{
		string value_ = mUpdateTable + nPath;
		filesystem::path path_(value_);
		if (filesystem::exists(value_)) {
			return value_;
		}
		value_ = mTablePath + nPath;
		if (filesystem::exists(value_)) {
			return value_;
		}
		value_ = "";
		return value_;
	}
	
	string WorkDirectory::configPath(const char * nPath)
	{
		string value_ = mConfigPath + nPath;
		if (filesystem::exists(value_)) {
			return value_;
		}
		value_ = "";
		return value_;
	}
	
	string WorkDirectory::luaPath(const char * nPath)
	{
		string value_ = mUpdateLua + nPath;
		value_ += ".lua";
		filesystem::path path_(value_);
		if (filesystem::exists(value_)) {
			return value_;
		}
		value_ = mLuaPath + nPath;
		value_ += ".lua";
		if (filesystem::exists(value_)) {
			return value_;
		}
		value_ = "";
		return value_;
	}
	
	string WorkDirectory::resourcePath(const char * nPath)
	{
		string value_ = mUpdatePath + nPath;
		filesystem::path path_(value_);
		if (filesystem::exists(value_)) {
			return value_;
		}
		value_ = mAssetPath + nPath;
		if (filesystem::exists(value_)) {
			return value_;
		}
		value_ = "";
		return value_;
	}
	
	const char * WorkDirectory::logPath()
	{
		return mLogPath.c_str();
	}
	
	const char * WorkDirectory::getOperatorName()
	{
		return mOperatorName.c_str();
	}
	
	int16_t WorkDirectory::getVersionNo()
	{
		return mVersionNo;
	}
	
	int16_t WorkDirectory::getUpdateNo()
	{
		return mUpdateNo;
	}
	
	int16_t WorkDirectory::getAppType()
	{
		return mAppType;
	}
	
	int64_t WorkDirectory::getAppId(int16_t nAppType)
	{
		return linkInt32(nAppType, 0);
	}
	
	int64_t WorkDirectory::getAppId()
	{
		return linkInt32(mAppType, mAppNo);
	}
	
	int32_t WorkDirectory::getAppNo()
	{
		return mAppNo;
	}
	
	int16_t WorkDirectory::getClassifyId()
	{
		return mClassifyId;
	}
	
	bool WorkDirectory::isRunning()
	{
		return mRunning;
	}
	
	bool WorkDirectory::isLog()
	{
		return mIsLog;
	}
	
	bool WorkDirectory::isConsole()
	{
		return mIsConsole;
	}
	
	WorkDirectory& WorkDirectory::instance()
	{
		return mWorkDirectory;
	}
	
	void WorkDirectory::runPreinit()
	{
#ifdef __WINDOW__
		TCHAR buf[MAX_PATH];
		GetCurrentDirectory(MAX_PATH, buf);
		basic_string<TCHAR> workingDirectory(buf);
		string value_(workingDirectory.begin(), workingDirectory.end());
		mRootPath = stringBackslant(value_);
#endif // __WINDOW__
		mLogPath = mRootPath + "/log/";
		mStoragePath = mRootPath + "/storage/";
		mAssetPath = mRootPath + "/asset/";
		mUpdatePath = mRootPath + "/update/";
		
		mLuaPath = mAssetPath + "lua/";
		mUpdateLua = mUpdatePath + "lua/";
		mTablePath = mAssetPath + "table/";
		mConfigPath = mAssetPath + "config/";
		mUpdateTable = mUpdatePath + "table/";
		mUiPath = mAssetPath + "ui/";
		mUpdateUi = mUpdatePath + "ui/";
		
		LifeCycle& lifeCycle_ = LifeCycle::instance();
		lifeCycle_.m_tClearEnd.connect(bind(&WorkDirectory::runClear, this));
	}
	
	void WorkDirectory::runLoad()
	{
		ConfigEngine& configEngine_ = ConfigEngine::instance();
		configEngine_.runReader<WorkDirectory>(this, configUrl(), configName());
		configEngine_.runReader<WorkDirectory>(this, streamUrl(), streamName());
	}
	
	void WorkDirectory::runClear()
	{
		mOperatorName = "";
		mVersionNo = 0;
		mAppType = 0;
		mAppNo = 0;
		mClassifyId = 0;
		mUpdateNo = 0;
		
		mRootPath = "";
		mLogPath = "";
		mStoragePath = "";
		mAssetPath = "";
		mUpdatePath = "";
		mConfigPath = "";
		
		mLuaPath = "";
		mUpdateLua = "";
		mTablePath = "";
		mUpdateTable = "";
		mUiPath = "";
		mUpdateUi = "";
		
		mIsJson = false;
		mRunning = false;
		mIsLog = false;
		mIsConsole = false;
	}
	
	const char * WorkDirectory::streamName()
	{
		return "workDirectory";
	}
	
	const char * WorkDirectory::streamUrl()
	{
		return "workDirectory.json";
	}
	
	const char * WorkDirectory::configName()
	{
		return "autoupEngine";
	}
	
	const char * WorkDirectory::configUrl()
	{
		return "autoupEngine.json";
	}
	
	WorkDirectory::WorkDirectory()
	{
		this->runClear();
	}
	
	WorkDirectory::~WorkDirectory()
	{
		this->runClear();
	}
	
	WorkDirectory WorkDirectory::mWorkDirectory;
	
}
