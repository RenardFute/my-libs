/*
** EPITECH PROJECT, 2022
** B-MUL-100-NAN-1-1-myhunter-axel.eckenberg
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "../game.h"

bool is_event(entity_t *entity, sfEventType type)
{
    int i = 0;
    while (entity->events[i] != NULL) {
        if (entity->events[i]->type == type)
            return true;
        i++;
    }
    return false;
}
