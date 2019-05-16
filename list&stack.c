//
// Created by Maybell Debbi on 2019-05-16.
//

#include "push_swap.h"

t_node *create_node(int nbr)
{
    t_node *new;

    new = (t_node*)malloc(sizeof(t_node));
    new->nbr = nbr;
    new->next = NULL;
    return (new);
}

void    add_node_tail(t_node **tail, t_node *node)
{
    if(*tail)
        (*tail)->next = node;
    *tail = node;
}


t_stack *create_stack(int *arr, int size)
{
    t_stack *new;
    int i;
    t_node *curr;

    new = (t_stack*)malloc(sizeof(t_stack));
    new->size = size;
    new->head = NULL;
    new->tail = NULL;
    i = 0;
    while (i < size)
    {
        curr = create_node(arr[i]);
        if (i++ == 0)
            new->head = curr;
        add_node_tail(&(new->tail), curr);
    }
    return (new);
}