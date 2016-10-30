#pragma once

namespace cc {
	
	class LuaEngine : noncopyable
	{
	public:
		template<typename R, typename... A>
		R runCall(const char * nName, A... nArgs)
		{
			return lua_tinker::call<R>(mLuaState, nName, nArgs...);
		}
		
		template<typename F>
		void runFun(F& nFun, const char * nName)
		{
			lua_tinker::def(mLuaState, nName, nFun);
		}
		
		template<class C>
		void runClass(const char * nName)
		{
			lua_tinker::class_add<C>(mLuaState, nName, true);
			auto f = lua_tinker::constructor<C>::invoke;
			lua_tinker::class_con<C>(mLuaState, f);
		}
		
		template<class C, class B>
		void runInherit()
		{
			lua_tinker::class_inh<C, B>(mLuaState);
		}
		
		template<class C, typename M>
		void runMethod(M nMethod, const char * nName)
		{
			lua_tinker::class_def<C>(mLuaState, nName, nMethod);
		}
		
		template<class C, typename S>
		void runStatic(S& nMethod, const char * nName)
		{
			lua_tinker::class_def_static<C>(mLuaState, nName, nMethod);
		}
		
		LuaThreadPtr createLuaThread(const char * nName);
		
		template<class T>
		void headSerialize(T& nSerialize, const char * nName)
		{
			nSerialize.template runNumbers<list<string>, string>(mLuaScripts, "luaScripts", "luaScript");
		}
		const char * streamName();
		const char * streamUrl();
		
		void runPreinit();
		void runLoad();
		void runStart();
		void runClear();
		
		void openFile(const char * nPath);
		
		static LuaEngine& instance();
		
		LuaEngine();
		~LuaEngine();
		
	private:
		static LuaEngine mLuaEngine;
		
		list<string> mLuaScripts;
		lua_State * mLuaState;
	};
	
}
