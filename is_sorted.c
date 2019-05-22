//
// Created by Maybell Debbi on 2019-05-22.
//

#include "push_swap.h"

int is_sorted_asc(t_stack *a)
{
	t_node *head = a->head;

	while (head && head->next)
	{
		if (head->nbr > head->next->nbr)
			return (0);
		head = head->next;
	}
	return (1);
}
int is_sorted_desc(t_stack *a)
{
	t_node *head = a->head;

	while (head && head->next)
	{
		if (head->nbr < head->next->nbr)
			return (0);
		head = head->next;
	}
	return (1);
}