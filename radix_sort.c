/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdebbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 18:29:38 by mdebbi            #+#    #+#             */
/*   Updated: 2019/05/23 18:29:46 by mdebbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		sort(t_stack *a, t_stack *b, char **ops)
{
	int mask;
	int i;
	int pushcnt;
	int start_size;

	mask = 1;
	start_size = a->size;
	while (!is_sorted_asc(a))
	{
		i = 0;
		pushcnt = 0;
		while (i++ < start_size && !(a->size == start_size && is_sorted_asc(a)))
		{
			if ((a->head->nbr & mask) == 0)
			{
				push(a, b, ops);
				pushcnt++;
			}
			else
				rotate(a, ops);
		}
		while (pushcnt-- && !(a->size == start_size && is_sorted_asc(a)))
			push(b, a, ops);
		mask = mask << 1;
	}
}

static void		neg_to_b(t_stack *a, t_stack *b, char **ops)
{
	int		neg_count;
	t_node	*ahead;

	neg_count = 0;
	ahead = a->head;
	while (ahead)
	{
		if (ahead->nbr < 0)
			neg_count++;
		ahead = ahead->next;
	}
	while (neg_count)
	{
		if (a->head->nbr < 0)
		{
			push(a, b, ops);
			neg_count--;
		}
		else
			rotate(a, ops);
	}
}

static void		neg_to_a(t_stack *a, t_stack *b, char **ops)
{
	while (b->size > 0)
	{
		rev_rotate(b, ops);
		push(b, a, ops);
	}
}

void			radix_sort(t_stack *a, t_stack *b, char **ops)
{
	neg_to_b(a, b, ops);
	sort(a, b, ops);
	sort(b, a, ops);
	neg_to_a(a, b, ops);
}
