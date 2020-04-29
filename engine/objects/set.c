/*
** EPITECH PROJECT, 2020
** MUL_my_RPG_2019
** File description:
** LUA::set
*/

#include "lua.h"
#include "objects.h"
#include "win.h"
#include "std.h"

int lua_set_object_pos(lua_State *L)
{
    INIT_LUA_OBJ
    float x = luaL_checknumber(L, 2);
    float y = luaL_checknumber(L, 3);

    LUA_OBJ->pos = (sfVector2f){x, y};
    return (0);
}

int lua_set_object_scale(lua_State *L)
{
    INIT_LUA_OBJ
    float scale = luaL_checknumber(L, 2);

    LUA_OBJ->scale = (sfVector2f){scale, scale};
    return (0);
}

int lua_set_texture(lua_State *L)
{
    INIT_LUA_OBJ
    const char *path = luaL_checkstring(L, 2);
    sfTexture *nw = NULL;

    if (path != LUA_OBJ->text_name) {
        nw = sfTexture_createFromFile(my_strcat("static/", path),
            NULL);
        sfSprite_setTexture(LUA_OBJ->sprite, nw, sfFalse);
        LUA_OBJ->text_name = (char *)path;
    }
    return (0);
}

int lua_set_inactive_obj(lua_State *L)
{
    INIT_LUA_OBJ
    const int active = luaL_checknumber(L, 2);
    LUA_OBJ->active = active;

    return (0);
}

int lua_set_rect_obj(lua_State *L)
{
    INIT_LUA_OBJ
    const int left = luaL_checkinteger(L, 2);
    const int top = luaL_checkinteger(L, 3);
    const int width = luaL_checkinteger(L, 4);
    const int height = luaL_checkinteger(L, 5);

    LUA_OBJ->rect = (sfIntRect){left, top, width, height};
    return (0);
}