/*
** EPITECH PROJECT, 2022
** my-libs
** File description:
** No file there , just an epitech header example .bnon
** You can even have multiple lines if you want !
*/

#include "../my_datastructures.h"

queue_t *create_queue(void)
{
    queue_t *queue = malloc(sizeof(queue_t));
    queue->size = 0;
    queue->first = NULL;
    queue->last = NULL;
    return queue;
}
