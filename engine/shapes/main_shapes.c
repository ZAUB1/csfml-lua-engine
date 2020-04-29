/*
** EPITECH PROJECT, 2020
** MUL_my_RPG_2019
** File description:
** main_shapes
*/

#include "std.h"
#include "shapes.h"
#include "lua.h"

volatile shape_t *SHAPES;

size_t add_shape(size_t type)
{
    static size_t shape_count = 0;
    shape_t new = malloc(sizeof(struct shape_s));

    (void)type;
    new->shape = sfRectangleShape_create();
    new->pos = (sfVector2f){0.0f, 0.0f};
    new->size = (sfVector2f){1.0f, 1.0f};
    new->active = true;
    SHAPES[shape_count] = new;
    return (shape_count++);
}

void render_shapes(sfRenderWindow **win)
{
    for (size_t i = 0; SHAPES[i]; i++) {
        if (SHAPES[i]->active) {
            sfRectangleShape_setPosition(SHAPES[i]->shape, SHAPES[i]->pos);
            sfRectangleShape_setSize(SHAPES[i]->shape, SHAPES[i]->size);
            sfRenderWindow_drawRectangleShape(*win, SHAPES[i]->shape, NULL);
        }
    }
}

int lua_destroy_shape(lua_State *L)
{
    size_t obj = luaL_checknumber(L, 1);

    SHAPES[obj]->active = false;
    sfRectangleShape_destroy (SHAPES[obj]->shape);
    return (0);
}

int lua_set_inactive_shape(lua_State *L)
{
    size_t shape = luaL_checknumber(L, 1);
    const int active = luaL_checknumber(L, 2);

    SHAPES[shape]->active = active;
    return (0);
}

void init_shapes(void)
{
    SHAPES = malloc(sizeof(struct shape_s) * 500);
    SHAPES[0] = NULL;
}