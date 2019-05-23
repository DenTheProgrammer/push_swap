#include "push_swap.h"

char **one_line_fix(char **argv)
{
	argv = ft_strsplit(argv[1], ' ');
	argv = argv - 1;
	return (argv);
}
