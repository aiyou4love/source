#include "Serialize.hpp"

using namespace cc;

void serializeInit()
{
#ifdef __WINDOW__
	Dump& dump_ = Dump::instance();
	dump_.runPreinit();
#endif
	
	LifeCycle::instance();
	
	WorkDirectory& workDirectory_ = WorkDirectory::instance();
	workDirectory_.runPreinit();
	
	LuaEngine& luaEngine_ = LuaEngine::instance();
	luaEngine_.runPreinit();
	
	RandomEngine& randomEngine_ = RandomEngine::instance();
	randomEngine_.runPreinit();
	
	{
		string logPath_ = workDirectory_.logPath();
		LogEngine& logEngine_ = LogEngine::instance();
		logEngine_.runPreinit(logPath_.c_str());
	}
	
	LOGI("[%s]", __METHOD__);
	
	ConfigEngine::instance();
	workDirectory_.runLoad();
	TableEngine::instance();
	UserDefault::instance();
	
	LOGI("[%s]1", __METHOD__);
}

void serializeStart()
{
	LOGI("[%s]1", __METHOD__);
	
	LifeCycle& lifeCycle_
		= LifeCycle::instance();
		
	lifeCycle_.runLuaApi();
	
	LOGI("[%s]2", __METHOD__);
	
	lifeCycle_.loadBegin();
	lifeCycle_.loading();
	lifeCycle_.loadEnd();
	
	LOGI("[%s]3", __METHOD__);
	
	lifeCycle_.initBegin();
	lifeCycle_.initing();
	lifeCycle_.initEnd();
	
	LOGI("[%s]4", __METHOD__);
	
	lifeCycle_.startBegin();
	lifeCycle_.starting();
	lifeCycle_.startEnd();
	
	LOGI("[%s]5", __METHOD__);
	
	lifeCycle_.runBegin();
	lifeCycle_.running();
	lifeCycle_.runEnd();
	
	LOGI("[%s]6", __METHOD__);
	
	lifeCycle_.runJoin();
	
	LOGI("[%s]7", __METHOD__);
	
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
