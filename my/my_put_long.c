/*
** EPITECH PROJECT, 2022
** day03-Cpool
** File description:
** cpool exersises
*/
#include "my.h"

int min_long_value(void)
{
    my_put_long(9223372036);
    my_put_long(854775808);
}

int get_power(unsigned long nb)
{
int power = 0;
    while (nb / 10 > 0) {
        power++;
        nb = nb / 10;
    }
return power;
}

int my_put_long(long nb)
{
    if (nb == -2147483648)
        my_put_long(2147483648);
    else if (nb == -9223372036854775807) {
        min_long_value();
        } else {
        if (nb < 0) {
            my_putchar('-');
            nb = -1 * nb;
        }
        long number = nb, mod = 1, power = 0;
        power = get_power(nb);
        for (int i = 0; i < power; i++) {
            mod *= 10;
        }
        for (int i = 0; i <= power; i++) {
            my_putchar((nb / mod) + '0');
            nb %= mod;
            mod /= 10;
        }
    }
}

void my_put_unsigned_long(unsigned long nb)
{
    unsigned long number = nb, mod = 1, power = 0;
    power = get_power(nb);
    for (int i = 0; i < power; i++) {
        mod *= 10;
    }
    for (int i = 0; i <= power; i++) {
        my_putchar((nb / mod) + '0');
        nb %= mod;
        mod /= 10;
    }
}
