//
// Created by den on 17.05.19.
//

#include "push_swap.h"
//todo negative numbers, operations trimmer
int    radix_sort(t_stack *a, t_stack *b, char **ops)
{
	int mask = 1;
	int i;
	int start_size = a->size;
	int opcount = 0;

	while (!is_sorted_asc(a))
	{
		i = 0;
		while (i++ < start_size && !(a->size == start_size && is_sorted_asc(a)))
		{
			if ((a->head->nbr & mask) == 0)
				push(a, b, ops);
			else
				rotate(a, ops);
			opcount++;
//			print_stacks(a,b);
		}
		while (b->size > 0 && !(a->size == start_size && is_sorted_asc(a)))
		{
			push(b, a, ops);
			opcount++;
//			print_stacks(a,b);
		}
		mask = mask << 1;
	}
	return (opcount);
}
