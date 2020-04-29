/*
** EPITECH PROJECT, 2020
** MUL_my_RPG_2019
** File description:
** lua_api
*/

#include "lua.h"
#include "std.h"
#include "win.h"
#include "objects.h"
#include <SFML/Audio.h>
#include "std.h"

size_t add_object(char *path);

size_t add_text(char *str, char *);

int lua_add_object(lua_State *L)
{
    const char *path = luaL_checkstring(L, 1);
    size_t pos = add_object((char *)path);
    sfFloatRect bounds = sfSprite_getGlobalBounds(OBJECTS[pos]->sprite);

    lua_stance->changingObj = true;
    lua_stance->changingObj = false;
    lua_pushinteger(lua_stance->L, pos);
    lua_pushnumber(lua_stance->L, bounds.height);
    lua_pushnumber(lua_stance->L, bounds.width);
    return (3);
}

int lua_add_text(lua_State *L)
{
    const char *str = luaL_checkstring(L, 1);
    const char *font = luaL_checkstring(L, 2);
    size_t pos = add_text((char *)str, (char *)font);

    lua_stance->changingObj = true;
    lua_stance->changingObj = false;
    lua_pushnumber(lua_stance->L, pos);
    return (1);
}

int lua_get_screen_res(void)
{
    while (win_save->mode.height == 0);
    lua_pushstring(lua_stance->L, int_to_str(win_save->mode.height));
    lua_pushstring(lua_stance->L, int_to_str(win_save->mode.width));
    return (2);
}

int lua_quit_game(void)
{
    exit(0);
    return (0);
}

int lua_play_music(lua_State *L)
{
    const char *path = luaL_checkstring(L, 1);
    sfMusic *new = sfMusic_createFromFile(my_strcat("static/", path));

    sfMusic_setLoop(new, sfTrue);
    sfMusic_play(new);

    return (0);
}