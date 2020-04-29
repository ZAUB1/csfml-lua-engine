/*
** EPITECH PROJECT, 2020
** MUL_my_RPG_2019
** File description:
** my_strdup
*/

#include "std.h"

char *my_strdup(char *str)
{
    char *new = malloc(sizeof(char) * (my_strlen(str) + 1));
    size_t i = 0;

    for (; str[i]; i++)
        new[i] = str[i];
    new[i] = '\0';
    return (new);
}