//
// Created by Maybell Debbi on 2019-05-16.
//

#include "push_swap.h"

void    rotate(t_stack *stack, char **ops)//ra rb
{
    t_node *tmp;

    if (ops)
		*ops = ft_strjoin_free(*ops, ft_strjoin_free(" r", stack->name, 0), 3);
    if (stack->size <= 1)
        return ;
    tmp = stack->head;
    stack->head = stack->head->next;
    stack->head->prev = NULL;
    stack->tail->next = tmp;
    tmp->next = NULL;
    tmp->prev = stack->tail;
    stack->tail = tmp;
//    printf("r%c\n", stack->name);
}

void    rot_both(t_stack *a, t_stack *b, char **ops)//rr
{
//	static char *null = NULL;

    rotate(a, NULL);
    rotate(b, NULL);
	*ops = ft_strjoin_free(*ops, " rr", 1);
}

void    rev_rotate(t_stack *stack, char **ops)//rra rrb
{
    t_node *tmp;

    if (ops)
		*ops = ft_strjoin_free(*ops, ft_strjoin_free(" rr", stack->name, 0), 3);
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

void    rev_rot_both(t_stack *a, t_stack *b, char **ops)//rrr
{
//	static char *null = NULL;

	rev_rotate(a, NULL);
	rev_rotate(b, NULL);
	*ops = ft_strjoin_free(*ops, " rrr", 1);
}