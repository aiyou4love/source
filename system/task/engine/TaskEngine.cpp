#include "../System.hpp"

namespace cc {
	
	const char * TaskEngine::streamName()
	{
		return "taskEngine";
	}
	
	const char * TaskEngine::streamUrl()
	{
		return "taskEngine.json";
	}
	
	void TaskEngine::runPreinit()
	{
		LifeCycle& lifeCycle_ = LifeCycle::instance();
		lifeCycle_.m_tLoadBegin.connect(bind(&TaskEngine::runLoad, this));
		lifeCycle_.m_tClearEnd.connect(bind(&TaskEngine::runClear, this));
	}
	
	void TaskEngine::runLoad()
	{
		ConfigEngine& configEngine_ = ConfigEngine::instance();
		configEngine_.runReader<TaskEngine>(this, streamUrl(), streamName());
	}
	
	void TaskEngine::runClear()
	{
		mTaskConfigs.clear();
	}
	
	TaskEngine TaskEngine::instance()
	{
		return mTaskEngine;
	}
	
	TaskEngine::TaskEngine()
	{
	}
	
	TaskEngine::~TaskEngine()
	{
	}
	
	TaskEngine TaskEngine::mTaskEngine;
	
}
