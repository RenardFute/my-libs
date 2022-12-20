/*
** EPITECH PROJECT, 2022
** my-libs
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "../my_datastructures.h"

void push(stack_t *stack, void *data)
{
    node_t *new = malloc(sizeof(node_t));
    new->data = data;
    new->next = stack->first;
    stack->first = new;
    stack->size++;
}

void *pop(stack_t *stack)
{
    node_t *current = stack->first;
    void *data = current->data;

    stack->first = current->next;
    free(current);
    stack->size--;
    return data;
}

void *peek(stack_t *stack)
{
    return stack->first->data;
}

bool is_stack_empty(stack_t *stack)
{
    return stack->size == 0;
}
