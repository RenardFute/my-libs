/*
** EPITECH PROJECT, 2022
** B-MUL-100-NAN-1-1-myhunter-axel.eckenberg
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "../game.h"

void render(game_t *game)
{
    sfRenderWindow_clear(game->window, sfWhite);

    render_scene(game, game->active_scene);

    sfRenderWindow_display(game->window);
}

void render_scene(game_t *game, scene_t *scene)
{
    sort_entities(scene);
    for (int i = 0; i < get_entity_count(scene); i++) {
        update_hitboxes(scene->entities[i]);
    }
    for (int i = 0; i < get_entity_count(scene); i++) {
        if (scene->entities[i]->update != NULL)
            scene->entities[i]->update(game, scene, scene->entities[i]);
        update_animation(scene->entities[i]);
    }
    for (int i = 0; i < get_entity_count(scene); i++) {
        render_entity(game, scene, scene->entities[i]);
        show_hitbox(game, scene->entities[i]);
    }
    if (scene->gui != NULL)
        render_gui(game, scene->gui);
}

void render_entity(game_t *game, scene_t *scene, entity_t *entity)
{
    if (entity->texture != NULL)
        sfSprite_setTexture(entity->sprite, entity->texture, sfFalse);

    float perspective = PERSPECTIVE_FACTOR * entity->position.z;
    if (entity->position.z > 0 && entity->perspective_enabled == true) {
        sfSprite_setScale(entity->sprite,
        (sfVector2f) {perspective, perspective});
        entity->size = (sfVector2f) {perspective * entity->base_size.x,
        perspective * entity->base_size.y};
    }
    sfSprite_setPosition(entity->sprite,
    (sfVector2f) {entity->position.x, entity->position.y});
    sfRenderWindow_drawSprite(game->window, entity->sprite, NULL);
}

void update_animation(entity_t *entity)
{
    if (!entity->is_animated)
        return;
    entity->frame_duration_counter ++;
    if (entity->frame_duration > entity->frame_duration_counter)
        return;
    entity->frame_duration_counter = 0;
    entity->current_frame ++;
    if (entity->current_frame >= entity->frame_count)
        entity->current_frame = 0;
    sfIntRect rect = sfSprite_getTextureRect(entity->sprite);
    rect.left = entity->current_frame * rect.width;
    sfSprite_setTextureRect(entity->sprite, rect);
}

void show_hitbox(game_t *game, entity_t *entity)
{
    if (!arg(game, "hitbox", "shown") || get_hitbox_count(entity) < 1)
        return;
    for (int i = 0; i < get_hitbox_count(entity); i++) {
        sfRectangleShape *shape = entity->hitboxes[i]->shape;
        if (entity->hitboxes[i]->is_trigger)
            sfRectangleShape_setOutlineColor(shape, sfBlue);
        else
            sfRectangleShape_setOutlineColor(shape, sfRed);
        sfRenderWindow_drawRectangleShape(game->window, shape, NULL);
    }
}
