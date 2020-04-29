/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** list
*/

#ifndef LIST_H_
#define LIST_H_

#include <stdlib.h>

typedef struct list_s {
    void *data;
    struct list_s *next;
    size_t pos;
} *list_t;

void push_node(void *data, list_t *list);
void rm_node(size_t pos, list_t *list);
void list_foreach(list_t list, void (*cb)(void *));

#endif /* !LIST_H_ */