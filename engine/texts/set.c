/*
** EPITECH PROJECT, 2020
** MUL_my_RPG_2019
** File description:
** LUA::set
*/

#include "lua.h"
#include "texts.h"
#include "win.h"
#include "std.h"

int lua_set_text_string(lua_State *L)
{
    const size_t pos = luaL_checknumber(L, 1);
    const char *str = luaL_checkstring(L, 2);
    TEXTS[pos]->str = (char *)str;

    return (0);
}

int lua_set_text_position(lua_State *L)
{
    const int pos = luaL_checknumber(L, 1);
    const int x = luaL_checknumber(L, 2);
    const int y = luaL_checknumber(L, 3);

    TEXTS[pos]->pos.x = x;
    TEXTS[pos]->pos.y = y;
    return (0);
}

int lua_set_text_size(lua_State *L)
{
    size_t txt = luaL_checknumber(L, 1);
    const unsigned int size = luaL_checknumber(L, 2);

    TEXTS[txt]->size = size;
    return (0);
}

int lua_set_text_outline_color(lua_State *L)
{
    size_t txt = luaL_checknumber(L, 1);
    const int r = luaL_checkinteger(L, 2);
    const int g = luaL_checkinteger(L, 3);
    const int b = luaL_checkinteger(L, 4);
    const int a = luaL_checkinteger(L, 5);
    const int tickness = luaL_checkinteger(L, 6);
    sfColor color = {r, g, b, a};

    sfText_setOutlineColor(TEXTS[txt]->text, color);
    sfText_setOutlineThickness(TEXTS[txt]->text, tickness);
    return (0);
}

int lua_set_text_fill_color(lua_State *L)
{
    size_t txt = luaL_checknumber(L, 1);
    const int r = luaL_checkinteger(L, 2);
    const int g = luaL_checkinteger(L, 3);
    const int b = luaL_checkinteger(L, 4);
    const int a = luaL_checkinteger(L, 5);
    sfColor color = {r, g, b, a};

    sfText_setFillColor(TEXTS[txt]->text, color);
    return (0);
}