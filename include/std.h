/*
** EPITECH PROJECT, 2020
** MUL_my_RPG_2019
** File description:
** std
*/

#pragma once

#ifndef STD_H_
#define STD_H_

#include <stdlib.h>
#include <unistd.h>

#define PRINTABLE(x) (x >= 32 && x <= 126)

size_t my_strlen(const char *str);
char *my_strcat(const char *str1, const char *str2);
char *int_to_str(const int nbr);
void rev_str(char **str);
int my_puts(const char *str);
char *my_strdup(char *str);

#endif /* !STD_H_ */