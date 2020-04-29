/*
** EPITECH PROJECT, 2020
** MUL_my_RPG_2019
** File description:
** lua_api2
*/

#include "lua.h"
#include "std.h"
#include "win.h"
#include "shapes.h"
#include <SFML/Audio.h>

int lua_add_shape(lua_State *L)
{
    const int type = luaL_checknumber(L, 1);
    size_t pos = add_shape(type);

    lua_stance->changingObj = true;
    lua_stance->changingObj = false;
    lua_pushnumber(lua_stance->L, pos);
    return (1);
}