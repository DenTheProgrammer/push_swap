/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdebbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 18:27:20 by mdebbi            #+#    #+#             */
/*   Updated: 2019/05/23 18:27:28 by mdebbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"


void	print_output(char **ops)
{
	int		i;

	i = 0;
	while (ops[i])
		ft_printf("%s\n", ops[i++]);
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
	int *A;
	t_stack *a;
	t_stack *b;
	int B[] = {};

	if (argc == 2)
	{
		argv = one_line_fix(argv[1], 0);
		argc = arrlen(argv + 1) + 1;
	}
	A = parseinput(argc - 1, argv + 1);
	if (!is_valid_input(argv + 1, argc - 1))
		throw_error("Error\n");
    a = create_stack(A, argc - 1, "a");
    b = create_stack(B, 0, "b");
	if (argc < 20)
		mdebbis_sort(a, b, A, argc - 1, &ops);
	else
		radix_sort(a,b,&ops);
	free(A);
	print_output(result_ops(ops));
	free_stack(a);
	free_stack(b);
	free(ops);
    return (0);
}
