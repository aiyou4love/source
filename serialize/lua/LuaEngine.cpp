#include "../Serialize.hpp"

namespace cc {
	
	LuaThreadPtr LuaEngine::createLuaThread(const char * nName)
	{
		return LuaThreadPtr(new LuaThread(mLuaState, nName));
	}
	
	const char * LuaEngine::streamName()
	{
		return "luaEngine";
	}
	
	const char * LuaEngine::streamUrl()
	{
		return "luaEngine.json";
	}
	
	void LuaEngine::runPreinit()
	{
		mLuaState = luaL_newstate();
		luaL_openlibs(mLuaState);
		lua_tinker::init(mLuaState);
		
		LifeCycle& lifeCycle_ = LifeCycle::instance();
		lifeCycle_.m_tLoadBegin.connect(bind(&LuaEngine::runLoad, this));
		lifeCycle_.m_tStartBegin.connect(bind(&LuaEngine::runStart, this));
		lifeCycle_.m_tClearEnd.connect(bind(&LuaEngine::runClear, this));
	}
	
	void LuaEngine::runLoad()
	{
		TableEngine& tableEngine_ = TableEngine::instance();
		tableEngine_.runReader<LuaEngine>(this, streamUrl(), streamName());
	}
	
	void LuaEngine::runStart()
	{
		WorkDirectory& workDirectory_ = WorkDirectory::instance();
		
		auto it = mLuaScripts.begin();
		for ( ; it != mLuaScripts.end(); ++it ) {
			string& value_ = (*it);
			string luaPath_ = workDirectory_.luaPath(value_.c_str());
			this->openFile(luaPath_.c_str());
		}
	}
	
	void LuaEngine::runClear()
	{
		if ( nullptr != mLuaState ) {
			lua_close(mLuaState);
			mLuaState = nullptr;
		}
		mLuaScripts.clear();
	}
	
	void LuaEngine::openFile(const char * nPath)
	{
		lua_tinker::dofile(mLuaState, nPath);
	}
	
	LuaEngine& LuaEngine::instance()
	{
		return mLuaEngine;
	}
	
	LuaEngine::LuaEngine()
		: mLuaState(nullptr)
	{
		mLuaScripts.clear();
	}
	
	LuaEngine::~LuaEngine()
	{
		this->runClear();
	}
	
	LuaEngine LuaEngine::mLuaEngine;
	
}
