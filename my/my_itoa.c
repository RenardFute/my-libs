/*
** EPITECH PROJECT, 2022
** B-MUL-100-NAN-1-1-myhunter-axel.eckenberg
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "my.h"

char *my_itoa(int nb)
{
    int len = len_of_int(nb);
    if (nb < 0)
        len++;
    char *str = malloc(sizeof(char) * (len + 1));
    int i = 0;
    if (nb < 0) {
        str[i++] = '-';
        nb *= -1;
    }
    for (int j = len - 1; j >= i; j--) {
        str[j] = (nb % 10) + '0';
        nb /= 10;
    }
    str[len] = '\0';
    return str;
}
