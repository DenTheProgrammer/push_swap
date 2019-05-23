//
// Created by Maybell Debbi on 2019-05-16.
//
//todo error management

#include "../push_swap.h"

int get_ops_count(char *ops)
{
	char **splitted = ft_strsplit(ops, ' ');

	int len = 0;
	while (splitted[len])
		len++;
	free2dim_chararr(splitted);
	return (len);
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

int		main(int argc, char **argv)
{
	char *ops = ft_strnew(0);
	int *A = parse_input(argc - 1, argv + 1);
	t_stack *a;
	t_stack *b;
	int B[] = {};

	if (!is_valid_input(argv + 1, argc - 1))
		throw_error("Error\n");
    a = create_stack(A, argc - 1, "a");
    b = create_stack(B, 0, "b");
	if (argc < 20)
	{
		mdebbis_sort(a, b, A, argc - 1, &ops);
	}
	else
	{
		radix_sort(a,b,&ops);
	}
	free(A);
	print_output(result_ops(ops));
	free_stack(a);
	free_stack(b);
	free(ops);
    return (0);
}