/*
** EPITECH PROJECT, 2022
** my-libs
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "../my_datastructures.h"

void *get_node(linked_list_t *list, int index)
{
    node_t *current = list->first;
    int i = 0;

    if (index < 0 || index >= list->size)
        return NULL;
    while (i < index) {
        current = current->next;
        i++;
    }
    return current->data;
}
