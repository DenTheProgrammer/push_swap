//
// Created by Maybell Debbi on 2019-05-16.
//

#ifndef PUSH_SWAP_PUSH_SWAP_H
# define PUSH_SWAP_PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>

typedef struct s_node
{
    int nbr;
    struct s_node *next;
} t_node;

typedef struct
{
    int size;
    t_node *head;
    t_node *tail;
} t_stack;

t_node *create_node(int nbr);
void    add_node_tail(t_node **tail, t_node *node);
t_stack *create_stack(int *arr, int size);

#endif //PUSH_SWAP_PUSH_SWAP_H
