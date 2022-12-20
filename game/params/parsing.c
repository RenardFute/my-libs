/*
** EPITECH PROJECT, 2022
** B-MUL-100-NAN-1-1-myhunter-axel.eckenberg
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "../game.h"

void parse_big_param(game_t *game, char *arg)
{
    char **params = my_split(arg, '=');
    arg_t *a = malloc(sizeof(arg_t));
    a->key = my_strdup(params[0] + 2);
    a->value = my_strdup(params[1]);
    free(params[0]);
    free(params[1]);
    free(params);
    add_param(game, a);
}

void parse_param(game_t *game, char *arg)
{
    if (my_strlen(arg) < 2)
        return;

    if (arg[1] == '-') {
        parse_big_param(game, arg);
    } else {
        for (int i = 1; i < my_strlen(arg); i++) {
            arg_t *a = malloc(sizeof(arg_t));
            a->key = malloc(sizeof(char) * 2);
            a->key[0] = arg[i];
            a->key[1] = '\0';
            a->value = NULL;
            add_param(game, a);
        }
    }
}

void parse_params(game_t *game, int argc, char **argv)
{
    arg_t *arg = NULL;
    for (int i = 0; i < argc; i++) {
        if (argv[i][0] == '-') {
            parse_param(game, argv[i]);
        }
    }
}
