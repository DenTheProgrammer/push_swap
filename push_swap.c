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
//    int A[] = {1,92,50, 5,17,4,1,2,0, 10,7,4,6,22,0, 15,7,4, 17, 134,11,21,1,92,50, 5,17,4,1,2,0, 10,7,4,6,22,0, 15,7,4, 17, 34,292,250, 25,127,24,21,1,92,50, 5,17,4,1,2,0, 10,7,4,6,22,0, 15,7,4, 17, 34,22,20, 210,27,24,26,222,20, 215,27,24, 217, 234,192,150, 15,117,14,11,12,10, 110,17,14,16,122,110, 115,17,14, 117, 134};
    int A[] = {2,1,3,6,2,1,3,6,5,8,3,5,4,0,5,2,1,2,1,3,6,5,8,3,5,4,0,3,6,5,2,1,3,6,2,1,3,6,5,8,3,5,4,0,5,2,1,2,1,3,6,5,8,3,5,4,0,3,6,5,8,3,5,4,0,8,3,2,1,3,6,5,8,3,5,4,0,5,4,0,8,3,5,4,0,8,3,2,1,3,6,5,8,3,5,4,0,5,4,0};
	int B[] = {};
    int len = sizeof(A)/ sizeof(int);
    t_stack *a = create_stack(A, sizeof(A)/ sizeof(int), "a", ops);
    t_stack *b = create_stack(B, 0, "b", ops);


//	mdebbis_sort(a, b, A, len, &ops);
	radix_sort(a,b,&ops);


//	printf("%s\n", ops + 1);
	printf("%d\n", get_ops_count(ops));
	char **trimmed = ops_trimmer(ft_strsplit(ops, ' '));
	int trimmed_cnt = 0;
	while (*trimmed)
	{
//		printf("%s\n", *trimmed);
		trimmed++;
		trimmed_cnt++;
	}
	printf("after trim : %d\n", trimmed_cnt);


    return (0);
}