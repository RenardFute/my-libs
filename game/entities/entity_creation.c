/*
** EPITECH PROJECT, 2022
** B-MUL-100-NAN-1-1-myhunter-axel.eckenberg
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "../game.h"

entity_t *create_entity(char *name, char *path, sfVector3f pos)
{
    entity_t *entity = malloc(sizeof(entity_t));
    entity->name = my_strdup(name);
    entity->sprite = sfSprite_create();
    sfSprite_setOrigin(entity->sprite, (sfVector2f) {0, 0});
    entity->texture = get_texture(path);
    entity->clock = sfClock_create();
    entity->events = malloc(sizeof(event_t *) * 1);
    entity->events[0] = NULL;
    entity->position = pos;
    entity->base_position = (sfVector3f) {pos.x, pos.y, pos.z};
    entity->perspective_enabled = false;
    entity->update = NULL;
    sfVector2u size = sfTexture_getSize(entity->texture);
    entity->size = (sfVector2f) {(float) size.x, (float) size.y};
    entity->base_size = (sfVector2f) {(float) size.x, (float) size.y};
    entity->is_animated = false;
    entity->frame_duration_counter = 0;
    entity->hitboxes = malloc(sizeof(hitbox_t *) * 1);
    entity->hitboxes[0] = NULL;
    return entity;
}

void add_event(entity_t *entity, event_t *event)
{
    int old_size = get_event_count(entity);
    event_t **new_events = malloc(sizeof(event_t *) * (old_size + 2));
    for (int i = 0; i < get_event_count(entity); i++) {
        new_events[i] = entity->events[i];
    }
    new_events[old_size] = event;
    new_events[old_size + 1] = NULL;
    free(entity->events);
    entity->events = new_events;
}

int get_event_count(entity_t *entity)
{
    int i = 0;
    while (entity->events[i++] != NULL);
    return i - 1;
}

void setup_animation(entity_t *entity, int frame_count,
int frame_duration, sfVector2f frame_size)
{
    entity->is_animated = true;
    entity->frame_count = frame_count;
    entity->frame_duration = frame_duration;
    entity->current_frame = 0;
    entity->frame_size = frame_size;
    sfIntRect rect = {0, 0, (int) frame_size.x, (int) frame_size.y};
    sfSprite_setTextureRect(entity->sprite, rect);
    entity->base_size = frame_size;
    entity->size = frame_size;
}
