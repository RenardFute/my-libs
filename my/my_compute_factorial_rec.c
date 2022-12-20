/*
** EPITECH PROJECT, 2022
** B-CPE-100-NAN-1-1-cpoolday05-axel.eckenberg
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "my.h"

int my_compute_factorial_rec(int nb)
{
    if (nb == 0)
        return 1;
    if (nb < 0)
        return 0;
    if (nb > 12)
        return 0;

    return nb * my_compute_factorial_rec(nb - 1);
}
