/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdebbi <mdebbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 20:14:05 by mdebbi            #+#    #+#             */
/*   Updated: 2019/04/07 17:28:19 by mdebbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_stupid_putstr(char *s)
{
	if (!s)
		return ;
	while (*s)
	{
		*s = *s == -1 ? 0 : *s;
		write(1, s++, 1);
	}
}
