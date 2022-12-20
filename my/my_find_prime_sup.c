/*
** EPITECH PROJECT, 2022
** B-CPE-100-NAN-1-1-cpoolday05-axel.eckenberg
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "my.h"

int my_find_prime_sup(int nb)
{
    for (int i = nb; i < 2147483647; i++) {
        if (my_is_prime(i)) return i;
    }
    return 0;
}
