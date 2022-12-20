/*
** EPITECH PROJECT, 2022
** B-CPE-100-NAN-1-1-cpoolday04-axel.eckenberg
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "my.h"

int my_strlen(char const * str)
{
    char c;
    int r = -1;
    do {
        c = *str;
        str++;
        r++;
    } while ( c != 0);
    return r;
}
