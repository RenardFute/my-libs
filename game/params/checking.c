/*
** EPITECH PROJECT, 2022
** B-MUL-100-NAN-1-1-myhunter-axel.eckenberg
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "../game.h"

bool is_arg(game_t *game, char *arg)
{
    for (int i = 0; i < get_param_count(game); i++) {
        if (my_strcmp(game->params[i]->key, arg) == 0)
            return true;
    }
    return false;
}

arg_t *get_arg_by_key(game_t *game, char *key)
{
    if (!is_arg(game, key))
        return NULL;

    for (int i = 0; i < get_param_count(game); i++) {
        if (my_strcmp(game->params[i]->key, key) == 0)
            return game->params[i];
    }
    return NULL;
}

bool arg(game_t *game, char *arg, char *value)
{
    if (!is_arg(game, arg))
        return false;
    arg_t *arg_t = get_arg_by_key(game, arg);

    if (my_strcmp(arg_t->value, value) == 0)
        return true;
    return false;
}

arg_t *get_arg(game_t *game, int index)
{
    if (index >= get_param_count(game))
        return NULL;
    return game->params[index];
}
