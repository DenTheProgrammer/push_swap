//
// Created by den on 25.05.19.
//
#include "libft.h"

void				throw_error(char *msg)
{
	write(2, msg, ft_strlen(msg));
	exit(0);
}