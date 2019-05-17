//
// Created by Maybell Debbi on 2019-05-16.
//

#include "push_swap.h"

void    swap(t_stack *stack, char *name)
{
    t_node *tmp;

    if (stack->size == 1)
        return ;
    if (stack->size == 2)
        stack->tail = stack->head;//?
    tmp = stack->head;
    stack->head = stack->head->next;
    stack->head->prev = NULL;
    tmp->next = stack->head->next;
    stack->head->next = tmp;
    stack->head->next->prev = stack->head;
    tmp->next->prev = tmp;
    if (*name)
        printf("s%s\n", name);
}

void    swap_both(t_stack *a, t_stack *b)
{
    swap(a, "");
    swap(b, "");
    printf("ss");

}

void    push(t_stack *src, t_stack *dest)
{
    t_node *tmp;

    if (src->size == 0)
        return ;
    tmp = src->head;
    src->head = src->head->next;
    tmp->next = dest->head;
    dest->head = tmp;
    src->size--;
    dest->size++;
    if (src->size > 0)
        src->head->prev = NULL;
    dest->head->prev = NULL;
    if (dest->size > 1)
        dest->head->next->prev = dest->head;
    if (src->size == 0 || src->size == 1)
        src->tail = src->size == 1 ? src->head : NULL;
    if (dest->size == 1)
        dest->tail = dest->head;
    printf("p%c\n", dest->name);
}