/*
** EPITECH PROJECT, 2020
** MUL_my_RPG_2019
** File description:
** main_objects
*/

#include "std.h"
#include "objects.h"
#include "lua.h"

volatile object_t *OBJECTS;

size_t add_object(char *path)
{
    static size_t obj_count = 0;
    object_t new = malloc(sizeof(struct object_s));

    new->pos = (sfVector2f){0.0f, 0.0f};
    new->scale = (sfVector2f){1.0f, 1.0f};
    new->texture = sfTexture_createFromFile(
        my_strcat("static/", path), NULL);
    sfTexture_setRepeated(new->texture, sfTrue);
    new->text_name = path;
    new->sprite = sfSprite_create();
    new->active = true;
    sfSprite_setTexture(new->sprite,
        new->texture, sfFalse);
    new->rect = sfSprite_getTextureRect(new->sprite);
    OBJECTS[obj_count] = new;
    return obj_count++;
}

void render_objets(sfRenderWindow **win)
{
    for (size_t i = 0; OBJECTS[i]; i++) {
        if (OBJECTS[i]->active) {
            sfSprite_setPosition(OBJECTS[i]->sprite, OBJECTS[i]->pos);
            sfSprite_setScale(OBJECTS[i]->sprite, OBJECTS[i]->scale);
            sfSprite_setTextureRect(OBJECTS[i]->sprite, OBJECTS[i]->rect);
            sfRenderWindow_drawSprite(*win, OBJECTS[i]->sprite, NULL);
        }
    }
}

void init_objects(void)
{
    OBJECTS = malloc(sizeof(struct object_s) * 2000);
    OBJECTS[0] = NULL;
}

int lua_destroy_object(lua_State *L)
{
    size_t obj = luaL_checknumber(L, 1);

    OBJECTS[obj]->active = false;
    sfSprite_destroy(OBJECTS[obj]->sprite);
    sfTexture_destroy(OBJECTS[obj]->texture);
    return (0);
}