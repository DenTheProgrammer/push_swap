#include "push_swap.h"

char **one_line_fix(char *str, int visual)
{
	char **argv;

	argv = ft_strsplit(str, ' ');
	argv = argv - 1 - visual;
	return (argv);
}
