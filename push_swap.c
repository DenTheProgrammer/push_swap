//
// Created by Maybell Debbi on 2019-05-16.
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
//todo post sort operations trim

int get_ops_count(char *ops)
{
	char **splitted = ft_strsplit(ops, ' ');

	int len = 0;
	while (*splitted++)
		len++;
	return (len);
}

int main()
{
	char *ops = ft_strnew(0);
    int A[] = {0,1,-1};
    int B[] = {};
    int len = sizeof(A)/ sizeof(int);
    t_stack *a = create_stack(A, sizeof(A)/ sizeof(int), "a", ops);
    t_stack *b = create_stack(B, 0, "b", ops);
//    printf("%d\n", is_cyclesorted_desc(a));
//    print_stacks(a, b);
//    radix_sort(a,b);
//	swap(a, &ops);
//	swap(b, &ops);
//	push(a, b, &ops);
//	push(a, b, &ops);
//	swap_both(a, b, &ops);
//	rotate(a, &ops);
//	rotate(b, &ops);
//	rotate_both(a, b, &ops);
//	reverse_rotate(a, &ops);
//	reverse_rotate(b, &ops);
//	reverse_rotate_both(a, b, &ops);
//	bubble_sort(A, sizeof(A)/ sizeof(int));
	mdebbis_sort(a, b, A, len, &ops);
//    printf("%d\n", radix_sort(a,b));

	printf("%s\n", ops + 1);
	printf("%d\n", get_ops_count(ops));
    return (0);
}