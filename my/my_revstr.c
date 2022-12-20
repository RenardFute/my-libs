/*
** EPITECH PROJECT, 2022
** B-CPE-100-NAN-1-1-cpoolday06-axel.eckenberg
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "my.h"

char *my_revstr(char *str)
{
    int len = my_strlen(str) - 1;

    for (int i = 0; i <= len / 2; i++) {
        char temp = *(str + len - i);
        *(str + len - i) = *(str + i);
        *(str + i) = temp;
    }
    return str;
}
