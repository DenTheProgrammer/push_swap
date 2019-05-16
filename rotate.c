//
// Created by Maybell Debbi on 2019-05-16.
//

#include "push_swap.h"

void    rotate(t_stack *stack)//ra rb
{
    t_node *tmp;

    if (stack->size <= 1)
        return ;
    tmp = stack->head;
    stack->head = stack->head->next;
    stack->head->prev = NULL;
    stack->tail->next = tmp;
    tmp->next = NULL;
    tmp->prev = stack->tail;
    stack->tail = tmp;
}

void    rotate_both(t_stack *a, t_stack *b)//rr
{
    rotate(a);
    rotate(b);
}

void    reverse_rotate(t_stack *stack)//rra rrb
{
    t_node *tmp;

    if (stack->size <= 1)
        return ;
    tmp = stack->tail;
    tmp->next = stack->head;
    stack->head = tmp;
    tmp->prev->next = NULL;
    tmp->next->prev = tmp;
    stack->tail = tmp->prev;
    tmp->prev = NULL;
}

void    reverse_rotate_both(t_stack *a, t_stack *b)//rrr
{
    reverse_rotate(a);
    reverse_rotate(b);
}