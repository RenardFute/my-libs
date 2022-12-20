/*
** EPITECH PROJECT, 2022
** B-CPE-110-NAN-1-1-pushswap-axel.eckenberg
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "my.h"

void my_putchar_guard(char c)
{
    if (c == '\0')
        return;
    write(1, &c, 1);
}
