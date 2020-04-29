/*
** EPITECH PROJECT, 2020
** MUL_my_RPG_2019
** File description:
** sound
*/

#include "lua.h"
#include "win.h"
#include <SFML/Audio.h>
#include "std.h"

int lua_play_sound(lua_State *L)
{
    const char *path = luaL_checkstring(L, 1);
    sfMusic *new = sfMusic_createFromFile(my_strcat("static/", path));

    sfMusic_play(new);

    return 0;
}