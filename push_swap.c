//
// Created by Maybell Debbi on 2019-05-16.
//


#include "push_swap.h"

int is_sorted(t_stack *a)
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

int    radix_sort(t_stack *a, t_stack *b)
{
    int mask = 1;
    int i;
    int start_size = a->size;
    int opcount = 0;

    while (!is_sorted(a))
    {
        i = 0;
        while (i++ < start_size)
        {
        	if ((a->head->nbr & mask) == 0)
                push(a, b);
        	else
        		rotate(a);
        	opcount++;
        }
        while (b->size > 0)
		{
			push(b, a);
			opcount++;
		}
        mask = mask << 1;
    }
	return (opcount);
}



int main()
{
    int testa[] = {2,1,3,6,5,8};
    int testb[] = {};
    t_stack *a = create_stack(testa, sizeof(testa)/ sizeof(int));
    t_stack *b = create_stack(testb, sizeof(testb)/ sizeof(int));


    printf("%d\n", radix_sort(a,b));

    return (0);
}