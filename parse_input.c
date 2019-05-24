/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdebbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 18:28:24 by mdebbi            #+#    #+#             */
/*   Updated: 2019/05/23 18:28:26 by mdebbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char		**argvdup(int argc, char **argv, int visual)
{
	char	**res;
	int		i;
	int		r;

	r = 0;
	i = 1 + visual;
	res = (char **)malloc(sizeof(char*) * argc - visual);
	while (i < argc)
	{
		res[r++] = ft_strdup(argv[i++]);
	}
	res[r] = NULL;
	return (res);
}

static int	ft_atoi_int(const char *str)
{
	int				i;
	long long int	answer;
	int				buff;
	int				simb;

	i = 0;
	simb = 0;
	answer = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v' ||
		   str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			simb = 1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		buff = str[i++] - '0';
		if (answer > 922337203685477580.7)
			throw_error("Error\n");
		answer = (answer * 10) + buff;
	}
	if (simb != 0)
		answer *= -1;
	if (answer > 2147483647 || answer < -2147483648 || ft_strlen(str) > 10)
		throw_error("Error\n");
	return ((int)answer);
}

int			*parseinput(int len, char **arr)
{
	int *res;
	int i;

	i = 0;
	res = malloc(sizeof(int) * (len));
	while (i < len)
		res[i++] = ft_atoi_int(*arr++);
	return (res);
}
