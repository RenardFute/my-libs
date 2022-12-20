/*
** EPITECH PROJECT, 2022
** my-libs
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "../my_datastructures.h"

void add_node(linked_list_t *list, void *data)
{
    node_t *node = malloc(sizeof(node_t));
    node->data = data;
    node->next = NULL;
    node_t *current = list->first;

    if (current == NULL) {
        list->first = node;
        list->size++;
        return;
    }
    while (current != NULL) {
        current = current->next;
    }
    current->next = node;
    list->size++;
}

void remove_node(linked_list_t *list, void *data)
{
    node_t *current = list->first;
    node_t *previous = NULL;
    node_t *match = NULL;

    while (current != NULL) {
        if (current->data == data) {
            match = current;
            break;
        }
        previous = current;
        current = current->next;
    }
    if (match == NULL)
        return;
    if (previous == NULL) {
        list->first = match->next;
        free(match);
        list->size--;
        return;
    }
    previous->next = match->next;
    free(match);
    list->size--;
}

void remove_node_at(linked_list_t *list, int index)
{
    node_t *current = list->first;
    node_t *previous = NULL;
    node_t *match = NULL;
    int i = 0;

    while (current != NULL) {
        if (i == index) {
            match = current;
            break;
        }
        previous = current;
        current = current->next;
        i++;
    }
    if (match == NULL)
        return;
    if (previous == NULL) {
        list->first = match->next;
        free(match);
        list->size--;
        return;
    }
    previous->next = match->next;
    free(match);
    list->size--;
}

bool is_list_empty(linked_list_t *list)
{
    return list->size == 0;
}
