#include "push_swap.h"

char	**one_line_fix(char **arr)
{
	char **argv;

	argv = ft_strsplit(arr[0], ' ');
	free2dim_chararr(arr);
	return (argv);
}
