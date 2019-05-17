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
    new->prev = NULL;
    return (new);
}

void    add_node_tail(t_node **tail, t_node *node)
{
    if(*tail)
        (*tail)->next = node;
    node->prev = *tail;
    *tail = node;
}


t_stack *create_stack(int *arr, int size, char *name, char *ops)
{
    t_stack *new;
    int i;
    t_node *curr;

    new = (t_stack*)malloc(sizeof(t_stack));
    new->name = name;
    new->ops = ops;
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