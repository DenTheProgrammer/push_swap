/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdebbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 16:48:11 by mdebbi            #+#    #+#             */
/*   Updated: 2019/05/31 16:48:12 by mdebbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	start_setup(t_stack *stacks[2], int *tab, int len, char **ops)
{
	int min;
	int mid;
	int max;

	min = tab[0];
	mid = tab[len / 2];
	max = tab[len - 1];
	while (stacks[0]->size > 3)
	{
		if (stacks[0]->head->nbr != min &&
				stacks[0]->head->nbr != mid &&
					stacks[0]->head->nbr != max)
			push(stacks[0], stacks[1], ops);
		else
			rotate(stacks[0], ops);
	}
	if (!is_cyclesorted_asc(stacks[0]))
	{
		swap(stacks[0], ops);
	}
}

int		get_elem_by_ind(t_stack *s, int ind)
{
	t_node	*shead;
	int		curind;

	curind = 0;
	shead = s->head;
	while (curind != ind)
	{
		shead = shead->next;
		curind++;
	}
	return (shead->nbr);
}

void	place(t_stack *a, t_stack *b, int ind, char **ops)
{
	int belem;
	int aind;
	int alind;
	int abind;
	int aelem;

	belem = get_elem_by_ind(b, ind);
	while (b->head->nbr != belem)
		ind < b->size - ind ? rotate(b, ops) : rev_rotate(b, ops);
	alind = find_lesser(a, belem);
	abind = find_bigger(a, belem);
	aind = min(alind, a->size - alind) < min(abind, a->size - abind) ?
															alind : abind;
	aelem = get_elem_by_ind(a, aind);
	if (aelem > belem)
		while (a->head->nbr != aelem)
		{
			aind < a->size - aind ? rotate(a, ops) : rev_rotate(a, ops);
		}
	else
		while (a->tail->nbr != aelem)
		{
			aind + 1 < a->size - aind - 1 ? rotate(a, ops) : rev_rotate(a, ops);
		}
	push(b, a, ops);
}

void	real_sort(t_stack *a, char **ops)
{
	int		min;
	int		minind;
	int		curind;
	t_node	*ahead;

	ahead = a->head;
	curind = 0;
	minind = 0;
	min = ahead->nbr;
	while (ahead)
	{
		if (ahead->nbr < min)
		{
			min = ahead->nbr;
			minind = curind;
		}
		curind++;
		ahead = ahead->next;
	}
	while (a->head->nbr != min)
		minind < a->size - minind ? rotate(a, ops) : rev_rotate(a, ops);
}

void	min_sort(t_stack *stacks[2], int *tab, int len, char **ops)
{
	int optimal_ind;

	if (is_sorted_asc(stacks[0]))
		return ;
	bubble_sort(tab, len);
	start_setup(stacks, tab, len, ops);
	while (stacks[1]->size > 0)
	{
		optimal_ind = find_min_ops_el(stacks[0], stacks[1]);
		place(stacks[0], stacks[1], optimal_ind, ops);
	}
	real_sort(stacks[0], ops);
}
