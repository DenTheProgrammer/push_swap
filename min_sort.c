//
// Created by den on 25.05.19.
//

#include "push_swap.h"

float opcnt = 0;
float opsum = 0;

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
//		print_stacks(stacks[0], stacks[1]);
	}
	if (!is_cyclesorted_asc(stacks[0]))
	{
		swap(stacks[0], ops);
//		print_stacks(stacks[0], stacks[1]);
	}
}

int		min(int a, int b)
{
	return (a < b ? a : b);
}

int		find_lesser(t_stack *a, int nbr)
{
	int les_val;
	int les_ind;
	int cur_ind;
	t_node *head;

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
	int big_val;
	int big_ind;
	int cur_ind;
	t_node *head;

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
	a_ops = min(min(lesser_ind, a->size - lesser_ind), min(bigger_ind, a->size - bigger_ind));
	return (a_ops + b_ops);
}

int		find_min_ops_el(t_stack *a, t_stack *b)
{
	int min_ind;
	int min_op_count;
	int cur_op_count;
	int cur_ind;
	t_node *bhead;

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
//	printf("min ops: %d\n", min_op_count);
	opcnt++;//
	opsum += min_op_count;//
	return (min_ind);
}

int		get_elem_by_ind(t_stack *s, int ind)
{
	t_node *shead;
	int curind;

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
	aind = min(alind, a->size - alind) < min(abind, a->size - abind) ? alind : abind;
	aelem = get_elem_by_ind(a, aind);
	if (aelem > belem)
		while (a->head->nbr != aelem)
		{
			aind < a->size - aind ? rotate(a, ops) : rev_rotate(a, ops);
//			print_stacks(a, b);
		}
	else
		while (a->tail->nbr != aelem)
		{
			aind + 1 < a->size - aind - 1 ? rotate(a, ops) : rev_rotate(a, ops);
//			print_stacks(a, b);
		}
	push(b, a, ops);
//	print_stacks(a, b);
}

void	real_sort(t_stack *a, char **ops)
{
	int min;
	int minind;
	int curind;

	curind = 0;
	minind = 0;
	t_node *ahead = a->head;
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
//	print_stacks(stacks[0], stacks[1]);
	start_setup(stacks, tab, len, ops);
	while (stacks[1]->size > 0)
	{
		optimal_ind = find_min_ops_el(stacks[0], stacks[1]);
		place(stacks[0], stacks[1], optimal_ind, ops);
	}
	real_sort(stacks[0], ops);
//	print_stacks(stacks[0], stacks[1]);
//	printf("average opcnt : %f\n", opsum / opcnt);//
}