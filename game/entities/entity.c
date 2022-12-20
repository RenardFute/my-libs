/*
** EPITECH PROJECT, 2022
** B-MUL-100-NAN-1-1-myhunter-axel.eckenberg
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "../game.h"

void free_entity(game_t *game, entity_t *entity)
{
    if (arg(game, "verbose", "full")) {
        my_putstr("\t    - ");
        my_putstr(entity->name);
        my_putchar('\n');
    }
    if (entity->sprite != NULL)
        sfSprite_destroy(entity->sprite);
    if (entity->texture != NULL)
        sfTexture_destroy(entity->texture);
    if (entity->clock != NULL)
        sfClock_destroy(entity->clock);
    if (entity->name != NULL)
        free(entity->name);
    free_events(game, entity);
    free(entity);
}

int get_entity_count(scene_t *scene)
{
    int i = 0;
    while (scene->entities[i++] != NULL);
    return i - 1;
}

void free_entities(game_t *game, scene_t *scene)
{
    if (arg(game, "verbose", "full")) {
        my_putstr("\t  - Entities: ");
        my_put_nbr(get_entity_count(scene));
        my_putchar('\n');
    }
    for (int i = 0; i < get_entity_count(scene); i++) {
        free_entity(game, scene->entities[i]);
    }
    free(scene->entities);
}
