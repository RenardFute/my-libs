/*
** EPITECH PROJECT, 2022
** B-CPE-100-NAN-1-1-cpoolday06-axel.eckenberg
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "my.h"

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;

    if (n < 0) {
        n *= -1;
    }
    do {
        if (*s1 != *s2) {
            return *s1 - *s2;
        }
        s1++;
        s2++;
        i++;
    } while (*s1 != 0 && *s2 != 0 && i < n);
    if (i < n || *s1 == 0 || *s2 == 0) {
        return 0;
    }
    return *s1 - *s2;
}
