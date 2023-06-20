#include <stdio.h>
#include <lualib.h>
#include <lauxlib.h>
lua_State *L;
void main(int argc, char *argv[])
{
    /* Create a Lua state */
    L = luaL_newstate();
    /* Check the return value */
    if (L == NULL)
    {
        fprintf(stderr, "Lua: cannot initialize\n");
        return -1;
    }
    /* Provide the Lua standard libraries to the Lua state */
    luaL_openlibs(L);
    /* Execute a Lua program in script.lua */
    luaL_dofile(L, "script.lua");
    /* Close the Lua state */
    lua_close(L);
    return 0;
}