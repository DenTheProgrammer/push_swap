//
// Created by den on 19.05.19.
//

#include "push_swap.h"

int *parse_input(int argc, char **argv)
{
	int *res;
	int i = 0;

	res = malloc(sizeof(int) * (argc - 1));
	while (i < argc - 1)
		res[i++] = ft_atoi(*++argv);
	return (res);
}
