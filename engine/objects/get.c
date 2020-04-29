/*
** EPITECH PROJECT, 2020
** MUL_my_RPG_2019
** File description:
** LUA::get
*/

#include "lua.h"
#include "objects.h"

int lua_get_object_pos(lua_State *L)
{
    INIT_LUA_OBJ

    lua_pushnumber(L, LUA_OBJ->pos.x);
    lua_pushnumber(L, LUA_OBJ->pos.y);
    return (2);
}

int lua_get_object_scale(lua_State *L)
{
    INIT_LUA_OBJ

    lua_pushnumber(L, LUA_OBJ->scale.x);
    return (1);
}

int lua_get_object_size(lua_State *L)
{
    INIT_LUA_OBJ
    sfFloatRect bounds = sfSprite_getGlobalBounds(LUA_OBJ->sprite);

    lua_pushnumber(L, bounds.width);
    lua_pushnumber(L, bounds.height);
    return (2);
}