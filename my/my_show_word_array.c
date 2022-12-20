/*
** EPITECH PROJECT, 2022
** B-CPE-100-NAN-1-1-cpoolday08-axel.eckenberg
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "my.h"

int my_show_word_array(char * const *tab)
{
    while (*tab != 0) {
        my_putstr(*tab);
        my_putchar('\n');
        tab++;
    }
    return 0;
}
