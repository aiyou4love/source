#include "../Serialize.hpp"

namespace cc {
	
	string WorkDirectory::uiEventPath(const char * nPath, int8_t nType)
	{
		const char * eventName_ = this->getUiEventName(nType);
		string value_ = mUpdateUi + nPath;
		value_ += eventName_;
		filesystem::path path_(value_);
		if (filesystem::exists(value_)) {
			return value_;
		}
		value_ = mUiPath + nPath;
		value_ += eventName_;
		if (filesystem::exists(value_)) {
			return value_;
		}
		value_ = "";
		return value_;
	}
	
	const char * WorkDirectory::getUiEventName(int8_t nType)
	{
		if (EuiType::mConsole == nType) {
			return "/event.con.json";
		} else if (EuiType::mCocos2dx == nType) {
			return "/event.2dx.json";
		} else if (EuiType::mUE4 == nType) {
			return "/event.ue4.json";
		} else {
			LOGE("[%s]%d", __METHOD__, nType);
			return "/event.json";
		}
	}
	
	string WorkDirectory::uiJsonPath(const char * nPath, int8_t nType)
	{
		const char * jsonName_ = this->getUiJsonName(nType);
		string value_ = mUpdateUi + nPath;
		value_ += jsonName_;
		filesystem::path path_(value_);
		if (filesystem::exists(value_)) {
			return value_;
		}
		value_ = mUiPath + nPath;
		value_ += jsonName_;
		if (filesystem::exists(value_)) {
			return value_;
		}
		value_ = "";
		return value_;
	}
	
	const char * WorkDirectory::getUiJsonName(int8_t nType)
	{
		if (EuiType::mConsole == nType) {
			if (mIsJson) {
				return "/ui.con.json";
			} else {
				return "/ui.con.xml";
			}
		} else if (EuiType::mCocos2dx == nType) {
			if (mIsJson) {
				return "/ui.2dx.json";
			} else {
				return "/ui.2dx.xml";
			}
		} else if (EuiType::mUE4 == nType) {
			if (mIsJson) {
				return "/ui.ue4.json";
			} else {
				return "/ui.ue4.xml";
			}
		} else {
			LOGE("[%s]%d", __METHOD__, nType);
			if (mIsJson) {
				return "/ui.json";
			} else {
				return "/ui.xml";
			}
		}
	}
	
	string WorkDirectory::uiLuaPath(const char * nPath, int8_t nType)
	{
		const char * luaName_ = this->getUiLuaName(nType);
		string value_ = mUpdateUi + nPath;
		value_ += luaName_;
		filesystem::path path_(value_);
		if (filesystem::exists(value_)) {
			return value_;
		}
		value_ = mUiPath + nPath;
		value_ += luaName_;
		if (filesystem::exists(value_)) {
			return value_;
		}
		value_ = "";
		return value_;
	}
	
	const char * WorkDirectory::getUiLuaName(int8_t nType)
	{
		if (EuiType::mConsole == nType) {
			return "/ui.con.lua";
		} else if (EuiType::mCocos2dx == nType) {
			return "/ui.2dx.lua";
		} else if (EuiType::mUE4 == nType) {
			return "/ui.ue4.lua";
		} else {
			LOGE("[%s]%d", __METHOD__, nType);
			return "/ui.lua";
		}
	}
	
	string WorkDirectory::uiStringPath(const char * nPath, int8_t nType)
	{
		string stringName_ = this->getUiStringName(nType);
		string value_ = mUpdateUi + nPath;
		value_ += stringName_;
		filesystem::path path_(value_);
		if (filesystem::exists(value_)) {
			return value_;
		}
		value_ = mUiPath + nPath;
		value_ += stringName_;
		if (filesystem::exists(value_)) {
			return value_;
		}
		value_ = "";
		return value_;
	}
	
	string WorkDirectory::getUiStringName(int8_t nType)
	{
		string result_ = "/string.";
		result_ += mLanguage;
		if (EuiType::mConsole == nType) {
			result_ += ".con.json";
		} else if (EuiType::mCocos2dx == nType) {
			result_ += ".2dx.json";
		} else if (EuiType::mUE4 == nType) {
			result_ += ".ue4.json";
		} else {
			LOGE("[%s]%d", __METHOD__, nType);
			result_ += ".json";
		}
		return result_;
	}
	
	string WorkDirectory::uiCorePath(const char * nPath, int8_t nType)
	{
		const char * coreName_ = this->getUiCoreName(nType);
		string value_ = mUpdateUi + nPath;
		value_ += coreName_;
		filesystem::path path_(value_);
		if (filesystem::exists(value_)) {
			return value_;
		}
		value_ = mUiPath + nPath;
		value_ += coreName_;
		if (filesystem::exists(value_)) {
			return value_;
		}
		value_ = "";
		return value_;
	}
	
	const char * WorkDirectory::getUiCoreName(int8_t nType)
	{
		if (EuiType::mConsole == nType) {
			return "/core.con.lua";
		} else if (EuiType::mCocos2dx == nType) {
			return "/core.2dx.lua";
		} else if (EuiType::mUE4 == nType) {
			return "/core.ue4.lua";
		} else {
			LOGE("[%s]%d", __METHOD__, nType);
			return "/core.lua";
		}
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
	
	const char * WorkDirectory::getLanguage()
	{
		return mLanguage.c_str();
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
#endif
		locale locale_;
		cout.imbue(locale_);
		
		mLanguage = locale_.name();
		cout << mLanguage << endl;
		
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
		
		mLanguage = "";
		
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
