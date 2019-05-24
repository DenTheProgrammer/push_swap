/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smarter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdebbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 18:30:37 by mdebbi            #+#    #+#             */
/*   Updated: 2019/05/23 18:30:39 by mdebbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		get_len(char **arr)
{
	int len;

	len = 0;
	while (*arr++)
		len++;
	return (len);
}

static char		*is_stupid(char *s1, char *s2)
{
	if ((ft_strequ(s1, "sa") && ft_strequ(s2, "sb")) || (ft_strequ(s1, "sb") && ft_strequ(s2, "sa")))
		return (ft_strdup("ss"));
	if ((ft_strequ(s1, "ra") && ft_strequ(s2, "rb")) || (ft_strequ(s1, "rb") && ft_strequ(s2, "ra")))
		return (ft_strdup("rr"));
	if ((ft_strequ(s1, "rra") && ft_strequ(s2, "rrb")) || (ft_strequ(s1, "rrb") && ft_strequ(s2, "rra")))
		return (ft_strdup("rrr"));
	return (NULL);
}

static char		**insert(char **arr, char *elem, int len, int ind)
{
	char	**new;
	int		i;
	int		n;

	n = 0;
	i = 0;
	new = (char **)ft_memalloc(sizeof(char*) * (len + 2));
	while (i < len + 1)
	{
		new[n] = (n != ind) ? arr[i++] : elem;
		n++;
	}
	free(arr);
	return (new);
}

char			**ops_smarter(char **oparr)
{
	int		len;
	int		delcount;
	int		i;
	char	*repl;

	delcount = 1;
	len = get_len(oparr);
	while (delcount != 0)
	{
		i = 0;
		delcount = 0;
		while (i < len - 1)
		{
			if ((repl = is_stupid(oparr[i], oparr[i + 1])))
			{
				oparr = del(oparr, len--, i);
				oparr = del(oparr, len--, i);
				oparr = insert(oparr, repl, len++, i);
				delcount++;
			}
			i++;
		}
	}
	return (oparr);
}
