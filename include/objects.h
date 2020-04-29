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

typedef struct object_s {
    sfVector2f pos;
    sfVector2f scale;
    sfSprite *sprite;
    sfTexture *texture;
    char *text_name;
    sfIntRect rect;
    bool active;
} *object_t;

extern volatile object_t *OBJECTS;

size_t add_object(char *path);

#endif /* !OBJECTS_H_ */