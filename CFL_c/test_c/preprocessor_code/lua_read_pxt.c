#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"
#include "lua_read_pxt.h"


static int changeWorkingDirectory(lua_State* L) {
    const char* newDir = luaL_checkstring(L, 1);  // Get the new directory path from Lua

    if (chdir(newDir) != 0) {
        lua_pushnil(L);
        lua_pushstring(L, "Error changing working directory");
        return 2;
    }

    lua_pushboolean(L, 1);  // Return true to indicate success
    return 1;
}
static int readPxtFiles(lua_State* L) {
    const char* directory;
    DIR* dir;
    int index;
    struct dirent* entry;
    int nargs;
     nargs = lua_gettop(L);
    if (nargs < 1) {
        return luaL_error(L, "Invalid number of arguments. Expected 1");
    }
    directory = luaL_checkstring(L, 1);  // Get the directory path from Lua
    dir = opendir(directory);

    if (dir == NULL) {
        lua_pushstring(L, "Error opening directory");
        lua_error(L);
    }

    lua_newtable(L);  // Create a new Lua table to store the file names
    
    
    index = 1;  // Index for Lua table
    while ((entry = readdir(dir)) != NULL) {
        const char* filename = entry->d_name;
        size_t len = strlen(filename);

        if (len > 4 && strcmp(filename + len - 4, ".pxt") == 0) {
            lua_pushnumber(L, index);  // Push the index to the stack
            lua_pushstring(L, filename);  // Push the filename to the stack
            lua_settable(L, -3);  // Set the filename in the Lua table

            index++;
        }
    }

    closedir(dir);

    return 1;  // Return the Lua table with file names
}
static int readMacFiles(lua_State* L) {
    const char* directory;
    DIR* dir;
    int index;
    struct dirent* entry;
    int nargs;
     nargs = lua_gettop(L);
    if (nargs < 1) {
        return luaL_error(L, "Invalid number of arguments. Expected 1");
    }
    directory = luaL_checkstring(L, 1);  // Get the directory path from Lua
    dir = opendir(directory);

    if (dir == NULL) {
        lua_pushstring(L, "Error opening directory");
        lua_error(L);
    }

    lua_newtable(L);  // Create a new Lua table to store the file names
    
    
    index = 1;  // Index for Lua table
    while ((entry = readdir(dir)) != NULL) {
        const char* filename = entry->d_name;
        size_t len = strlen(filename);

        if (len > 4 && strcmp(filename + len - 4, ".mac") == 0) {
            lua_pushnumber(L, index);  // Push the index to the stack
            lua_pushstring(L, filename);  // Push the filename to the stack
            lua_settable(L, -3);  // Set the filename in the Lua table

            index++;
        }
    }

    closedir(dir);

    return 1;  // Return the Lua table with file names
}

static const luaL_Reg mylib_functions[] = {
    {"read_mac", readMacFiles},
    {"read", readPxtFiles},
    {"cwd", changeWorkingDirectory},
    {NULL, NULL}
};

int luaopen_pxt_processor(lua_State* L) {
    luaL_newlib(L, mylib_functions);  // Create a new Lua module table
    return 1;
}


