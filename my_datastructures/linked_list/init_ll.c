/*
** EPITECH PROJECT, 2022
** my-libs
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "../my_datastructures.h"

linked_list_t *create_linked_list(void)
{
    linked_list_t *list = malloc(sizeof(linked_list_t));
    list->size = 0;
    list->first = NULL;
    return list;
}
