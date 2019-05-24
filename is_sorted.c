/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdebbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 18:27:52 by mdebbi            #+#    #+#             */
/*   Updated: 2019/05/23 18:27:53 by mdebbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		is_sorted_asc(t_stack *a)
{
	t_node *head;

	head = a->head;
	while (head && head->next)
	{
		if (head->nbr > head->next->nbr)
			return (0);
		head = head->next;
	}
	return (1);
}
int		is_sorted_desc(t_stack *a)
{
	t_node *head;

	head = a->head;
	while (head && head->next)
	{
		if (head->nbr < head->next->nbr)
			return (0);
		head = head->next;
	}
	return (1);
}
