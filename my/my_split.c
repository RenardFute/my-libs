/*
** EPITECH PROJECT, 2022
** B-MUL-100-NAN-1-1-myhunter-axel.eckenberg
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "my.h"

char **my_split(char const *str, char separator)
{
    int start = 0;
    int end = 0;
    int word_count = get_word_count_c(str, separator);
    int l = my_strlen(str);
    int i = 0;
    char **result = malloc(sizeof(char*) * (word_count + 1));

    while (str[end] != 0) {
        if (*(str + end + 1) == separator || *(str + end + 1) == 0) {
            int world_length = end - start + 1;
            result[i] = malloc(sizeof(char) * (world_length + 1));
            my_strncpy(result[i], (str + start), world_length);
            result[i][world_length] = 0;
            start = end + 2;
            is_word_c(result[i], separator) ? i++ : 0;
        }
        end++;
    }
    result[i] = 0;
    return result;
}

int get_word_count_c(char const *str, char separator)
{
    int word_count = 0;
    while (*str != 0) {
        if (*(str + 1) == separator) {
            word_count++;
        }
        str++;
    }
    return word_count + 1;
}

int is_word_c(char *str, char separator)
{
    int r = my_strlen(str) > 0;
    while (*str != 0) {
        r = r && *str != separator;
        str++;
    }
    return r;
}
