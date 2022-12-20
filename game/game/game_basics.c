/*
** EPITECH PROJECT, 2022
** B-MUL-100-NAN-1-1-myhunter-axel.eckenberg
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "../game.h"

game_t *get_empty_game(char *name)
{
    game_t *game = malloc(sizeof(game_t));

    game->active_scene = NULL;
    game->scenes = malloc(sizeof(scene_t *) * 1);
    game->scenes[0] = NULL;
    game->params = malloc(sizeof(arg_t *) * 1);
    game->params[0] = NULL;
    game->window = NULL;
    game->name = my_strdup(name);
    game->variables = malloc(sizeof(variable_t *) * 1);
    game->variables[0] = NULL;
    if (is_texture_path_valid("assets/icon.png"))
        game->icon = sfTexture_createFromFile("assets/icon.png", NULL);
    else
        game->icon = create_missing_texture(32, 32);
    return game;
}

void free_scenes(game_t *game)
{
    for (int i = 0; i < get_scene_count(game); i++) {
        if (arg(game, "verbose", "full")) {
            my_putstr("\t- ");
            my_putstr(game->scenes[i]->name);
            my_putchar('\n');
        }
        free_scene(game, game->scenes[i]);
    }
    free(game->scenes);
}

void free_params(game_t *game)
{
    bool verbose_full = arg(game, "verbose", "full");
    for (int i = 0; i < get_param_count(game); i++) {
        if (verbose_full) {
            my_putstr("\t- ");
            my_putstr(game->params[i]->key);
            my_putstr(": ");
            game->params[i]->value != NULL ?
            my_putstr(game->params[i]->value) : 0;
            my_putchar('\n');
        }
        free_param(game->params[i]);
    }
    free(game->params);
}

void free_game(game_t *game)
{
    if (arg(game, "verbose", "full")) {
        my_putstr("Freeing game\n");
        my_putstr("Scenes: ");
        my_put_nbr(get_scene_count(game));
        my_putchar('\n');
    }
    free_scenes(game);
    if (arg(game, "verbose", "full")) {
        my_putstr("Params: ");
        my_put_nbr(get_param_count(game));
        my_putchar('\n');
    }
    free_params(game);
    free(game->name);
    free(game);
}

void exit_game(game_t *game, int status)
{
    if (game->window != NULL)
        sfRenderWindow_destroy(game->window);
    free_game(game);
}
