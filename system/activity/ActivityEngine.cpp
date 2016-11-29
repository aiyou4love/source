#include "../System.hpp"

namespace cc {
	
#ifdef __CLIENT__
	const char * ActivityEngine::streamName()
	{
		return "activityEngine";
	}
	
	const char * ActivityEngine::streamUrl()
	{
		return "activityEngine.json";
	}
	
	void ActivityEngine::runPreinit()
	{
		LifeCycle& lifeCycle_ = LifeCycle::instance();
		lifeCycle_.m_tLoadBegin.connect(bind(&ActivityEngine::runLoad, this));
		lifeCycle_.m_tClearEnd.connect(bind(&ActivityEngine::runClear, this));
	}
	
	void ActivityEngine::runLoad()
	{
		ConfigEngine& configEngine_ = ConfigEngine::instance();
		configEngine_.runReader<ActivityEngine>(this, streamUrl(), streamName());
	}
	
	void ActivityEngine::runClear()
	{
		mActivityConfigs.clear();
	}
	
	ActivityEngine& ActivityEngine::instance()
	{
		return mActivityEngine;
	}
	
	ActivityEngine::ActivityEngine()
	{
	}
	
	ActivityEngine::~ActivityEngine()
	{
	}
	
	ActivityEngine ActivityEngine::mActivityEngine;
#endif
	
}
