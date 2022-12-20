/*
** EPITECH PROJECT, 2022
** B-MUL-100-NAN-1-1-myhunter-axel.eckenberg
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "../game.h"

void add_scene(game_t *game, scene_t *scene)
{
    int i = 0;
    scene_t **new_scenes = malloc(sizeof(scene_t *)
    * (get_scene_count(game) + 2));
    while (game->scenes[i] != NULL) {
        new_scenes[i] = game->scenes[i];
        i++;
    }
    new_scenes[i] = scene;
    new_scenes[i + 1] = NULL;
    free(game->scenes);
    game->scenes = new_scenes;
}

int get_scene_count(game_t *game)
{
    int i = 0;
    while (game->scenes[i++] != NULL);
    return i - 1;
}
