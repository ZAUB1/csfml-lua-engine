/*
** EPITECH PROJECT, 2020
** MUL_my_RPG_2019
** File description:
** lua_init
*/

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "std.h"

char **get_resource_files(void)
{
    FILE *fp = fopen("scripts/_resources", "r");
    char **res = malloc(sizeof(char *) * 25);
    size_t current = 0;
    char *script = NULL;
    size_t len_scripts = 0;

    while (getline(&script, &len_scripts, fp) != -1) {
        if (script[0] == '#')
            continue;
        if (script[my_strlen(script) - 1] == '\n')
            script[my_strlen(script) - 1] = '\0';
        res[current] = my_strdup(script);
        current += 1;
    }
    res[current] = NULL;
    return (res);
}