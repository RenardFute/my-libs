/*
** EPITECH PROJECT, 2022
** B-CPE-100-NAN-1-1-cpoolday06-axel.eckenberg
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "my.h"

int my_putnbr_base(long nb, char const *base, bool show_sign)
{
    int base_size = my_strlen(base);
    long cpy = nb;
    char result[64] = {0};
    int i = 0;

    if (base_size < 2)
        return 84;
    if (cpy < 0) {
        if (show_sign)
            my_putchar('-');
        cpy *= -1;
    }
    while (cpy != 0) {
        result[i] = base[cpy % base_size];
        cpy /= base_size;
        i++;
    }
    my_revstr(result);
    my_putstr(result);
    return 0;
}

int my_putfloat_base(long nb, char const *base, bool show_sign, int cp)
{
    int base_size = my_strlen(base);
    long cpy = nb;
    char result[64] = {0};
    int i = 0;
    if (base_size < 2)
        return 84;
    if (cpy < 0) {
        if (show_sign)
            my_putchar('-');
        cpy *= -1;
    }
    while (cpy != 0) {
        result[i] = base[cpy % base_size];
        cpy /= base_size;
        i++;
        i == cp ? result[i++] = '.' : 0;
    }
    my_revstr(result);
    my_putstr(result);
    return 0;
}
