#include "../AutoupInc.hpp"

namespace cc {
	
	string AutoupDirectory::downloadPath(const char * nPackage)
	{
		return (mRootPath + "/download/" + nPackage);
	}
	
	string AutoupDirectory::assetPath(const char * nPackage)
	{
		return (mRootPath + "/asset/" + nPackage);
	}
	
	string AutoupDirectory::tablePath(const char * nPackage)
	{
		return (mRootPath + "/asset/table/" + nPackage);
	}
	
	string AutoupDirectory::configPath(const char * nPackage)
	{
		return (mRootPath + "/asset/config/" + nPackage);
	}
	
	string AutoupDirectory::storagePath(const char * nPackage)
	{
		return (mRootPath + "/storage/" + nPackage);
	}
	
	string AutoupDirectory::pluginDir()
	{
		return (mRootPath + "/plugin/");
	}
	
	string AutoupDirectory::pluginPath()
	{
		string update_ = mRootPath + "/plugin/";
		update_ += SODLLNAME;
		filesystem::path path_(update_);
		if (filesystem::exists(update_)) {
			return update_;
		}
		string value_ = mRootPath + "/asset/plugin/";
		value_ += SODLLZIP;
		if (filesystem::exists(value_)) {
			string updatePath_ = this->pluginDir();
			zip_file zipFile_(value_.c_str());
			zipFile_.extractall(updatePath_.c_str());
		}
		if (filesystem::exists(update_)) {
			return update_;
		}
		value_ = "";
		return value_;
	}
	
	string AutoupDirectory::updatePath()
	{
		return (mRootPath + "/update/");
	}
	
	string AutoupDirectory::logPath()
	{
		return (mRootPath + "/log/");
	}
	
	AutoupDirectory& AutoupDirectory::instance()
	{
		return mAutoupDirectory;
	}
	
	static string stringTrim(const string& nValue, const string& nTrim)
	{
		string value_("");
		for (size_t i = 0; i < nValue.length(); ++i) {
			if ((nValue[i] == ' ') || (nValue[i] == '\t')
				|| (nValue[i] == '\r') || (nValue[i] == '\n')) {
				continue;
			}
			bool continue_ = false;
			for (size_t j = 0; j < nTrim.length(); ++j) {
				if (nValue[i] == nTrim[j]) {
					continue_ = true;
					break;
				}
			}
			if (continue_) {
				continue;
			}
			value_ = nValue.substr(i);
			break;
		}
		for (size_t i = value_.length(); i > 0; --i) {
			if ((value_[i - 1] == ' ') || (value_[i - 1] == '\t')
				|| (value_[i - 1] == '\r') || (value_[i - 1] == '\n')) {
				continue;
			}
			bool continue_ = false;
			for (size_t j = 0; j < nTrim.length(); ++j) {
				if (value_[i - 1] == nTrim[j]) {
					continue_ = true;
					break;
				}
			}
			if (continue_) continue;
			value_ = value_.substr(0, i);
			break;
		}
		return value_;
	}

	static string stringBackslant(const string& nValue)
	{
		string result_ = stringTrim(nValue, "/\\");
		for (size_t i = 0; i < result_.length(); ++i) {
			if ((result_[i] == '\\')) {
				result_[i] = '/';
			}
		}
		return result_;
	}

	void AutoupDirectory::runInit()
	{
#ifdef __WINDOW__
		TCHAR buf[MAX_PATH];
		GetCurrentDirectory(MAX_PATH, buf);
		basic_string<TCHAR> workingDirectory(buf);
		string value_(workingDirectory.begin(), workingDirectory.end());
		mRootPath = stringBackslant(value_);
#endif // __WINDOW__
		{
			filesystem::path path_(mRootPath);
			path_ /= "download";
			if (!filesystem::exists(path_)) {
				filesystem::create_directory(path_);
			}
		}
		{
			filesystem::path path_(mRootPath);
			path_ /= "asset";
			if (!filesystem::exists(path_)) {
				filesystem::create_directory(path_);
			}
			path_ /= "table";
			if (!filesystem::exists(path_)) {
				filesystem::create_directory(path_);
			}
		}
		{
			filesystem::path path_(mRootPath);
			path_ /= "storage";
			if (!filesystem::exists(path_)) {
				filesystem::create_directory(path_);
			}
		}
		{
			filesystem::path path_(mRootPath);
			path_ /= "update";
			if (!filesystem::exists(path_)) {
				filesystem::create_directory(path_);
			}
		}
		{
			filesystem::path path_(mRootPath);
			path_ /= "plugin";
			if (!filesystem::exists(path_)) {
				filesystem::create_directory(path_);
			}
		}
		{
			filesystem::path path_(mRootPath);
			path_ /= "log";
			if (!filesystem::exists(path_)) {
				filesystem::create_directory(path_);
			}
		}
	}
	
	AutoupDirectory::AutoupDirectory()
		: mRootPath ("")
	{
	}
	
	AutoupDirectory::~AutoupDirectory()
	{
		mRootPath = "";
	}
	
	AutoupDirectory AutoupDirectory::mAutoupDirectory;
	
}
