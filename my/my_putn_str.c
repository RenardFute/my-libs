/*
** EPITECH PROJECT, 2022
** B-CPE-101-NAN-1-1-myprintf-axel.eckenberg
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "my.h"

void my_putn_str(char const *str, int len)
{
    int i = 0;
    while (str[i] != 0 && i < len){
        my_putchar(str[i]);
        i++;
    }
}
