/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdebbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 18:30:28 by mdebbi            #+#    #+#             */
/*   Updated: 2019/05/23 18:30:30 by mdebbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    rotate(t_stack *stack, char **ops)
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
}

void    rot_both(t_stack *a, t_stack *b, char **ops)
{
    rotate(a, NULL);
    rotate(b, NULL);
    if (ops)
		*ops = ft_strjoin_free(*ops, " rr", 1);
}

void    rev_rotate(t_stack *stack, char **ops)
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

void    rev_rot_both(t_stack *a, t_stack *b, char **ops)
{
	rev_rotate(a, NULL);
	rev_rotate(b, NULL);
	if (ops)
		*ops = ft_strjoin_free(*ops, " rrr", 1);
}
