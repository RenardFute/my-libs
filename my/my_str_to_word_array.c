/*
** EPITECH PROJECT, 2022
** B-CPE-100-NAN-1-1-cpoolday08-axel.eckenberg
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "my.h"

int get_word_count(char const *str)
{
    int word_count = 0;
    while (*str != 0) {
        if (is_char_for_new_word(*(str + 1))) {
            word_count++;
        }
        str++;
    }
    return word_count;
}

int is_word(char *str)
{
    int r = my_strlen(str) > 0;
    while (*str != 0) {
        r = r && !is_char_for_new_word(*str);
        str++;
    }
    return r;
}

char **my_str_to_word_array(char const *str)
{
    int start = 0;
    int end = 0;
    int word_count = get_word_count(str);
    int l = my_strlen(str);
    int i = 0;
    char **result = malloc(sizeof(char*) * (word_count + 1));

    while (str[end] != 0) {
        if (is_char_for_new_word(*(str + end + 1))) {
            int world_length = end - start + 1;
            result[i] = malloc(sizeof(char) * (world_length + 1));
            my_strncpy(result[i], (str + start), world_length);
            result[i][world_length] = 0;
            start = end + 2;
            is_word(result[i]) ? i++ : 0;
        }
        end++;
    }
    result[i] = 0;
    return result;
}
