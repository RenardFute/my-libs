/*
** EPITECH PROJECT, 2022
** B-MUL-100-NAN-1-1-myhunter-axel.eckenberg
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "../game.h"

void add_hitbox(entity_t *entity, hitbox_t *hitbox)
{
    int i = 0;
    hitbox->parent = entity;
    hitbox_t **new_hitboxes = malloc(sizeof(hitbox_t *)
    * (get_hitbox_count(entity) + 2));
    while (entity->hitboxes[i] != NULL) {
        new_hitboxes[i] = entity->hitboxes[i];
        i++;
    }
    new_hitboxes[i] = hitbox;
    new_hitboxes[i + 1] = NULL;
    free(entity->hitboxes);
    entity->hitboxes = new_hitboxes;
}

void update_hitboxes(entity_t *entity)
{
    int i = 0;
    while (entity->hitboxes[i] != NULL) {
        hitbox_t *hitbox = entity->hitboxes[i];
        if (hitbox->is_trigger && hitbox->reset_counter < 15)
            hitbox->reset_counter++;
        if (hitbox->is_trigger && hitbox->reset_counter >= 15) {
            hitbox->is_trigger = false;
            hitbox->reset_counter = 0;
        }
        update_pos_and_size(hitbox);
        i++;
    }
}

int get_hitbox_count(entity_t *entity)
{
    int i = 0;
    while (entity->hitboxes[i++] != NULL);
    return i - 1;
}

hitbox_t *create_hitbox(sfFloatRect rect, char *name)
{
    hitbox_t *hitbox = malloc(sizeof(hitbox_t));
    hitbox->rect = rect;
    hitbox->shape = sfRectangleShape_create();
    sfRectangleShape_setSize(hitbox->shape, (sfVector2f){rect.width,
    rect.height});
    sfRectangleShape_setFillColor(hitbox->shape, sfTransparent);
    sfRectangleShape_setOutlineColor(hitbox->shape, sfRed);
    sfRectangleShape_setOutlineThickness(hitbox->shape, 2);
    hitbox->name = my_strdup(name);
    hitbox->is_trigger = false;
    hitbox->reset_counter = 0;
    return hitbox;
}
