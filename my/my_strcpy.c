/*
** EPITECH PROJECT, 2022
** B-CPE-100-NAN-1-1-cpoolday06-axel.eckenberg
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "my.h"

char *my_strcpy(char *dest, char const *src)
{
    int count = 0;
    while (src[count] != 0) {
        dest[count] = src[count];
        count++;
    }
    dest[count] = 0;
    return dest;
}
