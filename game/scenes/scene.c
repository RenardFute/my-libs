/*
** EPITECH PROJECT, 2022
** B-MUL-100-NAN-1-1-myhunter-axel.eckenberg
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "../game.h"

scene_t *get_empty_scene(char *name)
{
    scene_t *scene = malloc(sizeof(scene_t));

    scene->entities = malloc(sizeof(entity_t *) * 1);
    scene->entities[0] = NULL;
    scene->name = name;
    scene->clock = sfClock_create();
    scene->gui = NULL;
    return scene;
}

void free_scene(game_t *game, scene_t *scene)
{
    if (scene->entities != NULL)
        free_entities(game, scene);
    if (scene->clock != NULL)
        sfClock_destroy(scene->clock);
    if (scene->name != NULL)
        free(scene->name);
    free(scene);
}

void add_entity(scene_t *scene, entity_t *entity)
{
    int i = 0;
    entity_t **new_entities = malloc(sizeof(entity_t *)
    * (get_entity_count(scene) + 2));

    while (scene->entities[i] != NULL) {
        new_entities[i] = scene->entities[i];
        i++;
    }
    new_entities[i] = entity;
    new_entities[i + 1] = NULL;
    free(scene->entities);
    scene->entities = new_entities;
}

void remove_entity(scene_t *scene, entity_t *entity)
{
    int i = 0;
    int j = 0;
    entity_t **new_entities = malloc(sizeof(entity_t *)
    * (get_entity_count(scene) + 1));

    while (scene->entities[i] != NULL) {
        if (scene->entities[i] != entity) {
            new_entities[j] = scene->entities[i];
            j++;
        }
        i++;
    }
    new_entities[j] = NULL;
    free(scene->entities);
    scene->entities = new_entities;
}
