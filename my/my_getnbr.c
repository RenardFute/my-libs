/*
** EPITECH PROJECT, 2022
** B-CPE-100-NAN-1-1-cpoolday04-axel.eckenberg
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "my.h"

int execute2(char const * str, int * l, long * r, int is_neg)
{
    if (*str >= '0' && *str <= '9') {
        *l = 1;
        *r = (*r) * 10 + (*str - '0');
        if ((*r > 2147483647 && !is_neg) || (*r > 2147483648 && is_neg))
            return 2;
    } else {
        if (*l) {
            return 1;
        } else {
            *l = 0;
        }
    }
    return 0;
}

int my_getnbr(char const * str)
{
    long r = 0;
    int minus_count = 0;
    int last_was_int = 0;
    int return_code = 0;
    int is_neg = 0;
    while (* str != 0 && return_code != 1){
        if (*str == '-') {
            minus_count++;
            last_was_int = 0;
            str++;
            is_neg = 1;
            continue;
        }
        return_code = execute2(str, &last_was_int, &r, is_neg);
        if (return_code == 2) {
            return 0;
        }
        str++;
    }
    return minus_count % 2 ? r * -1 : r;
}
