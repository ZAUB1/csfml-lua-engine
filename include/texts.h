/*
** EPITECH PROJECT, 2020
** MUL_my_RPG_2019
** File description:
** objects
*/

#pragma once

#ifndef OBJECTS_H_
#define OBJECTS_H_

#include <stdbool.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>

typedef struct text_s {
    sfVector2f pos;
    sfVector2f scale;
    unsigned int size;
    sfText *text;
    char *str;
    bool active;
} *text_t;

extern volatile text_t *TEXTS;

size_t add_text(char *str, char *);

#endif /* !OBJECTS_H_ */