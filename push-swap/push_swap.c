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

char	**result_ops(char *ops)
{
	char **trimmed;
	char **smarted;

	trimmed = ops_trimmer(ft_strsplit(ops, ' '));
	smarted = ops_smarter(trimmed);
	return (smarted);
}

int		main(int argc, char **argv)
{
	char	*ops;
	int		*input;
	t_stack	*a;
	t_stack	*b;
	char	**arr;

	ops = ft_strnew(0);
	arr = argvdup(argc, argv, 0);
	if (argc == 2)
		arr = one_line_fix(arr);
	argc = arrlen(arr);
	input = parseinput(argc, arr);
	if (!is_valid_input(arr, argc))
		throw_error("Error\n");
	a = create_stack(input, argc, "a");
	b = create_stack(NULL, 0, "b");
	argc < 20 ? mdebbis_sort((t_stack*[2]){a, b}, input, argc, &ops) :
													radix_sort(a, b, &ops);
	free(input);
	print_output(result_ops(ops));
	free_stack(a);
	free_stack(b);
	free(ops);
	free2dim_chararr(arr);
	return (0);
}
