#pragma once

namespace cc {
	
	class AutoupDirectory : noncopyable
	{
	public:
		string downloadPath(const char * nPackage);
		string storagePath(const char * nPackage);
		string assetPath(const char * nPackage);
		string tablePath(const char * nPackage);
		string configPath(const char * nPackage);
		
		string pluginDir();
		string pluginPath();
		string updatePath();
		string logPath();
		
		void runInit();
		
		static AutoupDirectory& instance();
		
		AutoupDirectory();
		~AutoupDirectory();
		
	private:
		static AutoupDirectory mAutoupDirectory;
		
		string mRootPath;
	};
	
}
