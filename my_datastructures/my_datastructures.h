/*
** EPITECH PROJECT, 2022
** my-libs
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>

// Linked list

typedef struct node {
    void *data;
    struct node *next;
} node_t;

typedef struct linked_list {
    int size;
    node_t *first;
} linked_list_t;

linked_list_t *create_linked_list(void);
void add_node(linked_list_t *list, void *data);
void remove_node(linked_list_t *list, void *data);
void remove_node_at(linked_list_t *list, int index);
void *get_node(linked_list_t *list, int index);
bool is_list_empty(linked_list_t *list);

// Stack

typedef struct stack {
    int size;
    node_t *first;
} stack_t;

stack_t *create_stack(void);
void push(stack_t *stack, void *data);
void *pop(stack_t *stack);
void *peek(stack_t *stack);
bool is_stack_empty(stack_t *stack);

// Queue

typedef struct queue {
    int size;
    node_t *first;
    node_t *last;
} queue_t;

queue_t *create_queue(void);
void enqueue(queue_t *queue, void *data);
void *dequeue(queue_t *queue);
void *peek_queue(queue_t *queue);
bool is_queue_empty(queue_t *queue);
