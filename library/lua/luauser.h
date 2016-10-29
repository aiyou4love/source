#ifndef luauser_h
#define luauser_h

extern void LuaLockInitial(lua_State * L);
extern void LuaLockFinal(lua_State * L);
extern void LuaLock(lua_State * L);
extern void LuaUnlock(lua_State * L);

#endif
