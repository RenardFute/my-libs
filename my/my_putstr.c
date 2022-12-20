/*
** EPITECH PROJECT, 2022
** B-CPE-100-NAN-1-1-cpoolday04-axel.eckenberg
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "my.h"

void my_putstr(char const * str)
{
    int len = my_strlen(str);
    write(1, str, len);
}
