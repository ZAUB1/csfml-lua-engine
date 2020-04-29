/*
** EPITECH PROJECT, 2020
** MUL_my_RPG_2019
** File description:
** win
*/

#include "std.h"
#include "win.h"
#include "lua.h"
#include "events.h"

void init_cursors(void);

void render_objets(sfRenderWindow **win);

void render_texts(sfRenderWindow **win);

void render_shapes(sfRenderWindow **win);

volatile win_save_t win_save;

static sfRenderWindow *create_win(void)
{
    sfRenderWindow *window = sfRenderWindow_create(
        (sfVideoMode){1920, 1080, 32}, "RPG", sfResize | sfClose, NULL);

    if (!window)
        exit(84);
    sfRenderWindow_setFramerateLimit(window, 60);
    sfRenderWindow_setVerticalSyncEnabled(window, sfTrue);
    win_save->mode = sfVideoMode_getDesktopMode();
    return (window);
}

static void event_handling(sfEvent *evt)
{
    short type = (*evt).type;
    char *buff = malloc(sizeof(char) * 100);
    int m_x = (*evt).mouseMove.x;
    int m_y = (*evt).mouseMove.y;

    buff = my_strcat(int_to_str(m_x), ", ");
    buff = my_strcat(buff, int_to_str(m_y));
    buff = my_strcat(buff, ", ");
    buff = my_strcat(buff, int_to_str((*evt).key.code));
    win_save->mouse_x = (*evt).mouseMove.x;
    win_save->mouse_y = (*evt).mouseMove.y;
    lua_stance->last_evt = sfml_events[type];
    lua_stance->additional_evt = buff;
    lua_stance->need_evt = true;
}

static void main_loop(void *win)
{
    sfEvent event;
    sfRenderWindow **window = win;

    while (sfRenderWindow_isOpen(*window)) {
        while (sfRenderWindow_pollEvent(*window, &event)) {
            event_handling(&event);
        }
        sfRenderWindow_clear(*window, sfBlack);
        render_shapes(window);
        render_objets(window);
        render_texts(window);
        sfRenderWindow_display(*window);
    }
}

void init_win(void)
{
    sfRenderWindow *win = NULL;

    win_save = malloc(sizeof(struct win_save_s));
    win = create_win();
    win_save->win = win;
    init_cursors();
    main_loop(&win);
}