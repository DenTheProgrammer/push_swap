//
// Created by Maybell Debbi on 2019-05-16.
//

#ifndef PUSH_SWAP_PUSH_SWAP_H
# define PUSH_SWAP_PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include "libft/libft.h"

typedef struct s_node
{
    int nbr;
    struct s_node *prev;
    struct s_node *next;
} t_node;

typedef struct
{
	char *ops;
	char *name;
    int size;
    t_node *head;
    t_node *tail;
} t_stack;

t_node *create_node(int nbr);
void    add_node_tail(t_node **tail, t_node *node);
t_stack *create_stack(int *arr, int size, char *name, char *ops);
void print_stacks(t_stack *a, t_stack *b);
int is_sorted_asc(t_stack *a);
int is_sorted_desc(t_stack *a);

void    swap(t_stack *stack, char **ops);
void    swap_both(t_stack *a, t_stack *b, char **ops);
void    push(t_stack *src, t_stack *dest, char **ops);
void    rotate(t_stack *stack, char **ops);
void    rotate_both(t_stack *a, t_stack *b, char **ops);
void    reverse_rotate(t_stack *stack, char **ops);
void    reverse_rotate_both(t_stack *a, t_stack *b, char **ops);

void bubble_sort(int *arr, size_t len);
int    radix_sort(t_stack *a, t_stack *b);
void	mdebbis_sort(t_stack *a, t_stack *b, int *tab, size_t len, char **ops);


int is_cyclesorted_desc(t_stack *stack);
#endif //PUSH_SWAP_PUSH_SWAP_H
