/*
** EPITECH PROJECT, 2022
** B-MUL-100-NAN-1-1-myhunter-axel.eckenberg
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "../game.h"

void add_variable(game_t *game, char *name, void *value)
{
    variable_t *var = create_variable(name, value);
    int i = 0;
    variable_t **new_variables = malloc(sizeof(variable_t *)
    * (get_variable_count(game) + 2));
    while (game->variables[i] != NULL) {
        new_variables[i] = game->variables[i];
        i++;
    }
    new_variables[i] = var;
    new_variables[i + 1] = NULL;
    free(game->variables);
    game->variables = new_variables;
}

int get_variable_count(game_t *game)
{
    get_array_size((void **) game->variables);
}

void *get_variable(game_t *game, char *name)
{
    for (int i = 0; i < get_variable_count(game); i++) {
        if (my_strcmp(game->variables[i]->name, name) == 0) {
            return game->variables[i]->value;
        }
    }
    return NULL;
}

void set_variable(game_t *game, char *name, void *value)
{
    for (int i = 0; i < get_variable_count(game); i++) {
        if (my_strcmp(game->variables[i]->name, name) == 0) {
            game->variables[i]->value = value;
        }
    }
}

variable_t *create_variable(char *name, void *value)
{
    variable_t *var = malloc(sizeof(variable_t));
    var->name = my_strdup(name);
    var->value = value;
    return var;
}
