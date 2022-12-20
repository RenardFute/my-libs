/*
** EPITECH PROJECT, 2022
** B-CPE-100-NAN-1-1-cpoolday06-axel.eckenberg
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "my.h"

char *my_strupcase(char *str)
{
    int i = 0;
    while (*str != 0) {
        if (*str >= 'a' && *str <= 'z') {
            (*str) -= 'a' - 'A';
        }
        str++;
        i++;
    }
    return str - i;
}
