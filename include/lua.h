/*
** EPITECH PROJECT, 2020
** MUL_my_RPG_2019
** File description:
** lua
*/

#pragma once

#ifndef LUA_H_
#define LUA_H_

#include "../extern/lua.h"
#include "../extern/lualib.h"
#include "../extern/lauxlib.h"
#include "../extern/luaconf.h"
#include <pthread.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct lua_s {
    lua_State *L;
    pthread_t thd;

    bool need_evt;
    char *last_evt;
    char *additional_evt;

    bool changingObj;
} *lua_t;

void trigger_event(char *name, char *additionnal);

extern volatile lua_t lua_stance;

#define INIT_LUA_OBJ size_t obj = luaL_checknumber(L, 1);
#define LUA_OBJ OBJECTS[obj]

#endif /* !LUA_H_ */