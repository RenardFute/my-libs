/*
** EPITECH PROJECT, 2022
** B-MUL-100-NAN-1-1-myhunter-axel.eckenberg
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "../game.h"

event_t *create_event(char *name, callback_t callback)
{
    event_t *event = malloc(sizeof(event_t));

    event->name = my_strdup(name);
    event->callback = callback;
    event->type = -1;
    event->code = -1;
    event->on_whole_scene = false;
    return event;
}

event_t *create_event_full(char *name, callback_t callback, int type, int code)
{
    event_t *event = malloc(sizeof(event_t));

    event->name = my_strdup(name);
    event->callback = callback;
    event->type = type;
    event->code = code;
    event->button = code;
    event->on_whole_scene = false;
    return event;
}
