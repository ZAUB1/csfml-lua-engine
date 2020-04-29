/*
** EPITECH PROJECT, 2020
** MUL_my_RPG_2019
** File description:
** main_texts
*/

#include "std.h"
#include "texts.h"
#include "lua.h"

volatile text_t *TEXTS;

size_t add_text(char *str, char *font_str)
{
    static size_t txt_count = 0;
    text_t new = malloc(sizeof(struct text_s));
    sfFont *font = sfFont_createFromFile(my_strcat("static/", font_str));

    new->text = sfText_create();
    new->str = str;
    sfText_setString(new->text, new->str);
    sfText_setFont(new->text, font);
    sfText_setColor(new->text, sfWhite);
    new->pos = (sfVector2f){0.0f, 0.0f};
    new->scale = (sfVector2f){1.0f, 1.0f};
    new->size = 100;
    new->active = true;
    TEXTS[txt_count] = new;
    return (txt_count++);
}

void render_texts(sfRenderWindow **win)
{
    for (size_t i = 0; TEXTS[i]; i++) {
        if (TEXTS[i]->active) {
            sfText_setString(TEXTS[i]->text, TEXTS[i]->str);
            sfText_setPosition(TEXTS[i]->text, TEXTS[i]->pos);
            sfText_setScale(TEXTS[i]->text, TEXTS[i]->scale);
            sfText_setCharacterSize(TEXTS[i]->text, TEXTS[i]->size);
            sfRenderWindow_drawText(*win, TEXTS[i]->text, NULL);
        }
    }
}

int lua_destroy_text(lua_State *L)
{
    size_t obj = luaL_checknumber(L, 1);

    TEXTS[obj]->active = false;
    sfText_destroy(TEXTS[obj]->text);
    return (0);
}

int lua_set_inactive_text(lua_State *L)
{
    size_t txt = luaL_checknumber(L, 1);
    const int active = luaL_checknumber(L, 2);

    TEXTS[txt]->active = active;
    return (0);
}

void init_texts(void)
{
    TEXTS = malloc(sizeof(struct text_s) * 500);
    TEXTS[0] = NULL;
}