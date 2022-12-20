/*
** EPITECH PROJECT, 2022
** B-CPE-100-NAN-1-1-cpoolday06-axel.eckenberg
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "my.h"

char *inside(int *start, int *i, char const **to_find, char **str)
{
    if (**str == **to_find) {
        if (*start == -1) {
            *start = *i;
        }
        (*to_find)++;
        if (**to_find == 0){
            return ((*str - *i) + *start);
        }
    } else if (*start != -1) {
        *to_find -= *i - *start;
        *start = -1;
        (   *str)--;
        (*i)--;
    }
    return NULL;
}

char *my_strstr(char *str, char const *to_find)
{
    int start = -1;
    int i = 0;
    while (*str != 0) {
        char * r = inside(&start, &i, &to_find, &str);
        if (r != NULL)
            return r;
        str++;
        i++;
    }
    return NULL;
}
