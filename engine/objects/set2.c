/*
** EPITECH PROJECT, 2020
** MUL_my_RPG_2019
** File description:
** LUA::set2
*/

#include "lua.h"
#include "objects.h"
#include "win.h"
#include "std.h"

int lua_set_object_color(lua_State *L)
{
    INIT_LUA_OBJ
    const int r = luaL_checkinteger(L, 2);
    const int g = luaL_checkinteger(L, 3);
    const int b = luaL_checkinteger(L, 4);
    const int a = luaL_checkinteger(L, 5);
    sfColor color = {r, g, b, a};

    sfSprite_setColor(LUA_OBJ->sprite, color);
    return (0);
}