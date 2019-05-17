//
// Created by den on 17.05.19.
//

#include "push_swap.h"

void split_in_half(t_stack *a, t_stack *b, const int *tab, size_t len)
{
	t_node *ahead = a->head;
	int mid_value = tab[len/2];
	int in_a_cnt = 0;
	while (ahead)
	{
		if (ahead->nbr < mid_value)
			in_a_cnt++;
		ahead = ahead->next;
	}
	ahead = a->head;
	while (in_a_cnt)
	{
		if (ahead->nbr < mid_value)
		{
			push(a, b);
			in_a_cnt--;
		} else rotate(a);
	}
}

char *mdebbis_sort(t_stack *a, t_stack *b, int *tab, size_t len)
{
	bubble_sort(tab, len);
	split_in_half(a, b, tab, len);

	return (NULL);
}