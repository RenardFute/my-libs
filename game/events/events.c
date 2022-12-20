/*
** EPITECH PROJECT, 2022
** B-MUL-100-NAN-1-1-myhunter-axel.eckenberg
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "../game.h"

void close_event(game_t *game, event_t *event, scene_t *scene, entity_t *entity)
{
    sfRenderWindow_close(game->window);
}

bool is_in_bound(entity_t *e, sfVector2f mouse_pos)
{
    if (e != NULL) {
        sfVector2f entity_pos = sfSprite_getPosition(e->sprite);
        sfVector2f origin = sfSprite_getOrigin(e->sprite);
        entity_pos.x -= origin.x;
        entity_pos.y -= origin.y;
        sfVector2f entity_size = e->size;
        if (mouse_pos.x < entity_pos.x
        || mouse_pos.x > entity_pos.x + entity_size.x)
            return false;
        if (mouse_pos.y < entity_pos.y
        || mouse_pos.y > entity_pos.y + entity_size.y)
            return false;
    }
    return true;
}

void call_events(game_t *game, event_t **events, entity_t *e, sfEvent event)
{
    int i = 0;
    while (events[i] != NULL) {
        event_t *current_event = events[i++];
        if (current_event->type != event.type && current_event->type != -1)
            continue;
        if (current_event->type == sfEvtKeyPressed
        && current_event->code != event.key.code
        && current_event->code != -1)
            continue;
        if (current_event->type == sfEvtMouseButtonPressed
        && !current_event->on_whole_scene) {
            sfVector2f p =
            (sfVector2f) {event.mouseButton.x, event.mouseButton.y};
            if (current_event->button != event.mouseButton.button
            || !is_in_bound(e, p))
                continue;
        }
        current_event->event = &event;
        current_event->callback(game, current_event, game->active_scene, e);
    }
}

void handle_events(game_t *gme)
{
    event_t **events = malloc(sizeof(event_t *) * 2);
    events[0] = create_event_full("close", &close_event, sfEvtClosed, 0);
    events[1] = NULL;

    sfEvent event;

    while (sfRenderWindow_pollEvent(gme->window, &event)) {
        call_events(gme, events, NULL, event);

        for (int i = 0; i < get_entity_count(gme->active_scene); i++) {
            entity_t *entity = gme->active_scene->entities[i];
            call_events(gme, entity->events, entity, event);
        }
    }
}
