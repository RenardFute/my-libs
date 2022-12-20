/*
** EPITECH PROJECT, 2022
** B-CPE-100-NAN-1-1-cpoolday08-axel.eckenberg
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "my.h"

char *my_strdup(char const *src)
{
    char *new = malloc(sizeof(char) * my_strlen(src) + 1);

    if (new == NULL) return new;
    my_strcpy(new, src);
    return new;
}
