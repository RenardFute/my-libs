/*
** EPITECH PROJECT, 2022
** B-MUL-100-NAN-1-1-myhunter-axel.eckenberg
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "../game.h"

bool is_colliding(entity_t *a, entity_t *b)
{
    if (get_hitbox_count(a) < 1 || get_hitbox_count(b) < 1)
        return false;
}

bool is_hitbox_colliding(hitbox_t *a, hitbox_t *b)
{
    sfVector2f pos_a = sfRectangleShape_getPosition(a->shape);
    sfVector2f size_a = sfRectangleShape_getSize(a->shape);
    sfVector2f pos_b = sfRectangleShape_getPosition(b->shape);
    sfVector2f size_b = sfRectangleShape_getSize(b->shape);
    if (a->is_trigger || b->is_trigger)
        return false;
    if (!is_float_equal(a->parent->position.z, b->parent->position.z, 0.1f))
        return false;
    if (pos_a.x + size_a.x < pos_b.x)
        return false;
    if (pos_a.x > pos_b.x + size_b.x)
        return false;
    if (pos_a.y + size_a.y < pos_b.y)
        return false;
    if (pos_a.y > pos_b.y + size_b.y)
        return false;
    return true;
}

hitbox_t **is_entity_colliding(hitbox_t *hitbox, entity_t *entity)
{
    int count = 0;
    hitbox_t **colliding = malloc(sizeof(hitbox_t *)
    * get_hitbox_count(entity) + 1);
    for (int i = 0; i < get_hitbox_count(entity); i++) {
        hitbox_t *other = entity->hitboxes[i];
        if (is_hitbox_colliding(hitbox, other))
            colliding[count++] = other;
    }
    colliding[count] = NULL;
    return colliding;
}
