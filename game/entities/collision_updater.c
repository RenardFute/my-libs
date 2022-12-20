/*
** EPITECH PROJECT, 2022
** B-MUL-100-NAN-1-1-myhunter-axel.eckenberg
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "../game.h"

void update_pos_and_size(hitbox_t *hitbox)
{
    sfVector3f pos = hitbox->parent->position;
    sfRectangleShape *shape = hitbox->shape;
    sfFloatRect rect = hitbox->rect;
    sfVector2f base_size = {rect.width, rect.height};
    sfVector2f entity_base_size = {hitbox->parent->base_size.x,
    hitbox->parent->base_size.y};
    sfVector2f ratio = {base_size.x / entity_base_size.x,
    base_size.y / entity_base_size.y};
    sfVector2f size = {hitbox->parent->size.x * ratio.x,
    hitbox->parent->size.y * ratio.y};
    sfRectangleShape_setSize(shape, size);
    sfVector2f base_pos = {rect.left, rect.top};
    sfVector2f pos_ratio = {base_pos.x / entity_base_size.x,
    base_pos.y / entity_base_size.y};
    sfVector2f new_pos = {pos.x + (hitbox->parent->size.x * pos_ratio.x),
    pos.y + (hitbox->parent->size.y * pos_ratio.y)};
    sfRectangleShape_setPosition(shape, new_pos);
}

hitbox_t **merge_hitbox_arrays(hitbox_t **array, hitbox_t **hitbox)
{
    int total = 0;
    hitbox_t **new_array = malloc(sizeof(hitbox_t *) *
    (get_array_size((void **) array) + get_array_size((void **) hitbox) + 1));
    while (array[total] != NULL) {
        new_array[total] = array[total];
        total++;
    }
    int i = 0;
    while (hitbox[i] != NULL) {
        new_array[total++] = hitbox[i];
        i++;
    }
    new_array[total] = NULL;
    free(array);
    return new_array;
}

hitbox_t **get_colliders(entity_t *a, scene_t *scene)
{
    hitbox_t **colliders = malloc(sizeof(hitbox_t *) * 1);
    colliders[0] = NULL;
    for (int i = 0; i < get_hitbox_count(a); i++) {
        hitbox_t *hitbox = a->hitboxes[i];

        colliders = get_hitbox(a, scene, colliders, hitbox);
    }
    int i = 0;
    while (colliders[i] != NULL)
        colliders[i++]->is_trigger = true;
    return colliders;
}

hitbox_t **get_hitbox(entity_t *a, scene_t *scene, hitbox_t **colliders,
hitbox_t *hitbox)
{
    for (int j = 0; j < get_entity_count(scene); j++) {
        entity_t *entity = scene->entities[j];
        if (entity == a || get_hitbox_count(entity) < 1)
            continue;
        hitbox_t **colliding = is_entity_colliding(hitbox, entity);
        if (colliding[0] != NULL)
            colliders = merge_hitbox_arrays(colliders, colliding);
        free(colliding);
    }
    return colliders;
}
