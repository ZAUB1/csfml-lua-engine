/*
** EPITECH PROJECT, 2020
** MUL_my_RPG_2019
** File description:
** lua_events
*/

#include "lua.h"

void trigger_event(char *name, char *additionnal)
{
    lua_stance->last_evt = name;
    lua_stance->additional_evt = additionnal;
    lua_stance->need_evt = true;
}