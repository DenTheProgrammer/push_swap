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

//todo post sort operations trim

int main()
{
    int A[] = {2,1,3,8,5,6};
    int B[] = {};
    int len = sizeof(A)/ sizeof(int);
    t_stack *a = create_stack(A, sizeof(A)/ sizeof(int), 'a');
    t_stack *b = create_stack(B, 0, 'b');
//    print_stacks(a, b);
//    radix_sort(a,b);
//	bubble_sort(A, sizeof(A)/ sizeof(int));
	mdebbis_sort(a, b, A, len);
//    printf("%d\n", radix_sort(a,b));


    return (0);
}