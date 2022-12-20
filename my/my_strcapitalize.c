/*
** EPITECH PROJECT, 2022
** B-CPE-100-NAN-1-1-cpoolday06-axel.eckenberg
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "my.h"


int is_char_for_new_word(char c)
{
    return c == ' ' || c == '\n' || c == '+' || c == '-' || c == 0;
}

char *my_strcapitalize(char *str)
{
    str = my_strlowcase(str);
    int len = my_strlen(str);

    for (int i = 0; i < len; i++) {
        if ((str + i) == str || is_char_for_new_word(*(str + i - 1))) {
            *(str + i) -= *(str + i) >= 'a' && *(str + i) <= 'z' ? 32 : 0;
        }
    }

    return str;
}
