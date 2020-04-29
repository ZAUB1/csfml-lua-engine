/*
** EPITECH PROJECT, 2020
** MUL_my_RPG_2019
** File description:
** cursors
*/

#pragma once

#ifndef CURSORS_H_
#define CURSORS_H_

#include <stdbool.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>

typedef struct cursor_s {
    sfCursor *arrow;
    sfCursor *hand;
    sfCursorType actual;
} cursor_t;

extern cursor_t *CURSORS;

void lua_create_cursors(void);

#endif /* !CURSORS_H_ */