/*
** EPITECH PROJECT, 2020
** MUL_my_RPG_2019
** File description:
** lua
*/

#include <unistd.h>
#include <fcntl.h>
#include <SFML/System.h>
#include "std.h"
#include "lua.h"
#include "lua_init.h"
#include "lua_api.h"

volatile lua_t lua_stance;

void error(lua_State *L, char *, const char *);

static char *read_src(const char *str, const char *origin)
{
    const int fd = open(my_strcat("scripts/", str), O_RDONLY);
    char *buff = malloc(sizeof(char) * 100000);
    char *fbuff = NULL;
    size_t i = read(fd, buff, 32768);

    buff[i] = '\n';
    buff[i + 1] = '\0';
    close(fd);
    fbuff = my_strcat(origin, buff);
    free(buff);
    return (fbuff);
}

static void loop_lua(void)
{
    sfClock *llua_clock = sfClock_create();

    while (42) {
        if (sfClock_getElapsedTime(llua_clock).microseconds <= 100) {
            continue;
        }
        if (lua_stance->need_evt == true) {
            lua_getglobal(lua_stance->L, "event");
            lua_pushstring(lua_stance->L, lua_stance->last_evt);
            lua_pushstring(lua_stance->L, lua_stance->additional_evt);
            lua_pcall(lua_stance->L, 2, 0, 0) != 0 ?\
                error(lua_stance->L, "event: error running func `f': %s",
                    lua_tostring(lua_stance->L, -1)) : 0;
            lua_stance->need_evt = false;
        } else {
            lua_getglobal(lua_stance->L, "tick");
            lua_pcall(lua_stance->L, 0, 0, 0) != 0 ?\
                error(lua_stance->L, "tick: error running function `f': %s",
                    lua_tostring(lua_stance->L, -1)) : 0;
        }
        sfClock_restart(llua_clock);
    }
}

static void load_api(void)
{
    for (size_t i = 0; lua_api_funcs[i].name; i++) {
        lua_pushcfunction(lua_stance->L, lua_api_funcs[i].cb);
        lua_setglobal(lua_stance->L, lua_api_funcs[i].name);
    }
}

static void *run_lua(void *zebi)
{
    char **LUA_FILES = get_resource_files();
    char *buff = "";
    (void)zebi;

    lua_stance->L = luaL_newstate();
    luaL_openlibs(lua_stance->L);
    for (size_t i = 0; LUA_FILES[i]; i++)
        buff = read_src(LUA_FILES[i], buff);
    load_api();
    luaL_loadbuffer(lua_stance->L, buff, my_strlen(buff), "line");
    lua_pcall(lua_stance->L, 0, 0, 0);
    lua_getglobal(lua_stance->L, "ready");
    if (lua_pcall(lua_stance->L, 0, 0, 0) != 0)
        error(lua_stance->L, "rdy: error running function `f': %s",
            lua_tostring(lua_stance->L, -1));
    loop_lua();
    lua_close(lua_stance->L);
    return (NULL);
}

void init_lua(void)
{
    lua_stance = malloc(sizeof(struct lua_s));
    lua_stance->need_evt = false;
    lua_stance->changingObj = false;
    pthread_create(&lua_stance->thd, NULL, run_lua, NULL);
}