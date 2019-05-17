//
// Created by den on 17.05.19.
//

#include "push_swap.h"

void print_stacks(t_stack *a, t_stack *b)
{
	t_node *ahead = a->head;
	t_node *bhead = b->head;

	while (ahead || bhead)
	{
		if (ahead && bhead)
		{
			printf("|%5d|    |%5d|\n", ahead->nbr, bhead->nbr);
			ahead = ahead->next;
			bhead = bhead->next;
		}
		else if (ahead)
		{
			printf("|%5d|    |     |\n", ahead->nbr);
			ahead = ahead->next;
		}
		else
		{
			printf("|     |    |%5d|\n", bhead->nbr);
			bhead = bhead->next;
		}
	}
	printf("   a          b  \n");
}
