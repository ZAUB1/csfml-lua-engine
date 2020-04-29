/*
** EPITECH PROJECT, 2020
** MUL_my_RPG_2019
** File description:
** LUA::misc
*/

#include "lua.h"
#include "win.h"
#include "cursor.h"

cursor_t *CURSORS = NULL;

void init_cursors(void)
{
    CURSORS = malloc(sizeof(cursor_t));
    CURSORS->actual = sfCursorArrow;
    lua_create_cursors();
}

void lua_create_cursors(void)
{
    CURSORS->arrow = sfCursor_createFromSystem(sfCursorArrow);
    CURSORS->hand = sfCursor_createFromSystem(sfCursorHand);
}

int lua_set_cursor(lua_State *L)
{
    const int mouse = luaL_checkinteger(L, 1);

    if (CURSORS == NULL)
        return (0);
    switch (mouse) {
        case 2:
            if (CURSORS->actual == sfCursorHand)
                break;
            sfRenderWindow_setMouseCursor(win_save->win, CURSORS->hand);
            CURSORS->actual = sfCursorHand;
            break;
        default:
            if (CURSORS->actual == sfCursorArrow)
                break;
            sfRenderWindow_setMouseCursor(win_save->win, CURSORS->arrow);
            CURSORS->actual = sfCursorArrow;
            break;
    }
    return (0);
}

int lua_get_cursor_pos(lua_State *L)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(win_save->win);

    lua_pushinteger(L, pos.x);
    lua_pushinteger(L, pos.y);
    return (2);
}

int lua_set_cursor_visible(lua_State *L)
{
    const int visible = luaL_checkinteger(L, 1);

    sfRenderWindow_setMouseCursorVisible(win_save->win, visible);
    return (0);
}