/*
** EPITECH PROJECT, 2022
** B-MUL-100-NAN-1-1-myhunter-axel.eckenberg
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "../game.h"

void free_event(game_t *game, event_t *event)
{
    if (arg(game, "verbose", "full")) {
        my_putstr("\t        - ");
        my_putstr(event->name);
        my_putchar('\n');
    }
    free(event->name);
    free(event);
}

void free_events(game_t *game, entity_t *entity)
{
    if (arg(game, "verbose", "full")) {
        my_putstr("\t      - Events: ");
        my_put_nbr(get_event_count(entity));
        my_putchar('\n');
    }
    for (int i = 0; i < get_event_count(entity); i++) {
        free_event(game, entity->events[i]);
    }
}
