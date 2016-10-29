#include "lua.h"
#include "luauser.h"

#ifdef LUA_USE_WINDOWS
#include <windows.h>
#endif

#ifdef LUA_USE_WINDOWS
static CRITICAL_SECTION mLockSct;
#endif

void LuaLockInitial(lua_State * L)
{
#ifdef LUA_USE_WINDOWS
	InitializeCriticalSection(&mLockSct);
#endif
}

void LuaLockFinal(lua_State * L)
{
#ifdef LUA_USE_WINDOWS
	DeleteCriticalSection(&mLockSct);
#endif
}

void LuaLock(lua_State * L)
{
#ifdef LUA_USE_WINDOWS
	EnterCriticalSection(&mLockSct);
#endif
}

void LuaUnlock(lua_State * L)
{
#ifdef LUA_USE_WINDOWS
	LeaveCriticalSection(&mLockSct);
#endif
}
