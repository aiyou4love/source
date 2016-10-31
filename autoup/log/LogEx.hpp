#pragma once

namespace cc {
	
	namespace src = boost::log::sources;
	
	class LogEx : noncopyable
	{
	public:
		void logError(const char * nValue, ...);
		void logInfo(const char * nValue, ...);
		void logWarn(const char * nValue, ...);
		void logMethod(const char * nValue, ...);

		void runInit(const char * nPath);
		void runClear();
		
		static LogEx& instance();
		
		LogEx();
		~LogEx();
		
	private:
		static LogEx mLogEx;
		
		src::logger mLogger;
	};
#define LOGERROR LogEx::instance().logError
#define LOGINFO LogEx::instance().logInfo
#define LOGWARN LogEx::instance().logWarn
#define LOGFUN LogEx::instance().logMethod("[%s]", __METHOD__);

}
