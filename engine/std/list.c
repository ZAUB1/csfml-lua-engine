/*
** EPITECH PROJECT, 2020
** MUL_MY_RPG_2019
** File description:
** list
*/

#include "list.h"

static list_t create_node(void)
{
    list_t new = malloc(sizeof(struct list_s));
    new->data = NULL;
    new->next = NULL;
    return new;
}

void push_node(void *data, list_t *list)
{
    list_t new = create_node();
    new->data = data;

    if (!(*list)) {
        new->pos = 0;
        *list = new;
        return;
    }

    new->pos = (*list)->pos + 1;
    list_t p = *list;
    while (p->next != NULL)
        p = p->next;

    p->next = new;
}

void rm_node(size_t pos, list_t *list)
{
    if (!list)
        return;

    if (pos == 0) {
        *list = (*list)->next;
        return;
    }

    list_t temp = *list;
    for (size_t i = 1; i < pos; i++)
        temp = temp->next;

    if (temp == NULL || temp->next == NULL)
        return;

    list_t next = temp->next->next;
    free(temp->next);
    temp->next = next;
}

void list_foreach(list_t list, void (*cb)(void *))
{
    if (!list)
        return;

    list_t temp = list;

    while (temp) {
        cb(temp->data);
        temp = temp->next;
    }
}

void *get_at_pos(size_t pos, list_t list)
{
    if (!list)
        return NULL;

    list_t temp = list;
    size_t current = 0;

    while (temp) {
        if (current == pos)
            return list->data;
        current += 1;
    }

    return NULL;
}