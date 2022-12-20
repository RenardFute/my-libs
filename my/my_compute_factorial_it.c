/*
** EPITECH PROJECT, 2022
** B-CPE-100-NAN-1-1-cpoolday05-axel.eckenberg
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "my.h"

int my_compute_factorial_it(int nb)
{
    long r = 1;
    int i;

    if (nb == 0) return 1;
    if (nb < 0) return 0;

    for (i = nb; i > 0; i--){
        r *= i;
        if (r > 2147483647) return 0;
    }

    return r;
}
