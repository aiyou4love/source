#pragma once

namespace cc {
	
	namespace src = boost::log::sources;
	
	class LogEngine : noncopyable
	{
	public:
		void logError(const char * nValue, ...);
		void logInfo(const char * nValue, ...);
		void logWarn(const char * nValue, ...);
		void logMethod(const char * nValue, ...);
		void logLua(const char * nValue);
		
		void runPreinit(const char * nPath);
		void runClear();
		
		static void runLuaApi();
		
		static LogEngine& instance();
		
		LogEngine();
		~LogEngine();
		
	private:
		static LogEngine mLogEngine;
		
		src::logger mLogger;
	};
#define LOGE LogEngine::instance().logError
#define LOGI LogEngine::instance().logInfo
#define LOGW LogEngine::instance().logWarn
#define LOGL LogEngine::instance().logLua
#define LOGF LogEngine::instance().logMethod("[%s]", __METHOD__);
}
