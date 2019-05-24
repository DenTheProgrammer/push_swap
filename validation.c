/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdebbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 18:31:10 by mdebbi            #+#    #+#             */
/*   Updated: 2019/05/23 18:31:11 by mdebbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		is_number(char *str)
{
	if (*str == '-' || *str == '+')
		str++;
	while (*str)
		if (!ft_isdigit(*str++))
			return (0);
	return (1);
}

int		has_duplicates(char **input, int size)
{
	int i;
	int j;

	i = 0;
	while (i < size)
	{
		j = i;
		while (j < size)
		{
			if (i != j && ft_strequ(input[i], input[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int		is_valid_input(char **input, int size)
{
	int i;

	i = 0;
	while (i < size)
		if (!is_number(input[i++]))
			return (0);
	if (has_duplicates(input, size))
		return (0);
	return (1);
}
