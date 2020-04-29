/*
** EPITECH PROJECT, 2020
** MUL_my_RPG_2019
** File description:
** LUA::get
*/

#include "lua.h"
#include "objects.h"
#include "win.h"

int lua_is_mouse_over(lua_State *L)
{
    size_t obj = luaL_checknumber(L, 1);
    sfFloatRect bounds = sfSprite_getGlobalBounds(OBJECTS[obj]->sprite);
    sfBool res = sfFloatRect_contains(&bounds, \
        win_save->mouse_x, win_save->mouse_y);

    lua_pushboolean(L, res);
    return (1);
}