/*
** EPITECH PROJECT, 2022
** piscine
** File description:
** Personal "print fonctions"
*/
#include "my.h"
char *my_strncat(char *dest, char const *src, int n)
{
    int dest_len = my_strlen(dest);
    int i;
    for (i = 0; i < n; i++){
        dest[(dest_len) + i] = src[i];
    }
    dest[dest_len + i] = '\0';
    return dest;
}
