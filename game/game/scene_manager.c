/*
** EPITECH PROJECT, 2022
** B-MUL-100-NAN-1-1-myhunter-axel.eckenberg
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "../game.h"

void switch_scene_by_name(game_t *game, char *name)
{
    for (int i = 0; i < get_scene_count(game); i++) {
        if (my_strcmp(game->scenes[i]->name, name) == 0) {
            game->active_scene = game->scenes[i];
            return;
        }
    }
}
