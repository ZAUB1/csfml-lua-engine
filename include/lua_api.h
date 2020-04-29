/*
** EPITECH PROJECT, 2020
** MUL_my_RPG_2019
** File description:
** lua_api
*/

#ifndef LUA_API_H_
#define LUA_API_H_

#include "lua.h"

int lua_add_object(lua_State *L);
int lua_get_object_pos(lua_State *L);
int lua_set_object_pos(lua_State *L);
int lua_get_object_size(lua_State *L);
int lua_set_object_color(lua_State *L);
int lua_quit_game(lua_State *L);
int lua_get_object_scale(lua_State *L);
int lua_set_object_scale(lua_State *L);
int lua_is_mouse_over(lua_State *L);
int lua_set_texture(lua_State *L);
int lua_destroy_object(lua_State *L);
int lua_add_text(lua_State *L);
int lua_set_text_string(lua_State *L);
int lua_set_text_position(lua_State *L);
int lua_set_text_size(lua_State *L);
int lua_set_text_outline_color(lua_State *L);
int lua_set_text_fill_color(lua_State *L);
int lua_destroy_text(lua_State *L);
int lua_set_inactive_text(lua_State *L);
int lua_add_shape(lua_State *L);
int lua_set_shape_position(lua_State *L);
int lua_set_shape_size(lua_State *L);
int lua_set_shape_fill_color(lua_State *L);
int lua_destroy_shape(lua_State *L);
int lua_set_inactive_shape(lua_State *L);
int lua_get_screen_res(lua_State *L);
int lua_set_inactive_obj(lua_State *L);
int lua_play_music(lua_State *L);
int lua_set_rect_obj(lua_State *L);
int lua_set_cursor(lua_State *L);
int lua_get_cursor_pos(lua_State *L);
int lua_play_sound(lua_State *L);
int lua_set_cursor_visible(lua_State *L);

typedef struct lua_api_func_s {
    char *name;
    int (*cb)(lua_State *L);
} lua_api_func_t;

lua_api_func_t lua_api_funcs[] = {
    {"api_add_object", lua_add_object},
    {"api_set_obj_pos", lua_set_object_pos},
    {"api_set_obj_color", lua_set_object_color},
    {"api_get_obj_pos", lua_get_object_pos},
    {"api_get_obj_scale", lua_get_object_scale},
    {"api_set_obj_scale", lua_set_object_scale},
    {"api_get_obj_size", lua_get_object_size},
    {"api_is_mouse_over_obj", lua_is_mouse_over},
    {"api_quit_game", lua_quit_game},
    {"api_set_texture", lua_set_texture},
    {"api_destroy_obj", lua_destroy_object},
    {"api_add_text", lua_add_text},
    {"api_set_text_string", lua_set_text_string},
    {"api_set_text_position", lua_set_text_position},
    {"api_set_text_size", lua_set_text_size},
    {"api_set_inactive_text", lua_set_inactive_text},
    {"api_set_text_outline_color", lua_set_text_outline_color},
    {"api_set_text_fill_color", lua_set_text_fill_color},
    {"api_destroy_text", lua_destroy_text},
    {"api_add_shape", lua_add_shape},
    {"api_set_shape_position", lua_set_shape_position},
    {"api_set_shape_size", lua_set_shape_size},
    {"api_set_inactive_shape", lua_set_inactive_shape},
    {"api_set_shape_fill_color", lua_set_shape_fill_color},
    {"api_destroy_shape", lua_destroy_shape},
    {"api_get_screen_res", lua_get_screen_res},
    {"api_set_inactive_obj", lua_set_inactive_obj},
    {"api_play_music", lua_play_music},
    {"api_set_rect_obj", lua_set_rect_obj},
    {"api_set_cursor", lua_set_cursor},
    {"api_get_cursor_pos", lua_get_cursor_pos},
    {"api_play_sound", lua_play_sound},
    {"api_set_cursor_visible", lua_set_cursor_visible},
    {NULL, NULL}
};

#endif /* !LUA_API_H_ */