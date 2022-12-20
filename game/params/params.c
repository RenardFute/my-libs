/*
** EPITECH PROJECT, 2022
** B-MUL-100-NAN-1-1-myhunter-axel.eckenberg
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "../game.h"

void free_param(arg_t *arg)
{
    free(arg->key);
    if (arg->value != NULL)
        free(arg->value);
    free(arg);
}

void add_param(game_t *game, arg_t *arg)
{
    int i = 0;
    arg_t **new_params = malloc(sizeof(arg_t *) * (get_param_count(game) + 2));
    while (game->params[i] != NULL) {
        new_params[i] = game->params[i];
        i++;
    }
    new_params[i] = arg;
    new_params[i + 1] = NULL;
    free(game->params);
    game->params = new_params;
}

int get_param_count(game_t *game)
{
    int i = 0;
    while (game->params[i++] != NULL);
    return i - 1;
}
