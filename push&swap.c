//
// Created by Maybell Debbi on 2019-05-16.
//

#include "push_swap.h"

void    swap(t_stack *stack, char **ops)
{
    t_node *tmp;

    if (ops)
		*ops = ft_strjoin_free(*ops, ft_strjoin_free(" s", stack->name, 0), 3);
    if (stack->size < 2)
        return ;
    if (stack->size == 2)
        stack->tail = stack->head;//?
    tmp = stack->head;
    stack->head = stack->head->next;
    stack->head->prev = NULL;
    tmp->next = stack->head->next;
    stack->head->next = tmp;
    stack->head->next->prev = stack->head;
    if (tmp->next)
    	tmp->next->prev = tmp;
//    if (*op)
//        printf("s%s\n", op);

}

void    swap_both(t_stack *a, t_stack *b, char **ops)
{
//	static char *null = NULL;

    swap(a, NULL);
    swap(b, NULL);
	if (ops)
		*ops = ft_strjoin_free(*ops, " ss", 1);
}

void    push(t_stack *src, t_stack *dest, char **ops)
{
    t_node *tmp;

    if (ops)
		*ops = ft_strjoin_free(*ops, ft_strjoin_free(" p", dest->name, 0), 3);
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
//    printf("p%c\n", dest->name);
}