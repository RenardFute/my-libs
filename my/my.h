/*
** EPITECH PROJECT, 2022
** B-CPE-100-NAN-1-1-cpoolday07-axel.eckenberg
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#pragma once

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define ABS(x) ((x) < 0 ? -(x) : (x))

void my_putchar(char c);
int my_isneg(int nb);
int my_put_nbr(int nb);
void my_swap(int * a, int * b);
void my_swap_char(char * a, char * b);
void my_putstr(char const *str);
void my_putn_str(char const *str, int len);
void my_nput_char(char c, size_t n);
int my_strlen(char const * str);
int my_getnbr(char const * str);
void my_sort_int_array(int *tab, int size);
int my_compute_power_rec(int nb, int p);
int my_compute_power_it(int nb, int p);
int my_compute_factorial_it(int nb);
int my_compute_factorial_rec(int nb);
int my_compute_square_root(int nb);
int my_is_prime(int nb);
int my_find_prime_sup(int nb);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_revstr(char *str);
char *my_strstr(char *str, char const *to_find);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strupcase(char *str);
char *my_strlowcase(char *str);
char *my_strcapitalize(char *str);
int my_str_isalpha(char const *str);
int my_str_isnum(char const *str);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
int my_str_isprintable(char const *str);
int my_showstr(char const *str);
int my_showmem(char const *str, int size);
char *my_strcat(char *dest, char const *src);
char *my_strncat(char *dest, char const *src, int nb);
int is_char_for_new_word(char c);
int execute2(char const * str, int * l, long * r, int is_neg);
int len_of_int(long long n);
void execute(int nb);
int print_and_get_rest(int n);
int sort(int *array, int size);
char *inside(int *start, int *i, char const **to_find, char **str);
int my_show_word_array(char * const *tab);
int get_word_count(char const *str);
int is_word(char *str);
char **my_str_to_word_array(char const *str);
char *my_strdup(char const *src);
int len_of_int_base(long long n, int base);
void my_put_unsigned_long(unsigned long nb);
int my_put_long(long nb);
int get_power(unsigned long nb);
int min_long_value(void);
char **my_split(char const *str, char separator);
int get_word_count_c(char const *str, char separator);
int is_word_c(char *str, char separator);
int my_array_size(void **array);
void my_putchar_guard(char c);
char *my_itoa(int nb);
