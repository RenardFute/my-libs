/*
** EPITECH PROJECT, 2022
** B-CPE-100-NAN-1-1-Cworkshoplib-axel.eckenberg
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "my.h"

int my_compute_power_it(int nb, int p)
{
    long r = nb;
    if (p < 0) {
        return 0;
    }
    if (p == 0) {
        return 1;
    }
    for (int i = 1; i < p; i++){
        r *= nb;
        if (r > 2147483647 || r < -2147483648) {
            return 0;
        }
    }
    return r;
}
