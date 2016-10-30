#include "../Serialize.hpp"

namespace cc {
	
	void LuaThread::openFile(const char * nPath)
	{
		lua_tinker::tdofile(mLuaState, nPath, mName.c_str());
	}
	
	void LuaThread::runClose()
	{
		if (nullptr != mLuaState) {
			luaL_unref(mLuaState, LUA_REGISTRYINDEX, mLuaRef);
			lua_tinker::closethread(mLuaState, mName.c_str());
		}
		mLuaState = nullptr;
		mName = "";
	}
	
	LuaThread::LuaThread(lua_State * nLuaState, const char * nName)
		: mName (nName)
	{
		mLuaState = lua_newthread(nLuaState);
		lua_pushthread(mLuaState);
		mLuaRef = luaL_ref(mLuaState, LUA_REGISTRYINDEX);
		lua_tinker::createthread(mLuaState, mName.c_str());
	}
	
	LuaThread::~LuaThread()
	{
		this->runClose();
	}
	
}
