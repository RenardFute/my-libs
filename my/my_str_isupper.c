/*
** EPITECH PROJECT, 2022
** B-CPE-100-NAN-1-1-cpoolday06-axel.eckenberg
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "my.h"

int my_str_isupper(char const *str)
{
    int r = 1;
    while (*str != 0) {
        r = r && (*str >= 'A' && *str <= 'Z');
        str++;
    }
    return r;
}
