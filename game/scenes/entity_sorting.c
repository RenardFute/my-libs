/*
** EPITECH PROJECT, 2022
** B-MUL-100-NAN-1-1-myhunter-axel.eckenberg
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "../game.h"

void sort_entities(scene_t *scene)
{
    int i = 0;
    int j = 0;
    entity_t *tmp = NULL;

    while (scene->entities[i] != NULL) {
        j = i + 1;
        while (scene->entities[j] != NULL) {
            compare_and_swap(scene, i, j, tmp);
            j++;
        }
        i++;
    }
}

void compare_and_swap(scene_t *scene, int i, int j, entity_t *tmp)
{
    if (scene->entities[i]->position.z > scene->entities[j]->position.z) {
        tmp = scene->entities[i];
        scene->entities[i] = scene->entities[j];
        scene->entities[j] = tmp;
    }
}
