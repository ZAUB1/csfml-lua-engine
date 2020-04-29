/*
** EPITECH PROJECT, 2020
** MUL_my_RPG_2019
** File description:
** main
*/

void init_lua(void);

void init_win(void);

void init_objects(void);

void init_texts(void);

void init_shapes(void);

int main(int argc, char **argv)
{
    (void)argc;
    (void)argv;
    init_lua();
    init_objects();
    init_texts();
    init_shapes();
    init_win();
    return (84);
}