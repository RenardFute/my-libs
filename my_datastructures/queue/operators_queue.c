/*
** EPITECH PROJECT, 2022
** my-libs
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "../my_datastructures.h"

void enqueue(queue_t *queue, void *data)
{
    node_t *new = malloc(sizeof(node_t));
    new->data = data;
    new->next = NULL;
    if (queue->size == 0) {
        queue->first = new;
    } else {
        queue->last->next = new;
    }
    queue->last = new;
    queue->size++;
}

void *dequeue(queue_t *queue)
{
    node_t *current = queue->first;
    void *data = current->data;

    queue->first = current->next;
    free(current);
    queue->size--;
    return data;
}

void *peek_queue(queue_t *queue)
{
    return queue->first->data;
}

bool is_queue_empty(queue_t *queue)
{
    return queue->size == 0;
}
