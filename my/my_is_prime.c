/*
** EPITECH PROJECT, 2022
** B-CPE-100-NAN-1-1-cpoolday05-axel.eckenberg
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "my.h"

int my_is_prime(int nb)
{
    int i;

    if (nb % 2 == 0 && nb != 2) return 0;
    if (nb < 2) return 0;
    for (i = 3; i < nb; i += 2) {
        if (nb % i == 0)
            return 0;
    }
    return 1;
}
