#include "lua.h"
#include "lauxlib.h"

int main()
{
    // init state
    lua_State *L = luaL_newstate();
    // load libs
    luaL_openlibs(L);
    // do file
    luaL_dofile(L, "test.lua");

    return 0;
}