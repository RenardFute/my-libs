/*
** EPITECH PROJECT, 2022
** B-PSU-100-NAN-1-1-sokoban-axel.eckenberg
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "my.h"

int my_array_size(void **array)
{
    int i = 0;

    while (array[i++] != NULL);
    return i - 1;
}
