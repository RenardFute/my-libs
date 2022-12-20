/*
** EPITECH PROJECT, 2022
** B-CPE-100-NAN-1-1-cpoolday05-axel.eckenberg
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "my.h"

int my_compute_square_root(int nb)
{
    if (nb <= 0) return 0;

    for (int i = 0; i <= nb / 2 + 1; i++) {
        if (my_compute_power_rec(i, 2) == nb) {
            return i;
        }
    }

    return 0;
}
