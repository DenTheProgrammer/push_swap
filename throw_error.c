//
// Created by den on 23.05.19.
//

#include "push_swap.h"

void	throw_error(char *msg)
{
	write(2, msg, ft_strlen(msg));
	exit(0);
}