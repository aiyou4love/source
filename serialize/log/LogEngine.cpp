#include "../Serialize.hpp"

#include <boost/log/sinks.hpp>
#include <boost/log/common.hpp>
#include <boost/log/support/date_time.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/attributes.hpp>
#include <boost/log/utility/setup/console.hpp>

namespace cc {
	
	namespace logging = boost::log;
	namespace sinks = boost::log::sinks;
	namespace keywords = boost::log::keywords;
	namespace expr = boost::log::expressions;
	namespace attrs = boost::log::attributes;
	
	void LogEngine::logError(const char * nValue, ...)
	{
		char buf[1024]; memset(buf, 0, sizeof(buf));
		va_list argList_; va_start(argList_, nValue);
		vsprintf(buf, nValue, argList_);
		va_end(argList_);
		BOOST_LOG(mLogger) << "[ERROR]" << buf;
	}
	
	void LogEngine::logInfo(const char * nValue, ...)
	{
		char buf[1024]; memset(buf, 0, sizeof(buf));
		va_list argList_; va_start(argList_, nValue);
		vsprintf(buf,  nValue, argList_);
		va_end(argList_);
		BOOST_LOG(mLogger) << "[INFO]" << buf;
	}
	
	void LogEngine::logWarn(const char * nValue, ...)
	{
		char buf[1024]; memset(buf, 0, sizeof(buf));
		va_list argList_; va_start(argList_, nValue);
		vsprintf(buf, nValue, argList_);
		va_end(argList_);
		BOOST_LOG(mLogger) << "[WARN]" << buf;
	}
	
	void LogEngine::logMethod(const char * nValue, ...)
	{
		WorkDirectory& workDirectory_ = WorkDirectory::instance();
		bool isLog_ = workDirectory_.isLog();
		if (!isLog_) return;
		char buf[1024]; memset(buf, 0, sizeof(buf));
		va_list argList_; va_start(argList_, nValue);
		vsprintf(buf, nValue, argList_);
		va_end(argList_);
		BOOST_LOG(mLogger) << "[METHOD]" << buf;
	}
	
	void LogEngine::logLua(const char * nValue)
	{
		BOOST_LOG(mLogger) << "[LUA]" << nValue;
	}
	
	void LogEngine::runPreinit(const char * nPath)
	{
		auto consoleSink = logging::add_console_log();
		consoleSink->set_formatter
        (
            expr::format("[%1%]%2%")
                % expr::format_date_time< boost::posix_time::ptime >("TimeStamp", "%m-%d|%H:%M:%S")
                % expr::smessage
        );
        logging::core::get()->add_sink(consoleSink);
		
		typedef sinks::asynchronous_sink< sinks::text_file_backend > text_sink;
		std::string fileName(nPath); fileName += "%Y-%m-%d.log";
		boost::shared_ptr< text_sink > textSink(new text_sink(keywords::file_name = fileName.c_str(),
			keywords::rotation_size = 10 * 1024 * 1024,
			keywords::time_based_rotation = sinks::file::rotation_at_time_point(0, 0, 0),
			keywords::open_mode = (std::ios::out | std::ios::app)
			));
		textSink->set_formatter
        (
            expr::format("[%1%]%2%")
                % expr::format_date_time< boost::posix_time::ptime >("TimeStamp", "%m-%d %H:%M:%S")
                % expr::smessage
        );
    	logging::core::get()->add_sink(textSink);
		logging::core::get()->add_global_attribute("TimeStamp", attrs::local_clock());
		
		LifeCycle& lifeCycle_ = LifeCycle::instance();
		lifeCycle_.m_tClearEnd.connect(bind(&LogEngine::runClear, this));
	}
	
	void LogEngine::runClear()
	{
		logging::core::get()->flush();
		logging::core::get()->remove_all_sinks();
	}
	
	void printlog(const char * nValue)
	{
		LOGL(nValue);
	}
	
	void LogEngine::runLuaApi()
	{
		LuaEngine& luaEngine_ = LuaEngine::instance();
		luaEngine_.runFun(printlog, "printlog");
	}
	
	LogEngine& LogEngine::instance()
	{
		return mLogEngine;
	}
	
	LogEngine::LogEngine()
	{
	}
	
	LogEngine::~LogEngine()
	{
	}
	
	LogEngine LogEngine::mLogEngine;
	
}
