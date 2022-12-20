/*
** EPITECH PROJECT, 2022
** B-CPE-100-NAN-1-1-cpoolday07-axel.eckenberg
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "my.h"

void my_swap(int * a, int * b)
{
    int c = *b;
    *b = *a;
    *a = c;
}

void my_swap_char(char * a, char * b)
{
    char c = *b;
    *b = *a;
    *a = c;
}
