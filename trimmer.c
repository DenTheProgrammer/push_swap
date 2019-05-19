//
// Created by den on 17.05.19.
//

#include "push_swap.h"

static int get_len(char **arr)
{
	int len;

	len = 0;
	while (*arr++)
		len++;
	return (len);
}

char	**del(char **arr, int len, int ind)
{
	char **new;
	int i = 0;
	int n = 0;

	new = ft_memalloc(sizeof(char*) * len);
	while (i < len)
	{
		if (i != ind)
			new[n++] = arr[i];
		i++;
	}
//	free2dim_chararr(arr);
	free(arr[ind]);//?
	free(arr);

	return (new);
}
static int is_pointless(char *op1, char *op2)
{
	if ((ft_strequ(op1, "pa") && ft_strequ(op2, "pb")) || (ft_strequ(op1, "pb") && ft_strequ(op2, "pa")))
		return (1);
	if ((ft_strequ(op1, "ra") && ft_strequ(op2, "rra")) || (ft_strequ(op1, "rra") && ft_strequ(op2, "ra")))
		return (1);
	if ((ft_strequ(op1, "rb") && ft_strequ(op2, "rrb")) || (ft_strequ(op1, "rrb") && ft_strequ(op2, "rb")))
		return (1);
	if ((ft_strequ(op1, "sa") && ft_strequ(op2, "sa")) || (ft_strequ(op1, "sb") && ft_strequ(op2, "sb")))
		return (1);
	if ((ft_strequ(op1, "ss") && ft_strequ(op2, "ss")))
		return (1);
	if ((ft_strequ(op1, "rr") && ft_strequ(op2, "rrr")) || (ft_strequ(op1, "rrr") && ft_strequ(op2, "rr")))
		return (1);
	return (0);
}


char **ops_trimmer(char **oparr)
{
	int len = get_len(oparr);
	int delcount = 1;
	int i;

	while (delcount != 0)
	{
		i = 0;
		delcount = 0;
		while (i < len - 1)
		{
			if (is_pointless(oparr[i], oparr[i + 1]))
			{
				oparr = del(oparr, len--, i);
				oparr = del(oparr, len--, i);
				delcount++;
			}
			i++;
		}
	}
	return (oparr);
}