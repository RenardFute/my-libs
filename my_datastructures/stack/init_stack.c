/*
** EPITECH PROJECT, 2022
** my-libs
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "../my_datastructures.h"

stack_t *create_stack(void)
{
    stack_t *stack = malloc(sizeof(stack_t));
    stack->size = 0;
    stack->first = NULL;
    return stack;
}
