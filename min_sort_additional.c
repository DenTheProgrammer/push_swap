/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_sort_additional.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdebbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 16:54:42 by mdebbi            #+#    #+#             */
/*   Updated: 2019/05/31 16:54:55 by mdebbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		min(int a, int b)
{
	return (a < b ? a : b);
}

int		find_lesser(t_stack *a, int nbr)
{
	int		les_val;
	int		les_ind;
	int		cur_ind;
	t_node	*head;

	head = a->head;
	les_ind = 0;
	les_val = INT_MIN;
	cur_ind = 0;
	while (head)
	{
		if (nbr > head->nbr)
		{
			if (les_val <= head->nbr)
			{
				les_ind = cur_ind;
				les_val = head->nbr;
			}
		}
		cur_ind++;
		head = head->next;
	}
	return (les_ind);
}

int		find_bigger(t_stack *a, int nbr)
{
	int		big_val;
	int		big_ind;
	int		cur_ind;
	t_node	*head;

	head = a->head;
	big_ind = 0;
	big_val = INT_MAX;
	cur_ind = 0;
	while (head)
	{
		if (nbr < head->nbr)
		{
			if (big_val >= head->nbr)
			{
				big_ind = cur_ind;
				big_val = head->nbr;
			}
		}
		cur_ind++;
		head = head->next;
	}
	return (big_ind);
}

int		count_ops(t_stack *a, t_stack *b, int ind, int nbr)
{
	int a_ops;
	int b_ops;
	int lesser_ind;
	int bigger_ind;

	b_ops = min(ind, b->size - ind);
	lesser_ind = find_lesser(a, nbr);
	bigger_ind = find_bigger(a, nbr);
	a_ops = min(min(lesser_ind, a->size - lesser_ind), min(bigger_ind,
			a->size - bigger_ind));
	return (a_ops + b_ops);
}

int		find_min_ops_el(t_stack *a, t_stack *b)
{
	int		min_ind;
	int		min_op_count;
	int		cur_op_count;
	int		cur_ind;
	t_node	*bhead;

	cur_ind = 0;
	min_ind = 0;
	min_op_count = count_ops(a, b, min_ind, b->head->nbr);
	bhead = b->head;
	while (bhead)
	{
		cur_op_count = count_ops(a, b, cur_ind, bhead->nbr);
		if (cur_op_count < min_op_count)
		{
			min_ind = cur_ind;
			min_op_count = cur_op_count;
		}
		cur_ind++;
		bhead = bhead->next;
	}
	return (min_ind);
}
