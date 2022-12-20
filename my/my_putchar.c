/*
** EPITECH PROJECT, 2022
** B-CPE-100-NAN-1-1-cpoolday07-axel.eckenberg
** File description:
** Print a char in the std output
*/

#include "my.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}
