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
//todo post sort operations trim//done!
//todo checker.c

int get_ops_count(char *ops)
{
	char **splitted = ft_strsplit(ops, ' ');

	int len = 0;
	while (splitted[len])
		len++;
	free2dim_chararr(splitted);
	return (len);
}


void	print_info(char *sort_name, char *ops)
{

	printf("%s:\n--------------------------------------------------\n", sort_name);
	printf("%s\n", ops + 1);
	printf("before trim : %d\n", get_ops_count(ops));
	char **trimmed = ops_trimmer(ft_strsplit(ops, ' '));

	int i=0;
	while (trimmed[i])
	{
		printf("%s ", trimmed[i++]);
	}
	printf("\nafter trim : %d\n", i);
	char **smarter = ops_smarter(trimmed);

	i = 0;
	while (smarter[i])
	{
		printf("%s ", smarter[i++]);
	}
	printf("\nafter smarter : %d\n", i);
	printf("--------------------------------------------------\n");
	free2dim_chararr(smarter);
}

void	free_stack(t_stack *stack)
{
	t_node *head = stack->head;
	t_node *tmp;

	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
	free(stack);
}

void	print_output(char **ops)
{
	int		i;

	i = 0;
	while (ops[i])
		printf("%s\n", ops[i++]);
	free2dim_chararr(ops);
}

char 	**result_ops(char *ops)
{
	char **trimmed;
	char **smarted;

	trimmed = ops_trimmer(ft_strsplit(ops, ' '));
	smarted = ops_smarter(trimmed);
	return (smarted);
}

int main(int argc, char **argv)
{
	char *ops1 = ft_strnew(0);
	char *ops2 = ft_strnew(0);
	int *A = parse_input(argc, argv);

	int B[] = {};
    int len = argc - 1;//?

    t_stack *a = create_stack(A, len, "a", ops1);
    t_stack *b = create_stack(B, 0, "b", ops1);

	mdebbis_sort(a, b, A, len, &ops1);
	free_stack(a);
	free_stack(b);


	A = parse_input(argc, argv);
	a = create_stack(A, len, "a", ops2);
	b = create_stack(B, 0, "b", ops2);
	radix_sort(a,b,&ops2);
//	print_stacks(a,b);


//	print_info("my sort", ops1);
//	print_info("radix", ops2);
	free_stack(a);
	free_stack(b);
	free(A);

	print_output((get_ops_count(ops1) <= get_ops_count(ops2) ? result_ops(ops1) : result_ops(ops2)));

	free(ops1);
	free(ops2);
    return (0);
}