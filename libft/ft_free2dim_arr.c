//
// Created by den on 19.05.19.
//

#include "libft.h"

void free2dim_chararr(char **arr)
{
	int i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}