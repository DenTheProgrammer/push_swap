//
// Created by den on 17.05.19.
//

#include "push_swap.h"

int    radix_sort(t_stack *a, t_stack *b)
{
	int mask = 1;
	int i;
	int start_size = a->size;
	int opcount = 0;

	while (!is_sorted(a))
	{
		i = 0;
		while (i++ < start_size && !(a->size == start_size && is_sorted(a)))
		{
			if ((a->head->nbr & mask) == 0)
				push(a, b);
			else
				rotate(a);
			opcount++;
			print_stacks(a,b);
		}
		while (b->size > 0 && !(a->size == start_size && is_sorted(a)))
		{
			push(b, a);
			opcount++;
			print_stacks(a,b);
		}
		mask = mask << 1;
	}
	return (opcount);
}
