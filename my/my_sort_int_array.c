/*
** EPITECH PROJECT, 2022
** B-CPE-100-NAN-1-1-cpoolday04-axel.eckenberg
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "my.h"

int sort(int * array, int size)
{
    int last = -2147483648;
    int t = 1;
    for (int i = 0; i < size; i++) {
        if (array[i] > last || t) {
            last = array[i];
            t = 0;
        } else {
            my_swap(&array[i], &array[i - 1]);
            return 1;
        }
    }
    return 0;
}

void my_sort_int_array(int * array, int size)
{
    int changed = 1;
    while (changed) {
        changed = sort(array, size);
    }
}
