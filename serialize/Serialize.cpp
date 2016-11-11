#include "Serialize.hpp"

using namespace cc;

void serializeInit()
{
	LifeCycle::instance();
	
	WorkDirectory& workDirectory_ = WorkDirectory::instance();
	workDirectory_.runPreinit();
	
	LuaEngine& luaEngine_ = LuaEngine::instance();
	luaEngine_.runPreinit();
	
	{
		string logPath_ = workDirectory_.logPath();
		LogEngine& logEngine_ = LogEngine::instance();
		logEngine_.runPreinit(logPath_.c_str());
	}
	
	ConfigEngine::instance();
	workDirectory_.runLoad();
	TableEngine::instance();
	UserDefault::instance();
}

void serializeStart()
{
	LifeCycle& lifeCycle_
		= LifeCycle::instance();
		
	lifeCycle_.runLuaApi();
	
	lifeCycle_.loadBegin();
	lifeCycle_.loading();
	lifeCycle_.loadEnd();
	
	lifeCycle_.initBegin();
	lifeCycle_.initing();
	lifeCycle_.initEnd();
	
	lifeCycle_.startBegin();
	lifeCycle_.starting();
	lifeCycle_.startEnd();
	
	lifeCycle_.runBegin();
	lifeCycle_.running();
	lifeCycle_.runEnd();
	
	lifeCycle_.runJoin();
	
	lifeCycle_.stopBegin();
	lifeCycle_.stoping();
	lifeCycle_.stopEnd();
	
	lifeCycle_.saveBegin();
	lifeCycle_.saving();
	lifeCycle_.saveEnd();
	
	lifeCycle_.closeBegin();
	lifeCycle_.closing();
	lifeCycle_.closeEnd();
	
	lifeCycle_.clearBegin();
	lifeCycle_.clearing();
	lifeCycle_.clearEnd();
}
