/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_need_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdebbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 17:50:37 by mdebbi            #+#    #+#             */
/*   Updated: 2019/05/24 17:50:39 by mdebbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		is_need_swap_asc(t_stack *stack)
{
	int		min;
	int		max;
	t_node	*head;

	min = find_min(stack);
	max = find_max(stack);
	head = stack->head;
	if (head->nbr > head->next->nbr)
		if (head->nbr != max || head->next->nbr != min)
			return (1);
	return (0);
}

int		is_need_swap_desc(t_stack *stack)
{
	int		min;
	int		max;
	t_node	*head;

	min = find_min(stack);
	max = find_max(stack);
	head = stack->head;
	if (head->nbr < head->next->nbr)
		if (head->nbr != min || head->next->nbr != max)
			return (1);
	return (0);
}
