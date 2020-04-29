/*
** EPITECH PROJECT, 2020
** MUL_my_RPG_2019
** File description:
** SHAPES
*/

#pragma once

#ifndef OBJECTS_H_
#define OBJECTS_H_

#include <stdbool.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>

typedef struct shape_s {
    sfRectangleShape *shape;
    sfColor color;
    sfVector2f pos;
    sfVector2f size;
    size_t type;
    bool active;
} *shape_t;

extern volatile shape_t *SHAPES;

size_t add_shape(size_t type);

#endif /* !OBJECTS_H_ */