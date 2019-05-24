/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mdebbis_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdebbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 18:28:13 by mdebbi            #+#    #+#             */
/*   Updated: 2019/05/23 18:28:15 by mdebbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	split_in_half(t_stack *sarr[2], const int *tab, size_t len, char **ops)
{
	t_node	*ahead;
	int		mid_value;
	int		in_a_cnt;
	int		start_size;

	ahead = sarr[0]->head;
	in_a_cnt = 0;
	start_size = sarr[0]->size;
	mid_value = tab[len / 2];
	while (ahead)
	{
		if (ahead->nbr < mid_value)
			in_a_cnt++;
		ahead = ahead->next;
	}
	while (in_a_cnt && !(is_sorted_asc(sarr[0]) && start_size == sarr[0]->size))
	{
		if (sarr[0]->head->nbr < mid_value)
		{
			push(sarr[0], sarr[1], ops);
			in_a_cnt--;
		}
		else
			rotate(sarr[0], ops);
	}
}

int		rotate_dir(t_stack *stack, int elem)
{
	int		up_dir;
	t_node	*head;

	head = stack->head;
	up_dir = 1;
	while (head)
	{
		if (head->nbr == elem)
			break ;
		up_dir++;
		head = head->next;
	}
	return (up_dir < (stack->size / 2));
}

void	make_real_sorted(t_stack *a, t_stack *b, char **ops)
{
	int dir;

	dir = a->size > 0 ? rotate_dir(a, find_max(a)) : 0;
	while (!is_sorted_asc(a))
	{
		dir ? rotate(a, ops) : rev_rotate(a, ops);
	}
	dir = b->size > 0 ? rotate_dir(b, find_min(b)) : 0;
	while (!is_sorted_desc(b))
	{
		dir ? rotate(b, ops) : rev_rotate(b, ops);
	}
}

void	push_half_back(t_stack *a, t_stack *b, char **ops)
{
	while (b->size > 0)
	{
		push(b, a, ops);
	}
}

void	mdebbis_sort(t_stack *starr[2], int *tab, size_t len, char **ops)
{
	if (is_sorted_asc(starr[0]))
		return ;
	bubble_sort(tab, len);
	split_in_half(starr, tab, len, ops);
	while (!is_cyclesorted_asc(starr[0]) || !is_cyclesorted_desc(starr[1]))
	{
		if (is_need_swap_asc(starr[0]) && is_need_swap_desc(starr[1]))
			swap_both(starr[0], starr[1], ops);
		else if (is_need_swap_asc(starr[0]))
			is_cyclesorted_desc(starr[1]) ? swap(starr[0], ops) :
														rotate(starr[1], ops);
		else if (is_need_swap_desc(starr[1]))
			is_cyclesorted_asc(starr[0]) ? swap(starr[1], ops) :
														rotate(starr[0], ops);
		else
			rot_both(starr[0], starr[1], ops);
	}
	make_real_sorted(starr[0], starr[1], ops);
	push_half_back(starr[0], starr[1], ops);
}
