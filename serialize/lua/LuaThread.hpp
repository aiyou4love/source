#pragma once

namespace cc {
	
	class LuaThread : noncopyable
	{
	public:
		template<typename R, typename... A>
		R runCall(const char * nName, A... nArgs)
		{
			return lua_tinker::tcall<R>(mLuaState, mName.c_str(), nName, nArgs...);
		}
		
		void openFile(const char * nPath);
		void runClose();
		
		explicit LuaThread(lua_State * nLuaState, const char * nName);
		~LuaThread();
		
	private:
		lua_State * mLuaState;
		string mName;
		int mLuaRef;
	};
	typedef SPTR<LuaThread> LuaThreadPtr;
	typedef WPTR<LuaThread> LuaThreadWtr;
	
}
