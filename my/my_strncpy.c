/*
** EPITECH PROJECT, 2022
** B-CPE-100-NAN-1-1-cpoolday06-axel.eckenberg
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "my.h"

char *my_strncpy(char *dest, char const *src, int n)
{
    int count = 0;

    if (n < 0) {
        n *= -1;
    }
    while (src[count] != 0 && count < n) {
        dest[count] = src[count];
        count++;
    }
    if (count < n) {
        for (int i = 0; i < n - count; i++) {
            dest[count + i] = 0;
        }
    }
    return dest;
}
