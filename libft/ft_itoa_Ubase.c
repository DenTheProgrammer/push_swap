/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdebbi <mdebbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 21:27:10 by mdebbi            #+#    #+#             */
/*   Updated: 2019/04/07 17:33:48 by mdebbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	intlen(unsigned long long n, int base)
{
	size_t len;

	len = 0;
	while (n)
	{
		len++;
		n /= base;
	}
	return (len);
}

char			*ft_itoa_Ubase(unsigned long long n, int base)
{
	char	*res;
	size_t	len;
	int		min;
	char *barr;

	if (n == 0)
		return (ft_strdup("0"));
	barr = "0123456789ABCDEF";
	min = 1;
	len = intlen(n, base);
	res = ft_strnew(len);
	if (!res)
		return (NULL);
	while (len)
	{
		res[--len] = barr[min * (n % base)];
		n /= base;
	}
	return (res);
}
