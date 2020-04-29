/*
** EPITECH PROJECT, 2020
** MUL_my_RPG_2019
** File description:
** LUA::set
*/

#include "lua.h"
#include "shapes.h"
#include "win.h"
#include "std.h"

int lua_set_shape_position(lua_State *L)
{
    const int pos = luaL_checknumber(L, 1);
    const int x = luaL_checknumber(L, 2);
    const int y = luaL_checknumber(L, 3);

    SHAPES[pos]->pos.x = x;
    SHAPES[pos]->pos.y = y;
    return (0);
}

int lua_set_shape_size(lua_State *L)
{
    size_t txt = luaL_checknumber(L, 1);
    const float x = luaL_checknumber(L, 2);
    const float y = luaL_checknumber(L, 3);

    SHAPES[txt]->size.x = x;
    SHAPES[txt]->size.y = y;
    return (0);
}

int lua_set_shape_fill_color(lua_State *L)
{
    size_t txt = luaL_checknumber(L, 1);
    const int r = luaL_checkinteger(L, 2);
    const int g = luaL_checkinteger(L, 3);
    const int b = luaL_checkinteger(L, 4);
    const int a = luaL_checkinteger(L, 5);

    SHAPES[txt]->color.r = r;
    SHAPES[txt]->color.g = g;
    SHAPES[txt]->color.b = b;
    SHAPES[txt]->color.a = a;
    sfRectangleShape_setFillColor(SHAPES[txt]->shape, SHAPES[txt]->color);
    return (0);
}