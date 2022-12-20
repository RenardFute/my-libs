/*
** EPITECH PROJECT, 2022
** B-CPE-100-NAN-1-1-cpoolday03-axel.eckenberg
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "my.h"

int len_of_int(long long n)
{
    int len = 0;
    n = n < 0 ? -n : n;
    do {
        n /= 10;
        len++;
    } while (n > 0);
    return len;
}

int len_of_int_base(long long n, int base)
{
    int i = 0;
    n = ABS(n);
    while (n > 0) {
        i++;
        n /= base;
    }
    return i;
}

void execute(int nb)
{
    long rest = nb;
    while (rest > 0) {
        rest = print_and_get_rest(rest);
    }
}

int my_put_nbr(int nb)
{
    if (nb == 0) {
        my_putchar('0');
        return 0;
    }

    if (nb == -2147483648) {
        my_putchar('-');
        my_putchar('2');
        nb %= 1000000000;
        nb *= -1;
    } else if (nb < 0) {
        my_putchar('-');
        nb *= -1;
    }
    execute(nb);
    if (nb % 10 == 0)
        my_putchar('0');
    return 0;
}

int print_and_get_rest(int n)
{
    int div = 1;
    for (int i = 0; i < len_of_int(n)-1; i++) {
        div *= 10;
    }
    int a = n / div;
    int b = n % div;
    my_putchar('0' + a);
    if (len_of_int(b) != len_of_int(n) - 1) {
        int dif = len_of_int(n) - len_of_int(b);
        for (int i = 0; i < dif - 1; i++) {
            my_putchar('0');
        }
    }
    return b;
}
