/*
** EPITECH PROJECT, 2020
** MUL_my_RPG_2019
** File description:
** win
*/

#pragma once

#ifndef WIN_H_
#define WIN_H_

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Window.h>

typedef struct win_save_s {
    int mouse_x;
    int mouse_y;
    sfVideoMode mode;
    sfRenderWindow *win;
} *win_save_t;

extern volatile win_save_t win_save;

#endif /* !WIN_H_ */