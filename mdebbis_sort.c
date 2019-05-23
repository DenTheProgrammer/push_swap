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

void split_in_half(t_stack *a, t_stack *b, const int *tab, size_t len, char **ops)
{
	t_node *ahead = a->head;
	int mid_value = tab[len/2];
	int in_a_cnt = 0;
	int start_size = a->size;
	while (ahead)
	{
		if (ahead->nbr < mid_value)
			in_a_cnt++;
		ahead = ahead->next;
	}
	while (in_a_cnt && !(is_sorted_asc(a) && start_size == a->size))
	{
		if (a->head->nbr < mid_value)
		{
			push(a, b, ops);
			in_a_cnt--;
		} else rotate(a, ops);
//		print_stacks(a,b);
	}
}

int find_min(t_stack *stack)
{
	int min;
	t_node *head;

	head = stack->head;
	min = head->nbr;
	while (head)
	{
		if (head->nbr < min)
			min = head->nbr;
		head = head->next;
	}
	return (min);
}

int find_max(t_stack *stack)
{
	int max;
	t_node *head;

	head = stack->head;
	max = head->nbr;
	while (head)
	{
		if (head->nbr > max)
			max = head->nbr;
		head = head->next;
	}
	return (max);
}

int is_cyclesorted_asc(t_stack *stack)
{
	if (stack->size <= 2)
		return (1);
	int min = find_min(stack);
	int max = find_max(stack);

	t_node *head;

	head = stack->head;
	while (head->next)
	{
		if (head->nbr > head->next->nbr)
			if (head->nbr != max || head->next->nbr != min || stack->head->nbr < stack->tail->nbr)
				return (0);
		head = head->next;
	}
	return (1);
}

int is_cyclesorted_desc(t_stack *stack)
{
	if (stack->size <= 2)
		return (1);
	int min = find_min(stack);
	int max = find_max(stack);

	t_node *head = stack->head;

	while (head->next)
	{
		if (head->nbr < head->next->nbr)
			if (head->nbr != min || head->next->nbr != max || stack->head->nbr > stack->tail->nbr)
				return (0);
		head = head->next;
	}
	return (1);
}

int is_need_swap_asc(t_stack *stack)
{
	int min = find_min(stack);
	int max = find_max(stack);
	t_node *head;

	head = stack->head;
	if (head->nbr > head->next->nbr)
		if (head->nbr != max || head->next->nbr != min)
			return (1);
	return (0);
}

int is_need_swap_desc(t_stack *stack)
{
	int min = find_min(stack);
	int max = find_max(stack);
	t_node *head;

	head = stack->head;
	if (head->nbr < head->next->nbr)
		if (head->nbr != min || head->next->nbr != max)
			return (1);
	return (0);
}

int rotate_dir(t_stack *stack, int elem)
{
	int up_dir = 1;
	t_node *head = stack->head;

	while (head)
	{
		if (head->nbr == elem)
			break;
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
//		print_stacks(a,b);
	}
	dir = b->size > 0 ? rotate_dir(b, find_min(b)) : 0;
	while (!is_sorted_desc(b))
	{
		dir ? rotate(b, ops) : rev_rotate(b, ops);
//		print_stacks(a,b);
	}
}

void push_half_back(t_stack *a, t_stack *b, char **ops)
{
	while (b->size > 0)
	{
		push(b, a, ops);
//		print_stacks(a,b);
	}

}

void	mdebbis_sort(t_stack *a, t_stack *b, int *tab, size_t len, char **ops)
{
//	print_stacks(a,b);
	if (is_sorted_asc(a))
		return ;
	bubble_sort(tab, len);
	split_in_half(a, b, tab, len, ops);

	while (!is_cyclesorted_asc(a) || !is_cyclesorted_desc(b))
	{
		if (is_need_swap_asc(a) && is_need_swap_desc(b))
			swap_both(a,b, ops);
		else if (is_need_swap_asc(a))
			is_cyclesorted_desc(b) ? swap(a, ops) : rotate(b, ops);
		else if (is_need_swap_desc(b))
			is_cyclesorted_asc(a) ? swap(b, ops) : rotate(a, ops);
		else
			rot_both(a, b, ops);
//		print_stacks(a,b);
	}
	make_real_sorted(a, b, ops);
	push_half_back(a, b, ops);
}
