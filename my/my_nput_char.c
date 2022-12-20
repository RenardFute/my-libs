/*
** EPITECH PROJECT, 2022
** B-CPE-101-NAN-1-1-myprintf-axel.eckenberg
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "my.h"

void my_nput_char(char c, size_t n)
{
    for (int i = 0; i < n; i++) {
        my_putchar(c);
    }
}
