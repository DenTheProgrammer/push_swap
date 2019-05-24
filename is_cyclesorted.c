/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_cyclesorted.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdebbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 17:47:10 by mdebbi            #+#    #+#             */
/*   Updated: 2019/05/24 17:47:11 by mdebbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		is_cyclesorted_asc(t_stack *stack)
{
	t_node	*head;
	int		min;
	int		max;

	if (stack->size <= 2)
		return (1);
	min = find_min(stack);
	max = find_max(stack);
	head = stack->head;
	while (head->next)
	{
		if (head->nbr > head->next->nbr)
			if (head->nbr != max || head->next->nbr != min ||
				stack->head->nbr < stack->tail->nbr)
				return (0);
		head = head->next;
	}
	return (1);
}

int		is_cyclesorted_desc(t_stack *stack)
{
	t_node	*head;
	int		min;
	int		max;

	if (stack->size <= 2)
		return (1);
	min = find_min(stack);
	max = find_max(stack);
	head = stack->head;
	while (head->next)
	{
		if (head->nbr < head->next->nbr)
			if (head->nbr != min || head->next->nbr != max ||
				stack->head->nbr > stack->tail->nbr)
				return (0);
		head = head->next;
	}
	return (1);
}
