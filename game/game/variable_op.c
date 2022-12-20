/*
** EPITECH PROJECT, 2022
** B-MUL-100-NAN-1-1-myhunter-axel.eckenberg
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "../game.h"

void increase_variable(game_t *game, char* name, int delta)
{
    int *value = get_variable(game, name);
    if (value == NULL)
        return;
    *value += delta;
}

void increase_variable_float(game_t *game, char* name, float delta)
{
    float *value = get_variable(game, name);
    if (value == NULL)
        return;
    *value += delta;
}

void set_variable_to_i(game_t *game, char *name, int value)
{
    for (int i = 0; i < get_variable_count(game); i++) {
        if (my_strcmp(game->variables[i]->name, name) == 0) {
            int *var = (int *) get_variable(game, name);
            *var = value;
            return;
        }
    }
}

void set_variable_to_f(game_t *game, char *name, float value)
{
    for (int i = 0; i < get_variable_count(game); i++) {
        if (my_strcmp(game->variables[i]->name, name) == 0) {
            float *var = (float *) get_variable(game, name);
            *var = value;
            return;
        }
    }
}
