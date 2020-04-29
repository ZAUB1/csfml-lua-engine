/*
** EPITECH PROJECT, 2020
** MUL_my_RPG_2019
** File description:
** std
*/

#include "std.h"

size_t my_strlen(const char *str)
{
    int cnt;

    asm volatile ("cld\n"
        "repnz\n"
        "scasb" :
        "=c" (cnt) : "D" (str), "0" (-1), "a" (0));
    return (- 2 - cnt);
}

int my_puts(const char *str)
{
    return (write(1, str, my_strlen(str)));
}

void rev_str(char **str)
{
    const size_t slen = my_strlen(*str);
    char *new = malloc(sizeof(char) * slen);

    for (size_t i = slen; i > 0; i--)
        new[slen - i] = (*str)[i - 1];
    new[slen] = '\0';
    *str = new;
}

char *int_to_str(const int nbr)
{
    size_t count = 0;
    int temp = nbr;
    char *new = malloc(sizeof(char) * 9);

    if (nbr == 0) {
        return ("0");
    }
    while (temp > 0) {
        new[count] = temp % 10 + '0';
        temp /= 10;
        count += 1;
    }
    new[count] = '\0';
    rev_str(&new);
    return (new);
}

char *my_strcat(const char *str1, const char *str2)
{
    const size_t len1 = my_strlen(str1);
    const size_t len2 = my_strlen(str2);
    char *nstr = malloc(sizeof(char) * (len1 + len2 + 1));

    for (size_t i = 0; str1[i]; i++)
        nstr[i] = str1[i];
    for (size_t i = 0; str2[i]; i++)
        nstr[i + len1] = str2[i];
    nstr[len1 + len2] = '\0';
    return (nstr);
}